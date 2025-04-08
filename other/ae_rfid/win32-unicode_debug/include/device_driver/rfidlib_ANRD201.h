#ifndef __RFIDLIB_ANRD201_H__
#define __RFIDLIB_ANRD201_H__

#ifdef __cplusplus
extern "C" {
#endif






DWORD RFIDLIB_API ANRD201_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD201_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD201_OpenHid(BYTE AddrMode ,LPCTSTR DeviceIdentifyStr,RFID_READER_HANDLE *o_hr);
err_t RFIDLIB_API ANRD201_Close(RFID_READER_HANDLE hr) ;


#ifdef __cplusplus
}
#endif














#endif
