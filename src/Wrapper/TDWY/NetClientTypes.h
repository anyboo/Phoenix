#ifndef NETCLIENTTYPES_H
#define NETCLIENTTYPES_H

#include "GlobalTypes.h"

#ifdef WIN32
#else
#define __stdcall
#endif

#define HEAVY_MODE 0
#define LIGHT_MODE 1

#define LEN_8   8
#define LEN_10	10
#define LEN_16  16
#define LEN_32  32
#define LEN_64  64
#define LEN_63  63
#define LEN_128 128
#define LEN_256 256
#define LEN_1300 1300 //对于一次协议不能完全发送的协议，控制字符数组字段个数。比如65字节数组MAX：1300/65 = 20.剩余140字节保存其它int型变量

#define TD_FALSE 0
#define TD_TRUE  1


#define MAX_TIMESEGMENT_TYPE 2
#define MAX_TIMESEGMENT_INDEX 8

#define TD_NULL                 0L
#define TD_NULL_PTR             TD_NULL

#define TD_SUCCESS              0
#define TD_FAILURE              (-1)

#define  TD_LITTLE_ENDIAN       1234      
#define  TD_BIG_ENDIAN          4321      


#ifdef _MSC_VER
typedef __int64                 TD_S64;
typedef unsigned __int64        TD_U64;
#endif

#if defined __INTEL_COMPILER || defined __GNUC__
typedef long long               TD_S64;
typedef unsigned long long      TD_U64;
#endif

#define MAX_LOCAL_CHANNEL_NUM	64	
#define MAX_DIGIT_CHANNEL_NUM	64
#define	MAX_CHANNEL_NUM		(MAX_LOCAL_CHANNEL_NUM + MAX_DIGIT_CHANNEL_NUM)	   //支持3511
#define MAX_TOTAL_CHANNEL_NUM	MAX_CHANNEL_NUM
#define MAX_VOLUME_CTRL_TYPE 5

#define MAX_CONNECTION		32
#define MAX_PORT_NUM        512
#define MAX_DHINFO_PARAM_LEN 1024
#define MAX_DOWNLOAD_NUM    5
#define MAX_COM_NUM			16	   //最大串口数
#define MAX_INTERTALK_NUM	1      //最大双向对讲数
#define MAX_PICTURECHANNEL_NUM  	1      //最大图片通道数
#define MAX_CAPTURECHANNEL_NUM  	1      //最大抓拍通道数
#define MAX_TRACECHANNEL_NUM        1

#define MAX_STREAM_TYPES		5		//最大码流类型数
#define BASIC_STREAM_TYPES		2		//主副码流类型数
#define MAX_EVENT_STREAM_TYPES  (MAX_STREAM_TYPES - BASIC_STREAM_TYPES)//事件码流类型数（包括副码流）

#define MIN_ITS_CHANNEL_NUM		5		//交通相机由于 使用通道4 给图片流通道设置参数，故通道参数结构体最小创建 4数组 大小。

#define MAX_RECV_CHANNEL    1024
#define MAX_ENCODER         1024
#define LENGTH_RECV_ORDER   1024

#define LENGTH_USER_NAME_BASE64		50
#define LENGTH_PASSWORD_BASE64		50

#define LENGTH_USER_NAME	16
#define LENGTH_PASSWORD		16
#define LENGTH_CHN_TITLE    32
#define LENGTH_CHANNEL_TITLE  64
#define LENGTH_DEVICE_NAME  32
#define LENGTH_IPV4			16	
#define LENGTH_IPV6			32
#define LENGTH_IPV6_V1		64
#define LENGTH_SUB_MASK		16

//max dev port
#define MAX_NET_PORT_NUM				65535

//connect mode
#define NETMODE_TCP     1   //Tcp connect
#define NETMODE_UDP     2   //Udp connect
#define NETMODE_MC      3   //Multicast connect
#define NVS_ACTIVE      4   //Positive Mode
#define NETMODE_P2P		5   //P2P connect

//Video resolution
#define QCIF			0   //QCif 			176*144
#define HCIF			1   //HCif			352*144	
#define FCIF			2	//Cif			352*288	
#define HD1				3	//HD1			720*288
#define FD1				4	//D1			720*576
#define MD1				5	//MD1			720*288
#define QVGA			6   //QVGA			320x240
#define VGA				7   //VGA			640*480
#define HVGA			8	//HVGA			640*240
#define HD_720P			9   //720p			1280*720
#define HD_960P			10	//960P			1280*960
#define HD_200W			11  //200W			1600*1200
#define HD_1080P		12	//1080P			1920*1080
#define HD_QXGA			13	//QXGA			2048*1536
#define QHD				0x100	//QHD		960*540
#define VZ_960H			0x200	//960H		960*576
#define VZ_5MA			0x300	//5.0MP		2448*2048
#define VZ_5M			0x400	//5M(2)		2560*1920
#define VZ_5MB			0x410	//5M(3)		2592*1944
#define VZ_5MC			0x420	//5M(4)		2592*2048
#define VZ_5MD			0x430	//5M(5)		2528*2128
#define VZ_5ME			0x500	//5M		2560*2048
#define VZ_6M			0x600	//6M		2752*2208
#define VZ_6MA			0x610	//6M		3008*2008
#define VZ_6MB			0x620	//6M		3408*2008



//视频翻转
#define VZ_QCIF_REVERSE			(0x100000+QCIF)
#define VZ_HCIF_REVERSE			(0x100000+HCIF)
#define VZ_FCIF_REVERSE			(0x100000+FCIF)
#define VZ_HD1_REVERSE			(0x100000+HD1)
#define VZ_FD1_REVERSE			(0x100000+FD1)
#define VZ_MD1_REVERSE			(0x100000+MD1)
#define VZ_QVGA_REVERSE			(0x100000+QVGA)
#define VZ_VGA_REVERSE			(0x100000+VGA)
#define VZ_HVGA_REVERSE			(0x100000+HVGA)
#define VZ_HD_720P_REVERSE		(0x100000+HD_720P)
#define VZ_HD_960P_REVERSE		(0x100000+HD_960P)
#define VZ_HD_200W_REVERSE		(0x100000+HD_200W)
#define VZ_HD_1080P_REVERSE		(0x100000+HD_1080P)
#define VZ_HD_QXGA_REVERSE		(0x100000+HD_QXGA)
#define VZ_QHD_REVERSE			(0x100000+QHD)
#define VZ_VZ_960H_REVERSE		(0x100000+VZ_960H)
#define VZ_VZ_5MA_REVERSE		(0x100000+VZ_5MA)
#define VZ_VZ_5M_REVERSE		(0x100000+VZ_5M)
#define VZ_VZ_5MB_REVERSE		(0x100000+VZ_5MB)
#define VZ_VZ_5MC_REVERSE		(0x100000+VZ_5MC)
#define VZ_VZ_5MD_REVERSE		(0x100000+VZ_5MD)

//Stream type
#define MAIN_STREAM   		0      //Basic stream(hight quality)
#define SUB_STREAM    		1      //Extended stream(low bitrate)
#define CHANNEL_INTERTALK	2		//双向对讲
#define CHANNEL_DOWNLOAD    3		//文件下载
#define STREAM_DOWNLOAD     CHANNEL_DOWNLOAD
#define CHANNEL_PICTURE     4		//图片抓拍    
#define CHANNEL_SIMUCAP  	5		//模拟抓拍流
#define CHANNEL_TRACK  	    6		//轨迹流
#define SNAPSHOT_STREAM  	8		//SnapShot stream
#define FLAG_THREE_STREAM  256		//三码流
#define FLAG_CONID_THREE_STREAM	 8 	//移位标识三码流

#define CHANNEL_THREE_STREAM	254	//三码流

#define DOWNLOAD_CHANNEL_TAG  (250)
#define DISTINGUISH_FILE_CHAN	8

#define LAN_VIDEO MAIN_STREAM     //for old compatible
#define WAN_VIDEO SUB_STREAM    

//Device type
#define NVS_T       0           //T serials NVS
#define NVS_S       1           //S serials NVS
#define NVS_TPLUS   2           //T+ serials NVS

//Product Model
#define TC_NVSS					0x0000
#define TC_NS621S				0x0010			
#define TC_NS621S_USB			0x0011			
#define TC_NS224S				0x0020			
#define TC_NC621S				0x0030			
#define TC_NC8000S				0x0040			
#define TC_NC8001S				0x0041			
#define TC_NC8100S				0x0042			
#define TC_NC8101S				0x0043			
#define TC_NC8200S				0x0044			
#define TC_NC8700S2				0x0045
#define	TC_NC9100S1_MP_IR       0x0046	
#define TC_NC8250				0x0050			
#define TC_NC9010S2_MP			0x0051			
#define TC_NC9000S2_2MP			0x0052			
#define TC_NC9010N1_2MP			0x0053			
#define TC_NC9000S3_3MP			0x0054			
#define TC_NH9106N1_2MPIR		0x0055			
#define	TC_NS921_N1_2MP			0x0056	
#define	TC_NS921S3_HD_V1        0x0056			
#define TC_CC9118_MP_E			0x0057			
#define TC_NH9206N1_MPIR_IVS	0x0058			
#define TC_NC9100S3_3MP_IR30    0x0059          
#define TC_NT9054S2_MPIR		0x005A	
#define	TC_NC9000S3_2MP_E       0x005B			
#define	TC_NC9200S3_MP_E_IR15   0x005C
#define TC_NH9206S3_2MP_IVS		0x005D	
#define	TC_NC9000S3_MP_E        0x005E
#define TC_NS621S2				0x0060			
#define TC_NS622S2				0x0061			
#define TC_NS324S2				0x0062			
#define TC_NS628S2 				0x0064	
#define	TC_FS0013ERS_HD         0x0070
#define TC_NC9100S3E_MP_IR30	0x0080
#define TC_NC9000S3E_MP			0x0081
#define TC_NC9200S3E_MP_IR		0x0082
#define TC_NC9100S3E_2MP_IR30	0x0083
#define TC_NC9000S3E_2MP		0x0084
#define TC_NC9200S3E_2MP_IR		0x0085
#define TC_NC921S3E_MP_HD_C		0x0086
#define TC_NH9406S3E_MPIR       0x0087
#define TC_NH9406S3E_2MPIR		0x0088
#define TC_NC9320S3E_2MP_E		0x0089
#define TC_NC9320S3E_MP_E		0x0090
#define TC_NC9000S3E_5MP_UE		0x0091
#define	TC_NC9001S3E_3MP_E		0x0092	
#define	TC_NC9201S3E_3MP_EI_IR	0x0093
#define	TC_NH9806S6_3MPIR_I		0x0094
#define	TC_CC9033_3MP			0x0095
#define TC_NC9401S3E_4MP_I5_E	0x0096
#define TC_NC9401S3E_4MP_I_E	0x0097
#define TC_NC9001S3E_2MP_ES		0x0098
#define TC_NH9904S6_2MP			0x0099
#define TC_NH9806S6_2MPIR_S_A	0x009A
#define TC_NC9320S3E_2MP_D		0x009B

#define TC_NC9010I_2MP			0x00A1			
#define TC_NC9000I_5MP			0x00A2			
#define TC_21X_R2				0x00A3			
#define TC_21X_R3				0x00A4			
#define TC_21X_R5				0x00A5
#define TC_217_T2				0x00A6
#define TC_217_T3				0x00A7
#define TC_218_T5	            0x00A8
#define	TC_218_T3H				0x00A9	
#define	TC_217_T5				0x00AA	
#define	TC_217_T3H				0x00AB
#define	TC_237_5MPH				0x00AC
#define	TC_238_5MPH				0x00AD
#define	TC_227_2MP_S_Z			0x00AE
#define	TC_217_1MP_S			0x00AF
#define TC_NH9X06S6_XMPIR_A		0x00D0
#define TC_NH9X06S6_XMPIR_T		0x00D1
//end

#define TC_2816AN_SH			0x0100			
#define TC_2808AN_S_3511		0x0110			
#define TC_2816AN_SD			0x0120			
#define TC_2816AN_SD_E          0x0121			
#define TC_2808AN_S_3515		0x0130			
#define TC_2804AN_MX			0x0131			
#define TC_2816AN_S				0x0140			
#define TC_H802BHX_T			0x0141			
#define TC_2832AN_SS            0x0142			
#define TC_H804BE_HD            0x0143			
#define TC_1002S2_3C			0x0150			
#define TC_H804N_HD				0x0151			
#define	TC_2802AN_SDI			0x0160			
#define TC_H908NC_H_V50			0x0161			
#define TC_2800AN_SF_L_H		0x0170			
#define TC_2800AN_SF_H			0x0171			
#define TC_2804AN_SA			0x0172			
#define TC_2800AN_SF_L			0x0173			
#define TC_2800AN_SF			0x0174			
#define TC_H804BE_P				0x0175	
#define TC_2808AN_SF_L			0x0176
#define	TC_2804AN_SQ        	0x0177
#define TC_T800GE				0x0188

#define TC_2804AN_SR_L			0x0178
#define TC_H804I_HD_BP			0x0179
#define TC_H904B_HD_V6_X		0x017A
#define TC_H908NC_HD			0x017B

#define TC_2800AN_R16_S2		0x017C
#define	TC_2804AN_M				0x017D
#define TC_2800AN_R4_S1			0x017E
#define TC_2800AN_R4_S2			0x017F
#define TC_2800AN_R8_S2			0x017F

#define TC_H804N_HD_P			0x0180
#define TC_2800AN_R16_S2_V2_0   0x0181
#define TC_2800AN_R16_S4	    0x0181
#define TC_2800AN_R32_S4        0x0181

#define TC_2816AN_SR_V2_0		0x0182
#define TC_2832AN_SR_V2_0		0x0182

#define TC_ND921S2_MP			0x0400			
#define	TC_ND921S2_2MP			0x0410			
#define	TC_ND921S2_SDI			0x0411			
#define	TC_2804AN_SDI			0x0500	
#define	TC_2864AN_SR			0x0520
#define TC_7816W				0x0600
#define TC_H904BIX_HD_I			0x0184

#define TC_T238_5MP_S_Z			0x00B0
#define TC_T238_6MP				0x00B2
#define TC_T237_6MP				0x00B3
#define TC_T238_6MP_B			0x00B4
//
#define TC_NR2160M7_E16			0x0190
#define TC_NR2080M7_E16			0x0190
#define TC_NR2080M7_E8			0x0190
#define TC_NR2040M7_E8			0x0190
#define TC_NR2020M7_E8			0x0190
#define TC_NR2080M7_S8			0x0190
#define TC_NR2040M7_S8			0x0190
#define TC_NR2020M7_S8			0x0190
#define TC_NR2040M7_S4			0x0191
#define TC_NR2020M7_S4			0x0191	
#define TC_NR2020M7_S2			0x0192

#define TC_T237_2MP_S			0x00E0

//Encode type
#define H263		11
#define H264		21
#define MP4			31
#define MJPEG		41
#define MODE_H265	23

//	SendStringToServer
#define SEND_STRING_CMD		0
#define SEND_STRING_DATA	1
#define SEND_UTF8_STRING	2

//H264 Decod mode
#define H264DEC_DECTWO	0		//decode 2 field
#define H264DEC_DECTOP	1		//decode top field （low CPU cost）

//Message define
#define WCM_RECVMESSAGE         1   //Received string
#define WCM_ERR_ORDER           2   //Occur error in command socket
#define WCM_ERR_DATANET         3   //Occur error in data socket
#define WCM_TIMEOUT_DATANET     4   //Process stream timeout
#define WCM_ERR_PLAYER          5   //Occur error in player
#define WCM_ERR_USER            6   //User define error
#define WCM_LOGON_NOTIFY        7   //Logon notify
#define WCM_VIDEO_HEAD          8   //Received video head
#define WCM_VIDEO_DISCONNECT    9   //the connection were disconnect by mediacenter

//Message of Mediacenter
#define WCM_CLIENT_CONNECT      10  //There a client connected to Mediacenter
#define WCM_CLIENT_DISCONNECT   11  //A client disconnected from Mediacenter
#define WCM_CLIENT_LOGON        12  //A client logon/logogg the Mediacenter

#define WCM_RECORD_ERR          13  //Occur when recording file

//Directory Service Mode
#define WCM_DSM_REGERR          14  //Error on proxy regist to Directory server
#define WCM_DSM_ENCODERADD      15  //A NVS regist on the proxy
#define WCM_DSM_ENCODERDEL      16  //A NVS's regist connection disconnected.
//#define	WCM_DSM_ENCODERCHANGE	28	// A NVS'S IP changed.

//Message of Download logfile
#define WCM_LOGFILE_FINISHED    17  //When logfile download finished

//Message of query file
#define WCM_QUERYFILE_FINISHED  18  //Query finished record files

#define WCM_DWONLOAD_FINISHED   19  //Download finished
#define WCM_DWONLOAD_FAULT		20  //Download fault
#define WCM_REBUILDINDEX        22  //Finished of rebuild index file

//Message of talk
#define WCM_TALK				23  //Begin to talk

//Message of DiskManager
#define WCM_DISK_FORMAT_PROGRESS	24
#define WCM_DISK_FORMAT_ERROR		25
#define WCM_DISK_PART_ERROR			26

//Message of Backup Kernel
#define	WCM_BUCKUP_KERNEL			27

//Message of LocalstoreClearDisk
#define	WCM_LOCALSTORE_PROGRESS		28
#define WCM_DOWNLOAD_INTERRUPT		29	//  Download interrupt    
#define WCM_QUERYLOG_FINISHED		30  //	Query finished log

#define WCM_INTERTALK_READY			31	//	Intertalk is ready for now ...
#define WCM_CONTROL_DEVICE_RECORD	32	//	Control device record (start, stop, package)

#define WCM_RECORD_OVER_MAX_LIMIT	33	//	The size of record file is too big, and we should start to capture a new file.
#define WCM_ERR_DATANET_MAX_COUNT	34	//	Max DataNet

#define WCM_CDBURN_STATUS			35
#define WCM_NEED_DECRYPT_KEY		36	//	Need decrypt key for video
#define WCM_DECRYPT_KEY_FAILED		37	//	decrypt key is not matched
#define WCM_DECRYPT_SUCCESS			38	//	decrypt success

#define WCM_ERR_DIGITCHANNEL_NOT_ENABLED	39	//	The digital channel is not enabled
#define WCM_ERR_DIGITCHANNEL_NOT_CONNECTED	40	//	The digital channel is not connected

#define WCM_ENCRYPT_CLEARED			41   //	clear encrypt
#define WCM_FTP_UPDATE_STATUS       42   //FTP_UPDATE_STATUS
#define	WCM_BUCKUP_IMAGE			43
#define WCM_REBUILDINDEX_PROGRESS   44   //rebuild index file progress

#define	WCM_ILLEGAL_RECORD			45   //record notify when there is illegal patking

#define WCM_QUERY_ATMFILE_FINISHED  46  //Query ATM record files finished

#define WCM_AUTOTEST_INFO			47  //自动化调试@130109

#define WCM_LASTERROR_INFO			48	//设备返回的错误码

#define	WCM_LOCALSTORE_LOCK_FILE	49  //文件加解锁

#define WCM_DISK_QUOTA				50	//磁盘配额

#define WCM_CONNECT_INFO			51	//连接信息

#define WCM_DOWNLOAD_VOD_TRANS_FAILED		52	//Vod Transform Failed

#define WCM_USER_CHANGE             100          //用户信息改变
#define WCM_UNSUPPORT_STREAM        101          //设备不支持该路码流
#define WCM_BROADCAST_MSG			102          //通用广播消息
#define WCM_VCA_SUSPEND				103          //暂停智能分析通知消息
#define	WCM_ITS_ILLEGAL_RECORD		104			 //违章录像操作状态
#define WCM_BACKUP_SEEKWORKDEV		105			 //组播搜索工作机搜索结果通知消息
#define WCM_IPSAN_DISCOVERY			108			 //IPSAN设备发现

#define WCM_RAID_STATUS				109			//阵列状态消息
#define WCM_HDD_STATUS				110			//物理磁盘状态消息
#define WCM_VIRTUALDISK_STATUS		111			//虚拟磁盘状态消息
#define WCM_HOTBACK_DEV_STATUS		112			//工作机广播热备机状态
#define WCM_WORD_DEV_STATUS			113			//热备机广播工作机状态
#define WCM_ALARM_INFORMATION       114         //动环主机实时数据
#define WCM_ALARM_OUT_STATUS		115         //报警输出端口状态
#define WCM_ALARM_SCHEDULE_STATUS   116         //布防状态
#define WCM_EXPORT_CONFIG_FINISHED  117         //导出配置完成
#define WCM_ALM_OUTPORT_SET			118		    //设置报警输出端口的状态（开路还是闭路）
#define WCM_VOD_PLAY_FINISHED		119		    //vod播放完成
#define WCM_VOD_PLAY_INTERRUPT		120		    //vod播放中断
#define WCM_PSECH_STATE				121		    //pse channel state
#define WCM_EMAIL_TEST_RESULT		122		    //Email test result
#define WCM_DISK_SMART_INFO			123		    //
#define WCM_ITS_TRAFFICFLOWREPORT	124		    //
#define WCM_CHANNEL_TALK			125
#define WCM_GET_CREATEFREEVO		126
#define WCM_USER_MODIFYPSW			127			//修改密码
#define WCM_DISK_OPERATION          128         //磁盘操作
#define WCM_DOWNLOAD_SUCCESS		129
#define WCM_DOWNLOAD_FAULT			130
#define WCM_GIGITAL_CHN_BATCH		131			//digital channel batch
#define WCM_LIFEMONITOR_HBREAL		132			//heart rate and blood oxygen
#define WCM_LIFEMONITOR_GRAMREAl	133			//waveform data
#define WCM_PREVIEWREC_DEVAMPLITUDE	134
#define WCM_QUERYFILE_FAULT			135			//Query fault record files
//Number of Show Video
#define MAX_DRAW_NUM	2
#define MAX_OSDTYPE_NUM         10
#define MAX_OSD_REALTIME_NUM	16  //动环主机使用

//User 
#define AUT_BROWSE            1     //Only can preview video
#define AUT_BROWSE_CTRL       2     //Can preview and control device
#define AUT_BROWSE_CTRL_SET   3     //Preview, control device, modify settings
#define AUT_ADMIN             4      //Super user, No.0 user is super user,
                             //User name is Admin, which can not be modified,
                             //Can add, delete, modify user's authority

typedef int						ALARMTYPE;

//Logon state

#define LOGON_DSMING       3    //DSM（Directory Sevices Mode）connecting
#define LOGON_RETRY        2    //Retry
#define LOGON_SUCCESS      0    //Logon successfully
#define LOGON_ING          1    //Being logon
#define LOGON_FAILED       4   //Fail to logon
#define LOGON_TIMEOUT      5   //Logon timeout
#define NOT_LOGON          6   //Not logon
#define LOGON_DSMFAILED    7   //DSM connection failure
#define LOGON_DSMTIMEOUT   8   //DSM connection 
#define LOGON_SUCCESS_LIGHT	9  //Light Logon successfully

//Player state

#define    PLAYER_STOP          0    //Not require to play
#define    PLAYER_WAITTING      0x01 //Require to play but not play, waiting for data
#define    PLAYER_PLAYING       0x02 //Playing
#define    PLAYER_CARDWAITTING  0x04 //Require to hardware decode
#define    PLAYER_CARDPLAYING   0x08  //Being hardware decode output


//PAL/NTSC
// enum VIDEO_NORM
// {
//     VIDEO_MODE_PAL    = 0x00,
//     VIDEO_MODE_NTSC   = 0x01,
//     VIDEO_MODE_AUTO   = 0x02
// };
typedef int VIDEO_NORM;
#define VIDEO_MODE_PAL 0x00
#define VIDEO_MODE_NTSC 0x01
#define VIDEO_MODE_AUTO 0x02

//Character overlay type
// enum
// {
//     OSDTYPE_TIME      = 0x01,   //Overlay time
//     OSDTYPE_TITLE     = 0x02,   //Overlay character string
//     OSDTYPE_LOGO      = 0x04    //Overlay mark
// };

#define OSDTYPE_TIME	0x01
#define OSDTYPE_TITLE	0x02
#define OSDTYPE_LOGO	0x04
#define OSDTYPE_ITS		0x05

//Image property
// enum
// {
//     BRIGHTNESS = 0,         //Brightness
//     CONTRAST   = 1,         //Contrast
//     SATURATION = 2,         //Saturation
//     HUE        = 3          //Hue
// };
#define BRIGHTNESS 0
#define CONTRAST   1
#define SATURATION 2
#define HUE        3

//Prefer mode
// enum
// {
//     PRE_VDOQUALITY = 0,     //Video quality prefer
//     PRE_FRAMERATE  = 2      //Framerate prefer
// };
#define PRE_VDOQUALITY 0
#define PRE_FRAMERATE  2

//Stream encode type
// enum
// {
//     NO_STREAM   = 0,    //Null
//     ONLY_VIDEO  = 1,    //Video stream
//     ONLY_AUDIO  = 2,    //Audio stream
//     VIDEO_AUDIO = 3     //Video and audio stream
// };
#define NO_STREAM  0
#define ONLY_VIDEO 1
#define ONLY_AUDIO 2
#define VIDEO_AUDIO 3

// enum
// {
//     DISABLE     = 0,
//     ENABLE      = 1
// };

#define  DISABLE 0
#define  ENABLE  1
// enum
// {
//     LOW         = 0,
//     HIGH        = 1
// };
#define LOW 0
#define HIGH 1

//Talk
//enum
//{
//    TALK_BEGIN_OK       = 0,    //Start talk successfully
//    TALK_BEGIN_ERROR    = 1,   //Fail to start talk
//    TALK_ERROR          = 2,    //Talk error
//    TALK_END_OK         = 3
//};

#define TALK_BEGIN_OK			0
#define TALK_BEGIN_ERROR		1
#define TALK_ERROR				2
#define TALK_END_OK				3

//enum
//{
//    TALK_STATE_NO_TALK      = 0,
//    TALK_STATE_ASK_BEGIN    = 1,
//    TALK_STATE_TALKING      = 2,
//    TALK_STATE_ASK_STOP     = 3,
//    TALK_STATE_RESUME       = 4         //  2010-4-26-16:21 @yys@,  正在自动恢复对讲过程中
//
//};

#define TALK_STATE_NO_TALK			0			//	没有对讲
#define TALK_STATE_ASK_BEGIN		1			//	已经请求开始对讲
#define TALK_STATE_TALKING			2			//	正在对讲
#define TALK_STATE_ASK_STOP			3			//	已经请求停止对讲
#define TALK_STATE_RESUME			4			//  2010-4-26-16:21 @yys@,	正在自动恢复对讲过程中

//Core remote upgrade
// enum
// {
//     PRO_UPGRADE_OK      = 0,    // Remote upgrade success
//     PRO_UPGRADE_ERROR   = -1    // Remote upgrade failure
// };
#define  PRO_UPGRADE_OK 0
#define  PRO_UPGRADE_ERROR -1
#define  PRO_UPGRADE_READY -2

// enum
// {
//     WEB_UPGRADE_OK      = 0,    // Remote upgrade success
//     WEB_UPGRADE_ERROR   = -1    // Remote upgrade failure
// };
#define WEB_UPGRADE_OK 0
#define WEB_UPGRADE_ERROR -1
#define WEB_UPGRADE_READY -2
//兼容IE
#define WEB_UPGRADE_REDAY	WEB_UPGRADE_READY

//视频参数和设备定义
typedef int							PARATYPE;
#define PARA_VIDOEPARA				0
#define PARA_VIDEOPARA				0 
#define PARA_VIDEOPARA				0 
#define PARA_VIDEOQUALITY			1     
#define PARA_FRAMERATE				2     
#define PARA_IFRAMERATE				3     
#define PARA_STREAMTYPE				4     
#define PARA_MOTIONDETECTAREA		5
#define PARA_THRESHOLD          	6    
#define PARA_MOTIONDETECT			7     
#define PARA_OSDTEXT				8    
#define PARA_OSDTYPE				9     
#define PARA_ALMINMODE				10    
#define PARA_ALMOUTMODE				11    
#define PARA_ALARMINPUT				12    
#define PARA_ALARMOUTPUT			13    
#define PARA_AlMVDOCOVTHRESHOLD		14    
#define PARA_ALMVIDEOCOV			15    
#define PARA_RECORDCOVERAREA		16    
#define PARA_RECORDCOVER			17    
#define PARA_ALMVDOLOST				18    
#define PARA_DEVICETYPE				19    
#define PARA_NEWIP					20
#define PARA_AUDIOCHN				21    
#define PARA_IPFILTER				22    
#define PARA_COVERAREA				23    
#define PARA_VIDEOHEADER			24
#define PARA_VIDEOSIZE				25    
#define PARA_BITRATE				26    
#define PARA_DATACHANGED			27
#define PARA_PARSECHANGED			28   

#define PARA_APPIFRAMERATE			29    
#define PARA_APPFRAMERATE			30    
#define PARA_APPVIDEOQUALITY		31    
#define PARA_APPVIDEOSIZE			32    
#define PARA_APPSTREAMTYPE			33    
#define PARA_APPBITRATE				34    
#define PARA_APPCOVERAREA			35    
#define PARA_APPVIDEOHEADER			36    

#define PARA_REDUCENOISE			37    
#define PARA_BOTHSTREAMSAME			38    
#define PARA_PPPOE					39    

#define PARA_ENCODETYPE				40    
#define PARA_PREFERMODE				41    

#define PARA_LOGFILE				42    
#define PARA_SETLOGOOK				43    

#define PARA_STORAGE_SCHEDULE   	44   
#define PARA_STORAGE_TASKSTATE		45    
#define PARA_STORAGE_ALARMSTATE		46    
#define PARA_STORAGE_PRERECORD		47    
#define PARA_STORAGE_RECORDRULE		49    
#define PARA_STORAGE_EXTNAME		50    
#define PARA_STORAGE_MAPDEVICE		51    
#define PARA_STORAGE_MOUNTUSB		52    
#define PARA_STORAGE_DISKSTATE		53    
#define PARA_AUDIOCODER				54    
#define PARA_NPMODE					55    
#define PARA_STORAGE_RECORDSTATE	56    

#define PARA_PU_MANAGERSVR			57    
#define PARA_PU_DEVICEID			58    
#define PARA_STREAMCLIENT			59    
#define PARA_DATEFORMAT				60    
#define PARA_HTTPPORT				61    

#define PARA_CMOS_SCENE				62    
#define PARA_SMTP_INTO				63    
#define PARA_SMTP_ENABLE			64    
#define PARA_SENSORFLIP				65    

#define PRAM_WIFI_PARAM				66
#define PARA_WIFI_SEARCH_RESULT		67   

#define PARA_PRIVACYPROTECT			68
#define PARA_NTP					69
#define PARA_ALARTHRESHOLD			70
#define PARA_OSDALPHA				71
#define PARA_WORDOVERLAY			72

#define PARA_ALARMSERVER			73
#define PARA_DHCP_BACK				74
#define PARA_WIFIDHCP				75
#define PARA_DIAPHANEITY			76
#define PARA_PTZ_PROTOCOL			77
#define PARA_3D						78
#define PARA_DISK_USAGE				79
#define PARA_VIDEOPARA_SCHEDULE		80
#define PARA_ALARM_INPORT			81
#define PARA_ALARM_OUT				82
#define PARA_INPORT_SCHEDULE		83
#define PARA_OUTPORT_SCHEDULE		84
#define PARA_MOTION_SCHEDULE		85
#define PARA_VDOLOST_SCHEDULE		86
#define PARA_VDOLOST_LINKREC		87
#define PARA_MOTIONDEC_LINKREC		88
#define PARA_ALMINPORT_LINKREC		89
#define PARA_VDOLOST_LINKSNAP		90
#define PARA_MOTIONDEC_LINKSNAP		91
#define PARA_ALMINPORT_LINKSNAP		92
#define PARA_VDOLOST_LINKPTZ		93
#define PARA_ALMINPORT_LINKPTZ		94
#define PARA_VDOLOST_LINKSNDDIS		95
#define PARA_MOTIONDEC_LNKSNDDIS	96
#define PARA_ALMINPORT_LNKSNDDIS	97
#define PARA_ALMINPORT_LNKOUT		98
#define PARA_VDOLOST_LNKOUT			99
#define PARA_MOTIONDEC_LNKOUT		100
#define PARA_OUTPORT_DELAY			101
#define PARA_UPNP_ENABLE			102
#define PARA_SYSINFO_RESULT			103
#define PARA_DDNSCHANGED 			104	   
#define PARA_FUNCLIST				105	
#define PARA_OUTPORT_STATE			106
#define PARA_ZTEINFO				107
#define PARA_ONLINESTATE			108
#define PARA_DZINFO					109
#define PARA_COMSERVER				110
#define PARA_VENCTYPE				111  //视频编码改变 主码流
#define PARA_PTZAUTOPBACK			112
#define PARA_3GDEVICESTATUS			113
#define PARA_3GDIALOG				114
#define PARA_3GMESSAGE				115
#define PARA_HDCAMER				116
#define PARA_HXLISTENPORTINFO		117
#define PARA_3GTASKSCHEDULE			118
#define PARA_3GNOTIFY				119
#define PARA_COLORPARA				120
#define PARA_EXCEPTION				121
#define PARA_CAHNNELNAME			122
#define PARA_CUSTOMRECTYPE			123
#define PARA_FTP_UPDATE				124
#define PARA_FTP_UPDATE_STATUS		125
#define PARA_CHNPTZFORMAT			126
#define PARA_3GVPDN					127
#define PARA_VIDEOCOVER_SCHEDULE	128
#define PARA_CHNPTZCRUISE			129
#define PARA_VDOCOVER_LINKPTZ		130

#define PARA_VCA_CHANNEL			131
#define PARA_VCA_VIDEOSIZE			132
#define PARA_VCA_ADVANCED			133
#define PARA_VCA_TARGET				134
#define PARA_VCA_ALARMSTAT			135
#define PARA_VCA_RULESET			136
#define PARA_VCA_RULEEVENT0			137
#define PARA_VCA_RULEEVENT1			138
#define PARA_VCA_RULEEVENT2			139
#define PARA_VCA_ALARMSCHEDULE		140
#define PARA_VCA_SCHEDULEENABLE		141
#define PARA_VCA_ALARMLINK			142

#define PARA_FTP_SNAPSHOT			143
#define PARA_FTP_LINKSEND			144
#define PARA_FTP_TIMEDSEND			145

#define PARA_DVR3G_POWERDELAY		146
#define PARA_DVR3G_SIMNUM			147
#define PARA_DVR3G_GPSINFO			148
#define PARA_DVR3G_GPSFILTER		149

#define PARA_CDBURN_MODE			150					//	刻录方式设置
#define PARA_VIDEOENCRYPT			151
#define PARA_PREIVEWREOCRD			152

#define PARA_DIGITALCHANNEL			153
#define PARA_NPMODE_EX				154

#define	PARA_SIP_VIDEOCHANNEL		155			//	SIP视频通道设置
#define PARA_SIP_ALARMCHANNEL		156			//	SIP报警通道设置

#define PARA_VIDEOCOMBINE			157        //	多画面合成
#define PARA_PLATFORM_RUN			158			//	PlatForm Run

#define PARA_ITS_CHNLENABLE         159       //
#define PARA_ITS_CHNLLOOP           160       //
#define PARA_ITS_CHNLTIME           161       //
#define PARA_ITS_CHNLSPEED          162       //
#define PARA_ITS_CHNLRECO           163       //
#define PARA_ITS_CHNLVLOOP          164       //

#define PARA_ITS_LPOPTIM_FIRSTHZ    165       //
#define PARA_ITS_LPOPTIM_NPENABLE   166       //
#define PARA_ITS_LPOPTIM_OTHER      167       //

#define PARA_ITS_TIMERANGE			168         //相机时间段设置 
#define PARA_ITS_TIMERANGEPARAM     169			//时间段参数设置
#define PARA_ITS_TIMERANGE_AGCBLOCK			170     //时间段测光区域使能
#define PARA_ITS_TIMERANGE_FLASHLAMP		171     //时间段闪光灯使能
#define PARA_ITS_DETECTMODE					172     //相机检测模式设置
#define PARA_ITS_BLOCK						173		//相机测光区域设置
#define PARA_ITS_LOOPMODE					174		//线圈工作模式	
#define PARA_ITS_DEVICETYPE					175		//相机外设类型
#define PARA_ITS_SWITCHTIME					176     //设置视频与外触发模式切换时间和设置外设延时抓拍时间（主要用于雷达）
#define PARA_JPEGQUALITY					177     //设置JPEG图片质量	

#define PARA_VCA_RULEEVENT9					178		//智能分析人脸识别参数
#define PARA_VCA_RULEEVENT10				179		//智能分析视频诊断参数

#define PARA_ITS_TEMPLATENAME				180		//高清相机模板名称设置

#define PARA_ITS_RECOPARAM					181		//交通-设置识别算法参数

#define PARA_ITS_DAYNIGHT					182		//交通-白天夜晚开始时间设置
#define PARA_ITS_CAMLOCATION				183		//交通-相机位置
#define PARA_ITS_WORKMODE					184		//交通-相机工作模式
#define PARA_TIMEZONE_SET                   185     //设置时区
#define PARA_LANGUAGE_SET                   186     //设置语言

#define PARA_CHANNELENCODEPROFILE_SET       187     //通道编码

#define PARA_EXCEPTION_HANDLE               188    //异常处理

#define PARA_ITS_CHNLIGHT					189		//车道对应的信号灯
#define PARA_ITS_CAPTURE					190		//车道对应的抓拍位置
#define PARA_ITS_RECOGNIZE					191		//是否启用识别功能								
#define PARA_IMG_DISPOSAL					192		//图片效果处理功能
#define PARA_WATERMARK						193		//是否启用水印功能
#define PARA_SYSTEM_TYPE					194		//系统类型
#define PARA_ITS_LIGHT_INFO					195		//信号灯对应的参数

//IPC 3MP
#define PARA_CHECKBADPIXEL_STATUS           196     //坏点检测状态
#define PARA_DEVICE_STATE                   197     //设备实时状态
#define PARA_CHECKIRIS_STATUS               198     //光圈检测状态

#define PARA_ITS_ILLEGALPARK				199     //设置违章停车参数
#define PARA_ITS_ILLEGALPARKPARAM           200    //设置违章停车标定区域参数

#define PARA_LAN_IPV4						201     //网卡IPv4地址
#define PARA_LAN_IPV6						202     //网卡IPv6地址
#define PARA_LAN_WORKMODE					203     //网络工作模式
#define PARA_PWM_STATUS                     204     //红外灯PWM控制值

#define PARA_AUDIOMIX	                    205     //混音合成参数
#define PARA_AUDIOLOST_ALARMSCHEDULE		206		//音频丢失报警参数模板
#define PARA_AUDIOLOST_ALARMLINK			207		//音频丢失报警参数模板
#define PARA_AUDIOLOST_ALARMSCHENABLE		208		//音频丢失报警参数模板

#define PARA_ITS_SWITCH_INTERVAL			209		//相机外触发纯视频自动切换时间间隔
#define PARA_ITS_VIDEODETECT				210		//智能相机图像检测
#define PARA_ITS_REFERENCLINES				211		//智能相机绊线设置
#define PARA_ITS_DETECTAREA					212		//智能相机检测区域设置
#define PARA_ITS_RECOTYPE					213		//智能相机算法类型设置
#define PARA_METHODMODE				        214     //设置视频源制式的获取方式

#define PARA_LOCALSTORE_CHANNELPARA	        215     //通道相关存储策略


#define PARA_WIFIWORKMODE				    216      //设置WIFI工作模式
#define PARA_WIFIAPDHCPPARA					217      //设置DHCP服务配置参数 Ip范围 租用时间等
#define PARA_WIFIAPPARA						218      //设置WIFI_AP网络参数信息

#define PARA_ITS_ENABLEPARAM				219		 //设置交通相关功能使能
#define PARA_ITS_REDLIGHTDETECTAREA			220		 //设置红灯检测区域参数
#define PARA_ATM_INFO						221		 //设置ATM信息
#define PARA_AUDIO_SAMPLE					222		 //设置音频采样率
#define PARA_IPCPnP							223		 //设置数字通道即插即用
#define PARA_WIFIDHCPAP						224		 //设置AP模式DHCP功能
#define PARA_MIXAUDIO   			        225		 //混音
#define PARA_DOME_TITLE   			        226		 //	球机标题
#define PARA_HARDWARE_VOLTAGE               227      //设置8127相机电压

#define PARA_ALARMTRIGGER_AUDIOLOSE	        228      //设置音频丢失报警参数值

#define PARA_VIDEOCOVER_ALARMSCHEDULE		229		 //视频遮挡报警参数模板
#define PARA_VIDEOCOVER_ALARMLINK			230		 //视频遮挡报警联动设置
#define PARA_VIDEOCOVER_ALARMSCHENABLE		231		 //视频遮挡报警模板使能
#define PARA_HOLIDAY_PLAN_SCHEDULE			232		 //假日模板
#define PARA_VCA_RULEEVENT12				233
#define PARA_VCA_RULEEVENT13				234
#define PARA_VDOLOST_LNKSINGLEPIC			235
#define PARA_ALMINPORT_LNKSINGLEPIC			236
#define PARA_MOTIONDEC_LNKSINGLEPIC			237
#define PARA_VDOCOVER_LNKSINGLEPIC			238
#define PARA_CHANNEL_TYPE				    239		//通道类型
#define PARA_OTHER_ALARMSCHEDULE			240 	//其他报警参数模板
#define PARA_OTHER_ALARMLINK				241		//其他报警参数模板
#define PARA_OTHER_ALARMSCHENABLE			242		//其他报警参数模板
#define PARA_PORTSET						243		//端口设置参数改变
#define PARA_DISKGROUP						244		
#define PARA_DISKQUOTA						245			
#define PARA_NEW_IP							246

//add by wd @20130603
#define  PARA_ITS_CROSSINFO					247     //路口信息
#define  PARA_ITS_AREAINFO					248     //增益区域
#define  PARA_JPEGSIZEINFO					249    //相机抓拍分辨率	
#define  PARA_DEVSTATUS						250
//add end 

#define  PARA_HD_TEMPLATE_INDEX				251		//高清模板编号
#define	 PARA_STREAM_DATA					252		//用户自定义数据插入
#define  PARA_VCA_RULEEVENT14_LEAVE_DETECT	253		//离岗检测消息
#define  PARA_DOME_PTZ						254		//球机PTZ参数改变消息
#define  PARA_ITS_TEMPLATEMAP				255     //时间段与高清摄像机模板映射关系
#define  PARA_GPS_CALIBRATION				256     //是否启用GPS校时
#define  PARA_ALARM_THRESHOLD				257     //低压报警阈值
#define  PARA_SHUTDOWN_THRESHOLD			258     //低压关机阈值
#define  PARA_SMART_SCHEDULE				259		//智能录像模板
#define  PARA_VIDEO_SCHEDULE				260
#define  PARA_ITS_CHNCARSPEED				261		//车道内车辆速度参数

#define  PARA_DOME_SYETEM				    262		//球机系统参数
#define  PARA_DOME_MENU						263		//球机菜单参数
#define  PARA_DOME_WORK_SCHEDULE			264		//球机运行模板参数
#define  PARA_INTERESTED_AREA 				265		//感兴趣区域参数
#define  PARA_APPEND_OSD				    266		//附加字符叠加参数
#define  PARA_AUTO_REBOOT					267		//NVR自动重启布防时间
#define	 PARA_IP_FILTER						268		//IP地址过滤
#define	 PARA_DATE_FORMAT					269		//日期时间格式
#define  PARA_NETCONNECT_INFO_MTU			270     //MTU参数（底层socket发送分包的最大单元）
#define  PARA_LANSET_INFO					271     //网卡配置参数
#define  PARA_DAYLIGHT_SAVING_TIME			272		//夏令时
#define  PARA_NET_OFF_LINE					273
#define	 PARA_PICTURE_MERGE					274		//图像合成
#define  PARA_SNAP_SHOT_INFO			    275		//前后抓拍参数
#define	 PARA_IO_LINK_INFO					276
#define  PARA_COMMAND_ITS_FOCUS				278		//聚焦相机控制
#define  PARA_VCA_RULEEVENT7				279		//物品遗留丢失
#define	 PARA_VCA_RULEEVENT11				280		//跟踪事件
#define	 PARA_DEV_COMMONNAME  				281		//自定义设备通用接口的别名（64字节）

#define  PARA_APPVENCTYPE				    282		//视频编码改变 副码流
#define  PARA_THIRD_VENCTYPE				283		//视频编码改变 三码流
#define	 PARA_ITS_DEV_COMMONINFO  			284		//ITS设备通用信息消息
#define  PARA_ITS_COMPOUND_PARAM			285		//设置混合触发相关参数

#define  PARA_DEV_AUDIO_VOLUME				286		//设备音频控制方式或音量改变
#define  PARA_FILE_APPEND_INFO				287		//录像文件附加信息
#define	 PARA_VCA_RULEEVENT3				288		//智能分析徘徊事件
#define	 PARA_VCA_RULEEVENT4				289		//智能分析停车事件	
#define	 PARA_VCA_RULEEVENT5				290		//智能分析奔跑事件
#define  PARA_VCA_RULEEVENT8				291		//智能分析被盗物事件
#define  PARA_ANYSCENE						292		//分析场景
#define  PARA_ANYCRUISETYPE					293		//场景应用巡航
#define  PARA_ANYCRUISE_TIMER				294		//场景应用定时巡航模板
#define  PARA_ANYCRUISE_TIMERANGE			295		//场景应用时间段巡航模板
#define  PARA_TRACK_ASTRICT_LOCATION		296		//跟踪限位
#define  PARA_FACE_DETECT_ARITHMETIC		297		//人脸检测算法
#define  PARA_PERSON_STATISTIC_ARITHMETIC	298		//人数统计算法
#define  PARA_TRACK_ARITHMETIC				299		//智能跟踪算法
#define  PARA_TRACK_ZOOMX					300		//跟踪倍率系数--实时设置
#define  PARA_COVER_ALARM_AREA				301		//视频遮挡报警区域参数
#define  PARA_3D_PRAVICY_INFO				302     //3D隐私遮挡区域参数改变	

#define  PARA_WORKDEV_BACKUP_ENABLE			303		//工作机热备使能
#define  PARA_BACKUPDEV_INFO				305		//热备机配置信息
#define  PARA_IPSAN_DISKINFO				306		//IPSAN配置信息
#define  PARA_RAID_WORKMODE					307		//RAID工作模式信息  
#define  PARA_RAIDARRAY_INFO				308	    //RAID列表信息     
#define  PARA_VIRTUAL_DISK_INFO			    309	    //虚拟磁盘信息    
#define  PARA_RAID_ENABLE					310		//RAID功能使能状态
#define  PARA_HOTBACKUP_WORKMODE			311		//热备工作模式信息  
#define  PARA_ITS_SECURITY_CODE				312		//设置防伪码位数
#define  PARA_ITS_LIGHT_SUPPLY				313		//车牌亮度补偿
#define  PARA_ITS_CAPTURE_CPUNT				314		//抓拍张数
#define  PARA_ITS_ILLEGAL_PARK_INFO			315		//违章停车标定状态信息
#define  PARA_ITS_LINE_PRESS_PERMILLAGE		316		//设置车道内车辆轮廓压线千分比参数
#define  PARA_ITS_WORDOVERLAY				317     //ITS字符叠加
#define  PARA_RTMP_URL_INFO					318     //发送RTMP列表信息
#define  PARA_RTSP_LIST_INFO				319     //RTSP列表信息
#define  PARA_DEV_FORBID_CHN				320     //禁止通道数
#define  PARA_ALARM_IN_CONFIG				321     //报警通道配置改变消息
#define  PARA_ALARM_IN_LINK					322     //报警通道联动改变消息
#define  PARA_ALARM_SCHEDULE				323     //报警模板改变消息
#define  PARA_ALARM_IN_OSD					324     //字符叠加改变消息
#define  PARA_COM_DEVICE					 	325     //串口设备配置改变消息
#define  PARA_DH_ALARM_HOST		             	326     //报警服务器参数改变消息
#define  PARA_DH_WORK_MOD		             	327		//动环布防工作模式
#define  PARA_DH_DEV_TEST		             	328		//动环调试模式
#define  PARA_ALARM_IN_OFFLINE_TIME_INTERVEL 	329     //脱机扫描间隔改变消息
#define  PARA_ELENET_METER					 	330     //Electronic Net Meters Param
#define  PARA_DH_ADD_ALARM_HOST					331		//添加报警主机
#define  PARA_DH_DEVICE_ENABLE					332		//动环设备使能
#define  PARA_ALM_OUT_LHP						333		//报警触发方式，输出开路报警还是闭路报警
#define  PARA_OUTPUT_COLOR_TYPE					334		//设置色彩输出类型
#define  PARA_ITS_RADER_CFG_INFO				335		//ITS Roadway rader area config info
#define  PARA_VCA_RULEEVENT15_WATER_DETECT		336		//water level monitor change message
#define  PARA_CHANGE_VIDEO_INPUT_MODE			337		//change videoinput mode
#define  PARA_CHANGE_WATER_STEADY_PERIOD		338		//water steady period
#define  PARA_CHANGE_WATER_SNAP_INFO    		339		//water steady period

#define  PARA_STORAGE_ALARMPRE   				340
#define  PARA_FAN_TEMP_CONTRO					341
#define  PARA_MODIFYAUTHORITY					342
#define  PARA_VCA_VIDEODIAGNOSE					343    	//VCA video diagnose
#define  PARA_VCA_AUDIODIAGNOSE					344    	//VCA audio diagnose
#define  PARA_VCA_TRIPWIRE300W					345    	//VCA Tripwire For 300W

#define  PARA_PSE_CHANNEL_MODE					346
#define  PARA_PSE_BARCODE						347
#define  PARA_VCA_RULEEVENT14_LEAVE_DETECTEX	348		//VCA Leave Detect For 300W
#define  PARA_FAN_WHITELIGHT					349
#define  PARA_APERTURE_TYPE						350
#define  PARA_IDENTI_CODE						351

#define  PARA_EXCEPTION_INFO					353
#define  PARA_NET_CLIENT_VO_VIEW_SEGMENT		354 	//Custom Picture segmentation way
#define  PARA_NET_CLIENT_PREVIEWREC 			355		//Vc and VGA/HDMI1 or HDMI2 Output Homology
#define  PARA_NET_CLIENT_PRE_MODE 				356		//Preview mode
#define  PARA_ITS_TRAFFICFLOW					357 	//ITS Lane Traffic Statistics
#define  PARA_ITS_TRAFFICFLOWREPORT 			358 	//ITS Traffic Flow Report
#define  PARA_ITS_ILLEGALTYPE					359 	//ITS Illegal Type
#define  PARA_ITS_PICMERGEOVERLAY				360		//ITS Pictrue Merge Over Lay
#define  PARA_NET_CLIENT_AUDIO_PONTICELLO		361 	//Audio Ponticello
#define  PARA_VCA_FACEMOSAIC 					362		//Face Mosaic
#define  PARA_ITS_FTP_UPLOAD					363
#define  PARA_ITS_SIGNAL_LIGHT					364
#define  PARA_DISK_SMART						365
#define	 PARA_OSD_DOT_MATRIX					366
#define	 PARA_OSD_VECTOR						367
#define  PARA_FRAMERATE_LIST					368
#define  PARA_MAX_LANTRATE						369
#define  PARA_ITS_CARLOGO_OPTIM					370
#define  PARA_NET_CLIENT_CREATEFREEVO			371
#define  PARA_EIS								373
#define  PARA_SVC								374
#define  PARA_SERVICE_SNMP						375
#define  PARA_ALM_IN_LHP						376		//报警触发方式，输入开路报警还是闭路报警
#define  PARA_NET_CLIENT_PTZ_LIST				377
#define  PARA_ITS_CHNL_DELAY_DISTANCE			378
#define  PARA_DEV_TRENDS_ROI					379
#define  PARA_NET_CLIENT_COLORPARA_LIST			380
#define  PARA_NET_EXCEPTION_LINKOUTPORT			381     //异常处理端口联动
#define  PARA_NET_WIRELESSMODULE			    382     //获取设备支持无线模块
#define  PARA_DEV_EVENT							383     //事件模板使能
#define  PARA_DEV_TELNET						384     //telnet使能
#define	 PARA_ILLEGAL_ALARMLINK					385
#define  PARA_VDOLOST_LNKMAIL					386
#define	 PARA_ALMINPORT_LNKMAIL					387
#define  PARA_MOTIONDEC_LNKMAIL					388
#define  PARA_NET_CLIENT_SCENETIMEPOINT			389		//设置业务时间段
#define  PARA_VCA_RULE_RIVERCLEAN				390		//VCA规则(河道检测)
#define  PARA_VCA_RULE_DREDGE					391		//VCA规则(盗采盗卸)
#define  PARA_VCA_RIVER_ADVANCE					392		//VCA河道检测高级参数
#define  PARA_H323_LOCAL_Param					393		//H323 Local param
#define  PARA_H323_GK_Param						394		//H323 GK param
#define  PARA_COMMON_ENABLE_VIDEO_REVERSE		395		//video reverse
#define  PARA_LIFEMONITOR_SET_CONFIG			396		//set config
#define  PARA_OSD_EXTRA_INFO					397		//osd extra info
#define  PARA_SNAPSHOT_VIDEOSIZE				398		//snapshot video size
#define  PARA_ITS_IPDCAPMODEL					399		//set capture model
#define  PARA_ITS_IPDCARPOSITION				400     //set manul capture car potion
#define  PARA_DEV_DISKPOPSEAL					401     //disk pop & seal state
#define  PARA_NETSERVER_SERVERINFO				402		//server info
#define  PARA_COMMONENABLE_IllegalPark			403     //ITS Illegal Park

#define  MAX_SCENETIME_COUNT					8      //设置业务时间段
#define  MAX_SCENETIME_TYPE_COUNT				2    //设置业务时间段

typedef int							IDENTIFY;
#define CLIENT						0
#define PROXY						1
#define CLIENT_PROXY				2

// enum DECDATATYPE
// {
//     T_AUDIO8,T_YUV420,T_YUV422
// };
typedef int DECDATATYPE;
#define T_AUDIO8 0
#define T_YUV420 1
#define T_YUV422 2

typedef struct
{
    int     m_iPara[10];
    char    m_cPara[33];
}STR_Para;


#define MAX_DEVSTATUS_TYPE	6
//add by wd 20130621
#define MAX_DEVSTATUS_NUM	4
typedef struct 
{
	int     iType;
	int     iStatus[MAX_DEVSTATUS_NUM];
}STR_DevStatus;
//add end

//Templet time
/*typedef struct
{
    UINT8		m_u8StartHour;
    UINT8		m_u8StartMin;
    UINT8		m_u8StopHour;
    UINT8		m_u8StopMin;
}NVS_TEMPLETTIME,*PNVS_TEMPLETTIME;*/

//Schedle time
typedef struct
{
    unsigned short      iStartHour;
    unsigned short      iStartMin;
    unsigned short      iStopHour;
    unsigned short      iStopMin;
    unsigned short      iRecordMode; //iEnable;
}NVS_SCHEDTIME,*PNVS_SCHEDTIME;

typedef struct
{
	int		 iSize;
	int      iStartHour;
	int      iStartMin;
	int      iStopHour;
	int      iStopMin;
	int      iRecordMode; 
}NVS_SCHEDTIME_Ex,*PNVS_SCHEDTIME_Ex;

typedef struct
{
    unsigned short      m_u16Brightness;
    unsigned short      m_u16Hue;
    unsigned short      m_u16Contrast;
    unsigned short      m_u16Saturation;
    /*
    UINT8		m_u8StartHour;
    UINT8		m_u8StartMin;
    UINT8		m_u8StopHour;
    UINT8		m_u8StopMin;
    */
    NVS_SCHEDTIME strctTempletTime;
}STR_VideoParam;

typedef struct
{
    char    cEncoder[16];       //NVS IP，
    char    cClientIP[16];      //Client IP，
    int     iChannel;           //Channel Number，
    int     iStreamNO;          //Stream type
    int     iMode;              //Network mode，1（TCP）， 2（UDP），3（multicast）
}LINKINFO, *PLINKINFO;

typedef struct
{
    int             iCount;                     //Connect Count，
    unsigned int    uiID[MAX_ENCODER];          //ID
}UIDLIST, *PUIDLIST;

typedef struct
{
    char        m_cHostName[32];    //NVS host name
    char        m_cEncoder[16];     //NVS (IP)
    int         m_iRecvMode;        //Network mode
    char        m_cProxy[16];       //Proxy (IP)
    char        m_cFactoryID[32];   //ProductID
    int         m_iPort;            //NVS port
    int         m_nvsType;          //NVS type(NVS_T or NVS_S or DVR ...eg)

	int         m_iChanNum;         //encoder channel num
    int         m_iLogonState;      //encoder logon state 090414 zyp add
    int         m_iServerType;      //是主动模式设备SERVER_ACTIVE，还是被动模式设备SERVER_NORMAL
}ENCODERINFO,*PENCODERINFO;

typedef struct
{
    int             m_iServerID;        //NVS ID,NetClient_Logon 返回值
    int             m_iChannelNo;       //Remote host to be connected video channel number (Begin from 0)
    char            m_cNetFile[255];    //Play the file on net, not used temporarily
    char            m_cRemoteIP[16];    //IP address of remote host
    int             m_iNetMode;         //Select net mode 1--TCP  2--UDP  3--Multicast
    int             m_iTimeout;         //Timeout length for data receipt
    int             m_iTTL;             //TTL value when Multicast
    int             m_iBufferCount;     //Buffer number
    int             m_iDelayNum;        //Start to call play progress after which buffer is filled
    int             m_iDelayTime;       //Delay time(second), reserve
    int             m_iStreamNO;        //Stream type
    int             m_iFlag;            //0，首次请求该录像文件；1，操作录像文件
    int             m_iPosition;        //0～100，定位文件播放位置；-1，不进行定位
    int             m_iSpeed;           //1，2，4，8，控制文件播放速度
}CLIENTINFO;

//Version message structure, with which to transmit SDK version message
typedef struct
{
    unsigned short  m_ulMajorVersion;
    unsigned short  m_ulMinorVersion;
    unsigned short  m_ulBuilder;
    char*           m_cVerInfo;
}SDK_VERSION;

//OSD param
typedef struct
{
    unsigned char   ucCovTime;
    unsigned char   ucCovWord;
    int             iCovYear;
    int             iCovMonth;
    int             iCovDay;
    int             iCovHour;
    int             iCovMinute;
    int             iCovSecond;
    unsigned char   ucPosition;
    char            cCovWord[32];
}OSD_PROPERTY;

//Hardware decode to show external data parameter
typedef struct
{
    int     m_iChannelNum;      //Decode card hardware channel number
    int     m_iVideoWidth;      //Video width
    int     m_iVideoHeight;     //Video height
    int     m_iFrameRate;       //Frame rate
    int     m_iDisPos;          //Video display position
    int     m_iAudioOut;        //whether to output audio
}DecoderParam;

typedef struct
{
    unsigned long nWidth;    //Video width, audio data is 0；
    unsigned long nHeight;   //Video height, audio data is 0；
    unsigned long nStamp;    //Time stamp(ms)。
    unsigned long nType;     //Audio type，T_AUDIO8,T_YUV420，。
    unsigned long nFrameRate;//Frame rate。
    unsigned long nReserved; //reserve
}FRAME_INFO;

typedef struct __tagExtraInfo
{
	int		m_iInfoLen;
	void*	m_pvExtInfo;	
}FRAME_EXT_INFO, *LPFRAME_EXT_INFO;

// enum RAWFRAMETYPE
// {
//     VI_FRAME = 0,   //视频I帧
//     VP_FRAME = 1,   //视频P帧
//     AUDIO_FRAME = 5 //音频帧
// };
typedef int RAWFRAMETYPE;
#define VI_FRAME 0
#define VP_FRAME 1
#define AUDIO_FRAME 5


typedef struct
{
    unsigned int nWidth;    //Video width, audio data is 0
    unsigned int nHeight;   //Video height, audio data is 0
    unsigned int nStamp;    //Time stamp(ms)
    unsigned int nType;     //RAWFRAMETYPE, I Frame:0,P Frame:1,B Frame:2,Audio:5
    unsigned int nEnCoder;  //Audio or Video encoder(Video,0:H263,1:H264, 2:MP4. Audio,不压缩:0,G711_A:0x01,G711_U:0x02,ADPCM_A:0x03,G726:0x04)
    unsigned int nFrameRate;//Frame rate
    unsigned int nReserved; //reserve
}RAWFRAME_INFO;
   
//命令字的回调函数           
typedef void (*PROXY_NOTIFY)(int _ulLogonID,int _iCmdKey, char* _cData,  int _iLen,void* _iUser);

//网络接收的原始数据,不是完整的一帧数据，可用于代理转发
typedef void (*NVSDATA_NOTIFY)(unsigned int _ulID,unsigned char *_cData,int _iLen,void* _iUser);

#define STREAM_INFO_SYSHEAD     1  //系统头数据
#define STREAM_INFO_STREAMDATA  2  //视频流数据（包括复合流和音视频分开的视频流数据）
//完整的一帧数据,可用于写录像文件,或者送播放器器播放。要区分_ulStreamType的类型
typedef void (__stdcall *FULLFRAME_NOTIFY)(unsigned int _ulID,unsigned int _ulStreamType,unsigned char *_cData,int _iLen,void* _iUser);
typedef void (__stdcall *FULLFRAME_NOTIFY_V4)(unsigned int _ulID, unsigned int _ulStreamType, unsigned char *_cData, int _iLen, void* _iUser, void* _iUserData); //_iUser：文件头数据，_iUserData：用户数据
//未解码前的标准数据,纯h264数据
typedef void (__stdcall *RAWFRAME_NOTIFY)(unsigned int _ulID,unsigned char* _cData,int _iLen, RAWFRAME_INFO *_pRawFrameInfo, void* _iUser);

//下载数据，用于下载播放
typedef void (__stdcall *RECV_DOWNLOADDATA_NOTIFY)(unsigned int _ulID, unsigned char* _ucData,int _iLen, int _iFlag, void* _lpUserData);


//===========================================================================
//  storage  add 2007.6.13
//===========================================================================

#define MAX_DAYS            7
#define MAX_TIMESEGMENT     4
#define MAX_PAGE_SIZE       20
#define MAX_PAGE_LOG_SIZE	20
#define MAX_BITSET_COUNT    16  //支持512个联动

#define MAX_DH_TIMESEGMENT  8		//DH主机时间段

//Record type： 1-Manual record，2-Schedule record，3-Alarm record
// enum RECORD_TYPE
// {
//     RECORD_ALL=0xFF, RECORD_MANUAL=1, RECORD_TIME=2, RECORD_ALARM=3, RECORD_OTHER
// };
typedef int RECORD_TYPE;
#define RECORD_ALL 0xFF
#define RECORD_MANUAL 1
#define RECORD_TIME	  2
#define RECORD_ALARM  3
#define RECORD_OTHER  4

//Record state：
// enum RECORD_STATE
// {
//     REC_STOP=0, REC_MANUAL=1, REC_TIME=2, REC_ALARM=3
// };
 typedef int RECORD_STATE;
#define REC_STOP 0
#define REC_MANUAL 1
#define REC_TIME 2
#define REC_ALARM 3

//Audio encoder：
// enum AUDIO_ENCODER
// {
//     G711_A              = 0x01,  /* 64kbps G.711 A, see RFC3551.txt  4.5.14 PCMA */
//     G711_U              = 0x02,  /* 64kbps G.711 U, see RFC3551.txt  4.5.14 PCMU */
//     ADPCM_DVI4          = 0x03,  /* 32kbps ADPCM(DVI4) */
// 	G726_16KBPS         = 0x04,  /* 16kbps G.726, see RFC3551.txt  4.5.4 G726-16 */
//     G726_24KBPS         = 0x05,  /* 24kbps G.726, see RFC3551.txt  4.5.4 G726-24 */
//     G726_32KBPS         = 0x06,  /* 32kbps G.726, see RFC3551.txt  4.5.4 G726-32 */
//     G726_40KBPS         = 0x07,  /* 40kbps G.726, see RFC3551.txt  4.5.4 G726-40 */
//     MPEG_LAYER2         = 0x0E,  /* Mpeg layer 2*/
// 	AMR_NB				= 0x15,
//     ADPCM_IMA           = 0x23,  /* 32kbps ADPCM(IMA) */
//     MEDIA_G726_16KBPS   = 0x24,  /* G726 16kbps for ASF ... */
//     MEDIA_G726_24KBPS   = 0x25,  /* G726 24kbps for ASF ... */
//     MEDIA_G726_32KBPS   = 0x26,  /* G726 32kbps for ASF ... */
//     MEDIA_G726_40KBPS   = 0x27   /* G726 40kbps for ASF ... */
// };
typedef int AUDIO_ENCODER;
#define   G711_A              0x01  /* 64kbps G.711 A, see RFC3551.txt  4.5.14 PCMA */
#define   G711_U              0x02  /* 64kbps G.711 U, see RFC3551.txt  4.5.14 PCMU */
#define   ADPCM_DVI4          0x03  /* 32kbps ADPCM(DVI4) */
#define   G726_16KBPS         0x04  /* 16kbps G.726, see RFC3551.txt  4.5.4 G726-16 */
#define   G726_24KBPS         0x05  /* 24kbps G.726, see RFC3551.txt  4.5.4 G726-24 */
#define   G726_32KBPS         0x06  /* 32kbps G.726, see RFC3551.txt  4.5.4 G726-32 */
#define   G726_40KBPS         0x07  /* 40kbps G.726, see RFC3551.txt  4.5.4 G726-40 */
#define   MPEG_LAYER2         0x0E  /* Mpeg layer 2*/
#define   AMR_NB			  0x15
#define	  MPEG4_AAC			  0x16	/* MPEG-4 aac HEv2 ADTS*/
#define   ADPCM_IMA           0x23  /* 32kbps ADPCM(IMA) */
#define   MEDIA_G726_16KBPS   0x24  /* G726 16kbps for ASF ... */
#define   MEDIA_G726_24KBPS   0x25  /* G726 24kbps for ASF ... */
#define   MEDIA_G726_32KBPS   0x26  /* G726 32kbps for ASF ... */
#define   MEDIA_G726_40KBPS   0x27   /* G726 40kbps for ASF ... */

//Record time parameter
typedef struct
{
    unsigned short iYear;   /* Year */
    unsigned short iMonth;  /* Month */
    unsigned short iDay;    /* Day */
    unsigned short iHour;   /* Hour */
    unsigned short iMinute; /* Minute */
    unsigned short iSecond; /* Second */
} NVS_FILE_TIME,*PNVS_FILE_TIME;

//Record File Property
typedef struct
{
    int             iType;          /* Record type 1-Manual record, 2-Schedule record, 3-Alarm record*/
    int             iChannel;       /* Record channel 0~channel defined channel number*/
    char            cFileName[250]; /* File name */
    NVS_FILE_TIME   struStartTime;  /* File start time */
    NVS_FILE_TIME   struStoptime;   /* File end time */
    int             iFileSize;      /* File size */
}NVS_FILE_DATA,*PNVS_FILE_DATA;

typedef struct
{
	int				iSize;
	NVS_FILE_DATA	tFileData;		//文件基本信息
	int			    iLocked;		//加解锁状态
}NVS_FILE_DATA_EX,*PNVS_FILE_DATA_EX;

//Reserch parameter
typedef struct
{
    int             iType;          /* Record type 0xFF-All, 1-Manual record, 2-Schedule record, 3-Alarm record*/
    int             iChannel;       /* Record channel 0xFF-All, 0~channel-defined channel number*/
    NVS_FILE_TIME   struStartTime;  /* Start time of file */
    NVS_FILE_TIME   struStopTime;   /* End time of file */
    int             iPageSize;      /* Record number returned by each research*/
    int             iPageNo;        /* From which page to research */
    int             iFiletype;      /* File type, 0-All, 1-AVstream, 2-picture*/
    int             iDevType;       /* 设备类型，0-摄像 1-网络视频服务器 2-网络摄像机 0xff-全部*/
}NVS_FILE_QUERY, *PNVS_FILE_QUERY;

typedef struct  
{
	NVS_FILE_QUERY	fileQuery;
	char			cOtherQuery[65];
	int				iTriggerType;		//报警类型 3:端口报警,4:移动报警,5:视频丢失报警,0x7FFFFFFF:无效
	int				iTrigger;			//端口（通道）号
}NVS_FILE_QUERY_EX, *PNVS_FILE_QUERY_EX;

//Net storage device
typedef struct
{
    char cDeviceIP[16];
    char cStorePath[250];
    char cUsername[16];
    char cPassword[16];
    int  iState;
}NVS_NFS_DEV,*PNVS_NFS_DEV;

//Diskinfo
//disk manager
#define DISK_SATA_NUM		8
#define DISK_USB_NUM		4
#define	DISK_NFS_NUM		1
#define	DISK_ESATA_NUM		1
#define	DISK_SD_NUM			1
#define DISK_SATA_EX_NUM	8

#define DISK_VD_NUM			16
#define DISK_IPSAN_NUM		8

#define DNO_ESATA	32	// esata disk first no
#define DNO_SD		50	// SD disk first no

#define DISK_USB		8	  //USB类型磁盘 8~12
#define DISK_SATA_EX	1008  //SATA类型磁盘 1008~1015
#define	DISK_IPSAN		3000  //IPSAN类型 3000~3008
#define DISK_VD			2000  //虚拟磁盘盘号 2000~2015

// enum DISK_STATUSTYPE
// {
//     DISK_ZERO = 0,DISK_NOTFORMAT,DISK_FORMATED,DISK_CANUSE,DISK_READING
// };
typedef int DISK_STATUSTYPE;
#define DISK_ZERO 0
#define DISK_NOTFORMAT 1
#define DISK_FORMATED  2
#define DISK_CANUSE    3
#define DISK_READING   4

/*typedef struct
{
    int  iTotal;        //total size
    int  iFree;         //free size
    int  iReserved;     //reserved
}NVS_DISKINFO, *PNVS_DISKINFO;*/

typedef struct
{
    unsigned int  m_u32TotalSpace; // 总大小
    unsigned int  m_u32FreeSpace;  // 剩余空间
    unsigned short  m_u16PartNum;    // 分区数  1～4
    unsigned short  m_u16Status;     // 状态 0，无磁盘；1，未格式化；2，已格式化；3，已挂载；4，读写中
    unsigned short  m_u16Usage;      // 用途 0，录像；1，备份
    unsigned short  m_u16Reserve;    //	保留
}NVS_DISKINFO, *PNVS_DISKINFO;

//配额结构体
#define  CMD_DISK_QUOTA_MAX_USED  			1
#define  CMD_DISK_QUOTA_TOTAL				2
#define  CMD_DISK_QUOTA_CURRENT_USED		3
typedef struct
{
	int  iSize;												//结构体大小
	int  iRecordQuota; 										//录像配额（单位：GB）
	int  iPictureQuota;										//图片配额（单位：GB）
}DISK_QUOTA;

typedef struct
{
	int  iSize;												//结构体大小
	char cRecordQuota[65]; 										//已用录像配额（单位：GB）
	char cPictureQuota[65];										//已用图片配额（单位：GB）
}DISK_QUOTA_USED;
//盘组结构体
#define MAX_DISK_GROUP_NUM			8
typedef struct
{
	int		iSize;								//结构体大小 
	int		iGroupNO;							//盘组编号，0-7
	unsigned int	uiDiskNO[2];				//磁盘编号，按位表示，只能选择0-7//或者32，从小到大，对应bit位从低到高
	unsigned int	uiChannelNO[4];				//通道编号,按位表示，通道号从小到大，对应//bit位从低到高最大可设128通道
	unsigned int	uiDiskNoEx[4];				//新增磁盘编号
	unsigned int	uiChannelNOEx[12];			//通道编号,按位表示，通道号从小到大，对应//bit位从低到高最大可设512通道
}DISK_GROUP;

//单个权限信息结构体
#define MAX_MODIFY_AUTHORITY_NUM    26				//最大权限个数
typedef struct 
{
	int iLevel;									// 权限号
	unsigned int uiList[4];						//通道列表数组
}AUTHORITY_INFO;
//单个权限信息结构体扩展，支持大路数
typedef struct 
{
	int		iSize;
	char	cUserName[LEN_32];							//用户名
	int		iLevel;										//权限号
	unsigned int uiList[MAX_BITSET_COUNT];				//通道列表数组
}AUTHORITY_INFO_V1;
//用户权限结构体
typedef struct
{
	int iNeedSize;				//用户使用时，iNeedSize代表一次设置需要修改的权限数,最大不超过10
	AUTHORITY_INFO  strAutInfo[MAX_MODIFY_AUTHORITY_NUM];
}USER_AUTHORITY;

//用户权限组别结构体
#define MAX_AUTHORITY_GROUP_NUM		4	//权限组的种类数
typedef struct
{
	int iSize;												//结构体大小 
	int iGroupNO;											//权限组编号，1普通用户；2特权用户；
	//3超级用户；4管理员
	unsigned int uiList[2];									//该权限组所对应的权限号，按位表示，
	//权限编号从小到大，对应bit位从低到高
	char  cReserved[256];									//预留
}GROUP_AUTHORITY;

//Storage device info
/*typedef struct
{
    NVS_DISKINFO  usbDisk;  //usb disk information
    NVS_DISKINFO  nfsDisk;  //nfs disk information
    NVS_DISKINFO  ideDisk;  //ide disk information
}NVS_STORAGEDEV, *PNVS_STORAGEDEV;*/

typedef struct
{
    NVS_DISKINFO		m_strctSATA[DISK_SATA_NUM];
    NVS_DISKINFO		m_strctUSB[DISK_USB_NUM];
    NVS_DISKINFO		m_strctNFS[DISK_NFS_NUM];
    NVS_DISKINFO		m_strctESATA[DISK_ESATA_NUM];
    NVS_DISKINFO		m_strctSD[DISK_SD_NUM];
	NVS_DISKINFO		m_strctSATA_EX[DISK_SATA_EX_NUM];
	NVS_DISKINFO		m_tVD[DISK_VD_NUM];			//新增VD编号2000~2015
	NVS_DISKINFO		m_tIPSAN[DISK_IPSAN_NUM];	//新增IPSAN编号3000~3007
}NVS_STORAGEDEV, *PNVS_STORAGEDEV;

// enum SMTP_AUTHTYPE
// {
//     AUTH_OFF=0,AUTH_PLAIN,AUTH_CRAM_MD5,AUTH_DIGEST_MD5,AUTH_GSSAPI,AUTH_EXTERNAL,AUTH_LOGIN,AUTH_NTLM,SMTP_AUTHTYPE_LAST
// };
typedef int SMTP_AUTHTYPE;
#define AUTH_OFF			0
#define AUTH_PLAIN			1
#define AUTH_CRAM_MD5		2
#define AUTH_DIGEST_MD5 	3
#define AUTH_GSSAPI			4
#define AUTH_EXTERNAL		5
#define AUTH_LOGIN			6
#define AUTH_NTLM			7
#define SMTP_AUTHTYPE_LAST	8
// enum SCENE_TYPE
// {
//     AUTO=0, SCENE1,SCENE2,SCENE3,SCENE4,SCENE5,SCENE6,SCENE7,SCENE8,SCENE9,SCENE10,SCENE11,SCENE_TYPE_LAST
// };
typedef int SCENE_TYPE;
#define AUTO			0
#define SCENE1			1
#define SCENE2			2
#define SCENE3 			3
#define SCENE4			4
#define SCENE5			5
#define SCENE6			6
#define SCENE7			7
#define SCENE8			8
#define SCENE9			9
#define SCENE10			10
#define SCENE11			11
#define SCENE_TYPE_LAST	12

//SMTP alarm info
typedef struct
{
    char            cSmtpServer[32];    //smtp server
    unsigned short  wdSmtpPort;         //smtp server port
    char            cEmailAccount[32];  //mail account
    char            cEmailPassword[32];  //mail password
    int             iAuthtype;           //authtype
    char            cEmailAddress[32];  //mailbox address
    char            cMailSubject[32];   //mail subject
}SMTP_INFO,*PSMTP_INFO;
//add SMTP alarm info by gjf
typedef struct SMTP_INFOEX
{
	SMTP_INFO	smtpInfo;
	char		cMailAddr[3][32];		//	另外3个地址
	int			iScrityType;			//	0-retain，1-not scrity，2-SSL，3-TLS
}*PSMTP_INFOEX;
//add end 
//---------------------------------------------------------------------------

typedef struct
{
    char cESSID[33];            //ESSID
    char cEncryption[16];       //wifi encrypttion flag; 0 no encryption，1 digital encryption
}WIFI_INFO, *PWIFI_INFO;

typedef struct
{
    char    m_cDDNSUserName[32];
    char    m_cDDNSPwd[32];
    char    m_cDDNSNvsName[32];
    char    m_cDDNSDomain[32];
    int     m_iDDNSPort;
    int     m_iDDNSEnable;
}DDNS_INFO, *PDDNS_INFO;

typedef struct
{
    char    cESSID[33];         //ESSID
    char    cWifiSvrIP[16];     //wifiIP
    char    cWifiMask[16];          //wifi mask
    char    cWifiGateway[16];       //wifi gateway
    char    cWifiDNS[16];           //wifi DNS
    char    cWifiKeyType[16];       //wifi KeyType：Hex；ASCII
    char    cWifiPassword[128];     //wifi password, @yys@, 32->128, 2010-07-05
    char    cEncryption[16];        //wifi encrypttion flag; NULL no encryption，"WEP" encryption
    char    cWifiKeyNum[2];         //wifi KeyNum (1,2,3,4)
    int     iPwdFormat;
    int     iHaveCard;
    int     iCardOnline;
}NVS_WIFI_PARAM, *PNVS_WIFI_PARAM;

//兼容IE
//wifiap
//typedef struct
//{
//	char	cESSID[64];			    //ESSID!
//	char	cWifiSvrIP[16];		    //wifiapIP
//	char	cWifiMask[16];			//wifiap mask
//	char	cWifiGateway[16];		//wifiap gateway
//	char	cWifiDNS[16];			//wifiap DNS
//	char	cWifiKeyType[16];		//wifiap KeyType：Hex；ASCII
//	char	cWifiPassword[128];		//wifiap password,
//	char	cEncryption[16];		//wifiap encrypttion flag; NULL no encryption，"WEP" encryption
//	char	cWifiKeyNum[2];         //wifiap KeyNum (1,2,3,4)
//	int		iPwdFormat;
//	int		iHaveCard;
//	int		iCardOnline;
//}NVS_WIFIAP_PARAM, *PNVS_WIFIAP_PARAM;

//兼容SDK4.0和3.3
typedef struct NVS_IPAndID
{
    char *m_pIP;
    char *m_pID;
	union
	{
		unsigned int *m_puiLogonID;
		int  *m_piLogonID;
	};
}*pNVS_IPAndID;

typedef struct			//定制的通用信息
{
	char    m_cParam1[64];
	char    m_cParam2[64];
	char    m_cParam3[64];
	char    m_cParam4[64];
	char    m_cParam5[64];
	char    m_cParam6[64];
	char    m_cParam7[64];
	char    m_cParam8[64];
	char    m_cParam9[64];
	char    m_cParam10[64];
	char    m_cParam11[64];
	char    m_cParam12[64];
	char    m_cParam13[64];
	char    m_cParam14[64];
	char    m_cParam15[64];
	char    m_cParam16[64];
	char    m_cParam17[64];
	char    m_cParam18[64];
	char    m_cParam19[64];
	char    m_cParam20[64];
}DZ_INFO_PARAM, *PDZ_INFO_PARAM;


#define MAX_PARAM_NUM 32

typedef struct STRCT_ParamPackage
{
	char			m_strParam[MAX_PARAM_NUM][256];
	int				m_iParam[MAX_PARAM_NUM];
	void*           m_lpVoid[MAX_PARAM_NUM];
	
}*pSTRCT_ParamPackage;
//--------------------------------------------------------

#ifndef HIWORD
#define HIWORD(l)   ((unsigned short) (((unsigned int) (l) >> 16) & 0xFFFF))
#endif

#ifndef LOWORD
#define LOWORD(l)   ((unsigned short) (l))
#endif


#define SERVER_NORMAL  0
#define SERVER_ACTIVE  1
#define SERVER_DNS		2

#define DATA_RECEIVE_NOT  0      //没有接收
#define DATA_RECEIVE_WAIT 1      //等待接收
#define DATA_RECEIVE_HEAD 2      //已经收到视频头，但是还没有收到数据								 
#define DATA_RECEIVE_ING  3      //正在接收ing
#define DATA_RECEIVE_DIGITALCHANNEL_FAILED  4      //数字通道未连接

#define INFO_USER_PARA     0
#define INFO_CHANNEL_PARA  1
#define INFO_ALARM_PARA    2
#define INFO_VIDEO_HEAD    3
#define INFO_LOGON_PARA    4
#define INFO_FINISH_PARA   5

typedef void (*CMDSTRING_NOTIFY)(char *_cBuf,int _iLen,void* _pUserData); 
  
#define PROTOCOL_COUNT			64				//	最多支持的协议个数
#define PROTOCOL_NAME_LENGTH	32				//	单个协议名称的最大长度
#define MAX_PROTOCOL_TYPE		3
typedef struct
{
	int     iType;							   //整数， 0代表设备支持的协议, 1代表正在使用的协议
	int		iCount;					           //服务器支持的协议类型数
	char 	cProtocol[PROTOCOL_COUNT][PROTOCOL_NAME_LENGTH];		//各协议名称，最多支持个协议，每条协议名称最长字节；
} st_NVSProtocol;  

#ifdef WIN32
typedef struct
{
	char m_cIP[32];
	char m_cDeviceID[64];
	int  m_iLogonID;
	int  m_iChannel;
	int  m_iStreamNO;
	int  m_iDrawIndex;
}st_ConnectInfo,*pst_ConnectInfo;
#else
typedef struct
{
	char m_cIP[32];
	char m_cDeviceID[64];
	int  m_iLogonID;
	int  m_iChannel;
	int  m_iStreamNO;
	int  m_iDrawIndex;
	char m_cDownLoadFile[256];
}st_ConnectInfo,*pst_ConnectInfo;
#endif


#define CLIENT_DEFAULT 0       //连接代理的默认客户端
#define CLIENT_DECODER 1       //对解码器特殊处理

//#define MAX_DATA_CHAN MAX_CHANNEL_NUM		//包含副码流
#define MAX_FILE_CHAN 5

#define DATA_CMD  1
#define DATA_DATA 2
typedef void (*INNER_DATA_NOTIFY)(unsigned int _ulID,void *_pBlock,int _iType,void* _iUser);

#define REC_FILE_TYPE_STOP      (-1)
#define REC_FILE_TYPE_NORMAL	0
#define REC_FILE_TYPE_AVI		1
#define REC_FILE_TYPE_ASF		2
#define REC_FILE_TYPE_AUDIO     3
#define REC_FILE_TYPE_RAWAAC    4
#define REC_FILE_TYPE_VIDEO     5


typedef struct					//  2010-1-26-18:09 @yys@
{
	int			iChannelNo;		//	通道号
	int			iLogType;		//	日志类型
	int			iLanguage;		//	语言类型
	NVS_FILE_TIME	struStartTime;		//	开始时间
	NVS_FILE_TIME	struStopTime;		//	结束时间
	int			iPageSize;		//	页大小
	int			iPageNo;		//	页编号
}NVS_LOG_QUERY, *PNVS_LOG_QUERY;

typedef struct  
{
	int				iChannel;
	int				iLogType;
	NVS_FILE_TIME	struStartTime; 	/* File start time */
	NVS_FILE_TIME	struStoptime; 	/* File end time */
	char			szLogContent[129];					
}NVS_LOG_DATA,*PNVS_LOG_DATA;

#define DOWNLOAD_TYPE_NOTHING		0
#define DOWNLOAD_TYPE_ERROR			1
#define DOWNLOAD_TYPE_PIC			2
#define DOWNLOAD_TYPE_VIDEO			3
#define DOWNLOAD_TYPE_TIMESPAN		4

typedef struct  
{
	int iPreset[32]	;				//预置位号 取值范围：1-255	
	int	iStayTime[32];				//停留时间 取值范围：1-60	
	int	iSpeed[32];					//速度	   取值范围：0-100	
}st_PTZCruise,*Pst_PTZCruise;

/************************************************************************
*  CD-Burn 相关设置                                                                    
************************************************************************/
#define		CDBURN_CMD_SET_MIN					0
#define		CDBURN_CMD_SET_START				(CDBURN_CMD_SET_MIN+0)				//	开始刻录
#define		CDBURN_CMD_SET_STOP					(CDBURN_CMD_SET_MIN+1)				//	停止刻录
#define		CDBURN_CMD_SET_MODE					(CDBURN_CMD_SET_MIN+2)				//	设置刻录模式
#define		CDBURN_CMD_SET_RESUME				(CDBURN_CMD_SET_MIN+3)				//	继续刻录
#define		CDBURN_CMD_SET_MAX					(CDBURN_CMD_SET_MIN+4)

//#define		CDBURN_CMD_GET_MIN					(CDBURN_CMD_SET_MAX)			//	考虑下面的扩展兼容性
#define		CDBURN_CMD_GET_MIN					(3)									//	Get命令下限
#define		CDBURN_CMD_GET_MODE					(CDBURN_CMD_GET_MIN+0)				//	得到刻录模式
#define		CDBURN_CMD_GET_CDROMLIST			(CDBURN_CMD_GET_MIN+1)				//	得到当前光驱列表
#define		CDBURN_CMD_GET_CDROMCOUNT			(CDBURN_CMD_GET_MIN+2)				//	得到当前光驱的个数
#define		CDBURN_CMD_GET_STATUS				(CDBURN_CMD_GET_MIN+3)				//	得到当前刻录状态
#define		CDBURN_CMD_GET_MAX					(CDBURN_CMD_GET_MIN+4)

#define		CDBURN_MAX_COUNT				32			//	最多允许的光驱数

#define		CDBURN_STATUS_FREE				0		//	光盘未使用
#define		CDBURN_STATUS_BUSY				1		//	正在刻录
#define		CDBURN_STATUS_BAD				2		//	光盘已损坏
#define		CDBURN_STATUS_FULL				3		//	光盘已经满
#define		CDBURN_STATUS_PACK				4		//	光盘正在打包
#define     CDBURN_STATUS_BEGINFAILED       102     //  开始刻录失败 

#define		MAX_DVDNAME_LEN					31

struct TCDBurnStatus
{
	int				iCDRomID;					//	光驱ID
	int				iState;						//	当前状态
	unsigned long	ulTotal;					//	总大小
	unsigned long	ulFree;						//	空余大小
	union
	{
		char			cReserved[4];				//	预留4个字节
		int			iReserved;
	};	
};

//Burn file mode:0-original mode,1-single file mode
#define BURN_FILE_ORIGINAL_MODE			0
#define BURN_FILE_SINGLE_FILE_MODE		1

struct TCDBurnPolicy
{
	int				iCDRomID;								//	CD Rom ID,only use single burn

	int				iMode;									//	0-single burn, 1-mutil burn, 2-circle burn
	int				iChannelBits[CDBURN_MAX_COUNT];			//	channel list,bits
	int				iDeviceBits[CDBURN_MAX_COUNT];			//	device list,bits
	//Expand 20121025
	int				iDiskType;								//	disk type
	int				iBurnSpeed;								//	burn speed
	int				iBurnHour;								//	burn time
	int				iResSpace;								//	reserve space
	char			cDVDName[MAX_DVDNAME_LEN+1];			//	DVD name 
	//Expand 20150427
	int				iBurnFileMode;							//Burn file mode:0-original mode,1-single file mode
};

struct TCBurnStopMode
{
	int             iDeviceNum;                            //光驱编号
	int             iFlagByBits;                            //bit0: 1不弹盘，0弹盘；bit1：1不封盘， 0封盘
};       

/************************************************************************
*	视频加密 Video Encrypt & Decrypt                                                                      
************************************************************************/
struct TVideoEncrypt
{
	int			iChannel;					//	加密通道, -1：表示所有通道
	int			iType;						//	加密类型, -- 0，不加密；1，AES；其他待扩展
	int			iMode;						//	加密算法或方法，目前用不到
	char		cPassword[17];				//	加密密码
};

struct TVideoDecrypt
{
	int			iChannel;							//	解密通道
	char		cDecryptKey[17];					//	解密密钥
};

/************************************************************************
   Digital Channel Param  20110303                                                                   
************************************************************************/
#define DC_CMD_GET_MIN				0
#define DC_CMD_GET_ALL				(DC_CMD_GET_MIN+0)
#define DC_CMD_GET_IPCPnP			(DC_CMD_GET_MIN+2)
#define DC_CMD_GET_MAX				(DC_CMD_GET_MIN+3)

#define DC_CMD_SET_MIN				(0)
#define DC_CMD_SET_ALL				(DC_CMD_SET_MIN+1)
#define DC_CMD_SET_IPCPnP			(DC_CMD_SET_MIN+2)
#define DC_CMD_SET_MAX				(DC_CMD_SET_MIN+3)
/************************************************************************
   数字通道即插即用工作模式
***********************************************************************/
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN         0
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_OFF        (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 0)//关闭
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_AUTO_ADD   (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 1)//自动添加
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_AUTO_FIND  (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 2)//自动发现(提示用户手动添加)
#define DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MAX        (DIGITAL_CHANNEL_PLUGANDPLAY_WORKMODE_MIN + 0)

//  [12/15/2012]
#define	MAX_RTSPURL_LEN				(127)
#define MAX_RTSPURL_LEN_EX			(63)

//	协议类型
#define SERVERTYPE_PRIVATE			(0)
#define SERVERTYPE_ONVIF			(1)
#define SERVERTYPE_PUSH				(2)
#define SERVERTYPE_RTSP				(3)

struct TDigitalChannelParam
{
	int iChannel;							//	[数字通道号]--取值范围据设备类型而定，登录时会向客户端发送数字通道数
	int	iEnable;							//	[使能]--0，禁用该数字通道；1，启用该数字通道，默认为启用
	int iConnectMode;						//	[连接方式]--0，IP；1，域名；2，主动模式，默认为IP
	int	iDevChannel;						//	[前端设备通道号]--取值范围已前端设备能力而定，默认为0
	int iDevPort;							//	[前端设备端口号]--81～65535，默认为3000
	int iStreamType;						//	[码流类型]--0，主码流；1，副码流，默认为主码流
	int iNetMode;							//	[网络类型]--1，TCP；2，UDP；3，组播，暂定为TCP,不可更改
	int iPtzAddr;							//	[PTZ地址]--0～256，为空则使用默认值

	char cIP[33];							//	[连接参数]--iConnectMode=0时，IP地址；iConnectMode=1时，域名；iConnectMode=2时，设备ID，默认为空，至多32个字符
	char cProxyIP[33];						//	[代理IP]--iConnectMode=2时，该字段无效，默认为空，至多32个字符
	char cPtzProtocolName[33];				//	[PTZ协议]--登录设备时会向客户端发送设备支持的PTZ协议列表，为空则使用默认值，至多32个字符
	char cUserName[17];						//	[用户名]--登录前端设备的用户名，不可为空，至多16个字符
	char cPassword[17];						//	[密码]--登录前端设备的密码，不可为空，至多16个字符
	char cEncryptKey[17];					//	[视频加密密码]--前端设备视频加密的密码，为空则表示不加密，至多16个字符
	int iServerType;						//  前端设备所采用的网络协议(Miracle新增字段)
											//  0:私有协议
											//  1:Onvif协议；
											//  2:Push流
											//	3:RTSP
	union
	{
		struct{
			char cRTSPUrl[MAX_RTSPURL_LEN+1];		//	RTSP url
			char cIPv6[LENGTH_IPV6_V1];				//	IPv6 地址
		};
		char cRTSPUrlEx[4*MAX_RTSPURL_LEN_EX+4];
	};
	
	char cMucIp[LEN_64];	//muticast IP address
	int  iMucPort;			//muticast port
};

/************************************************************************
*	得到设备通道的属性参数                                                                     
************************************************************************/
#define		CHANNEL_TYPE_LOCAL			0			//	本地模拟通道
#define		CHANNEL_TYPE_DIGITAL		2			//	数字通道
#define		CHANNEL_TYPE_COMBINE		3			//	合成通道

#define		CHANNEL_TYPE_MAINSTREAM		0			//	主码流
#define     CHANNEL_TYPE_SUBSTREAM      1           //	副码流
#define		CHANNEL_TYPE_THIRDSTREAM	4			//	三码流

#define GENERAL_CMD_MIN						0
#define GENERAL_CMD_GET_CHANNEL_TYPE		(GENERAL_CMD_MIN+1)			//	得到此设备的某个通道的属性(旧)
#define GENERAL_CMD_CHANNEL_TYPE			(GENERAL_CMD_MIN+1)			//	得到此设备的某个通道的属性(新)
#define GENERAL_CMD_CHANTYPE_LIST			(GENERAL_CMD_MIN+2)			//	得到此设备的各通道可编辑的类型
#define GENERAL_CMD_ALARM_IN_CHANNEL_TYPE   (GENERAL_CMD_MIN+3)	//	得到此设备的各报警输入通道类型
#define GENERAL_CMD_MAX						(GENERAL_CMD_MIN+4)

/************************************************************************
* VCA 相关数据结构，供上层软件使用,下面的CMDID使用enum最好(sizeof(enum))，
	但考虑到CB与VC的兼容性问题，统一使用#define实现
************************************************************************/
#define VCA_MAX_RULE_NUM				8				//	每个通道所允许的最多规则数
#define VCA_MAX_EVENT_NUM				14				//	最多的事件个数
#define VCA_MAX_TRIPWIRE_NUM			8				//	最多的单绊线个数
#define VCA_MAX_DBTRIPWIRE_NUM			4				//	最多的双绊线个数
														//
#define VCA_MAX_OSC_REGION_NUM			3				//	最大物品丢失区域个数

#define VCA_MAX_RULE_NAME_LEN			17				//	规则名称的长度

typedef int vca_EEventType;

#define VCA_EVENT_MIN							0						//	事件ID的下限 "[0,9)"
#define VCA_EVENT_TRIPWIRE						(VCA_EVENT_MIN+0)		//	绊线事件
#define VCA_EVENT_DBTRIPWIRE					(VCA_EVENT_MIN+1)		//	双绊线事件
#define VCA_EVENT_PERIMETER						(VCA_EVENT_MIN+2)		//	周界事件
#define VCA_EVENT_LOITER						(VCA_EVENT_MIN+3)		//	徘徊事件
#define VCA_EVENT_PARKING						(VCA_EVENT_MIN+4)		//	停车事件
#define VCA_EVENT_RUN							(VCA_EVENT_MIN+5)		//	奔跑事件
#define VCA_EVENT_HIGH_DENSITY					(VCA_EVENT_MIN+6)		//	人员密度事件
#define VCA_EVENT_ABANDUM						(VCA_EVENT_MIN+7)		//	遗弃物事件
#define VCA_EVENT_OBJSTOLEN						(VCA_EVENT_MIN+8)		//	被盗物事件
#define VCA_EVENT_FACEREC						(VCA_EVENT_MIN+9)		//	人脸识别事件
#define	VCA_EVENT_VIDEODETECT					(VCA_EVENT_MIN+10)		//	视频诊断事件
#define	VCA_EVENT_TRACK							(VCA_EVENT_MIN+11)		//	跟踪事件
#define	VCA_EVENT_FLUXSTATISTIC					(VCA_EVENT_MIN+12)		//	流量统计事件
#define	VCA_EVENT_CROWD						    (VCA_EVENT_MIN+13)		//	人群聚集事件
#define	VCA_EVENT_LEAVE_DETECT					(VCA_EVENT_MIN+14)		//	离岗检测事件
#define	VCA_EVENT_WATER_LEVEL_DETECT			(VCA_EVENT_MIN+15)		//	水位检测事件
#define	VCA_EVENT_AUDIO_DIAGNOSE				(VCA_EVENT_MIN+16)		//	Audio Diagnose
#define VCA_EVENT_FACE_MOSAIC					(VCA_EVENT_MIN+17)		//  Face Mosaic
#define VCA_EVENT_RIVERCLEAN					(VCA_EVENT_MIN+18)		//  河道检测
#define VCA_EVENT_DREDGE						(VCA_EVENT_MIN+19)		//  盗采盗卸
#define VCA_EVENT_ILLEAGEPARK					(VCA_EVENT_MIN+20)		//	违章停车
#define	VCA_EVENT_MAX							(VCA_EVENT_MIN+21)		//	无效事件ID，最大上限


#define VCA_CMD_SET_MIN							1									//	VCA设置命令下限
#define VCA_CMD_SET_CHANNEL						(VCA_CMD_SET_MIN+ 0)				//	设置VCA通道号及使能
#define VCA_CMD_SET_VIDEOSIZE					(VCA_CMD_SET_MIN+ 1)				//	设置VCA通道的视频大小
#define VCA_CMD_SET_ADVANCE_PARAM				(VCA_CMD_SET_MIN+ 2)				//	设置VCA高级参数
#define VCA_CMD_SET_TARGET_PARAM				(VCA_CMD_SET_MIN+ 3)				//	设置VCA叠加参数和颜色设置
#define VCA_CMD_SET_ALARM_STATISTIC				(VCA_CMD_SET_MIN+ 4)				//	设置VCA报警计数为零
#define VCA_CMD_SET_RULE_COMMON					(VCA_CMD_SET_MIN+ 5)				//	设置VCA规则常规参数
#define VCA_CMD_SET_RULE0_TRIPWIRE				(VCA_CMD_SET_MIN+ 6)				//	设置VCA规则（单绊线）
#define VCA_CMD_SET_RULE1_DBTRIPWIRE			(VCA_CMD_SET_MIN+ 7)				//	设置VCA规则（双绊线）
#define VCA_CMD_SET_RULE2_PERIMETER				(VCA_CMD_SET_MIN+ 8)				//	设置VCA规则（周界）
#define VCA_CMD_SET_ALARM_SCHEDULE				(VCA_CMD_SET_MIN+ 9)				//	设置VCA报警模板
#define VCA_CMD_SET_ALARM_LINK					(VCA_CMD_SET_MIN+10)				//	设置VCA联动输出端口
#define VCA_CMD_SET_SCHEDULE_ENABLE				(VCA_CMD_SET_MIN+11)				//	设置VCA布防使能
#define VCA_CMD_SET_RULE9_FACEREC				(VCA_CMD_SET_MIN+12)				//	设置VCA规则（人脸识别）
#define VCA_CMD_SET_RULE10_VIDEODETECT			(VCA_CMD_SET_MIN+13)				//	设置VCA规则（视频诊断）
#define VCA_CMD_SET_RULE8_ABANDUM		        (VCA_CMD_SET_MIN+14)				//	设置VCA规则（遗弃物）
#define VCA_CMD_SET_RULE7_OBJSTOLEN             (VCA_CMD_SET_MIN+15)                //  设置VCA规则（被盗物）
#define VCA_CMD_SET_RULE11_TRACK	            (VCA_CMD_SET_MIN+16)                //  设置VCA规则（跟踪）
#define	VCA_CMD_CALL_TRACK_NO					(VCA_CMD_SET_MIN+17)				//  调用起始跟踪位
#define VCA_CMD_SET_RULE12_FLUXSTATISTIC	    (VCA_CMD_SET_MIN+18)				//	设置VCA规则（流量统计)
#define VCA_CMD_SET_RULE13_CROWD				(VCA_CMD_SET_MIN+19)				//	设置VCA规则（人群聚集)
#define VCA_CMD_SET_CHANNEL_ENABLE				(VCA_CMD_SET_MIN+20)				//	设置VCA通道使能(0:不启用智能分析 1:启用本地通道智能分析 2:启用前端通道智能分析)
#define VCA_CMD_SET_RULE14_LEAVE_DETECT			(VCA_CMD_SET_MIN+21)				//	设置VCA规则（离岗检测)
#define VCA_CMD_SET_RULE15_WATER_LEVEL			(VCA_CMD_SET_MIN+22)				//	设置VCA规则（水位检测)
#define VCA_CMD_SET_MAX							(VCA_CMD_SET_MIN+23)				//	VCA设置命令上限


#define VCA_CMD_GET_MIN							(16)								//	VCA读取命令下限,为了兼容VIDEODETECT之前的宏
#define VCA_CMD_GET_CHANNEL						(VCA_CMD_GET_MIN+ 0)				//	读取VCA通道号及使能
#define VCA_CMD_GET_VIDEOSIZE					(VCA_CMD_GET_MIN+ 1)				//	读取VCA通道的视频大小
#define VCA_CMD_GET_ADVANCE_PARAM				(VCA_CMD_GET_MIN+ 2)				//	读取VCA高级参数
#define VCA_CMD_GET_TARGET_PARAM				(VCA_CMD_GET_MIN+ 3)				//	读取VCA叠加参数和颜色设置
#define VCA_CMD_GET_ALARM_STATISTIC				(VCA_CMD_GET_MIN+ 4)				//	读取VCA报警计数
#define VCA_CMD_GET_RULE_COMMON					(VCA_CMD_GET_MIN+ 5)				//	读取VCA规则常规参数
#define VCA_CMD_GET_RULE0_TRIPWIRE				(VCA_CMD_GET_MIN+ 6)				//	读取VCA规则（单绊线）
#define VCA_CMD_GET_RULE1_DBTRIPWIRE			(VCA_CMD_GET_MIN+ 7)				//	读取VCA规则（双绊线）
#define VCA_CMD_GET_RULE2_PERIMETER				(VCA_CMD_GET_MIN+ 8)				//	读取VCA规则（周界）
#define VCA_CMD_GET_ALARM_LINK					(VCA_CMD_GET_MIN+ 9)				//	读取VCA联动输出端口
#define VCA_CMD_GET_ALARM_SCHEDULE				(VCA_CMD_GET_MIN+10)				//	读取VCA报警模板
#define VCA_CMD_GET_SCHEDULE_ENABLE				(VCA_CMD_GET_MIN+11)				//	读取VCA布防使能
#define VCA_CMD_GET_RULE9_FACEREC				(VCA_CMD_GET_MIN+12)				//	读取VCA规则（人脸识别）
#define VCA_CMD_GET_RULE10_VIDEODETECT			(VCA_CMD_GET_MIN+13)				//	读取VCA规则（视频诊断）
#define VCA_CMD_GET_RULE8_ABANDUM			    (VCA_CMD_GET_MIN+14)				//	设置VCA规则（遗弃物）
#define VCA_CMD_GET_RULE7_OBJSTOLEN             (VCA_CMD_GET_MIN+15)				//  设置VCA规则（被盗物）
#define VCA_CMD_GET_RULE11_TRACK	            (VCA_CMD_GET_MIN+16)                //  设置VCA规则（跟踪）
#define VCA_CMD_GET_RULE12_FLUXSTATISTIC	    (VCA_CMD_GET_MIN+18)				//	设置VCA规则（流量统计)
#define VCA_CMD_GET_RULE13_CROWD				(VCA_CMD_GET_MIN+19)				//	设置VCA规则（人群聚集)
#define VCA_CMD_GET_CHANNEL_ENABLE				(VCA_CMD_GET_MIN+20)				//	读取VCA通道使能(0:不启用智能分析 1:启用本地通道智能分析 2:启用前端通道智能分析)
#define VCA_CMD_GET_STATISTIC_INFO				(VCA_CMD_GET_MIN+21)				//  读取VCA通道人流量统计数据
#define VCA_CMD_GET_RULE14_LEAVE_DETECT			(VCA_CMD_GET_MIN+22)				//  读取VCA规则（离岗检测）
#define VCA_CMD_GET_RULE15_WATER_LEVEL			(VCA_CMD_GET_MIN+23)				//	设置VCA规则（水位检测)
#define VCA_CMD_GET_VCALIST						(VCA_CMD_GET_MIN+24)				//	Get VCA Type List
#define VCA_CMD_GET_MAX							(VCA_CMD_GET_MIN+25)				//	VCA读取命令的上限

#define VCA_CMD_FACEMOSAIC						(75)	//FACEMOSAIC
#define VCA_CMD_MIN 100
#define VCA_CMD_TARGET_PARAM					(VCA_CMD_MIN + 0)					//设置VCA叠加参数和颜色设置
#define VCA_CMD_ADVANCE_PARAM					(VCA_CMD_MIN + 1)					//设置VCA高级参数
#define VCA_CMD_RULE_PARAM						(VCA_CMD_MIN + 2)					//设置VCA规则常规参数
#define VCA_CMD_ALARM_STATISTIC					(VCA_CMD_MIN + 3)					//设置VCA报警计数为零
#define VCA_CMD_TRIPWIRE						(VCA_CMD_MIN + 4)					//设置VCA规则（单绊线）
#define VCA_CMD_PERIMETER						(VCA_CMD_MIN + 5)					//设置VCA规则（周界）
#define VCA_CMD_LINGER							(VCA_CMD_MIN + 6)					//设置VCA规则（徘徊）
#define VCA_CMD_PARKING							(VCA_CMD_MIN + 7)					//设置VCA规则（停车）
#define VCA_CMD_RUNNING							(VCA_CMD_MIN + 8)					//设置VCA规则（奔跑）
#define VCA_CMD_CROWD							(VCA_CMD_MIN + 9)					//设置VCA规则（人群聚集）
#define VCA_CMD_DERELICT						(VCA_CMD_MIN + 10)					//设置VCA规则（遗弃物）
#define VCA_CMD_STOLEN							(VCA_CMD_MIN + 11)					//设置VCA规则（被盗物）
#define VCA_CMD_MULITTRIP						(VCA_CMD_MIN + 12)					//设置VCA规则（双绊线）
#define VCA_CMD_VIDEODIAGNOSE					(VCA_CMD_MIN + 13)					// set VCA rule (video diagnose for 300W)
#define VCA_CMD_AUDIODIAGNOSE					(VCA_CMD_MIN + 14)					// set VCA rule (audio diagnose for 300W)
#define VCA_CMD_TRIPWIRE_EX						(VCA_CMD_MIN + 15)					// set VCA rule (Tripwire for 300W)
#define VCA_CMD_RULE14_LEAVE_DETECT				(VCA_CMD_MIN + 16)					// set VCA rule (leave detect for 300w)
#define VCA_CMD_CHANNEL_ENABLE                  (VCA_CMD_MIN + 17)                  //通道使能
#define VCA_CMD_FACEREC							(VCA_CMD_MIN + 18)                  //设置VCA规则（人脸识别）
#define VCA_CMD_TRACK							(VCA_CMD_MIN + 19)                  //设置VCA规则（轨迹）
#define VCA_CMD_VIDEODETECTION                  (VCA_CMD_MIN + 20)                  //设置VCA规则（视频诊断）
#define VCA_CMD_VIDEOSIZE						(VCA_CMD_MIN + 21)                  //设置智能分析视频输入大小
#define VCA_CMD_RIVERCLEAN						(VCA_CMD_MIN + 22)					//设置VCA规则（河道检测）
#define VCA_CMD_DREDGE							(VCA_CMD_MIN + 23)					//设置VCA规则（盗采盗卸）
#define VCA_CMD_RIVERADV						(VCA_CMD_MIN + 24)					//设置VCA河道检测高级参数
#define VCA_CMD_MAX								(VCA_CMD_MIN + 25)                  //最多

#define VCA_ALARMLINK_MIN                        0
#define VCA_ALARMLINK_AUDIO	                    (VCA_ALARMLINK_MIN)                 //联动声音提示
#define VCA_ARARMLINK_SCREEMSHOW                (VCA_ALARMLINK_MIN + 1)             //联动屏幕显示
#define VCA_ALARMLINK_OUTPORT                   (VCA_ALARMLINK_MIN + 2)             //联动输出端口
#define VCA_ALARMLINK_RECODER                   (VCA_ALARMLINK_MIN + 3)             //联动录像
#define VCA_ALARMLINK_PTZ                       (VCA_ALARMLINK_MIN + 4)             //联动PTZ
#define VCA_ALARMLINK_CAPTUREPIC                (VCA_ALARMLINK_MIN + 5)             //联动抓拍
#define VCA_ALARMLINK_SINGLEPIC					(VCA_ALARMLINK_MIN + 6)				//联动单画面
#define VCA_ALARMLINK_WHITELIGHT				(VCA_ALARMLINK_MIN + 7)				//White Light
#define VCA_ALARMLINK_MAX                       (VCA_ALARMLINK_MIN + 8)

#define VCA_ALARMTYPE_MIN                       0         
#define VCA_ALARMTYPE_VIDEOLOST                 (VCA_ALARMTYPE_MIN)                 //视频丢失
#define VCA_ALARMTYPE_PORT                      (VCA_ALARMTYPE_MIN + 1)				//端口
#define VCA_ALARMTYPE_MOVE						(VCA_ALARMTYPE_MIN + 2)				//移动侦测
#define VCA_ALARMTYPE_COVER						(VCA_ALARMTYPE_MIN + 3)				//视频遮挡
#define VCA_ALARMTYPE_VCA						(VCA_ALARMTYPE_MIN + 4)				//智能分析
#define VCA_ALARMTYPE_MAX						(VCA_ALARMTYPE_MIN + 5)

#define VCA_LINKPTZ_TYPE_MIN                    0
#define VCA_LINKPTZ_TYPE_NOLINK                 (VCA_LINKPTZ_TYPE_MIN )          //不联动
#define VCA_LINKPTZ_TYPE_PRESET                 (VCA_LINKPTZ_TYPE_MIN + 1)		 //预置位
#define VCA_LINKPTZ_TYPE_TRACK                  (VCA_LINKPTZ_TYPE_MIN + 2)		 //轨迹
#define VCA_LINKPTZ_TYPE_PATH                   (VCA_LINKPTZ_TYPE_MIN + 3)		 //路径
#define VCA_LINKPTZ_TYPE_MAX                    (VCA_LINKPTZ_TYPE_MIN + 4)

/************************************************************************/
/* 智能分析视频诊断类型                                                 */
/************************************************************************/
#define	VCA_AVD_NOISE 				(1<<0)   	//	噪声诊断
#define VCA_AVD_CLARITY				(1<<1)		//	清晰度诊断
#define VCA_AVD_BRIGHT_ABMNL		(1<<2)		//	亮度异常诊断
#define VCA_ADV_COLOR				(1<<3)		//	偏色诊断
#define VCA_ADV_FREEZE				(1<<4)		//	画面冻结诊断
#define VCA_ADV_NOSIGNAL			(1<<5)		//	信号丢失诊断
#define VCA_ADV_CHANGE				(1<<6)		//	场景变换诊断
#define VCA_ADV_INTERFERE			(1<<7)		//	人为干扰诊断
#define VCA_ADV_PTZ_LOST_CTL		(1<<8)		//	PTZ失控诊断

/************************************************************************/
/* 智能分析音频诊断类型                                                 */
/************************************************************************/
#define VCA_AUDIO_MIN                0
#define	VCA_AUDIO_DROP 				(1<<(VCA_AUDIO_MIN))	//	Voice Drop
#define VCA_AUDIO_UNNORMAL			(1<<(VCA_AUDIO_MIN + 1))//	Voice Unnormal
#define VCA_AUDIO_NOISE				(1<<(VCA_AUDIO_MIN + 2))//	Noise Restrain
#define VCA_AUDIO_ECHO				(1<<(VCA_AUDIO_MIN + 3))//	Echo Restrain
#define VCA_AUDIO_SIGNAL			(1<<(VCA_AUDIO_MIN + 4))//	Signal Unnormal
#define VCA_AUDIO_MAX               VCA_AUDIO_MIN + 5

//联动
#define	MAX_BITSET_NUM		4
#define	MAX_ALARM_LINKTYPE  6

// typedef enum __tagLinkPTZType
// {
// 	LINKPTZ_TYPE_MIN = 0,
// 	LINKPTZ_TYPE_NOLINK = LINKPTZ_TYPE_MIN,			//不联动
// 	LINKPTZ_TYPE_PRESET,						//预置位
// 	LINKPTZ_TYPE_TRACK,							//轨迹
// 	LINKPTZ_TYPE_PATH							//路径
// }ELinkPTZType, *PELinkPTZType;	
typedef int ELinkPTZType;
typedef int __tagLinkPTZType;
typedef int * PELinkPTZType ;
#define LINKPTZ_TYPE_MIN	0
#define LINKPTZ_TYPE_NOLINK LINKPTZ_TYPE_MIN
#define LINKPTZ_TYPE_PRESET 1
#define LINKPTZ_TYPE_TRACK  2
#define LINKPTZ_TYPE_PATH	3

//时间段
typedef struct __tagAlarmScheduleParam
{
	int				iBuffSize;

	int				iWeekday;								//	星期日到星期六（0-6）
	int				iParam1;
	int				iParam2;
	NVS_SCHEDTIME	timeSeg[MAX_DAYS][MAX_TIMESEGMENT];		//	时间段

	void*			pvReserved;									
	int				iSceneID;//场景编号(0~15) 20140305扩展
}TAlarmScheduleParam, *PTAlarmScheduleParam;

//报警模板使能
typedef struct __tagAlarmScheEnableParam
{
	int				iBuffSize;

	int				iEnable;						//	报警模板使能
	int				iParam1;						//	取值由iAlarmType而定
	int				iParam2;						//	取值由iAlarmType而定
	int				iParam3;						//	保留

	void*			pvReserved;									
	int				iSceneID;//场景编号(0~15) 20140305扩展
}TAlarmScheEnableParam, *PTAlarmScheEnableParam;


struct vca_TPoint
{
	int iX;
	int	iY;
} ;					//	sizeof = 2*4 = 8

struct vca_TLine
{
	vca_TPoint 	stStart;
	vca_TPoint 	stEnd;
} ;						//	sizeof = 2*8 = 16

struct vca_TPolygon
{
	int 		iPointNum;
	vca_TPoint 	stPoints[VCA_MAX_POLYGON_POINT_NUM];   
} ;						//	sizeof = 16*8+4 = 260 

struct vca_TPolygonEx
{
	int 		iPointNum;
	vca_TPoint 	stPoints[VCA_MAX_POLYGON_POINT_NUMEX];   
} ;						//	sizeof = 32*8+4 = 260

struct vca_TDisplayParam
{
	int				iDisplayRule;			//	是否显示规则，比如绊线，周界线	
	int				iDisplayStat;			//	是否显示报警计数
	int				iColor;					//	正常时的颜色
	int				iAlarmColor;			//	报警时的颜色
};	
				
struct vca_TAlarmTimeSegment
{
	int		iStartHour;					
	int		iStartMinute;
	int		iStopHour;
	int		iStopMinute;
	int		iEnable;
};				//	报警时间段

struct vca_TAlarmSchedule
{
	int						iWeekday;					//	星期日到星期六（0-6）
	vca_TAlarmTimeSegment	timeSeg[7][4];				//	时间段
};			//	报警布防模板

struct vca_TLinkPTZ
{
	unsigned short	usType;								//	0不联动该通道，1预置位，2轨迹，3路径
	unsigned short	usPresetNO;							//	预置位号
	unsigned short	usTrackNO;							//	轨迹号
	unsigned short	usPathNO;							//	路径号
};

//	报警联动
struct vca_TAlarmLink
{
	int						iLinkType;					//	0，联动声音提示；1，联动屏幕显示；2，联动输出端口；3，联动录像；4，联动PTZ；5，联动抓拍
	int						iLinkChannel;
	
	int						iLinkSet[6];				//	0,1,2,3,5
	vca_TLinkPTZ			ptz[MAX_CHANNEL_NUM];		//	4
};					

struct vca_TScheduleEnable
{
	int						iEnable;					//	是否使能	
	int						iParam;						//	参数，保留
};

// 单绊线参数
struct vca_TTripwire
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	int					iTargetTypeCheck;		//	目标类型限制
	int					iMinDistance;			//	最小距离,目标运动距离必须大于此阈值
	int					iMinTime;				//	最短时间,目标运动距离必须大于此阈值	
	int					iType;					//	表示穿越类型
	int					iDirection;				//	单绊线禁止方向角度
	vca_TLine			stLine;					//	绊线坐标
}; 

struct vca_TPerimeter
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	int					iTargetTypeCheck;		//	区分人车
	int					iMode;					//	监测模式
	int 				iMinDistance;			//	最小距离
	int 				iMinTime;				//	最短时间		
	int					iType;					//	是否做方向限制
	int 				iDirection;				//	禁止方向角度(单位: 角度)
	vca_TPolygon		stRegion;				//	区域范围	
} ;		// 周界参数

struct vca_TFaceRec
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	vca_TPolygon		stRegion;				//	区域范围
};		//人脸识别参数

struct vca_TVideoDetection
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	int					m_iCheckTime;
};

struct vca_tOSC
{
	int                 iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
	int                 iColor;					//区域颜色
	int					iAlarmColor;			//报警时区域颜色
	int					iMinTime;				//遗弃物在区域存在的最短时间
	int 				iMinSize;				//最小像素尺寸
	int 				iMaxSize;				//最大像素尺寸
	int 				iSunRegionCount;		//子多边形个数
	vca_TPolygon 		stMainRegion;			//主多边形区域
	vca_TPolygon 		stSubRegion[VCA_MAX_OSC_REGION_NUM];	//子多边形区域
};

typedef	struct vca_tTrack
{
	int					m_iStartPreset;			//起始跟踪点
	vca_TPolygon		m_TrackRegion;			//跟踪区域
	int					m_iScene;				//场景大/中/小
	int					m_iWeekDay;				//星期
	NVS_SCHEDTIME		m_timeSeg[MAX_DAYS][MAX_TIMESEGMENT];		//跟踪时间段
}vca_tTrack, *LPvca_tTrack;

typedef	struct vca_tFluxStatistic
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	vca_TPolygon		stRegion;				//	区域范围	
}vca_tFluxStatistic, *LPvca_tFluxStatistic;

typedef	struct vca_tCrowd
{
	int					iValid;					//	是否有效,本来由规则中的iEventID判断哪个事件有效即可，
												//	但如果所有规则都不生效时iEventID总会指向一个事件，上层无法判断是否真的有效，只能加一个事件有效字段
	vca_TPolygon		stRegion;				//	区域范围	
}vca_tCrowd, *LPvca_tCrowd;

#define  MAX_RULE_REGION_NUM	4
typedef struct vca_tLeaveDetect
{
	int					iValid;					//	此事件检测是否有效,0：无效 1：有效
	int					iLeaveAlarmTime;		//	离岗报警时间,60~3600,单位：秒 ,默认值：120S
	int					iRuturnClearAlarmTime;	//	回岗消警时间,10~300,单位：秒   默认值：15S
	int					iAreaNum;				//	规则区域总数,1～4
	vca_TPolygon		stRegion[MAX_RULE_REGION_NUM];			//	区域范围	
}vca_tLeaveDetect, *LPvca_tLeaveDetect;

//（水位检测）RULEEVENT15
#define MAX_REFERPOINT_NUM   10
typedef struct tagWaterRange //水位范围
{
	int iStart;	//开始范围
	int iEnd;    //结束范围
}WaterRange;

typedef struct tagReferPoint //水位参考
{
	int iPointX;	//横坐标
	int iPointY;    //纵坐标
	int iValue;		//标尺上的读数
}ReferPoint;

typedef struct tagWaterPresetInfo
{
	int                 iSize;
	int					iPresetId;					//	预置位ID
	WaterRange			stGaugeRange;				//	水位范围 iStart:iEnd
	RECT				rcGaugeRect;				//	水尺区域对角线坐标
	RECT				rcAssistRect;				//  辅助区域对角线坐标
	RECT				rcGaugeLine;				//	水尺参考线坐标
	int					iReferNum;					//  参考点个数
	ReferPoint			stReferPoint[MAX_REFERPOINT_NUM]; //  参考点1、2, 3
}WaterPresetInfo;

#define	EVENT_BUF_RESERVED		2048			//预留大小
#define MAX_WATER_SAMPLE_POINT 4
typedef union vca_UEventParam
{	
	char cBuf[EVENT_BUF_RESERVED];							//	联合体预留空间改为2048
	vca_TTripwire		tripwire;
	vca_TPerimeter		perimeter;
	vca_TFaceRec		m_stFaceRec;
	vca_TVideoDetection	m_stVideoDetection;
	vca_tOSC            m_stOSC;
	vca_tTrack			m_stTrack;
	vca_tFluxStatistic  m_stFluxStatic;
	vca_tCrowd          m_stCrowd;
	vca_tLeaveDetect	m_stLeaveDetect;
}vca_UEventParam, *LPvca_UEventParam;
	
// 规则设置参数
struct vca_TRuleParam
{
	char 				cRuleName[VCA_MAX_RULE_NAME_LEN];	// 规则名字
	int					iValid;								// 该规则是否生效

	vca_TDisplayParam	stDisplayParam;						//	显示时的参数设定

	int					iAlarmCount;						//	报警次数
	vca_TAlarmSchedule	alarmSchedule;						//	报警布防模板参数
	vca_TAlarmLink		alarmLink;							//	报警联动设置参数
	vca_TScheduleEnable	scheduleEnable;						//	布防使能

	vca_EEventType		iEventID;							// 行为分析事件类型 
	vca_UEventParam		events;								// 行为分析事件参数
};	

// 智能分析配置参数
struct vca_TConfig
{
	int		iVideoSize;						// 视频大小
	int		iDisplayTarget;					// 是否叠加目标框
	int		iDisplayTrace;					// 是否叠加轨迹
	int		iTargetColor;					// 目标框颜色
	int		iTargetAlarmColor;				// 报警时目标框颜色
	int		iTraceLength;					// 轨迹长度
};	  

// 智能分析高级参数
struct vca_TAdvParam
{
	int		iEnable; 					//是否启用高级参数
	int		iTargetMinSize; 			//目标最小像素数
	int		iTargetMaxSize; 			//目标最大像素数
	int   	iTargetMinWidth;  			//最大宽度
	int		iTargetMaxWidth;  			//最小宽度
	int		iTargetMinHeight;  			//最大高度
	int		iTargetMaxHeight;  			//最小高度
	int     iTargetMinSpeed;			//目标最小像素速度(-1为不做限制)
	int     iTargetMaxSpeed;			//目标最大像素速度(-1为不做限制)
	int 	iTargetMinWHRatio;			//最小长宽比
	int 	iTargetMaxWHRatio;			//最大长宽比
	int		iSensitivity;				//灵敏度级别
};	

struct TStatisticInfo
{
	int					iSize;								//结构体大小
	int					iFluxIn;							//进入人数
	int					iFluxOut;							//离开人数
};

//智能分析通道参数
struct vca_TVCAChannelParam
{
	int					iEnable;					//	是否使能此通道智能分析
	vca_TConfig			config;  					//	智能分析配置参数    	
	vca_TAdvParam		advParam;					//	智能分析高级参数

	int					iRuleID;
	vca_TRuleParam	rule[VCA_MAX_RULE_NUM]; 		//	规则设置参数	
};

//	VCA配置的参数总集, 
struct vca_TVCAParam
{
	int						iEnable;								//	是否使能智能分析
	int						iChannelBit;							//	智能分析通道的Bit集

	int						iChannelID;								//	VCA通道
	vca_TVCAChannelParam	chnParam[MAX_CHANNEL_NUM];				//	每个通道的参数设置
};					

struct vca_TAlarmInfo
{
	int				iID;				//	报警消息ID，用于获取具体的信息
	int				iChannel;			//	通道号
	int				iState;				//	报警状态
	int				iEventType;			//	事件类型  0：单绊线 1：双绊线 2：周界检测 3：徘徊 4：停车 5：奔跑 
													//6：区域内人员密度 7：被盗物 8：遗弃物 9：人脸识别 10:视频诊断 
													//11:智能跟踪 12：流量统计 13：人群聚集  14：离岗检测 15：音频诊断
	int				iRuleID;			//	规则ID

	unsigned int	uiTargetID;			//	目标ID
	int				iTargetType;		//	目标类型
	RECT			rctTarget;			//	目标位置
	int				iTargetSpeed;		//	目标速度
	int				iTargetDirection;	//	目标方向
	int             iPresetNo;    //  预置位ID
	unsigned int	iWaterLevelNUm;		//  水面标尺读数
	char			cWaterPicName[LEN_64];//  保存图片路径 
	int             iPicType;             // 0:关键 1：普通
	int             iDataType;            // 0:实时 1：脱机
};

/************************************************************************
* FTP 定时更新相关                                                                     
************************************************************************/

//	FTP相关协议
#define FTP_CMD_SET_MIN				0
#define FTP_CMD_SET_SNAPSHOT		(FTP_CMD_SET_MIN+0)
#define FTP_CMD_SET_LINKSEND		(FTP_CMD_SET_MIN+1)
#define FTP_CMD_SET_TIMEDSEND		(FTP_CMD_SET_MIN+2)
#define FTP_CMD_SET_UPDATE			(FTP_CMD_SET_MIN+3)
#define FTP_CMD_SET_MAX				(FTP_CMD_SET_MIN+4)

//#define FTP_CMD_GET_MIN				(FTP_CMD_SET_MAX)		//	考虑下面的扩展兼容性
#define FTP_CMD_GET_MIN				(4)
#define FTP_CMD_GET_SNAPSHOT		(FTP_CMD_GET_MIN+0)
#define FTP_CMD_GET_LINKSEND		(FTP_CMD_GET_MIN+1)
#define FTP_CMD_GET_TIMEDSEND		(FTP_CMD_GET_MIN+2)
#define FTP_CMD_GET_UPDATE			(FTP_CMD_GET_MIN+3)
#define FTP_CMD_GET_MAX				(FTP_CMD_GET_MIN+4)

#define FTP_COMMON_CMD_MIN			(FTP_CMD_GET_MAX)
#define FTP_COMMON_CMD_SNAPSHOT_EX	(FTP_COMMON_CMD_MIN + 0)
#define FTP_COMMON_CMD_MAX			(FTP_COMMON_CMD_MIN + 1)

struct FTP_SNAPSHOT
{
	int		iChannel;			//	通道 
	int		iEnable;			//	使能
	int		iQValue;			//	质量
	int		iInterval;			//	时间间隔
	int		iPictureSize;       //  抓拍图片大小	0x7fff：代表自动，其余对应分辨率大小
	int		iPicCount;			//  抓拍图片数量
};

typedef struct tagFtpSnapshot
{
	int		iSize;
	int		iChannelNo;			//	channel number 
	int		iType;			
	int		iQValue;			//	quality[0-100]
	char	cInterval[LEN_16];	//	capture time interval [0,3600]
	int		iPictureSize;       //  capture picture size	0x7fff：automatic
	int		iPicCount;			//  capture picture number
}FtpSnapshot, *pFtpSnapshot;

struct FTP_LINKSEND
{
	int		iChannel;			//	通道
	int		iEnable;			//	使能
	int		iMethod;			//	方式
};

struct FTP_TIMEDSEND	
{
	int		iChannel;			//	通道
	int		iEnable;			//	使能
	int		iFileType;			//	文件类型
	int		iHour;				//	时间(hour)
	int		iMinute;			//	时间(Minute)
	int		iSecond;			//	秒数(Second)
};

struct FTP_UPDATE
{
	char	cFtpAddr[32];		//	升级使用的Ftp地址
	char	cFileName[32];		//	升级使用的文件名
	char	cUserName[16];		//	升级使用的用户名
	char	cPassword[16];		//	升级使用的密码
	int		iPort;				//	端口
	int		iUsage;				//	标志位用途
};

/************************************************************************
* 3G DVR 相关设置
************************************************************************/
#define		DVR3G_CMD_SET_MIN					0
#define		DVR3G_CMD_SET_POWERDELAY			(DVR3G_CMD_SET_MIN+0)				//	延时开关机
#define		DVR3G_CMD_SET_SIMNUM				(DVR3G_CMD_SET_MIN+1)				//	SIM卡号
#define		DVR3G_CMD_SET_GPSOVERLAY			(DVR3G_CMD_SET_MIN+2)				//	GPS信息
#define		DVR3G_CMD_SET_GPSFILTER				(DVR3G_CMD_SET_MIN+3)				//	GPS过滤
#define		DVR3G_CMD_SET_FTPUPLOAD_MODE		(DVR3G_CMD_SET_MIN+4)				//	Ftp自动上传的方式
#define		DVR3G_CMD_SET_VPDN					(DVR3G_CMD_GET_MIN+5)				//	VPDN
#define		DVR3G_CMD_SET_MAX					(DVR3G_CMD_SET_MIN+6)

//#define		DVR3G_CMD_GET_MIN					(DVR3G_CMD_SET_MAX)					//	考虑下面的扩展兼容性
#define		DVR3G_CMD_GET_MIN					(5)									//  Get命令下限
#define		DVR3G_CMD_GET_POWERDELAY			(DVR3G_CMD_GET_MIN+0)				//	延时开关机
#define		DVR3G_CMD_GET_SIMNUM				(DVR3G_CMD_GET_MIN+1)				//	SIM卡号
#define		DVR3G_CMD_GET_GPSOVERLAY			(DVR3G_CMD_GET_MIN+2)				//	GPS信息
#define		DVR3G_CMD_GET_GPSFILTER				(DVR3G_CMD_GET_MIN+3)				//	GPS过滤
#define		DVR3G_CMD_GET_FTPUPLOAD_MODE		(DVR3G_CMD_GET_MIN+4)				//	Ftp自动上传的方式
#define		DVR3G_CMD_GET_VPDN					(DVR3G_CMD_GET_MIN+5)				//	VPDN
#define		DVR3G_CMD_GET_MAX					(DVR3G_CMD_GET_MIN+6)

struct TDVR3GInfo
{
	int		iPowerDelayOnTime;						//	延时开机的时间，秒数，范围0~999秒， 0表示延时开机不使能。
	int		iPowerDelayOffTime;						//	延时关机的时间，秒数， 范围0~999秒，0表示延时关机不使能。	
	int		iGpsOverlay[MAX_CHANNEL_NUM];			//	使能叠加GPS信息，与通道相关
	int		iGpsFilter;								//	bitset, 0-不转发, 65535-所有. GPGGA-bit 1，GPRMC-bit 2，GPVTG-bit 3，GPGLL-bit 4，GPGSA- bit 5, GPGSV-bit 6，其它位暂时保留。
	char	cSimNum[33];							//	SIM卡号，长度最长为32位。
};

struct TDVR3GInfoEx
{
	TDVR3GInfo	dvr3GInfo;
	int			iFtpUploadMode;					//	上传方式
	char		cReserved[64];					//	预留字段
};

#define DVR3G_VPDN_MAX_LEN 32

struct TDVR3GVPDN
{
	int iSize;
	char cDialNumber[DVR3G_VPDN_MAX_LEN];	//接入号码
	char cAccount[DVR3G_VPDN_MAX_LEN];		//账号
	char cPassword[DVR3G_VPDN_MAX_LEN];		//密码
};

/************************************************************************
* 多画面合成                                                                     
************************************************************************/
struct TVideoCombine 
{
	int     iPicNum;     		// 合成画面数
	int		iRec;  				// 合成位置
	char	cChannelID[300];   	// 合成通道信息
};

#define MAX_VIDEO_COMBINE_NUM		2      //视频合成每段最大数目
#define MAX_VIDEO_COMBINE_BLOCK     4	   //视频合成最大分段数
#define MAX_VO_NUM					3	   //Max Video Output Num
#define MAX_VC_NUM					2 	   //Max Video Combine Num
typedef struct tagVideoCombine 
{
	int		iSize;				// the size of Struct
	int     iPicNum;     		// combine picture number
	int		iRec;  				// combine location
	char	cChannelID[300];   	// combine information
	int		iVoDevId;			// input device number, 0-reserved，1-VGA/HDMI0, 17-HDMI1, 33-CVBS 49-VC, default is VC
}VideoCombine, *pVideoCombine;


typedef struct tagRectEx
{
	int 			iX;
	int				iY;					// coordinates
	int				iWidth;
	int				iHeight;			// width and height
}RectEx, *pRectEx;

typedef struct tagPicParam
{
	int				ChnNo;				// Channel No
	tagRectEx		RectParam;
}PicParam, *pPicParam;

#define  MAX_VIEW_NUM				128		//Max View Number

//Create Free
typedef struct tagVoViewSegment
{
	int				iSize;				// the size of Struct
	int    	 		iVoDevId;     		// output Device ID
	int				iPicCnt;  		    // Picture Count= iPicCnt/1000 - 1
	tagPicParam		tPicPar[MAX_VIEW_NUM];
}VoViewSegment,*pVoViewSegment;

//VC Affinal
typedef struct tagVcAffinal 
{
	int				iSize;				// the size of Struct
	int             iVcId;	            // vcid
	int    	 		iVoDevId;     		// output Device ID
}VcAffinal,*pVcAffinal;

//Preview Mode  
typedef struct tagPreviewMode  
{
	int				iSize;				// the size of Struct
	int				iType;  			// Video Input Type
}PreviewMode, *pPreviewMode;

/************************************************************************
* 混音                                                                     
************************************************************************/
#define MAX_MIX_NUM 300
typedef struct __tagAudioMix
{	
	int		iEnable;					//混音使能
	int		iChannel;					//音频合成通道的通道号
	char	cMixChannels[MAX_MIX_NUM];	//音源组合
	void*	pvReserved;					//保留参数,同时也是为了与TVideoCombine的大小区分
}TAudioMix,	*PTAudioMix;


/************************************************************************
* SIP协议相关                                                                     
************************************************************************/
#define SIP_CMD_GET_MIN						0
#define SIP_CMD_GET_ALARMCHANNEL			(SIP_CMD_GET_MIN+0)
#define SIP_CMD_GET_VIDEOCHANNEL			(SIP_CMD_GET_MIN+1)
#define SIP_CMD_GET_MAX						(SIP_CMD_GET_MIN+2)

//#define SIP_CMD_SET_MIN						(SIP_CMD_GET_MAX)		//	考虑下面的扩展兼容性
#define SIP_CMD_SET_MIN						(2)
#define SIP_CMD_SET_ALARMCHANNEL			(SIP_CMD_SET_MIN+0)
#define SIP_CMD_SET_VIDEOCHANNEL			(SIP_CMD_SET_MIN+1)
#define SIP_CMD_SET_MAX						(SIP_CMD_SET_MIN+2)

struct TSipVideoChannel
{
	int		iChannelNo;
	char	cChannelID[33];
	int		iLevel;
	int		iPtzTime;
};

struct TSipAlarmChannel
{
	int		iChannelNo;
	char	cChannelID[33];
	int		iLevel;
};

#define CHARSET_LENGTH          32              //  表示字符集字符串长度
#define LANGUAGE_COUNT			255				//	最多支持的语言个数
#define LANGUAGE_NAME_LENGTH	32				//	单个语言名称的最大长度
typedef struct
{
	int    iCount;
	char   cLanguage[LANGUAGE_COUNT][LANGUAGE_NAME_LENGTH];
} st_NVSLanguageList;

typedef struct
{
	unsigned long nWidth;
	unsigned long nHeight;
	unsigned long nStamp;
	unsigned long nType;
	unsigned long nFrameRate;
	unsigned long nReserved;
}PSPACK_INFO;

//2012-04-22
/************************************************************************
* 新增数据回调结构体相关                                                                     
************************************************************************/
#define 	DTYPE_MIN			0
#define 	DTYPE_H264_MP		(DTYPE_MIN + 0)
#define     DTYPE_RAW_AUDIO		(DTYPE_MIN + 1)
#define 	DTYPE_PS			(DTYPE_MIN + 2)
#define 	DTYPE_MAX			(DTYPE_MIN + 2)

typedef void (*RAWH264_MP_NOTIFY)(unsigned int _ulID, unsigned char* _cData, 
								  int _iLen, RAWFRAME_INFO *_pRawFrameInfo, void* _iUser);

typedef void (*RAW_AUDIO_NOTIFY)(unsigned int _ulID, unsigned char* _cData, int _iLen, int Type, void* _pvUserData);
//PS流回调与纯音频回调一样
typedef RAW_AUDIO_NOTIFY	PS_STREAM_NOTIFY;

//PS流封装的回调函数 
typedef void (*PSPACK_NOTIFY)(unsigned long _ulID, unsigned char* _ucData, int _iSize, PSPACK_INFO* _pPsPackInfo, void* _pContext);

/************************************************************************/
/*                   不兼容回调                                         */
/************************************************************************/

//报警消息回调
typedef void (*ALARM_NOTIFY_V4)(int _ulLogonID, int _iChan, int _iAlarmState,ALARMTYPE _iAlarmType,void* _iUser);

//设备参数改变回调   
typedef void (*PARACHANGE_NOTIFY_V4)(int _ulLogonID, int _iChan, PARATYPE _iParaType,STR_Para* _strPara,void* _iUser);

//主回调函数,负责通知设备上下线、视频数据等相关消息，_iWparam参照WCM_LOGON_NOTIFY等消息定义
typedef void (*MAIN_NOTIFY_V4)(int _ulLogonID,int _iWparam, int _iLParam,void* _iUser); 

//串口收数回调
typedef void (*COMRECV_NOTIFY_V4)(int _ulLogonID, char *_cData, int _iLen,int _iComNo,void* _iUser); 

//解码后的音视频数据
typedef void (*DECYUV_NOTIFY_V4)(unsigned int _ulID,unsigned char *_cData, int _iLen, const FRAME_INFO *_pFrameInfo, void* _iUser);

#ifndef WIN32
#define HDC int
#endif

typedef int (*CBK_DRAW_FUNC)(long _lHandle,HDC _hDc,long _lUserData);


#define UPGRADE_PROGRAM			1		//	程序升级
#define UPGRADE_WEB				2		//	网页升级

typedef void (*UPGRADE_NOTIFY_V4)(int _iLogonID, int _iServerState, void* _iUserData);


typedef void (__stdcall *RECVDATA_NOTIFY)(unsigned long _ulID,unsigned char* _ucData,int _iLen);		//	不建议使用此回调函数
typedef void (__stdcall *RECVDATA_NOTIFY_EX)(unsigned long _ulID, unsigned char* _ucData,int _iLen, int _iFlag, void* _lpUserData);

#ifdef WIN32
typedef void (__stdcall *LOGON_NOTIFY)(int _iLogonID, int _iLogonState);
typedef void (__stdcall *ALARM_NOTIFY)(int _iLogonID, int _iCh, void* _vContext,ALARMTYPE _iAlarmType);
typedef void (__stdcall *PARACHANGE_NOTIFY)(int _iLogonID, int _iCh, PARATYPE _iParaType,LPVOID _strPara);
typedef void (__stdcall *MAIN_NOTIFY)(int _iLogonID,int _iWParam,int _iLParam, void* _lpNoitfyUserData);
typedef void (__stdcall *ALARM_NOTIFY_EX)(int _iLogonID, int _iChannel, void* _vContext,ALARMTYPE _iAlarmType, void* _lpNoitfyUserData);
typedef void (__stdcall *PARACHANGE_NOTIFY_EX)(int _iLogonID, int _iChannel, PARATYPE _iParaType,LPVOID _strPara, void* _lpNoitfyUserData);
typedef void (__stdcall *COMRECV_NOTIFY)(int _iLogonID, char *_buf, int _length,int _iComNo);
typedef void (__stdcall *DECYUV_NOTIFY)(unsigned long _ulID, unsigned char* _ucData, int _iSize, FRAME_INFO *_pFrameInfo, void* _pContext);
//升级内核程序
typedef void (__stdcall *PROUPGRADE_NOTIFY)(int _iLogonID,int _iServerState);
//升级网页
typedef void (__stdcall *WEBUPGRADE_NOTIFY)(int _iLogonID,int _iServerState);    
#else
typedef void (*ALARM_NOTIFY)(int _ulLogonID, int _iChan, int _iAlarmState,ALARMTYPE _iAlarmType,void* _iUser);
typedef void (*PARACHANGE_NOTIFY)(int _ulLogonID, int _iChan, PARATYPE _iParaType,STR_Para* _strPara,void* _iUser);
typedef void (*MAIN_NOTIFY)(int _ulLogonID,int _iWparam, int _iLParam,void* _iUser); 
typedef void (*COMRECV_NOTIFY)(int _ulLogonID, char *_cData, int _iLen,int _iComNo,void* _iUser);
typedef void (*DECYUV_NOTIFY)(unsigned int _ulID,unsigned char *_cData, int _iLen, const FRAME_INFO *_pFrameInfo, void* _iUser);
//升级内核程序
typedef void (*PROUPGRADE_NOTIFY)(int _iLogonID,int _iServerState,void* _iUser);
//升级网页
typedef void (*WEBUPGRADE_NOTIFY)(int _iLogonID,int _iServerState,void* _iUser);    
#endif

//通道相关存储策略
#define STORAGE_CMD_MIN 0
#define STORAGE_CMD_STORAGE_RULE STORAGE_CMD_MIN+0
#define STORAGE_CMD_MAX STORAGE_CMD_MIN+1

#define STORAGE_RULE_MIN 0
#define STORAGE_RULE_RECORD_AUDIO STORAGE_RULE_MIN+0
#define STORAGE_RULE_STORAGE_TIME STORAGE_RULE_MIN+1
#define STORAGE_RULE_EXTRACT_FRAME STORAGE_RULE_MIN+2
#define STORAGE_RULE_REDUNDANCE_RECORD STORAGE_RULE_MIN+3
#define STORAGE_RULE_SUB_RECORD STORAGE_RULE_MIN+4
#define STORAGE_RULE_SUB_STORAGE_TIME STORAGE_RULE_MIN+5
#define STORAGE_RULE_MAX STORAGE_RULE_MIN+6
typedef struct STORAGE_RULE
{
	int			iSize;		//Size of the structure,must be initialized before used
	int			iType;		//参数类型 0:是否记录音频 1:过期时间(单位:天) 2:是否开启抽帧功能 3：是否开启冗余录像
	int			iValue;		//参数值 iType = 0，2，3时，0:不记录或不开启 1:记录或开启;
							//iType = 1时，范围为[0,60]。0表示不强制执行过期操作，磁盘满后覆盖。
}*PSTORAGE_RULE;


//************************************************************************/
//*							网卡参数
//************************************************************************/
#define MAX_LAN_NUM						2
#define MAX_WIFICARD_NUM				2

#define LAN_CMD_SET_MIN					0
#define LAN_CMD_SET_IPV4				(LAN_CMD_SET_MIN+0)
#define LAN_CMD_SET_IPV6				(LAN_CMD_SET_MIN+1)
#define LAN_CMD_SET_WORKMODE			(LAN_CMD_SET_MIN+2)
//#define LAN_CMD_SET_LANNUM			(LAN_CMD_SET_MIN+3)
#define LAN_CMD_SET_DHCP				(LAN_CMD_SET_MIN+4)
#define LAN_CMD_SET_WIFIDHCPMODE		(LAN_CMD_SET_MIN+5)
#define LAN_CMD_SET_WIFIWORKMODE		(LAN_CMD_SET_MIN+6)
#define LAN_CMD_SET_WIFIAPDHCPPARA		(LAN_CMD_SET_MIN+7)
#define LAN_CMD_SET_WIFIAPPARA			(LAN_CMD_SET_MIN+8)
#define LAN_CMD_SET_WIFIPARA			(LAN_CMD_SET_MIN+9)
#define LAN_CMD_SET_MAX					(LAN_CMD_SET_MIN+10)

#define LAN_CMD_GET_MIN					0
#define LAN_CMD_GET_IPV4				(LAN_CMD_GET_MIN+0)
#define LAN_CMD_GET_IPV6				(LAN_CMD_GET_MIN+1)
#define LAN_CMD_GET_WORKMODE			(LAN_CMD_GET_MIN+2)
#define LAN_CMD_GET_LANNUM				(LAN_CMD_GET_MIN+3)
#define LAN_CMD_GET_DHCP				(LAN_CMD_GET_MIN+4)
#define LAN_CMD_GET_WIFIDHCPMODE		(LAN_CMD_GET_MIN+5)
#define LAN_CMD_GET_WIFIWORKMODE		(LAN_CMD_GET_MIN+6)
#define LAN_CMD_GET_WIFIAPDHCPPARA		(LAN_CMD_GET_MIN+7)
#define LAN_CMD_GET_WIFIAPPARA			(LAN_CMD_GET_MIN+8)
#define LAN_CMD_GET_WIFIPARA			(LAN_CMD_GET_MIN+9)
#define LAN_CMD_GET_MAX					(LAN_CMD_GET_MIN+10)

typedef struct LANPARAM_IPV4 
{
	int iSize;						//sizeof(LANPARAM_IPV4)
	int iLanNo;						//网卡编号 0:Lan1 1:Lan2	
	int iLanType;					//网卡类型 预留，填0即可。
	//默认10M/100M/1000M自适应，不可更改。
	char cIP[LENGTH_IPV4];			//IPV4 IP地址			
	char cMask[LENGTH_IPV4];		//IPV4 子网掩码
	char cGateway[LENGTH_IPV4];		//IPV4 默认网关
	char cDNS[LENGTH_IPV4];			//IPV4 首选DNS服务器
	char cBackDNS[LENGTH_IPV4];		//IPV4 备用DNS服务器
	char cReserved[64];				//预留，填0即可。
	//用于以后其他网络属性的扩展，比如MTU					
} *PLANPARAM_IPV4;

typedef struct LANPARAM_IPV6 
{
	int iSize;						//sizeof(LANPARAM_IPV6)
	int iLanNo;						//网卡编号 0:Lan1 1:Lan2	
	int iPrefixLen;					//IPV6 子网前缀长度
	char cIP[LENGTH_IPV6];			//IPV6 IP地址	
	char cGateway[LENGTH_IPV6];		//IPV6 默认网关
	char cDNS[LENGTH_IPV6];			//IPV6 首选DNS服务器
	char cBackDNS[LENGTH_IPV6];		//IPV6 备用DNS服务器
	char cReserved[LEN_64];				//预留，填0即可。
	//如有IPV6相关的基本属性可以通过该字段实现。					
} *PLANPARAM_IPV6;

typedef struct LANPARAM_IPV6_V1 
{
	int iSize;						//sizeof(LANPARAM_IPV6)
	int iLanNo;						//网卡编号 0:Lan1 1:Lan2	
	int iPrefixLen;					//IPV6 子网前缀长度
	char cIP[LENGTH_IPV6_V1];			//IPV6 IP地址	
	char cGateway[LENGTH_IPV6_V1];		//IPV6 默认网关
	char cDNS[LENGTH_IPV6_V1];			//IPV6 首选DNS服务器
	char cBackDNS[LENGTH_IPV6_V1];		//IPV6 备用DNS服务器
	char cReserved[LEN_64];				//预留，填0即可。
	//如有IPV6相关的基本属性可以通过该字段实现。					
} *PLANPARAM_IPV6_V1;

typedef struct LANPARAM_WORKMODE 
{
	int iSize;						//sizeof(LANPARAM_WORKMODE)
	int iWorkMode;					//工作模式	0:负载均衡 1:网络容错 2:多址设定					
	int iMainLanNo;					//主网卡编号 0:Lan1 1:Lan2					
} *PLANPARAM_WORKMODE;

typedef struct LANPARAM_DHCP 
{
	int iSize;						//sizeof(LANPARAM_WORKMODE)
	int iLanNo;						//网卡编号 0:Lan1 1:Lan2	
	int iEnable;					//DHCP使能 0:停用 1:启动 
} *PLANPARAM_DHCP;
//add wifi&wifiap
typedef struct WIFIPARAM_DHCP       //cb@120711
{
	int iSize;						//sizeof(WIFIPARAM_DHCP)
	int iWifiDHCPMode;				//网卡工作模式 0:无线网卡0 DHCP； 1:无线网卡0 ap模式DHCP	
	int iEnable;					//DHCP使能 0:停用 1:启动 
	int iReserved;                  //待扩展参数 PS：目前只是一个无线网卡有两种DHCP类型
} *PWIFIPARAM_DHCP;

typedef struct WIFIAPDHCPPARA_DHCP       
{
	int iSize;						//sizeof(WIFIAPDHCPPARA_DHCP)
	int iDHCPStart;					//DHCP分配范围开始	
	int iDHCPEnd;					//DHCP分配范围结束 
	int iDHCPLease;                //DHCP租期
} *PWIFIAPDHCPPARA_DHCP;

typedef struct ITS_OSD
{
	int iX;
	int iY;
	int iEnable;
} *PITS_OSD;

// typedef	enum __tagAlarmLinkType
// {
// 	ALARM_LINKTYPE_AUDIO = 0,
// 	ALARM_LINKTYPE_VIDEO,
// 	ALARM_LINKTYPE_OUTPORT,
// 	ALARM_LINKTYPE_RECORD,
// 	ALARM_LINKTYPE_PTZ,
// 	ALARM_LINKTYPE_SNAPSHOT
// }EAlarmLinkType, *PEAlarmLinkType;
typedef int __tagAlarmLinkType;
typedef int EAlarmLinkType;
typedef int *PEAlarmLinkType;

//modify by zhy 2013.03.06
//////////////////////////////////////General AlarmLinkType////////////////////////////////////
#define ALARMLINKTYPE_MIN                               0  
#define ALARMLINKTYPE_LINKSOUND			(ALARMLINKTYPE_MIN + 0)		//联动声音提示
#define ALARMLINKTYPE_LINKDISPLAY		(ALARMLINKTYPE_MIN + 1)		//联动屏幕显示
#define ALARMLINKTYPE_LINKOUTPORT		(ALARMLINKTYPE_MIN + 2)     //联动输出端口 
#define ALARMLINKTYPE_LINKRECORD     	(ALARMLINKTYPE_MIN + 3)     //联动录像  
#define ALARMLINKTYPE_LINKPTZ	     	(ALARMLINKTYPE_MIN + 4)     //联动PTZ  
#define ALARMLINKTYPE_LINKSNAP   	    (ALARMLINKTYPE_MIN + 5)     //联动抓拍 
#define ALARMLINKTYPE_LINKSINGLEPIC		(ALARMLINKTYPE_MIN + 6)		//联动单画面
#define ALARMLINKTYPE_LINKEMAIL			(ALARMLINKTYPE_MIN + 7)		//联动邮件

//兼容IE
#define ALARM_LINKTYPE_AUDIO		ALARMLINKTYPE_LINKSOUND			//联动声音提示
#define ALARM_LINKTYPE_VIDEO		ALARMLINKTYPE_LINKDISPLAY		//联动屏幕显示
#define ALARM_LINKTYPE_OUTPORT		ALARMLINKTYPE_LINKOUTPORT		//联动输出端口 
#define ALARM_LINKTYPE_RECORD		ALARMLINKTYPE_LINKRECORD		//联动录像  
#define ALARM_LINKTYPE_PTZ			ALARMLINKTYPE_LINKPTZ			//联动PTZ  
#define ALARM_LINKTYPE_SNAPSHOT		ALARMLINKTYPE_LINKSNAP   		//联动抓拍
#define ALARM_LINKTYPE_SINGLEPIC	ALARMLINKTYPE_LINKSINGLEPIC		//联动单画面
#define ALARM_LINKTYPE_EMAIL		ALARMLINKTYPE_LINKEMAIL			//联动邮件

typedef struct __tagAlarmLink
{
	int				iLinkSetSize;
	int				iLinkSet[MAX_ALARM_LINKTYPE*MAX_BITSET_NUM];	//联动录像 抓拍 输出
	//取值由iLinkType而定,MAX_BITSET_NUM用于扩展，如0 Type与0+MAX_ALARM_LINKTYPE为同一种联动类型的参数，后者为扩展
	//iLinkType=0,1时，iLinkSet中对应位置数据表示使能iEnable，0，不使能；1，使能。
	//iLinkType=2,3,5时，iLinkSet中对应位置数据表示按位使能iEnableByBits，
	//从最低位至最高位每一位表示一个音视频通道/输出端口的使能。
	//iLinkType=4时，iLinkSe对应位置数据t表示联动的通道号

	int				iPtzSize;										//PTZ
	struct			vca_TLinkPTZ		ptz[MAX_CHANNEL_NUM];		//iLinkType=4时存储联动PTZ的参数
}TAlarmLink, *PTAlarmLink;							//	报警联动参数

typedef struct __tagAlarmLinkParam
{
	int				iBuffSize;

	int				iAlarmTypeParam;				//	报警类型参数
	//	取值由iAlarmType而定，假如iAlarmType为智能分析，则iAlarmTypeParam表示iRuleID
	int				iReserved;						//	取值由iAlarmType而定，假如iAlarmType为智能分析，则iAlarmTypeParam表示iEventID
	int				iLinkType;						//  扩展 +100 
	union
	{

		int iChannelSet[4];							//联动单画面用此结构 不支持扩展，需要使用原子获取方式
		int iEnable;								//联动单画面32路使能					
		struct										//除了单画外都使用这个结构体
		{
			TAlarmLink		stLinkContent;			//联动参数
			void*			pvReserved;		
		};
	};
}TAlarmLinkParam, *PTAlarmLinkParam;


typedef struct __tagAlarmLinkParam_V1
{
	int				iAlarmTypeParam;				//	报警类型参数
	//	取值由iAlarmType而定，假如iAlarmType为智能分析，则iAlarmTypeParam表示iRuleID
	int				iReserved;						//	取值由iAlarmType而定，假如iAlarmType为智能分析，则iAlarmTypeParam表示iEventID
	int				iLinkType;						//  扩展 +100 
	int				iLinkParamSize;
	union
	{
		int iEnable;
		int iChannelSet[MAX_BITSET_COUNT];						//联动单画面用此结构
		struct  
		{
			int				iPtzNo;				
			unsigned short	usType;					//	0不联动该通道，1预置位，2轨迹，3路径
			unsigned short	usTypeNO;				//	预置位号/轨迹号/路径号
		};
	};
}TAlarmLinkParam_V1, *PTAlarmLinkParam_V1;

/************************************************************************/
/* 通用报警参数															*/
/************************************************************************/
//命令
// typedef enum __tagAlarmSetCmd
// {
// 	CMD_SET_ALARMSCHEDULE = 0,
// 	CMD_SET_ALARMLINK,
// 	CMD_SET_ALARMSCH_ENABLE
// }EAlarmSetCmd, *PEAlarmSetCmd;
typedef int __tagAlarmSetCmd;
typedef int EAlarmSetCmd;
typedef int * PEAlarmSetCmd;
#define CMD_SET_ALARMSCHEDULE	0
#define CMD_SET_ALARMLINK		1
#define CMD_SET_ALARMSCH_ENABLE 2
#define CMD_SET_ALARMTRIGGER	3
#define CMD_SET_ALARMLINK_V1	4
#define CMD_SET_ALARMLINK_V2	5

// typedef enum __tagAlarmGetCmd
// {
// 	CMD_GET_ALARMSCHEDULE = 0,
// 	CMD_GET_ALARMLINK,
// 	CMD_GET_ALARMSCH_ENABLE
// }EAlarmGetCmd, *PEAlarmGetCmd;
typedef int __tagAlarmGetCmd;
typedef int EAlarmGetCmd;
typedef int * PEAlarmGetCmd;
#define CMD_GET_ALARMSCHEDULE	0
#define CMD_GET_ALARMLINK		1
#define CMD_GET_ALARMSCH_ENABLE 2
#define CMD_GET_ALARMTRIGGER	3
#define CMD_GET_ALARMLINK_V1	4
#define CMD_GET_ALARMLINK_V2	5

//报警参数标识
#define ATPI_AUDIO_LOST			0		//音频丢失报警触发参数
#define AUDIO_LOST_PARAM_COUNT	1		

//报警阀值参数
typedef struct __tagAlarmTriggerParam
{
	int				iBuffSize;
	int				iType;				//	报警类型
	int				iID;				//	报警参数标识
	int				iValue;				//	参数值
}TAlarmTriggerParam, *PTAlarmTriggerParam;

//SDK current use               //这块只保留通知报警，其他均使用与协议一致的宏定义
#define ALARM_VDO_MOTION		0
#define ALARM_VDO_REC			1
#define ALARM_VDO_LOST			2
#define ALARM_VDO_INPORT		3
#define ALARM_VDO_OUTPORT		4
#define ALARM_VDO_COVER 		5
#define ALARM_VCA_INFO			6			//VCA报警信息
#define ALARM_AUDIO_LOST		7
#define ALARM_EXCEPTION		    8
//动环主机报警（改为和协议一致）
#define ALARM_NORMAL						0x7FFFFFFF //状态正常无报警		
#define ALARM_ANALOG_UPPER_LIMIT_ON			10//模拟量上限报警
#define ALARM_ANALOG_LOWER_LIMIT_ON			11//模拟量下限报警
#define ALARM_TEMPERATURE_UPPER_LIMIT_ON	12//温度上限报警
#define ALARM_TEMPERATURE_LOWER_LIMIT_ON	13//温度下限报警
#define ALARM_HUMIDITY_UPPER_LIMIT_ON		14//湿度上限报警
#define ALARM_HUMIDITY_LOWER_LIMIT_ON		15//湿度下限报警
#define	ALARM_VDO_INPORT_OFF			    (3+256) //端口消警
#define ALARM_ANALOG_UPPER_LIMIT_OFF		(10+256)//模拟量上限消警 
#define ALARM_ANALOG_LOWER_LIMIT_OFF		(11+256)//模拟量下限消警 
#define ALARM_TEMPERATURE_UPPER_LIMIT_OFF	(12+256)//温度上限消警 
#define ALARM_TEMPERATURE_LOWER_LIMIT_OFF	(13+256)//温度下限消警 
#define ALARM_HUMIDITY_UPPER_LIMIT_OFF		(14+256)//湿度上限消警 
#define ALARM_HUMIDITY_LOWER_LIMIT_OFF		(15+256)//湿度下限消警 
//////////////////////////////////////ALARM CLEAR TYPE////////////////////////////////////CMD_GET_ALARMSCHEDULE
//from now on, after code 10  alarm use the style sending directly，not switch code in SDK。chenbin@140719
#define  ALARM_TYPE_MIN                          0
#define  ALARM_TYPE_VIDEO_LOST					 (ALARM_TYPE_MIN)       //视频丢失
#define  ALARM_TYPE_PORT_ALARM                   (ALARM_TYPE_MIN + 1)   //端口报警            
#define  ALARM_TYPE_MOTION_DETECTION			 (ALARM_TYPE_MIN + 2)   //移动侦测
#define  ALARM_TYPE_VIDEO_COVER					 (ALARM_TYPE_MIN + 3)   //视频遮挡
#define	 ALARM_TYPE_VCA							 (ALARM_TYPE_MIN + 4)	//智能分析
#define  ALARM_TYPE_AUDIOLOST					 (ALARM_TYPE_MIN + 5)	//音频丢失
#define  ALARM_TYPE_TEMPERATURE                  (ALARM_TYPE_MIN + 6)	//温湿度
#define  ALARM_TYPE_ILLEGAL_DETECT               (ALARM_TYPE_MIN + 7)	//违章检测
#define  ALARM_TYPE_EXCPETION				     (ALARM_TYPE_MIN + 100) //异常报警
#define  ALARM_TYPE_ALL							 (ALARM_TYPE_MIN + 255) //全部
#define  ALARM_TYPE_MAX                          (ALARM_TYPE_ALL + 1)
#define  ALARM_TYPE_PORT_ALARM_OFF				 (ALARM_TYPE_MIN + 1 + 256)//端口报警消警
///////////////////////////////////////ExceptionType///////////////////////////////////

#define  EXCEPTION_TYPE_MIN						0
#define  EXCEPTION_TYPE_DISK_FULL				(EXCEPTION_TYPE_MIN + 0)  //磁盘满			
#define  EXCEPTION_TYPE_NO_DISK					(EXCEPTION_TYPE_MIN + 1)  //无磁盘
#define  EXCEPTION_TYPE_DISK_IO_ERROR			(EXCEPTION_TYPE_MIN + 2)  //磁盘读写错误
#define  EXCEPTION_TYPE_NOALLOW_ACCESS			(EXCEPTION_TYPE_MIN + 3)  //非法访问
#define  EXCEPTION_TYPE_IP_COLLISION			(EXCEPTION_TYPE_MIN + 4)  //IP冲突
#define  EXCEPTION_TYPE_NETWORK_INTERRUPT		(EXCEPTION_TYPE_MIN + 5)  //网络中断
#define  EXCEPTION_TYPE_SYSTEM_BUSY				(EXCEPTION_TYPE_MIN + 6)  //系统忙	
#define  EXCEPTION_TYPE_NO_REDUNDANCY_DISK		(EXCEPTION_TYPE_MIN + 7)  //无冗余盘
#define  EXCEPTION_TYPE_ABNORMAL_VOLTAGE		(EXCEPTION_TYPE_MIN + 8)  //电压异常
#define  EXCEPTION_TYPE_MAC_COLLISION			(EXCEPTION_TYPE_MIN + 9)  //MAC冲突
#define  EXCEPTION_TYPE_RAID                    (EXCEPTION_TYPE_MIN + 10) //阵列异常
#define  EXCEPTION_TYPE_HOTBACKUP               (EXCEPTION_TYPE_MIN + 11) //热备异常
#define  EXCEPTION_TYPE_OVERLOAD				(EXCEPTION_TYPE_MIN + 12) //PSE overload
#define  EXCEPTION_TYPE_DISK_OVERLOAD			(EXCEPTION_TYPE_MIN + 13) //Disk overload
#define  EXCEPTION_TYPE_MAX						(EXCEPTION_TYPE_MIN + 14)	
//////////////////////////////////////Exception Handle////////////////////////////////////
#define  EXCEPTION_HANDLE_ENABLE                 0x01         //使能异常处理 
#define  EXCEPTION_HANDLE_DIALOG				 0x02         //是否弹出提示对话框
#define  EXCEPTION_HANDLE_LINK_BELL              0x04         //是否联动蜂鸣器
#define  EXCEPTION_HANDLE_LINK_NETCLIENT         0x08         //是否通知网络客户端
#define  EXCEPTION_HANDLE_LINK_EMAIL			 0x10         //是否联动邮件

//////////////////////////////////////AlarmLinkType////////////////////////////////////
#define ALARMLINKTYPE_MIN                               0  
#define ALARMLINKTYPE_VIDEOLOST_LINKRECORD     	(ALARMLINKTYPE_MIN + 0)   //视频丢失报警联动录像    
#define ALARMLINKTYPE_VIDEOLOST_LINKSNAP   	    (ALARMLINKTYPE_MIN + 1)   //视频丢失报警联动抓拍 
#define ALARMLINKTYPE_VIDEOLOST_LINKOUTPORT     (ALARMLINKTYPE_MIN + 3)   //视频丢失联动输出端口 
#define ALARMLINKTYPE_MOTIONDETECT_LINKRECORD   (ALARMLINKTYPE_MIN + 4)   //移动侦测报警联动录像 
#define ALARMLINKTYPE_MOTIONDETECT_LINKSNAP     (ALARMLINKTYPE_MIN + 5)   //移动侦测报警联动抓拍
#define ALARMLINKTYPE_MOTIONDETECT_LINKOUTPORT 	(ALARMLINKTYPE_MIN + 6)   //移动侦测联动输出端口 
#define ALARMLINKTYPE_PORTALARM_LINKRECORD     	(ALARMLINKTYPE_MIN + 7)   //端口报警联动录像
#define ALARMLINKTYPE_PORTALARM_LINKSNAP       	(ALARMLINKTYPE_MIN + 8)   //端口报警联动抓拍
#define ALARMLINKTYPE_PORTALARM_LINKOUTPORT    	(ALARMLINKTYPE_MIN + 9)   //端口报警联动输出端口
#define ALARMLINKTYPE_MAX					   	(ALARMLINKTYPE_PORTALARM_LINKOUTPORT + 1)

/************************************************************************/
/*  智能交通 电子警察*/
/************************************************************************/

#define SN_ENCRYPT_TYPE_MASK					0x01
#define SN_ENCRYPT_TYPE_RECOGNIZE_ARITHMETIC	0x00			//识别算法加密类型
#define SN_ENCRYPT_TYPE_PROGRAM					0x01			//程序加密类型

#define SYSTEM_TYPE_MASK					0x04					
#define SYSTEM_TYPE_DEBUG					0x00				//调试
#define SYSTEM_TYPE_GATE					0x03				//卡口
#define SYSTEM_TYPE_ECOP					0x04				//电警

#define SN_REG_MASK							0x02				
#define SN_REG_RECOGNIZE_DOG				0x01				//识别狗
#define SN_REG_ENCRYPT_DOG					0x02				//智能交通加密狗

//IPC 3MP
#define MAX_CHANNEL_TYPE		2
#define MAX_REALTYPE_NUM        2  //实时数据类型种类，0：高清相机实时亮度值；1：相机实时锐度信息

struct STRCT_REAL_STATE 
{
	int        m_iTypes[MAX_REALTYPE_NUM];  //每个type的type值
	int        m_iValues[MAX_REALTYPE_NUM]; //每个type对应的实时数据
};

//ITScb@121010
//智能相机扩展
////CMD集锦
///************************************************************************
//*	锐视相机时间段                                                                     
//************************************************************************/
//#define ITS_CMD_SET_MIN                         0
//#define ITS_CMD_SET_TIMERANGE_ENABLE			0                           //设置时间段使能
//#define ITS_CMD_SET_TIMERANGE_AGCBLOCK			1							//设置时间段测光区域使能
//#define ITS_CMD_SET_TIMERANGE_FLASHLAMP			2							//设置时间段闪光灯使能
//
//#define ITS_CMD_GET_TIMERANGE_ENABLE			3							//获取时间段使能
//#define ITS_CMD_GET_TIMERANGE_AGCBLOCK			4							//获取时间段测光区域使能
//#define ITS_CMD_GET_TIMERANGE_FLASHLAMP			5							//获取时间段闪光灯使能
///************************************************************************/
///*   智能交通车道参数                                                                 
///************************************************************************/
//#define ITS_ROADWAY_CMD_SET_MIN     0
//#define ITS_ROADWAY_CMD_SET_ENABLE  (ITS_ROADWAY_CMD_SET_MIN + 0)	    //设置车道使能
//#define ITS_ROADWAY_CMD_SET_LOOP    (ITS_ROADWAY_CMD_SET_MIN + 1)		//设置车道线圈
//#define ITS_ROADWAY_CMD_SET_TIME    (ITS_ROADWAY_CMD_SET_MIN + 2)		//设置车道时间
//#define ITS_ROADWAY_CMD_SET_SPEED   (ITS_ROADWAY_CMD_SET_MIN + 3)		//设置车道速度
//#define ITS_ROADWAY_CMD_SET_RECO    (ITS_ROADWAY_CMD_SET_MIN + 4)		//设置测到识别区域
//#define ITS_ROADWAY_CMD_SET_VLOOP   (ITS_ROADWAY_CMD_SET_MIN + 5)		//设置虚拟线圈
//#define ITS_ROADWAY_CMD_SET_LIGHT   (ITS_ROADWAY_CMD_SET_MIN + 6)		//设置车道信号灯
//#define ITS_ROADWAY_CMD_SET_CAPTURE (ITS_ROADWAY_CMD_SET_MIN + 7)		//设置车道抓拍
//#define ITS_ROADWAY_CMD_SET_REFERENCELINE	(ITS_ROADWAY_CMD_SET_MIN + 8)		//设置车道绊线
//#define ITS_ROADWAY_CMD_SET_MAX     (ITS_ROADWAY_CMD_SET_MIN + 9)		//
//
//#define ITS_ROADWAY_CMD_GET_MIN     0
//#define ITS_ROADWAY_CMD_GET_ENABLE  (ITS_ROADWAY_CMD_GET_MIN + 0)	    //获得车道使能
//#define ITS_ROADWAY_CMD_GET_LOOP    (ITS_ROADWAY_CMD_GET_MIN + 1)		//获得车道线圈
//#define ITS_ROADWAY_CMD_GET_TIME    (ITS_ROADWAY_CMD_GET_MIN + 2)		//获得车道时间
//#define ITS_ROADWAY_CMD_GET_SPEED   (ITS_ROADWAY_CMD_GET_MIN + 3)		//获得车道速度
//#define ITS_ROADWAY_CMD_GET_RECO    (ITS_ROADWAY_CMD_GET_MIN + 4)		//获得测到识别区域
//#define ITS_ROADWAY_CMD_GET_VLOOP   (ITS_ROADWAY_CMD_GET_MIN + 5)		//获得虚拟线圈
//#define ITS_ROADWAY_CMD_GET_LIGHT   (ITS_ROADWAY_CMD_GET_MIN + 6)		//获得车道信号灯
//#define ITS_ROADWAY_CMD_GET_CAPTURE (ITS_ROADWAY_CMD_GET_MIN + 7)		//获得车道抓拍
//#define ITS_ROADWAY_CMD_GET_REFERENCELINE	(ITS_ROADWAY_CMD_GET_MIN + 8)	//设置车道绊线
//#define ITS_ROADWAY_CMD_GET_MAX     (ITS_ROADWAY_CMD_GET_MIN + 9)		//
///************************************************************************/
///*	智能交通车牌优化
///************************************************************************/
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN                   0
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_FIRST_HZ				(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 0)	    //设置车牌优化首汉字
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 1)		//设置是否允许无牌车
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 2)		//设置待检索车牌和不可信车牌
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 3)		//
//
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN                   0										   		
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_FIRST_CHARACTER       (ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 0)		//获得车牌优化首汉字
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 1)		//获得是否允许无牌车
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 2)		//获得待检索车牌和不可信车牌
//#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 3)		//
///************************************************************************/
///*  交通违章检测球  
///************************************************************************/
//#define ITS_EXTRAINFO_CMD_SET_MIN								 0
////违停项目
//#define ITS_ILLEGALPARK_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 0)	    //设置违章停车参数
//#define ITS_ILLEGALPARKPARM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 1)		//设置违章停车标定区域参数
//#define ITS_LICENSEOPTIMIZEOTHER_CMD_SET						(ITS_EXTRAINFO_CMD_SET_MIN + 2)		//设置待检索车牌和不可信车牌
//#define ITS_OPTIM_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 3)		//设置车牌优化首汉字
//#define ITS_RECOPARAM_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 4)		//设置识别算法参数
//#define ITS_ROADWAYENABLE_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 5)		//设置车道
//#define ITS_CAMLOCATION_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 6)		//设置设备信息
//#define ITS_EXACTCONFIRM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 7)		//设置精确定位信息
////智能相机
//#define ITS_VIDEODECTECT_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 8)		//图像检测参数
//#define ITS_DETECTAREA_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 10)	//轨迹分析检测区域参数
//#define ITS_RECOTYPE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 11)	//算法类型参数
////交通一体机
//#define ITS_REDLIGHTDETECTAREA_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//设置红灯检测区域参数
//#define ITS_ENABLE_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//设置交通相关功能使能协议
//
//#define ITS_EXTRAINFO_CMD_SET_MAX								(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//
//
//#define ITS_EXTRAINFO_CMD_GET_MIN								 0
////违停项目
//#define ITS_ILLEGALPARK_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 0)	    //获得违章停车参数
//#define ITS_ILLEGALPARKPARM_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 1)		//获得违章停车标定区域参数
//#define ITS_LICENSEOPTIMIZEOTHER_CMD_GET						(ITS_EXTRAINFO_CMD_GET_MIN + 2)		//获得待检索车牌和不可信车牌
//#define ITS_OPTIM_CMD_GET										(ITS_EXTRAINFO_CMD_GET_MIN + 3)		//获得车牌优化首汉字
//#define ITS_RECOPARAM_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 4)		//获得识别算法参数
//#define ITS_ROADWAYENABLE_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 5)		//获得车道
//#define ITS_CAMLOCATION_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 6)		//获得设备信息
////智能相机
//#define ITS_VIDEODECTECT_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 7)		//图像检测参数
//#define ITS_DETECTAREA_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 9)		//轨迹分析检测区域参数
//#define ITS_RECOTYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 10)	//算法类型参数
//#define ITS_CAMRATYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 11)	//相机类型
////交通一体机
//#define ITS_REDLIGHTDETECTAREA_CMD_GET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//获得红灯检测区域参数
//#define ITS_ENABLE_CMD_GET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//获得交通相关功能使能协议
//#define ITS_VERSIONPRO_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//获得相机版本信息
//
//#define ITS_EXTRAINFO_CMD_GET_MAX								(ITS_EXTRAINFO_CMD_GET_MIN + 15)	//
////CMD集锦END 建议保留原位置注释，以便相关参数在同一个位置，提高可读性

/************************************************************************
*	相机测光区域坐标                                                                   
************************************************************************/
#define MAX_ITS_BLOCK        5  

struct ITS_TBlock  
{
	int iX;					
	int iY;
};

struct ITS_TOTAL_TBlock
{
	ITS_TBlock block[MAX_ITS_BLOCK];
};
/************************************************************************
*	锐视相机时间段                                                                     
************************************************************************/
#define ITS_CMD_SET_TIMERANGE_ENABLE			0                           //设置时间段使能
#define ITS_CMD_SET_TIMERANGE_AGCBLOCK			1							//设置时间段测光区域使能
#define ITS_CMD_SET_TIMERANGE_FLASHLAMP			2							//设置时间段闪光灯使能

#define ITS_CMD_GET_TIMERANGE_ENABLE			3							//获取时间段使能
#define ITS_CMD_GET_TIMERANGE_AGCBLOCK			4							//获取时间段测光区域使能
#define ITS_CMD_GET_TIMERANGE_FLASHLAMP			5							//获取时间段闪光灯使能

#define MAX_ITS_TIMERANGE                8

struct ITS_TTimeRange 
{
	int iEnable;								//是否启用该时间段，1-启用，0-不启用
	int iTimeRange;								//时间范围： bit24-bit31:开始小时
	//					bit16-bit23:开始分钟
	//					bit8-bit15:结束小时
	//					bit0-bit7:结束分钟	
};

struct ITS_TOTAL_TTimeRange 
{
	ITS_TTimeRange timerange[MAX_ITS_TIMERANGE];
};
/************************************************************************
*	锐视相机时间段通用参数                                                                     
************************************************************************/
#define MAX_ITS_TEMPLATE                8
#define MAX_TIME_RANGE_PARAM  			43
struct ITS_TTimeRangeParam 
{
	int iType;							// 0-设置增益 1-设置曝光 2-设置白平衡 3-设置亮度
	int iAutoEnable[MAX_TIME_RANGE_PARAM];	//  1、1-自动；0-手动。
	//	2、特殊说明（iType为12时，0-日光模式；1-荧光灯模式；2-不进行白平衡）。
	//	3、iType为255时，代表：1-自动；0-手动。
	//  4、iType为8时1-自动（普通模式），0-手动 2-自动（专家模式）3-ITS相机3D降噪级别   //add by wd @20130619
	int iParam1[MAX_TIME_RANGE_PARAM];		//0--光圈调节：手动下：代表具体值；自动下：1开启光圈，0关闭光圈。
	//1--超宽动态：1代表开启；0代表关闭
	//2--背光补偿：1代表开启；0代表关闭
	//3--曝光时间：手动下：代表具体值；自动下：代表期望值
	//4--快门调节：手动下：代表具体值；自动下：代表期望值
	//5--增益调节：手动下：代表具体值；自动下：代表期望值
	//6--gamma调节：手动下：代表具体值；自动下：代表期望值
	//7--锐度调节：手动下：代表具体值；自动下：代表期望值
	//8--降噪调节：手动下：代表具体值；自动(简单模式)下：代表期望值：自动(专家模式)下：代表2D降噪期望值   ITS相机3D降噪级别：3-高，2-中，1-低，0-最低 //add by wd @20130619
	//9--曝光区域：代表左上角X坐标
	//10--背光补偿区域：代表左上角X坐标
	//11--AF区域设置：代表左上角X坐标
	//12--目标亮度调节：手动下：代表具体值；自动下：代表期望值
	//13--白平衡调节：手动下：代表白平衡的R分量：0-255；自动下：代表白平衡的R分量校正系数：范围100-200，精度为5
	//14--jpeg图像质量
	//15--lut使能
	//16--自动亮度调节使能
	int iParam2[MAX_TIME_RANGE_PARAM];		//0--光圈调节：未使用
	//1--超宽动态：未使用
	//2--背光补偿：未使用
	//3--曝光时间：手动下：未使用；自动下：代表上限值
	//4--快门调节：手动下：未使用；自动下：代表上限值
	//5--增益调节：手动下：未使用；自动下：代表上限值
	//6--gamma调节：手动下：未使用；自动下：代表上限值
	//7--锐度调节：手动下：未使用；自动下：代表上限值
	//8--降噪调节：手动下：未使用；自动(简单模式)下：未使用：自动(专家模式)下：代表3D降噪期望值
	//9--曝光区域：代表左上角Y坐标
	//10--背光补偿区域：代表左上角Y坐标
	//11--AF区域设置：代表左上角Y坐标
	//12--目标亮度调节：手动下：代表具体值；自动下：代表上限值
	//13--白平衡调节：手动下：代表白平衡的G分量：0-255；自动下：代表白平衡的G分量校正系数：范围100-200，精度为5
	//14--jpeg图像质量
	//15--lut使能
	//16--自动亮度调节使能
	int iParam3[MAX_TIME_RANGE_PARAM];		//0--光圈调节：未使用
	//1--超宽动态：未使用
	//2--背光补偿：未使用
	//3--曝光时间：手动下：未使用；自动下：代表下限值
	//4--快门调节：手动下：未使用；自动下：代表下限值
	//5--增益调节：手动下：未使用；自动下：代表下限值
	//6--gamma调节：手动下：未使用；自动下：代表下限值
	//7--锐度调节：手动下：未使用；自动下：代表下限值
	//8--降噪调节：手动下：未使用；自动下：未使用
	//9--曝光区域：代表右下角X坐标
	//10--背光补偿区域：代表右下角X坐标
	//11--AF区域设置：代表右下角X坐标
	//12--目标亮度调节：手动下：代表具体值；自动下：代表下限值
	//13--白平衡调节：手动下：代表白平衡的B分量：0-255；自动下：代表白平衡的B分量校正系数：范围100-200，精度为5
	//14--jpeg图像质量
	//15--lut使能
	//16--自动亮度调节使能
	int iParam4[MAX_TIME_RANGE_PARAM];		//0--光圈调节：未使用
	//1--超宽动态：未使用
	//2--背光补偿：未使用
	//3--曝光时间：未使用
	//4--快门调节：未使用
	//5--增益调节：未使用
	//6--gamma调节：未使用
	//7--锐度调节：未使用
	//8--降噪调节：未使用
	//9--曝光区域：代表右下角Y坐标
	//10--背光补偿区域：代表右下角Y坐标
	//11--AF区域设置：代表右下角Y坐标
	//12--目标亮度调节：未使用
	//13--白平衡调节：未使用
	//14--jpeg图像质量
	//15--lut使能
	//16--自动亮度调节使能
};

struct ITS_TOTAL_TTimeRangeParam 
{
	ITS_TTimeRangeParam timerangeparam[MAX_ITS_TEMPLATE +1];
};

struct ITS_TTemplateMap 
{
	int iTemplateID;					//模板编号
	char cTemplateName[64];				//模板名称
};

struct ITS_TOTAL_TTemplateMap 
{
	ITS_TTemplateMap templatemap[MAX_ITS_TIMERANGE];
};

typedef struct ITS_ILLEGALRECORD
{
	long m_lCarID;
	int  m_iRecordFlag;
	int  m_iIllegalType;
	int  m_iPreset;
}*pITS_ILLEGALRECORD;

/************************************************************************
*	锐视相机工作模式                                                                    
************************************************************************/
struct ITS_CamWorkMode 
{
	int iWorkMode;							//工作模式  0-卡口模式   1-超速模式
	int iInterval;								//时间间隔	
};

/************************************************************************/
//*   智能交通车道参数                                                                 
/************************************************************************/

//从9开始GET/SET使用统一的宏定义，增加时注意修改ITS_ROADWAY_CMD_GET_MAX/ITS_ROADWAY_CMD_SET_MAX的值
#define ITS_ROADWAY_CMD_SET_MIN				0
#define ITS_ROADWAY_CMD_SET_ENABLE			(ITS_ROADWAY_CMD_SET_MIN + 0)	    //设置车道使能
#define ITS_ROADWAY_CMD_SET_LOOP			(ITS_ROADWAY_CMD_SET_MIN + 1)		//设置车道线圈
#define ITS_ROADWAY_CMD_SET_TIME			(ITS_ROADWAY_CMD_SET_MIN + 2)		//设置车道时间
#define ITS_ROADWAY_CMD_SET_SPEED			(ITS_ROADWAY_CMD_SET_MIN + 3)		//设置车道速度
#define ITS_ROADWAY_CMD_SET_RECO			(ITS_ROADWAY_CMD_SET_MIN + 4)		//设置测到识别区域
#define ITS_ROADWAY_CMD_SET_VLOOP			(ITS_ROADWAY_CMD_SET_MIN + 5)		//设置虚拟线圈
#define ITS_ROADWAY_CMD_SET_LIGHT			(ITS_ROADWAY_CMD_SET_MIN + 6)		//设置车道信号灯
#define ITS_ROADWAY_CMD_SET_CAPTURE			(ITS_ROADWAY_CMD_SET_MIN + 7)		//设置车道抓拍
#define ITS_ROADWAY_CMD_SET_REFERENCELINE	(ITS_ROADWAY_CMD_SET_MIN + 8)		//设置车道绊线
#define ITS_ROADWAY_CMD_CHNLCARSPEED        (ITS_ROADWAY_CMD_SET_MIN + 9)		//设置/获取 车道不同车辆类型的速度检测参数
#define ITS_ROADWAY_CMD_CHNLDELAYDIS        (ITS_ROADWAY_CMD_SET_MIN + 10)		//设置/获取 车道延迟抓拍距离
#define ITS_ROADWAY_CMD_SET_MAX				(ITS_ROADWAY_CMD_SET_MIN + 11)		

#define ITS_ROADWAY_CMD_GET_MIN				0
#define ITS_ROADWAY_CMD_GET_ENABLE			(ITS_ROADWAY_CMD_GET_MIN + 0)	    //获得车道使能
#define ITS_ROADWAY_CMD_GET_LOOP			(ITS_ROADWAY_CMD_GET_MIN + 1)		//获得车道线圈
#define ITS_ROADWAY_CMD_GET_TIME			(ITS_ROADWAY_CMD_GET_MIN + 2)		//获得车道时间
#define ITS_ROADWAY_CMD_GET_SPEED			(ITS_ROADWAY_CMD_GET_MIN + 3)		//获得车道速度
#define ITS_ROADWAY_CMD_GET_RECO			(ITS_ROADWAY_CMD_GET_MIN + 4)		//获得测到识别区域
#define ITS_ROADWAY_CMD_GET_VLOOP			(ITS_ROADWAY_CMD_GET_MIN + 5)		//获得虚拟线圈
#define ITS_ROADWAY_CMD_GET_LIGHT			(ITS_ROADWAY_CMD_GET_MIN + 6)		//获得车道信号灯
#define ITS_ROADWAY_CMD_GET_CAPTURE			(ITS_ROADWAY_CMD_GET_MIN + 7)		//获得车道抓拍
#define ITS_ROADWAY_CMD_GET_REFERENCELINE	(ITS_ROADWAY_CMD_GET_MIN + 8)		//获得车道绊线
#define ITS_ROADWAY_CMD_GET_MAX				(ITS_ROADWAY_CMD_GET_MIN + 11)		

#define MAX_ROADWAY_COUNT					4          //最大车道数
#define MAX_LOOP_COUNT						4          //车道内最大线圈数
#define DAY_OR_NIGHT						2          //0---白天，1---晚上

#define LIGHT_COUNT_EX                      8                   //信号灯数 
#define LIGHT_COUNT							4					//信号灯数
#define LIGHT_COM_COUNT						4					//信号灯串口数
#define CAPTURE_PLACE_COUNT					3					//车道对应的抓拍位置数目

#define CAPTURE_TYPE_MASK					0x01FF				// 升级到后8位 [4/19/2012 hanyongqiang]
#define CAPTURE_TYPE_GATE					0x01				//卡口
#define CAPTURE_TYPE_RED_LIGHT				0x02				//闯红灯 
#define CAPTURE_TYPE_REVERSE				0x04				//逆行
#define CAPTURE_TYPE_OVERSPEED				0x08				//超速

//智能相机扩展
#define	MAX_ITS_REFLINE_NUM		25
#define MAX_ITS_DETECTMODE		5

#define	MAX_SCENE_NUM			16								//	场景编号最大值

struct TITSRoadwayInfo 
{
	int iRoadwayID;
	int  iEnable;
	char cChannelName[32];
	char cChannelDir[32];
};

#define MAX_ROADWAY_CHANNEL_NAME 50
struct TITSRoadwayInfoEx
{
	int iRoadwayID;
	int  iEnable;
	char cChannelName[MAX_ROADWAY_CHANNEL_NAME+1];
	char cChannelDir[LEN_32];
};

//add by wd @20130531 设置车道信息 扩展
typedef struct __tagTITSRoadwayInfo_V1
{
	int  iBufSize;					//根据所需结构体的长度(可自定义)
	int  iRoadwayID;				//车道编号 最大支持4个车道：0-3
	int  iEnable;					//车道使能标志  1-使能；0-不使能
	char cChannelName[MAX_ROADWAY_CHANNEL_NAME+1];			//车道名称  长度不超过50字符
	char cChannelDir[LEN_32];		//车道方向  长度不超过31字符
	int	 iChannelDownUp;			//车道上下行  0-上行，1-下行
	//add by wd 20130619 扩展字段 如下
	int  iUses;						//车道用途 0-普通车道，1-非机动车道，2-公交车道,3-小型汽车车道
	int	 iSceneID;					// 场景ID(0~15) 20140203扩展
	NVS_FILE_TIME  stStartTime;	
	NVS_FILE_TIME  stStopTime;		//Time RangeS
	NVS_FILE_TIME  stStartTime2;	
	NVS_FILE_TIME  stStopTime2;
	NVS_FILE_TIME  stStartTime3;	
	NVS_FILE_TIME  stStopTime3;	
	NVS_FILE_TIME  stStartTime4;	
	NVS_FILE_TIME  stStopTime4;
	int  iBorderEnable;				//边界车道 按位使能：bit0-左边界，bit1-右边界。默认都为0
	char cNewChannelID[LEN_64];		//Roadway new channel ID, the lenth less than 63 bits
} TITSRoadwayInfo_V1, *PTITSRoadwayInfo_V1;
//add ended

struct TITSRoadWayLoop
{
	int iRoadwayID;
	int iComportNo;
	int iSpeedLoopNo;
	int iCaptureLoopNo;
	int iSceneID;// 场景ID(0~15) 20140203扩展
	int iSecCaptureLoopNo;//第二抓拍线圈号,20150304拓展
};

struct TITSRoadwayTime
{
	int iRoadwayID;
	int iLoopMaxTime;
	int iLoopMinTime;
	int iLoopDelayTime;
	int iSceneID;// 场景ID(0~15) 20140203扩展
};

struct TITSRoadwaySpeed
{
	int iRoadwayID;
	int iLoopDistance;
	int iSpeedLimit;
	int iSpeedModify;
	int iSceneID;// 场景ID(0~15) 20140203扩展
};

struct TITSRoadwayReco
{
	int iRoadwayID;
	int iRoadwayRange;
	int iSceneID;// 场景ID(0~15) 20140203扩展
	int iChnNo;
};

struct TITSRoadwayVLoop
{
	int iRoadwayID;
	int iLoopID;
	int iDayNight;
	int iPoint1[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint2[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint3[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iPoint4[DAY_OR_NIGHT][MAX_LOOP_COUNT];
	int iSceneID;// 场景ID(0~15) 20140203扩展
	int iSensitivity;//sensibility(0~100) defult50 20141219
	int iChnNo;
};

struct TITSRoadwayLight			//信号灯
{
	int iRoadwayID;
	int iComNo;				//信号灯对应的串口号，范围0-2（其中0、1为RS232串口，2为RS485串口）
	int iFloodID;			//补光灯编号,按位					
	char cLightID[32];	//其他信号灯,格式4,0,1,2,3……(第一位标示一共几个灯，后面对于4路红灯检测器，范围0-3。)					
};

//智能相机扩展
typedef struct __tagTITSRoadwayLight_V1
{
	TITSRoadwayLight m_stLight;
	int				 m_iCompelRedlight;		//强制红灯
	int iSceneID;					// 场景ID(0~15) 20140203扩展
	int iFlashLampType;				//闪光灯控制方式  0：关联闪； 1：轮闪；
}TITSRoadwayLight_V1, *PTITSRoadwayLight_V1;

struct TITSRoadwayCapture			//抓拍位置
{
	int iRoadwayID;                         //车道编号   最大支持4个车道：0-3
	int iType;							//车道抓拍类型
	//bit0--卡口
	//bit1--闯红灯 
	//bit2--逆行 
	//bit3--超速
	//bit4--禁止左行驶抓拍 
	//bit5--禁止右行驶抓拍 
	//bit6--压黄线抓拍
	//bit7--非机动车抓拍
	//bit8--不按规定车道行驶 (不按导向行驶)
	//bit9--禁止直行    //add by wd @20130619 扩展
	//bit10--公交车道
	//bit11--压车道线
	//bit12--待转区域闯红灯
	//bit13--违法停车  //add end
	//bit14--混合触发下视频抓拍超速功能使能
	char cPlace[CAPTURE_PLACE_COUNT][64];	//车辆经过线圈时的抓拍位置
	//0——不抓拍
	//1——进入测速线圈时抓拍
	//2——离开测速线圈时抓拍
	//3——进入抓拍线圈时抓拍
	//4——离开抓拍线圈时抓拍
	//5——延时抓拍
	//按类型进行，例：1,2,3,4
	int iChannelTpye;                       //类别
	//0--左转车道
	//1--右转车道
	//2--直行车道
	//3--左转直行车道
	//4--右转直行车道
	//5--非机动车道 ---预留                 //modify by wd @20130619 
	//6--左转右转车道
	//7--左转车道加待转线
	//8--直行+左转+右转车道
	int iRecognizePlace;                   //识别策略
	//0--识别第一张
	//1--识别第二张
	//2--先识别第一张再识别第二张,取置信度高的结果
	//3--识别第二张,如果未识别出结果,再识别第一张
	//4--识别第一张,如果未识别出结果,再识别第二张
	//5—识别第三张                        
	int iSceneID;							// 场景ID(0~15) 20140203扩展
};

struct ITS_RecoParamEx					//锐视相机识别算法扩展参数   
{
	int iMaxPlateNO;					//最大车牌数
	int iMaxPlateWidth;					//最大车牌宽度
	int iMinPlateWidth;					//最小车牌宽度
	int iRoadwayID;						//车道编号
	int iEnable;						//使能标志	0：禁用识别；1：启用识别；3：代表启动识别，并启动人脸识别				
	int iEngineNum;						//识别引擎个数	暂不支持，填0即可	
	int iAreaType;						//识别区域类型
	int iPlateType;						//识别车辆类型
	int iSpeed;							//车辆速度。注：车辆速度指的是车辆在视频画面中的移动速度，而非车辆的实际行使速度。	范围1-10					
	int iMaxSkip;						//最大遮挡帧数
	int iMinValid;						//最小车牌置信度
	int iFramePercent;					//识别比率
	int iMinCapDiff;					//抓图更新阈值
	char cCaliInfo[76];					//车牌标定  20120229扩展
	//20121030扩展
	int	iPlateCharType;					//车牌每一位的识别字符类型,
	//当前车牌为7位，使用后14位表示每位车牌的字符类型，每两位表示一位字符类型
	//00-汉字 01-字母 10-数字 11-字母或数字
	int iConfid;						//车牌置信度阈值
};

typedef struct tagTITSRecoParam
{
	int iSize;
	ITS_RecoParamEx tRecoPara;
	int iCarNumType;
	int iAngle;	
}TITSRecoParam, *pTITSRecoParam;

//ITS绊线参数---智能相机v3.2
typedef struct __tagTITS_RefLine
{
	int			m_iLineID;
	int			m_iEnable;
	int			m_iLineType;
	vca_TLine	m_stLine1;
	vca_TLine	m_stLine2;				//预留
	int			m_iDistance;
}TITS_RefLine, *PTITS_RefLine;

typedef struct __tagTITS_ReflineAarry
{
	int			m_iRoadwayID;
	int			m_iLineNum;
	TITS_RefLine m_stLines[MAX_ITS_REFLINE_NUM];
	int iSceneID;// 场景ID(0~15) 20140203扩展
}TITS_RefLineAarry, *PTITS_ReflineArray;


#define MAX_VEHICLE_TYPE 3//最大车辆类型数
typedef struct __tagTITS_ChnCarSpeedPara
{
	int iCarWayNo;						//车道编号：最大支持4个车道，0-3
	int iCarType;						//车辆类型：0-不检测，1-小车，2-大车
	int iSpeedHighLimit;				//车道限速上限：m/s（解析时除以1000，转换成保留3为小数）
	int iSpeedLowLimit;					//车道限速下限：m/s（解析时除以1000，转换成保留3为小数）
	int iHighExceedPercent;				//高速执法百分比：0-100
	int iLowExceedPercent;				//低速执法百分比：0-100
	int iSceneID;						// 场景ID(0~15) 20140203扩展
	float fAbnormalHighSpeed;			//异常超速 速度限制参数：单位：米/秒(3位小数的float型)
	float fAbnormalLowSpeed;			//异常低速 速度限制参数：单位：米/秒(3位小数的float型)
}TITS_ChnCarSpeedPara, *PTITS_ChnCarSpeedPara;


struct TITSRoadwayParam
{
	int iRoadWayID;

	//modified by wd @20130531 
	//TITSRoadwayInfoEx info;
	TITSRoadwayInfo_V1 RoadWayInfo;
	//modified end

	TITSRoadWayLoop loop;
	TITSRoadwayTime time;
	TITSRoadwaySpeed speed;
	TITSRoadwayReco reco;
	TITSRoadwayVLoop vloop;
	TITSRoadwayCapture capture;
	TITSRoadwayCapture captureNew;
	ITS_RecoParamEx recopara;
	TITSRecoParam   recopara_ex;
	TITSRoadwayLight_V1	light;
	TITS_RefLineAarry   m_stLineArray;	
};

//ShangHai BK  |zyb add 20150304
typedef struct tagTITSRoadwayDelayDistance
{
	int				iSize;
	int				iSceneId;	//场景ID(0~15)
	int				iLaneId;	//车道编号, 最大支持4个车道：0-3
	int				iSignalDelayDistance;	//抓拍信号延迟抓拍距离(cm)或时间(ms)
	int				iDelayCapDistanceS;		//第二张抓拍延迟距离(cm)或时间(ms)
	int				iDelayCapDistanceT;		//第三张抓拍延迟距离(cm)或时间(ms)
	int				iDelayCapDistanceFourth;//第四张抓拍延迟距离(cm)或时间(ms)
	int				iDelayCapDistanceFifth;	//第五张抓拍延迟距离(cm)或时间(ms)
	int				iDelayCapTypeFirst;		//第1张抓拍延迟类型 1：时间
	int				iDelayCapTypeSec;		//第2张抓拍延迟类型 1：时间
	int				iDelayCapTypeTrd;		//第3张抓拍延迟类型 1：时间
	int				iDelayCapTypeFourth;	//第4张抓拍延迟类型 1：时间 
	int				iDelayCapTypeFifth;		//第5张抓拍延迟类型 1：时间
}TITSRoadwayDelayDistance, *pTITSRoadwayDelayDistance;
//add end

/************************************************************************/
//*	智能交通车牌优化
/************************************************************************/

#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN                   0
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_FIRST_HZ				(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 0)	    //设置车牌优化首汉字
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 1)		//设置是否允许无牌车
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 2)		//设置待检索车牌和不可信车牌
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_SET_MIN + 3)		//

#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN                   0										   		
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_FIRST_CHARACTER       (ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 0)		//获得车牌优化首汉字
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_NOPLATE_ENABLE		(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 1)		//获得是否允许无牌车
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_OTHER					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 2)		//获得待检索车牌和不可信车牌
#define ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MAX					(ITS_LICENSEPLATE_OPTIMIZE_CMD_GET_MIN + 3)		//

struct TITSLicensePlateOptimizeFirstHZInfo
{
	char cModifyChar[9];
	int iMinCharConfid;
	char cModifyAlpha[10];
	int iMinAlphaConfig;
};

struct TITSLicesePlateOptimizeOther    //检索车牌和不可信车牌
{
	int iType;                         //类型 0：待检索汉字；1：不可信汉字
	int iCount;                        //首汉字数目 最多支持8个
	char cModifyChar[8][3];            //首汉字    应设置成邻省车牌首汉字或不可能出现的车牌首汉字。不超过4个字节
};
typedef struct _TITSLicensePlateOptimizeFirstHZInfo_V1
{
	char cModifyChar[9];
	int iMinCharConfid;
	char cModifyAlpha[10];
	int iMinAlphaConfig;
	int iSize;
	int iSceneId;
	int iChnNo;
}TITSLicensePlateOptimizeFirstHZInfo_V1, *PTITSLicensePlateOptimizeFirstHZInfo_V1;

#define MAX_OPTIMIZEOTHERTYPE_NUM 2    //0：待检索汉字；1：不可信汉字
#define MAX_OPTIMIZEOTHERTYPE_SCENE	15	//最大场景编号
struct TITSLicensePlateOptimizeParam
{
	int iEnableNoPlate;
	TITSLicensePlateOptimizeFirstHZInfo_V1  firstHZinfo[MAX_OPTIMIZEOTHERTYPE_SCENE];
	//modify by wd @20130626
	TITSLicesePlateOptimizeOther other[MAX_OPTIMIZEOTHERTYPE_NUM];
};

/************************************************************************/
///*  设置待检索车牌和不可信车牌//非本地车牌 
/************************************************************************/
#define  MAX_MODIFYCHAR_COUNT    8
struct ITS_LicenseOptimizeOther
{
	int			iType;      							//0：待检索汉字；1：不可信汉字
	int			iCount;									//首汉字数目 最多支持8个
	char		cModifyChar[MAX_MODIFYCHAR_COUNT][5];	//应设置成邻省车牌首汉字或不可能出现的车牌首汉字。不超过4个字节
	int			iOtherCharWeight[MAX_MODIFYCHAR_COUNT];	//首汉字优化最低置信度
} ;

/************************************************************************/
///*  交通违章检测球  
/************************************************************************/
#define ITS_EXTRAINFO_CMD_SET_MIN								 0
//违停项目
#define ITS_ILLEGALPARK_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 0)	    //设置违章停车参数
#define ITS_ILLEGALPARKPARM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 1)		//设置违章停车标定区域参数
#define ITS_LICENSEOPTIMIZEOTHER_CMD_SET						(ITS_EXTRAINFO_CMD_SET_MIN + 2)		//设置待检索车牌和不可信车牌
#define ITS_OPTIM_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 3)		//设置车牌优化首汉字
#define ITS_RECOPARAM_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 4)		//设置识别算法参数
#define ITS_ROADWAYENABLE_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 5)		//设置车道
#define ITS_CAMLOCATION_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 6)		//设置设备信息
#define ITS_EXACTCONFIRM_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 7)		//设置精确定位信息
//智能相机
#define ITS_VIDEODECTECT_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 8)		//图像检测参数
#define ITS_DETECTAREA_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 10)	//轨迹分析检测区域参数
#define ITS_RECOTYPE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 11)	//算法类型参数
//交通一体机
#define ITS_REDLIGHTDETECTAREA_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//设置红灯检测区域参数
#define ITS_ENABLE_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//设置交通相关功能使能协议
#define ITS_DAYNIGHT_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//设置交通相关功能使能协议
#define ITS_WORKMODE_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//设置工作模式
#define  ITS_LIGHTINFO_CMD_SET                                  (ITS_EXTRAINFO_CMD_SET_MIN + 16)   //设置信号灯对应的参数
#define ITS_CROSSINFO_CMD_SET                                   (ITS_EXTRAINFO_CMD_SET_MIN + 17)	//设置路口信息参数
#define ITS_AREAINFO_CMD_SET                                    (ITS_EXTRAINFO_CMD_SET_MIN + 18)    //设置增益区域参数
#define ITS_ILLEGALPARKINFO_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 19)	//违停球
#define ITS_SECURITYCODE_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 20)	//设置防伪码位数
#define ITS_LIGHTSUPPLY_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 21)	//车牌亮度补偿
#define ITS_CAPTURECOUNT_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 22)	//抓拍张数
#define ITS_LINEPRESSPERMILLAGE_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 23)	//设置车道内车辆轮廓压线千分比参数
#define ITS_ITSWORDOVERLAY_CMD_SET								(ITS_EXTRAINFO_CMD_SET_MIN + 24)	//交通专用字符叠加
#define ITS_VIDEODECTECT_NEW_CMD_SET							(ITS_EXTRAINFO_CMD_SET_MIN + 25)	//新增图像检测参数
#define ITS_RADERINFO_CMD_SET									(ITS_EXTRAINFO_CMD_SET_MIN + 26)	//Set roadway rader information
#define ITS_PICCUT_CMD_SET										(ITS_EXTRAINFO_CMD_SET_MIN + 27)	//Picture Cut Infomation
#define ITS_EXTRAINFO_CMD_SET_MAX								(ITS_EXTRAINFO_CMD_SET_MIN + 28)	//最大(已达到最大，不再扩大)

#define ITS_EXTRAINFO_CMD_GET_MIN								 0
//违停项目
#define ITS_ILLEGALPARK_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 0)	    //获得违章停车参数
#define ITS_ILLEGALPARKPARM_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 1)		//获得违章停车标定区域参数
#define ITS_LICENSEOPTIMIZEOTHER_CMD_GET						(ITS_EXTRAINFO_CMD_GET_MIN + 2)		//获得待检索车牌和不可信车牌
#define ITS_OPTIM_CMD_GET										(ITS_EXTRAINFO_CMD_GET_MIN + 3)		//获得车牌优化首汉字
#define ITS_RECOPARAM_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 4)		//获得识别算法参数
#define ITS_ROADWAYENABLE_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 5)		//获得车道
#define ITS_CAMLOCATION_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 6)		//获得设备信息
//智能相机
#define ITS_VIDEODECTECT_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 7)		//图像检测参数
#define ITS_DETECTAREA_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 9)		//轨迹分析检测区域参数
#define ITS_RECOTYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 10)	//算法类型参数
#define ITS_CAMRATYPE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 11)	//相机类型
//交通一体机
#define ITS_REDLIGHTDETECTAREA_CMD_GET							(ITS_EXTRAINFO_CMD_SET_MIN + 12)	//获得红灯检测区域参数
#define ITS_ENABLE_CMD_GET										(ITS_EXTRAINFO_CMD_SET_MIN + 13)	//获得交通相关功能使能协议
#define ITS_VERSIONPRO_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 14)	//获得相机版本信息
#define ITS_DAYNIGHT_CMD_GET									(ITS_EXTRAINFO_CMD_SET_MIN + 15)	//设置交通相关功能使能协议
#define ITS_WORKMODE_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 16)    //获取工作模式
#define ITS_LIGHTINFO_CMD_GET                                   (ITS_EXTRAINFO_CMD_GET_MIN + 17)    //获取信号灯对应的参数
#define ITS_CROSSINFO_CMD_GET	                                (ITS_EXTRAINFO_CMD_GET_MIN + 18)	//获取路口信息参数
#define ITS_AREAINFO_CMD_GET	                                (ITS_EXTRAINFO_CMD_GET_MIN + 19)    //获取增益区域参数
#define ITS_ILLEGALPARKINFO_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 20)	//违停球
#define ITS_SECURITYCODE_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 21)	//设置防伪码位数
#define ITS_LIGHTSUPPLY_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 22)	//车牌亮度补偿
#define ITS_CAPTURECOUNT_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 23)	//抓拍张数
#define ITS_LINEPRESSPERMILLAGE_CMD_GET							(ITS_EXTRAINFO_CMD_GET_MIN + 24)	//设置车道内车辆轮廓压线千分比参数
#define ITS_ITSWORDOVERLAY_CMD_GET								(ITS_EXTRAINFO_CMD_GET_MIN + 25)	//交通专用字符叠加
#define ITS_VIDEODECTECT_NEW_CMD_GET							(ITS_EXTRAINFO_CMD_GET_MIN + 26)	//新增图像检测参数
#define ITS_RADERINFO_CMD_GET									(ITS_EXTRAINFO_CMD_GET_MIN + 27)	//Get roadway rader information
#define ITS_PICCUT_CMD_GET										(ITS_EXTRAINFO_CMD_GET_MIN + 28)	//Picture Cut Infomation
#define ITS_EXTRAINFO_CMD_GET_MAX								(ITS_EXTRAINFO_CMD_GET_MIN + 29)	//最大(已达到最大，不再扩大)

#define ITS_EXTRAINFO_CMD_MIN									0
#define ITS_EXTRAINFO_COMMON_CMD_MIN							(ITS_EXTRAINFO_CMD_GET_MIN + 29)

//ITS 6M zyb add 14.12.05
#define ITS_EXTRAINFO_CMD_TRAFFIC_FLOW							(ITS_EXTRAINFO_COMMON_CMD_MIN + 0)  //ITS Lane Traffic Statistics
#define ITS_EXTRAINFO_CMD_TRAFFICFLOWREPORT						(ITS_EXTRAINFO_COMMON_CMD_MIN + 1)
#define ITS_EXTRAINFO_CMD_ILLEGAL								(ITS_EXTRAINFO_COMMON_CMD_MIN + 2) //ITS Illegal Type
#define ITS_EXTRAINFO_CMD_PICMERGEOVERLAY						(ITS_EXTRAINFO_COMMON_CMD_MIN + 3) //ITS Pictrue Merge Over Lay
#define ITS_EXTRAINFO_CMD_RECOPARAM								(ITS_EXTRAINFO_COMMON_CMD_MIN + 4)
#define ITS_EXTRAINFO_CMD_FTP_UPLOAD							(ITS_EXTRAINFO_COMMON_CMD_MIN + 5)
#define ITS_EXTRAINFO_CMD_CARLOGO_OPTIM							(ITS_EXTRAINFO_COMMON_CMD_MIN + 6)
#define ITS_EXTRAINFO_CMD_LOOP_MODE								(ITS_EXTRAINFO_COMMON_CMD_MIN + 7)
#define ITS_EXTRAINFO_CMD_IPDCAPMODEL							(ITS_EXTRAINFO_COMMON_CMD_MIN + 8)//ipd capture model
#define ITS_EXTRAINFO_CMD_IPDCARPOSITION						(ITS_EXTRAINFO_COMMON_CMD_MIN + 9)//ipd car     position
#define ITS_EXTRAINFO_CMD_MAX									(ITS_EXTRAINFO_COMMON_CMD_MIN + 10)


#define MAX_PRESET_COUNT			16					//违章停车最多预置位数
#define MAX_AREA_COUNT				8					//违章停车最多区域数
#define MAX_PARAM_COUNT				4					//违章停车四边形区域中最多标定位置数
#define MAX_ITS_RULE_NUM			1					//违章停车最大规则数
/************************************************************************/
///*  设置违章停车参数  
/************************************************************************/
//struct ITS_IllegalPark
//{
//	int			iPresetNo;      						//预置位编号
//	int			iAreaNo;								//区域编号
//	int		  	iIllegalParkTime;						//违章停车检测时间
//	int			iTimeRange[MAX_TIMESEGMENT];								//使能时间范围
//	POINT		arrPTArea[MAX_AREA_COUNT];				//区域四个点坐标  iX1,iY1:iX2,iY2:iX3,iY3:iX4,iY4
//} ;

struct ITS_IllegalPark                                  //扩展违停参数（iCheckParkTime&iSensitivity）@120905
{
	int			iPresetNo;      						//预置位编号   最多8个，0-7
	int			iAreaNo;								//区域编号     最多4个，0-3
	int		  	iIllegalParkTime;						//违章停车检测时间  秒为单位
	int			iTimeRange[MAX_TIMESEGMENT];								//使能时间范围
	POINT		arrPTArea[MAX_AREA_COUNT];				//区域四个点坐标  iX1,iY1:iX2,iY2:iX3,iY3:iX4,iY4
	int         iCheckParkTime;                         //停车判断时间
	int         iSensitivity;                           //灵敏度等级
	char		cAreaName[LEN_32];						//区域名称
	int			iEnable;								//区域使能	0未使能 1使能
	int			iRuleID;								//规则ID:0~10，其中0~7是通用规则，8~10:特殊规则,需特殊申请才能使用--zyb add 20150530
	int			iValid;									//此事件检测是否有效--zyb add 20150530
} ;

/************************************************************************/
//  设置违章停车标定区域参数 
/************************************************************************/
struct ITS_IllegalParkParm
{
	int			iPresetNo;      					    //预置位编号
	int			iAreaNo;								//区域编号
	POINT       arrPTParam[MAX_PARAM_COUNT][2];         //标定位置两个点坐标 iAX1,iAY1:iAX2,iAY2;iBX1,iBY1:iBX2,BiY2;iCX1,iCY1:iCX2,iCY2;iDX1,iDY1:iDX2,iDY2
} ;

/************************************************************************/
//  设置待检索车牌和不可信车牌//非本地车牌 
/************************************************************************/
//#define  MAX_MODIFYCHAR_COUNT    8
//struct ITS_LicenseOptimizeOther
//{
//	int			iType;      							//0：待检索汉字；1：不可信汉字
//	int			iCount;									//首汉字数目 最多支持8个
//	char		cModifyChar[MAX_MODIFYCHAR_COUNT][5];	//应设置成邻省车牌首汉字或不可能出现的车牌首汉字。不超过4个字节
//	int			iOtherCharWeight[MAX_MODIFYCHAR_COUNT];	//首汉字优化最低置信度
//} ;


/************************************************************************/
//*  设置精确定位参数 
/************************************************************************/
struct ITS_ExactConfirm
{
	int			iPresetNo;      						//预置位编号
	int			iAreaNo;								//区域编号
	int         iLocalPos1;								//标定块编号
} ;

/************************************************************************/
//*							智能相机参数				
/************************************************************************/

#define		MAX_ITS_DETECTAREA_NUM		16
#define		MAX_ITS_AREA_POINTNUM		16
//130T算法私有参数
typedef struct __tagTITS_Params130T
{
	int			m_iZoomRate;
	int			m_iVehicleWidth;
	int			m_iConfidenceValve;
	int			m_iProportion;
}TITS_Params130T, *PTITS_Params130T;

//ITS图像检测参数
typedef	struct __tagTITS_VDetect
{
	int			m_iEngineType;
	int			m_iEnable;
	int			m_iVedioType;
	int			m_iVedioWidth;
	int			m_iVedioHeight;
	int			m_iVehicleMinSize;
	int			m_iVehicleMaxSize;
	int			m_iModelType;
	int			m_iFrameRateCount;
	TITS_Params130T	m_stParmas130T;
}TITS_VDetect, *PTITS_VDetect;

typedef	struct __tagTITS_VDetect_Ex
{
	int				m_iSize;
	TITS_VDetect	m_tVDetect;
	int				m_iVDetectMotor;	//非机动车检测使能
	int iSceneID;// 场景ID(0~15) 20140203扩展
}TITS_VDetect_Ex, *PTITS_VDetect_Ex;

//ITS图像检测区域参数
#define  MAX_ITS_DETECTAREAPOINT_NUM  15
typedef struct __tagTITS_DetectArea
{ 
	int			m_iRegionID;                      //区域编号  0~11
	int			m_iEnabled;                       //使能标记  0：不启用，1：启用 
	int			m_iPointCount;                    //坐标个数 4~15
	vca_TPoint	m_arrPoint[MAX_ITS_AREA_POINTNUM];//标定位置两个点坐标（最多15个点） iAX1:iAY1,iAX2:iAY2,iAX3:iAY3,iAX4:iAY4,…
	int iSceneID;// 场景ID(0~15) 20140203扩展
}TITS_DetectArea, *LTITS_PDetectArea;

/************************************************************************/
//*  交通相关功能使能参数
/************************************************************************/

#define MAX_ITS_ENABLE_NUM	13
#define MAX_ITS_POWERINPHASEENABLE_NUM	0
#define MAX_ITS_ITSMANUALENABLE_NUM	1
struct ITS_EnalbeParam	
{
	int iType;	    // 功能类型 0--电源同步功能  1--启动手动模式  2--CRC校验功能  3--视频测速功能   4—红灯增益使能   5—ftp使能
							 // 6--图像合成功能  7--人脸识别功能  8--车标识别使能 9--安全带识别使能 10--副驾驶人脸识别功能
	int iEnable;	// 0-不使能；1-使能
};

#define	MAX_ITS_REDLIGHT_DETECTAREA_NUM		8

struct ITS_RedLightDetectArea
{
	int iRegionID;	//红灯区域编号 0-3
	int iEnabled;	//使能标记	0：不启用，1：启用					
	RECT rcStandardArea;	//标定区域位置
	RECT rcReviseArea;		
};

typedef struct __tagITS_RedLightDetectAreaV1
{
	int  iBufSize;                  //根据所需结构体的长度(可自定义)
	int  iRegionID;	                //红灯编号 8个
	int  iEnabled;	                //使能标记	0：不启用，：启用	
	RECT rcStandardArea;	        //标定区域位置
	RECT rcReviseArea;		
	int  iLightType;                //灯盘类型 0-单灯灯盘，1-三灯灯盘，2-五灯灯盘红，3-五灯灯盘绿
	int  iChannelType;              //红灯区域对应的车道类型 车道类型按位设置,0-不启用，1-启用： bit0-直行 bit1-左转 bit2-右转 bit3-掉头
} ITS_RedLightDetectAreaV1, *PITS_RedLightDetectAreaV1;

//add by wd @20130603 路口信息结构体
struct ITS_CrossInfo
{
	int iBufSize;                //根据所需结构体的长度(可自定义)
	char pcCrossingID[LEN_64];       //路口编号  长度不超过63字符
	char pcCrossingName[LEN_64];     //路口名称  长度不超过63字符
	int iSceneID;// 场景ID(0~15) 20140203扩展
	int iUseType;// 应用类型(0-不启用；1-违法停车； 2-违法掉头； 3-违法检测) 20140203扩展
};
//add end

//add by wd @20130620增益区域参数
#define  MAX_AREAINFOPOINT_NUM 6
#define	 MAX_ITS_AREAINFOREGIONID_NUM		8     //区域编号 
#define  MAX_ITS_AREAINFO_TYPE				2		//区域类型
struct ITS_AreaInfo
{
	int iBufSize;                 //根据所需结构体的长度
	int iType;                    //区域类型  0—红灯增益
	int iRegionID;               //区域编号区域ID，0~7
	int iEnabled;                //使能标记 0：不启用，1：启用
	int iCount;                  //坐标个数 4~6
	vca_TPoint  stTPoint[MAX_AREAINFOPOINT_NUM];	         //标定位置两个点坐标（最多6个点）
};
//add end

/************************************************************************
*	锐视相机识别算法参数                                                                     
************************************************************************/
struct ITS_RecoParam 
{
	int iMaxPlateNO;					//最大车牌数
	int iMaxPlateWidth;					//最大车牌宽度
	int iMinPlateWidth;					//最小车牌宽度
};

/************************************************************************
*	锐视相机位置                                                                     
************************************************************************/
struct ITS_CamLocation
{
	char cDeviceVode[LEN_64];								//设备编号
	char cRoadName[LEN_64];									//路口名称
};

//	ITS(智能交通)配置的变量总集
struct ITS_VariableParam
{
	int m_iAgcBlock[MAX_ITS_TIMERANGE];              //时间段测光区域使能
	int m_iFlashLamp[MAX_ITS_TIMERANGE];             //时间段闪光灯使能
	int m_iDetectMode;								 //相机检测模式
	int m_iLoopMode;			  				     //线圈工作模式,0：单线圈；1：双线圈；2：三线圈
	int m_iITSDeviceType;							 //相机外设类型

	//智能相机
	int	m_iITSCamraType;
	//相机版本信息
	char m_strITSVersionPro[1024];	
};


#define CAMERA_PARAM_JPEG_QUALITY			0
#define CAMERA_PARAM_LUT					1

struct TCameraParam
{
	int iParamType;		//参数类型 0:图片质量 1:LUT  其它预留					
	int iParamValue;	//参数值 iParamType=0时：0-100，数值越大质量越好; iParamType=1时：0:不启用;1:启用		
};

/************************************************************************
* 得到设备端连接信息                                                                     
************************************************************************/
#define MAX_CONNECT_COUNT		128

struct TChannelConnectInfo
{
	int iChannelID;					//	取值范围据设备总通道数而定（规则与NVSSDK中相同），数据通道从0开始，命令通道忽略
	char cClientIP[16];				//	客户端IP地址
	int iChannelType;				//通道类型，0代表命令通道，1代表数据通道
	int iNetMode;					//1，TCP； 2，UDP； 3，多播； 4，主动模式
	int iConnectState;				//连接状态，0代表增加连接；  1代表断开连接
	char cUserName[17];				//用户名，最多16个字符
};

struct TTotalConnectInfo
{
	TChannelConnectInfo	connInfo[MAX_CONNECT_COUNT];
};

/************************************************************************
*	平台服务程序列表及控制                                                                     
************************************************************************/
#define MAX_PLATFORM_COUNT			10
#define MAX_PALTFORM_NAME_LENGTH	33

#define PLATFORM_CMD_SET_MIN		0
#define PLATFORM_CMD_SET_RUN		(PLATFORM_CMD_SET_MIN+0)
#define PLATFORM_CMD_SET_MAX		(PLATFORM_CMD_SET_MIN+1)

//#define PLATFORM_CMD_GET_MIN		(PLATFORM_CMD_SET_MAX)			//	考虑下面的扩展兼容性			
#define PLATFORM_CMD_GET_MIN		(1)
#define PLATFORM_CMD_GET_LIST		(PLATFORM_CMD_GET_MIN+0)
#define PLATFORM_CMD_GET_MAX		(PLATFORM_CMD_GET_MIN+1)


struct TPlatformVersion
{
	char cData[LEN_32+1];
};

struct TPlatformApp
{
	char cName[MAX_PLATFORM_COUNT][MAX_PALTFORM_NAME_LENGTH];			//	平台服务程序的名称，最多10个，单个长度最长32字节
	int iState[MAX_PLATFORM_COUNT];										//	各个平台服务程序的状态, 0-停止，1-运行
};

//ATM相关参数
#define ATM_CONFIG_CMD_MIN							0
#define ATM_CONFIG_CMD_ATM_INFO				(ATM_CONFIG_CMD_MIN+0)
#define ATM_CONFIG_CMD_OSD_INFO				(ATM_CONFIG_CMD_MIN+1)
#define ATM_CONFIG_CMD_PROTOCOL_COUNT		(ATM_CONFIG_CMD_MIN+2)
#define ATM_CONFIG_CMD_PROTOCOL_NAME		(ATM_CONFIG_CMD_MIN+3)
#define ATM_CONFIG_CMD_MAX					(ATM_CONFIG_CMD_MIN+4)

#define ATM_PROTOCOL_NAME_LEN 31
#define ATM_PROTOCOL_NAME_COUNT 40
#define ATM_FIELD_COUNT	5
#define ATM_FIELD_LEN	64
#define ATM_CARD_ID_LEN 32

//ATM文件查询相关参数
#define ATM_QUERY_CMD_MIN						0
#define ATM_QUERY_CMD_FIELD				(ATM_QUERY_CMD_MIN+0)
#define ATM_QUERY_CMD_CARD				(ATM_QUERY_CMD_MIN+1)
#define ATM_QUERY_CMD_MAX				(ATM_QUERY_CMD_MIN+2)

//前端录像查询
#define CMD_NETFILE_QUERY_MIN			0
#define CMD_NETFILE_QUERY_FILE			(CMD_NETFILE_QUERY_MIN+0)
#define CMD_NETFILE_QUERY_MAX			(CMD_NETFILE_QUERY_MIN+1)


typedef struct ATM_INFO
{
	int		iSize;									//Size of the structure,must be initialized before used
	int		iInformWay;								//通信方式 0:串口,1:UDP
	char	cProtocolName[ATM_PROTOCOL_NAME_LEN+1];	//协议类型 协议厂家
	char	cSrcIP[LENGTH_IPV4];					//ATM IP地址
	int		iSrcPort;								//ATM 端口号
	char	cDestIP[LENGTH_IPV4];					//设备IP地址 默认0
	int		iDestPort;								//设备端口号
}*PATM_INFO;

typedef struct ATM_OSD_INFO
{
	int				iSize;					//Size of the structure,must be initialized before used
	int 	        iX; 	    			//横坐标
	int             iY; 	    			//纵坐标
	unsigned int	uEnable;				//使能 通道按位取
}*PATM_OSD_INFO;

typedef struct ATM_PROTOCOL_NAME
{
	int		iSize;							//Size of the structure,must be initialized before used
	int		iIndex;							//协议索引
	char	cName[ATM_PROTOCOL_NAME_LEN+1];	//协议名称
}*PATM_PROTOCOL_NAME;

typedef struct ATM_FIELD_QUERY
{
	int				iSize;										//Size of the structure,must be initialized before used
	int          	iType; 										//录像类型 33:ATM
	int     	    iChannel; 									//通道号 从0开始,0xff代表所有
	NVS_FILE_TIME	struStartTime; 								//开始时间
	NVS_FILE_TIME	struStopTime; 								//结束时间
	int     	    iPageSize;									//页大小
	int         	iPageNo;									//页编号
	int             iFiletype;									//文件类型 0:全部,1:视频,2:图片
	int				iDevType;									//设备类型 0:摄像机,1:网络视频服务器,2:网络摄像机,0xff:全部
	char			cOtherQuery[65];							//字符叠加
	int				iTriggerType;								//报警类型 3:端口报警,4:移动报警,5:视频丢失报警,0x7FFFFFFF:无效
	int				iTrigger;									//端口（通道）号
	char			cField[ATM_FIELD_COUNT][ATM_FIELD_LEN+1];	//域查询
}*PATM_FIELD_QUERY;

typedef struct ATM_CARD_QUERY
{
	int				iSize;					//Size of the structure,must be initialized before used
	int          	iType; 					//录像类型 33:ATM
	int     	    iChannel; 				//通道号 从0开始,0xff代表所有
	NVS_FILE_TIME	struStartTime; 			//开始时间
	NVS_FILE_TIME	struStopTime; 			//结束时间
	int     	    iPageSize;				//页大小
	int         	iPageNo;				//页编号
	int             iFiletype;				//文件类型 0:全部,1:视频,2:图片
	int				iDevType;				//设备类型 0:摄像机,1:网络视频服务器,2:网络摄像机,0xff:全部
	char			cOtherQuery[65];		//字符叠加
	int				iTriggerType;			//报警类型 3:端口报警,4:移动报警,5:视频丢失报警,0x7FFFFFFF:无效
	int				iTrigger;				//端口（通道）号
	char			cID[ATM_CARD_ID_LEN+1];	//卡号
	int				iOperate;				//业务类型 0:代表查询,1:取款,2:改密,3:转账,4:存款,5:无卡查询,6:无卡存款,20:其他
	int				iQuantity;				//金额:代表金额数目（分）
	int				iAbnormity;				//异常情况 0:吞钞,1:吞卡
}*PATM_CARD_QUERY;

typedef struct ATM_FILE_DATA
{
	int				iSize;					//Size of the structure,must be initialized before used
	int             iType; 	        		//录像类型 33:ATM
	int 	        iChannel; 	    		//通道号 从0开始,0xff代表所有
	char 		    cFileName[250]; 		//文件名
	NVS_FILE_TIME	struStartTime; 			//开始时间
	NVS_FILE_TIME	struStoptime; 			//结束时间
	int             iFileSize; 	    		//文件大小
	int				iOperate;				//操作类型 1:取款,2:改密,3:转账,4:存款,5:无卡查询,6:无卡存款,20:其他,21:吞钞,22:吞卡
	NVS_FILE_TIME	struOperateTime;		//操作时间
}*PATM_FILE_DATA;

#define  QUERY_MSG_COUNT	5
#define  QUERY_MSG_LEN		68
typedef struct NETFILE_QUERY_V4
{
	int				iSize;										//Size of the structure,must be initialized before used
	int          	iType; 										//录像类型 33:ATM
	int     	    iChannel; 									//通道号 从0开始,0xff代表所有
	NVS_FILE_TIME	struStartTime; 								//开始时间
	NVS_FILE_TIME	struStopTime; 								//结束时间
	int     	    iPageSize;									//页大小
	int         	iPageNo;									//页编号
	int             iFiletype;									//文件类型 0:全部,1:视频,2:图片
	int				iDevType;									//设备类型 0:摄像机,1:网络视频服务器,2:网络摄像机,0xff:全部
	char			cOtherQuery[65];							//字符叠加
	int				iTriggerType;								//报警类型 3:端口报警,4:移动报警,5:视频丢失报警,0x7FFFFFFF:无效
	int				iTrigger;									//端口（通道）号
	int				iQueryType;									//查询类型 0: 基本查询 1:ATM查询 2：ITS查询					
	int				iQueryCondition;							//查询条件 0：按域查询  1：按卡号查询；2：交通查询条件：
	char			cField[QUERY_MSG_COUNT][QUERY_MSG_LEN];		//查询消息
}*PNETFILE_QUERY_V4;


//音频采样率相关参数
#define AUDIO_SAMPLE_CMD_MIN						0			
#define AUDIO_SAMPLE_CMD_SAMPLE				(AUDIO_SAMPLE_CMD_MIN+0)	//设置或获取某通道的采样率
#define AUDIO_SAMPLE_CMD_SAMPLE_COUNT		(AUDIO_SAMPLE_CMD_MIN+1)	//获得某通道支持的采样率个数
#define AUDIO_SAMPLE_CMD_SAMPLE_LIST		(AUDIO_SAMPLE_CMD_MIN+2)	//获得某通道支持的第几个采样率，对应结构体为AUDIO_SAMPLE
#define AUDIO_SAMPLE_CMD_MAX				(AUDIO_SAMPLE_CMD_MIN+3)

#define MAX_AUDIO_SAMPLE_NUM 16

typedef struct AUDIO_SAMPLE
{
	int				iSize;					//Size of the structure,must be initialized before used
	int				iIndex;					//采样率索引
	int				iSample;				//音频采样率
}*PAUDIO_SAMPLE;

/*-------------------------------------------------------*/
//系统类型参数
#define	SYSTEMTYPE_WORKMODE		0		//	工作模式	
#define SYSTEMTYPE_DEVPROD		1		//	设备制造商
typedef struct __tagSYSTEMTYPE
{
	int m_iSize;
	int m_iWorkMode;					//	不修改此参数时赋0x7FFFFFFF
	int m_iDevProducter;
}SYSTEMTYPE, *LPSYSTEMTYPE;


//交通相关
//#define MAX_ROADWAY_COUNT           4          //最大车道数
//#define MAX_LOOP_COUNT              4           //车道内最大线圈数
//#define DAY_OR_NIGHT                2          //0---白天，1---晚上
//
//#define LIGHT_COUNT							4					//信号灯数
//#define LIGHT_COM_COUNT						4					//信号灯串口数
//#define CAPTURE_PLACE_COUNT					3					//车道对应的抓拍位置数目


struct TImgDisposal	//图片效果
{
	int iChannelID;
	int iStartUp;		//图片效果处理是否启用标识, 0：不启用 1：启用
	int iQuality;		//质量,	范围：0到100
	int iSaturation;	//饱和度,范围：0到255
	int iBrighten;		//亮度,范围：0到255
	int iContrast;		//对比度,范围：0到255
	int iGamma;			//伽马值,范围：0到50	
	int iAcutance;		//锐度,范围：0到255
	int iImgEnhanceLevel;//图像增强级别,范围：0～3					
};

struct TECOPChannelParam	//车道相关参数
{
	TImgDisposal tImgDisposal;
	int iRecognizeEnable;
	int iWaterMarkEnable;
};

//信号灯对应的参数
struct TITSLightInfo
{
	int iLightID;						//信号灯编号 0-3	
	int iTimeInterval;					//信号灯时间间隔 单位秒	
	int iTimeAcceptDiff;				//信号灯时间容忍值 单位秒					
};
//扩展信号灯参数
//扩展信号灯参数
typedef	struct __tagTITSLightInfoEx
{
	int				iBufSize;
	TITSLightInfo	m_stLightInfo;			//其中 信号灯编号 0-7	
	int				iChannelType;			//信号灯对应的车道类型  车道类型按位设置,0-不启用，1-启用：bit0-直行 bit1-左转 bit2-右转 bit3-掉头
	int				iPhase;					//红灯相位值   相位值 0~360
	int				iDetectType;			//检测红灯还是绿灯 0—红灯　1—绿灯
	int				m_iYellowLightTime;		//黄灯持续时间, 单位ms：0-100000ms----->add new
	int				m_iLightEnhanceLevel;	//红灯增益等级;增益范围：1~255；0-保留；
}TITSLightInfoEx,LPTITSLightInfoEx;

struct TECOPParam
{
	TECOPChannelParam tChannel[MAX_ROADWAY_COUNT];
	int iSystemType;	//系统类型
	//0：调试
	//3：卡口
	//4：电警	
	int iLockRet;		//获取注册结果
	//bit0：识别狗
	//bit1：智能交通加密狗
	//0：未注册，1：注册
	TITSLightInfo tLightInfo[LIGHT_COUNT];
};

typedef int				VIDEO_METHOD;
#define VIDEO_MODE_HAND			0x00
#define VIDEO_MODE_AUT			0x01

#define MAX_MONITOR_DESCLEN     512
typedef struct MONITOR_INFO
{
	char        cDriverDesc[MAX_MONITOR_DESCLEN];
	char        cDriverName[MAX_MONITOR_DESCLEN];	
	RECT		rect;
}*PMONITOR_INFO;

typedef struct
{
	int         m_iStructSize;        //结构体大小
	char        m_cVersion[32];       //服务器版本号
	char		m_cUIVersion[32];	  //UI服务器版本号
	char		m_cSlaveVersion[32];  //从片版本号
	char        m_cPlugInVersion[32]; //外挂版本号 
	char		m_cSCMVersion[32];	  //单片机版本号
	char 		m_cSCGuiVersion[32];  //UI版本号
}SERVER_VERSION;

/************************************************************************/
/*							串口格式设置                                */
/************************************************************************/
typedef struct COMFORMAT
{
	int				iSize;				//Size of the structure,must be initialized before used
	int				iComNo;				//串口编号
	char			cDeviceName[32];	//协议名称
	char			cComFormat[32];		//格式串 9600,n,8,1
	int				iWorkMode;			//工作模式 1:协议控制,2:透明通道,3:行业预留,4:7601B串行报警主机,5:485键盘
	int				iComType;			//串口类型 0:485,1:232,2:422
} *PCOMFORMAT;

/*-------------------------------------------------------*/
//球机高级参数
#define	MAX_DOME_PRESET_NUM			255	//	最大预置位编号个数
#define	MAX_DOME_SCAN_NUM			255	//	最大扫描编号个数
#define	MAX_DOME_CURISE_NUM			255	//	最大巡航编号个数
#define	MAX_DOME_PATTERN_NUM		255	//	最大模式路径编号个数
#define	MAX_DOME_ZONES_NUM			255	//	最大区域提示编号个数

#define TITLETYPE_RESERVED			0	//	预留
#define TITLETYPE_PRESET			1	//	预置位
#define TITLETYPE_SCAN				2	//	扫描
#define TITLETYPE_CRUISE			3	//	巡航
#define TITLETYPE_PATTERN			4	//	模式路径
#define TITLETYPE_ZONES				5	//	区域提示

#define	MAX_TITLE_LEN				31

#define	CMD_DOME_ADV_SETTITLE		0	//	设置球机标题
typedef struct __tagDOME_TITLE
{
	int		m_iStructSize;				//	结构体size
	int		m_iType;					//	标题类型
	int		m_iNum;						//	标题编号
	char	m_cTitle[MAX_TITLE_LEN+1];	//	标题名
}DOME_TITLE, *LPDOME_TITLE;

/*-------------------------------------------------------*/
//cb@1212068124: SET GET的CMD使用同一个名字，使代码可读性和易用性更好；
#define IPC_CMD_MIN 0
#define IPC_CMD_SENSOR_VOLTAGE       (IPC_CMD_MIN + 0)
#define IPC_CMD_MAX                  (IPC_CMD_MIN + 1)

typedef struct  
{
	int		iType; 
	int		iMold;
	float   fValue;
	int     iReserved;
}HardWare_Param;

typedef struct
{
	unsigned int uiTextColor;
	unsigned char ucOSDText[LENGTH_CHANNEL_TITLE+1];
}OSD_TEXT;

//假日计划相关参数
#define HOLIDAY_PLAN_CMD_MIN						0			
#define HOLIDAY_PLAN_CMD_SCHEDULE			(HOLIDAY_PLAN_CMD_MIN+0)	//设置或获取假日计划录像模板
#define HOLIDAY_PLAN_CMD_MAX				(HOLIDAY_PLAN_CMD_MIN+1)
#define MAX_HOLIDAY_PLAN_SCHEDULE					10

typedef struct
{
	unsigned short iYear;
	unsigned short iMonth;
	unsigned short iDay;
	unsigned short iWeekOfMonth;
	unsigned short iDayOfWeek;
}HOLIDAY_TIME;

typedef struct
{
	int iPlanID;		//计划模板ID,[0,9]
	int iEnable;		//是否使能,1:使能 0:不使能
	char cPlanName[33]; //计划模板名称
	int iMode;			//时间格式,0:按日期(年月日) 1:按星期(月周 星期) 2:按月份(月日)
	HOLIDAY_TIME tStartTime;	//开始时间
	HOLIDAY_TIME tEndTime;		//结束时间
}HOLIDAYPLAN_SCHEDULE;

//M7.6之后设备返回的错误ID		EC:ERROR CODE
//音视频
#define EC_AV_SWITCHOVER_CHANNEL			0x1000	//（数字通道）切换通道类型失败
#define EC_AV_QUERY_FILE					0x1010	//（断电续传）查询不到传输文件
//字符叠加
#define EC_OSD_LOGO_FORMAT					0x2001	//（字符叠加）传输的logo图片格式不对
#define EC_OSD_LOGO_DATA					0x2002	//（字符叠加）传输的logo图片数据错误
//串口PTZ
#define EC_SERIAL_PORT_PTZ					0x3000
//异常
#define EC_EXCEPTION						0x4000
//报警
#define EC_ALARM							0x5000
//存储
#define EC_STORAGE_LOCK_FILE				0x6000	//（加解锁）加锁文件失败
#define EC_STORAGE_UNLOCK_FILE				0x6001	//（加解锁）解锁文件失败
#define EC_STORAGE_REDUNDANCY				0x6010	//（存储策略）没有启动盘组策略，无法启动冗余录像
#define EC_STORAGE_HOLIDAY_TIME				0x6020	//（假日计划）假日模板存在时间冲突
//网络服务
#define EC_NET_SERVICE						0x7000	
//用户
#define EC_LOGON_USERNAME					0x8000	//（登录）用户名不存在
#define EC_LOGON_PASSWORD					0x8001	//（登录）密码错误
#define EC_LOGON_DECRYPT_PWD				0x8002	//（登录）解密密码不对
#define EC_LOGON_AUTHORITY					0x8010	//（操作）用户权限不足
#define EC_LOGON_AUTHORITY_GROUP			0x8020	//（修改用户权限）用户所在组不够，不能配置高权限
//PU设置
#define EC_PU								0x9000
//磁盘管理
#define EC_DISK_RECORDING					0xA000	//(用途)正在录像，无法修改此盘
#define EC_DISK_MEMORY						0xA001	//(用途)盘组中录像磁盘不足
#define EC_DISK_TYPE						0xA002	//(用途)磁盘类型不支持此用途
#define EC_DISK_NO_DISK						0xA010	//(盘组）此盘组没有录像盘
#define EC_DISK_NO_SETTING					0xA011	//（盘组）此盘组未设置任何磁盘
#define EC_DISK_REPEAT_ADD					0xA012	//（盘组）重复添加同一磁盘到不同盘组
#define EC_DISK_NO_RECORD_CHANNEL			0xA013	//（盘组）此盘组中未添加任何录像通道
#define EC_DISK_RECORD_QUOTA_BIG			0xA020	//（配额）录像配额过大
#define EC_DISK_IMAGE_QUOTA_BIG				0xA021	//（配额）图片配额过大
#define EC_DISK_DEL_LOCK_FILE				0xA022	//（配额）修改配额策略时，无法删除加锁文件
//系统管理
#define EC_SYSTEM							0xB000	
//通信
#define EC_COM								0xC000
//网络连接
#define EC_NET_CONNECTION					0xD000	
//智能分析
#define EC_VCA								0xE000	
#define EC_VCA_UNSUPPORT_SIZE				0xE001	//数字通道智能分析功能目前不支持的分辨率
#define EC_VCA_VDEC_VENC_FAILED				0xE002  //数字通道启用智能分析编解码通道失败
#define EC_VCA_VCPRIOR_FAILED				0xE003  //vc通道已经开启，无法启动数字通道本地智能分析
#define EC_VCA_UNSUPPORT_FAILED				0xE004  //不支持启用本地智能分析
#define EC_VCA_MAX2CHN_FAILED				0xE005  //本地智能分析只能开启前2路
#define EC_VCA_UNSUPPORT_H265_FAILED		0xE006  //本地智能分析不支持H265	
#define EC_VCA_PREVIEW_FAILED				0xE007  //预览性能受限不支持开启本地智能分析
//ATM
#define EC_ATM								0xF000	
//交通相关
#define EC_ITS								0x10000	
//DZ相关
#define EC_DZ								0x11000	
//通用使能
#define EC_COMMON_ENABLE					0x12000


//M7.6之后设备新增通用使能ID		CI:COMMON ID
#define CI_ALARM_MOTION_DETECT				0x5000
#define CI_ALARM_VIDEO_COVER				0x5001

#define CI_NET_SERVICE_SNMP					0x7000
#define CI_NET_SERVICE_SMTP					0x7001

#define CI_STORAGE_DISK_GROUP				0xA000
#define CI_STORAGE_DISK_QUOTA				0xA001
#define CI_COMMON_ID_RAID					0xA002	//RAID功能使能状态

#define CI_VEHICLE_GPS_CALIBRATION			0x12001
#define CI_VEHICLE_ALARM_THRESHOLD			0x12002
#define CI_VEHICLE_SHUTDOWN_THRESHOLD		0x12003

#define CI_NET_CONNECT_INFO					0xD001  //底层socket发送分包的最大单元

#define CI_COMMON_ID_EIS					0x1001	//电子防抖
#define CI_COMMON_ID_SVC					0x1002	//svc
#define CI_COMMON_ID_VO_ENABLE				0x1003	//Video Output Control
#define CI_COMMON_ID_DENOISE				0x1004	//audio denoise	 |zyb add 20141223
#define CI_COMMON_ID_TRENDS_ROI				0x1005	//trends ROI	 |zyb add 20150304

#define CI_COMMON_ID_VIDEO_REVERSE			0x1006	//video reverse			
 
#define CI_COMMON_ID_ANR					0x12010	//ANR使能
#define CI_COMMON_ID_WORKDEV_BACKUP			0x12011	//工作机热备使能
#define CI_COMMON_ID_FORBIDCHN				0x12012	//禁用通道数
#define CI_COMMON_ID_EVENT					0x12013	//事件模板使能
#define CI_COMMON_ID_TELNET					0x12014	//telnet使能
#define CI_COMMON_ID_DISK					0x12015	//光盘弹盘和封盘状态

#define CI_HASH_CHECK						0x6002	//哈希校验,0-不使能，1-使能
#define CI_COMMON_ID_MAKE_AUDIO_FILE		0x6003	//音频文件生成使能，与通道有关
#define CI_COMMON_ID_BURN_AUDIO_FILE		0x6004	//音频文件刻录使能
#define CI_COMMON_ID_BACK_AUDIO_FILE		0x6005	//音频文件备份使能
#define CI_COMMON_ID_BURNFILE_FORMAT		0x6006	//Video Record File Format

#define CI_COMMON_ID_RTSP_CHECK				0x7002 	//RTSP校验使能

#define CI_COMMON_ID_FAN_CONTROL			0xB000	//风扇远程控制
#define CI_COMMON_ID_FAN_TEMP_CONTROL		0xB001	//风扇温控，实际数值：温度取值-100到100（软件取值后减1000之后除以10，精度0.1）
													//例：-50.5 摄氏度（ -50.5×10 + 1000 = 495），网络发送495
#define CI_COMMON_ID_WHTITELIGHT_ENABLE		0xB002	//white light is enable
//OSD
#define CI_COMMON_ID_OSD_DOT_MATRIX			0x2001	
#define CI_COMMON_ID_OSD_VECTOR				0x2002	
//ITS 6M zyb add 14.12.05
#define CI_ITS_COMMON_ID					0x10000
#define CI_COMMON_ID_ITS_SIGNAL_LIGHT		0x10001
#define CI_COMMON_ID_ITS_BUSINESS			0x10002	//ITS Business Enable
#define CI_COMMON_ID_ITS_ILLEGAL_PARK		0x10003	//ITS Illegal parking

#define CI_COMMON_ID_NVR_LOCAL_VCA			0xE000	//NVR Local VCA 

//add by wd @20130621
//相机抓拍分辨率结构体 
struct JPEGSizeInfo
{
	int iBufSize;                 //根据所需结构体的长度
	int iChannelNo;              //通道号 0~n-1
	int iWidth;                   //抓拍图片宽  宽，像素值
	int iHeight;                 //抓拍图片高  高，像素值
};
//add end

//下载相关参数
#define DOWNLOAD_FLAG_MIN							0
#define DOWNLOAD_FLAG_FIRST_REQUEST		(DOWNLOAD_FLAG_MIN+0)
#define DOWNLOAD_FLAG_OPERATE_RECORD	(DOWNLOAD_FLAG_MIN+1)
#define DOWNLOAD_FLAG_BREAK_CONTINUE	(DOWNLOAD_FLAG_MIN+2)
#define DOWNLOAD_FLAG_MAX				(DOWNLOAD_FLAG_MIN+3)

#define DOWNLOAD_CMD_MIN							0
#define DOWNLOAD_CMD_FILE				(DOWNLOAD_CMD_MIN+0)
#define DOWNLOAD_CMD_TIMESPAN			(DOWNLOAD_CMD_MIN+1)
#define DOWNLOAD_CMD_CONTROL			(DOWNLOAD_CMD_MIN+2)
#define DOWNLOAD_CMD_FILE_CONTINUE		(DOWNLOAD_CMD_MIN+3)
#define DOWNLOAD_CMD_MAX				(DOWNLOAD_CMD_MIN+4)

typedef struct
{
	int				m_iSize;			//结构体大小
	char            m_cRemoteFilename[255];   //前端录像文件名
	char			m_cLocalFilename[255];	  //本地录像文件名
	int				m_iPosition;		//文件定位时,按百分比0～100;断点续传时，请求的文件指针偏移量
	int				m_iSpeed;			//1，2，4，8，控制文件播放速度, 0-暂停
	int				m_iIFrame;			//只发I帧 1,只播放I帧;0,全部播放					
	int				m_iReqMode;			//需求数据的模式 1,帧模式;0,流模式					
	int				m_iRemoteFileLen;	//	如果本地文件名不为空，此参数置为空
	int				m_iVodTransEnable;		//使能
	int				m_iVodTransVideoSize;	//视频分辨率
	int				m_iVodTransFrameRate;   //帧率
	int				m_iVodTransStreamRate;  //码率
}DOWNLOAD_FILE;

typedef struct
{
	int				m_iSize;			//结构体大小
	char			m_cLocalFilename[255]; //本地录像文件名
	int				m_iChannelNO;		//通道号
	NVS_FILE_TIME	m_tTimeBegin;		//开始时间
	NVS_FILE_TIME	m_tTimeEnd;			//结束时间
	int				m_iPosition;		//按时间点定位，>100
	int				m_iSpeed;			//1，2，4，8，控制文件播放速度, 0-暂停
	int				m_iIFrame;			//只发I帧 1,只播放I帧;0,全部播放
	int				m_iReqMode;			//需求数据的模式 1,帧模式;0,流模式
	int				m_iVodTransEnable;		//使能
	int				m_iVodTransVideoSize;	//视频分辨率
	int				m_iVodTransFrameRate;   //帧率
	int				m_iVodTransStreamRate;  //码率
}DOWNLOAD_TIMESPAN;

typedef struct
{
	int				m_iSize;			//结构体大小
	int				m_iPosition;		//0～100，定位文件播放位置；-1，不进行定位
	int				m_iSpeed;			//1，2，4，8，控制文件播放速度, 0-暂停
	int				m_iIFrame;			//只发I帧 1,只播放I帧;0,全部播放
	int				m_iReqMode;			//需求数据的模式 1,帧模式;0,流模式
}DOWNLOAD_CONTROL;

//自动化调试相关协议
#define CMD_AUTOTEST_MIN                    0
#define	CMD_AUTOTEST_RESERVED 				(CMD_AUTOTEST_MIN+0)      //预留
#define	CMD_AUTOTEST_SETMACADDR				(CMD_AUTOTEST_MIN+1)	  //设置MAC地址； 
#define	CMD_AUTOTEST_LAN					(CMD_AUTOTEST_MIN+2)	  //调试网卡
#define	CMD_AUTOTEST_AUDIOIN				(CMD_AUTOTEST_MIN+3)      //调试音频输入；
#define	CMD_AUTOTEST_VIDEOIN				(CMD_AUTOTEST_MIN+4)	  //调试视频输入；
#define	CMD_AUTOTEST_AUDIOOUT				(CMD_AUTOTEST_MIN+5)	  //调试音频输出；
#define	CMD_AUTOTEST_VIDEOOUT				(CMD_AUTOTEST_MIN+6)	  //调试视频输出；
#define	CMD_AUTOTEST_MICIN					(CMD_AUTOTEST_MIN+7)	  //调试MIC输入；
#define	CMD_AUTOTEST_SPEAKER				(CMD_AUTOTEST_MIN+8)	  //调试SPEAKER输出；
#define	CMD_AUTOTEST_VIDEOADJUST			(CMD_AUTOTEST_MIN+9)	  //调试视频调节；协议为：AUTOTEST_ADADJUST
#define	CMD_AUTOTEST_USB					(CMD_AUTOTEST_MIN+10)     //调试USB口；
#define	CMD_AUTOTEST_SATA					(CMD_AUTOTEST_MIN+11)	  //调试SATA口；
#define	CMD_AUTOTEST_ALARMIN				(CMD_AUTOTEST_MIN+12)	  //调试报警输入端口；
#define	CMD_AUTOTEST_ALARMOUT				(CMD_AUTOTEST_MIN+13)	  //调试报警输出端口；
#define	CMD_AUTOTEST_SERIAL					(CMD_AUTOTEST_MIN+14)	  //调试串口；
#define	CMD_AUTOTEST_RTC			   		(CMD_AUTOTEST_MIN+15)	  //调试时钟芯片；
#define	CMD_AUTOTEST_VGADETECTIVE   		(CMD_AUTOTEST_MIN+16)	  //调试VGA信号侦测；设备回
#define	CMD_AUTOTEST_HDMIDETECTIVE			(CMD_AUTOTEST_MIN+17)	  //调试HDMI信号侦测；设备回
#define	CMD_AUTOTEST_RESETDETECTIVE			(CMD_AUTOTEST_MIN+18)	  //调试复位信号侦测；设备回
#define	CMD_AUTOTEST_FORMATDISK				(CMD_AUTOTEST_MIN+19)	  //格式化磁盘；
#define	CMD_AUTOTEST_BACKUPSYSTEM			(CMD_AUTOTEST_MIN+20)	  //备份系统；
#define	CMD_AUTOTEST_ENABLEGUIDE			(CMD_AUTOTEST_MIN+21)	  //启用开机向导；

#define CMD_AUTOTEST_IRIS					(CMD_AUTOTEST_MIN+22)	  //光圈校正；
#define CMD_AUTOTEST_BADPOINTS				(CMD_AUTOTEST_MIN+23)	  //坏点校正；
#define CMD_AUTOTEST_IRCUT					(CMD_AUTOTEST_MIN+24)	  //IRCUT校正；
#define CMD_AUTOTEST_SDCARD					(CMD_AUTOTEST_MIN+25)	  //SD卡校正；
#define CMD_AUTOTEST_VERIFYTIME				(CMD_AUTOTEST_MIN+26)	  //时间校正；
#define CMD_AUTOTEST_CALIBRATEVIDEOBRIGHTNESS	(CMD_AUTOTEST_MIN+27) //亮度差异校正；
#define CMD_AUTOTEST_POWER_SYNC				(CMD_AUTOTEST_MIN+28)	  //电源同步检测；
#define AUTOTEST_AGGING_RESULT				(CMD_AUTOTEST_MIN+29)	  //设备老化结果；
#define AUTOTEST_CREATKEYFILE				(CMD_AUTOTEST_MIN+30)	  //检测Key文件；
#define CMD_AUTOTEST_ANALOG					(CMD_AUTOTEST_MIN+31)	  //模拟量测试；

#define AUTOTEST_FOCUSLIGHT					(CMD_AUTOTEST_MIN+32)	  //聚焦指示灯测试；
#define AUTOTEST_WHITELIGHT					(CMD_AUTOTEST_MIN+33)	  //白光灯调试；
#define AUTOTEST_LINEIN						(CMD_AUTOTEST_MIN+34)	  //调试LineIn；
#define AUTOTEST_DC							(CMD_AUTOTEST_MIN+35)	  //调试DC光圈；
#define AUTOTEST_PIRIS						(CMD_AUTOTEST_MIN+36)	  //调试P-iris；
#define AUTOTEST_CAMERARESET				(CMD_AUTOTEST_MIN+37)	  //调试镜头复位；
#define AUTOTEST_SWITCHLAN					(CMD_AUTOTEST_MIN+38)     //切换UI语言；
#define AUTOTEST_WIFI						(CMD_AUTOTEST_MIN+39)     //调试无线；
#define AUTOTEST_KEYPRESS					(CMD_AUTOTEST_MIN+40)     //调试五项按键；

#define AUTOTEST_VIDEOSIZE					(CMD_AUTOTEST_MIN+41)	  //最大分辨率调试；
#define AUTOTEST_IICLINE					(CMD_AUTOTEST_MIN+42)	  //I2C线路测试；
#define AUTOTEST_INSIDELIGHT				(CMD_AUTOTEST_MIN+43)	  //内置灯测试；
#define AUTOTEST_OUTSIDELIGHT				(CMD_AUTOTEST_MIN+44)	  //补光灯测试
#define	CMD_AUTOTEST_END					(CMD_AUTOTEST_MIN+100)	  //调试结束；
#define	CMD_AUTOTEST_MAX					(CMD_AUTOTEST_MIN+101)

#define MAX_AUTOTEST_ID     CMD_AUTOTEST_MAX

typedef struct
{
	int     iTestParam[5];
	char    cTestParam[65];
}strAutoTest_Para;

#define MAX_HD_TEMPLATE_NUMBER	8

//用户自定义插入数据
#define STREAMDATA_CMD_MIN		                0
#define	STREAMDATA_CMD_USER_DEFINE				STREAMDATA_CMD_MIN + 1
#define STREAMDATA_CMD_MAX						STREAMDATA_CMD_MIN + 1
#define MAX_INSERT_STREAM_LEN					64

#define INSERTDATA_FLAG_MIN						0
#define INSERTDATA_MAIN_STRAM					INSERTDATA_FLAG_MIN + 1
#define INSERTDATA_SUB_STRAM					INSERTDATA_FLAG_MIN + 2
#define INSERTDATA_MAIN_SUB						INSERTDATA_FLAG_MIN + 3
#define INSERTDATA_FLAG_MAX						INSERTDATA_FLAG_MIN + 4
typedef struct __tagTStreamData
{
	int  iSize;				//结构体大小
	char cStreamData[MAX_INSERT_STREAM_LEN];
	int  iStreamLen;
} TStreamData, *PTStreamData;

#define DOME_PTZ_TYPE_MIN  1
#define DOME_PTZ_TYPE_PRESET_FREEZE_UP  		(DOME_PTZ_TYPE_MIN +0)
#define DOME_PTZ_TYPE_AUTO_FLIP 	 			(DOME_PTZ_TYPE_MIN +1)
#define DOME_PTZ_TYPE_PRESET_SPEED_LEVE			(DOME_PTZ_TYPE_MIN +2)
#define DOME_PTZ_TYPE_MANUL_SEPPD_LEVEL			(DOME_PTZ_TYPE_MIN +3)
#define DOME_PTZ_TYPE_WAIT_ACT             		(DOME_PTZ_TYPE_MIN +4)
#define DOME_PTZ_TYPE_INFRARED_MODE 			(DOME_PTZ_TYPE_MIN +5)
#define DOME_PTZ_TYPE_SCALE_ZOOM				(DOME_PTZ_TYPE_MIN +6)
#define DOME_PTZ_TYPE_LINK_DISJUNCTOR 			(DOME_PTZ_TYPE_MIN +7)
#define DOME_PTZ_TYPE_MAX			 			(DOME_PTZ_TYPE_MIN +8)
typedef struct
{
	int iSize;
	int iType;       		//类型
	int iAutoEnable; 		//0--不使能，1--使能
	int iParam1;			//参数
							//1--启用预置位冻结：未使用
							//2--启用自动翻转：未使用
							//3--预置位速度等级：0--低，1--中，2--高
							//4--手控速度等级：0--低，1--中，2--高
							//5--启用待机动作：具体数值：30、60、300、600、1800（单位：秒）
							//6--红外灯模式：0--手动，1--自动
	int iParam2;    		//参数
							//1--启用预置位冻结：未使用
							//2--启用自动翻转：未使用
							//3--预置位速度等级：未使用
							//4--手控速度等级：未使用
							//5--启用待机动作：0--预置位，1--扫描，2--巡航，3--模式路径
							//6--红外灯模式："0--手动时，代表红外灯亮度，具体数值：[0,10]；
								//1--自动时，代表红外灵\敏度，具体数值：0-最低，1-较低，2-标准，
								//3-较高，4-最高；"
	int iParam3;	//预留
	int iParam4;	//预留	
}DOMEPTZ;

/*****************************************************************************/
#define GET_USERDATA_INFO_MIN                            (0)                           
#define GET_USERDATA_INFO_TIME							 (GET_USERDATA_INFO_MIN )		//获得用户数据中的时间信息
#define GET_USERDATA_INFO_OSD							 (GET_USERDATA_INFO_MIN +1)		//获得用户数据中的OSD信息
#define GET_USERDATA_INFO_GPS                            (GET_USERDATA_INFO_MIN +2)		//获得用户数据中的GPS信息
#define GET_USERDATA_INFO_VCA                            (GET_USERDATA_INFO_MIN +3)		//获得用户数据中的VCA信息
#define GET_USERDATA_INFO_USER_DEFINE                    (GET_USERDATA_INFO_MIN +4)		//获得用户数据中的VCA信息
#define GET_USERDATA_INFO_MAX                            (GET_USERDATA_INFO_MIN +4)	
/*****************************************************************************/

//广播消息ID
#define MSG_VEHICLE_GPS_CALIBRATION				0x12001		//GPS校时 iMsgValue(0:禁用,1:启用)
#define MSG_VEHICLE_VOLTAGE						0x12002		//iMsgValue(表示电压值)
#define MSG_VEHICLE_TEMPERATURE					0x12003		//iMsgValue(表示温度值)
#define MSG_VEHICLE_SATELLITE_NUM				0x12004		//iMsgValue(表示卫星个数)
#define MSG_VEHICLE_SIGNAL_INTENSITY			0x12005		//iMsgValue(表示GPS信号强度)
#define MSG_VEHICLE_GPS_MODULE_TYPE				0x12006		//GPS模块类型 iMsgValue(0:无模块,1:GPS,2:北斗)
#define MSG_VEHICLE_ALARM_THRESHOLD				0x12007		//低压报警阈值
#define MSG_VEHICLE_SHUTDOWN_THRESHOLD			0x12008		//低压关机阈值

#define MSG_VALUE_MAX_LEN 64
typedef struct  
{
	int iMsgID;								//消息ID
	int iChannelNo;							//通道号
	int iMsgValue;							//消息附带参数
	char cMsgValue[MSG_VALUE_MAX_LEN];		//消息附带参数
}BROADCAST_MSG,*PBROADCAST_MSG;

//模块能力ID
#define MODULE_CAP_MIN				(0) 
#define MODULE_CAP_VEHICLE	(MODULE_CAP_MIN+0)
#define MODULE_CAP_MAX		(MODULE_CAP_MIN+1)

//车载模块能力
#define MODULE_CAP_VEHICLE_GPS_OVERLAY			0x1
#define MODULE_CAP_VEHICLE_POWER_DELAY			0x2
#define MODULE_CAP_VEHICLE_ALARM_THRESHOLD		0x4
#define MODULE_CAP_VEHICLE_SHUTDOWN_THRESHOLD	0x8

//模拟485键盘控制指令
#define KEYBOARD_CTRL_MIN			0
#define KEYBOARD_CURRENT_SCREEN		KEYBOARD_CTRL_MIN + 0 	//设置UI选中窗口，Value为UI窗口号
#define KEYBOARD_SINGLE_SCREEN 		KEYBOARD_CTRL_MIN + 1 	//单屏显示UI窗口，Value预留
#define KEYBOARD_PRESET_CALL		KEYBOARD_CTRL_MIN + 2 	//从单屏显示恢复，Value未使用
#define KEYBOARD_SCREEN_RRSTORE 	KEYBOARD_CTRL_MIN + 3 	//调用预置位,Value为预置位号
#define KEYBOARD_CTRL_MAX			KEYBOARD_CTRL_MIN + 4

#define TTEMPLATE_CMD_MIN				0
#define TTEMPLATE_CMD_SMART	(TTEMPLATE_CMD_MIN+0)   //设置智能录像模板
#define TTEMPLATE_CMD_VIDEO	(TTEMPLATE_CMD_MIN+1)   //设置智能录像参数模板
#define TTEMPLATE_CMD_MAX	(TTEMPLATE_CMD_MIN+2)

#define SMART_TTEMPLATE_MAX_NUM	4
typedef struct  
{
	int iWeek;								//星期日到星期六为～，iWeekday=7，代表假日计划
	int iIndex[SMART_TTEMPLATE_MAX_NUM];		//模板编号1-8，-不启用，-8代表模板-模板
}SMART_TEMPLATE,*PSMART_TEMPLATE;

typedef struct  
{
	int iIndex;			//模板编号
	int iType;			//参数类型
	int iValue;			//参数值
}VIDEO_TEMPLATE,*PVIDEO_TEMPLATE;

//*****VIDEO_TEMPLATE对应的type和value******/
// 1--编码方式	0，H.264；，M-JPEG；，MPEG4
// 2--编码Profile 0:baseline,1:main,2:high
// 3--分辨率	详见分辨率页
// 4--帧率	1～
// 5--压缩模式	0，CBR；，VBR
// 6--码率	单位为KBytes/s，如kbps的码率，此处应置(除以)
// 7--画面质量	4～，越小质量越高
// 8--I帧帧率	0-100
// 9--码流类型	3，音视频符合流；，音频流；，视频流
// 10--音频编码算法	AUDIO_CODEC_FORMAT_G711A   = 1,   /*G.711 A率*/
//					AUDIO_CODEC_FORMAT_G711Mu  = 2,   /*G.711 Mu率*/
//					AUDIO_CODEC_FORMAT_ADPCM   = 3,   /*ADPCM */
//					AUDIO_CODEC_FORMAT_G726    = 4,   /*G.726 */
//					AUDIO_CODEC_FORMAT_AAC_LC  = 22---31,   /*AAC */预留一个区间给AAC用于扩展
//					AUDIO_CODEC_FORMAT_BUTT

//add by 20131022
#define DEVICE_STATE_MIN            0
#define DEVICE_STATE_BRIGHT			(DEVICE_STATE_MIN)    //亮度
#define DEVICE_STATE_ACUTANCE		(DEVICE_STATE_MIN+1)  //锐度
#define DEVICE_STATE_SYSTEM			(DEVICE_STATE_MIN+2)  //系统
#define DEVICE_STATE_MAX			(DEVICE_STATE_MIN+2)  

#define NVS_TIME NVS_FILE_TIME
typedef struct __tagSystemState
{
	int iSize;
	int iCamera;				//摄像机状态
	int iHLimit;				//水平限位
	int iVLimit;				//垂直限位
	int iInterface;				//接口模组
	int iTSensor;				//温度传感器
	int temperature;			//球机温度
	int itemperatureScale;		//温度单位
	NVS_TIME strPublishData;		//发布日期
}TSystemState, *pTSystemState;

#define NET_CLIENT_MIN						0	
#define NET_CLIENT_DOME_MENU				(NET_CLIENT_MIN + 0)	//球机菜单参数
#define NET_CLIENT_DOME_WORK_SCHEDULE		(NET_CLIENT_MIN + 1)	//球机运行模板参数
#define NET_CLIENT_INTERESTED_AREA			(NET_CLIENT_MIN + 2)	//感兴趣区域
#define NET_CLIENT_APPEND_OSD				(NET_CLIENT_MIN + 3)	//附加字符叠加
#define NET_CLIENT_LOGONFAILED_REASON		(NET_CLIENT_MIN + 4)	//登陆失败
#define NET_CLIENT_AUTOREBOOT				(NET_CLIENT_MIN + 5)	//NVR自动重启布防时间
#define NET_CLIENT_IP_FILTER				(NET_CLIENT_MIN + 6)	//IP地址过滤（黑白名单）
#define NET_CLIENT_DATE_FORMATE				(NET_CLIENT_MIN + 7)	//叠加字符日期显示格式
#define NET_CLINET_COLOR2GRAY				(NET_CLIENT_MIN + 8)	//视频彩转灰即时生效
#define NET_CLINET_LANPARAM					(NET_CLIENT_MIN + 9)	//网卡配置功能
#define NET_CLINET_DAYLIGHT_SAVING_TIME		(NET_CLIENT_MIN + 10)	//设置设备夏令时
#define NET_CLINET_NETOFFLINE				(NET_CLIENT_MIN + 11)	//强制断开用户连接
#define NET_CLINET_HTTPPORT					(NET_CLIENT_MIN + 12)	//HTTP端口
#define NET_CLINET_PICTURE_MERGE			(NET_CLIENT_MIN + 13)	//图像合成
#define NET_CLIENT_SNAP_SHOT_INFO			(NET_CLIENT_MIN + 14)	//前后抓拍参数
#define NET_CLIENT_IO_LINK_INFO				(NET_CLIENT_MIN + 15)	//IO联动设备类型
#define NET_CLIENT_DEV_COMMONNAME			(NET_CLIENT_MIN + 16)	//自定义设备通用接口的别名
#define NET_CLIENT_ITS_DEV_COMMONINFO		(NET_CLIENT_MIN + 17)	//ITS设备通用信息
#define NET_CLIENT_ITS_COMPOUNDPARAM		(NET_CLIENT_MIN + 18)	//设置混合触发相关参数
#define NET_CLIENT_DEV_VOLUME_CTRL			(NET_CLIENT_MIN + 19)	//音频音量控制
#define NET_CLIENT_INTIMITY_COVER		(NET_CLIENT_MIN + 20)	//3D隐私遮挡
#define NET_CLIENT_ANYSCENE				(NET_CLIENT_MIN + 21)	//分析场景
#define NET_CLIENT_CALL_ANYSCENE		(NET_CLIENT_MIN + 22)	//调用球机到相应分析场景
#define NET_CLIENT_SENCE_CRUISE_TYPE	(NET_CLIENT_MIN + 23)	//场景应用巡航使能类型
#define NET_CLIENT_SENCE_CRUISE_TIMER	(NET_CLIENT_MIN + 24)	//场景应用定时巡航模板
#define NET_CLIENT_SENCE_CRUISE_TIMERANGE	(NET_CLIENT_MIN + 25)	//场景应用时间段巡航模板
#define NET_CLIENT_FACE_DETECT_ARITHMETIC		(NET_CLIENT_MIN + 26)	//人脸检测算法
#define NET_CLIENT_PERSON_STATISTIC_ARITHMETIC	(NET_CLIENT_MIN + 27)	//人数统计算法
#define NET_CLIENT_TRACK_ARITHMETIC		(NET_CLIENT_MIN + 28)	//智能跟踪算法
#define NET_CLIENT_TRACK_ASTRICT_LOCATION		(NET_CLIENT_MIN + 29)	//跟踪限位
#define NET_CLIENT_TRACK_ZOOMX			(NET_CLIENT_MIN + 30)	//跟踪倍率系数--实时设置
#define NET_CLIENT_TRACK_MANUAL_LOCKED	(NET_CLIENT_MIN + 31)	//手动锁定跟踪
#define NET_CLIENT_VCA_SUSPEND			(NET_CLIENT_MIN + 32)	//暂停智能分析
#define NET_CLIENT_COVER_ALARM_AREA		(NET_CLIENT_MIN + 33)	//视频遮挡报警区域参数
#define NET_CLIENT_MANUAL_SNAPSHOT		(NET_CLIENT_MIN + 34)	//手动抓拍
#define NET_CLIENT_FILE_APPEND_INFO		(NET_CLIENT_MIN + 35)	//录像文件附加信息
#define NET_CLIENT_CURRENT_SENCE		(NET_CLIENT_MIN + 36)	//获取球机当前使用分析场景
#define NET_CLIENT_BACKUP_SEEK_WORKDEV		(NET_CLIENT_MIN + 37)	//组播搜索工作机
#define NET_CLIENT_BACKUP_GET_SEEK_COUNT	(NET_CLIENT_MIN + 38)	//组播搜索工作机个数
#define NET_CLIENT_BACKUP_GET_SEEK_WORKDEV	(NET_CLIENT_MIN + 39)	//获得搜索列表中某个工作机的信息
#define NET_CLIENT_BACKUP_WORKMODE			(NET_CLIENT_MIN + 40)	//工作模式
#define NET_CLIENT_BACKUP_MODIFY			(NET_CLIENT_MIN + 41)	//给工作机添加删除热备机
#define NET_CLIENT_BACKUP_BACKUPDEV_STATE	(NET_CLIENT_MIN + 42)	//获得热备机配置信息及连接状态 
#define NET_CLIENT_BACKUP_GET_WORKDEV_NUM	(NET_CLIENT_MIN + 43)	//获得与热备机关联的工作机个数
#define NET_CLIENT_BACKUP_WORKDEV_STATE		(NET_CLIENT_MIN + 44)	//获得工作机配置信息及连接状态
#define NET_CLIENT_APP_SERVER_LIST			(NET_CLIENT_MIN + 45)	//获取设备当前平台支持的服务程序列表
#define NET_CLIENT_RTMP_URL_INFO			(NET_CLIENT_MIN + 46)	//RTMP列表信息
#define NET_CLIENT_FRAME_RATE_LIST			(NET_CLIENT_MIN + 47)	//获取某通道支持帧率列表
#define NET_CLIENT_RTSP_LIST_INFO			(NET_CLIENT_MIN + 48)	//设置RTSP列表信息
#define NET_CLIENT_DISABLE_PROC_VCA			(NET_CLIENT_MIN + 49)	//禁用对VCA参数的处理，防止占用过多内存
#define NET_CLIENT_ENABLE_PROC_VCA			(NET_CLIENT_MIN + 50)	//启用对VCA参数的处理
#define NET_CLIENT_COM_DEVICE               (NET_CLIENT_MIN + 51)	//串口设备配置
#define NET_CLIENT_GAIN_LOG					(NET_CLIENT_MIN + 52)	//获取脱机日志
#define NET_CLIENT_EXPORT_CONFIG            (NET_CLIENT_MIN + 53)	//导出配置
#define NET_CLIENT_ELECNET_METER            (NET_CLIENT_MIN + 54)	//electronic net meters param
#define NET_CLIENT_DEVINFO_AUTO_CONFIRM		(NET_CLIENT_MIN + 55)   //Dh DevInvo confirm
#define NET_CLIENT_COLOR_TYPE				(NET_CLIENT_MIN + 56)   //color input type
#define NET_CLIENT_CHANGE_VI_MODE			(NET_CLIENT_MIN + 57)   //change video input mode
#define NET_CLIENT_WATER_STEADY_PERIOD		(NET_CLIENT_MIN + 58)   
#define NET_CLIENT_WATER_SNAPINFO    		(NET_CLIENT_MIN + 59)   
#define NET_CLIENT_VIDEOENCODE_LIST			(NET_CLIENT_MIN + 60)   //Video Encod List
#define NET_CLIENT_BARCODE					(NET_CLIENT_MIN + 61)   //device bar code
#define NET_CLIENT_RESET_PASSWORD			(NET_CLIENT_MIN + 62)
#define NET_CLIENT_PSECH_STATE				(NET_CLIENT_MIN + 63)
#define NET_CLIENT_WHITELIGHT_MODE			(NET_CLIENT_MIN + 64)	//white light mode
#define NET_CLIENT_IRIS_TYPE				(NET_CLIENT_MIN + 65)	//aperture type
#define NET_CLIENT_IDENTI_CODE				(NET_CLIENT_MIN + 67)	//identity code
#define NET_CLIENT_EMAIL_TEST				(NET_CLIENT_MIN + 68)	//email test
#define NET_CLIENT_CREATEFREEV				(NET_CLIENT_MIN + 69)	//create freev0
#define NET_CLIENT_VCAFFINAL				(NET_CLIENT_MIN + 70)	//VCAFFINAL
#define NET_CLIENT_PREVIEW_MODE				(NET_CLIENT_MIN + 71)	//MODE
#define NET_CLIENT_DISK_SMART_ENABLE		(NET_CLIENT_MIN + 72)	//disk smart check enable
#define NET_CLIENT_SMART_INFO				(NET_CLIENT_MIN + 73)	//disk smart check info
#define NET_CLIENT_AUDIO_PONTICELLO			(NET_CLIENT_MIN + 74)	//AUDIO_PONTICELLO
#define NET_CLIENT_FACEMOSAIC				(NET_CLIENT_MIN + 75)	//FACEMOSAIC
#define NET_CLIENT_MAX_LANRATE				(NET_CLIENT_MIN + 76)	//max lan rate
#define NET_CLIENT_P2P_APP_URL				(NET_CLIENT_MIN + 77)	//P2p load app url
#define NET_CLIENT_CREATEFREEVO				(NET_CLIENT_MIN + 78)
#define NET_CLIENT_DEVAMPLITUDE				(NET_CLIENT_MIN + 79)
#define NET_CLIENT_PTZLIST					(NET_CLIENT_MIN + 80)
#define NET_CLIENT_COLORPARALIST			(NET_CLIENT_MIN + 81)
#define NET_CLIENT_EXCEPTION_LINKOUTPORT	(NET_CLIENT_MIN + 82)  //Exceptyion LinkOutPort
#define NET_CLIENT_WIRELESSMODULE			(NET_CLIENT_MIN + 83)  //WifiLessModule
#define NET_CLIENT_MODIFYAUTHORITY			(NET_CLIENT_MIN + 84)  //modify authority
#define NET_CLIENT_DISK_OPERATION           (NET_CLIENT_MIN + 85)  //disk operate
#define NET_CLIENT_SCENETIMEPOINT	        (NET_CLIENT_MIN + 86)  //scene time port
#define NET_CLIENT_H323_LOCALPARAS          (NET_CLIENT_MIN + 87)  //H.323 local param
#define NET_CLIENT_H323_GKPARAS				(NET_CLIENT_MIN + 88)  //H.323 GK param
#define NET_CLIENT_ENABLE_LOGON_LIGHT		(NET_CLIENT_MIN + 89)  //Enable Light Logon Mode
#define NET_CLIENT_CHN_CONNECT_STATE		(NET_CLIENT_MIN + 90)  //channel connect state
#define NET_CLIENT_GET_PROTOCOL_ENABLE		(NET_CLIENT_MIN + 91)  //device is send protocol
#define NET_CLIENT_GET_LIFEMONITOR_HBREAL		(NET_CLIENT_MIN + 92)  //Vital signs in real time heart rate and blood oxygen
#define NET_CLIENT_GET_LIFEMONITOR_GRAMREAl		(NET_CLIENT_MIN + 93)  //Vital signs waveform data
#define NET_CLIENT_LIFEMONITOR_SET_CONFIG		(NET_CLIENT_MIN + 94)  //Set life monitor config
#define NET_CLIENT_PASSWD_ERR_TIMES			(NET_CLIENT_MIN + 95)		//Password Error times
#define NET_CLIENT_DEV_ABSTRACT				(NET_CLIENT_MIN + 96)		//dev abstract
#define NET_CLIENT_OSD_EXTRA_INFO			(NET_CLIENT_MIN + 97)		//OSD extra info
#define NET_CLIENT_SERVERINFO				(NET_CLIENT_MIN + 98)		//Server Info
#define NET_CLIENT_MAX						(NET_CLIENT_MIN + 99)

//加密对外接口
typedef struct _tagEncrypt_Info
{
	int iSize;
	int iPasswdErrTimes;			//密码错误次数
}TEncrypt_Info_Out, *PTEncrypt_Info_Out;

//pse ch zyb add
#define MAX_PSE_CHANNEL_NUM		16
typedef struct tagPseChState
{
	int				iBufSize;
	int				iPseCh;
	int				iState;			
	int				iPower;
}PseChState, *pPseChState;

typedef struct tagPseChProperty
{
	int				iBufSize;	
	int				iPseCh;			
	int				iWorkMode;
}PseChProperty, *pPseChProperty;

typedef struct tagPseChInfo
{
	int				iBufSize;	
	int				iPseChNum;		//PSE total channel number			
	int				iPsePower;		//PSE total power
}PseChInfo, *pPseChInfo;

//autotest use it to confirm test  item
typedef struct _tagDevAbstract 
{
	int		iBufSize;
	int		iSataPortNum;  //sata num
	int		iESataPortNum; //esata num
	int     iUsbPortNum;   //usb num
	int     iSDCardNum;	   //sd card num
}TDevAbstract, *pTDevAbstract;

typedef struct tagDiskSmartEnable
{
	int				iSize;	
	int				iDiskId;			
	int				iEnable;
}DiskSmartEnable, *pDiskSmartEnable;


typedef struct tagSmartInfo
{
	int				iSize;	
	char			cId[LEN_8];			
	char			cAttributeName[LEN_32];	
	int				iFlag;
	int				iValue;
	int				iWorst;
	int				iThresh;
	char			cStatue[LEN_16];
	char			cRawValue[LEN_64];
}SmartInfo, *pSmartInfo;

#define MAX_SMART_INFO_NUM	256
#define SMART_INFO_NUM		32
typedef struct tagDiskSmartMsg
{
	int				iSize;	
	int				iDiskId;			
	int				iTotalPackageNum;		//total message number
	int				iCurrentPackageMsgNo;			//current message No
	char			cHDDModel[LEN_32];//HDD model
	char			cSericalNum[LEN_16];
	int				iTemprt;			//temperature
	int				iUsedTime;
	int				iHealth;
	int				iAllHealth;
	int				iTotalSmartInfoNum;
	pSmartInfo		pstSmartInfo;
}DiskSmartMsg, *pDiskSmartMsg;

typedef struct tagP2PAppUrl
{
	int				iBufSize;
	int				iTypeId;	//1=android，2=IOS
	char			cUrl[256];	//include "http://"
}P2PAppUrl,*pP2PAppUrl;

//S3E
typedef struct tagWhiteLight
{
	int				iBufSize;
	int				iMode;		//work mode
}WhiteLight,*pWhiteLight;

typedef struct tagApertureType
{
	int				iBufSize;
	int				iType;			//0-retain 1-DC 2-Piris
}ApertureType, *pApertureType;

typedef struct tagIdentiCode
{
	int				iBufSize;
	char			cParam[LEN_32];
}IdentiCode, *pIdentiCode;

typedef struct tagMaxLanRate
{
	int				iBufSize;
	int				iLanNo;
	int				iRate;
}MaxLanRate, *pMaxLanRate;

#define MAX_PRESET_LIST_NUM	501
typedef struct tagPTZList
{
	int				iBufSize;
	int				iChanNo;
	int             iFocusMode[MAX_PRESET_LIST_NUM]; //PTZ focus mode  0:auto   1:fixed -1:unknown
	int				iPtzState[MAX_PRESET_LIST_NUM];  //PTZ state 0:set 1:delete 2:call -1:unknown
}PTZList, *pPTZList;

typedef struct tagColorParaList
{
	int iSize;
	int iChanNo;
	int iParam;
}tColorParaList, *ptColorParaList;

//ITS 6M 2014/12/05
typedef struct tagITSTrafficFlow
{
	int				iBufSize;		//Size of struct
	int				iLaneID;		//LaneID ([0, 3])
	int				iType;			//Statistical Type ([0, 1])
	int				iEnable;		//Traffic Statistics Enable ([0, 1])
	int				iTimeInterval;	//Statistics Time Interval ([1, 1440])
}ITSTrafficFlow, *pITSTrafficFlow;

typedef struct tagITSTrafficFlowReport
{
	int				iSize;				//Size of struct
	int				iLaneID;			//Lane ID ([0, 3])
	int				iFlow;				//Flow 
	int				iHoldRate;			//Lane Hold Rate
	int				iSpeed;				//Average Speed
	int				iDistance;			//  	
	NVS_FILE_TIME 	stStartTime;	
	NVS_FILE_TIME  	stStopTime;			//Time Range
}ITSTrafficFlowReport, *pITSTrafficFlowReport;

#define MAX_ITS_ILLEGALTYPE		12	
typedef struct tagITSIllegalType
{
	int				iBufSize;				//Size of struct
	int				iLaneID;				//Lane ID ([0, 3])
	int				iTypeID;				//Illegal Type ID ([1, 12 ])
	char			cMarkID[LEN_32];		//Type ID
	int				iPriority;				//Priority([0, 100] )
	char			pcName[LEN_64];			//Illegal Name
}ITSIllegalType, *pITSIllegalType;

typedef struct tagITSPicMergeOverLay
{
	int		iBufSize;				//Size of struct
	int		iLaneID;			//Lane No
	int		iOneOSD;
	int		iOsdType;				
	int		iEnable;				
	char	cOsdName[LEN_32];
	int		iPosX;				
	int		iPosY;
	int     iZoomScale;
}ITSPicMergeOverLay, *pITSPicMergeOverLay;


#define MAX_LIST_COUNT	32

typedef struct tagPicDirectory
{
	int				iDirectoryId;
	char			cUserDefine[LEN_32];
}PicDirectory,*pPicDirectory;

typedef struct tagPicName
{
	int				iDirectoryId;
	char			cUserDefine[LEN_32];
}PicName,*pPicName;

typedef struct tagFtpUpload
{
	int				iSize;
	int				iFtpNum;		//0：retain；1：ftp1；2：ftp2
	int				iFtpEnable;		//0-unable 1-enable
	char			cFtpAddr[LEN_32];
	char			cUserName[LEN_16];
	char			cPassWord[LEN_16];
	int				iPort;			//ftp port [0,65535]
	int				iFtpType;		//0：retain； 1：bayonet； 2：break rules（two ftp mutual exclusion）
	int				iListCount;		//0：root list； 1~n：n-list
	int				iPicNameCount;	//0：none 1~n：n-list
	int				iPlateEnable;	//small picture of plate number 
	pPicDirectory   pstDirectory;	
	pPicName        pstPicName;	
}FtpUpload, *pFtpUpload;

typedef struct tagCarLogoOptim
{
	int				iSize;
	int				iOptimID;
	int				iEnable;				//0-Unable；1-Enable
	char			cFirstChar[LEN_32];
	char			cFirstLetter[LEN_16];
	char			cSecondLetter[LEN_32];
	int				iLogoType;				
}CarLogoOptim, *pCarLogoOptim;

typedef struct tagITS_LoopMode
{
	int		iBufSize;
	int		iLaneID;			//Lane No	Max:4  value：0-3	
	int		iLoopMode;			//0：One Loop；1：two Loop；2：three Loop											
}ITS_LoopMode, *pITS_LoopMode;

//add end

//HN zyb add 20150123
typedef struct tagDevAmplitude
{
	int				iSize;
	int				iChanNo;
	int				iMicNo;
	int				iValue;		
}DevAmplitude, *pDevAmplitude;
//add end

#define MAX_DOME_TYPE	25
#define MAX_DOME_PARA_GROUP_NUM		8
typedef struct __tagDomeParam
{
	int iType;
	int iParam1;
	int iParam2;
	int iParam3;
	int iParam4;
}TDomeParam, *pTDomeParam;

#define MAX_SCHEDULE 8
typedef struct __tagDomeWork
{
	int iBeginHour;
	int iBeginMinute;
	int iEndHour;
	int iEndMinute;
	int iWorkType;  //0：无动作1：预置位2：扫描 3：巡航 4：模式  5：辅助输出
	int iWorkValue; //预置位号取值范围1～8，扫描号取值范围：1～4，巡航号取值范围：1～4，模式路径号取值范围：1～4 ,辅助输出号取值范围：bit0:输出1，bit1:输出2
	int iEnable;	//0-不启用,1-启用
}TDomeWork, *pTDomeWork;

//彩转灰
typedef struct __tagColor2GrayParam
{
	int  m_isize;         //结构体大小
	int  m_iColor2Gray;   //彩转灰类型
	int  m_iDayRange;     //白天亮度值
	int  m_iNightRange;   //夜晚亮度值
	int  m_iTimeRange;    //定时范围：白天开始时间，晚上开始时间。
	int  m_iColorDelay;   //彩转黑延时
	int  m_iGrayDelay;    //黑转彩延时
	int	 m_iDevType;	  //0:Monitoring Products   1:ITS Products
}TColor2GrayParam,*pTColor2GrayParam;

//网卡参数
typedef struct __tagLanParam
{
	int m_iSize;		  //结构体大小
	int m_iNo;			  //网卡编号：lan1：0； lan2:1
	int m_iMode;		  //网卡模式：0：保留；1：半双工；2：保留；3：双工。
	int m_iSpeed;		  //速率
}TLanParam,*pTLanParam;

#define MAX_DEVCOMNAME_NO   3		//通道类型数目
#define DEVCOMNAME_VIDEO    0		//视频
#define DEVCOMNAME_ALARMIN	1       //报警输入
#define DEVCOMNAME_ALARMOUT 2       //报警输出
//自定义设备通用接口的别名
typedef struct __tagDevCommonName
{
	int  m_iSize;				//结构体大小
	int	 m_iChannelType;		//通道类型
	char m_cChanneleName[LEN_64+1];   //通道名称
}TDevCommonName,*pTDevCommonName;

typedef struct __tagDomeWorkSchedule
{	
	int iWeekDay;
	TDomeWork tWork[MAX_SCHEDULE];
}TDomeWorkSchedule, *pTDomeWorkSchedule;

#define  MAX_APPEND_DSD_LAY_BUM	7
#define MAX_OSD_LENGTH 256
typedef struct __tagAppendOSD
{
	int iSize;
	int iLayNo;
	int iColor;
	int iDiaphaneity;
	int iFontSize;
	int iPosX;
	int iPosY;
	char pcText[MAX_OSD_LENGTH];
}TAppendOSD, *pTAppendOSD;

#define MAX_INTERESTED_AREA_NUM	8
typedef struct __tagInterestedArea
{
	int iSize;
	int iIndex;
	int iEnable;
	int iAbsQp;
	int iQp;
	int iLeft;
	int iTop;
	int iRight;
	int iBottom;
	int iDstFrameRate;	//destination frame rate，1-current framerate
}TInterestedArea, *pTInterestedArea;

#define MAX_NVR_AUTOREBOOT_SCHEDULE 9
typedef struct __tagAutoRebootSchedule
{
	int iSize;
	int iWeekDay;			//星期日到星期六为0～6，7-每天，8-从不
	int iHour;
	int iMinute;
}TAutoRebootSchedule, *pTAutoRebootSchedule;

#define MAX_IP_FILTER_NUM	16
typedef struct __tagIpFilter
{
	int iSize;
	char cIp[LENGTH_IPV4];
	char cSubMask[LENGTH_SUB_MASK];
	int iFilterType;								//过滤类型:0,禁用IP权限设定;1,禁止IP访问;2,允许IP访问
	int iIpNum;										//过滤ip数量,最大支持16个不同的IP地址
	char cFilterIp[MAX_IP_FILTER_NUM][LENGTH_IPV4];	//网络地址字符串。如：pcFilterIp[0]=“192.168.1.10”
}TIpFilter, *pTIpFilter;

typedef struct __tagDateFormat
{
	int iSize;
	int iFormatType;	//格式类型:case 0:/*yyyy/mm/dd*/; 1:/*mm/dd/yyyy*/; 2:/*dd/mm/yyyy*/; 3:/*M day yyyy*/; 4:/*day M yyyy*/
	char cSeparate;		//分隔符,可设置为“/”，“-”
	char cReserved[3];	//字节对齐
	int iFlagWeek;		//表示星期是否显示: 0-不显示，1-显示					
	int iTimeMode;		//表示时间制式: 0-24小时制，1-12小时制							
}TDateFormat, *pDateFormat;

//设置设备的时区
typedef struct __tagTimeZone
{
	int iSize;
	int iTimeZone;			//当前正在使用的时区,范围应该是-12～+13
	int iDSTEnable;			//夏令时使能,0-禁用，1-启用
}TTimeZone, *pTTimeZone;

//夏令时
typedef struct __tagDaylightSavingTime
{
	int m_iSize;
	int m_iMonth;				//月份
	int m_iWeekOfMonth;			//星期编号(0：末个，1：首个，2：第二个，3：第三个，4：第四个)
	int m_iDayOfWeek;			//星期（星期日到星期六为0～6）
	int m_iHourOfDay;			//小时（0～23）
}TDaylightSavingTime, *pTDaylightSavingTime;

typedef struct __tagDaylightSavingTimeSchedule
{
	int m_iSize;
	int m_iDSTEnable;					//夏令时使能,0-禁用，1-启用
	int m_iOffsetTime;					//偏移时间,0～120（单位：分）
	TDaylightSavingTime m_tBeginDST;	//起始时间
	TDaylightSavingTime m_tEndDST;		//结束时间
}TDaylightSavingTimeSchedule, *pTDaylightSavingTimeSchedule;

//远程强制断开用户连接
typedef struct __tagNetOffLine
{
	int iSize;
	char cIPAddr[LENGTH_IPV4];		//IP地址、域名
	int iOffTime;					//断开时间,秒；最小10秒
}TNetOffLine, *pTNetOffLine;

//HTTP端口
typedef struct __tagHttpPort
{
	int iSize;
	int iPort;			//http端口号
	int iHttpsport;		//https端口号,默认443
	int	iRtspPort;		//rtsp端口号,默认554
}THttpPort, *pTHttpPort;

//登录失败错误码
#define UNKNOW_ERROR			0
#define CIPHER_USERNAME_ERROR	1
#define CIPHER_USERPASS_ERROR	2
#define NO_SUPPORT_ALGORITHM	3
#define PSWD_ERR_TIMES_OVERRUN	4
#define LOGON_NET_ERROR			0xFF01
#define LOGON_PORT_ERROR		0xFF02

//高清摄像机参数模板类型
#define CAMERA_PARA_MIN								0
#define CAMERA_PARA_IRIS_ADJUSTMENT 				CAMERA_PARA_MIN + 0		//0--光圈调节
#define CAMERA_PARA_WDR								CAMERA_PARA_MIN + 1		//1--超宽动态
#define CAMERA_PARA_BLC								CAMERA_PARA_MIN + 2		//2--背光补偿
#define CAMERA_PARA_EXPOSURE_TIME					CAMERA_PARA_MIN + 3		//3--曝光时间
#define CAMERA_PARA_SHUTTER_ADJUSTMENT				CAMERA_PARA_MIN + 4		//4--快门调节
#define CAMERA_PARA_GAIN_ADJUSTMENT					CAMERA_PARA_MIN + 5		//5--增益调节
#define CAMERA_PARA_GAMMA_ADJUSTMENT				CAMERA_PARA_MIN + 6		//6--gamma调节
#define CAMERA_PARA_SHARPNESS_ADJUSTMENT			CAMERA_PARA_MIN + 7		//7--锐度调节
#define CAMERA_PARA_NOISE_REDUCTION_ADJUSTMENT		CAMERA_PARA_MIN + 8		//8--降噪调节
#define CAMERA_PARA_EXPOSURE_REGION					CAMERA_PARA_MIN + 9		//9--曝光区域
#define CAMERA_PARA_BLC_REGION						CAMERA_PARA_MIN + 10	//10--背光补偿区域
#define CAMERA_PARA_AF_REGION_SET					CAMERA_PARA_MIN + 11	//11--AF区域设置
#define CAMERA_PARA_TARGET_BRIGHTNESS_ADJUSTMENT	CAMERA_PARA_MIN + 12	//12--目标亮度调节
#define CAMERA_PARA_WHITE_BALANCE_ADJUSTMENT		CAMERA_PARA_MIN + 13	//13--白平衡调节
#define CAMERA_PARA_JPEG_IMAGE_QUALITY				CAMERA_PARA_MIN + 14	//14--JPEG图像质量
#define CAMERA_PARA_LUT_ENABLE						CAMERA_PARA_MIN + 15	//15--LUT使能
#define CAMERA_PARA_AUTOMATIC_BRIGHTNESS_ADJUST		CAMERA_PARA_MIN + 16	//16--自动亮度调节使能
#define CAMERA_PARA_HSBLC							CAMERA_PARA_MIN + 17	//17--强光抑制功能
#define CAMERA_PARA_AUTO_EXPOSURE_MODE				CAMERA_PARA_MIN + 18	//18--自动曝光模式
#define CAMERA_PARA_SCENE_MODE						CAMERA_PARA_MIN + 19	//19--场景模式
#define CAMERA_PARA_FOCUS_MODE						CAMERA_PARA_MIN + 20	//20--聚焦模式
#define CAMERA_PARA_MIN_FOCUSING_DISTANCE			CAMERA_PARA_MIN + 21	//21--最小聚焦距离
#define CAMERA_PARA_DAY_AND_NIGHT					CAMERA_PARA_MIN + 22	//22--日夜切换
#define CAMERA_PARA_RESTORE_DEFAULT					CAMERA_PARA_MIN + 23	//23--恢复默认
#define CAMERA_PARA_THROUGH_FOG						CAMERA_PARA_MIN + 24	//24--去雾
#define CAMERA_PARA_MAX								CAMERA_PARA_MIN + 25

//球机菜单参数模板类型
#define DOME_PARA_MIN										0
#define DOME_PARA_PRESET_TITLE_DISPLAY_TIME					DOME_PARA_MIN + 1		//1--预置位标题显示时间
#define DOME_PARA_AUTOMATIC_FUNCTION_TITLE_DISPLAY_TIME		DOME_PARA_MIN + 2		//2--自动功能标题显示时间
#define DOME_PARA_REGION_TITLE_DISPLAY_TIME					DOME_PARA_MIN + 3		//3--区域标题显示时间
#define DOME_PARA_COORDINATE_DIRECTION_DISPLAY_TIME			DOME_PARA_MIN + 4		//4--坐标方向显示时间
#define DOME_PARA_TRACEPOINTS_DISPLAY_TIME					DOME_PARA_MIN + 5		//5--跟踪点标题显示时间
#define DOME_PARA_TITLE_BACKGROUND							DOME_PARA_MIN + 6		//6--标题背景
#define DOME_PARA_AUTOMATIC_STOP_TIME						DOME_PARA_MIN + 7		//7--自动停止时间
#define DOME_PARA_MENU_OFF_TIME								DOME_PARA_MIN + 8		//8--菜单关闭时间
#define DOME_PARA_VERTICAL_ANGLE_ADJUSTMENT					DOME_PARA_MIN + 9		//9--垂直角度调整
#define DOME_PARA_MANIPULATION_SPEED_RATING					DOME_PARA_MIN + 10		//10--操控速度等级
#define DOME_PARA_PRESET_SPEED_RATING						DOME_PARA_MIN + 11		//11--预置位速度等级
#define DOME_PARA_TEMPERATURE_CONTROL_MODE					DOME_PARA_MIN + 12		//12--温度控制模式
#define DOME_PARA_485_ADDRESS_SETTING						DOME_PARA_MIN + 13		//13--485地址设置
#define DOME_PARA_ZERO_SETTING								DOME_PARA_MIN + 14		//14--零点设置
#define DOME_PARA_NORTH_SETTING								DOME_PARA_MIN + 15		//15--指北设置
#define DOME_PARA_CONTROL_MODE								DOME_PARA_MIN + 16		//16--控制方式
#define DOME_PARA_SENSITIVE_THRESHOLD						DOME_PARA_MIN + 17		//17--感光阈值
#define DOME_PARA_DELAY_TIME								DOME_PARA_MIN + 18		//18--延时时间
#define DOME_PARA_ZOOM_MATCH								DOME_PARA_MIN + 19		//19--变倍匹配
#define DOME_PARA_PRESET									DOME_PARA_MIN + 20		//20--预置位
#define DOME_PARA_SCANNING									DOME_PARA_MIN + 21		//21--扫描
#define DOME_PARA_SCHEMA_PATH								DOME_PARA_MIN + 22		//22--模式路径
#define DOME_PARA_SCHEMA_PATH_CURRENT_STATE					DOME_PARA_MIN + 23		//23--模式路径当前状态
#define DOME_PARA_REGIONAL_INDICATIVE						DOME_PARA_MIN + 24		//24--区域指示
#define DOME_PARA_ZOOM_SPEED								DOME_PARA_MIN + 25		//25--变倍速度
#define DOME_PARA_DIGITAL_ZOOM								DOME_PARA_MIN + 26		//26--数字变倍
#define DOME_PARA_PRESET_FROZEN								DOME_PARA_MIN + 27		//27--预置位冻结
#define DOME_PARA_LASER_LIGHT								DOME_PARA_MIN + 28		//28--激光器亮度阈值
#define DOME_PARA_LASER_COAXIAL								DOME_PARA_MIN + 29		//29--激光器同轴设置
#define DOME_PARA_KEYING_LIMIT								DOME_PARA_MIN + 31		//31--键控限位设置
#define DOME_PARA_OUTAGE_MEMORY								DOME_PARA_MIN + 32		//32--掉电记忆模式
#define DOME_PARA_PTZ_PRIOR									DOME_PARA_MIN + 33		//33--云台优先
#define DOME_PARA_KEYING_USING								DOME_PARA_MIN + 34		//34--键控限位启用
#define DOME_PARA_MAX										DOME_PARA_MIN + 35		

//CMD
#define COMMAND_ID_MIN					0
#define COMMAND_ID_ITS_FOCUS			(COMMAND_ID_MIN + 1)		//五点聚焦相机控制协议
#define COMMAND_ID_MODIFY_CGF_FILE		(COMMAND_ID_MIN + 2)		//设置配置文件任意字段的值
#define COMMAND_ID_AUTO_FOCUS			(COMMAND_ID_MIN + 3)		//auto focus
#define COMMAND_ID_SAVECFG				(COMMAND_ID_MIN + 4)		//save param
#define COMMAND_ID_DEFAULT_PARA			(COMMAND_ID_MIN + 5)		//default para
#define COMMAND_ID_DIGITAL_CHANNEL		(COMMAND_ID_MIN + 6)		//digital channel
#define COMMAND_ID_DELETE_FOG			(COMMAND_ID_MIN + 7)		//delete fog
#define COMMAND_ID_MAX					(COMMAND_ID_MIN + 8)

//default para
typedef struct _tagDefaultPara
{
	int iSize;
	int iType;
}TDefaultPara, *PTDefaultPara;

//digital channel
typedef struct _tagDigitalChnBatch
{
	int iSize;
	int iType;  //0-保留 1-数字通道批量删除 2-数字通道批量禁用
	int iOpt;	//iOp为 1 表示数字通道批量操作开;iOp为 0 表示数字通道批量操作结束
}TDigitalChnBatch, PTDigitalChnBatch;

//图像合成方式设置
#define MAX_ITS_MERGE_TYPE	4
typedef struct __tagTITS_MergeInfo
{
	int		m_iSize;
	int		m_iMergeType;		//合成张数类型:1-一张合成方式类型,2-两张合成方式类型,3-三张合成方式类型
	int		m_iMergeMode;		//单张合成方式：0-横向原图加特写合成,1-纵向原图加特写合成,
								//				2-横向特写加原图合成,3-纵向特写加原图合成。
								//两张合成方式类型：0-垂直合成模式,1-水平合成模式
								//三张合成方式类型:0-品字形,上一下二;1-品字形,上二下一;2-左二右一;3-左一右二;
								//				4-垂直排列;5-水平排列;6-田字形7-垂直排列3张加特写，8-水平排列3张加特写，
								//				9-田字形-特写左下，10-田字形-特写右上，11-田字形-特写左上
	int		m_iResizePercent;	//图像缩放比例
}TITS_MergeInfo, *PTITS_MergeInfo;

#define IODEVICE_NUM 3		//IO设备数
//前后抓拍参数
#define MAX_LINK_CAMERA_ID		4
typedef struct __tagTITS_SnapShotInfo
{
	int		m_iSize;
	int		m_iRoadNo;				//车道编号
	int		m_iEnable;				//使能
	char	m_cLinkIP[LENGTH_IPV4];	//联动相机IP
	int		m_iLinkRoadNo;			//联动相机车道ID
	int		m_iSceneID;// 场景ID(0~15) 20140203扩展
}TITS_SnapShotInfo, *pTITS_SnapShotInfo;

//IO联动设备类型设置
#define MAX_IO_DEVICE_NUM	10
typedef struct __tagTITS_IOLinkInfo
{
	int		m_iSize;
	int		m_iIONo;		//IO口编号,0-10
	int		m_iLinkDevice;	//设备联动类型,0-闪光灯,1-频闪灯,2-偏振镜
	int		m_iDevicePulse;	//补光灯联动脉冲宽度,0us-10000us
	int		m_iAheadTime;	//output ahead time
	int		m_iWorkState;	//work state
	int		m_iDefaultState;//default state
	int		m_iFrequency;
	int		m_iDutyCycle;	// Duty cycle	
}TITS_IOLinkInfo, *pTITS_IOLinkInfo;

//时间段闪光灯使能
typedef struct __tagTITS_FlashEnable
{
	int   m_iSize;
	int   m_iIndex;				//时间段编号,0-7，支持最多8个时间段
	int   m_iFlashLampEnable;	//是否启用闪光灯,bit0：0-禁用闪光灯，1-启用闪光灯；bit1: 0-禁用频闪灯，1-启用频闪灯；bit2: 0-禁用偏振镜，1-启用偏振镜；
	int   m_iVideoLinkEnbale;	//视频联动使能,按位bit0:0-不使能，1-使能; bit1:0-闪光灯不使能，1-闪光灯使能；bit2:0-频闪灯不使能，1-频闪灯使能；bit3:0-偏振镜不使能，1-偏振镜使能；
}TITS_FlashEnable, *pTITS_FlashEnable;

#define REBUILDINDEX_SUCCESS			0
#define REBUILDINDEX_NO_DISK			1
#define REBUILDINDEX_EXCEPTION			2

#define MAX_ITS_DEV_COMMOMINFO_TYPE		7
typedef struct tagITS_DevCommonInfo
{
	int		iSize;
	int		iType;					//信息类型,0-保留，1-机关代码，2-机关名称，3-抓拍图片字符叠加位
	char	cCommonInfo[LEN_64];	//信息内容,长度不超过63字符;iType为3时候：0-图片内叠加，1-图片下黑框中叠加,2-图片上黑框中叠加
}ITS_DevCommonInfo, *pITS_DevCommonInfo;

typedef struct tagITS_CamLocationEx
{
	int				iSize;
	ITS_CamLocation tITS_CamLocation;	//锐视相机位置设备信息结构体
	int				iDeviceType;		//设备类型,按位，bit0：闯红灯设备,bit1：测速证设备,bit2：监控录像,
										//bit3：数码照相,bit4：卡口监控,bit5：区间测速证设备；
}ITS_CamLocationEx, *pITS_CamLocationEx;

//设置混合触发相关参数
#define MAX_ITS_ROADID_NUM	4
typedef struct tagITS_ComPoundParam
{
	int		iSize;
	int		iITSRoadID;					//车道编号,最大支持4个车道：0-3
	int		iRadarMatchTime;			//雷达速度匹配时间,单位：毫秒
	int		iRadarMinSpeed;				//雷达最小触发速度值,单位：米/小时
	int		iRadarMaxSpeed;				//雷达最大速度值;单位：米/小时
	int		iSceneID;					//场景编号(0~15)
}ITS_ComPoundParam, *pITS_ComPoundParam;

#define VOLUMECTRL_TYPE_MIN					0
#define VOLUMECTRL_TYPE_INPUT	(VOLUMECTRL_TYPE_MIN+1)
#define VOLUMECTRL_TYPE_OUTPUT	(VOLUMECTRL_TYPE_MIN+2)
#define VOLUMECTRL_TYPE_LINEIN	(VOLUMECTRL_TYPE_MIN+3)
#define VOLUMECTRL_TYPE_MICIN	(VOLUMECTRL_TYPE_MIN+4)
#define VOLUMECTRL_TYPE_MAX		(VOLUMECTRL_TYPE_MIN+5)
typedef struct tagDevAudioVolume
{
	int				iBufSize;			//音量控制信息结构体大小
	int				iCtrlType;			//音量控制类型：0-保留；1-输入； 2-输出；3-LineIn；4-MicIn		
	int				iVolume;			//音量数值：0：静音 ，1-255：音量数值
}DevAudioVolume, *pDevAudioVolume;

#define MAX_CRUISE_NUM	16
#define SENCE_CRUISE_TYPE_TIMER      1
#define SENCE_CRUISE_TYPE_TIMERANGE 2

#define MAX_PRAVICY_COVER_AREA_NUM	  24
#define MAX_INTIMITY_COVER_AREA_COUNT 32
typedef struct tagIntimityCover
{
	int				iBufSize;			//3D隐私遮挡结构体大小
	int				iAreaNum;			//区域编号(1~24)
	int				iMinZoom;			//最小变倍(1~50)
	int				iColor;				//颜色(1：红色 2：绿色 3：黄色 4：蓝色 5：紫色 6：青色 7：黑色 8：白色 9:马赛克)
	int				iPointNum;			//坐标点个数(3~32)
	POINT			ptArea[MAX_INTIMITY_COVER_AREA_COUNT]; //坐标
}IntimityCover, *pIntimityCover;

typedef struct tagAnyScene
{
	int				iBufSize;			//场景应用定时巡航模板结构体大小
	int				iSceneID;			//场景编号(0~15)
	char			cSceneName[LEN_32];	//场景名称
	int				iArithmetic;		//启用算法类型( bit0: 1-行为分析算法启用；0-不启用
										//bit1：1-跟踪算法启用；0-不启用
										//bit2：1-人脸检测算法启用；0-不启用
										//bit3：1-人数统计算法启用；0-不启用)
										//bit4：1-视频诊断算法启用；0-不启用
	                                    //bit5：1-车牌识别算法启用；0-不启用
	                                    //bit6：1-音频异常算法启用；0-不启用 
										//bit7：1-离岗算法启用；0-不启用      
										//bit8：1-人群聚集算法启用；0-不启用
}AnyScene, *pAnyScene;

typedef struct tagSceneTimerCruise
{
	int				iBufSize;			//场景应用定时巡航模板结构体大小
	int				iCruiseID;			//巡航点序号(0~15)
	int				iSceneID;			//场景编号(0~15)
	int				iEnable;			//使能(0：不使能 1：使能)
	int				iTime;				//定时时间(30~3600s)
}SceneTimerCruise, *pSceneTimerCruise;

typedef struct tagSceneTimeRangeCruise
{
	int				iBufSize;			//场景应用时间段巡航模板结构体大小
	int				iCruiseID;			//时间段编号(0~15) 
	int				iSceneID;			//场景编号(0~15)
	int				iEnable;			//使能(0：不使能 1：使能)
	int				iBeginHour;			//开始小时
	int				iBeginMinute;		//开始分钟
	int				iEndHour;			//结束小时
	int				iEndMinute;			//结束分钟
	int				iWeekday;			//星期(星期日到星期六为0～6）
}SceneTimeRangeCruise, *pSceneTimeRangeCruise;

typedef struct tagTrackArithmetic
{
	int				iBufSize;			//跟踪算法结构体大小
	int				iSceneID;			//场景编号(0~15)
	int				iZoomRate;			//跟踪倍率(10~360,1~36倍，精确到0.1)
	int				iMaxFallowTime;		//最长跟踪时间(0~300秒)
	int				iHeight;			//球机高度
	int				iDesStopTime;		//目标静止跟踪时间(2~600秒,默认8秒)
	int				iEnable;			//使能标志(按位表示：1-使能，0-不使能
										//第0位：检测到人脸后是否返回
										//第1位：是否使用抗遮挡功能
										//第2位：是否启用限位)
}TrackArithmetic, *pTrackArithmetic;

typedef struct tagTrackAstrictLocation
{
	int				iBufSize;			//跟踪限位结构体大小
	int				iSceneID;			//场景编号(0~15)
	int				iType;				//限位类型(1:上限位。2:下限位 3:左限位 4:右限位)
}TrackAstrictLocation, *pTrackAstrictLocation;

#define MANUALCAP_TYPE_TRACK_LOCKED		 1  //手动锁定跟踪
#define MANUALCAP_TYPE_SNAPSHOT			 2	//手动抓拍

#define MAX_FACE_DETECT_AREA_COUNT 32
typedef struct tagFaceDetectArithmetic
{
	int				iBufSize;			//人脸检测算法构体大小
	int				iSceneID;			//场景编号(0~15)
	int				iMaxSize;			//最大人脸尺寸(0~100 图像宽度百分比,100表示整个屏幕的宽度)
	int				iMinSize;			//最小人脸尺寸(0~100 图像宽度百分比，100表示整个屏幕的宽度)
	int				iLevel;				//算法运行级别(0~5)
	int				iSensitiv;			//灵敏度(0~5)
	int				iPicScale;			//图像缩放比例(1~10)
	int				iSnapEnable;		//人脸抓拍使能(1-使能，0-不使能)
	int				iSnapSpace;			//抓拍间隔(间隔帧数)
	int				iSnapTimes;			//抓拍次数(1~8)
	int				iPointNum;			//多边形区域顶点个数(3～32)
	POINT			ptArea[MAX_FACE_DETECT_AREA_COUNT]; //多边形区域顶点坐标
}FaceDetectArithmetic, *pFaceDetectArithmetic;

typedef struct tagPersonStatisticArithmetic
{
	int				iBufSize;			//人数统计算法构体大小
	int				iSceneID;			//场景编号(0~15)
	int				iMode;				//模式(1-垂直人数统计 2-水平人数统计)
	int				iTargetMaxSize;		//目标最大尺寸(0~100 图像宽度百分比，100表示整个屏幕的宽度)
	int				iTargetMinSize;		//目标最小尺寸(0~100 图像宽度百分比，100表示整个屏幕的宽度)
	int				iSensitiv;			//灵敏度(0~5)
	int				iDetectType;		//检测类型(1-检测区域 2-检测线)
	int				iPointNum;			//多边形区域顶点个数(2～32)
	POINT			ptArea[MAX_FACE_DETECT_AREA_COUNT]; //多边形区域顶点坐标
	vca_TPolygonEx	stRegion;			//Line1 Point Num and Points
}PersonStatisticArithmetic, *pPersonStatisticArithmetic;

typedef struct tagTrackZoomX
{
	int				iBufSize;			//跟踪倍率结构体大小
	int				iSceneID;			//场景编号(0~15)
	int				iRate;				//跟踪倍率系数(10~360[精度0.1])
}TrackZoomX, *pTrackZoomX;

#define MAX_COVER_ALARM_BLOCK_COUNT 8
#define MAX_COVER_ALARM_AREA_COUNT 32
typedef struct tagCoverAlarmArea
{
	int				iBufSize;			//视频遮挡报警区域结构体大小
	int				iBlockNo;			//块ID(1~8)
	int				iAlarmTime;			//报警检测时间
	int				iPointNum;			//多边形区域顶点个数(3～32)
	POINT			ptArea[MAX_COVER_ALARM_AREA_COUNT]; //多边形区域顶点坐标
}CoverAlarmArea, *pCoverAlarmArea;

//Record time parameter
typedef struct tagNVS_FILE_TIME_V1
{
	unsigned short iYear;   /* Year */
	unsigned short iMonth;  /* Month */
	unsigned short iDay;    /* Day */
	unsigned short iHour;   /* Hour */
	unsigned short iMinute; /* Minute */
	unsigned short iSecond; /* Second */
	unsigned short iMillisecond; /* Millisecond */
} NVS_FILE_TIME_V1,*PNVS_FILE_TIME_V1;

typedef struct tagITS_ILLEGALRECORD_V1
{
	int	 iBufSize;			//混合触发结构体大小
	long lCarID;
	int  iRecordFlag;
	int  iIllegalType;
	int  iPreset;
	char cCrossingID[LEN_64];		 //路口编号 64个字符
	char cLaneID[LEN_64];			 //车道编号	64个字符
	NVS_FILE_TIME_V1 m_tSnapTime;//抓拍开始时间(第一张图片抓拍时间)
}ITS_ILLEGALRECORD_V1,*pITS_ILLEGALRECORD_V1;

//智能分析叠加参数和颜色
typedef struct tagVCATargetParam
{
	int		iBufSize;						//叠加参数和颜色结构体大小
	int		iSceneID;						//场景编号(0~15)
	int		iDisplayTarget;					//视频是否叠加目标(0：不叠加 1：叠加)
	int		iDisplayTrace;					//视频是否叠加轨迹(0：不叠加 1：叠加)
	int		iTargetColor;					//目标和轨迹颜色(0:由程序自动设定颜色，每个目标一种颜色 
											//1：红色 2：绿色 3：黄色 4：蓝色 5：紫色 6：青色 7：黑色 8：白色)
	int		iTargetAlarmColor;				//报警时目标和轨迹的颜色(1：红色 2：绿色 3：黄色 4：蓝色 5：紫色 6：青色 7：黑色 8：白色)
	int		iTraceLength;					//轨迹长度(0～40)
}VCATargetParam,*pVCATargetParam;	

// 智能分析高级参数
typedef struct tagVCAAdvanceParam
{
	int		iBufSize;					//高级参数结构体大小
	int		iSceneID;					//场景编号(0~15)
	int		iTargetEnable; 				//是否启用高级参数
	int		iTargetMinSize; 			//目标最小像素数
	int		iTargetMaxSize; 			//目标最大像素数
	int   	iTargetMinWidth;  			//最大宽度
	int		iTargetMaxWidth;  			//最小宽度
	int		iTargetMinHeight;  			//最大高度
	int		iTargetMaxHeight;  			//最小高度
	int     iTargetMinSpeed;			//目标最小像素速度(-1为不做限制)
	int     iTargetMaxSpeed;			//目标最大像素速度(-1为不做限制)
	int 	iTargetMinWHRatio;			//目标的最小长宽比×100	（长/宽）×100
	int 	iTargetMaxWHRatio;			//目标的最大长宽比×100	（长/宽）×100
	int		iSensitivity;				//目标输出灵敏度级别(0: 低灵敏度 1：中灵敏度 2：高灵敏度)
	int		iForegroundMinDiff;			//前景最小差异(4~100)
	int		iForegroundMaxDiff;			//前景最大差异(4~100)
	int		iBackUpdateSpeed;			//背景更新速度(1~10)
	int		iRealTargetTime;			//目标确认帧数(10~30，默认为16)
	int		iBlendBackTime;				//融入背景时间(帧数 范围)
	int		iTarMergeSensitiv;			//目标合并灵敏度(0~100)
}VCAAdvanceParam,*pVCAAdvanceParam;	

//智能分析规则通用参数
typedef struct tagVCARule
{
	int		iSceneID;							//场景编号(0~15)
	int		iRuleID;							//规则ID(0~7)
	int		iValid;								//规则是否生效(0: 不生效 1:生效)
}VCARule,*pVCARule;

//智能分析规则参数
typedef struct tagVCARuleParam
{
	int					iBufSize;							//叠加参数和颜色结构体大小
	VCARule				stRule;								//规则通用参数
	char				cRuleName[VCA_MAX_RULE_NAME_LEN];	//规则名字
	int					iEventID;							//当前事件ID
}VCARuleParam,*pVCARuleParam;

//智能分析报警计数统计清零
typedef struct tagVCAAlarmStatisticClear
{
	int		iBufSize;					//报警计数统计清零结构体大小
	int		iSceneID;					//场景编号(0~15)
	int		iRuleID;					//规则ID(0~7)
	int		iEventType;					//事件类型(0：单绊线 1：双绊线 2：周界检测 3：徘徊 4：停车 5：奔跑 6：区域内人员密度 7：被盗物 
										//8：遗弃物9：人脸识别 10：视频诊断  11：智能跟踪  12：流量统计 13：人群聚集 14：离岗检测)
}VCAAlarmStatisticClear,*pVCAAlarmStatisticClear;

//Set AUDIO PONTICELLO
typedef struct tagAudioPonticello
{
	int				iSize;				// the size of Struct
	int				iTouchType;  		    
	int				iTouchParam;
	int				iPitchLevel;	
}AudioPonticello,pAudioPonticello;

typedef struct tagCallParam
{
	int		iBufSize;					//调用通用参数结构体大小
	int		iType;						//0-调用场景ID；1-调用隐私遮挡位置
	int		iValue;						//场景ID范围：0~15； 隐私遮挡位置范围：0~23
}CallParam, *pCallParam;

// Anxiety test/scene change
typedef struct tagVCA_TRuleParam_VideoDiagnose
{
	int  iSize;   		  // struct size
	int  iChannelNo ;	  // channel No.
	int  iSceneId ;		  // scene ID
	int  iRuleID ;		  // rule ID
	int  iDisplayStat ;	  // display alarm number or not
	int  iType ;		  // arithmetic enable type
	int  iEnable ;		  // enable type
	int  iLevel ;		  // level
	int  iTime ; 		  // test time
}VCA_TRuleParam_VideoDiagnose, *pVCA_TRuleParam_VideoDiagnose;

//Audio Exception
typedef struct tagVCA_TRuleParam_AudioDiagnose
{
	int  iSize;   			// struct size
	int  iChannelNo ;		// channel No.
	int  iSceneId ;			// scene ID
	int  iRuleID ;		    // rule ID
	int  iDisplayStat ;	    // display alarm number or not
	int  iType ;		    // arithmetic enable type
	int  iEnable ;		    // enable type
	int  iLevel ;		    // level
}VCA_TRuleParam_AudioDiagnose, *pVCA_TRuleParam_AudioDiagnose;

//VCA Tripwire for 300W
typedef struct tagVCA_TRuleParam_Tripwire
{
	int					iBufSize;
	VCARule				stRule;
	int					iTargetTypeCheck;
	vca_TDisplayParam	stDisplayParam;			
	int					iTripwireType;			//0: unidirectional, 1: bidirectional
	int					iTripwireDirection;		//(0～359°)
	int					iMinSize;				//[0, 100] init 5
	int					iMaxSize;				//[0, 100] init 30
	vca_TPolygonEx		stRegion1;				//Line1 Point Num and Points
}VCA_TRuleParam_Tripwire,*pVCA_TRuleParam_Tripwire;
//add end

//智能分析单拌线参数
typedef struct tagVCATripwire
{
	int					iBufSize;				//拌线结构体大小
	VCARule				stRule;					//规则通用参数
	int					iTargetTypeCheck;		//目标类型限制(0：不区分 1：区分人 2：区分车 3：区分人车 )
	int					iMinDistance;			//最小距离(目标运动距离必须大于此阈值)
	int					iMinTime;				//最短时间(目标运动距离必须大于此阈值)
	int					iTripwireType;			//穿越类型(0: 单向, 1: 双向)
	int					iTripwireDirection;		//禁止穿越方向(0～359度)
	vca_TDisplayParam	stDisplayParam;			//显示参数
	vca_TLine			stLine;					//绊线坐标
}VCATripwire,*pVCATripwire;

//智能分析双拌线参数
typedef struct tagVCADbTripwire
{
	int					iBufSize;
	VCARule				stRule;
	int					iTargetTypeCheck;
	vca_TDisplayParam	stDisplayParam;			
	int					iTripwireType;			//0: unidirectional, 1: bidirectional
	int					iDirTripwire1;			//tripwire 1 direction(0～359°)
	int					iDirTripwire2;			//tripwire 2 direction(0～359°)
	int					iMinDBTime;
	int					iMaxDBTime;
	int					iMinSize;				//[0, 100] default 5
	int					iMaxSize;				//[0, 100] default 30
	vca_TPolygonEx		stRegion1;				//Line1 Point Num and Points
	vca_TPolygonEx		stRegion2;				//Line2 Point Num and Points
}VCADbTripwire,*pVCADbTripwire;

//智能分析周界参数
typedef struct tagVCAPerimeter
{
	int					iBufSize;			//周界结构体大小
	VCARule				stRule;				//规则通用参数
	int					iTargetTypeCheck;	//区分目标类型(0：不区分 1：区分人 2：区分车 3：区分人车)
	int 				iMode;				//周界检测模式(0:入侵 1:进入 2:离开)
	int					iMinDistance;		//最小距离
	int					iMinTime;			//最短时间
	int					iType;				//是否做方向限制
	int					iDirection;			//禁止方向角度
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon		stRegion;			//区域范围	
	int  				iMiniSize;			//Min Size(range:0~100, default:5)
	int  				iMaxSize;			//Max Size(range:0~100, default:30)
}VCAPerimeter,*pVCAPerimeter;

//智能分析徘徊参数
typedef struct tagVCALinger
{
	int					iBufSize;			//徘徊结构体大小
	VCARule				stRule;				//规则通用参数
	int					iMinTime;			//徘徊最短时间(5000~600000毫秒，默认值：10000)
	int					iSensitivity;		//灵敏度(0~100)
	int					iMinRange;			//徘徊最小距离(0~100 图像宽度百分比，100表示整个屏幕的宽度)
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon		stRegion;			//区域范围
	int					iMinBoundy;			//circumscribed polygon area(range:0~100, default:5)
}VCALinger,*pVCALinger;	

//智能分析停车参数
typedef struct tagVCAParking
{
	int					iBufSize;			//停车结构体大小
	VCARule				stRule;				//规则通用参数
	int					iMinTime;			//触发停车报警的持续时间(0~30000毫秒，默认值：5000)
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon		stRegion;			//区域范围
	int					iMiniSize;			//Min Size(range:0~100, default:5)
	int					iMaxSize;			//Max Size(range:0~100, default:30)
	int					fThVelocity;		//threshold value(Accurate to one decimal places, *10 before to send the network protocol)
}VCAParking,*pVCAParking;	

//VCA Leave Detect   
typedef struct tagVCALeaveDetect
{
	int					iBufSize;
	VCARule				stRule;
	vca_TDisplayParam	stDisplayParam;			
	int					iLeaveAlarmTime;		
	int					iRuturnClearAlarmTime;	//Clear Alarm Time for People return
	int					iAreaNum;				//Area Num
	vca_TPolygon		stRegion1[MAX_AREA_NUM];//Area Point Num and Point	
	int					iDutyNum;				//[0, 5] init 2
	int					iMinSize;				//[0, 100] init 3
	int					iMaxSize;				//[0, 100] init 15
	int					iSensitivity;
}VCALeaveDetect,*pVCALeaveDetect;

//智能分析奔跑参数
typedef struct tagVCARunning
{
	int					iBufSize;			//奔跑结构体大小
	VCARule				stRule;				//规则通用参数
	int					iMaxDistance;		//人奔跑最大距离(0.01×100～1.00×100)
	int					iMinDistancePerSec;	//每秒最小移动距离(0~100 图像宽度百分比，100表示整个屏幕的宽度)
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon		stRegion;			//区域范围
	int  				iMiniSize;			//Min Size(range:0~100, default:5)
	int  				iMaxSize;			//Max Size(range:0~100, default:30)
}VCARunning,*pVCARunning;	

//VCA Face Mosaic
typedef struct tagVCAFaceMosaic 
{
	int					iBufSize;
	VCARule				stRule;
	vca_TDisplayParam	stDisplayParam;
	int					iMinSize;				//[0, 100] 
	int					iMaxSize;				//[0, 100] 
	int					iLevel;					//[0, 5] 
	int					iSensitiv;				//[0, 5] 
	int					iPicScal;				//[1, 10] 
	vca_TPolygonEx		stRegion1;				//[3, 32]
}VCAFaceMosaic,pVCAFaceMosaic;

//智能分析人群聚集参数
typedef struct tagVCACrowd
{
	int					iBufSize;			//人群聚集结构体大小
	VCARule				stRule;				//规则通用参数
	int					iSensitivity;		//灵敏度(0~100)
	int					iTimes;				//持续时间(秒)
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon		stRegion;			//区域范围
}VCACrowd,*pVCACrowd;

//智能分析遗弃物/被盗物参数
typedef struct tagVCADerelict
{
	int					iBufSize;			//遗弃物/被盗物结构体大小
	VCARule				stRule;				//规则通用参数
	int					iMinTime;			//遗弃物在区域存在的最短时间(0~30000毫秒，默认值：5000)
	int					iMinSize;			//最小像素尺寸(0~100像素，默认值：10)
	int					iMaxSize;			//最大像素尺寸(100~40000像素，默认值：10000)
	int 				iSunRegionNum;		//子多边形个数
	vca_TDisplayParam	stDisplayParam;		//显示参数
	vca_TPolygon 		stMainRegion;		//主多边形区域
	vca_TPolygon 		stSubRegion[VCA_MAX_OSC_REGION_NUM];	//子多边形区域
}VCADerelict,VCAStolen,*pVCADerelict,*pVCAStolen;

//智能分析-河道检测参数
typedef struct tagVCARiverClean
{
	int					iBufSize;			
	VCARule				stRule;				//规则通用参数
	vca_TDisplayParam	stDisplayParam;		//显示参数
	int					iType;				//模式 0:截面、河流交汇处漂浮物检测 1:坝前堆积物检测 2:站前拦网堆积物检测	
	int					iSensitivity;		//灵敏度 默认2	范围0-5
	int					iMinSize;			//疑似漂浮物 最小尺寸(画面宽度的百分比) ，默认值10	取值范围[8, 100]，单位：无
	int					iMaxSize;			//疑似漂浮物 最大尺寸(画面宽度的百分比) ，默认值30	取值范围[8, 100]，单位：无
	int 				iPercentage;		//疑似漂浮物 占比(画面宽度的百分比) 默认值 10	取值范围[8, 100]，单位：无
	vca_TPolygonEx		stPoints;			//多边形区域顶点个数以及坐标
}VCARiverClean,*pVCARiverClean;

//智能分析-盗采盗卸参数
typedef struct tagVCADredge
{
	int					iBufSize;			
	VCARule				stRule;				//规则通用参数
	vca_TDisplayParam	stDisplayParam;		//显示参数
	int					iSensitivity;		//灵敏度 默认2	范围0-5
	int					iMinSize;			//最小尺寸(画面宽度的百分比) ，默认值5	取值范围[0, 100]，单位：无
	int					iMaxSize;			//最大尺寸(画面宽度的百分比) ，默认值30	取值范围[0, 100]，单位：无
	int 				iTimeMin;			//报警时间 ，默认值3	取值范围[0, 3600]，单位：秒
	vca_TPolygonEx		stPoints;			//多边形区域顶点个数以及坐标
}VCADredge,*pVCADredge;

//智能分析-河道检测高级参数
typedef struct tagVCARiverAdvance
{
	int					iBufSize;			
	int					iSceneID;			//场景编号(0~15)
	int					iFGSampleNum;		//建模样本个数（默认值为20）
	int					iFGDistThresh;		//距离阈值（默认值为18）
	int					iFGCountThresh;		//计数阈值（默认值为15）
	int 				iFGLifeThresh;		//生命阈值（默认值为10）
}VCARiverAdvance,*pVCARiverAdvance;


typedef struct tagVCAChannelEnable
{
	int iBufSize;					//结构体大小
	int iEnable;
}VCAChannelEnable, *pVCAChannelEnable;

typedef struct tagVCAFacerec
{
	int iBufSize;					//结构体大小
	VCARule	stRule;
	vca_TDisplayParam stDisplayParam;			
	vca_TPolygon stRegion;				//	区域范围
}VCAFaceRec, *pVCAFacerec;

typedef struct tagVCATrace
{
	int iBufSize;					//结构体大小
	VCARule	stRule;
	vca_TDisplayParam stDisplayParam;			
	int					m_iStartPreset;			//起始跟踪点
	vca_TPolygon		m_TrackRegion;			//跟踪区域
	int					m_iScene;				//场景大/中/小
	int					m_iWeekDay;				//星期
	NVS_SCHEDTIME		m_timeSeg[MAX_DAYS][MAX_TIMESEGMENT];		//跟踪时间段
}VCATrace, *pVCATrace;

typedef struct tagVideoDetection
{
	int iBufSize;					//结构体大小
	VCARule	stRule;
	vca_TDisplayParam stDisplayParam;			
	int	m_iCheckTime;
}VideoDetection, *pVideoDetection;

typedef struct tagVCAVideoSize
{
	int iBufSize;					//结构体大小
	int iVideoSize;
}VCAVideoSize, *pVCAVideoSize;

//录像文件附加信息
#define MAX_FILE_APPEND_INFO_TYPE	2
typedef struct tagFileAppendInfo
{
	int		iBufSize;				//录像文件附加信息结构体大小
	int		iType;					//附加信息类型,0-保留 1-哈希
	char    cFileName[LEN_256];		//录像文件名
	char	cValue[LEN_256];		//iType取值1-代表录像文件的哈希值（字符串）
}FileAppendInfo, *pFileAppendInfo;

typedef struct tagVCASuspendResult
{
	int		iBufSize;				//结构体大小
	int		iStatus;				//状态(0:暂停智能分析 1:开启智能分析)
	int		iResult;				//结果(1:成功[表示可以设参] 2:失败[表示参数正在设置，不可设参])
}VCASuspendResult, *pVCASuspendResult;

typedef struct tagBackupDevModify
{
	int					iBufSize;			//结构体大小
	int					iDevType;			//设备类型(0:工作机操作热备机1:热备机操作工作机)
	int					iOptType;			//操作命令(0:ADD 1:DEL)	
	char				cIP[LEN_64];		//热备机IP
	char				cUserName[LEN_64];	//工作机登录用户名	
	char				cPassword[LEN_64];	//工作机登录密码	
}BackupDevModify,*pBackupDevModify;

typedef struct tagWorkDevInfo
{
	int					iBufSize;		//结构体大小
	int					iIndex;			//索引
	char				cIP[LEN_64];	//工作机IP地址	
}WorkDevInfo,*pWorkDevInfo;

typedef struct tagVirtualDisk
{
	int					iBufSize;			//结构体大小
	int 				iIndex;			//输入参数，指定索引值
	int					iOptType;		//操作类型
	char				cVDName[LEN_64];	//虚拟磁盘名称
	int					iVdSize;			//虚拟磁盘大小(单位为M)
	int					iInitType;	//初始化类型(1:前台2:后台3:快速) [新建、修复、删除操作时有效]
	char				cRaidName[LEN_64];	//阵列名称
}VirtualDisk,*pVirtualDisk;



#define MAX_RAID_DISK_NUM 16   
typedef struct tagRAIDWorkMode
{
	int		iBufSize;		             //结构体大小
	int		iDiskID;		             //磁盘编号(SATA1~SATA8编号～,SATA9~SATA16编号~1015)
	char	cRaidName[LEN_64];	         //阵列名称
	int		iWorkMode;		             //热备盘类型(0:空闲盘；1:阵列热备盘；2:全局热备盘；3：RAID盘；4：无效RAID盘；5：故障盘)
}RAIDDiskWorkMode, *pRAIDDiskWorkMode;
#define DISKWORKTYPE_RAIDHOTBACK	1

#define MAX_RAID_NUM 8	//全局最大支持8个阵列   
typedef struct tagRAIDState
{
	int					iBufSize;			//结构体大小
	int 				iIndex;				//输入参数，指定索引值
	char				cRaidName[LEN_64];	//阵列名称
	int					iRaidAllSize;		//总大小(单位为M)
	int					iRiadUseAbleSize;	//可用空间(单位为M)
	int					iRaidState;			//阵列状态(1:正常2:降级3:下线)
	int					iRaidTask;			//任务(1:无2:正在初始化3:正在重建)
	int					iRaidTaskPara1;		//任务状态参数(进度x.x%)
	int					iRaidTaskPara2;	    //任务状态参数(预计剩余时间x.x小时,x.x=0时不显示本条)
}RAIDState, *pRAIDState;              

#define MAX_VIRTUAL_DISK_NUM 16			//全局最大支持16个虚拟磁盘  
typedef struct tagVirtualDiskState
{
	int					iBufSize;			//结构体大小
	int 				iIndex;			    //输入参数，指定索引值
	char				cVDName[LEN_64];	//虚拟磁盘名称
	int					iVdUseAbleSize;		//虚拟磁盘可用空间(单位为M)
	int					iVdState;			//虚拟磁盘状态(1:正常2:降级3:下线)
	int					iVdTask;			//任务(1:无2:正在初始化3:正在修复)
	int					iVdTaskPara1;		//任务状态参数(进度x.x%)
	int					iVdTaskPara2;		//任务状态参数(预计剩余时间x.x小时,x.x=0时不显示本条)
}VirtualDiskState, *pVirtualDiskState;     

#define MAX_HDD_NUM 16   
#define WORKDEV_BROADCAST_BACKUPDEV		0   
#define BACKUPDEV_BROADCAST_WORKDEV		1   
#define MAX_WORK_DEV_COUNT		16			//最大工作机个数

typedef struct tagBackupDevState
{
	int					iBufSize;			//结构体大小
	int 				iIndex;				//输入参数，指定索引值
	char				cIP[LEN_64];		//设备IP
	int					iState;			    //状态([DevType=0 0:掉线1:在线2:正在同步]
	                                        //[DevType=1 0:热备1:备份2:同步])
	int					iProgress;		    //同步百分比(0~100)
}BackupDevState,WorkDevState, *pBackupDevState,*pWorkDevState;  

typedef struct tagRAIDDiskInfo
{
	int					iBufSize;			//结构体大小
	int					iDiskID;			//磁盘编号(SATA1~SATA8编号～,SATA9~SATA16编号~1015)
	int					iDiskType;			//磁盘类型(0:空闲盘1:阵列热备盘2:全局热备盘3:RAID盘4：无效RAID盘；5：故障盘)
	int					iDiskState;			//磁盘状态(0:正常1:异常2:健康预警)
	int					iDiskSize;			//磁盘大小(单位为M)
	char				cRaidName[LEN_64];	//阵列名称
	char				cDiskModel[LEN_64];	//磁盘型号
}RAIDDiskInfo,*pRAIDDiskInfo;

typedef struct tagIPSANDiskInfo
{
	int					iBufSize;			//结构体大小
	int					iDevNo;				//编号(0～)
	int					iEnable;			//是否启用(0:禁用1:启用)
	char				cDeviceIP[LEN_64];	//IP地址
	int					iDevicePort;		//端口号
	char				cUserName[LEN_32];	//用户名
	char				cPassword[LEN_32];	//密码
	char				cPath[LEN_64];		//目录
}IPSANDiskInfo,*pIPSANDiskInfo;

typedef struct tagIPSANDiscovery
{
	int					iBufSize;			//结构体大小
	int 				iDevType;			//类型(0:保留1:iSCSI)
	char				cDeviceIP[LEN_64];	//IP地址
	int					iDevicePort;		//端口号
	char				cUserName[LEN_32];	//用户名
	char				cPassword[LEN_32];	//密码
}IPSANDiscovery,*pIPSANDiscovery;


//获得IPSAN目录信息
typedef struct tagIPSANDirectoryInfo
{
	int					iBufSize;			//结构体大小
	int 				iIndex;				//输入参数，指定索引值
	char				cDeviceIP[LEN_64];	//IP地址
	char				cPath[LEN_64];		//目录
}IPSANDirectoryInfo,*pIPSANDirectoryInfo;


#define MAX_RAID_NUM_NUM				8
#define MAX_RAID_TYPE_NUM				4
#define MAX_IPSAN_INFO_NUM				8
#define MAX_IPSAN_DISCOVERY				16
//设备磁盘相关配置信息使用
#define NET_CLIENT_IPSAN_DISCOVERY				(NET_CLIENT_MIN + 0)	//IPSAN设备发现
#define NET_CLIENT_IPSAN_GET_DIR_COUNT			(NET_CLIENT_MIN + 1)	//IPSAN发现目录个数
#define NET_CLIENT_IPSAN_GET_DIRECTORY			(NET_CLIENT_MIN + 2)	//取出目录信息
#define NET_CLIENT_IPSAN_DISK_INFO				(NET_CLIENT_MIN + 3)	//IPSAN设备信息
#define NET_CLIENT_RAID_DISK_WORKMODE			(NET_CLIENT_MIN + 4)	//RAID磁盘工作模式
#define NET_CLIENT_RAID_DISK_INFO				(NET_CLIENT_MIN + 5)	//RAID磁盘信息
#define NET_CLIENT_RAID_ARRAY_MANAGE			(NET_CLIENT_MIN + 6)	//新建RAID阵列
#define NET_CLIENT_RAID_ARRAY_INFO				(NET_CLIENT_MIN + 7)	//获得RAID阵列信息
#define NET_CLIENT_RAID_STATE					(NET_CLIENT_MIN + 8)	//RAID状态
#define NET_CLIENT_RAID_VIRTUAL_DISK_MANAGE		(NET_CLIENT_MIN + 9)	//新建RAID虚拟磁盘
#define NET_CLIENT_RAID_VIRTUAL_DISK_INFO		(NET_CLIENT_MIN + 10)	//获得RAID虚拟磁盘信息
#define NET_CLIENT_RAID_VIRTUAL_DISK_STATE		(NET_CLIENT_MIN + 11)	//RAID虚拟磁盘状态

//raid 操作类型 0=保留；1=新建；2=重建； 3=删除
#define RAID_OPERATE_RESERVE		0
#define RAID_OPERATE_CREATE			1
#define RAID_OPERATE_REBUILD		2
#define RAID_OPERATE_DELETE			3

//RAID阵列信息
typedef struct tagRAIDArrayInfo
{
	int					iBufSize;					//结构体大小
	int 				iIndex;						//输入参数，指定索引值
	char				cRaidName[LEN_64];			//阵列名称
	int					iOptType;					//操作类型,0=保留；1=新建；2=重建； 3=删除
	int					iRaidType;					//阵列级别(0:RAID0 1:RAID1 5:RAID5 10:RAID10 100:JBOD)
	int					iBackDiskID;				//	-1表示无热备盘，大于0表示热备盘ID	
	char				cDiskModel[LEN_64];			//磁盘型号
	int					iDiskNum;					//磁盘个数
	int					iDisk[MAX_RAID_DISK_NUM];	//磁盘列表
}RAIDArrayInfo,*pRAIDArrayInfo;

typedef struct tagAlarmLink_V1
{
	int				iBuffSize;
	int				iSceneID;			//场景编号(0~15)
	int				iAlarmTypeParam1;	//报警类型参数
	int				iAlarmTypeParam2;	//报警类型参数
	int				iLinkType;			//联动类型
	int				iLinkTypeParam1;	//联动参数
	int				iLinkTypeParam2;	//联动参数
	int				iLinkTypeParam3;	//联动参数
	int				iLinkTypeParam[13];	//联动参数，支持512路扩展
}AlarmLink_V1, *PAlarmLink_V1;
/************************************************************************/
/*       报警类型      |      报警类型参数1    |      报警类型参数2     */
/*----------------------------------------------------------------------*/
/*      0:视频丢失     |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      1:端口报警     |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      2:移动侦测     |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      3:视频遮挡     |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      4:智能分析     |        规则ID         |         事件类型       */
/*----------------------------------------------------------------------*/
/*      5:音频丢失     |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      6:温湿度报警   |        未使用         |          未使用        */
/*----------------------------------------------------------------------*/
/*      7:违章检测     |        未使用         |          违章类型      */
/************************************************************************/
/*								事件类型								*/
/*----------------------------------------------------------------------*/
/* 0：单绊线 1：双绊线 2：周界检测 3：徘徊 4：停车 5：奔跑				*/
/* 6：区域内人员密度 7：被盗物 8：遗弃物 9：人脸识别 10：视频诊断		*/
/* 11：智能跟踪  12：流量统计 13：人群聚集 14：离岗检测 15：水位监测	*/
/*16：音频诊断 17：人脸遮挡(马赛克)										*/                                                           
/************************************************************************/
/*								违章类型								*/
/*----------------------------------------------------------------------*/
/* 1:卡口 2：闯红灯 3：逆行 4：超速 5：禁止左行驶 6：禁止右行驶 		*/
/* 7：压黄线 8：非机动车 9：不按导向行驶 10：禁止直行 11：占用公交车道 	*/
/* 12：压车道线 13：待转区域闯红灯 14：违法停车 15：违章停车 16：倒车	*/ 
/* 17：调头																*/ 
/************************************************************************/

/************************************************************************/
/*     联动类型    |    联动参数1    |    联动参数2   |    联动参数3    */
/*----------------------------------------------------------------------*/
/* 0:联动声音提示  |       使能      |      未使用    |      未使用     */
/*----------------------------------------------------------------------*/
/* 1:联动屏幕显示  |       使能      |      未使用    |      未使用     */
/*----------------------------------------------------------------------*/
/* 2:联动输出端口  |     按位使能    |      未使用    |      未使用     */
/*----------------------------------------------------------------------*/
/* 3:联动录像      |     按位使能    |      未使用    |      未使用     */
/*----------------------------------------------------------------------*/
/* 4:联动PTZ       |      通道号     |     0:不联动   |    未使用       */
/*                 |                 |     1:预置位   |    预置位号     */
/*                 |                 |     2:轨迹     |    轨迹号       */
/*                 |                 |     3:路径     |    路径号       */
/************************************************************************/
/*								   使能	    							*/
/*----------------------------------------------------------------------*/
/* 0，不使能；1，使能													*/
/************************************************************************/
/*							     按位使能								*/
/*----------------------------------------------------------------------*/
/* 从最低位至最高位每一位表示一个音视频通道/输出端口的使能				*/
/* 64路使用联动参数2表示后32路使能										*/
/************************************************************************/

//设置防伪码位数
typedef struct tagITS_SecurityCode
{
	int		iBufSize;	//结构体大小
	int		iPos;		//起始位置,取值为0-64
	int		iCount;		//防伪码位数,取值为0-64
}ITS_SecurityCode, *pITS_SecurityCode;

//车牌亮度补偿参数结构体
typedef struct tagITS_LightSupply
{
	int		iBufSize;		//结构体大小
	int		iIndex;			//时间段编号	0-7，支持最多8个时间段
	int		iFrontLight;	//顺光补偿值	
	int		iBackLight;		//逆光补偿值	
	int		iEnable;		//0-unable 1-enable(tolerant)
	int		iSensitivity;	//灵敏度(1,100)
	int		iPolarlzerValue;//偏振镜阈值(0,100）
}ITS_LightSupply, *pITS_LightSupply;

#define MAX_ITS_CAR_TYPE	3
//设置车道内车辆轮廓压线千分比参数
typedef struct tagITS_LinePressPermillage
{
	int  iBufSize;			//结构体大小
	int  iSceneId;			//场景ID,0~15
	int  iRoadID;			//车道编号,最大支持4个车道：0-3
	int  iCarType;			//车辆类型,0-保留，1-小车，2-大车
	int  iSpeed;			//车辆轮廓压线千分比【1-1000】
}ITS_LinePressPermillage,*pITS_LinePressPermillage;

//发送交通专用字符叠加
#define  MAX_ITS_OSDTYPE_NUM	       36		//标签类型数量
typedef struct tagITS_WordOverLay
{
	int  	iBufSize;							//结构体大小
	int  	iChannelNo;							//通道号
	int   	iOsdType;							//叠加字符的标签类型
	int   	iEnable;							//使能状态,单个位代表类型，字符串内容是整数.0: 叠加时间使能；,,,
	char  	pcOsdName[LEN_32+1];				//标签内容
	int   	iPosX;							    //横坐标
	int     iPosY;							    //纵坐标
	int		iZoomScale;							//缩放百分比	范围0-500，100代表无变化					
}ITS_WordOverLay,*pITS_WordOverLay;


#define MAX_ITS_CAPTURE_NUM	16
//抓拍张数结构体
typedef struct tagITS_CapCount
{
	int		iBufSize;		//结构体大小
	int		iCapType;		//抓拍类型	0-卡口抓拍 1--闯红灯 2--逆行 3--超速 4--禁止左行驶 5--禁止右行驶 6--压黄线 7--非机动车 
							//8--不按规定车道行驶(不按导向行驶) 9--禁止直行 10--公交车道 11--压车道线 12--待转区域闯红灯 13--违法停车
							//14--混合触发下视频抓拍超速功能使能 15--倒车 16--调头
	int		iCapCount;		//抓拍张数	取值为1，2,最小1，目前上限控制在10以内
}ITS_CapCount, *pITS_CapCount;

#define MAX_ILLEGAL_PARK_POINT_NUM		8
typedef struct tagITS_IVTMoveCTR
{
	int		iBufSize;		//结构体大小
	int		iXMove;			//上下方向运动坐标，精确到0.01 *100
	int		iYMove;			//左右方向运动坐标，精确到0.01 *100
	int		iZAim;			//倍数，精确到0.01*100*
}ITS_IVTMoveCTR, *pITS_IVTMoveCTR;

typedef struct tagITS_IllegalParkInfo
{
	int				iBufSize;										//结构体大小
	int				iPreset;										//预置位编号(场景ID),最多16个， 0~15
	int				iArea;											//区域编号,最多8个，0~7 
	int				iCalibrationStaus;								//0-未标定,1-手动标定,2-自动标定
	ITS_IVTMoveCTR	tITS_IVTMoveCTR[MAX_PARAM_COUNT];				//标定球机坐标，绝对值坐标
	POINT			tPoint[MAX_ILLEGAL_PARK_POINT_NUM];				//位置两个点坐标		
}ITS_IllegalParkInfo, *pITS_IllegalParkInfo;

typedef struct _tagITS_PicCutInfo
{
	int iSize;
	int iChannelNo;
	int iCutType;	// Picture cut types 0-base plate; 1-base car flag;2-base face
	int iCutScale;  //characteristics pictures cut range, such as 4, represent cut range is 1/4 of the size of raw picture.
}ITS_PicCutInfo, *pITS_PicCutInfo;

typedef struct tagCfgFileInfo
{
	int		iBufSize;				//结构体大小
	char	cFileName[LEN_64+1];	//文件名,64字节
	char	cSection[LEN_64+1];		//区段名,64字节
	char	cKey[LEN_64+1];			//关键字,64字节
	char	cValue[LEN_64+1];		//字段取值,如果本字段是多种数值类型则使用，逗号分割；例如“9600,n,7,2 ”
}CfgFileInfo, *pCfgFileInfo;

#define MAX_PLATFORM_NUM				10
#define MAX_APP_SERVER_LIST_NUM			10
//远程读取/设置温控数值
typedef struct tagAPPServerList
{
	int		iBufSize;					//结构体大小
	char	cAppName[LEN_32+1];			//平台名称，不超过32字节
	int		iServerListNum;				//服务数量，最多10个
	char	cServerListName[MAX_APP_SERVER_LIST_NUM][LEN_32+1];	//服务名称，不超过32字节
	int		iState[MAX_APP_SERVER_LIST_NUM];
}APPServerList, *pAPPServerList;

#define MAX_RTMP_NUM		16
//RTMP列表信息
typedef struct tagRtmpInfo
{
	int		iBufSize;			//结构体大小
	int		iRtmpNo;			//编号,取值0~15
	int		iRtmpChnNo;			//视频通道号
	int		iRtmpEnable;		//使能：使能后，可以推流；不使能后，禁止推流
	char	cRtmpUrl[LEN_256];	//Rtmp的URL字串,字符串信息：如："rtmp://10.30.31.21:1935/live"
}RtmpInfo, *pRtmpInfo;

//某通道支持帧率列表
#define MAX_FRAME_RATE_NUM		20
typedef struct tagFrameRateList
{
	int		iBufSize;			//结构体大小
	int		iChannelNo;			//通道号，取值范围根据设备实际能力而定，包括副码流。以16模拟+16数字的混合DVR为例，取值范围为0～63
								//三码流4n~5n-1
	int		iFrameRateNum;		//帧率个数，设备显示的帧率个数，即后续字段数
	int		iFrameRate[MAX_FRAME_RATE_NUM];	//帧率列表，按从大到小顺序存储。N制：60 30 25 20 15 10 5 1 ，P制：50 25 20 15 10 5 1
}FrameRateList, *pFrameRateList;

//RTSP列表信息
#define MAX_RTSP_LIST_NUM		64
typedef struct tagRtspListInfo
{
	int		iBufSize;			//结构体大小
	int		iRtspNo;			//rtsp编号，范围0~63
	char	cRtspIp[LEN_32];	//rtsp连接ip。默认0.0.0.0，“0.0.0.0”代表允许任何人连接
}RtspListInfo, *pRtspListInfo;

/////////////////////////////////动环新增////////////////////////////////
//报警输入通道类型
#define ALARM_INTERFACE_TYPE_MIN       0
#define ALARM_INTERFACE_TYPE_SWITCH    1  //switch
#define ALARM_INTERFACE_TYPE_ANALOG    2  //analog
#define ALARM_INTERFACE_TYPE_COM       3  //Serial port
#define ALARM_INTERFACE_TYPE_MAX       4


//动环报警配置 NetClient_SetAlarmConfig/ NetClient_GetAlarmConfig
#define CMD_DH_ALARM_MIN					(100)//动环报警类接口最小值
#define CMD_ALARM_IN_CONFIG                 (CMD_DH_ALARM_MIN + 0)//动环报警配置
#define CMD_ALARM_IN_LINK                   (CMD_DH_ALARM_MIN + 1)//动环报警联动
#define CMD_ALARM_IN_SCHEDULE				(CMD_DH_ALARM_MIN + 2)//动环布防模板配置
#define CMD_ALARM_IN_SCHEDULE_ENABLE        (CMD_DH_ALARM_MIN + 3)//动环布防使能配置
#define CMD_ALARM_IN_OSD                    (CMD_DH_ALARM_MIN + 4)//动环字符叠加配置
#define CMD_ALARM_IN_DEBUG                  (CMD_DH_ALARM_MIN + 5)//动环调试
#define CMD_ALARM_IN_OFFLINE_TIME_INTERVEL  (CMD_DH_ALARM_MIN + 6)//脱机间隔
#define CMD_DH_ALARM_HOST  					(CMD_DH_ALARM_MIN + 7)//报警服务器参数配置
#define CMD_DH_ADD_ALARM_HOST				(CMD_DH_ALARM_MIN + 8)//添加报警主机
#define CMD_DH_DEVICE_ENABLE				(CMD_DH_ALARM_MIN + 9)//设置动环设备使能
#define CMD_DH_ALARM_MAX					(CMD_DH_ALARM_MIN + 10)//MAX

#define MAX_NAME_LEN 64
#define MAX_IPADDRESS_LEN 64

typedef struct __tagAlarmInConfig
{	
	int iSize;
	char cName[MAX_NAME_LEN + 1];
	int iInterfaceType; //ALARM_IN_CHANNEL_TYPE_MIN~  ALARM_IN_CHANNEL_TYPE_MAX
	int iInterfaceNo ;
	int iScheduleNo;
	int iDelay;
	char cParam[MAX_DHINFO_PARAM_LEN];
}AlarmInConfig, *PAlarmInConfig;


typedef struct __tagAlarmInLink
{	
	int iSize;
	int  iLinkIndex;
	int iLinkEnable;
	char cName[MAX_NAME_LEN + 1];
	int iAlarmType; 
	int iLinkType;
	int  iDisappearType;		//消警类型
	int  iDisappearTime;        //消警时间
	char cParam[MAX_DHINFO_PARAM_LEN];
}AlarmInLink, *PAlarmInLink;

typedef struct __tagAlarmInSchedule
{	
	int iSize;
	int iScheduleNo;
	int iEnable;
	char cName[MAX_NAME_LEN + 1];
	int iWeekday;//0~6 周日~周一   -1 整周设置  
	NVS_SCHEDTIME	timeSeg[MAX_DAYS][MAX_DH_TIMESEGMENT];	
}AlarmInSchedule, *PAlarmInSchedule;

#define ALARM_IN_SCHEDULE_DISENABLE 0
#define ALARM_IN_SCHEDULE_ENABLE    1 
#define ALARM_IN_SCHEDULE_AUTO      2
#define MAX_ALARM_IN_SCHEDULE		3

typedef struct __tagAlarmInOSD
{	
	int iSize;
	int iOsdIndex;
	int iEnable;
	char cIP[LENGTH_IPV4];
	int iChannelNo;
	int iBlockNo;	
	int iColor;
}AlarmInOSD, *PAlarmInOSD;

typedef struct __tagAlarmInDebug
{	
	int iSize;
	char    cName[MAX_NAME_LEN + 1];
	int iDelayTime;
	char cParam[MAX_DHINFO_PARAM_LEN];
}AlarmInDebug, *PAlarmInDebug;

#define MAX_DH_ALARMTYPE_NUM		2
#define MAX_DH_ALARMHOST_NUM		8
typedef  struct _tagAlarmHost
{
	int iSize;				
	int iDevType;  				//报警主机类型0：网络报警主机；1：串口报警主机
	int	iDevNo;					//报警主机编号0-7
	int iEnable;				//使能标志0：禁用；1：启用
	char cDevAddr[LEN_64];		//报警主机地址，IP地址（最大64字节）
	int	iDevPort; 				//报警主机端口，0～65535（默认18803）
	int	iConnType;				//连接类型，1：TCP；2：UDP（默认）
	int	iPortInNum; 			//输入端口数
	int	iPortOutNum;			//输出端口数
}tAlarmHost, *ptAlarmHost;

//报警主机类型
#define ALARM_SERVER_NET               0
#define ALARM_SERVER_COM               1

//连接类型
#define ALARM_SERVER_CONNTYPE_TCP       1
#define ALARM_SERVER_CONNTYPE_UDP       2

typedef struct __tagLogInterval
{	
	int		iSize;
	int		iDelayTime;
}tLogInterval, *PtLogInterval;

typedef struct __tagComDevice
{
	int		iSize;				//Size of the structure,must be initialized before used
	int		iComNo;				//串口编号
	char	cComFormat[LEN_32];	//格式串9600,n,8,1
	int     iDeviceType;        //0- 1- 2-
	char	cParam[MAX_DHINFO_PARAM_LEN];
}ComDevice,*PComDevice;

#define FILE_COUNT			16	//最多支持个数
typedef struct ExportConfig
{
	int		iSize;		    //Size of the structure,must be initialized before used
	int		iCount;		    //输入数量			      
	char   	cFileList[FILE_COUNT][MAX_NAME_LEN];	//文件列表
	char    cFileOut[128];  //输出文件
} ExportConfig  ,*PExportConfig;

#define MAX_DH_SER_NO		100000   //动环流水号 
//动环数据上报 WCM_ALARM_INFORMATION
typedef struct __tagAlarmInfoData
{	
	int iSize;
	int iSerNo;
	int iDhInterfaceType;			  //通道类型
	int iStatus;
	int iChannelNo;
	int iAlarmType;
	int iAlarmState;
	int iDataType;
	unsigned long iTime;
	char cInfo[MAX_DHINFO_PARAM_LEN];	
}AlarmInfoData, *PAlarmInfoData;

//字符串发送接收的拆分最大数
#define MAX_RECV_AND_SPLIT_NUM		16   //动态接收或发送拆分的字符串数目
#define MAX_PROTOCO_SPLIT_NUM		40   //动态接收或发送拆分的协议字符串数目

//串口联动设备类型
#define	DH_COM_DEV_TYPE_TEM			0	  //温湿度	
#define	MAX_DH_DEV_TYPE				40    //最大支持的设备类型个数
#define MAX_DH_COM_PROTOCOL			40	  //最大支持协议类型种类(动环设备对应为支持的联动设备类型)

//DH报警联动
#define MAX_DH_ALARMLINK_NUM		16    //动环报警联动数目
#define MAX_DH_ALARMSCHE_NUM		16    //报警布防模板数目

//DH报警联动类型
#define DH_ALARM_LINK_TYPE_MIN				0
#define DH_ALARM_LINK_TYPE_RESERVE			(DH_ALARM_LINK_TYPE_MIN+0)	//保留
#define DH_ALARM_LINK_TYPE_OUT				(DH_ALARM_LINK_TYPE_MIN+1)	//报警输出
#define DH_ALARM_LINK_TYPE_OSD				(DH_ALARM_LINK_TYPE_MIN+2)	//OSD
#define DH_ALARM_LINK_TYPE_EMBATTLE			(DH_ALARM_LINK_TYPE_MIN+3)	//布防
#define DH_ALARM_LINK_TYPE_DISMANTLE		(DH_ALARM_LINK_TYPE_MIN+4)	//撤防
#define DH_ALARM_LINK_TYPE_RECOVERY			(DH_ALARM_LINK_TYPE_MIN+5)	//恢复自控
#define DH_ALARM_LINK_TYPE_MAX				(DH_ALARM_LINK_TYPE_MIN+6)

//DH消警类型
#define DH_ALARM_DISAPPEAR_TYPE_MIN				0
#define DH_ALARM_DISAPPEAR_TYPE_NOT				(DH_ALARM_LINK_TYPE_MIN+0)	//不恢复
#define DH_ALARM_DISAPPEAR_TYPE_DELAY			(DH_ALARM_LINK_TYPE_MIN+1)	//延时恢复
#define DH_ALARM_DISAPPEAR_TYPE_DIS_RECOVERY	(DH_ALARM_LINK_TYPE_MIN+2)	//消警恢复
#define DH_ALARM_DISAPPEAR_TYPE_DIS_DELAY		(DH_ALARM_LINK_TYPE_MIN+3)	//消警延时恢复
#define DH_ALARM_DISAPPEAR_TYPE_MAX				(DH_ALARM_LINK_TYPE_MIN+4)

#define MAX_DH_ALARM_HOST_NUM		16
typedef struct tagAddAlarmHost
{
	int iSize;					//结构体大小
	int iHostIndex;				//主机索引，[0,15]
	int iEnable;				//0--不使能，1--使能
	char cIP[LEN_32];			//报警主机IP
	int	iPort;					//报警主机端口
}AddAlarmHost, *pAddAlarmHost;
//////////////////////////////////动环新增///////////////////////////////

/////////////////////////////////电网////////////////////////////////
#define		Td_Alg_Meter_TaoGuanBiao_1					0/* 套管表（白底） */
#define		Td_Alg_Meter_ZhuBianYouBiao					1/* 主变油表 */
#define		Td_Alg_Meter_BiLeiQi						2/* 避雷器 */
#define		Td_Alg_Meter_DangWeiXianShiQi_1				3/* 档位显示器1（半径小）*/
#define		Td_Alg_Meter_WenDuBiao						4/* 温度表 */
#define		Td_Alg_Meter_KaiGuanFenHeQi					5/* 开关分合器 */
#define		Td_Alg_Meter_QiTiYaLiBiao					6/* 气体压力表 */
#define		Td_Alg_Meter_YaLiBiao						7/* 压力表 */
#define		Td_Alg_Meter_DaoZha							8/* 刀闸 */
#define		Td_Alg_Meter_BiLeiJianCeBiao				9/* 避雷检测表 */
#define		Td_Alg_Meter_WenDuBiaoQiTiBiao				10/* 温度表气体表 */

#define		Td_Alg_Meter_DuoGongNengDianNengBiao		11/* 多功能电能表 */
#define		Td_Alg_Meter_XianLuBaoHuZhuangZhi			12/* 线路保护装置 */
#define		Td_Alg_Meter_HuaLiDuoGongNengDianNeng		13/* 华立多功能电能 */
#define		Td_Alg_Meter_WeiShengDuoGongNengDianNeng	14/* 威胜多功能电能 */
#define		Td_Alg_Meter_ZhiNengWenShiDuKongZhiQi		15/* 智能温湿度控制器 */
#define		Td_Alg_Meter_KaiGuanZhiNengCaoKongZhuangZhi	16/* 开关智能操控装置 */
#define		Td_Alg_Meter_SanXiangDuoGongNengDianNeng	17/* 三相多功能电能 */
#define		Td_Alg_Meter_KaiGuan						18/* 开关 */
#define		Td_Alg_Meter_KaiGuanFenHeXianShiQi			19/* 开关分合显示器 */
#define		Td_Alg_Meter_TaoGuanBiao_2					20/* 套管表2（数字，半径大） */
#define		Td_Alg_Meter_MiDuJiDianQi					21/* 密度继电器 */
#define		Td_Alg_Meter_YouWeiJiBiao					22/* 油位计表 */
#define		Td_Alg_Meter_DangWeiXianShiQi_2				23/* 档位显示器2（红底） */

typedef struct tagEleNetMeter
{
	int iSize;					//结构体大小
	int iChanNo;				//通道号
	int iMeterType;				//仪表类型
	char cParam[1024];			//字符串
}EleNetMeter, *pEleNetMeter;
/////////////////////////////////电网/////////////////////////////////

//NvsType——0-T，1-S，2-T+
#define NVS_TYPE_T			0
#define NVS_TYPE_S			1
#define NVS_TYPE_T_OTHER	2

typedef struct tagLogonPara
{
	int		iSize;					//结构体大小
	char	cProxy[LEN_32];			//连接视频所经的上一级代理IP地址，不超过32个字符，包括‘\0’
	char	cNvsIP[LEN_32];			//IP地址，不超过32个字符，包括‘\0’
	char	cNvsName[LEN_32];		//Nvs name 域名解析时使用
	char	cUserName[LEN_16];		//登录Nvs用户名，不超过16个字符，包括‘\0’
	char	cUserPwd[LEN_16];		//登录Nvs密码，不超过16个字符，包括‘\0’
	char	cProductID[LEN_32];		//产品ID，不超过32个字符，包括‘\0’
	int		iNvsPort;				//该Nvs服务器所使用的通讯端口，若不指定则使用系统默认的端口(3000)。
	char	cCharSet[LEN_32];		//字符集
	char	cAccontName[LEN_16];	//连接目录服务器的帐户
	char	cAccontPasswd[LEN_16];	//连接目录服务器的帐户密码
}LogonPara, *pLogonPara;

//ITS图像检测参数新增结构体
typedef	struct tagITS_VideoDetect
{
	int			iSize;					//结构体大小
	int			iEngineType;
	int			iEnable;
	int			iVedioType;
	int			iVedioWidth;
	int			iVedioHeight;
	int			iVehicleMinSize;
	int			iVehicleMaxSize;
	int			iModelType;
	int			iFrameRateCount;
	int			iVDetectMotor;			//非机动车检测使能
	int			iSceneID;				//场景ID
	char		cParams130T[LEN_64];	//算法1的私有参数
	char		cParams130G[LEN_64];	//算法2的私有参数
	char		cParams110G[LEN_64];	//算法3的私有参数
}ITS_VideoDetect, *PITS_VideoDetect;

//ITS Roadway rader area config info struct
typedef	struct tagITS_RaderCfgInfo
{
	int			iSize;					//Size of Struct
	int			iRoadwayID;				//Roadway ID,range[0,3]
	int			iRaderAreaID;			//Rader area ID,range[1,8]
	int			iRaderAreaLeftEdge;		//Rader area left edge value,range[-200-200]
	int			iRaderAreaRightEdge;	//Rader area right edge value,range[-200-200]
	int			iRaderAreaLine;			//Rader area line,range[1,100] Unit :( m)
}ITS_RaderCfgInfo, *PITS_RaderCfgInfo;

//play back control CMD
#define		PLAY_CONTROL_PLAY			1			//play start
#define		PLAY_CONTROL_PAUSE			2			//play pause
#define     PLAY_CONTROL_SEEK           3
#define		PLAY_CONTROL_FAST			4			//play fast
#define		PLAY_CONTROL_SLOW			5			//play slow



//download state
#define		VOD_DOWNLOAD_NORMAL		0
#define		VOD_DOWNLOAD_PAUSE		1


typedef struct __tagVideoEncodList
{
	int iSize;		   //struct size	
	int iChnNo;        //dev channel no
	int iVideoEncode;  //EncodType:By byte：bit0，H.264；bit1，M-JPEG；bit2，MPEG4；bit3，H.265，def:0
}tVideoEncodList,*ptVideoEncodList;


typedef struct
{
	int iSize;    //结构体大小
	int iIndex;   //采样点
	int iTime;    //时间点
	int iCount;   //抓拍张数
	int iInterVal;//抓拍间隔
}WaterSampleSnapInfo,*pWaterSampleSnapInfo;

#define MAX_PRESET_NUM		32
typedef  struct WaterSamplePoint
{
	int iSize;
	VCARule	stRule;
	vca_TDisplayParam	stDisplayParam;		//显示参数
	int iSamplePointId;
	int iSnapInterval;
	int iBaseValue;       //base water level value
	int iCurrentPresetId; //current preset id
	int	iGaugeType;		//  水尺类型，0-保留，1-宽尺、新尺，2-窄尺、旧尺
	int iPresetCount;
	WaterPresetInfo stPresetInfo[MAX_PRESET_NUM];
}WaterSamplePoint, *LPWaterSamplePoint;

typedef struct _tagExceptionLinkOut
{
	int iSize;								//权限号
	int iExceptionType;						//异常类型
	unsigned int iExceptionEnable[LEN_16];  //异常使能
}tExceptionLinkOut, *ptExceptionLinkOut;

typedef struct _tagDiskOperation
{
	int iSize;
	int iAction;
	int iDiskNo;
}tDiskOperation, *pDiskOperation;
typedef struct tagScenetimePoint
{
	int					iBufSize;			
	int					iType;	
	int           		iIndex;
	int 				iEnable;			
	NVS_FILE_TIME		stStartTime;
	NVS_FILE_TIME		stEndTime;
}ScenetimePoint,*pScenetimePoint;

//reboot device by type
#define REBOOT_BY_DEVICE	0
#define REBOOT_BY_GUI		1
#define REBOOT_BY_APP		2

#define MAX_H323_GROUP_ID	1
/*****************************H.323 Local Param*****************************/
//ID code mode，0-UTF-8， 1-Unicode
#define H323_IDCODE_UTF8		0
#define H323_IDCODE_UNICODE		1
//Responds by call：0-automatic,1-manual,2-not disturb
#define  H323_RESPONDS_AUTOMATIC		0
#define  H323_RESPONDS_MANUAL			1
#define  H323_RESPONDS_NOTDISTURB		2

typedef struct _tagH323LocalParam
{
	int iSize;
	int iH323GroupId;				//H323 number,default 0
	int iListenPort;				//Listen port
	char cLocalNo[LEN_64];			//Terminal number
	char cPassWord[LEN_64];			//Encrytion password
	int iIdCodeType;				//ID code mode，0-UTF-8， 1-Unicode
	int iAnwTypeForCall;			//Responds by call：0-automatic,1-manual,2-not disturb
	int iMainSrcChnNo;				//Encode main stream channel number
	int	iSubSrcChnNo;				//Encode sub stream channel number
	int	iMainDecChnNo;				//Decode main stream channel number
	int	iSubDecChnNo;				//Decode sub stream channel number
}H323LocalParam, *pH323LocalParam;

/*****************************H.323 GK Param*****************************/
//GK Mode:0-disable,1-designation,2-auto search
#define  H323_GK_MODE_DISABLE		0
#define  H323_GK_MODE_DESIGNATION	1
#define  H323_GK_MODE_AUTOSEARCH	2
//GK Encrytion mode,0-shut down,1-automatic,2-zhongxing,3-xinshitong,4-sike
#define  H323_GK_ENCRYTION_SHUTDOWN			0	
#define  H323_GK_ENCRYTION_AUTOMATIC		1
#define  H323_GK_ENCRYTION_ZHONGXING		2
#define  H323_GK_ENCRYTION_XINGSHITONG		3
#define  H323_GK_ENCRYTION_SIKE				4

typedef struct _tagH323GKParam
{
	int iSize;
	int iH323GroupId;				//H323 number,default 0
	int iGKMode;					//GK Mode:0-disable,1-designation,2-auto search
	char cGKAddress[LEN_64];		//GK address,64 bytes
	int iGKPort;					//GK port
	char cRegisterName[LEN_64];		//Register Name,64 bytes
	int iGKEncrytionType;			//GK Encrytion mode,0-shut down,1-automatic,2-zhongxing,3-xinshitong,4-sike
}H323GKParam, *pH323GKParam;

#define VCA_ARITHMETIC_TYPE_MIN							0						//Arithmetic Type Min
#define VCA_ARITHMETIC_BEHAVIOR_ANALYSIS		(VCA_ARITHMETIC_TYPE_MIN+0)		//Behavior Analysis
#define VCA_ARITHMETIC_LICENSE_RECOGNITION		(VCA_ARITHMETIC_TYPE_MIN+1)		//License Plate Recognition
#define VCA_ARITHMETIC_FACE_DETECT				(VCA_ARITHMETIC_TYPE_MIN+9)		//face detect
#define	VCA_ARITHMETIC_VIDEO_DETECT				(VCA_ARITHMETIC_TYPE_MIN+10)	//Video Detect
#define	VCA_ARITHMETIC_TRACK					(VCA_ARITHMETIC_TYPE_MIN+11)	//track
#define	VCA_ARITHMETIC_FLUX_STATISTIC			(VCA_ARITHMETIC_TYPE_MIN+12)	//Flux Statistics
#define	VCA_ARITHMETIC_CROWDS					(VCA_ARITHMETIC_TYPE_MIN+13)	//Crowds
#define	VCA_ARITHMETIC_LEAVE_DETECT				(VCA_ARITHMETIC_TYPE_MIN+14)	//Leave Detect
#define	VCA_ARITHMETIC_AUDIO_DIAGNOSE			(VCA_ARITHMETIC_TYPE_MIN+16)	//Audio Diagnose
#define VCA_ARITHMETIC_ILLEAGEPARK				(VCA_ARITHMETIC_TYPE_MIN+20)	//Illeage Park
#define	VCA_ARITHMETIC_TYPE_MAX					(VCA_ARITHMETIC_TYPE_MIN+21)	//Arithmetic Type Max

#define VCA_BEHAVIOR_TYPE_TRIPWIRE				(1<<0)  						//Tripwire 0
#define VCA_BEHAVIOR_TYPE_DBTRIPWIRE			(1<<1)  						//Double Tripwire 1
#define VCA_BEHAVIOR_TYPE_PERIMETER				(1<<2)  						//Perimeter 2
#define VCA_BEHAVIOR_TYPE_LOITER				(1<<3)  						//Loiter 3
#define VCA_BEHAVIOR_TYPE_PARKING				(1<<4)  						//Parking 4
#define VCA_BEHAVIOR_TYPE_RUN					(1<<5)  						//Running 5
#define VCA_BEHAVIOR_TYPE_OBJSTOLEN				(1<<7)  						//Stolen Objects 7
#define VCA_BEHAVIOR_TYPE_ABANDUM				(1<<8)  						//Abandum Objects 8


//设备发送协议的宏，IE区分新老设备
//与通道无关
#define PROTOCOL_VCALIST					(1<<0)
#define PROTOCOL_DHDEVICESET				(1<<1)
#define PROTOCOL_DHALARMLINK				(1<<2)
#define PROTOCOL_DHOSDREALTIME				(1<<3)
#define PROTOCOL_DHDEVENABLE				(1<<4)
#define PROTOCOL_IPCPLUGANDPLAY				(1<<5)
//与通道有关
#define PROTOCAL_VCA						(1<<0)
#define PROTOCAL_CAMERAPARA					(1<<1)
#define PROTOCAL_DOMEPARA					(1<<2)
#define PROTOCOL_ALARMLINK					(1<<3)
#define PROTOCOL_ALARMSCHEDULE				(1<<4)
#define PROTOCOL_VIDEOROI					(1<<5)
#define PROTOCOL_AUDIOCODERLIST				(1<<6)
#define PROTOCOL_DOMEPTZ					(1<<7)
#define PROTOCOL_MULTIWORDOVERLAY			(1<<8)
#define PROTOCOL_TIMESEGMENT				(1<<9)


typedef struct _tagVcaArithmeticList
{
	int iSize;						//size of struct
	int iChannelNo;					//channel number
	int iArithmeticType;			//arithmetic type
	int iEnableCount;				//enable count
	int* piEnableValue;				//enable value
} VcaArithmeticList, *pVcaArithmeticList;

typedef struct _tagDownloadByTimeSpan
{
	int				iSize;							//size of struct
	NVS_FILE_TIME	tStartTime;						//Start Time
	NVS_FILE_TIME	tStopTime;						//Stop Time
	char			cLocalFilename[LEN_256-1];		//Local File Name
	int				iFileType;						//sdv:0; avi:1
} DownloadByTimeSpan, *pDownloadByTimeSpan;

typedef struct _tagPotocolEnable
{
	int iSize;
	int iEnable;
}PotocolEnable, *pPotocolEnable;

#define LIFE_MONITOR_TYPE_MIN					1
#define LIFE_MONITOR_HEART_RATE			LIFE_MONITOR_TYPE_MIN + 0
#define LIFE_MONITOR_OXYGEN				LIFE_MONITOR_TYPE_MIN + 1
#define LIFE_MONITOR_BLOOD_PRESSURE		LIFE_MONITOR_TYPE_MIN + 2
#define LIFE_MONITOR_TYPE_MAX			LIFE_MONITOR_TYPE_MIN + 3	
// Vital signs in real time heart rate and blood oxygen
typedef struct _tagLifeMonitorHBReal
{
	int iSize;
	int iMonType;			//Monitor type	1:heart rate, 2:oxygen, 3:blood pressure
	int	iMonStatus;			//Monitor status	1:normal, 2:Super caps, 3:Ultra-limit, 4:Shedding, 5:Device Offline, 6:testing blood pressure
	int	iMonRealVal1;		//Real-time value1	
	int	iMonRealVal2;		//Real-time value2	
	int	iMonRealVal3;		//Real-time value3	
	int	iMonRealVal4;		//Real-time value4	
} LifeMonitorHBReal, *pLifeMonitorHBReal;

//Vital signs waveform data
#define MAX_WAVEFORM_GRAM_ID	2
#define MAX_GRAM_SEQ_NUMBER		3
typedef struct _tagLifeMonitorGramReal
{
	int iSize;
	int iOscilloGramID;		//Gram ID	1:Electrocardiographic 2:Oxygen wave
	int	iGramSeq;			//The current wave number starting with 1, the heart waves can be divided into three packs,
							//followed by 1,2,3 transfer, oxygen wave only one package, this value is 1
	int	iGramRate;			//The frequency of collection points
	int	iReserved;			//Reserved value,default 0
	int	iPointCount;		//The total count of points collected
	int* piPoints;
} LifeMonitorGramReal, *pLifeMonitorGramReal;

#define MAX_LIFE_MONITOR_CMD_ID	2
typedef struct _tagLifeMonitorConfig
{
	int iSize;
	int iMonType;			//Monitor type,	1:heart rate, 2:oxygen, 3:blood pressure, 0x7FFFFFFF:All(default value)
	int	iCmdID;				//Command ID,	1:Set whether to report IE, 2:Set whether OSD
	int	iCmdContent;		//Command content,	iCmdID=1:1--yes 0--no, iCmdID=2:1--yes,0--no
} LifeMonitorConfig, *pLifeMonitorConfig;

typedef struct _tagOSDExtraInfo
{
	int iSize;
	int iOsdType;		//1:channel name 2:time and date 3:logo color 4:Extra OSD 5:ITS use 6:ITS combine picture
	int	iBgColor;		//back color,"32 is taken low 24 indicates color rgb,representative digitally bgr:Other bits reserved 0x00BBGGRR high eight,do not use."					
	int	iDigitNum;		//Superimposed digits,it shows the median insufficient bit zeros				
} OSDExtraInfo, *pOSDExtraInfo;

//设置违停球违章停车抓拍样式参数
#define MAX_ITS_IPDCAPMODEL_NUM		8		//最大违停抓拍张数
#define MAX_ITS_CAPTYPE				2		//最大抓拍类型
typedef  struct _tagIpdCapModel
{
	int	 iSize;
	int  iChannelNo;
	int  iPreset;
	int  iCapType;
	int  iCapNum;
	int  iCapStyle[MAX_ITS_IPDCAPMODEL_NUM];   
}tITS_IpdCapModel, *ptITS_IpdCapModel;

//标记人工抓拍车辆位置
#define  MAX_ITS_IPDCARPOSITION_NUM   15		//最大坐标数
#define MAX_REGION_NUM			      16		//区域编号
typedef  struct _tagIpdCarPosition
{
	int  iSize;
	int  iChannelNo;
	int  iSceneId;
	int  iRegionID;
	int  iEnabled;
	int  iCount;
	vca_TPoint	m_arrPoint[MAX_ITS_IPDCARPOSITION_NUM];  
}tITS_IpdCarPosition, *ptITS_IpdCarPosition;

typedef struct _tagServerInfo
{
	int		iSize;
	int		iAppID;					//apply type
	char	cAddress[LEN_16];		//server addr				
	int		iProt;					//server port			
}tServerInfo, *ptServerInfo;

#endif
