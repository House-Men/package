#ifndef __RFIDLIB_ANRD501_H__
#define __RFIDLIB_ANRD501_H__



#ifdef __cplusplus
extern "C" {
#endif




DWORD RFIDLIB_API ANRD501_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD501_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD501_Close(RFID_READER_HANDLE hr) ;




#ifdef __cplusplus
}
#endif









#endif
