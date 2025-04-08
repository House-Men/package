#ifndef __RFIDLIB_DRV_RL8000_H__
#define __RFIDLIB_DRV_RL8000_H__

#ifdef __cplusplus
extern "C" {
#endif



DWORD RFIDLIB_API RL8000_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;

err_t RFIDLIB_API RL8000_USBOpen(BYTE AddrMode ,
								  LPCTSTR DeviceIdentifyStr,
								  RFID_READER_HANDLE *o_hr /* out parameter */)  ;

err_t RFIDLIB_API RL8000_SerOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame,BYTE busAddr ,
								  RFID_READER_HANDLE *o_hr /* out parameter */)  ;

err_t RFIDLIB_API RL8000_TCPOpen(LPCTSTR readerIPAddr, WORD remotePort, LPCTSTR localIPToBind, RFID_READER_HANDLE *o_hr);

DWORD RFIDLIB_API RL8000_Enum()  ;


err_t RFIDLIB_API RL8000_GetEnumItem(DWORD indx ,BYTE infType,LPTSTR infBuffer,DWORD *nSize ) ;



#ifdef __cplusplus
}
#endif










#endif
