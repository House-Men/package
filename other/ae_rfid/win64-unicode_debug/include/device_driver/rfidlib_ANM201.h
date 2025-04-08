#ifndef __RFIDLIB_ANM201_H__
#define __RFIDLIB_ANM201_H__




#ifdef __cplusplus
extern "C" {
#endif



DWORD RFIDLIB_API ANM201_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
err_t RFIDLIB_API ANM201_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,RFID_READER_HANDLE *o_hr /* out parameter */)  ;

err_t RFIDLIB_API ANM201_OpenHid(BYTE AddrMode ,LPCTSTR DeviceIdentifyStr,RFID_READER_HANDLE *o_hr);

err_t RFIDLIB_API ANM201_Close(RFID_READER_HANDLE hr) ;

err_t RFIDLIB_API ANM201_GetNoiseLevel(RFID_READER_HANDLE hr ,BYTE noisebuf[],DWORD *nSize) ;





#ifdef __cplusplus
}
#endif



















#endif

