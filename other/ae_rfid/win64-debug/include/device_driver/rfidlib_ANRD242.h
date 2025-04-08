#ifndef __RFIDLIB_ANRD242_H__
#define __RFIDLIB_ANRD242_H__



#ifdef __cplusplus
extern "C" {
#endif




DWORD RFIDLIB_API ANRD242_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD242_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD242_Close(RFID_READER_HANDLE hr) ;





#ifdef __cplusplus
}
#endif











#endif
