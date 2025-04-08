#ifndef __RFIDLIB_API_NFCFORUMTYPE1_H__
#define __RFIDLIB_API_NFCFORUMTYPE1_H__
#include <Windows.h>
#include"rfidlib.h"



#ifdef __cplusplus
extern "C" {
#endif

RFID_DN_HANDLE RFIDLIB_API NFCForumType1_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList, BYTE AntennaID);

err_t RFIDLIB_API  NFCForumType1_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
										  DWORD *aip_id,
										  DWORD *tag_id,
										  DWORD * ant_id,
										  BYTE *m_hr1,
										  BYTE *m_hr2,
										  BYTE uid[],
										  DWORD *uidLen
	)  ;

err_t RFIDLIB_API NFCForumType1_Connect(RFID_READER_HANDLE hr, DWORD tagType, BYTE uid[], RFID_TAG_HANDLE *ht);
err_t RFIDLIB_API NFCForumType1_ReadAll(RFID_READER_HANDLE hr,
	RFID_TAG_HANDLE ht,
	BYTE *m_hr0,
	BYTE *m_hr1,
	BYTE buffer[],
	DWORD *nSize);

err_t RFIDLIB_API NFCForumType1_ReadByte(RFID_READER_HANDLE hr,
	RFID_TAG_HANDLE ht,
	BYTE block_no,
	BYTE byte_no,
	BYTE *pData);

err_t RFIDLIB_API NFCForumType1_WriteEraseByte(RFID_READER_HANDLE hr,
	RFID_TAG_HANDLE ht,
	BYTE block_no,
	BYTE byte_no,
	BYTE m_data);


err_t RFIDLIB_API NFCForumType1_WriteNoEraseByte(RFID_READER_HANDLE hr,
	RFID_TAG_HANDLE ht,
	BYTE block_no,
	BYTE byte_no,
	BYTE m_data);

#ifdef __cplusplus
}
#endif







#endif
