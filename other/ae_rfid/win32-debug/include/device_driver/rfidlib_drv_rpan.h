#ifndef __RFIDLIB_ANRPAN_H__
#define __RFIDLIB_ANRPAN_H__


#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API ANRPAN_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */) ;
err_t RFIDLIB_API ANRPAN_SerialOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame, RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANRPAN_HidOpen(BYTE AddrMode ,LPCTSTR DeviceIdentifyStr,RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API ANRPAN_TCPOpen(LPCTSTR readerIPAddr,WORD remotePort,LPCTSTR localIPToBind,RFID_READER_HANDLE *o_hr /* out parameter */);

err_t RFIDLIB_API ANRPAN_Close(RFID_READER_HANDLE hr);
err_t RFIDLIB_API ANRPAN_SetSysTime(RFID_READER_HANDLE hr,WORD year,BYTE month,BYTE day,BYTE hour,BYTE min,BYTE sec);


err_t RFIDLIB_API ANRPAN_ParseRecord(RFID_READER_HANDLE hr,RFID_DN_HANDLE hReport,BYTE* buffer,int *len);
err_t RFIDLIB_API ANRPAN_GetRecord(RFID_READER_HANDLE hr,BYTE flg);
err_t RFIDLIB_API ANRPAN_ClearRecord(RFID_READER_HANDLE hr);

#ifdef __cplusplus
}
#endif

#endif