#ifndef __RFIDLIB_H__
#define __RFIDLIB_H__



/* Air interface protocol type id */
#ifndef __RFID_APL_ID_H__
#define __RFID_APL_ID_H__
enum rfid_APL_id {
	RFID_APL_UNKNOWN_ID = 0,
	RFID_APL_ISO15693_ID,
	RFID_APL_ISO14443A_ID,
	RFID_APL_ISO14443B_ID,
	RFID_APL_EPCGEN2_ID,       //UHF
	RFID_APL_ISO18000P3M3,
	RFID_APL_STISO14443B,
	RFID_APL_SONYFELICA,
	RFID_APL_NFCFORUMTYPE1,
};
#endif

#ifndef RFID_UNKNOWN_PICC_ID
#define RFID_UNKNOWN_PICC_ID					0
#endif


/* ISO15693 tag type id */
#ifndef __RFID_ISO15693_PICC_ID__
#define __RFID_ISO15693_PICC_ID__
/* ISO15693 PICC id*/
enum 
{
   RFID_ISO15693_PICC_ICODE_SLI_ID = 1,
   RFID_ISO15693_PICC_TI_HFI_PLUS_ID,
   RFID_ISO15693_PICC_ST_SERIES_ID,		    /* ST serial ,ST can not identify tag type by UID */
   RFID_ISO15693_PICC_FUJ_MB89R118C_ID,
   RFID_ISO15693_PICC_ST_M24LR64_ID,
   RFID_ISO15693_PICC_ST_M24LR16E_ID,	
   RFID_ISO15693_PICC_ICODE_SLIX_ID,
   RFID_ISO15693_PICC_TIHFI_STANDARD_ID,
   RFID_ISO15693_PICC_TIHFI_PRO_ID,             // password
   RFID_ISO15693_PICC_ICODE_SLIX2_ID,
   RFID_ISO15693_PICC_CIT83128_ID,				/* 北京华大*/
   RFID_ISO15693_PICC_ST25TV02K_ID,
   RFID_ISO15693_PICC_ICODE_SLI_L_ID,
   RFID_ISO15693_PICC_ICODE_SLIX_L_ID,
   RFID_ISO15693_PICC_ICODE_SLI_S_ID,
   RFID_ISO15693_PICC_ICODE_SLIX_S_ID,
   RFID_ISO15693_PICC_EM4237SLIC_ID,
   RFID_ISO15693_PICC_EM4237SLIX_ID,
   RFID_ISO15693_PICC_RF430FR12XH_ID,
   RFID_ISO15693_PICC_ST25DV04K_JF_ID,
   RFID_ISO15693_PICC_ST_M24LRXX_ID,
   RFID_ISO15693_PICC_TCSHF001_ID,
   RFID_ISO15693_PICC_FM13HF_ID,
   RFID_ISO15693_PICC_ST_M24LR04E_ID,
   RFID_ISO15693_PICC_NBWX_TC603_ID,
   
} ;
#endif


/* ISO14443A tag type id */
enum
{
	RFID_ISO14443A_PICC_NXP_ULTRALIGHT_ID =1,    // Ultralight
	RFID_ISO14443A_PICC_NXP_MIFARE_S50_ID,
	RFID_ISO14443A_PICC_NXP_MIFARE_S70_ID,
	RFID_ISO14443A_PICC_NXP_DESFIRE_EV1_ID,
	RFID_ISO14443A_PICC_NTAG21x_ID,
	RFID_ISO14443A_PICC_MIFARE_MINI_ID,
	RFID_ISO14443A_PICC_MIFARE_PLUS,
} ;

/* ST ISO14444B tag type id */
enum 
{
	RFID_STISO14443B_PICC_SRIX4K_ID =1,
	RFID_STISO14443B_PICC_ST25TB512_AC_ID
};


/*
*	rfidlib api
*/
#if defined(_WIN64)
#define RFIDLIB_API				__fastcall	
#else
#define RFIDLIB_API				__stdcall		
#endif



/*
*	variable types
*/



#ifndef err_t
#define  err_t					INT32
#endif

#ifndef NO_ERR
#define NO_ERR                                  0
#endif

#ifndef mem_ptr_t
#define mem_ptr_t									HANDLE		
#endif

#define RFID_HANDLE_NULL							0
typedef void *RFID_HANDLE;
#define RFID_READER_HANDLE							RFID_HANDLE
#define RFID_TAG_HANDLE								RFID_HANDLE
#define RFID_DN_HANDLE								RFID_HANDLE
#define MEM_PTR_T									RFID_HANDLE
#define RFID_NFC_HANDLE                             RFID_HANDLE
#define	WIN_MSG_t									UINT

// callback event type
enum
{
	RFIDLIB_EVNT_GETBUF_REPORT_FOUND = 1,
	RFIDLIB_EVNT_GETBUF_ERROR ,
	RFIDLIB_EVNT_GETBUF_EXIT,
} ;


// Event method 
#define RFID_EVTMED_USE_MSG								1			// use sendmessage
#define RFID_EVTMED_USE_CB								2			// use call back function
#define RFID_EVTMED_USE_POSTMSG							3           // use postmessage
//typedef void (__stdcall *RFID_EVENT_CALLBACK)(WPARAM wparam,LPARAM lparam) ; 
//typedef void (__stdcall *RFID_EVENT_CALLBACK_NEW)(void *inParam,WPARAM wparam, LPARAM lparam) ;

typedef VOID(__stdcall *RFID_EVENT_CALLBACK)(WPARAM wparam, LPARAM lparam);
typedef VOID(__stdcall *RFID_EVENT_CALLBACK_NEW)(void *inParam, WPARAM wparam, LPARAM lparam);

//Inventory type 
#define AI_TYPE_NEW										1     // new antenna inventory  (reset RF power)
#define AI_TYPE_CONTINUE								2	  // continue antenna inventory ;
#define AI_TYPE_NEW_WITH_NOINIT_BUFF					3

// Move position 
#define RFID_NO_SEEK				0					// No seeking 
#define RFID_SEEK_FIRST				1					// Seek first
#define RFID_SEEK_NEXT				2					// Seek next 
#define RFID_SEEK_LAST				3					// Seek last



/* 
* inventory stop trigger type
*/
enum
{
	INVEN_STOP_TRIGGER_TYPE_Tms,   
	INVEN_STOP_TRIGGER_TYPE_N_attempt,
	INVEN_STOP_TRIGGER_TYPE_N_found,
	INVEN_STOP_TRIGGER_TYPE_TIMEOUT,
} ;


/*
usb enum information
*/
#define HID_ENUM_INF_TYPE_SERIALNUM				1
#define HID_ENUM_INF_TYPE_DRIVERPATH			2


/*
ip enum information
*/
#define IP_ENUM_INF_TYPE_IP						1
#define IP_ENUM_INF_TYPE_MAC					2
#define IP_ENUM_INF_TYPE_DESCRIPTION            3
#define IP_ENUM_INF_TYPE_NAME                   4
#define IP_ENUM_INF_TYPE_TYPE					5	


/*
* Output Name
*/
#define OUTPUT_NAME_BUZZER_INBOARD		"Buzzer"
#define OUTPUT_NAME_RELAY1				"Relay#1"







/*
* Open connection string 
*/
#define CONNSTR_NAME_RDTYPE				"RDType"
#define CONNSTR_NAME_COMMTYPE			"CommType"

/*
* communication interface type
*/
#define CONNSTR_NAME_COMMTYPE_COM		"COM"
#define CONNSTR_NAME_COMMTYPE_USB		"USB"
#define CONNSTR_NAME_COMMTYPE_NET		"NET"
#define CONNSTR_NAME_COMMTYPE_BLUETOOTH  "BLUETOOTH"

//USB Param
#define CONNSTR_NAME_HIDADDRMODE	    "AddrMode"
#define CONNSTR_NAME_HIDSERNUM		    "SerNum"


//COM Param
#define CONNSTR_NAME_COMNAME			"COMName"
#define CONNSTR_NAME_COMBARUD			"BaudRate"
#define CONNSTR_NAME_COMFRAME			"Frame"
#define CONNSTR_NAME_BUSADDR			"BusAddr"
//Netword
#define CONNSTR_NAME_REMOTEIP	"RemoteIP"
#define CONNSTR_NAME_REMOTEPORT	"RemotePort"
#define CONNSTR_NAME_LOCALIP	"LocalIP"

#define COMNSTR_BRODCAST        "BROADCAST"

//Bluetooth
#define CONNSTR_NAME_BLUETOOTH_SERNUM   "Addr"


#define CONNSTR_NAME_CHECK_ONLINE		"CheckOnline"


/*
* Get loaded reader driver option 
*/
#define LOADED_RDRDVR_OPT_CATALOG					"CATALOG"
#define LOADED_RDRDVR_OPT_NAME						"NAME"
#define LOADED_RDRDVR_OPT_ID						"ID"
#define LOADED_RDRDVR_OPT_COMMTYPESUPPORTED			"COMM_TYPE_SUPPORTED"

/*
* Reader driver type
*/
#define RDRDVR_TYPE_READER					"Reader" // general reader
#define RDRDVR_TYPE_MTGATE					"MTGate" // meeting gate
#define RDRDVR_TYPE_LSGATE					"LSGate" // Library secure gate


/* supported communication type */
enum
{
	COMMTYPE_COM_EN =0x01,
	COMMTYPE_USB_EN =0x02,
	COMMTYPE_NET_EN =0x04,
	COMMTYPE_BLUETOOTH_EN = 0x08,
};


/*
* GPO Output Mode 
*/
enum
{
	OUTPUT_MODE_NOCHANGE,
	OUTPUT_MODE_ON,
	OUTPUT_MODE_OFF,
	OUTPUT_MODE_FLASH ,
} ;


/*
*  ISO18000p3m3 
*/
// meta flags 
#define ISO18000p3m3_META_BIT_MASK_EPC						0x01
 
// begin round sel 
enum
{
	ISO18000p3m3_BEGIN_ROUND_SEL_ALL =0 ,
	ISO18000p3m3_BEGIN_ROUND_SEL_DEASSERT_SL =0x02,
	ISO18000p3m3_BEGIN_ROUND_SEL_ASSERT_SL=0x03,
};
// session
enum
{
	ISO18000p3m3_S0 =0x00 ,
	ISO18000p3m3_S2= 0x02,
};

#define ISO18000p3m3_Dynamic_Q				0xFF



/*
* ISO18000-6C
*/

// session
enum
{
	ISO18000p6C_S0 =0x00,
	ISO18000p6C_S1 =0x01,
	ISO18000p6C_S2= 0x02,
	ISO18000p6C_S3= 0x03,
};
// inventory target
#define ISO18000p6C_TARGET_A			0x00
#define ISO18000p6C_TARGET_B			0x01


// inventory Sel type
#define ISO18000p6C_SEL_TYPE_ALL		0x00 
#define ISO18000p6C_SEL_TYPE_negate_SL	0x01
#define ISO18000p6C_SEL_TYPE_SL			0x02

//Q value
#define ISO18000p6C_Dynamic_Q			0xFF
/*
* meta data bit mask
*/
#define ISO18000p6C_META_BIT_MASK_EPC						0x01
#define ISO18000P6C_META_BIT_MASK_TIMESTAMP					0x02
#define ISO18000P6C_META_BIT_MASK_FREQUENCY					0x04
#define ISO18000p6C_META_BIT_MASK_RSSI						0x08
#define ISO18000P6C_META_BIT_MASK_READCOUNT					0x10 
#define ISO18000P6C_META_BIT_MASK_TAGDATA					0x20


// selection target
//b000: Inventoried (S0)
//b001: Inventoried (S1)
//b010: Inventoried (S2)
//b011: Inventoried (S3)
//b100: SL
//b101: RFU
//b110: RFU
//b111: RFU
#define ISO18000p6C_SELECT_TARGET_INV_S0			0x00
#define ISO18000p6C_SELECT_TARGET_INV_S1			0x01
#define ISO18000p6C_SELECT_TARGET_INV_S2			0x02
#define ISO18000p6C_SELECT_TARGET_INV_S3			0x03
#define ISO18000p6C_SELECT_TARGET_INV_SL			0x04

/* select action type
0x00: assert SL or inventoried → A deassert SL or inventoried → B
0x01: assert SL or inventoried → A do nothing
0x02: do nothing deassert SL or inventoried → B
0x03: negate SL or (A → B, B → A) do nothing
0x04: deassert SL or inventoried → B assert SL or inventoried → A
0x05: deassert SL or inventoried → B do nothing
0x06: do nothing assert SL or inventoried → A
0x07: do nothing negate SL or (A → B, B → A)
*/

// Memory bank type
#define ISO18000p6C_MEM_BANK_RFU					0x00
#define ISO18000p6C_MEM_BANK_EPC					0x01
#define ISO18000p6C_MEM_BANK_TID					0x02
#define ISO18000p6C_MEM_BANK_USER					0x03


#define PDA_UHF_RECORD_EPC_FLAG  (1)
#define PDA_UHF_RECORD_TID_FLAG  (1<<1)
#define PDA_UHF_RECORD_USER_FLAG  (1<<2)

#define PDA_HF_RECORD_UID_FLAG   (1)
#define PDA_HF_RECORD_BARCODE_FLAG (1<<1)


#define KEYWORD_TYPE_2K3DES					0x01
#define KEYWORD_TYPE_3K3DES					0x02
#define KEYWORD_TYPE_AES128					0x03


/* Connected tag information type */
#define CONNTAG_INF_TYPE_ISO14443P4_APPDATA                0x00 

#endif
