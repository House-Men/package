#ifndef __RFIDLIB_ANRD131_H__
#define __RFIDLIB_ANRD131_H__


#ifdef __cplusplus
extern "C" {
#endif




DWORD RFIDLIB_API ANRD131_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD131_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD131_Close(RFID_READER_HANDLE hr) ;
err_t RFIDLIB_API ANRD131_SetSEGLEDValue(RFID_READER_HANDLE hr ,BYTE seg1,BYTE seg2,BYTE seg3,BYTE seg4) ;



#ifdef __cplusplus
}
#endif















#endif
