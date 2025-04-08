#ifndef __RFIDLIB_API_ISO144443B_H__
#define __RFIDLIB_API_ISO144443B_H__



#ifdef __cplusplus
extern "C" {
#endif



DWORD RFIDLIB_API ISO14443B_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;


err_t RFIDLIB_API ISO14443B_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
										  DWORD *aip_id,
										  DWORD *tag_id,
										  DWORD * ant_id,
										  DWORD *metaFlags,
										  BYTE tagData[],
										  DWORD *tagDataLen/* IN:max size of buffer for writing ,OUT:bytes written to buffer */)  ;


RFID_DN_HANDLE RFIDLIB_API ISO14443B_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList,
															BYTE AntennaID,/* By default set to 0,apply to all antenna */
															BYTE AFI ,
															BYTE SlotNum
															)   ;



#ifdef __cplusplus
}
#endif







#endif
