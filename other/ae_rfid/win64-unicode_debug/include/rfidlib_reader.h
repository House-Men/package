#ifndef __RFIDLIB_READER_H__
#define __RFIDLIB_READER_H__


#include "rfidlib.h"

#ifdef __cplusplus
extern "C" {
#endif



	/************************************functions not opened for application*******************************/
	RFID_DN_HANDLE RFIDLIB_API RDR_CreateAccessNoneParamRequest(DWORD accessCode); // use

	err_t RFIDLIB_API RDR_GetCapabilities(RFID_READER_HANDLE hr,
		BYTE Type,
		RFID_DN_HANDLE pCapabilityData /* out */
	);
	err_t RFIDLIB_API RDR_SetConfig(RFID_READER_HANDLE hr,
		RFID_DN_HANDLE  CfgItemSettingData /* Input,Node name is item name */
	);
	err_t RFIDLIB_API RDR_GetConfig(RFID_READER_HANDLE hr,
		RFID_DN_HANDLE pCfgItemGettedData /*Output ,Node name is item name*/
	);
	err_t RFIDLIB_API RDR_EnableAsyncTagReportOutput(RFID_READER_HANDLE hr, BYTE type, WIN_MSG_t msg, HWND hwnd, RFID_EVENT_CALLBACK cb);
	err_t RFIDLIB_API RDR_DisableAsyncTagReportOutput(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_IsSupportInventoryAsyncOutput(RFID_READER_HANDLE hr, BOOLEAN *suppported);
	RFID_DN_HANDLE RFIDLIB_API RDR_CreateSetGetConfigItemList();

	/*********************************functions opened*****************************************************/

	/*
	* get lib version
	*/
	DWORD RFIDLIB_API RDR_GetLibVersion(LPTSTR buf, DWORD nSize /* in character */);
	/*
	* load device drivers
	*/
	err_t RFIDLIB_API RDR_LoadReaderDrivers(LPCTSTR path);
	/*
	* get loaded device driver count
	*/
	DWORD RFIDLIB_API RDR_GetLoadedReaderDriverCount();
	/*
	*get loaded device driver option
	*/
	err_t RFIDLIB_API RDR_GetLoadedReaderDriverOpt(DWORD idx, LPCTSTR option, LPTSTR valueBuffer, DWORD *nSize);
	/*
	*get loaded device driver option by name
	*/
	err_t RFIDLIB_API RDR_GetLoadedReaderDriverOptByName(LPCTSTR ID, LPCTSTR option, LPTSTR valueBuffer, DWORD *nSize);

	DWORD RFIDLIB_API HID_Enum(LPCTSTR DevId);
	err_t RFIDLIB_API HID_GetEnumItem(DWORD indx, BYTE infType, LPTSTR infBuffer, DWORD *nSize);
	DWORD RFIDLIB_API COMPort_Enum(void);
	err_t RFIDLIB_API COMPort_GetEnumItem(DWORD idx, LPTSTR nameBuf, DWORD nSize);
	err_t RFIDLIB_API RDR_Open(LPCTSTR connStr, RFID_READER_HANDLE *hrOut);
	err_t RFIDLIB_API RDR_Close(RFID_READER_HANDLE hr);
	/*
	*create inventory parameter list node
	*/
	RFID_DN_HANDLE RFIDLIB_API RDR_CreateInvenParamSpecList();


	err_t RFIDLIB_API RDR_SetAtennaAsUniqueIdentifier(RFID_DN_HANDLE InvenParamSpecList, BYTE flag);
	/*
	*inventory,support multiple air protocol ,embedded commands
	*/
	err_t RFIDLIB_API RDR_TagInventory(RFID_READER_HANDLE hr,
		BYTE AIType,
		BYTE AntennaCount,
		BYTE AntennaIDs[],
		RFID_DN_HANDLE InvenParamSpecList);
	/*
    * 加入盘点写的命令
	*/
	err_t RFIDLIB_API RDR_AddTagAccessToInvenParam(RFID_DN_HANDLE hInvenParam, RFID_DN_HANDLE hTagAccess);
	/*
    *  解析盘点写的结果
	*/
	err_t RFIDLIB_API RDR_ParseTagDataReportWriteResult(RFID_DN_HANDLE hTagReport, RFID_DN_HANDLE cmd, BYTE *result);
	/*
	* 解析盘点读的数据块数据
	*/
	err_t RFIDLIB_API RDR_ParseTagDataReportBlockData(RFID_DN_HANDLE hTagReport, BYTE *buf, DWORD *nSize);
	/*
	*get tag data report count
	*/
	DWORD RFIDLIB_API RDR_GetTagDataReportCount(RFID_READER_HANDLE hr);
	/*
	*get tag data report
	*/
	RFID_DN_HANDLE	RFIDLIB_API RDR_GetTagDataReport(RFID_READER_HANDLE hr, BYTE seek);
	/*
	*connect tag
	*/
	err_t RFIDLIB_API RDR_TagConnect(RFID_READER_HANDLE hr,
		RFID_DN_HANDLE ConnParms,   /* Connect parameters,inclue AIP id and tag id */
		RFID_TAG_HANDLE *hTag   /* Return handle of the connected picc */
	);
	/*
	*access tag
	*/
	err_t RFIDLIB_API RDR_TagAccess(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE hTag,		/* the handle of connected picc */
		RFID_DN_HANDLE tagAccess
	);
	/*
	*disconnect tag
	*/
	err_t RFIDLIB_API RDR_TagDisconnect(RFID_READER_HANDLE hr,
		RFID_TAG_HANDLE hTag);
	/*
	*disconnect all connected tags
	*/
	err_t RFIDLIB_API RDR_DisconnectAllTags(RFID_READER_HANDLE hr);
    /*
	* get connected tag information
	*/
	err_t RFIDLIB_API  RDR_GetConnectedTagInfo(RFID_READER_HANDLE hr, RFID_TAG_HANDLE hTag, BYTE infType, BYTE *infBuffer, DWORD *nSize);
	/*
	*get reader last return error
	*/
	err_t RFIDLIB_API RDR_GetReaderLastReturnError(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_SetAcessAntenna(RFID_READER_HANDLE hr, BYTE AntennaID);

	err_t RFIDLIB_API RDR_OpenRFTransmitter(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_CloseRFTransmitter(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_SetCommuImmeTimeout(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_ResetCommuImmeTimeout(RFID_READER_HANDLE hr);

	DWORD RFIDLIB_API RDR_GetAntennaInterfaceCount(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_GetOutputCount(RFID_READER_HANDLE hr, BYTE *nCount);

	err_t RFIDLIB_API RDR_GetOutputName(RFID_READER_HANDLE hr, BYTE idxOut, LPTSTR bufName, DWORD *nSize);

	RFID_DN_HANDLE RFIDLIB_API RDR_CreateSetOutputOperations();

	/*
	* outMode:
	  0: No change
	  1: On
	  2: Off
	  3: flash
	*/
	err_t RFIDLIB_API RDR_AddOneOutputOperation(RFID_DN_HANDLE hOperas, BYTE outNo, BYTE outMode, DWORD outFrequency, DWORD outActiveDuration, DWORD outInactiveDuration);

	err_t RFIDLIB_API RDR_SetOutput(RFID_READER_HANDLE hr, RFID_DN_HANDLE outputOpers /* output operations */);

	err_t RFIDLIB_API RDR_LoadFactoryDefault(RFID_READER_HANDLE hr);




	err_t RFIDLIB_API RDR_SystemReset(RFID_READER_HANDLE hr);


	err_t RFIDLIB_API RDR_GetReaderInfor(RFID_READER_HANDLE hr,
		BYTE Type,
		LPTSTR buffer,
		DWORD *nSize);

	err_t RFIDLIB_API RDR_ConfigBlockWrite(RFID_READER_HANDLE hr, DWORD cfgno, BYTE cfgdata[], DWORD nSize, DWORD mask);
	err_t RFIDLIB_API RDR_ConfigBlockRead(RFID_READER_HANDLE hr, DWORD cfgno, BYTE cfgbuff[], DWORD nSize);
	err_t RFIDLIB_API RDR_ConfigBlockSave(RFID_READER_HANDLE hr, DWORD cfgno);

	err_t RFIDLIB_API RDR_CreateRS485Node(RFID_READER_HANDLE hr, DWORD busAddr, RFID_READER_HANDLE *ohrRS485Node);

	err_t RFIDLIB_API RDR_GetSupportedAirInterfaceProtocol(RFID_READER_HANDLE hr, DWORD index, DWORD *AIPType);

	err_t RFIDLIB_API RDR_DetectNoise(RFID_READER_HANDLE hr, BYTE noiseData[], DWORD *nSize);

	err_t RFIDLIB_API RDR_EnableProtocolLog(RFID_READER_HANDLE hr, BYTE methType, WIN_MSG_t msg, HWND hwnd, RFID_EVENT_CALLBACK_NEW cb, void *param);
	err_t RFIDLIB_API RDR_DisalbeProtocolLog(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_GetGPICount(RFID_READER_HANDLE hr, DWORD *oCount);

	err_t RFIDLIB_API RDR_ExeSpecialControlCmd(RFID_READER_HANDLE hr, LPCTSTR cmd, LPCTSTR params, LPTSTR result, DWORD *nSize);

	err_t RFIDLIB_API RDR_GetGPIsStatus(RFID_READER_HANDLE hr/* in */,
		BYTE GPIs[]/* in */,
		WORD number /* in */,
		BYTE status[] /* out */);

	err_t RFIDLIB_API RDR_SetEventHandler(RFID_READER_HANDLE hr, BYTE eventType, BYTE methType, UINT msg, HWND hwnd, RFID_EVENT_CALLBACK_NEW cb, VOID *param);
	err_t RFIDLIB_API RDR_GetAirInterfaceProtName(RFID_READER_HANDLE hr, DWORD AIPType, LPTSTR namebuf, DWORD nSize);
	err_t RFIDLIB_API RDR_LoadAuthKey(RFID_READER_HANDLE hr, BYTE storeType, BYTE keyType, BYTE key[], WORD keylen);
	err_t RFIDLIB_API RDR_SelectAuthKey(RFID_READER_HANDLE hr, BYTE keyType);
	err_t RFIDLIB_API RDR_CommandTransceive(RFID_READER_HANDLE hr, DWORD cmd, BYTE *prmDataSnd, DWORD bytesToSnd, BYTE *prmDataRecv, DWORD *bytesRecv, DWORD timeout);
	err_t RFIDLIB_API RDR_StartBootLoader(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_UpdateHardSerialNum(RFID_READER_HANDLE hr, BYTE sernum[], WORD length);

	err_t RFIDLIB_API RDR_UpdateHardProductNum(RFID_READER_HANDLE hr, BYTE pid[], WORD length);

	err_t RFIDLIB_API RDR_ResetRF(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API DNODE_Destroy(RFID_DN_HANDLE dn);

	err_t RFIDLIB_API RDR_SetInvenStopTrigger(RFID_DN_HANDLE hInvenParams, BYTE stopTriggerType, DWORD maxTimeout, DWORD triggerValue);

	err_t RFIDLIB_API RDR_IsSupportEmbeddedTagAccess(RFID_READER_HANDLE hr, BOOLEAN *isSupported);

	DWORD RFIDLIB_API Bluetooth_Enum();
	err_t RFIDLIB_API Bluetooth_GetEnumItem(DWORD idx, BYTE infType, LPTSTR nameBuf, DWORD *nSize);

	/*
	* 标示在关闭之前停止所有通行操作 ， 通信连接有可能会中断
	*/
	err_t RFIDLIB_API RDR_SetStopCommBeforeClose(RFID_READER_HANDLE hr);


	err_t  RFIDLIB_API RDR_GetSystemTime(RFID_READER_HANDLE hr, DWORD *year, BYTE *month, BYTE *day, BYTE *hour, BYTE *minute, BYTE *second);
	err_t  RFIDLIB_API RDR_SetSystemTime(RFID_READER_HANDLE hr, DWORD year, BYTE month, BYTE day, BYTE hour, BYTE minute, BYTE second);
	err_t RFIDLIB_API RDR_BuffMode_FetchRecords(RFID_READER_HANDLE hr, DWORD flags);
	err_t RFIDLIB_API RDR_BuffMode_ClearRecords(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_BuffMode_FlashEmpty(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_FetchTodayPassingData(RFID_READER_HANDLE hr, BYTE nFlag, BYTE nAddr);
	err_t RFIDLIB_API RDR_FetchHistoryPassingData(RFID_READER_HANDLE hr, BYTE nFlag, BYTE nAddr);
	RFID_DN_HANDLE	RFIDLIB_API RDR_GetTodayPassingReport(RFID_READER_HANDLE hr, BYTE seek);
	RFID_DN_HANDLE	RFIDLIB_API RDR_GetHistoryPassingReport(RFID_READER_HANDLE hr, BYTE seek);
	err_t RFIDLIB_API RDR_ParseTodayPassingReport(RFID_DN_HANDLE hReport, BYTE *mDirection, DWORD *mPassingValue, BYTE mTime[]);
	err_t RFIDLIB_API RDR_ParseHistoryPassingReport(RFID_DN_HANDLE hReport, DWORD *mInValue, DWORD *mOutValue, BYTE mDate[]);

	err_t RFIDLIB_API RDR_ResetBackupAntenna(RFID_READER_HANDLE hr);

	err_t  RFIDLIB_API RDR_StartRO(RFID_READER_HANDLE hr, DWORD ROSepcID);
	err_t  RFIDLIB_API RDR_StopRO(RFID_READER_HANDLE hr, DWORD ROSepcID);

	err_t  RFIDLIB_API RDR_ParseTagDataReportRaw(RFID_DN_HANDLE hTagReport, BYTE rawBuffer[], DWORD *nSize);
	err_t  RFIDLIB_API  RDR_BuffMode_StartReportCollection(RFID_READER_HANDLE hr);
	err_t  RFIDLIB_API  RDR_BuffMode_StopReportCollection(RFID_READER_HANDLE hr);
	err_t  RFIDLIB_API  RDR_BuffMode_StopReportCollectionNoWait(RFID_READER_HANDLE hr);
	err_t  RFIDLIB_API RDR_ResetPassingCounter(RFID_READER_HANDLE hr, DWORD flag);
	err_t  RFIDLIB_API RDR_GetPassingCounter(RFID_READER_HANDLE hr, DWORD *inFlow, DWORD *outFlow);
	err_t  RFIDLIB_API RDR_ChangePassingCounter(RFID_READER_HANDLE hr, BYTE addr, DWORD inFlow, DWORD outFlow);
	err_t  RFIDLIB_API RDR_SetPassingCounter(RFID_READER_HANDLE hr, BYTE addr, DWORD inFlow, DWORD outFlow);
	err_t  RFIDLIB_API RDR_ReverseInOutDirection(RFID_READER_HANDLE hr);
	err_t  RFIDLIB_API RDR_Login(RFID_READER_HANDLE hr, BYTE pwd[]);
	err_t  RFIDLIB_API RDR_EnablePasswordLogin(RFID_READER_HANDLE hr, BYTE pwd[], BOOLEAN enable);
	err_t  RFIDLIB_API RDR_UpdateLoginPassword(RFID_READER_HANDLE hr, BYTE pwd[], BYTE newPwd[]);
	err_t  RFIDLIB_API RDR_GetAIPTypeName(RFID_READER_HANDLE hr, DWORD AIP_ID, LPTSTR nameBuf, DWORD *nSize);
	err_t  RFIDLIB_API RDR_GetTagTypeName(RFID_READER_HANDLE hr, DWORD AIP_ID, DWORD TAG_ID, LPTSTR nameBuf, DWORD *nSize);
	err_t  RFIDLIB_API RDR_ResetTagFilterCounter(RFID_READER_HANDLE hr);
	err_t  RFIDLIB_API RDR_TestWGIF(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_ModuleStartBootLoader(RFID_READER_HANDLE hr, LPCTSTR sDevId);
	err_t RFIDLIB_API RDR_ModuleStopMBootLoader(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_ModuleTransferData(RFID_READER_HANDLE hr, DWORD timeout, BYTE transferData[], DWORD nTransferData, BYTE dataBack[], DWORD *nDataBackSize);

	err_t RFIDLIB_API RDR_GetIOPortIDs(RFID_READER_HANDLE hr, BYTE OutputIDs[], DWORD *OutputSize, BYTE InputIDs[], DWORD *InputSize);

	err_t RFIDLIB_API RDR_DetectAntennaCount(RFID_READER_HANDLE hr, DWORD *mCount);
	err_t RFIDLIB_API RDR_DiagnosisReader(RFID_READER_HANDLE hr, BYTE mode, DWORD *flag);
	err_t RFIDLIB_API RDR_GetNoiseLevel(RFID_READER_HANDLE hr, BYTE AntennaID, WORD* min, WORD* avg, WORD* max);
	err_t RFIDLIB_API RDR_GetNoiseLevelWithBase(RFID_READER_HANDLE hr, BYTE AntennaID, WORD * base, BYTE *count, WORD*data);

	err_t RFIDLIB_API RDR_CheckAntennas(RFID_READER_HANDLE hr, BYTE option, BYTE AntennaCount, BYTE AntennaID[], BYTE sta[], DWORD swr[]);
	err_t RFIDLIB_API RDR_AdjustAntenna(RFID_READER_HANDLE hr, BYTE antenna_id, WORD calib_imp);

	err_t RFIDLIB_API RDR_CheckAntennasV2(RFID_READER_HANDLE hr, BYTE AntennaCount, BYTE AntennaID[], BYTE sta[], DWORD swr[]);

	err_t RFIDLIB_API RDR_GetReaderDetailInfor(RFID_READER_HANDLE hr, WORD info_s, RFID_DN_HANDLE *Detail);
	err_t RFIDLIB_API RDR_ParseReaderDetailBasic(RFID_DN_HANDLE report, BYTE product[]/*3 bytes*/, BYTE firmware[]/*2 bytes*/, BYTE hardware[]/*2 bytes*/, BYTE serial[]/*5 bytes*/);
	err_t RFIDLIB_API RDR_ParseReaderDetailAntennaCount(RFID_DN_HANDLE report, BYTE* mAntennaCount);
	err_t RFIDLIB_API RDR_ParseReaderDetailIO(RFID_DN_HANDLE report, BYTE input_ids[], BYTE *input_size, BYTE output_ids[], BYTE *output_size);
	err_t RFIDLIB_API RDR_ParseReaderDetailMuxCount(RFID_DN_HANDLE report, BYTE *muxCount);
	err_t RFIDLIB_API RDR_ParseReaderDetailMuxInfo(RFID_DN_HANDLE report, DWORD index, BYTE *addr, BYTE*ports, WORD* firmware, BYTE*sta);
	err_t RFIDLIB_API RDR_ParseReaderDetailComm(RFID_DN_HANDLE report, WORD* comm);
	err_t RFIDLIB_API RDR_DetectMux(RFID_READER_HANDLE hr, BYTE *cnt);
	err_t RFIDLIB_API RDR_GetInputStatus(RFID_READER_HANDLE hr, BYTE InputIO[], BYTE Status[], DWORD *nSize);
	err_t RFIDLIB_API RDR_SetFactoryInfor(RFID_READER_HANDLE hr, BYTE opt, BYTE pwd[], BYTE sn[]);
	err_t RFIDLIB_API RDR_DetectOutputCount(RFID_READER_HANDLE hr, DWORD *mCount);
	err_t RFIDLIB_API RDR_RFTransmitterOperate(RFID_READER_HANDLE hr, BYTE opt, BYTE ant);

	err_t RFIDLIB_API RDR_ConfigBlockLock(RFID_READER_HANDLE hr, BYTE pwb[], DWORD cfgno, DWORD mask, DWORD lock);
	err_t RFIDLIB_API RDR_ConfigBlockLockState(RFID_READER_HANDLE hr, DWORD cfgno, DWORD *sta);
	err_t RFIDLIB_API RDR_SetMultiAccessAntennas(RFID_READER_HANDLE hr, BYTE antennas[], BYTE nSize);

	err_t RFIDLIB_API RDR_AccessMultipleTags(RFID_READER_HANDLE hr, RFID_DN_HANDLE hTagSet);
	RFID_DN_HANDLE RFIDLIB_API CreateMultipleAccessTagSet(BYTE bDefaultAnt, BYTE bAllAnt, BYTE bAntDelay, DWORD mAntDelayTime);
	err_t RFIDLIB_API RDR_SetLastATagTagType(RFID_DN_HANDLE hTagSet, DWORD tagType);
	err_t RFIDLIB_API RDR_SetLastATagAntennas(RFID_DN_HANDLE hTagSet, BYTE pAnt[], BYTE antCnt);
	err_t RFIDLIB_API RDR_AddLastATagAccessCommand(RFID_DN_HANDLE hTagSet, RFID_DN_HANDLE hCommand);
	err_t RFIDLIB_API RDR_SeekAccessTag(RFID_DN_HANDLE hTagSet, WORD idx);
	RFID_DN_HANDLE RFIDLIB_API RDR_GetTagAccessCommand(RFID_DN_HANDLE hTagSet, BYTE seekType);

	err_t RFIDLIB_API RDR_FridgeInventory(RFID_READER_HANDLE hr, BYTE mode, BYTE mask);
	err_t RFIDLIB_API RDR_FridgeParseTagDataReport(RFID_DN_HANDLE hTagReport,
		BYTE *tag_sta,
		BYTE* ant_id,
		BYTE *tag_data,
		BYTE *nSize);
	RFID_DN_HANDLE RFIDLIB_API RDR_CreateDownloadTagsOperations();
	err_t RFIDLIB_API RDR_AddOneDownloadTagOperation(RFID_DN_HANDLE hOperas, BYTE uid[], BYTE uidlen, BYTE ant);
	err_t RFIDLIB_API RDR_FridgeDownloadTag(RFID_READER_HANDLE hr, RFID_DN_HANDLE hOperas, BYTE mode);


	err_t RFIDLIB_API RDR_SearchLSG(RFID_READER_HANDLE hr);//搜索安全门

	err_t RFIDLIB_API RDR_ClearHistoryRecord(RFID_READER_HANDLE hr);//清除历史记录
	err_t RFIDLIB_API RDR_ClearTodayRecord(RFID_READER_HANDLE hr);//清除实时记录

	err_t RFIDLIB_API RDR_SaveSearchLSG(RFID_READER_HANDLE hr);//开始搜索安全门

	err_t RFIDLIB_API RDR_GetSingleDoorInfo(RFID_READER_HANDLE hr, BYTE sid, LPTSTR buffer, DWORD *nSize);//获取单片门信息
	err_t RFIDLIB_API RDR_GetSingleDoorSWR(RFID_READER_HANDLE hr, BYTE sid, BYTE antennnaCnt, BYTE * ant, WORD *swr);//获取单片门驻波
																													 //err_t RFIDLIB_API RDR_GetSingleDoorSWRReport(RFID_READER_HANDLE hr, BYTE sid, BYTE aid, WORD * aswr);

	err_t RFIDLIB_API RDR_GetSingleDoorTemp(RFID_READER_HANDLE hr, BYTE sid, DWORD * temp);//获取单片门温度
	err_t RFIDLIB_API RDR_GetSingleDoorRFIDPower(RFID_READER_HANDLE hr, BYTE sid, DWORD * power);//获取单片门射频功率
	err_t RFIDLIB_API RDR_GetSingleDoorNoiseLevel(RFID_READER_HANDLE hr, BYTE sid, BYTE antennaCnt, BYTE * aid, DWORD* NOI_MIN, DWORD *NOI_AVG, DWORD *NOI_MAX);//获取单片门噪声
																																							   //err_t RFIDLIB_API RDR_GetSingleDoorNosieLevelReport(RFID_READER_HANDLE hr, BYTE sid, BYTE aid, DWORD* NOI_MIN, DWORD *NOI_AVG, DWORD *NOI_MAX);


	err_t RFIDLIB_API RDR_GetSingleDoorSysErr(RFID_READER_HANDLE hr, BYTE sid, DWORD *mcErrFlag);//获取单片安全门的系统错误
	err_t RFIDLIB_API RDR_GetSingleDoorOutput(RFID_READER_HANDLE hr, BYTE sid, BYTE *TE, BYTE * FRQ, DWORD * ACTIVE, DWORD *DEACTIVE, DWORD mask);
	err_t RFIDLIB_API RDR_GetSingleDoorMos(RFID_READER_HANDLE hr, BYTE sid, BYTE *TE, BYTE * FRQ, DWORD * ACTIVE, DWORD *DEACTIVE);

	err_t RFIDLIB_API RDR_SetSingleDoorOutput(RFID_READER_HANDLE hr, BYTE sid, BYTE *TE, BYTE *FRQ, DWORD *ACTIVE, DWORD *DEACTIVE, DWORD mask, BOOL bsave);
	err_t RFIDLIB_API RDR_SetSingleDoorMos(RFID_READER_HANDLE hr, BYTE sid, BYTE *TE, BYTE  *FRQ, DWORD  *ACTIVE, DWORD *DEACTIVE);

	err_t RFIDLIB_API RDR_GetLSGSearchReport(RFID_READER_HANDLE hr, BYTE * sta);//搜索单门
	RFID_DN_HANDLE RFIDLIB_API RDR_FetchLSGSearchReport(RFID_READER_HANDLE hr, BYTE seek);//获取单门搜索的一片门的句柄
	err_t RFIDLIB_API RDR_ParseLSGSearchReport(RFID_DN_HANDLE hd, BYTE *sid, BYTE *type, BYTE * gid, BYTE * gidLength);//解析单门搜索信息

	err_t RFIDLIB_API RDR_ParseLSGWarnningReport(RFID_DN_HANDLE hd, BYTE *sid, BYTE * eventtype, BYTE * direction, BYTE * rawData, DWORD * size);

	err_t RFIDLIB_API RDR_GetSingleDoorOnlineStatus(RFID_READER_HANDLE hr, BYTE *num, BYTE *SID, BYTE *TYPE, BYTE *gid, BYTE *gidlength, BYTE *STA);//获取单门在线状态


	err_t RFIDLIB_API RDR_BootLoaderCmdGetSta(RFID_READER_HANDLE hr, BYTE *pStatus);
	err_t RFIDLIB_API RDR_BootLoaderCmdGetProgramInfor(RFID_READER_HANDLE hr, BYTE *pFlag, WORD *pMaxSize, DWORD *pMaxTime, DWORD *pAppSize, BYTE *pFlashIDBuf, DWORD *nSizeFlashID);
	err_t RFIDLIB_API RDR_BootLoaderCmdProgramInit(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_BootLoaderCmdProgram(RFID_READER_HANDLE hr, BYTE *pData, DWORD nSize);
	err_t RFIDLIB_API RDR_BootLoaderCmdProgramFini(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API RDR_BootLoaderCmdGetRandom(RFID_READER_HANDLE hr, BYTE *pRandom);
	err_t RFIDLIB_API RDR_BootLoaderCmdGetProgramedSize(RFID_READER_HANDLE hr, DWORD *pSize);
	err_t RFIDLIB_API RDR_BootLoaderCmdRunApp(RFID_READER_HANDLE hr);
	void RFIDLIB_API RDR_BootLoaderSetMaxRxWaitTime(RFID_READER_HANDLE hr, DWORD time);
	DWORD RFIDLIB_API RDR_BootLoaderMinBufferSize(RFID_READER_HANDLE hr, DWORD pckBufSize);
	DWORD RFIDLIB_API RDR_BootLoaderMinPacketSize(RFID_READER_HANDLE hr);
	BYTE RFIDLIB_API  RDR_BootLoaderGetErrSta(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API RDR_ResetSingleDoor(RFID_READER_HANDLE hr, BYTE sid);//重启安全门
	err_t RFIDLIB_API RDR_StartSinlgeDoorBootloader(RFID_READER_HANDLE hr, BYTE sid, int mode);//
	err_t RFIDLIB_API RDR_StopSingleDoorBootloader(RFID_READER_HANDLE hr, BYTE sid);//停止单片门的升级
	err_t RFIDLIB_API RDR_SingleDoorAVAlarm(RFID_READER_HANDLE hr, BYTE sid);//单片安全门声光报警
	err_t RFIDLIB_API RDR_StopAntiTheft(RFID_READER_HANDLE hr);//停止安全门防盗
	err_t RFIDLIB_API RDR_ResumeAntiTheft(RFID_READER_HANDLE hr);//恢复安全门防盗

	/**测试工具用到的接口*/
	err_t RFIDLIB_API RDR_DeviceDebugAntTest(RFID_READER_HANDLE hr, BYTE *data, BYTE nSize);
	err_t RFIDLIB_API RDR_DeviceDebugBeepTest(RFID_READER_HANDLE hr, BYTE type);
	err_t RFIDLIB_API RDR_DeviceDebugLedOrOutput(RFID_READER_HANDLE hr, BYTE  time, BYTE frq, BOOL ledOrOutput/*false:led ture:output*/);
	err_t RFIDLIB_API RDR_DeviceDebugRFIDPower(RFID_READER_HANDLE hr, BYTE pwr);
	err_t RFIDLIB_API RDR_AntSel(RFID_READER_HANDLE hr, BYTE ant, BYTE dc);
	err_t RFIDLIB_API RDR_InputSelect(RFID_READER_HANDLE hr, BYTE port);
	err_t RFIDLIB_API RDR_DeviceDebugAlarmOut(RFID_READER_HANDLE hr, BYTE OPT);
	err_t RFIDLIB_API RDR_DeviceDebugAntCheck(RFID_READER_HANDLE hr, BYTE option, BYTE *num, BYTE *id, WORD *swr);
	err_t RFIDLIB_API RDR_DeviceDebugGetDiagnosisData(RFID_READER_HANDLE hr, WORD flag, WORD * temp, WORD * rfpwr, DWORD * sysErr);



	/**LSG428 618 拓展的记录查询接口***/
	err_t RFIDLIB_API RDR_GetLSGRecord(RFID_READER_HANDLE hr, BYTE option, BYTE flag);
	err_t RFIDLIB_API RDR_ParseHistoryPassingReport_V2(RFID_DN_HANDLE hReport, DWORD *mInValue, DWORD *mOutValue, BYTE mDate[]);
	err_t RFIDLIB_API RDR_ParseTodayPassingReport_V2(RFID_DN_HANDLE hReport, BYTE *mDirection, DWORD *mPassingValue, BYTE mTime[]);
	err_t RFIDLIB_API LSG_SetOutput(RFID_READER_HANDLE hr, BYTE sid, RFID_DN_HANDLE outputOpers /* output operations */);
	err_t  RFIDLIB_API RDR_GetPassingCounter_V2(RFID_READER_HANDLE hr, DWORD *inFlow, DWORD *outFlow);
	err_t  RFIDLIB_API RDR_ParseTagDataReportRaw_V2(RFID_DN_HANDLE hTagReport, BYTE rawBuffer[], DWORD *nSize);


	err_t RFIDLIB_API RDR_GetAlarmEventType(RFID_READER_HANDLE hr, BYTE type, LPTSTR buffer, DWORD *nSize);

	//err_t RFIDLIB_API LSG_FetchStoredDataAndAlaramFromGate(RFID_READER_HANDLE hr, BOOLEAN del, DWORD additional, BYTE gid, DWORD *pcIN, DWORD * pcOUT);

	err_t RFIDLIB_API LSG_FetchStoredDataAndAlaramFromGate(RFID_READER_HANDLE hr, BOOLEAN del, DWORD additional, BYTE gid, DWORD*pcInTotal, DWORD*pcOutTotal, DWORD*pcInDay, DWORD*pcOutDay);

	DWORD RFIDLIB_API   LSG_GetBufRecordCount(RFID_READER_HANDLE hr, BYTE type);
	RFID_DN_HANDLE RFIDLIB_API   LSG_ReadBufRecord(RFID_READER_HANDLE hr, BYTE seek, BYTE type);
	err_t RFIDLIB_API  LSG_ParseAlaramRecord(RFID_DN_HANDLE hTagReport, BYTE *sid, BYTE *date, BYTE *event, BYTE  *dFla, BYTE *uid, DWORD *uSize, BYTE *user, DWORD *userSize);
	err_t RFIDLIB_API  LSG_ParseDayPCRecord(RFID_DN_HANDLE hTagReport, BYTE *date, DWORD *inPC, DWORD *outPC);
	err_t  RFIDLIB_API  LSG_ParseRealtimePCRecord(RFID_DN_HANDLE hTagReport, BYTE *datetime, BYTE *dir, DWORD *PC);
	err_t RFIDLIB_API  LSG_InitPC(RFID_READER_HANDLE hr, BYTE type, DWORD inPC, DWORD outPC);
	err_t RFIDLIB_API  LSG_Alaram(RFID_READER_HANDLE hr);

	err_t RFIDLIB_API LSG_FetchPCFromGate(RFID_READER_HANDLE hr, BYTE option, DWORD *pcInTotal, DWORD*pcOutTotal, DWORD*pcInDay, DWORD*pcOutDay);

	err_t RFIDLIB_API LSG_SetAtmosphereLight(RFID_READER_HANDLE hr, BYTE sid, BYTE id, BYTE type, DWORD v, WORD FLASH_AT, WORD FLASH_DT);


	err_t RFIDLIB_API BookShelf_SetLID(RFID_READER_HANDLE hr, BYTE lid);
	err_t RFIDLIB_API BookShelf_SetLSN(RFID_READER_HANDLE hr, BYTE *lsn, BYTE len);
	err_t RFIDLIB_API BookShelf_GetOnlineStatus(RFID_READER_HANDLE hr, BOOL *sta);
	err_t RFIDLIB_API BookShelf_SetLayerParams(RFID_READER_HANDLE hr, RFID_DN_HANDLE params);
	err_t RFIDLIB_API BookShelf_SetLayerLed(RFID_READER_HANDLE hr, RFID_DN_HANDLE params);

	RFID_DN_HANDLE RFIDLIB_API BookShelf_CreateLayerParamsManager();
	RFID_DN_HANDLE RFIDLIB_API BookShelf_CreateLayerParams(int offset, BYTE *data, BYTE len);
	err_t RFIDLIB_API BookShelf_AddLayerParams(RFID_DN_HANDLE layerParamsManager, RFID_DN_HANDLE layerParam);

	err_t RFIDLIB_API BookShelf_DestoryLayerParamsManager(RFID_DN_HANDLE layerParamsManager);


	RFID_DN_HANDLE RFIDLIB_API BookShelf_CreateLedControlManager();
	RFID_DN_HANDLE RFIDLIB_API BookShelf_CreateLedControl(int id, int type, DWORD activeTime, WORD flashAT, WORD flashDT);
	err_t RFIDLIB_API BookShelf_AddLedControl(RFID_DN_HANDLE ledManager, RFID_DN_HANDLE ledControl);

	err_t RFIDLIB_API BookShelf_DestoryLedControlManager(RFID_DN_HANDLE ledManager);

	err_t RFIDLIB_API BookShelf_GetIRSta(RFID_READER_HANDLE hr, BYTE *sta);


	err_t RFIDLIB_API LSC100_SetLayerLed(RFID_READER_HANDLE hr, int layid, RFID_DN_HANDLE params);

	err_t RFIDLIB_API LSC100_Inventory(RFID_READER_HANDLE hr, BYTE opt, BYTE *lays, BYTE laycnt,WORD startPos,BYTE readLen,int timeout);

	err_t RFIDLIB_API LSC100_ParseReport(RFID_HANDLE hReport, BYTE *type, BYTE *layid, WORD *rssi, BYTE *uid, BYTE *uidlen,BYTE *barcode,BYTE *barcodeLen);

	err_t RFIDLIB_API LSC100_GetIRSta(RFID_READER_HANDLE hr, BYTE lid, BYTE *sta);

	err_t RFIDLIB_API LSC100_GetLayerInfor(RFID_READER_HANDLE hr,int lid, LPTSTR buffer, DWORD *nSize/* buffer size in character */); //获取层控制器信息;

	err_t RFIDLIB_API LSC100_SetOutput(RFID_READER_HANDLE hr, RFID_DN_HANDLE handle);

	err_t RFIDLIB_API LSC100_DiagnosisBookShelf(RFID_READER_HANDLE hr, DWORD *flag);

	err_t RFIDLIB_API LSC100_StartModuleBootLoader(RFID_READER_HANDLE hr, BYTE flag,int index);

	err_t RFIDLIB_API LSC100_SystemReset(RFID_READER_HANDLE hr, BYTE flag);

	err_t RFIDLIB_API RDR_GetAntennaSWR(RFID_READER_HANDLE hr, BYTE AntennaCount, BYTE AntennaID[], BYTE sta[], DWORD swr[]);

	err_t RFIDLIB_API LSC100_GetLEDControlInfo(RFID_READER_HANDLE hr, BYTE * pAddr,BYTE* pDisp);

	err_t RFIDLIB_API LSC100_SetDispText(RFID_READER_HANDLE hr, BYTE cid, BYTE sid, BYTE option, WORD dispTime, BYTE *pText, BYTE textLen);


	err_t RFIDLIB_API LSC100_LayerWriteAFIEas(RFID_READER_HANDLE hr, BYTE lid, BOOL writeAfi, BOOL writeEAS, BYTE afiVal, BOOL EasEnable);

	/*2020-08-28 添加RD5200 /RD2100 /M22 读卡器开始支持*/
	/* 获取设备硬件唯一识别信息*/
	err_t RFIDLIB_API RDR_GetDeviceUniqueID(RFID_READER_HANDLE hr, BYTE *pHUIDData, BYTE *nSize);
	/* 更新用户设备数字签名*/
	err_t RFIDLIB_API RDR_UpdateUserSignature(RFID_READER_HANDLE hr, BYTE *pSig, BYTE nLen);
	/* 读用户设备数字签名*/
	err_t RFIDLIB_API RDR_ReadUserSignature(RFID_READER_HANDLE hr, BYTE *pSig, BYTE *nSize);
	/*2020-08-28 完成*/
	
	
	err_t RFIDLIB_API LSG_GetIRSta(RFID_READER_HANDLE hr, BYTE sid, DWORD *ir_tri_cnt, BYTE *ir_num);
	err_t RFIDLIB_API LSG_GetIRCoverSta(RFID_READER_HANDLE hr, BYTE * ir_num, BYTE * irCoverBitMask);

	err_t RFIDLIB_API LSG_DiagnosisFlow(RFID_READER_HANDLE hr, BYTE sid, DWORD *inflow, DWORD *outflow);


	err_t RFIDLIB_API LSG_GetDetectStatus(RFID_READER_HANDLE hr, BYTE *State);
	err_t RFIDLIB_API LSG_StartDetect(RFID_READER_HANDLE hr, BYTE DetectNum);


	err_t RFIDLIB_API  PDA_GetScanKeyState(RFID_READER_HANDLE hr, BYTE * flag);
	err_t RFIDLIB_API  PDA_LowPowerConsumption(RFID_READER_HANDLE hr, BYTE *flag);
	err_t RFIDLIB_API  PDA_GetDeviceStatus(RFID_READER_HANDLE hr, BYTE *DeviceMode, BYTE * TagType);


	err_t RFIDLIB_API  PDA_ParseUHFRecord(RFID_DN_HANDLE hReport, BYTE *flag, BYTE *pDatas, DWORD *pDATALen);
	err_t RFIDLIB_API  PDA_ParseHFRecord(RFID_DN_HANDLE hReport, BYTE *flag, BYTE *pDatas, DWORD *pDATALen);
	err_t RFIDLIB_API  PDA_ParseQRCodeRecord(RFID_DN_HANDLE hReport,BYTE *pData, DWORD *len);
	err_t RFIDLIB_API  PDA_SetHostMode(RFID_READER_HANDLE hr);
	err_t RFIDLIB_API  PDA_SetActiveMode(RFID_READER_HANDLE hr);



	err_t RFIDLIB_API Bookcase_SetBoxAntennas(RFID_READER_HANDLE hr, BYTE boxNo, BYTE *ant, BYTE antLen);
	RFID_DN_HANDLE RFIDLIB_API  Bookcase_CreateTagRecordSet(void);
	err_t RFIDLIB_API  Bookcase_AddTagToRecordSet(RFID_DN_HANDLE hTagSet,BYTE boxNo, BYTE * id, DWORD idLen);
	err_t RFIDLIB_API  Bookcase_DownloadTagsToBuffer(RFID_READER_HANDLE hr,RFID_DN_HANDLE hTagSet);
	RFID_DN_HANDLE Bookcase_GetTagReport(RFID_READER_HANDLE hr,BYTE mode, BYTE seek);
	err_t RFIDLIB_API Bookcase_ParseTagReport(RFID_READER_HANDLE hr,RFID_DN_HANDLE dn, BYTE *boxNo, BYTE tagid[], DWORD *len);
	err_t RFIDLIB_API Bookcase_Inventory(RFID_READER_HANDLE hr,BOOLEAN isBookOnshelf, BYTE boxid);
	err_t RFIDLIB_API Bookcase_SubmitInventoryResult(RFID_READER_HANDLE hr);

	

	err_t  RFIDLIB_API RDR_Active_Upload_Start(RFID_READER_HANDLE hr,BOOLEAN sendtick);
	err_t  RFIDLIB_API RDR_Active_Upload_Stop(RFID_READER_HANDLE hr);




	err_t RFIDLIB_API JD100_Inventory(RFID_READER_HANDLE hr, BYTE opt,RFID_DN_HANDLE hGroupManager, BYTE *sequencyID, BYTE sequencyIDLen, WORD startPos, BYTE readLen, DWORD timeout);


	err_t RFIDLIB_API JD_ParseReport(RFID_HANDLE hReport, BYTE *addr, BYTE *flag, BYTE * error, BYTE *uid, BYTE *uidlen, BYTE *barcode, BYTE *barcodeLen);
	err_t RFIDLIB_API JD_SearchReader(RFID_READER_HANDLE hr,BYTE opt, DWORD MaxTimeout);
	RFID_DN_HANDLE RFIDLIB_API JD_FetchSearchReport(RFID_READER_HANDLE hr, BYTE seek);
	err_t RFIDLIB_API  JD_ParseSearchReport(RFID_DN_HANDLE hReport,BYTE *RSN,BYTE *RSNLEN,BYTE *RID,BYTE *AID,BYTE *AIDLEN );
	err_t RFIDLIB_API  JD_SetRID(RFID_READER_HANDLE hr, BYTE* pRSN, BYTE RSNLen, BYTE opt, BYTE RID, BYTE *pAID, BYTE AIDLen);
	err_t RFIDLIB_API  JD_ControlLightByRSN(RFID_READER_HANDLE hr, BYTE* pRSN, BYTE RSNLen, BYTE action, BYTE  Second);


	RFID_DN_HANDLE RFIDLIB_API JD_CreateLedControlManager();
	RFID_DN_HANDLE RFIDLIB_API JD_CreateLedControl(int id, int type, DWORD activeTime, WORD flashAT, WORD flashDT);
	err_t RFIDLIB_API JD_AddLedControl(RFID_DN_HANDLE ledManager, RFID_DN_HANDLE ledControl);
	err_t RFIDLIB_API JD_DestoryLedControlManager(RFID_DN_HANDLE ledManager);
	err_t RFIDLIB_API JD_ControlLedByRID(RFID_READER_HANDLE hr, int rid, RFID_DN_HANDLE params);
	err_t RFIDLIB_API JD_GetReaderOfflineSta(RFID_READER_HANDLE hr, BYTE * readerSta,WORD * len);


	RFID_DN_HANDLE JD100_CreateGroupManager();
	RFID_DN_HANDLE  JD100_CreateGroup(int gid,BYTE *ids,DWORD idlen);
	err_t  JD100_AddGroupToGroupManager(RFID_DN_HANDLE hManager, RFID_DN_HANDLE hGroup);
	void JD100_DestroyGroupManager(RFID_DN_HANDLE hManager);



	DWORD RFIDLIB_API EnumIP();


	err_t RFIDLIB_API IP_GetEnumItem(DWORD indx, BYTE infType, LPTSTR infBuffer, DWORD *nSize);


#ifdef __cplusplus
}
#endif


#endif

