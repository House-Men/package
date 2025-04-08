#ifndef __RFIDLIB_LSGATE_H__
#define __RFIDLIB_LSGATE_H__



#include "rfidlib.h"

#ifdef __cplusplus
extern "C" {
#endif


DWORD RFIDLIB_API LSG_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API LSG_CmdGetReports(RFID_READER_HANDLE hr ,BYTE Flag,BYTE recordsToGet) ;
err_t  RFIDLIB_API LSG_CmdGetSystemTime(RFID_READER_HANDLE hr,DWORD *year,BYTE *month,BYTE *day ,BYTE *hour,BYTE *minute,BYTE *second) ;
err_t  RFIDLIB_API LSG_CmdSetSystemTime(RFID_READER_HANDLE hr,DWORD year,BYTE month,BYTE day ,BYTE hour,BYTE minute,BYTE second) ;
err_t  RFIDLIB_API LSG_CmdResetFlowOfPeople(RFID_READER_HANDLE hr,BYTE flag) ;
err_t  RFIDLIB_API LSG_CmdGetCurrentFlowOfPeople(RFID_READER_HANDLE hr,DWORD *inFlow,DWORD *outFlow) ;
err_t  RFIDLIB_API LSG_CmdReverseDirection(RFID_READER_HANDLE hr)  ;
err_t RFIDLIB_API LSG_ParseSCEventData(RFID_DN_HANDLE hReport ,LPTSTR slData,DWORD nSize,BYTE *dir ,BYTE time[]) ;


#ifdef __cplusplus
}
#endif




















#endif
