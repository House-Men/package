#ifndef __RFIDLIB_ANRD5100F_H__
#define __RFIDLIB_ANRD5100F_H__



#ifdef __cplusplus
extern "C" {
#endif

err_t RFIDLIB_API ANRD5100F_SerOpen(LPCTSTR comname, DWORD baud, LPCTSTR frame, BYTE busAddr, RFID_READER_HANDLE *o_hr);

err_t RFIDLIB_API ANRD5100F_TcpOpen(LPCTSTR readerIPAddr, WORD remotePort, LPCTSTR localIPToBind, RFID_READER_HANDLE *o_hr);


#ifdef __cplusplus
}
#endif





#endif
