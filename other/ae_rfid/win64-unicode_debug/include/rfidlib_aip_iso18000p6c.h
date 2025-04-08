#ifndef __RFIDLIB_API_ISO18000P6C_H__
#define __RFIDLIB_API_ISO18000P6C_H__

#ifdef __cplusplus
extern "C" {
#endif


	DWORD RFIDLIB_API ISO18000p6C_GetLibVersion(LPTSTR buf, DWORD nSize /* in character */);
	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList,
		BYTE AntennaID /* By default set to 0,apply to all antenna */,
		BYTE Sel,
		BYTE Session,
		BYTE Target,
		BYTE Q);
	err_t RFIDLIB_API  ISO18000p6C_SetInvenSelectParam(RFID_DN_HANDLE hIso18000p6CInvenParam,
		BYTE target,
		BYTE action,
		BYTE memBank,
		DWORD dwPointer,
		BYTE maskBits[],
		BYTE maskBitLen,
		BYTE truncate);
	err_t RFIDLIB_API ISO18000p6C_SetInvenMetaDataFlags(RFID_DN_HANDLE hIso18000p6CInvenParam, DWORD flags);

	err_t RFIDLIB_API ISO18000p6C_SetInvenReadParam(RFID_DN_HANDLE hIso18000p6CInvenParam, BYTE MemBank, DWORD WordPtr, BYTE WordCount);
	err_t RFIDLIB_API ISO18000p6C_SetInvenAccessPassword(RFID_DN_HANDLE hIso18000p6CInvenParam, DWORD pwd);


	err_t RFIDLIB_API ISO18000p6C_ParseTagReport(RFID_DN_HANDLE hTagReport,
		DWORD *aip_id,
		DWORD *tag_id,
		DWORD * ant_id,
		DWORD *metaFlags,
		BYTE tagdata[],
		DWORD *tdLen /* IN:max size of the tagdata buffer ,OUT:bytes written into tagdata buffer */);


	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateTAWrite(RFID_DN_HANDLE hIso18000p6CInvenParam,
		BYTE memBank,
		DWORD wordPtr,
		DWORD wordCnt,
		BYTE pdatas[],
		DWORD nSize);


	err_t RFIDLIB_API ISO18000p6C_CheckTAWriteResult(RFID_DN_HANDLE hTagReport);

	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateTALock(RFID_DN_HANDLE hIso18000p6CInvenParam,
		WORD mask,
		WORD action);

	err_t RFIDLIB_API ISO18000p6C_CheckTALockResult(RFID_DN_HANDLE hTagReport);


	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateTAKill(RFID_DN_HANDLE hIso18000p6CInvenParam, DWORD password, BYTE rfu);

	err_t RFIDLIB_API ISO18000p6C_CheckTAKillResult(RFID_DN_HANDLE hTagReport);

	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateTABlockWrite(RFID_DN_HANDLE hIso18000p6CInvenParam,
		BYTE memBank,
		DWORD wordPtr,
		DWORD wordCnt,
		BYTE pdatas[],
		DWORD nSize);

	RFID_DN_HANDLE RFIDLIB_API ISO18000p6C_CreateTABlockErase(RFID_DN_HANDLE hIso18000p6CInvenParam,
		BYTE memBank,
		DWORD wordPtr,
		DWORD wordCnt);


	err_t RFIDLIB_API ISO18000p6C_ParseTagReportV2(
		RFID_DN_HANDLE hTagReport,
		DWORD *aip_id,
		DWORD *tag_id,
		DWORD * ant_id,
		BYTE epc[],
		DWORD *dLen);

	err_t RFIDLIB_API ISO18000p6C_Connect(
		RFID_READER_HANDLE hr,
		DWORD tag_id,
		BYTE epc[], 
		BYTE epcLen,
		DWORD accessPwb, 
		RFID_TAG_HANDLE *ht);

	err_t RFIDLIB_API ISO18000p6C_Read(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE memBank,
		DWORD wordStart,
		DWORD wordCnt,
		BYTE wordData[],
		DWORD *nSize);

	err_t RFIDLIB_API ISO18000p6C_Write(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE memBank,
		DWORD wordStart,
		DWORD workCnt,
		BYTE wordData[],
		DWORD nSize);



	err_t RFIDLIB_API ISO18000p6C_Lock(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		WORD mask,
		WORD action);

	err_t RFIDLIB_API ISO18000p6C_Kill(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		DWORD killPwb,
		BYTE rfu);


	err_t RFIDLIB_API ISO18000p6C_BlockWrite(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE memBank,
		DWORD wordStart,
		DWORD workCnt,
		BYTE wordData[],
		DWORD nSize);


	err_t RFIDLIB_API ISO18000p6C_BlockErase(
		RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE ht,
		BYTE memBank,
		DWORD wordStart,
		DWORD workCnt);


	err_t RFIDLIB_API NXPUCODE_EnableEAS(RFID_READER_HANDLE hr,RFID_TAG_HANDLE ht);
	err_t RFIDLIB_API NXPUCODE_DisableEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
	err_t RFIDLIB_API NXPUCODE_EASCheck(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE *flag);

#ifdef __cplusplus
}
#endif


#endif

