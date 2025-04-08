#ifndef __RFIDLIB_LSG428_H__
#define __RFIDLIB_LSG428_H__





err_t RFIDLIB_API LSG428_SerOpen(LPCTSTR comname, DWORD baud, LPCTSTR frame, BYTE busAddr, RFID_READER_HANDLE *o_hr);
err_t RFIDLIB_API LSG428_TcpOpen(LPCTSTR readerIPAddr, WORD remotePort, LPCTSTR localIPToBind, RFID_READER_HANDLE *o_hr) ;


















#endif
