#ifndef __RFIDLIB_ANMF102U_H__
#define __RFIDLIB_ANMF102U_H__

#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API ANMF102U_Enum()  ;
err_t RFIDLIB_API ANMF102U_GetEnumItem(DWORD indx ,BYTE infType,LPTSTR infBuffer,DWORD *nSize ) ;
DWORD RFIDLIB_API ANMF102U_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANMF102U_Open(BYTE AddrMode ,
												LPCTSTR DeviceIdentifyStr,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANMF102U_Close(RFID_READER_HANDLE hr) ;


#ifdef __cplusplus
}
#endif














#endif

