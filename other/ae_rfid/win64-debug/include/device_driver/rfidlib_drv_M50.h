#ifndef __RFIDLIB_M50_H__
#define __RFIDLIB_M50_H__


#ifdef __cplusplus
extern "C" {
#endif

err_t RFIDLIB_API M50_SerialOpen(LPCTSTR comname,DWORD baud,LPCTSTR frame, RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API M50_HidOpen(BYTE AddrMode ,LPCTSTR DeviceIdentifyStr,RFID_READER_HANDLE *o_hr /* out parameter */) ;
err_t RFIDLIB_API M50_TCPOpen(LPCTSTR readerIPAddr,WORD remotePort,LPCTSTR localIPToBind,RFID_READER_HANDLE *o_hr /* out parameter */);

err_t RFIDLIB_API M50_Close(RFID_READER_HANDLE hr);

#ifdef __cplusplus
}
#endif

#endif