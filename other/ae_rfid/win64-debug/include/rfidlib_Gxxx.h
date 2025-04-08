#ifndef __RFIDLIB_GXXX_H__
#define __RFIDLIB_GXXX_H__





#define MGXXX_EVNT_REPORTOUT				1					//report event output 
#define MGXXX_EVNT_ERROROUT					2					//error event output
#define MGXXX_EVNT_COLLEXIT					3                   //collecting exit event output 




#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API MGXXX_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API MGXXX_GetReports(RFID_READER_HANDLE hr ,BYTE Flag)  ;
err_t RFIDLIB_API MGXXX_RunLoopCollecting(RFID_READER_HANDLE hr )  ;
err_t RFIDLIB_API MGXXX_StopLoopCollecting(RFID_READER_HANDLE hr ) ;
err_t RFIDLIB_API MGXXX_StopLoopCollectingBegin(RFID_READER_HANDLE hr ) ;
err_t RFIDLIB_API MGXXX_StopLoopCollectingEnd(RFID_READER_HANDLE hr ) ;
err_t RFIDLIB_API MGXXX_ParseIOReportData(RFID_READER_HANDLE hr  ,RFID_DN_HANDLE hreport,LPTSTR uid,DWORD nSize ,BYTE *dir ,BYTE time[]) ;
err_t RFIDLIB_API MGXXX_ClearBuffer(RFID_READER_HANDLE hr)  ;

#ifdef __cplusplus
}
#endif









#endif


