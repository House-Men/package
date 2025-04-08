#ifndef RFIDLIB_PICC_MIFAREPLUS_H_
#define RFIDLIB_PICC_MIFAREPLUS_H_

#include <Windows.h>
#include "rfidlib.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAKE_BYTE
#define MAKE_BYTE(a)			((BYTE)(a))
#endif

#ifndef MAKE_WORD
#define MAKE_WORD(a,b)			((MAKE_BYTE(b)<<8)|MAKE_BYTE(a))
#endif

#ifndef MAKE_DWORD
#define MAKE_DWORD(a,b,c,d)		((MAKE_BYTE(d)<<24)|(MAKE_BYTE(c)<<16)|(MAKE_BYTE(b)<<8)|MAKE_BYTE(a))
#endif

#define MFDF_CREATE_VALUE_FILE_FREE_GET_VALUE		0x02
#define MFDF_CREATE_VALUE_FILE_LIMITEDCRED_ENABLE	0x01

	// Desfire EV1 File Type
#define MFDF_FILE_TYPE_STD_DATA_FILE				0x00
#define MFDF_FILE_TYPE_BACKUP_DATA_FILE				0x01
#define MFDF_FILE_TYPE_VALUE_FILE					0x02
#define MFDF_FILE_TYPE_LINEAR_RECORD_FILES			0x03
#define  MFDF_FILE_TYPE_CYCLIC_RECORD_FILES			0x04

#define FILE_TYPE_STDDATAFILE						0
#define FILE_TYPE_BACKUPDATAFILE					1
#define FILE_TYPE_VALUEDATAFILE						2
#define FILE_TYPE_LINEARRECORDFILE					3
#define FILE_TYPE_CYLICRECORDFILE					4

	class MFDF_BASE_FILE_FILESETT
	{
	public:
		UINT8 m_com_sett;
		UINT16 m_access_rights;

		MFDF_BASE_FILE_FILESETT(BYTE file_sett[])
		{
			m_com_sett = file_sett[0];
			m_access_rights = MAKE_WORD(file_sett[1], file_sett[2]);
		}

		MFDF_BASE_FILE_FILESETT()
			:m_com_sett(0),
			m_access_rights(0)
		{
		}
	};

	class MFDF_DATA_FILE_FILESETT
		: public MFDF_BASE_FILE_FILESETT
	{
	public:
		UINT32 m_file_size;
		MFDF_DATA_FILE_FILESETT(BYTE file_sett[])
			: MFDF_BASE_FILE_FILESETT(file_sett)
		{
			m_file_size = MAKE_DWORD(file_sett[3], file_sett[4], file_sett[5], 0);
		}

		MFDF_DATA_FILE_FILESETT()
			:m_file_size(0)
		{
		}
	};

	class MFDF_VALUE_FILE_FILESETT
		: public MFDF_BASE_FILE_FILESETT
	{
	public:
		INT32 m_lower_limit;
		INT32 m_upper_limit;
		INT32 m_limited_credit_value;
		BYTE m_limited_credit_enabled;

		MFDF_VALUE_FILE_FILESETT(BYTE file_sett[])
			: MFDF_BASE_FILE_FILESETT(file_sett)
		{
			m_lower_limit = MAKE_DWORD(file_sett[3], file_sett[4], file_sett[5], file_sett[6]);
			m_upper_limit = MAKE_DWORD(file_sett[7], file_sett[8], file_sett[9], file_sett[10]);
			m_limited_credit_value = MAKE_DWORD(file_sett[11], file_sett[12], file_sett[13], file_sett[14]);
			m_limited_credit_enabled = file_sett[15];
		}

		MFDF_VALUE_FILE_FILESETT()
			:m_lower_limit(0),
			m_upper_limit(0),
			m_limited_credit_value(0),
			m_limited_credit_enabled(0)
		{
		}
	};

	class MFDF_RECORD_FILE_FILESETT :
		public MFDF_BASE_FILE_FILESETT
	{
	public:
		UINT32 m_record_size;
		UINT32 m_max_num_of_records;
		UINT32 m_current_num_of_records;

		MFDF_RECORD_FILE_FILESETT(BYTE file_sett[])
			: MFDF_BASE_FILE_FILESETT(file_sett)
		{
			m_record_size = MAKE_DWORD(file_sett[3], file_sett[4], file_sett[5], 0);
			m_max_num_of_records = MAKE_DWORD(file_sett[6], file_sett[7], file_sett[8], 0);
			m_current_num_of_records = MAKE_DWORD(file_sett[9], file_sett[10], file_sett[11], 0);
		}

		MFDF_RECORD_FILE_FILESETT()
			:m_record_size(0),
			m_max_num_of_records(0),
			m_current_num_of_records(0)
		{
		}
	};

	class MFDF_CARD_VERSION {
	public:
		struct {
			BYTE hw_vendor_id;
			BYTE hw_type;
			BYTE hw_sub_type;
			BYTE hw_major_ver;
			BYTE hw_minor_ver;
			BYTE hw_storage_size;
			BYTE hw_protocol;
		};

		struct {
			BYTE sw_vendor_id;
			BYTE sw_type;
			BYTE sw_sub_type;
			BYTE sw_major_ver;
			BYTE sw_minor_ver;
			BYTE sw_storage_size;
			BYTE sw_protocol;
		};

		struct {
			BYTE uid[7];
			BYTE batch_no[5];
			BYTE cw_prod;
			BYTE year_prod;
		};

		MFDF_CARD_VERSION(BYTE frame1[], BYTE frame2[], BYTE frame3[])
		{
			hw_vendor_id = frame1[0];
			hw_type = frame1[1];
			hw_sub_type = frame1[2];
			hw_major_ver = frame1[3];
			hw_minor_ver = frame1[4];
			hw_storage_size = frame1[5];
			hw_protocol = frame1[6];

			sw_vendor_id = frame2[0];
			sw_type = frame2[1];
			sw_sub_type = frame2[2];
			sw_major_ver = frame2[3];
			sw_minor_ver = frame2[4];
			sw_storage_size = frame2[5];
			sw_protocol = frame2[6];

			memcpy(uid, frame3, 7);
			memcpy(batch_no, frame3 + 7, 5);

			cw_prod = frame3[12];
			year_prod = frame3[13];
		}
	};

	err_t RFIDLIB_API MFDF_SelectApplication(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, DWORD aid);

	err_t RFIDLIB_API MFDF_Authenticate(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE key_type,
		BYTE key_value[],
		BYTE key_len,
		BYTE key_no,
		BYTE key_ver);

	err_t RFIDLIB_API MFDF_AuthenticateISO(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE key_type,
		BYTE key_value[],
		BYTE key_len,
		BYTE key_no,
		BYTE key_ver);


	err_t RFIDLIB_API MFDF_AuthenticateAES(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE key_value[],
		BYTE key_len,
		BYTE key_no,
		BYTE key_ver);

	err_t RFIDLIB_API MFDF_ChangeKeySettings(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mask);
	err_t RFIDLIB_API MFDF_GetKeySettings(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE* keySettings, BYTE* maxNoOfKeys);
	err_t RFIDLIB_API MFDF_GetCardUID(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE uid[], BYTE uidLen);
	err_t RFIDLIB_API MFDF_GetVersion(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE frame1[]/*7 byte*/, BYTE frame2[]/*7 byte*/, BYTE frame3[]/*14 byte*/);
	err_t RFIDLIB_API MFDF_GetKeyVersion(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE key_no, BYTE* keyver);
	err_t RFIDLIB_API MFDF_FormatPICC(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
	err_t RFIDLIB_API MFDF_SetConfiguration(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE opt, BYTE data[], BYTE dataLen);
	err_t RFIDLIB_API MFDF_SetApplicationDefaultKey(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE key_type, BYTE key_ver, BYTE key_data[], BYTE key_len);
	err_t RFIDLIB_API MFDF_CreateApplication(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		DWORD m_aid,
		BYTE m_keySettings1,
		BYTE m_keySettings2,
		WORD m_IsoFileID,
		BYTE m_DfName[],
		BYTE m_DnNameLen);

	err_t RFIDLIB_API MFDF_DeleteApplication(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, DWORD m_aid);

	err_t RFIDLIB_API MFDF_GetApplicationIDs(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, DWORD IDs[], DWORD* nSize);

	err_t RFIDLIB_API MFDF_FreeMem(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, DWORD* nMemorySize);

	err_t RFIDLIB_API MFDF_GetFileIDs(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE IDs[], DWORD* nSize);

	err_t RFIDLIB_API MFDF_CreateStdDataFile(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNum,
		BOOLEAN bIsoSelect,
		WORD mIso7816FileID,
		BYTE mComSet,
		WORD mAccessRights,
		DWORD mFileSize);


	err_t RFIDLIB_API MFDF_CreateBackupDataFile(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNum,
		BOOLEAN bIsoSelect,
		WORD mIso7816FileID,
		BYTE mComSet,
		WORD mAccessRights,
		DWORD mFileSize);



	err_t RFIDLIB_API MFDF_CreateValueFile(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNum,
		BYTE mComSet,
		WORD mAccessRights,
		INT32 mLowerLimit,
		INT32 mUpperLimit,
		INT32 mInitialValue,
		BYTE mLimitedCreditEnable);

	err_t RFIDLIB_API MFDF_CreateLinearRecordFile(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		BOOLEAN bIsoSelect,
		WORD mIso7816FileID,
		BYTE mComSet,
		WORD mAccessRights,
		DWORD mRecordSize,
		DWORD mMaxNumOfReocord);


	err_t RFIDLIB_API MFDF_CreateCyclicRecordFile(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		BOOLEAN bIsoSelect,
		WORD mIso7816FileID,
		BYTE mComSet,
		WORD mAccessRights,
		DWORD mRecordSize,
		DWORD mMaxNumOfReocord);

	err_t RFIDLIB_API MFDF_DeleteFile(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo);


	err_t RFIDLIB_API MFDF_GetFileSettings(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, BYTE* pFileType, BYTE cfg[], DWORD* nSize);


	err_t RFIDLIB_API MFDF_ChangeFileSettings(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, BYTE mNewComSet, WORD mNewAccessRights);


	err_t RFIDLIB_API MFDF_ChangeKey(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mKeyNo,
		BYTE mOldKeyType,
		BYTE mOldKeyVer,
		BYTE mOldKey[],
		BYTE mNewKeyType,
		BYTE mNewKeyVer,
		BYTE mNewKey[],
		BYTE mKeyLen);

	err_t RFIDLIB_API MFDF_WriteData(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		DWORD mOffset,
		BYTE mComSet,
		BYTE buffer[],
		DWORD* nSize);


	err_t RFIDLIB_API MFDF_ReadData(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		DWORD mOffset,
		DWORD mNeedToRead,
		BYTE mComSet,
		BYTE buffer[],
		DWORD* nSize);

	err_t RFIDLIB_API MFDF_CommitTransaction(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);

	err_t RFIDLIB_API MFDF_AbortTransaction(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);

	err_t RFIDLIB_API MFDF_Credit(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, INT32 mData, BYTE mComSet);

	err_t RFIDLIB_API MFDF_Dedit(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, INT32 mData, BYTE mComSet);

	err_t RFIDLIB_API MFDF_LimitedCredit(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, INT32 mData, BYTE mComSet);

	err_t RFIDLIB_API MFDF_GetValue(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo, BYTE mComSet, BOOLEAN enFreeGetValue, INT32* mData);

	err_t RFIDLIB_API MFDF_WriteRecord(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		DWORD mOffset,
		BYTE mCommType,
		BYTE buffer[],
		DWORD* nSize);

	err_t RFIDLIB_API MFDF_ReadRecord(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE mFileNo,
		DWORD mOffset,
		DWORD mNeedToRead,
		DWORD mReadLen,
		BYTE mComSet,
		BYTE buffer[],
		DWORD* nSize);

	err_t RFIDLIB_API MFDF_ClearRecordFile(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE mFileNo);


#ifdef __cplusplus
}
#endif


#endif // !RFIDLIB_PICC_MIFAREPLUS_H_
