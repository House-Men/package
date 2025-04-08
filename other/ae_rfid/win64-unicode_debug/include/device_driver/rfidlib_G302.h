#ifndef __RFIDLIB_G302_H__
#define __RFIDLIB_G302_H__




DWORD RFIDLIB_API MG302_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */) ;
err_t RFIDLIB_API MG302_EthOpen(LPCTSTR ipAddr,WORD port ,RFID_READER_HANDLE *o_hr) ;
err_t RFIDLIB_API MG302_SerOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame,
								RFID_READER_HANDLE *o_hr /* out parameter */)  ;






















#endif


