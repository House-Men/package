#ifndef __RFIDLIB_DRV_UM200_H__
#define __RFIDLIB_DRV_UM200_H__


#ifdef __cplusplus
extern "C" {
#endif

	err_t RFIDLIB_API UM200_Open(LPCTSTR comname, DWORD baud, LPCTSTR frame, BYTE busAddr, RFID_READER_HANDLE *o_hr /* out parameter */);




#ifdef __cplusplus
}
#endif











#endif
