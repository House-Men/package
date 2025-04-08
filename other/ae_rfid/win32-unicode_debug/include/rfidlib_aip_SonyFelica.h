#ifndef __RFIDLIB_API_SONY_FELICA_H__
#define __RFIDLIB_API_SONY_FELICA_H__
#include <Windows.h>
#include"rfidlib.h"



#ifdef __cplusplus
extern "C" {
#endif



//DWORD RFIDLIB_API SonyFelica_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;

RFID_DN_HANDLE RFIDLIB_API SonyFelica_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList, BYTE AntennaID);

err_t RFIDLIB_API  SonyFelica_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
										  DWORD *aip_id,
										  DWORD *tag_id,
										  DWORD * ant_id,
										  BYTE uid[],
										  DWORD *uidLen)  ;

#ifdef __cplusplus
}
#endif







#endif
