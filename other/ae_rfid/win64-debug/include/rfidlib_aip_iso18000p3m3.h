#ifndef __RFIDLIB_AIP_ISO18000P3M3_H__
#define __RFIDLIB_AIP_ISO18000P3M3_H__

#ifdef __cplusplus
extern "C" {
#endif


DWORD RFIDLIB_API ISO18000p3m3_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */) ;


RFID_DN_HANDLE RFIDLIB_API ISO18000p3m3_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList,
													 BYTE AntennaID /* By default set to 0,apply to all antenna */,
													BYTE Sel,
												   BYTE Session,
													BYTE Q 
													 )  ;

err_t RFIDLIB_API  ISO18000p3m3_SetInvenSelectParam(RFID_DN_HANDLE hIso18000p3m3InvenParam ,
											        BYTE target ,
													 BYTE action ,
													  BYTE memBank ,
													    DWORD dwPointer,
														BYTE maskBits[],
														  BYTE maskBitLen,
														  BYTE truncate) ;

err_t RFIDLIB_API ISO18000p3m3_SetInvenReadParam(RFID_DN_HANDLE hIso18000p3m3InvenParam ,BYTE MemBank ,DWORD WordPtr,BYTE WordCount) ;



err_t RFIDLIB_API ISO18000p3m3_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
												  DWORD *aip_id,
												  DWORD *tag_id,
												  DWORD * ant_id,
												  DWORD *metaFlags,
												  BYTE tagdata[],
												  DWORD *tagDataLen)   ;


err_t RFIDLIB_API ISO18000p3m3_Connect(RFID_READER_HANDLE hr ,
								   DWORD tagType,//0:reader default setting
								   BYTE epcBits[] ,
								   DWORD epcBitsLen ,
								   BOOLEAN setPwd, /*  «∑Ò—È÷§access password */
								   DWORD accessPwd ,
								   RFID_TAG_HANDLE *ht
								   )  ;




err_t RFIDLIB_API ISO18000p3m3_Read(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht ,
									BYTE memBank,
									DWORD startWord,
									BYTE wordCnt,
									BYTE wordBuffer[],
									DWORD *nSize /* In:size of buffer ;Out:bytes written 	*/
								 ) ;

err_t RFIDLIB_API ISO18000p3m3_Write(RFID_READER_HANDLE hr ,
										RFID_TAG_HANDLE ht ,
										BYTE memBank,
										DWORD startWord,
										BYTE wordCnt,
										BYTE wordData[],
										DWORD nSize) ;


err_t RFIDLIB_API ISO18000p3m3_Lock(RFID_READER_HANDLE hr ,
										RFID_TAG_HANDLE ht ,
										WORD mask ,
										WORD action 
										) ;

err_t RFIDLIB_API ISO18000p3m3_Kill(RFID_READER_HANDLE hr ,
										RFID_TAG_HANDLE ht ,
										DWORD password ,
										BYTE recommission) ;


err_t RFIDLIB_API ISO18000p3m3_ReadPC(RFID_READER_HANDLE hr,
								RFID_TAG_HANDLE ht,
									WORD *pc);


err_t RFIDLIB_API ISO18000p3m3_WritePC(RFID_READER_HANDLE hr,
								RFID_TAG_HANDLE ht,
								WORD mask,
									WORD pc);






#ifdef __cplusplus
}
#endif









#endif