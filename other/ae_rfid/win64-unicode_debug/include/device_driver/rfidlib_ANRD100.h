#ifndef __RFIDLIB_ANRD100_H__
#define __RFIDLIB_ANRD100_H__


#ifdef __cplusplus
extern "C" {
#endif


DWORD RFIDLIB_API ANRD100_Enum()  ;
err_t RFIDLIB_API ANRD100_GetEnumItem(DWORD indx ,BYTE infType,LPTSTR infBuffer,DWORD *nSize ) ;
DWORD RFIDLIB_API ANRD100_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD100_Open(BYTE AddrMode ,
												LPCTSTR DeviceIdentifyStr,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD100_Close(RFID_READER_HANDLE hr) ;





#ifdef __cplusplus
}
#endif











#endif

