#ifndef __RFIDLIB_ANRD120M_H__
#define __RFIDLIB_ANRD120M_H__










DWORD RFIDLIB_API ANRD120M_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANRD120M_Open(BYTE AddrMode ,
												LPCTSTR DeviceIdentifyStr,
												RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRD120M_Close(RFID_READER_HANDLE hr) ;
err_t RFIDLIB_API ANRD120M_UpdateHwSerialNumber(RFID_READER_HANDLE hr,LPCTSTR serialnum/* Êý×Ö×Ö·û´®*/ ,DWORD nSize)  ;
DWORD RFIDLIB_API ANRD120M_Enum()  ;
err_t RFIDLIB_API ANRD120M_GetEnumItem(DWORD indx ,BYTE infType,LPTSTR infBuffer,DWORD *nSize ) ;













#endif
