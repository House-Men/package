#ifndef __RFIDLIB_ANRD122_H__
#define __RFIDLIB_ANRD122_H__


#ifdef __cplusplus
extern "C" {
#endif


DWORD RFIDLIB_API ANRD122_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD122_Open(BYTE AddrMode ,
												LPCTSTR DeviceIdentifyStr,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD122_Close(RFID_READER_HANDLE hr) ;
DWORD RFIDLIB_API ANRD122_Enum()  ;
err_t RFIDLIB_API ANRD122_GetEnumItem(DWORD indx ,BYTE infType,LPTSTR infBuffer,DWORD *nSize ) ;





#ifdef __cplusplus
}
#endif


















#endif