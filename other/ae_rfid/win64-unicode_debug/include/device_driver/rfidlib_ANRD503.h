#ifndef __RFIDLIB_ANRD503_H__
#define __RFIDLIB_ANRD503_H__

#ifdef __cplusplus
extern "C" {
#endif


DWORD RFIDLIB_API ANRD503_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD503_SerOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame,
								  RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD503_TcpOpen(LPCTSTR readerIPAddr,WORD remotePort/* default is 9909 */,LPCTSTR localIPToBind,RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANRD503_Close(RFID_READER_HANDLE hr) ;



#ifdef __cplusplus
}
#endif












#endif
