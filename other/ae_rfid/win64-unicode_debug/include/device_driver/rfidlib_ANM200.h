#ifndef __RFIDLIB_ANM200_H__
#define __RFIDLIB_ANM200_H__



/*
* Reader system mode
*/
enum
{
	ANM200_SYSMODE_HOST =0x00,
	ANM200_SYSMODE_SCAN
} ;

/*
*  Scan data option 
*/




/*
*/
DWORD RFIDLIB_API ANRPAN_GetLibVersion(LPTSTR buf ,DWORD nSize )  ;
err_t RFIDLIB_API ANRPAN_Open(LPCTSTR comname,DWORD baud,LPCTSTR frame,RFID_READER_HANDLE *o_hr /* out parameter */)  ;
err_t RFIDLIB_API ANRPAN_Close(RFID_READER_HANDLE hr) ;












#endif