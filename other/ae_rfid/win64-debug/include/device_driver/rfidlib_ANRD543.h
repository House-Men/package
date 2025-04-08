#ifndef __RFIDLIB_ANRD543_H__
#define __RFIDLIB_ANRD543_H__




DWORD RFIDLIB_API ANRD543_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD543_SerOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame,
								  RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD543_TcpOpen(LPCTSTR readerIPAddr,WORD remotePort/* default is 9909 */,LPCTSTR localIPToBind,RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANRD543_Close(RFID_READER_HANDLE hr) ;














#endif
