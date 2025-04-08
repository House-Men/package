#ifndef __RFIDLIB_ANRD5112_H__
#define __RFIDLIB_ANRD5112_H__

#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API ANRD5112_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD5112_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD5112_OpenNetwork(LPCTSTR readerIPAddr,
									   WORD remotePort/* default is 9909 */,
									   LPCTSTR localIPToBind,
									   RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANRD5112_Close(RFID_READER_HANDLE hr) ;


#ifdef __cplusplus
}
#endif

























#endif
