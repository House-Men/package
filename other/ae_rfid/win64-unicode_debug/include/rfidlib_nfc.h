#ifndef _RFIDLIB_NFC_H_
#define _RFIDLIB_NFC_H_
#include "windows.h"
#include "rfidlib.h"

#ifdef __cplusplus
extern "C" {
#endif

RFID_NFC_HANDLE RFIDLIB_API nfc_CreateUriNdef(LPCTSTR sNetAddr,BYTE UriType);
err_t RFIDLIB_API nfc_WriteNdef(RFID_READER_HANDLE hReader,RFID_TAG_HANDLE hTag,RFID_NFC_HANDLE hNdef,BOOLEAN IsLock);
err_t RFIDLIB_API nfc_ReadNdef(RFID_READER_HANDLE hReader,RFID_TAG_HANDLE hTag,RFID_NFC_HANDLE *hNdef,BYTE *NdefType);
err_t RFIDLIB_API nfc_ParseNdefByUri(RFID_NFC_HANDLE hNdef,LPTSTR sNetAddr,DWORD NetAddrSize,BYTE *netType);

#ifdef __cplusplus
}
#endif


#endif