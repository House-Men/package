#ifndef __RFIDLIB_API_ST_ISO144443B_H__
#define __RFIDLIB_API_ST_ISO144443B_H__



#ifdef __cplusplus
extern "C" {
#endif



DWORD RFIDLIB_API STISO14443B_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;


err_t RFIDLIB_API STISO14443B_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
										  DWORD *aip_id,
										  DWORD *tag_id,
										  DWORD * ant_id,
										  BYTE *chip_id,
										  BYTE uid[],
										  DWORD *uidLen)  ;


RFID_DN_HANDLE RFIDLIB_API STISO14443B_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList,BYTE AntennaID) ;

err_t RFIDLIB_API STISO14443B_Connect(RFID_READER_HANDLE hr,DWORD tagType,BYTE chip_id,RFID_TAG_HANDLE *ht);

err_t RFIDLIB_API STISO14443B_ReadBlocks(RFID_READER_HANDLE hr,
										RFID_TAG_HANDLE ht, /* Tag handle connected */
										DWORD blkAddr,/* Block number  */
										DWORD numOfBlksToRead, /* in:Number of blocks to read  */
										DWORD *numOfBlksRead,/* ,out: blocks read */
										BYTE bufBlocks[],/*  buffer for storing block data ,4 * num_of_blks */
										DWORD nSize, /* in:size of the buffer */
										DWORD *bytesBlkDatRead);
err_t RFIDLIB_API STISO14443B_WriteBlocks(RFID_READER_HANDLE hr,
										RFID_TAG_HANDLE ht, /* Tag handle connected */
										DWORD blkAddr,
										DWORD numOfBlks,
										BYTE newBlksData[],
										DWORD bytesToWrite);



#ifdef __cplusplus
}
#endif







#endif
