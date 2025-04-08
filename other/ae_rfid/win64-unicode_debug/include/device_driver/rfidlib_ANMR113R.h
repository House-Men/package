#ifndef __RFIDLIB_ANM123R_H__
#define __RFIDLIB_ANM123R_H__







DWORD RFIDLIB_API ANMR113R_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;



err_t RFIDLIB_API ANMR113R_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANMR113R_Close(RFID_READER_HANDLE hr) ;














#endif
