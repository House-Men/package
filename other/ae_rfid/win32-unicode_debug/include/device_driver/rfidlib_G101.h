#ifndef __RFIDLIB_G101_H__
#define __RFIDLIB_G101_H__



DWORD RFIDLIB_API MG101_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API MG101_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
							 RFID_READER_HANDLE *o_hr /* out parameter */) ;






















#endif


