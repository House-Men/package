#ifndef __RFIDLIB_ANWE818_H__
#define __RFIDLIB_ANWE818_H__

#include "rfidlib.h"

err_t RFIDLIB_API ANWE818_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,RFID_READER_HANDLE *o_hr)  ;
err_t RFIDLIB_API ANWE818_Close(RFID_READER_HANDLE hr) ;


#endif