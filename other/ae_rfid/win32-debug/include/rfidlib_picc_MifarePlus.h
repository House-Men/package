#ifndef RFIDLIB_PICC_MIFAREPLUS_H_

#include <Windows.h>
#include "rfidlib.h"


#ifdef __cplusplus
extern "C" {
#endif

#define ORIGINALITY_KEY  0x8000
#define CARD_MASTER_KEY  0x9000
#define CARD_CONFIGURATION_KEY 0x9001
#define LEVEL2_SWITCH_KEY 0x9002
#define LEVEL3_SWITCH_KEY 0x9003
#define SL1_CARD_AUTHENTICATION_KEY 0x9004
#define SELECT_VC_KEY 0xA000
#define PROXIMITY_CHECK_KEY 0xA001
#define VC_POLLING_ENC_KEY  0xA080
#define VC_POLLING_MAC_KEY  0xA080

	err_t RFIDLIB_API MIFAREPLUS_Connect(RFID_READER_HANDLE hr,
		BYTE uid[],
		BYTE uidLen,
		RFID_TAG_HANDLE *ht);

	err_t RFIDLIB_API MIFAREPLUS_Level0WritePerso(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE data[]);

	err_t RFIDLIB_API MIFAREPLUS_Level0CommitPerso(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht);


	err_t RFIDLIB_API MIFAREPLUS_Level2Authentication(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE key[]);

	err_t RFIDLIB_API MIFAREPLUS_Level3FirstAuthentication(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE key[],
		BYTE PICCcap2[]/*The capabilities os the PICC.6 byte*/);

	err_t RFIDLIB_API MIFAREPLUS_Level3FollowingAuthentication(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE key[]);

	err_t RFIDLIB_API MIFAREPLUS_Level3ResetAuthentication(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht);


	err_t RFIDLIB_API MIFAREPLUS_Level3ReadEx(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE bMACedOnCmd,
		BYTE bPlainText,
		BYTE bMACedOnResp,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3WriteEx(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE bMACedOnCmd,//must be 1.
		BYTE bPlainText,
		BYTE bMACedOnResp,
		WORD bnr,
		BYTE data[],
		DWORD nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3Read(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadPlainMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadPlain(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadUnMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadUnMACedRespMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadPlainUnMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3ReadPlainUnMACedRespMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE ext,
		BYTE data[],
		DWORD *nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3Write(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE data[],
		DWORD nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3WritePlainMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE data[],
		DWORD nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3WritePlain(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE data[],
		DWORD nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3WriteMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		BYTE data[],
		DWORD nSize);

	err_t RFIDLIB_API MIFAREPLUS_Level3Increment(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3IncrementMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3Decrement(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3DecrementMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD bnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3Transfer(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nDesBnr);

	err_t RFIDLIB_API MIFAREPLUS_Level3TransferMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nDesBnr);

	err_t RFIDLIB_API MIFAREPLUS_Level3IncrementTransfer(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr,
		WORD nDesBnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3IncrementTransferMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr,
		WORD nDesBnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3DecrementTransfer(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr,
		WORD nDesBnr,
		DWORD nValue);

	err_t RFIDLIB_API MIFAREPLUS_Level3DecrementTransferMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr,
		WORD nDesBnr,
		DWORD nValue);


	err_t RFIDLIB_API MIFAREPLUS_Level3Restore(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr);

	err_t RFIDLIB_API MIFAREPLUS_Level3RestoreMACed(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD nSrcBnr);

#ifdef __cplusplus
}
#endif


#endif // !RFIDLIB_PICC_MIFAREPLUS_H_
