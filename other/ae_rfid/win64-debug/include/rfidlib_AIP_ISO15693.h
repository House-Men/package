#ifndef __RFIDLIB_AIP_ISO15693_H__
#define __RFIDLIB_AIP_ISO15693_H__


#include "rfidlib.h"

#ifdef __cplusplus
extern "C" {
#endif

DWORD RFIDLIB_API ISO15693_GetLibVersion(LPTSTR buf ,DWORD nSize /* in character */)  ;
/*
*	iso15693 inventory parameters
*/
// inventory need to match the AFI value 
RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateInvenParam(RFID_DN_HANDLE hInvenParamSpecList,
															BYTE AntennaID/* By default set to 0,apply to all antenna */,
															BOOLEAN en_afi,
															BYTE afi,
															BYTE slot_type/*0:default,1: 1slot,16:16 slot */)   ;


err_t RFIDLIB_API ISO15693_SetInvenReadParam(
	RFID_DN_HANDLE hIso15693InvenParam, 
	BOOLEAN readSecSta, 
	DWORD blkAddr,
	DWORD numOfBlks);


err_t RFIDLIB_API ISO15693_SetInventoryReadParam(
	RFID_DN_HANDLE hIso15693InvenParam,
	BYTE mode,
	BYTE mask);


err_t RFIDLIB_API ISO15693_AddInventoryReadBlockArea(
	RFID_DN_HANDLE hIso15693InvenParam, 
	DWORD blkAddr, 
	DWORD numOfBlks);

/*
* Parse iso15693 tag data 
*/
err_t RFIDLIB_API ISO15693_ParseTagDataReport(RFID_DN_HANDLE hTagReport,
										  DWORD *aip_id,
										  DWORD *tag_id,
										  DWORD* ant_id,
										  BYTE *dsfid,
										  BYTE uid[])  ;


err_t RFIDLIB_API ISO15693_ParseTagDataReportEx(RFID_DN_HANDLE hTagReport,
	DWORD *aip_id,
	DWORD *tag_id,
	DWORD* ant_id,
	BYTE *dsfid,
	WORD *rssi,
	DWORD *readCnt,
	BYTE uid[]);

err_t RFIDLIB_API ISO15693_ParseInventoryReadReport(RFID_DN_HANDLE hTagReport,
	BYTE uid[],
	DWORD *numOfBlocks,
	BYTE blkData[],
	DWORD* nSize);

err_t RFIDLIB_API ISO15693_ParseInvenReadReport(RFID_DN_HANDLE hTagReport,
	BYTE *ant,
	BYTE *dsfid,
	BYTE uid[],
	DWORD *numOfBlocks,
	BYTE blkData[],
	DWORD* nSize);


err_t RFIDLIB_API ISO15693_Connect(RFID_READER_HANDLE hr ,
								   DWORD tagType,
							BYTE address_mode,/* in param */ 
							const BYTE uid[] ,
							RFID_TAG_HANDLE *ht
							) ;

err_t RFIDLIB_API ISO15693_Reset(RFID_READER_HANDLE hr ,
								 RFID_TAG_HANDLE ht /* Tag handle connected */) ;
err_t RFIDLIB_API ISO15693_ReadSingleBlock(
									RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
									BOOLEAN readSecSta,/* IN: Whether read security status */
								  DWORD blkAddr,/* IN: Block number  */
						BYTE bufBlockDat[], /* OUT: buffer for storing single block data or single block data +sec sta*/
						DWORD nSize /* in:size of the buffer*/,
						DWORD *bytesBlkDatRead)  ;
err_t RFIDLIB_API ISO15693_WriteSingleBlock(
									RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
								   DWORD blkAddr,/* Block number  */
								BYTE newBlkData[] ,
								DWORD bytesToWrite)  ;
err_t RFIDLIB_API ISO15693_ReadMultiBlocks( RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
									BOOLEAN readSecSta ,
									 DWORD blkAddr,/* Block number  */
							DWORD numOfBlksToRead, /* in:Number of blocks to read  */
							DWORD *numOfBlksRead,/* ,out: blocks read */
							BYTE bufBlocks[],/*  buffer for storing block data ,4 * num_of_blks */
							DWORD nSize, /* in:size of the buffer */
							DWORD *bytesBlkDatRead)  ;
err_t RFIDLIB_API ISO15693_WriteMultipleBlocks(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
									 DWORD blkAddr,
							DWORD numOfBlks, 
							BYTE newBlksData[],
							DWORD bytesToWrite) ;

err_t RFIDLIB_API ISO15693_WriteAFI(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
								BYTE afi) ;

err_t RFIDLIB_API ISO15693_LockAFI(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht /* Tag handle connected */) ;
err_t RFIDLIB_API ISO15693_WriteDSFID(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, 
									BYTE dsfid)  ;
err_t RFIDLIB_API ISO15693_LockDSFID(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht)  ;
err_t RFIDLIB_API ISO15693_GetSystemInfo(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht,
									BYTE uid[],	/* out: tag uid */
											BYTE *dsfid, /* out:DSFID */
											BYTE *afi,  /* out:AFI */
											DWORD *blkSize ,/* out: block size */
											DWORD *numOfBloks, /* out:number of total blocks */
											BYTE *icRef /* out:ic reference */) ;

err_t RFIDLIB_API ISO15693_GetBlockSecStatus(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht,
										DWORD blkAddr, 
										DWORD numOfBlks,
										BYTE bufBlkSecs[],
										DWORD nSize/* in: size of the buffer */,
										DWORD *bytesSecRead /*out:number of block status byte copied*/ ) ;

err_t RFIDLIB_API ISO15693_LockMultipleBlocks(RFID_READER_HANDLE hr ,
									RFID_TAG_HANDLE ht, /* Tag handle connected */
									 DWORD blkAddr,
							DWORD numOfBlks) ;


err_t RFIDLIB_API NXPICODESLI_EableEAS(RFID_READER_HANDLE hr ,
									   RFID_TAG_HANDLE ht)  ;
err_t RFIDLIB_API NXPICODESLI_DisableEAS(RFID_READER_HANDLE hr ,
										 RFID_TAG_HANDLE ht) ;
err_t RFIDLIB_API NXPICODESLI_LockEAS(RFID_READER_HANDLE hr ,
									  RFID_TAG_HANDLE ht) ;
err_t RFIDLIB_API NXPICODESLI_EASAlarm(RFID_READER_HANDLE hr ,
									   RFID_TAG_HANDLE ht,
									   BYTE EAS_data[],
									   DWORD nSize /* EAS data buffer,32 bytes */,
									   DWORD *bytesWritten);
err_t RFIDLIB_API NXPICODESLI_EASCheck(RFID_READER_HANDLE hr ,
									   RFID_TAG_HANDLE ht,
									   BYTE *EASFlag) ;

err_t RFIDLIB_API NXPICODESLI_GetRandomNum( RFID_READER_HANDLE hr ,
											RFID_TAG_HANDLE ht,
											WORD *random/* 16bits */) ;
err_t RFIDLIB_API NXPICODESLI_SetPassword( RFID_READER_HANDLE hr ,
										   RFID_TAG_HANDLE ht,
										   BYTE pwdNo,/* password adress,Only one password is supported now,the address is 10H */
										   WORD random,
										   DWORD pwd/* 32bits */)  ;

err_t RFIDLIB_API NXPICODESLI_WritePassword(RFID_READER_HANDLE hr ,
											 RFID_TAG_HANDLE ht,
											 BYTE pwdNo,
											 DWORD pwd/* 32bits */)  ;
err_t RFIDLIB_API NXPICODESLI_LockPassword(RFID_READER_HANDLE hr ,
											RFID_TAG_HANDLE ht,
											BYTE pwdNo) ;
err_t	RFIDLIB_API	NXPICODESLI_PasswordProtect(RFID_READER_HANDLE hr ,
												 RFID_TAG_HANDLE ht,
												 BYTE bandType/* EAS=0 or AFI=1 */) ;

err_t RFIDLIB_API NXPICODESLI_EASCheck(RFID_READER_HANDLE hr ,
										RFID_TAG_HANDLE ht,
										BYTE *EASFlag) ;
err_t RFIDLIB_API NXPICODESLI_GetRandomAndSetPassword( RFID_READER_HANDLE hr ,
													   RFID_TAG_HANDLE ht,
													   BYTE pwdNo,/* password adress,Only one password is supported now,the address is 10H */
													   DWORD pwd/* 32bits */)   ;

err_t RFIDLIB_API NXPICODESLI_WriteEASID(RFID_READER_HANDLE hr ,
										 RFID_TAG_HANDLE ht,
										 WORD EASID ) ;

err_t RFIDLIB_API NXPICODESLI_GetNxpSysInfo(RFID_READER_HANDLE hr ,
											RFID_TAG_HANDLE ht,
											BYTE *PPPointer ,
											BYTE *PPConditions ,
											BYTE *lockBits,
											DWORD *featureFlags
											) ;
err_t RFIDLIB_API NXPICODESLI_ReadSignature(RFID_READER_HANDLE hr ,
											RFID_TAG_HANDLE ht,
											BYTE signature[] /* out ,32 bytes */) ;

err_t RFIDLIB_API NXPICODESLI_Enable64BitPwd(RFID_READER_HANDLE hr ,
											 RFID_TAG_HANDLE ht) ;
err_t RFIDLIB_API NXPICODESLI_ProtectPage(RFID_READER_HANDLE hr ,
										  RFID_TAG_HANDLE ht,
										  BYTE PPPointer,
										  BYTE protSta) ;
err_t RFIDLIB_API NXPICODESLI_LockPageProtection(RFID_READER_HANDLE hr ,
												 RFID_TAG_HANDLE ht,
												 BYTE pageAddr) ;
err_t RFIDLIB_API NXPICODESLI_Destroy(RFID_READER_HANDLE hr ,
									  RFID_TAG_HANDLE ht,
									  DWORD pwd) ;
err_t RFIDLIB_API NXPICODESLI_EnblePrivacy(RFID_READER_HANDLE hr ,
										   RFID_TAG_HANDLE ht,
										   DWORD pwd) ;
err_t RFIDLIB_API NXPICODESLI_PresetCounter(RFID_READER_HANDLE hr ,
											RFID_TAG_HANDLE ht,
											WORD initCnt,
											BOOLEAN enReadPwdProtect) ;
err_t RFIDLIB_API NXPICODESLI_IncrementCounter(RFID_READER_HANDLE hr ,
											   RFID_TAG_HANDLE ht) ;




err_t RFIDLIB_API TIHFIPLUS_Write2Blocks(RFID_READER_HANDLE hr ,
										 RFID_TAG_HANDLE ht,
										 DWORD blkAddr,
										 BYTE newTwoBlksData[] /* 2 * 4 */,
										 DWORD bytesToWrite
										 ) ;

err_t RFIDLIB_API TIHFIPLUS_Lock2Blocks(RFID_READER_HANDLE hr ,
										RFID_TAG_HANDLE ht,
										DWORD blkAddr) ;



err_t RFIDLIB_API CIT83128_InitMem(RFID_READER_HANDLE hr , /*in */
								   RFID_TAG_HANDLE ht, /*in */
								   BOOLEAN loseEffect,
								   BYTE blkAddr, /*in */
								   BYTE blkData[] /*in,4bytes */ ) ;

err_t RFIDLIB_API CIT83128_ActAu(RFID_READER_HANDLE hr , /*in */
								 RFID_TAG_HANDLE ht, /*in */
								 DWORD rr /* in */,
								 BYTE token[] /* out */) ;
err_t RFIDLIB_API CIT83128_GetSecPara(RFID_READER_HANDLE hr , /*in */
									  RFID_TAG_HANDLE ht, /*in */
									  BOOLEAN readSecByte, /*in */
									  BYTE secData[]  /*out */ ) ;


err_t RFIDLIB_API STM24LR_WriteSectorPassword(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE pwdnum,
									DWORD new_pwd);

err_t RFIDLIB_API STM24LR_PresentSectorPassword(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE pwdnum,
									DWORD pwd);

err_t RFIDLIB_API  STM24LR_LockSector(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE sector_num,
									BYTE access_type,
									BYTE pwd_num_protect);

err_t RFIDLIB_API  STM24LR_ReadCFG(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE *cfgby);

err_t RFIDLIB_API  STM24LR_WriteEHCfg(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE EnergyHarvesting,
									BYTE EHMode);

err_t RFIDLIB_API  STM24LR_WriteDOCfg(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE cfg_do /* 0: RF busy mode(RF WIP/BUSY pin for RF busy) , 1: RF Write in progress( RF WIP/BUSY pin for) */
									);

err_t RFIDLIB_API  STM24LR_SetRstEHEn(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE enable
										);

err_t RFIDLIB_API  STM24LR_CheckEHEn(RFID_READER_HANDLE hr,
									RFID_TAG_HANDLE ht,
									BYTE *ctrlreg);


err_t RFIDLIB_API STLRI2k_Kill(RFID_READER_HANDLE hr, /*in */
								RFID_TAG_HANDLE ht, /*in */
									BYTE access, /*value is 0x00 */
									DWORD code);

err_t RFIDLIB_API STLRI2k_WriteKill(RFID_READER_HANDLE hr, /*in */
									RFID_TAG_HANDLE ht, /*in */
									BYTE access, /*value is 0x00 */
									DWORD code);

err_t RFIDLIB_API STLRI2k_LockKill(RFID_READER_HANDLE hr, /*in */
									RFID_TAG_HANDLE ht, /*in */
									BYTE access, /*value is 0x00 */
									BYTE protectSta);


err_t RFIDLIB_API TIHFI_Kill(RFID_READER_HANDLE hr, /*in */ RFID_TAG_HANDLE ht, /*in */ DWORD password);



err_t RFIDLIB_API TIHFI_WriteSingleBlockPwd(RFID_READER_HANDLE hr, /*in */
											RFID_TAG_HANDLE ht, /*in */
											DWORD password,
											BYTE blkAddr,
											BYTE blkData[]  /* 4 bytes block data*/);




err_t RFIDLIB_API ST25DV04K_ReadConfiguration(RFID_READER_HANDLE hr, /*in */
											RFID_TAG_HANDLE ht, /*in */
											BYTE Pointer,
											BYTE *RegisterValue);

err_t RFIDLIB_API ST25DV04K_WriteConfiguration(RFID_READER_HANDLE hr, /*in */
											RFID_TAG_HANDLE ht, /*in */
											BYTE Pointer,
											BYTE RegisterValue);

err_t RFIDLIB_API ST25DV04K_ReadDynamicConfiguration(RFID_READER_HANDLE hr, /*in */
													RFID_TAG_HANDLE ht, /*in */
													BYTE Pointer,
													BYTE *RegisterValue);

err_t RFIDLIB_API ST25DV04K_WriteDynamicConfiguration(RFID_READER_HANDLE hr, /*in */
													RFID_TAG_HANDLE ht, /*in */
													BYTE Pointer,
													BYTE RegisterValue);

err_t RFIDLIB_API ST25DV04K_ManageGPO(RFID_READER_HANDLE hr, /*in */
									RFID_TAG_HANDLE ht, /*in */
									BYTE gpo);

err_t RFIDLIB_API ST25DV04K_WriteMessage(RFID_READER_HANDLE hr, /*in */
										RFID_TAG_HANDLE ht, /*in */
										BYTE* msgData,
										BYTE msgLen);


err_t RFIDLIB_API ST25DV04K_ReadMessageLength(RFID_READER_HANDLE hr, /*in */
											RFID_TAG_HANDLE ht, /*in */
											BYTE* msgLength);
err_t RFIDLIB_API ST25DV04K_ReadMessage(RFID_READER_HANDLE hr, /*in */
										RFID_TAG_HANDLE ht, /*in */
										BYTE Pointer,/*in*/
										BYTE ReadCount,/*in*/
										BYTE *msgBuf,/*out*/
										DWORD *nSize /*in/out*/);

err_t RFIDLIB_API ST25DV04K_WritePassword(RFID_READER_HANDLE hr, /*in */
										RFID_TAG_HANDLE ht, /*in */
										BYTE passwordNum,
										BYTE password[]/*8 bytes*/);

err_t RFIDLIB_API ST25DV04K_PresentPassword(RFID_READER_HANDLE hr, /*in */
										RFID_TAG_HANDLE ht, /*in */
										BYTE passwordNum,
										BYTE password[]/*8 bytes*/);




//EN4237SLIC and EN4237SLIX
err_t RFIDLIB_API EM4237SLI_EnableEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_DisableEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_LockEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_ActiveEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE AddressMode,BYTE EASIdMaskLen, WORD EASID,BYTE EASData[],DWORD*nSize);
err_t RFIDLIB_API EM4237SLI_ProtectEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_EASCheck(RFID_READER_HANDLE hr,RFID_TAG_HANDLE ht,BYTE *EASFlag);
err_t RFIDLIB_API EM4237SLI_WriteEASID(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,WORD EASID);
err_t RFIDLIB_API EM4237SLI_WriteEASCfg(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, WORD cfg);
err_t RFIDLIB_API EM4237SLI_ChangeKey(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE KeyIndentifier,DWORD Password);
err_t RFIDLIB_API EM4237SLI_ProtectMemoryPage(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, DWORD PageNo, BYTE ProtectStatus);
err_t RFIDLIB_API EM4237SLI_GetMultipleBlocksProtectionStatus(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE BlockAddress,BYTE BlockNumber,BYTE buffer[],DWORD *nSize);
err_t RFIDLIB_API EM4237SLI_Destroy(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_EnablePrivacy(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_DisablePrivacy(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_EnableRandomID(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_DisableRandomID(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API EM4237SLI_Login(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,DWORD password);

err_t RFIDLIB_API ST25TV02K_ReadConfiguration(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE Pointer,BYTE*Value);
err_t RFIDLIB_API ST25TV02K_WriteConfiguration(RFID_READER_HANDLE hr,RFID_TAG_HANDLE ht,BYTE Pointer,BYTE RegisterValue);
err_t RFIDLIB_API ST25TV02K_WritePassword(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE PasswordNumber, BYTE Password[]/*4 byte*/);
err_t RFIDLIB_API ST25TV02K_PresentPassword(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE PasswordNumber,BYTE Password[],BYTE PasswordLen/*4 or 8*/);
err_t RFIDLIB_API ST25TV02K_SetEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API ST25TV02K_ResetEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API ST25TV02K_CheckEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE AddressMode,BYTE EASIdMask, WORD EASID, BYTE EASData[], DWORD*nSize);
err_t RFIDLIB_API ST25TV02K_LockEAS(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht);
err_t RFIDLIB_API ST25TV02K_WriteEASId(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,WORD EASId);
err_t RFIDLIB_API ST25TV02K_WriteEASCfg(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht,BYTE cfg);
err_t RFIDLIB_API ST25TV02K_Kill(RFID_READER_HANDLE hr,RFID_TAG_HANDLE ht,BYTE Password[]/*4 byte*/);
err_t RFIDLIB_API ST25TV02K_LockKill(RFID_READER_HANDLE hr,RFID_TAG_HANDLE ht, BYTE protectSta);
err_t RFIDLIB_API ST25TV02K_EnableUntraceableMode(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE password[]/*4 byte*/);

//err_t RFIDLIB_API ISO15693_AddOneCheckTagIsExistOperation(RFID_DN_HANDLE hOperas,BYTE uid[],BYTE tagId);
err_t RFIDLIB_API ISO15693_TransparentTransceive(RFID_READER_HANDLE hr, BYTE mode,BYTE isTxCRC, BYTE isRxCRC,BYTE *reqData, DWORD reqLen, DWORD nBytesTagWillRet, BYTE *pRxBuffer, DWORD *nSize, DWORD time);
err_t RFIDLIB_API ISO15693_AddNewAccessTag(RFID_DN_HANDLE hTagSet, BYTE addrMode,BYTE uid[8], BOOLEAN inheritTagType, BOOLEAN inheritAnt, BOOLEAN inhertCmdSet);
RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAReset(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API ISO15693_ParseResetResult(RFID_DN_HANDLE hTagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAReadSingleBlock(RFID_DN_HANDLE hTagAccessSet,BOOLEAN readSecSta,DWORD blkAddr);
err_t RFIDLIB_API ISO15693_ParseReadSingleBlockResult(RFID_DN_HANDLE hTagAccess,BYTE bufBlockDat[],DWORD *nSize);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAWriteSingbleBlock(RFID_DN_HANDLE hTagAccessSet,DWORD blkAddr,BYTE newBlkData[],DWORD bytesToWrite);
err_t RFIDLIB_API ISO15693_ParseWriteSingbleBlockResult(RFID_DN_HANDLE hTagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAReadMultipleBlocks(RFID_DN_HANDLE hTagAccessSet,BOOLEAN readSecSta,DWORD blkAddr,DWORD numOfBlksToRead);
err_t  RFIDLIB_API ISO15693_ParseReadMultiBlocksResult(RFID_DN_HANDLE tagAccess,DWORD *numOfBlksRead,BYTE bufBlocks[],DWORD *nSize);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAWriteMultipleBlocks(RFID_DN_HANDLE hTagAccessSet,DWORD blkAddr,DWORD numOfBlks,BYTE newBlksData[],DWORD bytesToWrite);
err_t  RFIDLIB_API ISO15693_ParseWriteMultipleBlocksResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTALockMultipleBlocks(RFID_DN_HANDLE hTagAccessSet,DWORD blkAddr,DWORD numOfBlks);
err_t  RFIDLIB_API ISO15693_ParseLockMultipleBlocksResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAWriteAFI(RFID_DN_HANDLE hTagAccessSet,BYTE afi);
err_t  RFIDLIB_API ISO15693_ParseWriteAFIResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTALockAFI(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API ISO15693_ParseLockAFIResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAWriteDSFID(RFID_DN_HANDLE hTagAccessSet,BYTE dsfid);
err_t RFIDLIB_API ISO15693_ParseWriteDSFIDResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTALockDSFID(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API ISO15693_ParseLockDSFIDResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAGetTagInfor(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API ISO15693_ParseGetSystemInfoResult(RFID_DN_HANDLE tagAccess,BYTE uid[],BYTE *dsfid,BYTE *afi,DWORD *blkSize,DWORD *numOfBloks,BYTE *icRef);

RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAGetSecStaOfBlocks(RFID_DN_HANDLE hTagAccessSet,DWORD blkAddr,DWORD numOfBlks);
err_t RFIDLIB_API ISO15693_ParseGetBlockSecStatusResult(RFID_DN_HANDLE tagAccess,BYTE bufBlkSecs[],DWORD nSize,DWORD *bytesRead);


RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTACustomCommand(
	RFID_DN_HANDLE hTagAccessSet,
	BYTE m_mode,
	BYTE m_recvCount,
	BYTE m_302,
	BYTE m_ewt,
	BYTE m_command,
	BYTE m_reqData[],
	DWORD m_reqDataSize);

err_t RFIDLIB_API ISO15693_ParseCustomCommandResult(RFID_DN_HANDLE tagAccess,BYTE m_respData[],DWORD *nSize);


RFID_DN_HANDLE RFIDLIB_API ISO15693_CreateTAWriteMultipleTags(BYTE isReadCheck,BYTE antCnt,BYTE antsel[]);
err_t RFIDLIB_API ISO15693_AddOneTagToWriteMultipleTagsAccess(RFID_DN_HANDLE tagAccess,BYTE uid[]);
err_t RFIDLIB_API ISO15693_AddAreaToWriteMultipleTagsAccess(
	RFID_DN_HANDLE tagAccess,
	DWORD blkAddr,
	DWORD blkCnt,
	BYTE  blkData[],
	DWORD nSize
);
err_t RFIDLIB_API ISO15693_WriteMultipleTags(RFID_READER_HANDLE hr, RFID_DN_HANDLE tagAccess,BYTE result[],DWORD *nSize);


RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAEableEAS(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseEableEASResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTADisableEAS(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API  NXPICODESLI_ParseDisableEASResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTALockEAS(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API  NXPICODESLI_ParseLockEASResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAEASAlarm(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseEASAlarmResult(RFID_DN_HANDLE tagAccess,BYTE EAS_data[],DWORD nSize,DWORD *bytesWritten);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAEASCheck(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseEASCheckResult(RFID_DN_HANDLE tagAccess, BYTE *EASFlag);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAGetRandomAndSetPassword(RFID_DN_HANDLE hTagAccessSet,BYTE pwdNo,DWORD pwd);
err_t RFIDLIB_API  NXPICODESLI_ParseGetRandomAndSetPasswordResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAWritePassword(RFID_DN_HANDLE hTagAccessSet,BYTE pwdNo,DWORD pwd/* 32bits */);
err_t RFIDLIB_API NXPICODESLI_ParseWritePasswordResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE NXPICODESLI_CreateTALockPassword(RFID_DN_HANDLE hTagAccessSet,BYTE pwdNo);
err_t RFIDLIB_API NXPICODESLI_ParseLockPasswordResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAPasswordProtect(RFID_DN_HANDLE hTagAccessSet,BYTE bandType);
err_t RFIDLIB_API NXPICODESLI_ParsePasswordProtectResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAWriteEASID(RFID_DN_HANDLE hTagAccessSet,WORD EASID);
err_t RFIDLIB_API NXPICODESLI_ParseWriteEASIDResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAGetNxpSysInfo(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseGetNxpSysInfoResult(RFID_DN_HANDLE tagAccess,BYTE *PPPointer,BYTE *PPConditions,BYTE *lockBits,DWORD *featureFlags);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAReadSignature(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseReadSignatureResult(RFID_DN_HANDLE tagAccess,BYTE signature[]);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAEnable64BitPwd(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseEnable64BitPwdResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAProtectPage(RFID_DN_HANDLE hTagAccessSet,BYTE PPPointer,BYTE protSta);
err_t RFIDLIB_API NXPICODESLI_ParseProtectPageResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTALockPageProtection(RFID_DN_HANDLE hTagAccessSet,BYTE pageAddr);
err_t RFIDLIB_API NXPICODESLI_ParseLockPageProtectionResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTADestroy(RFID_DN_HANDLE hTagAccessSet,DWORD pwd);
err_t RFIDLIB_API NXPICODESLI_ParseDestroyResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAEnblePrivacy(RFID_DN_HANDLE hTagAccessSet,DWORD pwd);
err_t RFIDLIB_API NXPICODESLI_ParseEnblePrivacyResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAPresetCounter(RFID_DN_HANDLE hTagAccessSet,WORD initCnt,BOOLEAN enReadPwdProtect);
err_t RFIDLIB_API NXPICODESLI_ParsePresetCounterResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API NXPICODESLI_CreateTAIncrementCounter(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API NXPICODESLI_ParseIncrementCounterResult(RFID_DN_HANDLE tagAccess);

RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTAWriteSectorPassword(RFID_DN_HANDLE hTagAccessSet,
	BYTE pwdnum,
	DWORD new_pwd);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTAPresentSectorPassword(RFID_DN_HANDLE hTagAccessSet,
	BYTE pwdnum,
	DWORD pwd);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTALockSector(RFID_DN_HANDLE hTagAccessSet,
	BYTE sector_num,
	BYTE access_type,
	BYTE pwd_num_protect);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTAReadCFGByte(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API STM24LR_ParseReadCFGByteResult(RFID_DN_HANDLE tagAccess, BYTE *cfgby);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTAWriteEHCfg(RFID_DN_HANDLE hTagAccessSet,
	BYTE EnergyHarvesting,
	BYTE EHMode);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTAWriteDOCfg(RFID_DN_HANDLE hTagAccessSet,
	BYTE cfg_do);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTASetRstEHEn(RFID_DN_HANDLE hTagAccessSet,
	BYTE enable);
RFID_DN_HANDLE RFIDLIB_API STM24LR_CreateTACheckEHEn(RFID_DN_HANDLE hTagAccessSet);
err_t RFIDLIB_API STM24LR_ParseCheckEHEnResult(RFID_DN_HANDLE tagAccess, BYTE *ctrlreg);

/* ����΢ISO15693��оƬ����*/
RFID_DN_HANDLE RFIDLIB_API FM13HF_CreateTAPadIOOnOff(RFID_DN_HANDLE hTagAccessSet, BYTE ledCfg1, BYTE ledCfg2);
err_t RFIDLIB_API FM13HF_PadIOOnOff(RFID_READER_HANDLE hr, RFID_TAG_HANDLE ht, BYTE ledCfg1, BYTE ledCfg2);

#ifdef __cplusplus
}
#endif

#endif