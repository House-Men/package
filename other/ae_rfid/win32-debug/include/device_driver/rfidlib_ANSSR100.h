#ifndef __RFIDLIB_ANSSR100_H__
#define __RFIDLIB_ANSSR100_H__



#include "rfidlib.h"




/*
*   ANSSR100 outputs
*/
#define ANSSR100_BUZZER_OUTPUT				0x01
#define ANSSR100_RELAY1_OUTPUT				0x02




/*
*  Message error 
*/
#define MSG_NOERR							0
#define MSGERR_RORUNING						0x0081 
#define MSGERR_REPORT_CURSOR_EXCEEDED		0x0082
#define MSGERR_EEPROM						0x0083
#define MSGERR_SIZE							0x0084
#define MSGERR_NOSYS						0x0085
#define MSGERR_INVLID_CFGNO					0x0086













#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API ANSSR100_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANSSR100_OpenTCP(LPCTSTR readerIPAddr,WORD remotePort/* default is 9909 */,LPCTSTR localIPToBind,RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANSSR100_OpenSerial(LPCTSTR comname,DWORD baud,LPCTSTR frame,RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANSSR100_Close(RFID_READER_HANDLE hr)   ;


err_t RFIDLIB_API ANSSR100_CmdStartReaderOperation(RFID_READER_HANDLE hr , DWORD antSelected,BYTE afi) ;
err_t RFIDLIB_API ANSSR100_CmdGetStatusAndReports(RFID_READER_HANDLE hr ,WORD cursor,BYTE *status,DWORD *getted,DWORD *left) ;
err_t RFIDLIB_API ANSSR100_CmdGetReportsCount(RFID_READER_HANDLE hr , WORD *reportscount) ;
err_t RFIDLIB_API ANSSR100_CmdGetStatus(RFID_READER_HANDLE hr ,BYTE *sta) ;


#ifdef __cplusplus
}
#endif



#endif
