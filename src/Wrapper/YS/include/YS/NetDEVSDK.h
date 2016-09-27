#ifndef _NETDEV_H_
#define _NETDEV_H_

#ifdef  __cplusplus
extern "C"{
#endif

#ifndef STATIC
    #define STATIC                  static
#endif

#ifndef CONST
    #define CONST                   const
#endif

#ifndef EXTERN
    #define EXTERN                  extern
#endif

#ifndef INLINE
    #define INLINE                  __inline
#endif

#ifndef UNION
    #define UNION                   union
#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef INOUT
    #define INOUT
#endif

#ifndef NEWINTERFACE
    #define NEWINTERFACE
#endif

#if defined(WIN32)  /* windows */
#if defined(NETDEV_SDK_DLL)
#define NETDEV_API                  __declspec(dllexport)
#else
#define NETDEV_API                  __declspec(dllimport)
#endif
#else
#define NETDEV_API
#endif

/* 函数标准调用约定 Standard function calling convention */
#ifdef i386
    #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))
    #endif
#else
    #ifndef WIN32
    #ifndef STDCALL
        #define STDCALL
    #endif
#else
    #ifndef STDCALL
        #define STDCALL                 __stdcall
    #endif
#endif

#endif

#ifndef UCHAR_DEF
#define UCHAR_DEF
    typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
    typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
    typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
    typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
    typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
    typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
    typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
    typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
    typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
    typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
    typedef int                     BOOL;
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
    typedef float                   FLOAT;
#endif
#endif

#ifndef FALSE
    #define FALSE                   0
#endif

#ifndef TRUE
    #define TRUE                    1
#endif

#ifndef WIN32
    typedef LPVOID                 HWND;
#endif

/********************************** 常用数值宏  Commonly used numerical macros *************** */

/* 流ID标识长度  Length of stream ID*/
#define NETDEV_STREAM_ID_LEN                    32

/* 文件名长度  Length of filename */
#define NETDEV_FILE_NAME_LEN                    (256u)

/* 用户名最大长度  Maximum length of username */
#define NETDEV_USER_NAME_LEN                    32

/* 密码最大长度  Maximum length of password */
#define NETDEV_PASSWD_LEN                       64

/* 用户登录密码,密文口令（加密后）字符串长度  Length of password and encrypted passcode for user login */
#define NETDEV_PASSWD_ENCRYPT_LEN               64

/* 资源编码信息字符串长度  Length of resource code string */
#define NETDEV_RES_CODE_LEN                     48

/* 域名最大长度  Maximum length of domain name */
#define NETDEV_DOMAIN_LEN                       64

/* 设备名称最大长度  Maximum length of device name */
#define NETDEV_DEVICE_NAME_LEN                  32

/* 路径最大长度  Maximum length of path */
#define NETDEV_PATH_LEN_WITHOUT_NAME            64

/* 路径最大长度:包括文件名称  Maximum length of path, including filename */
#define NETDEV_PATH_LEN                         128

/* Email地址最大长度  Maximum length of email address */
#define NETDEV_EMAIL_NAME_ADDR                  32

/* Mac地址长度  Length of MAC address */
#define NETDEV_MAC_ADDR_LEN                     6

/* gsoap调用endpoint长度  Length of endpoint called by gSOAP */
#define NETDEV_ENDPOINT_LEN                     96

/* 引流ID最大长度  Maximum length of session ID */
#define NETDEV_SESSION_ID_LEN                   16

/* URL 的最大长度  Maximum length of URL */
#define NDE_MAX_URL_LEN                         260

/* 通用长度  Common length */
#define NETDEV_LEN_4                            4
#define NETDEV_LEN_8                            8
#define NETDEV_LEN_16                           16
#define NETDEV_LEN_32                           32
#define NETDEV_LEN_64                           64
#define NETDEV_LEN_128                          128
#define NETDEV_LEN_132                          132
#define NETDEV_LEN_260                          260

/* IP 地址信息字符串长度  Length of IP address string */
#define NETDEV_IPADDR_STR_MAX_LEN              (64u)

/* 通用名称字符串长度  Length of common name string */
#define NETDEV_NAME_MAX_LEN                    (20u)

/* 通用CODE 长度  Length of common code */
#define NETDEV_CODE_STR_MAX_LEN                (48u)

/* 最大日期字符长度 Maximum length of date string "2008-10-02 09:25:33.001 GMT" */
#define NETDEV_MAX_DATE_STRING_LEN             (64u)

/* 时间信息字符串长度 Length of time string "hh:mm:ss" */
#define NETDEV_SIMPLE_TIME_LEN                 (12u)

/* 日期信息字符串长度 Length of date string "YYYY-MM-DD"*/
#define NETDEV_SIMPLE_DATE_LEN                 (12u)

/* 告警输入最大数量  Maximum number of alarm inputs */
#define NETDEV_MAX_ALARM_IN_NUM                 64

/* 告警输出最大数量  Maximum number of alarm outputs */
#define NETDEV_MAX_ALARM_OUT_NUM                64

/* 一天中的计划时间段  Number of scheduled time sections in a day */
#define NETDEV_PLAN_SECTION_NUM                 8

/* 一周总共可配置的计划个数,包括周一至周日和假日  Total number of plans allowed in a week, including Monday to Sunday, and holidays */
#define NETDEV_PLAN_NUM_AWEEK                   8

/* 最大可配置移动侦测区域个数  Maximum number of motion detection areas allowed */
#define NETDEV_MAX_MOTION_DETECT_AREA_NUM       4

/* 最大可配置遮盖区域个数  Maximum number of privacy mask areas allowed */
#define NETDEV_MAX_PRIVACY_MASK_AREA_NUM        8

/* 最大可配置遮挡区域个数  Maximum number of tamper-proof areas allowed */
#define NETDEV_MAX_TAMPER_PROOF_AREA_NUM        1

/* 通道字符叠加数量  Maximum number of text overlays allowed for a channel */
#define NETDEV_MAX_TEXTOVERLAY_NUM              6

/* 视频通道最大流个数  Maximum number of video streams */
#define NETDEV_MAX_VIDEO_STREAM_NUM             8

/* 月数/每年  Month of the year */
#define NETDEV_MONTH_OF_YEAR                    12

/* 天数/每月  Day of the month */
#define NETDEV_DAYS_OF_MONTH                    32

/* 设备ID长度  Length of device ID */
#define NETDEV_DEV_ID_LEN                       64

/* 设备序列号长度  Length of device serial number */
#define NETDEV_SERIAL_NUMBER_LEN                32

/* 单次最大查询个数  Maximum number of queries allowed at a time */
#define NETDEV_MAX_QUERY_NUM                    200

/* 总共最大查询个数  Total number of queries allowed */
#define NETDEV_MAX_QUERY_TOTAL_NUM              2000

/* IPC最大个数  Maximum number of IP cameras */
#define NETDEV_MAX_IPC_NUM                      128

/* 预置位最大数  Maximum number of presets */
#define NETDEV_MAX_PRESET_NUM                   256

/* 巡航路径中预置位点最大个数  Maximum number of presets for preset patrol */
#define NETDEV_MAX_CRUISEPOINT_NUM              32

/* 预置位巡航路径最大条数  Maximum number of routes for preset patrol */
#define NETDEV_MAX_CRUISEROUTE_NUM              16

/* 云台移动速度  PTZ rotating speed */
#define NETDEV_MIN_PTZ_SPEED_LEVEL              1
#define NETDEV_MAX_PTZ_SPEED_LEVEL              9

/* 图像参数（亮度 对比度 色度 饱和度）最大/小值  Maximum / Minimum values for image parameters (brightness, contrast, hue, saturation) */
#define NETDEV_MAX_VIDEO_EFFECT_VALUE           255
#define NETDEV_MIN_VIDEO_EFFECT_VALUE           0

/* 图像参数（伽马值）最大值 Minimum values for image parameters (Gama) */
#define NETDEV_MAX_VIDEO_EFFECT_GAMMA_VALUE     10

/* 连接超时时间最大值  Maximum connection timeout */
#define NETDEV_MAX_CONNECT_TIME_VALUE           75000

/* 连接超时时间最小值  Minimum connection timeout */
#define NETDEV_MIN_CONNECT_TIME_VALUE           300

/* 最大用户数  Maximum number of users */
#define NETDEV_MAX_USER_NUM                     (256 + 32)

/* 最大实时预览的路数  Maximum number of channels allowed for live preview */
#define NETDEV_MAX_REALPLAY_NUM                 128

/* 最大回放或下载的路数  Maximum number of channels allowed for playback or download */
#define NETDEV_MAX_PALYBACK_NUM                 128

/* 最大建立报警通道的路数  Maximum number of alarm channels */
#define NETDEV_MAX_ALARMCHAN_NUM                128

/* 最大硬盘格式化的路数  Maximum number of channels allowed for formatting hard disk */
#define NETDEV_MAX_FORMAT_NUM                   128

/* 最大文件搜索的路数  Maximum number of channels allowed for file search */
#define NETDEV_MAX_FILE_SEARCH_NUM              2000

/* 最大日志搜索的路数  Maximum number of channels allowed for log search */
#define NETDEV_MAX_LOG_SEARCH_NUM               2000

/* 最大建立透明通道的路数  Maximum number of channels allowed for creating transparent channels */
#define NETDEV_MAX_SERIAL_NUM                   2000

/* 最大升级的路数  Maximum number of channels allowed for upgrade */
#define NETDEV_MAX_UPGRADE_NUM                  256

/* 最大语音转发的路数  Maximum number of channels allowed for audio forwarding */
#define NETDEV_MAX_VOICE_COM_NUM                256

/* 最大语音广播的路数  Maximum number of channels allowed for audio broadcast */
#define NETDEV_MAX_VOICE_BROADCAST_NUM          256

/* 超时时间最大值,单位毫秒  Maximum timeout, unit: ms */
#define NETDEV_MAX_CONNECT_TIME                 75000

/* 超时时间最小值,单位毫秒  Minimum timeout, unit: ms */
#define NETDEV_MIN_CONNECT_TIME                 300

/* 超时时间默认值,单位毫秒  Default timeout, unit: ms */
#define NETDEV_DEFAULT_CONNECT_TIME             3000

/* 连接尝试次数  Number of connection attempts */
#define NETDEV_CONNECT_TRY_TIMES                1

/* 用户保活失败次数  User keep-alive interval */
#define NETDEV_KEEPLIVE_TRY_TIMES               3

/* 通道 OSD 字符叠加数量  Number of OSD text overlays */
#define NETDEV_OSD_TEXTOVERLAY_NUM              6

/* 通道 OSD 字符长度  Length of OSD texts */
#define NETDEV_OSD_TEXT_MAX_LEN                 (64u)

/* 拉告警最大告警个数  Maximum number of alarms a user can get */
#define NETDEV_PULL_ALARM_MAX_NUM               8

/* 支持的轨迹巡航的最大条数  Maximum number of patrol routes allowed  */
#define NETDEV_TRACK_CRUISE_MAXNUM               1

/* 音量调节最小值  Minimum volume */
#define NETDEV_AUDIO_SOUND_MIN_VALUE            0

/* 音量调节最大值  Maximum volume */
#define NETDEV_AUDIO_SOUND_MAX_VALUE            255

/* 麦克风音量调节最小值  Minimum volume */
#define NETDEV_MIC_SOUND_MIN_VALUE              0

/* 麦克风音量调节最大值  Maximum volume */
#define NETDEV_MIC_SOUND_MAX_VALUE              255

/* 屏幕信息行数  Screen Info Row */
#define NETDEV_SCREEN_INFO_ROW                  18

/* 屏幕信息列数  Screen Info Column */
#define NETDEV_SCREEN_INFO_COLUMN               22

/* BEGIN**************************** 错误码 Error codes ************************************************************/
#define NETDEV_E_SUCCEED                        0           /* 成功  Succeeded*/
#define NETDEV_E_FAILED                         -1          /* 失败  Failed*/

/* 通用错误码  Common error codes */
#define NETDEV_E_COMMON_FAILED                  1           /* 通用错误  Common error */
#define NETDEV_E_DEV_COMMON_FAILED              2           /* 由设备返回的通用错误  Common error returned by device */
#define NETDEV_E_SYSCALL_FALIED                 3           /* 系统函数调用失败,请查看errno  Failed to call system function. See errno */
#define NETDEV_E_NULL_POINT                     4           /* 空指针  Null pointer */
#define NETDEV_E_INVALID_PARAM                  5           /* 无效参数  Invalid parameter */
#define NETDEV_E_INVALID_MODULEID               6           /* 无效模块ID  Invalid module ID */
#define NETDEV_E_NO_MEMORY                      7           /* 内存分配失败  Failed to allocate memory */
#define NETDEV_E_NOT_SUPPORT                    8           /* 设备不支持  Not supported by device */
#define NETDEV_E_SDK_SOCKET_LSN_FAIL            9           /* 创建socket listen失败  Failed to create socket listen */
#define NETDEV_E_INIT_MUTEX_FAIL                10          /* 初始化锁失败  Failed to initialize lock */
#define NETDEV_E_INIT_SEMA_FAIL                 11          /* 初始化信号量失败  Failed to initialize semaphore */
#define NETDEV_E_ALLOC_RESOURCE_ERROR           12          /* SDK资源分配错误  Error occurred during SDK resource allocation */
#define NETDEV_E_SDK_NOINTE_ERROR               13          /* SDK未初始化  SDK not initialized */
#define NETDEV_E_ALREDY_INIT_ERROR              14          /* SDK已经初始化。  SDK already initialized */
#define NETDEV_E_HAVEDATA                       15          /* 还有数据   Data not all sent */
#define NETDEV_E_NEEDMOREDATA                   16          /* 需要更多数据  More data required  */
#define NETDEV_E_CONNECT_ERROR                  17          /* 创建连接失败  Failed to create connection */
#define NETDEV_E_SEND_MSG_ERROR                 18          /* 发送请求消息失败  Failed to send request message */
#define NETDEV_E_TIMEOUT                        19          /* 消息超时  Message timeout */
#define NETDEV_E_DECODE_RSP_ERROR               20          /* 解析响应消息失败  Failed to decode response message */
#define NETDEV_E_SOCKET_RECV_ERROR              21          /* Socket接收消息失败  Socket failed to receive message */
#define NETDEV_E_NUM_MAX_ERROR                  22          /* 个数达到最大。分配的注册连接数、预览连接数超过SDK支持的最大数  Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK */
#define NETDEV_E_GET_PORT_ERROR                 24          /* 获取本地端口号失败  Failed to obtain local port number */
#define NETDEV_E_CREATE_THREAD_FAIL             25          /* 创建线程失败  Failed to create thread */
#define NETDEV_E_NOENOUGH_BUF                   26          /* 缓冲区太小: 接收设备数据的缓冲区  Buffer is too small for receiving device data */
#define NETDEV_E_GETLOCALIPANDMACFAIL           27          /* 获得本地PC的IP地址或物理地址失败  Failed to obtain the IP or MAC address of the local PC */
#define NETDEV_E_RESCODE_NO_EXIST               28          /* 资源编码不存在  Resource code not exist */
#define NETDEV_E_MSG_DATA_INVALID               31          /* 消息内容错误  Incorrect message content */
#define NETDEV_E_GET_CAPABILITY_ERROR           32          /* 获取能力级失败  Failed to obtain capabilities */
#define NETDEV_E_USER_NOT_BIND                  33          /* 该用户没有订阅告警   User not subscribed to alarms */
#define NETDEV_E_AUTHORIZATIONFAIL              34          /* 用户鉴权失败  User authentication failed */
#define NETDEV_E_BINDNOTIFY_FAIL                35          /* 绑定告警失败  Failed to bind alarms*/
#define NETDEV_E_NOTADMIN                       36          /* 操作权限不足,windows下一般为非管理员帐号操作导致 Not enough permission. In Windows, it is normally because the operator is not an administrator. */
#define NETDEV_E_DEVICE_FACTURER_ERR            37          /* 不支持的设备厂商 Manufacturers that are not supported */
#define NETDEV_E_NONSUPPORT                     38          /* 该功能不支持  Function not supported */
#define NETDEV_E_TRANSFILE_FAIL                 39          /* 文件传输失败  File transmission failed */
#define NETDEV_E_JSON_ERROR                     40          /* Json 通用错误  Json common error */
#define NETDEV_E_NO_RESULT                      41          /* 查无结果   No result */

/* 用户相关错误码  User-related error codes */
#define NETDEV_E_USER_WRONG_PASSWD              101         /* 用户密码错误  Incorrect password */
#define NETDEV_E_USER_LOGIN_MAX_NUM             102         /* 用户登录数已达上限  Number of login users reached the upper limit */
#define NETDEV_E_USER_NOT_ONLINE                103         /* 用户不在线  User not online */
#define NETDEV_E_USER_NO_SUCH_USER              104         /* 没有该用户  User not online */
#define NETDEV_E_USER_NO_AUTH                   105         /* 用户无权限  User has no rights */
#define NETDEV_E_USER_MAX_NUM                   106         /* 用户上限-不能再被添加  Reached the upper limit–no more users can be added */
#define NETDEV_E_USER_EXIST                     107         /* 用户已存在  User already exists */
#define NETDEV_E_USER_PASSWORD_CHANGE           108         /* 用户密码修改  Password changed */
#define NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD   109         /* 远程用户弱密码错误  Remote user with weak password */

/* 业务相关错误码  Service-related error codes */

/* 回放相关错误码  Playback-related error codes */
#define NETDEV_E_VOD_PLAY_END                   250         /* 回放结束  Playback ended */
#define NETDEV_E_VOD_NO_CM                      251         /* 回放控制块不存在  Playback controlling module not exist */
#define NETDEV_E_VOD_OVER_ABILITY               252         /* 回放能力超出限制  Beyond playback capability */
#define NETDEV_E_VOD_NO_RECORDING_CM            253         /* 录像文件控制块不存在  Recording file controlling module not exist */
#define NETDEV_E_VOD_NO_RECORDING               254         /* 无录像内容   No recording */
#define NETDEV_E_VOD_NO_REPLAYURL               255         /* 无法获取回放的url   Cannot get the URL for playback*/


/* 云台相关错误码  PTZ-related error codes */
#define NETDEV_E_PTZ_SET_PRESET_FAILED              300         /* 预置位设置失败  Failed to set preset */
#define NETDEV_E_PTZ_QUERY_PRESET_FAILED            301         /* 预置位查询失败  Failed to query preset */
#define NETDEV_E_PTZ_QUERY_TRACK_FAILED             302         /* 轨迹查询失败  Failed to query route */
#define NETDEV_E_PTZ_START_RECORD_TRACK_FAILED      303         /* 开始录制轨迹失败  Failed to start route recording */
#define NETDEV_E_PTZ_STOP_RECORD_TRACK_FAILED       304         /* 结束录制轨迹失败  Failed to end route recording */
#define NETDEV_E_PTZ_QUERY_CRUISE_FAILED            305         /* 巡航线路查询失败  Failed to query patrol route */
#define NETDEV_E_PTZ_SET_CRUISE_FAILED              306         /* 巡航线路设置失败  Failed to set patrol route */
#define NETDEV_E_PTZ_CTRL_FAILED                    307         /* 云台操作失败  PTZ operation failed */
#define NETDEV_E_PTZ_PRESET_IN_CRUISE               308         /* 预置位在巡航线路中使用, 无法删除  Preset is being used in patrol route and cannot be deleted */
#define NETDEV_E_PTZ_CRUISEPOINT_ERR                309         /* 设置巡航点不连续  Discontinuous presets */
#define NETDEV_E_PTZ_TRACK_ISUSED                   310         /* 轨迹已使用,无法删除  Route is in use and cannot be deleted */
#define NETDEV_E_PTZ_SERIALMODE_MISMATCH            311         /* 串口模式不匹配  Serial modes do not match */
#define NETDEV_E_PTZ_TRACK_NOT_EXIST                312         /* 轨迹不存在  Route does not exist */
#define NETDEV_E_PTZ_MODE_CRUISE_FULL               313         /* 模式路径轨迹点个数已满  Route points are full */


/* SOAP相关错误码  SOAP-related error codes */
#define NETDEV_E_DEVICE_STREAM_FULL                 500         /* 设备流已满  Device stream full */
#define NETDEV_E_DEVICE_STREAM_CLOSED               501         /* 设备流已关闭  Device stream closed */
#define NETDEV_E_DEVICE_STREAM_NONEXIST             502         /* 设备流不存在  Device stream does not exist */

#define NETDEV_E_COMMON_FAIL_STAT                   503         /* 读取文件（目录）状态失败  Failed to read file (directory) status */
#define NETDEV_E_COMMON_FILE_NONEXIST               504         /* 文件不存在  File does not exist */
#define NETDEV_E_COMMON_MKDIR_ERR                   505         /* 创建目录失败  Failed to create directory */
#define NETDEV_E_SUBSCRIBE_FULL                     506         /* 本用户订阅已满, 设备侧用户订阅已满的错误码不能返回  Subscription is full for current user */
#define NETDEV_E_UPGRADE_NOTADMIN                   507         /* 非admin用户无法升级  Only admin can upgrade */
#define NETDEV_E_UPGRADE_INVALID                    508         /* 升级 未开始  Upgrade not started */
#define NETDEV_E_UPGRADE_INPROCESS                  509         /* 升级 处理中  Upgrade in process */
#define NETDEV_E_UPGRADE_NOMEMORY                   510         /* 升级 内存空间不够  Insufficient memory for upgrade */
#define NETDEV_E_UPGRADE_FILE_OPEN_ERR              511         /* 升级 打开镜像文件出错  Error occurred while opening the mirror file during upgrade */
#define NETDEV_E_UPGRADE_DEVICE_ERR                 512         /* 升级 FLASH出错  Error occurred while upgrading FLASH */
#define NETDEV_E_UPGRADE_BUSY                       513         /* 不能同时加载多个升级进程  Cannot load multiple upgrade processes at the same time */
#define NETDEV_E_UPGRADE_FAIL_TIMEOUT               514         /* 升级超时  Upgrade timeout */
#define NETDEV_E_INVALID_CONFIGFILE                 515         /* 配置文件无效  Invalid configuration file */
#define NETDEV_E_STOR_RESOURCE_NOTINIT              516         /* 存储资源未分配  Storage resource not allocated */

#define NETDEV_E_PLAYER_BASE_ERR                    1000        /* 解码基础错误码  Basic decoding error code */
#define NETDEV_E_PLAYER_FAIL                        1001        /* 执行失败  Basic decoding error code */
#define NETDEV_E_PLAYER_INVALID_PARAM               1002        /* 输入参数非法  Invalid input parameter */
#define NETDEV_E_PLAYER_NO_MEMORY                   1003        /* 系统内存不足  Not enough system memory */
#define NETDEV_E_PLAYER_SOCKET_FAIL                 1004        /* 创建SOCKET失败  Failed to create SOCKET */
#define NETDEV_E_PLAYER_RECV_FAIL                   1005        /* 接收失败  Failed to receive */
#define NETDEV_E_PLAYER_RECV_ZERO                   1006        /* 接收为零  None received */
#define NETDEV_E_PLAYER_NOT_SUPPORT                 1007        /* 功能暂不支持  Currently not supported */
#define NETDEV_E_PLAYER_CREATETHREAD_FAILED         1008        /* 创建线程失败  Failed to create the thread */
#define NETDEV_E_PLAYER_OPENDL_FAILED               1009        /* 加载动态库失败  Failed to load the dynamic library */
#define NETDEV_E_PLAYER_SYMDL_FAILED                1010        /* 获取动态方法失败  Failed to get the dynamic library */
#define NETDEV_E_PLAYER_SEND_FAILED                 1011        /* 发送失败  Failed to send */
#define NETDEV_E_PLAYER_EACCES                      1012        /* 创建文件权限不足  No permission to create the file */
#define NETDEV_E_PLAYER_FILE_NOT_FIND               1013        /* 读文件未找到  Failed to find the file to read */
#define NETDEV_E_PLAYER_LOG_CLOSE                   1014        /* 日志关闭  Close log */

/*********************** Player 资源相关********************************/
#define NETDEV_E_FAIL_TO_INIT_EZPLAYER              1257        /* 初始化播放器失败  Failed to initialize the player */
#define NETDEV_E_FAIL_TO_ALLOC_PORT_RES             1258        /* 分配播放通道资源失败  Failed to allocate playing channel resources */
#define NETDEV_E_FAIL_TO_GET_PORT_RES               1259        /* 获得播放通道资源失败  Failed to get playing channel resources */
#define NETDEV_E_BUFFER_QUEUE_FULL                  1260        /* 缓存队列已满  Cache queue full */
#define NETDEV_E_BUFFER_QUEUE_EMPTY                 1261        /* 缓存队列空  Cache queue empty */
#define NETDEV_E_OPEN_FILE_FAILED                   1262        /* 打开文件失败  Failed to open the file */
#define NETDEV_E_FILE_READ_END                      1263        /* 文件已经读取完毕  The file is read */
#define NETDEV_E_FILE_DISKSPACE_FULL                1264        /* 磁盘空间满  Disk space full */
#define NETDEV_E_FILE_READ_FAIL                     1265        /* 读取失败  Failed to read */
#define NETDEV_E_MCM_MIC_NOT_EXIST                  1266        /* 麦克风不存在  The microphone does not exist */
#define NETDEV_E_TS_PACKET_IN_THE_ROUGH             1267        /* TS打包未完成  TS packing not finished */
#define NETDEV_E_FILE_RECORD_FINISH                 1268        /* 录像保存完毕  Recording saved */

#define NETDEV_E_FAIL_TO_OPEN_STREAM                1513        /* 启动媒体流播放失败  Failed to start media streaming */
#define NETDEV_E_FAIL_TO_CLOSE_STREAM               1514        /* 关闭媒体流播放失败  Failed to close media streaming */
#define NETDEV_E_FAIL_TO_RECV_DATA                  1515        /* 网络故障导致接收数据失败  Failed to receive data due to network error */
#define NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         1516        /* 媒体数据处理失败  Failed to handle media data */
#define NETDEV_E_NOT_START_PLAY                     1517        /* 播放通道未开始播放操作  Playing not started in playing channel */
#define NETDEV_E_FAIL_TO_INPUT_DATA                 1518        /* 输入媒体流数据失败  Failed to enter media stream data */
#define NETDEV_E_INPUTDATA_BUFFER_FULL              1519        /* 输入数据缓存满  Input data cache full */
#define NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        1520        /* 设置媒体流数据回调函数失败  Failed to set media stream data callback function */
#define NETDEV_E_VOICE_RUNNING                      1521        /* 语音业务运行过程中出错  Error occurred when running voice service */
#define NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             1522        /* 启动语音业务失败  Failed to start voice service */
#define NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            1523        /* 关闭语音业务失败  Failed to close voice service */
#define NETDEV_E_UNKNOWN_STREAM_TYPE                1524        /* 未知媒体流  Unknown media stream */
#define NETDEV_E_PACKET_LOSE                        1525        /* 丢包  Packet loss */
#define NETDEV_E_NEED_MORE_PACKET                   1526        /* 拼包未完成,需要更多包  More packets are needed for the packing */
#define NETDEV_E_FAIL_TO_CREATE_DECODE              1527        /* 创建解码器失败  Failed to create the decoder */
#define NETDEV_E_FAIL_TO_DECODE                     1528        /* 解码失败 Failed to decode */
#define NETDEV_E_RECV_DATA_NOTENOUGH                1529        /* 接收数据不足  Not enough data received */
#define NETDEV_E_RENDER_RES_FULL                    1530        /* 显示资源满  Display resources full */
#define NETDEV_E_RENDER_RES_NOT_EXIST               1531        /* 显示资源不存在  Display resources do not exist */
#define NETDEV_E_CREATE_DEV_FAILED                  1532        /* 资源创建失败  Failed to create the resources */
#define NETDEV_E_AUDIO_RES_NOT_EXIST                1533        /* 音频资源不存在  Audio resources do not exist */
#define NETDEV_E_IHW265D_NEED_MORE_BITS             1534        /* 解码器需要更多数据  Decoder requires more data */
#define NETDEV_E_FAIL_TO_CREATE_ENCODE              1535        /* 创建编码器失败  Failed to create encoder */
#define NETDEV_E_CAPTURE_RES_EXIST                  1536        /* 采集资源不存在  Capture resources do not exist */
#define NETDEV_E_RECORD_STARTED                     1537        /* 录像已打开  Recording already opened */
#define NETDEV_E_NEED_WAIT_DECODEC                  1538        /* 未解码完成,需要等待  Decoding in progress, please wait */
#define NETDEV_E_MORE_DATA_NEED_PACKET              1539        /* 数据过多,还需要继续打包  Too much data, still need packing */

/* 实况相关错误码  Live video error codes */
#define NETDEV_E_LIVE_EXISTED                       2000        /* 实况业务已经建立  Live video service already established */
#define NETDEV_E_LIVE_INPUT_NOT_READY               2001        /* 媒体流未准备就绪  Media stream not ready */
#define NETDEV_E_LIVE_OUTPUT_BUSY                   2002        /* 实况业务显示资源忙  Display resource is busy for live video service */
#define NETDEV_E_LIVE_CB_NOTEXIST                   2003        /* 实况控制块不存在  Control module for live video not exist */
#define NETDEV_E_LIVE_STREAM_FULL                   2004        /* 实况流资源已满  Live stream resource full */

/* 抓拍相关错误码  Capture-related error codes */
#define NETDEV_E_CAPTURE_NO_SUPPORT_FORMAT          2100        /* 抓拍格式不支持  Format of captured image not supported */
#define NETDEV_E_CAPTURE_NO_ENOUGH_CAPACITY         2101        /* 硬盘空间不足  Insufficient disk space */
#define NETDEV_E_CAPTURE_NO_DECODED_PICTURE         2102        /* 没有解码过的图片可供抓拍  No decoded image for capture */
#define NETDEV_E_CAPTURE_SINGLE_FAILED              2103        /* 单次抓拍操作失败  Single capture failed */

/* 语音对讲相关错误码  Error codes related to two-way audio */
#define NETDEV_E_AUDIO_EXISTED                      2200        /* 语音对讲已存在  Two-way audio already exists */
#define NETDEV_E_AUDIO_NO_EXISTED                   2201        /* 语音业务不存在  Two-way audio service does not exist */
#define NETDEV_E_AUDIO_RESCODE_INVALID              2202        /* 语音对讲资源编码无效  Invalid two-way audio resource code */
#define NETDEV_E_AUDIO_RES_USED_BY_TALK             2203        /* 语音资源已被对讲使用  Audio resource is being used by two-way audio */
#define NETDEV_E_AUDIO_FAILED                       2204        /* 语音对讲失败  Two-way audio failed */
#define NETDEV_E_AUDIO_AUDIOBCAST_FULL              2205        /* 语音业务已满  No more audio service allowed */

/* END********************* 错误码  Error codes *********************************************************** */

/* BEGIN:****************** 枚举值  Enumeration value ***************************************************** */

/**
 * @enum tagNETDEVChannelStatus
 * @brief 通道状态 枚举定义 Channel status Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVChannelStatus
{
    NETDEV_CHL_STATUS_OFFLINE,      /* 通道离线  Channel offline */
    NETDEV_CHL_STATUS_ONLINE,       /* 通道在线  Channel online */
    NETDEV_CHL_STATUS_VIDEO_LOST,   /* 视频丢失  Video lost */
    NETDEV_CHL_STATUS_MAX,

    NETDEV_CHL_STATUS_BUTT
}NETDEV_CHANNEL_STATUS_E;

/**
 * @enum tagNETDEVCameraType
 * @brief 摄像机类型 枚举定义 Camera type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVCameraType
{
    NETDEV_CAMERA_TYPE_FIX         = 0,            /* 固定摄像机  Fixed camera */
    NETDEV_CAMERA_TYPE_PTZ         = 1,            /* 云台摄像机  PTZ camera */

    NETDEV_CAMERA_TYPE_INVALID     = 0xFF          /* 无效值  Invalid value */
}NETDEV_CAMERA_TYPE_E;

/**
 * @enum tagNETDEVLiveStreamIndex
 * @brief 实况业务流索引 枚举定 义 Live stream index Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN  = 0,   /* 主流  Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX   = 1,   /* 辅流  Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD = 2,   /* 第三流  Third stream */

    NETDEV_LIVE_STREAM_INDEX_BUTT
}NETDEV_LIVE_STREAM_INDEX_E;

/**
 * @enum tagHOSTType
 * @brief IP协议类型 枚举定义  Protocol type Enumeration definition
 * @attention 无 None
 */
typedef enum tagHOSTType
{
    NETDEV_NETWORK_HOSTTYPE_IPV4 = 0,               /* IPv4 */
    NETDEV_NETWORK_HOSTTYPE_IPV6 = 1,               /* IPv6 */
    NETDEV_NETWORK_HOSTTYPE_DNS  = 2                /* DNS */
}NETDEV_HOSTTYPE_E;


/**
 * @enum tagNETDEVProtocal
 * @brief 媒体传输协议 枚举定义  Media transport protocol Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPTCP = 1,         /* TCP */
    NETDEV_TRANSPROTOCAL_RTPUDP = 2          /* UDP */
}NETDEV_PROTOCAL_E;

/**
 * @enum tagNETDEVMediaFileFormat
 * @brief 媒体文件格式 枚举定义  Media file format Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVMediaFileFormat
{
    NETDEV_MEDIA_FILE_MP4 = 0,           /* mp4格式的媒体文件  mp4 media file */
    NETDEV_MEDIA_FILE_TS = 1,            /* TS格式的媒体文件  TS media file */
    NETDEV_MEDIA_FILE_BUTT
}NETDEV_MEDIA_FILE_FORMAT_E;

/**
 * @enum tagNETDEVVideoCodeType
 * @brief 视频编码格式 枚举定义  Video encoding format Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoCodeType
{
    NETDEV_VIDEO_CODE_MJPEG = 0,          /* MJPEG */
    NETDEV_VIDEO_CODE_H264  = 1,          /* H.264 */
    NETDEV_VIDEO_CODE_H265  = 2,          /* H.265 */
    NETDEV_VIDEO_CODE_BUTT
}NETDEV_VIDEO_CODE_TYPE_E;

/**
 * @enum tagNETDEVVideoFrameType
 * @brief 视频帧类型 枚举定义  Video frame type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I = 0,               /* 视频帧为I帧  I-frame */
    NETDEV_VIDEO_FRAME_P = 1,               /* 视频帧为P帧  P-frame */
    NETDEV_VIDEO_FRAME_B = 2                /* 视频帧为B帧  B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
 * @enum tagNETDEVRenderScale
 * @brief 视频显示比例 枚举定义  Video display ratio Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL       = 0,                  /* 图像填充整个播放 窗格  Stretch */
    NETDEV_RENDER_SCALE_PROPORTION = 1,                  /* 图像按比例显示  Scale */

    NETDEV_RENDER_SCALE_BUTT       = 0xFF
}NETDEV_RENDER_SCALE_E;

/**
 * @enum tagNETDEVPictureFormat
 * @brief 图片格式 枚举定义 Picture type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPictureFormat
{
    NETDEV_PICTURE_BMP = 0,                  /* 图片格式为bmp格式  Picture format is bmp */
    NETDEV_PICTURE_JPG = 1,                  /* 图片格式为jpg格式  Picture format is jpg */

    NETDEV_PICTURE_BUTT
}NETDEV_PICTURE_FORMAT_E;

/**
 * @enum tagNETDEVVideoQuality
 * @brief 视频图像质量 枚举定义  Video image quality Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /* 最高  Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /* 较高  Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /* 中  Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /* 低  Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /* 较低  Lower */
    NETDEV_VQ_L9 = 31,                   /* 最低  Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1,        /* 无效  Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
 * @enum tagNETDEVPictureSize
 * @brief 图像分辨率 枚举定义 Image resolution Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPictureSize
{
    NETDEV_PICTURE_SIZE_D1     = 0,           /* D1 */
    NETDEV_PICTURE_SIZE_4CIF   = 1,           /* 4CIF */
    NETDEV_PICTURE_SIZE_2CIF   = 2,           /* 2CIF */
    NETDEV_PICTURE_SIZE_CIF    = 3,           /* CIF */
    NETDEV_PICTURE_SIZE_960H   = 4,           /* 960H */
    NETDEV_PICTURE_SIZE_QCIF   = 5,           /* QCIF */
    NETDEV_PICTURE_SIZE_HALFD1 = 6,           /* HALFD1 */
    NETDEV_PICTURE_SIZE_720    = 7,           /* 720 */
    NETDEV_PICTURE_SIZE_1080   = 8,           /* 1080 */
    NETDEV_PICTURE_SIZE_XGA    = 9,           /* 1024*768 */
    NETDEV_PICTURE_SIZE_SXGA   = 10,          /* 1280*1024 */

    NETDEV_PICTURE_SIZE_INVALID               /* 无效值  Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
 * @enum tagNETDEVPtzCmdEnum
 * @brief 云台命令 枚举定义 PTZ commands Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPtzCmdEnum
{
#if 0
    NETDEV_PTZ_IRISCLOSE            =0x0102,       /* 光圈关  Iris close */
    NETDEV_PTZ_IRISOPEN             =0x0104,       /* 光圈开  Iris open */
#endif
    NETDEV_PTZ_FOCUSNEAR            = 0x0202,       /* 近聚集  Focus near */
    NETDEV_PTZ_FOCUSFAR             = 0x0204,       /* 远聚集  Focus far */
    NETDEV_PTZ_ZOOMTELE             = 0x0302,       /* 放大  Zoom in */
    NETDEV_PTZ_ZOOMWIDE             = 0x0304,       /* 缩小  Zoom out */
    NETDEV_PTZ_TILTUP               = 0x0402,       /* 向上  Tilt up */
    NETDEV_PTZ_TILTDOWN             = 0x0404,       /* 向下  Tilt down */
    NETDEV_PTZ_PANRIGHT             = 0x0502,       /* 向右  Pan right */
    NETDEV_PTZ_PANLEFT              = 0x0504,       /* 向左  Pan left */
    NETDEV_PTZ_LEFTUP               = 0x0702,       /* 左上  Move up left */
    NETDEV_PTZ_LEFTDOWN             = 0x0704,       /* 左下  Move down left */
    NETDEV_PTZ_RIGHTUP              = 0x0802,       /* 右上  Move up right */
    NETDEV_PTZ_RIGHTDOWN            = 0x0804,       /* 右下  Move down right */

#if 0
    NETDEV_PTZ_PRESAVE              = 0x0601,       /* 预置位保存  Save preset */
    NETDEV_PTZ_PRECALL              = 0x0602,       /* 预置位调用  Call preset */
    NETDEV_PTZ_PREDEL               = 0x0603,       /* 预置位删除  Delete preset */
#endif

    NETDEV_PTZ_ALLSTOP              = 0x0901,       /* 全停命令字  All-stop command word */

    NETDEV_PTZ_TRACKCRUISE          = 0x1001,       /* 开始轨迹巡航  Start route patrol*/
    NETDEV_PTZ_TRACKCRUISESTOP      = 0x1002,       /* 停止轨迹巡航  Stop route patrol*/
    NETDEV_PTZ_TRACKCRUISEREC       = 0x1003,       /* 开始录制轨迹  Start recording route */
    NETDEV_PTZ_TRACKCRUISERECSTOP   = 0x1004,       /* 停止录制轨迹  Stop recording route */
    NETDEV_PTZ_TRACKCRUISEADD       = 0x1005,       /* 添加巡航轨迹  Add patrol route */
    NETDEV_PTZ_TRACKCRUISEDEL       = 0x1006,       /* 删除轨迹巡航  Delete patrol route */

    NETDEV_PTZ_AREAZOOMIN           = 0x1101,       /* 拉框放大  Zoom in area */
    NETDEV_PTZ_AREAZOOMOUT          = 0x1102,       /* 拉框缩小  Zoom out area */
    NETDEV_PTZ_AREAZOOM3D           = 0x1103,       /* 3D定位  3D positioning */

    NETDEV_PTZ_BRUSHON              = 0x0A01,       /* 雨刷开  Wiper on */
    NETDEV_PTZ_BRUSHOFF             = 0x0A02,       /* 雨刷关  Wiper off */

    NETDEV_PTZ_LIGHTON              = 0x0B01,       /* 灯开  Lamp on */
    NETDEV_PTZ_LIGHTOFF             = 0x0B02,       /* 灯关  Lamp off */

    NETDEV_PTZ_HEATON               = 0x0C01,       /* 加热开  Heater on */
    NETDEV_PTZ_HEATOFF              = 0x0C02,       /* 加热关  Heater off */

    NETDEV_PTZ_SNOWREMOINGON        = 0x0D01,       /* 除雪开  Snowremoval on */
    NETDEV_PTZ_SNOWREMOINGOFF       = 0x0D02,       /* 除雪关  Snowremoval off  */

#if 0
    NETDEV_PTZ_ABSPOSITION          = 0x0902,       /* 设置摄像机绝对角度  Set absolute position of camera */
    NETDEV_PTZ_GUARD                = 0x0903,       /* 回看守位,该命令不在云台模板体现  Return to home position (this command is not implemented on the PTZ template) */
    NETDEV_PTZ_SPEEDSET             = 0x0904,       /* 设置速度  Set speed */

    NETDEV_PTZ_INFRAREDON           = 0x0E01,       /* 红外开  IR on */
    NETDEV_PTZ_INFRAREDOFF          = 0x0E02,       /* 红外关  IR off */

    NETDEV_PTZ_PRESETCRUISE         = 0x1001,       /* 云台按预置位巡航 ,该命令字不在云台模板体现  Preset-based PTZ patrol (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_PRESETCRUISESTOP     = 0x1002,       /* 云台按预置位巡航停止,该命令字不在云台模板体现  Preset-based PTZ patrol stop (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_CRUISEDEL            = 0X1003,       /* 删除线路  Delete route */
    NETDEV_PTZ_CRUISEADDPRESET      = 0x1004,       /* 往线路中添加预置位  Add preset to route */
    NETDEV_PTZ_CRUISEADDSTART       = 0x1005,       /* 开始往线路中添加预置位  Start adding preset to route */
    NETDEV_PTZ_CRUISEADDSTOP        = 0x1006,       /* 结束往线路中添加预置位  Stop adding preset to route */
#endif

    NETDEV_PTZ_BUTT
} NETDEV_PTZ_E;

/**
 * @enum tagNETDEVPtzPresetCmd
 * @brief 云台预置位操作命令 枚举定义 PTZ preset operation commands Enumeration Definition
 * @attention 无 None
 */
typedef enum tagNETDEVPtzPresetCmd
{
    NETDEV_PTZ_SET_PRESET   = 0,            /* 设置预置位  Set preset */
    NETDEV_PTZ_CLE_PRESET   = 1,            /* 清除预置位  Clear preset */
    NETDEV_PTZ_GOTO_PRESET  = 2             /* 转到预置位  Go to preset */
}NETDEV_PTZ_PRESETCMD_E;

/**
 * @enum tagNETDEVPTZCruiseCmd
 * @brief 云台巡航操作命令 枚举定义 PTZ patrol operation commands Enumeration Definition
 * @attention 无 None
 */
typedef enum tagNETDEVPTZCruiseCmd
{
    NETDEV_PTZ_ADD_CRUISE      = 0,         /* 添加巡航路径   Add patrol route */
    NETDEV_PTZ_MODIFY_CRUISE   = 1,         /* 编辑巡航路径  Edit patrol route */
    NETDEV_PTZ_DEL_CRUISE      = 2,         /* 删除巡航路径  Delete patrol route */
    NETDEV_PTZ_RUN_CRUISE      = 3,         /* 开始巡航  Start patrol */
    NETDEV_PTZ_STOP_CRUISE     = 4          /* 停止巡航  Stop patrol */
}NETDEV_PTZ_CRUISECMD_E;

/**
 * @enum tagNETDEVPlayControl
 * @brief 回放控制命令 枚举定义 Playback control commands Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPlayControl
{
    NETDEV_PLAY_CTRL_PLAY            = 0,           /* 开始播放  Play */
    NETDEV_PLAY_CTRL_PAUSE           = 1,           /* 暂停播放  Pause */
    NETDEV_PLAY_CTRL_RESUME          = 2,           /* 恢复播放  Resume */
    NETDEV_PLAY_CTRL_GETPLAYTIME     = 3,           /* 获取播放进度  Obtain playing time */
    NETDEV_PLAY_CTRL_SETPLAYTIME     = 4,           /* 设置播放进度  Configure playing time */
    NETDEV_PLAY_CTRL_GETPLAYSPEED    = 5,           /* 获取播放速度  Obtain playing speed */
    NETDEV_PLAY_CTRL_SETPLAYSPEED    = 6            /* 设置播放速度  Configure playing speed */
}NETDEV_VOD_PLAY_CTRL_E;

/**
 * @enum tagNETDEVVodPlayStatus
 * @brief 回放、下载状态 枚举定义 Playback and download status Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVodPlayStatus
{
/** 播放状态  Play status */
    NETDEV_PLAY_STATUS_16_BACKWARD        = 0,        /* 16倍速后退播放  Backward at 16x speed */
    NETDEV_PLAY_STATUS_8_BACKWARD         = 1,        /* 8倍速后退播放  Backward at 8x speed */
    NETDEV_PLAY_STATUS_4_BACKWARD         = 2,        /* 4倍速后退播放  Backward at 4x speed */
    NETDEV_PLAY_STATUS_2_BACKWARD         = 3,        /* 2倍速后退播放  Backward at 2x speed */
    NETDEV_PLAY_STATUS_1_BACKWARD         = 4,        /* 正常速度后退播放  Backward at normal speed */
    NETDEV_PLAY_STATUS_HALF_BACKWARD      = 5,        /* 1/2倍速后退播放  Backward at 1/2 speed */
    NETDEV_PLAY_STATUS_QUARTER_BACKWARD   = 6,        /* 1/4倍速后退播放  Backward at 1/4 speed */
    NETDEV_PLAY_STATUS_QUARTER_FORWARD    = 7,        /* 1/4倍速播放  Play at 1/4 speed */
    NETDEV_PLAY_STATUS_HALF_FORWARD       = 8,        /* 1/2倍速播放  Play at 1/2 speed */
    NETDEV_PLAY_STATUS_1_FORWARD          = 9,        /* 正常速度前进播放  Forward at normal speed */
    NETDEV_PLAY_STATUS_2_FORWARD          = 10,       /* 2倍速前进播放  Forward at 2x speed */
    NETDEV_PLAY_STATUS_4_FORWARD          = 11,       /* 4倍速前进播放  Forward at 4x speed */
    NETDEV_PLAY_STATUS_8_FORWARD          = 12,       /* 8倍速前进播放  Forward at 8x speed */
    NETDEV_PLAY_STATUS_16_FORWARD         = 13,       /* 16倍速前进播放  Forward at 16x speed */

    NETDEV_PLAY_STATUS_INVALID
}NETDEV_VOD_PLAY_STATUS_E;

/**
 * @enum tagNETDEVDownloadSpeed
 * @brief 录像下载速度  Recording download speed
 * @attention 无 None
 */
typedef enum tagNETDEVDownloadSpeed
{
    NETDEV_DOWNLOAD_SPEED_ONE = 0,          /* 一倍速  1x */
    NETDEV_DOWNLOAD_SPEED_TWO,              /* 二倍速  2x */
    NETDEV_DOWNLOAD_SPEED_FOUR,             /* 四倍速  4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT,            /* 八倍速  8x */
    NETDEV_DOWNLOAD_SPEED_TWO_IFRAME,       /* 二倍速I帧  I2x */
    NETDEV_DOWNLOAD_SPEED_FOUR_IFRAME,      /* 四倍速I帧  I4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT_IFRAME      /* 八倍速I帧  I8x */
}NETDEV_E_DOWNLOAD_SPEED_E;

/**
 * @enum tagNETDEVStoreType
 * @brief 录像存储类型 枚举定义 Recording storage type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVStoreType
{
    NETDEV_TYPE_STORE_TYPE_ALL                  = 0,            /* 所有的存储  All */

    NETDEV_EVENT_STORE_TYPE_MOTIONDETECTION     = 4,            /* 运动检测事件存储  Motion detection */
    NETDEV_EVENT_STORE_TYPE_DIGITALINPUT        = 5,            /* 数字输入事件存储  Digital input */
    NETDEV_EVENT_STORE_TYPE_VIDEOLOSS           = 7,            /* 视频丢失事件存储  Video loss */

    NETDEV_TYPE_STORE_TYPE_INVALID              = 0xFF          /* 无效值  Invalid value */
}NETDEV_PLAN_STORE_TYPE_E;

/**
 * @enum tagNETDEVException
 * @brief 异常回调的消息类型 枚举定义 Exception callback message types Enumeration definition 
 * @attention 无 None
 */
typedef enum tagNETDEVException
{
    /* 实况 业务异常上报  Live view exceptions report 200~299 */

    /* 回放业务异常上报  Playback exceptions report 300~399 */
    NETDEV_EXCEPTION_REPORT_VOD_END             = 300,          /* 回放结束  Playback ended*/
    NETDEV_EXCEPTION_REPORT_VOD_ABEND           = 301,          /* 回放异常  Playback exception occured */
    NETDEV_EXCEPTION_REPORT_BACKUP_END          = 302,          /* 备份结束  Backup ended */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_OUT     = 303,          /* 磁盘被拔出  Disk removed */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_FULL    = 304,          /* 磁盘已满  Disk full */
    NETDEV_EXCEPTION_REPORT_BACKUP_ABEND        = 305,          /* 其他原因导致备份失败   Backup failure caused by other reasons */

    NETDEV_EXCEPTION_EXCHANGE                   = 0x8000,       /* 用户交互时异常（用户保活超时）  Exception occurred during user interaction (keep-alive timeout) */

    NETDEV_EXCEPTION_REPORT_INVALID             = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_EXCEPTION_TYPE_E;

/**
 * @enum tagNETDEVAlarmTypeEn
 * @brief 告警配置操作 枚举定义  Alarm configuration operation Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmTypeEn
{
    /*********************************************************************** */
    /* 告警 Alarm                                                            */
    /*********************************************************************** */
    /* 有恢复类型的告警  Recoverable alarms */
    NETDEV_ALARM_MOVE_DETECT                        = 1,            /* 运动检测告警  Motion detection alarm */
    NETDEV_ALARM_VIDEO_LOST                         = 2,            /* 视频丢失告警  Video loss alarm */
    NETDEV_ALARM_VIDEO_TAMPER_DETECT                = 3,            /* 遮挡侦测告警  Tampering detection alarm */
    NETDEV_ALARM_INPUT_SWITCH                       = 4,            /* 输入开关量告警  boolean input alarm */
    NETDEV_ALARM_TEMPERATURE_HIGH                   = 5,            /* 高温告警  High temperature alarm */
    NETDEV_ALARM_TEMPERATURE_LOW                    = 6,            /* 低温告警  Low temperature alarm */
    NETDEV_ALARM_AUDIO_DETECT                       = 7,            /* 声音检测告警  Audio detection alarm */
    NETDEV_ALARM_DISK_ABNORMAL                      = 8,            /* 磁盘异常 */
    NETDEV_ALARM_DISK_OFFLINE                       = 9,            /* 磁盘下线 */

    /* NVR及接入设备状态上报  Status report of NVR and access device 100~199 */
    NETDEV_ALARM_REPORT_DEV_ONLINE                  = 100,          /* 设备上线  Device online */
    NETDEV_ALARM_REPORT_DEV_OFFLINE                 = 101,          /* 设备下线  Device offline */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS              = 102,          /* 视频丢失  Video loss */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS_RECOVER      = 103,          /* 视频丢失恢复  Video loss recover */
    NETDEV_ALARM_REPORT_DEV_REBOOT                  = 104,          /* 设备重启  Device restart */
    NETDEV_ALARM_REPORT_DEV_SERVICE_REBOOT          = 105,          /* 服务重启  Service restart */

    /* 实况业务异常上报  Live view exception report 200~299 */
    NETDEV_ALARM_NET_FAILED                         = 200,          /* 会话网络错误 Network error */
    NETDEV_ALARM_NET_TIMEOUT                        = 201,          /* 会话网络超时 Network timeout */
    NETDEV_ALARM_SHAKE_FAILED                       = 202,          /* 会话交互错误 Interaction error */
    NETDEV_ALARM_STREAMNUM_FULL                     = 203,          /* 流数已经满 Stream full */
    NETDEV_ALARM_STREAM_THIRDSTOP                   = 204,          /* 第三方停止流 Third party stream stopped */
    NETDEV_ALARM_FILE_END                           = 205,          /* 文件结束 File ended */


    /* 无布防24小时有效的告警  Valid alarms within 24 hours without arming schedule */
    NETDEV_ALARM_ALLTIME_FLAG_START                 = 400,          /* 无布防告警开始标记  Start marker of alarm without arming schedule */
    NETDEV_ALARM_STOR_ERR                           = 401,          /* 存储错误  Storage error */
    NETDEV_ALARM_STOR_DISOBEY_PLAN                  = 402,          /* 未按计划存储  Not stored as planned */

    /* 无恢复类型的告警  Unrecoverable alarms */
    NETDEV_ALARM_NO_RECOVER_FLAG_START              = 500,          /* 无恢复类型告警开始标记  Start marker of unrecoverable alarm */
    NETDEV_ALARM_DISK_ERROR                         = 501,          /* 磁盘错误  Disk error */
    NETDEV_ALARM_ILLEGAL_ACCESS                     = 502,          /* 非法访问  Illegal access */

    NETDEV_ALARM_ALLTIME_FLAG_END                   = 600,          /* 无布防告警结束标记  End marker of alarm without arming schedule */

    /* 告警恢复  Alarm recover */
    NETDEV_ALARM_RECOVER_BASE                       = 1000,         /* 告警恢复基数  Alarm recover base */
    NETDEV_ALARM_MOVE_DETECT_RECOVER                = 1001,         /* 运动检测告警恢复  Motion detection alarm recover */
    NETDEV_ALARM_VIDEO_LOST_RECOVER                 = 1002,         /* 视频丢失告警恢复  Video loss alarm recover */
    NETDEV_ALARM_VIDEO_TAMPER_RECOVER               = 1003,         /* 遮挡侦测告警恢复  Tampering detection alarm recover */
    NETDEV_ALARM_INPUT_SWITCH_RECOVER               = 1004,         /* 输入开关量告警恢复  Boolean input alarm recover */
    NETDEV_ALARM_TEMPERATURE_RECOVER                = 1005,         /* 温度告警恢复  Temperature alarm recover */
    NETDEV_ALARM_AUDIO_DETECT_RECOVER               = 1006,         /* 声音检测告警恢复  Audio detection alarm recover */
    NETDEV_ALARM_DISK_ABNORMAL_RECOVER              = 1008,         /* 磁盘异常恢复 */
    NETDEV_ALARM_DISK_OFFLINE_RECOVER               = 1009,         /* 磁盘上线恢复 */

    NETDEV_ALARM_STOR_ERR_RECOVER                   = 1201,         /* 存储错误恢复  Storage error recover */
    NETDEV_ALARM_STOR_DISOBEY_PLAN_RECOVER          = 1202,         /* 未按计划存储恢复  Not stored as planned recover */

    NETDEV_ALARM_BUTT                               = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_ALARM_TYPE_E;

/**
 * @enum tagNETDEVLogMainType
 * @brief 日志主类型枚举 枚举定义 Major types of logs Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLogMainType
{
    NETDEV_LOG_MAIN_TYPE_ALL                    = 0,               /* 全部类型的日志  Logs of all types */
    NETDEV_LOG_MAIN_TYPE_ALARM                  = 1,               /* 告警类  Alarms */
    NETDEV_LOG_MAIN_TYPE_EXCEPTION              = 2,               /* 异常类  Exceptions */
    NETDEV_LOG_MAIN_TYPE_OPERATION              = 3,               /* 操作类  Operations */
    NETDEV_LOG_MAIN_TYPE_MESSAGE                = 4,               /* 信息类  Messages */

    NETDEV_LOG_MAIN_TYPE_BUTT                   = 0xFFFF            /* 无效值  Invalid value */
}NETDEV_LOG_MAIN_TYPE_E;

/**
 * @enum tagNETDEVLogSubType
 * @brief 日志次类型ID 枚举定义 Minor type IDs of logs Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLogSubType
{
    NETDEV_LOG_ALL_SUB_TYPES                     = 0x0101,          /* 所有信息类日志  All information logs */

    /* 信息类日志  Information logs */
    NETDEV_LOG_MSG_HDD_INFO                     = 300,              /* 硬盘信息  HDD information */
    NETDEV_LOG_MSG_SMART_INFO                   = 301,              /* S.M.A.R.T信息  S.M.A.R.T information */
    NETDEV_LOG_MSG_REC_OVERDUE                  = 302,              /* 过期录像删除  Expired recording deletion */
    NETDEV_LOG_MSG_PIC_REC_OVERDUE              = 303,              /* 过期图片文件删除  Expired image deletion */

    /* 告警类日志的子类型日志ID  Sub type log ID of alarm logs */
    NETDEV_LOG_ALARM_MOTION_DETECT              = 350,              /* 移动侦测告警  Motion detection alarm */
    NETDEV_LOG_ALARM_MOTION_DETECT_RESUME       = 351,              /* 移动侦测告警恢复  Motion detection alarm recover */
    NETDEV_LOG_ALARM_VIDEO_LOST                 = 352,              /* 视频丢失告警  Video loss alarm */
    NETDEV_LOG_ALARM_VIDEO_LOST_RESUME          = 353,              /* 视频丢失告警恢复  Video loss alarm recover */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_DETECT        = 354,              /* 遮挡侦测告警  Tampering detection alarm */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_RESUME        = 355,              /* 遮挡侦测告警恢复  Tampering detection alarm recover */
    NETDEV_LOG_ALARM_INPUT_SW                   = 356,              /* 输入开关量告警  Boolean input alarm */
    NETDEV_LOG_ALARM_INPUT_SW_RESUME            = 357,              /* 输入开关量告警恢复  Boolean input alarm recover */
    NETDEV_LOG_ALARM_IPC_ONLINE                 = 358,              /* IPC 设备上线  Device online */
    NETDEV_LOG_ALARM_IPC_OFFLINE                = 359,              /* IPC 设备下线  Device offline */

    /* 异常类日志的子类型日志ID  Sub type log ID of exception logs */
    NETDEV_LOG_EXCEP_DISK_ONLINE                = 400,              /* 磁盘上线  Disk online */
    NETDEV_LOG_EXCEP_DISK_OFFLINE               = 401,              /* 磁盘下线  Disk offline */
    NETDEV_LOG_EXCEP_DISK_ERR                   = 402,              /* 磁盘异常  Disk exception */
    NETDEV_LOG_EXCEP_STOR_ERR                   = 403,              /* 存储错误  Storage error */
    NETDEV_LOG_EXCEP_STOR_ERR_RECOVER           = 404,              /* 存储错误恢复  Storage error recover */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN          = 405,              /* 未按计划存储  Not stored as planned */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN_RECOVER  = 406,              /* 未按计划存储恢复  Not stored as planned recover */
    NETDEV_LOG_EXCEP_ILLEGAL_ACCESS             = 407,              /* 非法访问  Illegal access */
    NETDEV_LOG_EXCEP_IP_CONFLICT                = 408,              /* IP地址冲突  IP address conflict */
    NETDEV_LOG_EXCEP_NET_BROKEN                 = 409,              /* 网络断开  Network disconnection */
    NETDEV_LOG_EXCEP_PIC_REC_ERR                = 410,              /* 抓图出错,获取图片文件失败  Failed to get captured image */
    NETDEV_LOG_EXCEP_VIDEO_EXCEPTION            = 411,              /* 视频输入异常(只针对模拟通道)  Video input exception (for analog channel only) */
    NETDEV_LOG_EXCEP_VIDEO_MISMATCH             = 412,              /* 视频制式不匹配   Video standards do not match */
    NETDEV_LOG_EXCEP_RESO_MISMATCH              = 413,              /* 编码分辨率和前端分辨率不匹配  Encoding resolution and front-end resolution do not match */
    NETDEV_LOG_EXCEP_TEMP_EXCE                  = 414,              /* 温度异常  Temperature exception */

    /* 操作类日志的子类型日志ID  Sub type log ID of operation logs */
    /* 业务类  Services */
    NETDEV_LOG_OPSET_LOGIN                      = 450,              /* 用户登录  User login */
    NETDEV_LOG_OPSET_LOGOUT                     = 451,              /* 注销登录  Log out */
    NETDEV_LOG_OPSET_USER_ADD                   = 452,              /* 用户添加  Add user */
    NETDEV_LOG_OPSET_USER_DEL                   = 453,              /* 用户删除  Delete user */
    NETDEV_LOG_OPSET_USER_MODIFY                = 454,              /* 用户修改  Modify user */
    NETDEV_LOG_OPSET_START_REC                  = 455,              /* 开始录像  Start recording */
    NETDEV_LOG_OPSET_STOP_REC                   = 456,              /* 停止录像  Stop recording */
    NETDEV_LOG_OPSETR_PLAY_DOWNLOAD             = 457,              /* 回放/下载  Playback and download */
    NETDEV_LOG_OPSET_DOWNLOAD                   = 458,              /* 下载  Download */
    NETDEV_LOG_OPSET_PTZCTRL                    = 459,              /* 云台控制  PTZ control */
    NETDEV_LOG_OPSET_PREVIEW                    = 460,              /* 实况预览  Live preview */
    NETDEV_LOG_OPSET_REC_TRACK_START            = 461,              /* 轨迹录制开始  Start recording route */
    NETDEV_LOG_OPSET_REC_TRACK_STOP             = 462,              /* 轨迹录制停止  Stop recording route */
    NETDEV_LOG_OPSET_START_TALKBACK             = 463,              /* 开始语音对讲  Start two-way audio */
    NETDEV_LOG_OPSET_STOP_TALKBACK              = 464,              /* 停止语音对讲  Stop two-way audio */
    NETDEV_LOG_OPSET_IPC_ADD                    = 465,              /* 添加IPC  Add IP camera */
    NETDEV_LOG_OPSET_IPC_DEL                    = 466,              /* 删除IPC  Delete IP camera */
    NETDEV_LOG_OPSET_IPC_SET                    = 467,              /* 设置IPC  Modify IP camera */

    /* 配置类  Configurations */
    NETDEV_LOG_OPSET_DEV_BAS_CFG                = 500,              /* 设备基本信息配置  Basic device information */
    NETDEV_LOG_OPSET_TIME_CFG                   = 501,              /* 设备时间配置  Device time */
    NETDEV_LOG_OPSET_SERIAL_CFG                 = 502,              /* 设备串口配置  Device serial port */
    NETDEV_LOG_OPSET_CHL_BAS_CFG                = 503,              /* 通道基本配置  Basic channel configuration */
    NETDEV_LOG_OPSET_CHL_NAME_CFG               = 504,              /* 通道名称配置  Channel name configuration */
    NETDEV_LOG_OPSET_CHL_ENC_VIDEO              = 505,              /* 视频编码参数配置  Video encoding configuration */
    NETDEV_LOG_OPSET_CHL_DIS_VIDEO              = 506,              /* 通道视频显示参数配置  Video display configuration */
    NETDEV_LOG_OPSET_PTZ_CFG                    = 507,              /* 云台配置  PTZ configuration */
    NETDEV_LOG_OPSET_CRUISE_CFG                 = 508,              /* 巡航线路设置  Patrol route configuration */
    NETDEV_LOG_OPSET_PRESET_CFG                 = 509,              /* 预置位设置  Preset configuration */
    NETDEV_LOG_OPSET_VIDPLAN_CFG                = 510,              /* 录像计划配置  Recording schedule configuration */
    NETDEV_LOG_OPSET_MOTION_CFG                 = 511,              /* 运动检测配置  Motion detection configuration */
    NETDEV_LOG_OPSET_VIDLOSS_CFG                = 512,              /* 视频丢失配置  Video loss configuration */
    NETDEV_LOG_OPSET_COVER_CFG                  = 513,              /* 视频遮挡配置  Tampering detection configuration */
    NETDEV_LOG_OPSET_MASK_CFG                   = 514,              /* 视频遮盖配置  Privacy mask configuration */
    NETDEV_LOG_OPSET_SCREEN_OSD_CFG             = 515,              /* OSD叠加配置  OSD overlay configuration */
    NETDEV_LOG_OPSET_ALARMIN_CFG                = 516,              /* 报警输入配置  Alarm input configuration */
    NETDEV_LOG_OPSET_ALARMOUT_CFG               = 517,              /* 报警输出配置  Alarm output configuration */
    NETDEV_LOG_OPSET_ALARMOUT_OPEN_MAN          = 518,              /* 手动开启报警输出,人机  Manually enable alarm output, GUI */
    NETDEV_LOG_OPSET_ALARMOUT_CLOSE_MAN         = 519,              /* 手动关闭报警输出,人机  Manually disable alarm input, GUI */
    NETDEV_LOG_OPSET_ABNORMAL_CFG               = 520,              /* 异常配置  Exception configuration */
    NETDEV_LOG_OPSET_HDD_CFG                    = 521,              /* 硬盘配置  HDD configuration */
    NETDEV_LOG_OPSET_NET_IP_CFG                 = 522 ,             /* TCP/IP配置  TCP/IP configuration */
    NETDEV_LOG_OPSET_NET_PPPOE_CFG              = 523,              /* PPPOE配置  PPPOE configuration */
    NETDEV_LOG_OPSET_NET_PORT_CFG               = 524,              /* 端口配置  Port configuration */
    NETDEV_LOG_OPSET_NET_DDNS_CFG               = 525,              /* DDNS配置  DDNS configuration */

    /* 维护类 Maintenance */
    NETDEV_LOG_OPSET_START_DVR                  = 600,              /* 开机  Start up*/
    NETDEV_LOG_OPSET_STOP_DVR                   = 601,              /* 关机  Shut down */
    NETDEV_LOG_OPSET_REBOOT_DVR                 = 602,              /* 重启设备  Restart device */
    NETDEV_LOG_OPSET_UPGRADE                    = 603,              /* 版本升级  Version upgrade */
    NETDEV_LOG_OPSET_LOGFILE_EXPORT             = 604,              /* 导出日志文件  Export log files */
    NETDEV_LOG_OPSET_CFGFILE_EXPORT             = 605,              /* 导出配置文件  Export configuration files */
    NETDEV_LOG_OPSET_CFGFILE_IMPORT             = 606,              /* 导入配置文件  Import configuration files */
    NETDEV_LOG_OPSET_CONF_SIMPLE_INIT           = 607,              /* 简单恢复配置  Export configuration files */
    NETDEV_LOG_OPSET_CONF_ALL_INIT              = 608               /* 恢复出厂配置  Restore to factory settings */

}NETDEV_LOG_SUBTYPE_ID_E;

typedef enum tagNETDEVDeviceType
{
    NETDEV_DTYPE_UNKNOWN                        = 0,            /* Unknown type */
    NETDEV_DTYPE_IPC                            = 1,            /* IPC range */
    NETDEV_DTYPE_IPC_FISHEYE                    = 2,            /* 鱼眼IPC  fish eye IPC */
    NETDEV_DTYPE_NVR                            = 101,          /* NVR range */
    NETDEV_DTYPE_NVR_BACKUP                     = 102,          /* NVR备份服务器  NVR back up */
    NETDEV_DTYPE_DC                             = 201,          /* DC range */
    NETDEV_DTYPE_EC                             = 301,          /* EC range */
    NETDEV_DTYPE_BUTT                           = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_DEVICETYPE_E;

/**
 * @enum tagNETDEVCFGCmd
 * @brief 参数配置命令字 枚举定义 Parameter configuration command words Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVCFGCmd
{
    NETDEV_GET_DEVICECFG                = 100,              /* 获取设备信息,参见#NETDEV_DEVICE_BASICINFO_S  Get device information, see #NETDEV_DEVICE_BASICINFO_S */
    NETDEV_SET_DEVICECFG                = 101,              /* 保留 Reserved */

    NETDEV_GET_NTPCFG                   = 110,              /* 获取NTP参数,参见#NETDEV_SYSTEM_NTP_INFO_S  Get NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */
    NETDEV_SET_NTPCFG                   = 111,              /* 设置NTP参数,参见#NETDEV_SYSTEM_NTP_INFO_S  Set NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */

    NETDEV_GET_STREAMCFG                = 120,              /* 获取视频编码参数,参见#NETDEV_VIDEO_STREAM_INFO_S  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */
    NETDEV_SET_STREAMCFG                = 121,              /* 设置视频编码参数,参见#NETDEV_VIDEO_STREAM_INFO_S  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */

    NETDEV_GET_PTZPRESETS               = 130,              /* 获取云台预置位,参见#NETDEV_PTZ_ALLPRESETS_S  Get PTZ preset, see #NETDEV_PTZ_ALLPRESETS_S */

    NETDEV_GET_OSDCFG                   = 140,              /* 获取OSD配置信息,参见#NETDEV_VIDEO_OSD_CFG_S  Get OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */
    NETDEV_SET_OSDCFG                   = 141,              /* 设置OSD配置信息,参见#NETDEV_VIDEO_OSD_CFG_S  Set OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */

    NETDEV_GET_ALARM_OUTPUTCFG          = 150,              /* 获取开关量配置信息,参见#NETDEV_ALARM_OUTPUT_LIST_S  Get boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_SET_ALARM_OUTPUTCFG          = 151,              /* 设置开关量配置信息,参见#NETDEV_ALARM_OUTPUT_LIST_S  Set boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_TRIGGER_ALARM_OUTPUT         = 152,              /* 触发开关量,参见#NETDEV_TRIGGER_ALARM_OUTPUT_S        Trigger boolean, see #NETDEV_TRIGGER_ALARM_OUTPUT_S */
    NETDEV_GET_ALARM_INPUTCFG           = 153,              /* 获取开关量输入数量,参见#NETDEV_ALARM_INPUT_LIST_S   Get the number of boolean inputs, see #NETDEV_ALARM_INPUT_LIST_S */

    NETDEV_GET_IMAGECFG                 = 160,              /* 获取图像配置信息,参见#NETDEV_IMAGE_SETTING_S  Get image configuration information, see #NETDEV_IMAGE_SETTING_S */
    NETDEV_SET_IMAGECFG                 = 161,              /* 设置图像配置信息,参见#NETDEV_IMAGE_SETTING_S  Set image configuration information, see #NETDEV_IMAGE_SETTING_S */

    NETDEV_GET_NETWORKCFG               = 170,              /* 获取网络配置信息,参见#NETDEV_NETWORKCFG_S  Get network configuration information, see #NETDEV_NETWORKCFG_S */
    NETDEV_SET_NETWORKCFG               = 171,              /* 设置网络配置信息,参见#NETDEV_NETWORKCFG_S  Set network configuration information, see #NETDEV_NETWORKCFG_S */

    NETDEV_GET_PRIVACYMASKCFG           = 180,              /* 获取隐私遮盖配置信息,参见#NETDEV_PRIVACY_MASK_CFG_S  Get privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_SET_PRIVACYMASKCFG           = 181,              /* 设置隐私遮盖配置信息,参见#NETDEV_PRIVACY_MASK_CFG_S  Set privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_DELETE_PRIVACYMASKCFG        = 182,              /* 删除隐私遮盖配置信息  Delete privacy mask configuration information */

    NETDEV_GET_TAMPERALARM              = 190,              /* 获取遮挡检测告警信息  参见#NETDEV_TAMPER_ALARM_INFO_S  Get tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */
    NETDEV_SET_TAMPERALARM              = 191,              /* 设置遮挡检测告警信息  参见#NETDEV_TAMPER_ALARM_INFO_S  Set tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */

    NETDEV_GET_MOTIONALARM              = 201,              /* 获取运动检测告警信息 参见#NETDEV_MOTION_ALARM_INFO_S  Get motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */
    NETDEV_SET_MOTIONALARM              = 202,              /* 设置运动检测告警信息 参见#NETDEV_MOTION_ALARM_INFO_S  Set motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */

    NETDEV_CFG_BUTT                     = 0xFFFF            /* 无效值  Invalid value */

}NETDEV_CONFIG_COMMAND_E;

/**
 * @enum tagNETDEVDateOSDFormateCap
 * @brief 日期格式能力集 枚举定义 OSD date format capabilities enumeration 
 * @attention 无 None
 */
typedef enum tagNETDEVDateOSDFormateCap
{
    NETDEV_OSD_DATE_FORMAT_CAP_MD_YYYY          = 0,        /* M/d/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMDD_YYYY        = 1,        /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMM_YYYY        = 2,        /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYY_MMDD        = 3,        /* yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYYMMDDB        = 4,        /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_CAP_XX_MMDD_YYYY     = 5,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMMMDD_YYYY      = 6,        /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMMMM_YYYY      = 7         /* dd MMMM, yyyy */
}NETDEV_OSD_DATE_FORMAT_CAP_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief OSD时间格式能力集枚举 OSD time format capabilities enumeration
 * @attention 无 None
 */
typedef enum tagNETDEVTimeOSDFormateCap
{
    NETDEV_OSD_TIME_FORMAT_CAP_HHMMSS = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_CAP_HH_MM_SS_PM                  /* hh:mm:ss tt */
}NETDEV_OSD_TIME_FORMAT_CAP_E;

/**
 * @enum tagNETDEVBooleanMode
 * @brief 输入开关量运行模式 Boolean input operation mode
 * @attention 无 None
 */
typedef enum tagNETDEVBooleanMode
{
    NETDEV_BOOLEAN_MODE_OPEN   = 1,                         /* 常开  Always open */
    NETDEV_BOOLEAN_MODE_CLOSE  = 2,                         /* 常闭  Always closed */
    NETDEV_BOOLEAN_MODE_BUTT
}NETDEV_BOOLEAN_MODE_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief 开关量状态 Boolean input operation mode
 * @attention 无 None
 */
typedef enum tagNETDEVRelayOutPutState
{
    NETDEV_BOOLEAN_STATUS_ACTIVE    = 0,                /* 触发状态  Triggered */
    NETDEV_BOOLEAN_STATUS_INACTIVE  = 1                 /* 非触发状态 Not triggered */
}NETDEV_RELAYOUTPUT_STATE_E;

/**
* @enum tagNETDEVMediaDataFormat
* @brief 媒体数据流格式
* @attention 无
*/
typedef enum tagNETDEVMediaDataFormat
{
    NETDEV_MEDIA_DATA_TS            = 0,            /* TS */
    NETDEV_MEDIA_DATA_RTP_ES        = 3             /* RTP + ES */
}NETDEV_MEDIA_DATA_FORMAT_E;

/**
* @enum tagNETDEVProtocolType
* @brief 协议类型
* @attention 无
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP  = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP  = 2
}NETDEV_PROTOCOL_TYPE_E;

/**
* @enum tagNETDEVTTimeZone
* @brief 时区  Time Zone
* @attention 无 None
*/
typedef enum tagNETDEVTimeZone
{
    NETDEV_TIME_ZONE_W1200 = 0,              /* W12 */
    NETDEV_TIME_ZONE_W1100 = 1,              /* W11 */
    NETDEV_TIME_ZONE_W1000 = 2,              /* W10 */
    NETDEV_TIME_ZONE_W0900 = 3,              /* W9 */
    NETDEV_TIME_ZONE_W0800 = 4,              /* W8 */
    NETDEV_TIME_ZONE_W0700 = 5,              /* W7 */
    NETDEV_TIME_ZONE_W0600 = 6,              /* W6 */
    NETDEV_TIME_ZONE_W0500 = 7,              /* W5 */
    NETDEV_TIME_ZONE_W0430 = 8,              /* W4:30 */
    NETDEV_TIME_ZONE_W0400 = 9,              /* W4 */
    NETDEV_TIME_ZONE_W0330 = 10,             /* W3:30 */
    NETDEV_TIME_ZONE_W0300 = 11,             /* W3 */
    NETDEV_TIME_ZONE_W0200 = 12,             /* W2 */
    NETDEV_TIME_ZONE_W0100 = 13,             /* W1 */
    NETDEV_TIME_ZONE_0000  = 14,             /* W0 */
    NETDEV_TIME_ZONE_E0100 = 15,             /* E1 */
    NETDEV_TIME_ZONE_E0200 = 16,             /* E2 */
    NETDEV_TIME_ZONE_E0300 = 17,             /* E3 */
    NETDEV_TIME_ZONE_E0330 = 18,             /* E3:30 */
    NETDEV_TIME_ZONE_E0400 = 19,             /* E4 */
    NETDEV_TIME_ZONE_E0430 = 20,             /* E4:30 */
    NETDEV_TIME_ZONE_E0500 = 21,             /* E5 */
    NETDEV_TIME_ZONE_E0530 = 22,             /* E5:30 */
    NETDEV_TIME_ZONE_E0545 = 23,             /* E5:45 */
    NETDEV_TIME_ZONE_E0600 = 24,             /* E6 */
    NETDEV_TIME_ZONE_E0630 = 25,             /* E6:30 */
    NETDEV_TIME_ZONE_E0700 = 26,             /* E7 */
    NETDEV_TIME_ZONE_E0800 = 27,             /* E8 */
    NETDEV_TIME_ZONE_E0900 = 28,             /* E9 */
    NETDEV_TIME_ZONE_E0930 = 29,             /* E9:30 */
    NETDEV_TIME_ZONE_E1000 = 30,             /* E10 */
    NETDEV_TIME_ZONE_E1100 = 31,             /* E11 */
    NETDEV_TIME_ZONE_E1200 = 32,             /* E12 */
    NETDEV_TIME_ZONE_E1300 = 33,             /* E13 */

    NETDEV_TIME_ZONE_INVALID = 0xFF          /* Invalid value */
}NETDEV_TIME_ZONE_E;

/* END************* 枚举值  Enumeration value *************************** */

/* BEGIN*********** 结构体  Structure *********************************** */

/**
 * @struct tagNETDEVDeviceInfo
 * @brief 设备信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /* 设备类型,参见枚举#NETDEV_DEVICETYPE_E  Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT16   wAlarmInPortNum;                    /* 报警输入个数  Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /* 报警输出个数  Number of alarm outputs */
    INT32   dwChannelNum;                       /* 通道个数  Number of Channels */
    BYTE    byRes[48];                          /* 保留字段  Reserved */
}NETDEV_DEVICE_INFO_S,*LPNETDEV_DEVICE_INFO_S;

/**
 * @struct tagNETDEVDeviceBasicInfo
 * @brief 设备基本信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDeviceBasicInfo
{ 
    CHAR szDevModel[NETDEV_LEN_64];                     /* 设备型号  Device model */
    CHAR szSerialNum[NETDEV_LEN_64];                    /* 硬件序列号  Hardware serial number */
    CHAR szFirmwareVersion[NETDEV_LEN_64];              /* 软件版本号  Software version */
    CHAR szMacAddress[NETDEV_LEN_64];                   /* IPv4的Mac地址  MAC address of IPv4 */
    CHAR szDeviceName[NETDEV_LEN_64];                   /* 设备名称  Device name */
    BYTE byRes[448];                                    /* 保留字  Reserved */
}NETDEV_DEVICE_BASICINFO_S, *LPNETDEV_DEVICE_BASICINFO_S;

/**
 * @struct tagNETDEVNetworkInterfaces
 * @brief 网络配置信息 结构体定义 Network configuration information
 * @attention 无 None
 */
typedef struct tagNETDEVNetworkInterfaces
{
    INT32   dwMTU;                              /* MTU值  MTU value */
    INT32   dwIPv4DHCP;                         /* IPv4的DHCP  DHCP of IPv4 */
    CHAR    szIpv4Address[NETDEV_LEN_32];       /* IPv4的IP地址  IP address of IPv4 */
    CHAR    szIPv4GateWay[NETDEV_LEN_32];       /* IPv4的网关地址  Gateway of IPv4 */
    CHAR    szIPv4SubnetMask[NETDEV_LEN_32];    /* IPv4的子网掩码  Subnet mask of IPv4 */
    BYTE    byRes[480];                         /* 保留字  Reserved */
}NETDEV_NETWORKCFG_S, *LPNETDEV_NETWORKCFG_S;

/**
 * @struct tagSysemIPAddr
 * @brief 地址 结构体定义 Address Structure definition 
 * @attention 无 None
 */
typedef struct tagSysemIPAddr
{
    INT32   eIPType;                            /* 协议类型参见枚举#NETDEV_HOSTTYPE_E  Protocol type, see enumeration #NETDEV_HOSTTYPE_E */
    CHAR    szIPAddr[NETDEV_LEN_132];           /* IP地址  IP address */
}NETDEV_SYSTEM_IPADDR_S, *LPNETDEV_SYSTEM_IPADDR_S;

/**
 * @struct tagNETDEVSystemNTPInfo
 * @brief  NTP参数 NTP parameter
 * @attention 无 None
 */
typedef struct tagNETDEVSystemNTPInfo
{
    BOOL bSupportDHCP;                      /* 是否支持DHCP  Support DHCP or not */
    NETDEV_SYSTEM_IPADDR_S stAddr;          /* NTP 信息  NTP information */
}NETDEV_SYSTEM_NTP_INFO_S, *LPNETDEV_SYSTEM_NTP_INFO_S;

/**
 * @struct tagNETDEVPriviewInfo
 * @brief 实况预览参数 结构体定义 Live view parameter Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                    /* 通道ID  Channel ID */
    INT32   dwStreamType;                   /* 码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                     /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* 播放窗口句柄 Play window handle */ 
    BYTE    byRes[264];                     /* 保留字段  Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
 * @struct tagNETDEVVideoEffect
 * @brief 实况影像信息 结构体定义 Live image information Structure definition
 * @attention 伽马参数范围0-10,其它参数取值范围0-255 Gamma parameter range: 0-10, other parameters: 0-255
 */
typedef struct tagNETDEVVideoEffect
{
    INT32 dwContrast;                   /* 对比度  Contrast */
    INT32 dwBrightness;                 /* 亮度  Brightness */
    INT32 dwSaturation;                 /* 饱和度  Saturation */
    INT32 dwHue;                        /* 色调  Hue */
    INT32 dwGamma;                      /* 伽玛值  Gamma */
    BYTE  byRes[16];                    /* 保留字段  Reserved */
}NETDEV_VIDEO_EFFECT_S, *LPNETDEV_VIDEO_EFFECT_S;

/**
 * @struct tagNETDEVImagingSetting
 * @brief 设备图像设置 结构体定义    Device image settings Structure definition
 * @attention 参数取值范围：0-255     parameter range: 0-255
 */
typedef struct tagNETDEVImagingSetting
{
    INT32 dwContrast;                   /* 对比度  Contrast */
    INT32 dwBrightness;                 /* 亮度  Brightness */
    INT32 dwSaturation;                 /* 饱和度  Saturation */
    INT32 dwSharpness;                  /* 亮度  Sharpness */
    BYTE  byRes[252];                   /* 保留字段  Reserved */
}NETDEV_IMAGE_SETTING_S, *LPNETDEV_IMAGE_SETTING_S;

/************ 回放业务 Playback services***********************************************/

/**
 * @struct tagNETDEVVodFile
 * @brief 录像文件 结构体定义 Recording file Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVodFile
{
    CHAR                        szFileName[NETDEV_LEN_64];      /* 录像文件名  Recording file name */
    NETDEV_PLAN_STORE_TYPE_E    enType;                         /* 录像存储类型  Recording storage type */
    INT64                       tBeginTime;                     /* 起始时间  Start time */
    INT64                       tEndTime;                       /* 结束时间  End time */
}NETDEV_VOD_FILE_S, *LPNETDEV_VOD_FILE_S;

/**
 * @struct tagNETDEVFindCond
 * @brief 录像查找 结构体定义 Recording query Structure definition
 *        根据文件类型、时间查找设备录像文件 Query recording files according to file type and time
 * @attention 无 None
 */
typedef struct tagNETDEVFindCond
{
    CHAR    szFileName[NETDEV_LEN_64];      /* 录像文件名  Recording file name */
    INT32   dwChannelID;                    /* 通道号  Channel number */
    INT32   dwFileType;                     /* 录像存储类型,参见枚举#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT64   tBeginTime;                     /* 起始时间  Start time */
    INT64   tEndTime;                       /* 结束时间  End time */
    BYTE    byRes[40];                      /* 保留字段  Reserved */
}NETDEV_FILECOND_S, *LPNETDEV_FILECOND_S;

/**
 * @struct tagNETDEVFingData
 * @brief 录像查找数据 结构体定义 Recording query data Structure definition
 *        逐个获取查找到的文件信息 Get the information of found files one by one
 * @attention 无 None
 */
typedef struct tagNETDEVFingData
{
    CHAR    szFileName[NETDEV_FILE_NAME_LEN];               /* 录像文件名  Recording file name */
    INT64   tBeginTime;                                     /* 起始时间  Start time */
    INT64   tEndTime;                                       /* 结束时间  End time */
    BYTE    byFileType;                                     /* 录像存储类型  Recording storage type */
    BYTE    byRes[171];                                     /* 保留字段  Reserved */
}NETDEV_FINDDATA_S,*LPNETDEV_FINDDATA_S;

/**
 * @struct tagNETDEVPlayBackInfo
 * @brief 按文件名回放录像参数 结构体定义 Parameters of play back recordings by file name Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlayBackInfo
{
    char    szName[NETDEV_LEN_260];         /* 回放的控制块名称  Playback control block name*/
    INT64   tBeginTime;                     /* 回放开始时间  Playback start time */
    INT64   tEndTime;                       /* 回放结束时间  Playback end time */
    INT32   dwLinkMode;                     /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* 播放窗口句柄  Play window handle */
    INT32   dwFileType;                     /* 录像存储类型,参见枚举#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;                /* 下载速度 参见枚举#NETDEV_E_DOWNLOAD_SPEED_E  Download speed, see enumeration #NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                     /* 保留字段  Reserved */
}NETDEV_PLAYBACKINFO_S, *LPNETDEV_PLAYBACKINFO_S;

/**
 * @struct tagNETDEVPlayBackCondition
 * @brief 按时间回放录像参数 结构体定义 Parameters of play back by time Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlayBackCondition
{
    INT32   dwChannelID;                /* 回放的通道  Playback channel */
    INT64   tBeginTime;                 /* 回放开始时间  Playback start time */
    INT64   tEndTime;                   /* 回放结束时间  Playback end time */
    INT32   dwLinkMode;                 /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                   /* 播放窗口句柄  Play window handle */
    INT32   dwFileType;                 /* 录像存储类型,参见枚举#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;            /* 下载速度 参见枚举#NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                 /* 保留字段  Reserved */
}NETDEV_PLAYBACKCOND_S, *LPNETDEV_PLAYBACKCOND_S;

/************************************************* 云台业务*****************************************************/
/************************************************* PTZ services*****************************************************/
/**
 * @struct tagstNETDEVPtzPreset
 * @brief 云台预置位信息 结构体定义 PTZ preset information Structure definition
 * @attention 无 None
 */
typedef struct tagstNETDEVPtzPreset
{
    INT32   dwPresetID;                                 /* 预置位ID  Preset ID */
    CHAR    szPresetName[NETDEV_LEN_32];                /* 预置位名称  Preset name */
}NETDEV_PTZ_PRESET_S, *LPNETDEV_PTZ_PRESET_S;

/**
 * @struct tagstNETDEVPtzAllPresets
 * @brief 所有云台预置位 结构体定义 All PTZ presets Structure definition
 * @attention 无 None
 */
typedef struct tagstNETDEVPtzAllPresets
{
    INT32               dwSize;                             /* 预置位总数  Total number of presets */
    NETDEV_PTZ_PRESET_S astPreset[NETDEV_MAX_PRESET_NUM];   /* 预置位信息结构体  Structure of preset information */
}NETDEV_PTZ_ALLPRESETS_S, *LPNETDEV_PTZ_ALLPRESETS_S;

/**
 * @struct tagNETDEVCruisePointInfo
 * @brief 云台预置位巡航轨迹点信息 结构体定义 PTZ preset patrol point information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCruisePoint
{
    INT32   dwPresetID;                     /* 预置位ID  Preset ID */
    INT32   dwStayTime;                     /* 停留时间  Stay time */
    INT32   dwSpeed;                        /* 转动速度  Speed */
    INT32   dwReserve;                      /* 保留字段  Reserved */
}NETDEV_CRUISE_POINT_S, *LPNETDEV_CRUISE_POINT_S;

/**
 * @struct tagNETDEVCruiseInfo
 * @brief 云台预置位巡航路径详细信息 结构体定义 PTZ preset patrol route information Structure definition 
 * @attention 无 None
 */
typedef struct tagNETDEVCruiseInfo
{
    INT32                   dwCuriseID;                                     /* 轨迹ID  Route ID */
    CHAR                    szCuriseName[NETDEV_LEN_32];                    /* 轨迹名称  Route name */
    INT32                   dwSize;                                         /* 路径包含的轨迹点数量  Number of presets included in the route */
    NETDEV_CRUISE_POINT_S   astCruisePoint[NETDEV_MAX_CRUISEPOINT_NUM];     /* 路径包含的轨迹点信息   Information of presets included in the route */
}NETDEV_CRUISE_INFO_S, *LPNETDEV_CRUISE_INFO_S;

/**
 * @struct tagNETDEVCruiseList
 * @brief 云台预置位巡航路径列表 结构体定义 PTZ preset patrol route list Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCruiseList
{
    INT32                   dwSize;                                         /* 巡航路径数量  Number of patrol routes */
    NETDEV_CRUISE_INFO_S    astCruiseInfo[NETDEV_MAX_CRUISEROUTE_NUM];      /* 巡航路径信息  Information of patrol routes */
}NETDEV_CRUISE_LIST_S, *LPNETDEV_CRUISE_LIST_S;

/**
 * @struct tagNETDEVPtzTrackinfo
 * @brief 云台轨迹巡航路径信息 结构体定义 Route information of PTZ route patrol Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPtzTrackinfo
{
    INT32 dwTrackNum;                                               /* 已存在的巡航轨迹的数量  Number of existing patrol routes */
    CHAR  aszTrackName[NETDEV_TRACK_CRUISE_MAXNUM][NETDEV_LEN_64];  /* 轨迹名称  Route name */
}NETDEV_PTZ_TRACK_INFO_S, *LPNETDEV_PTZ_TRACK_INFO_S;

/**
 * @struct tagNETDEVRect
 * @brief 矩形区域 结构体定义 Rectangle Area  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVRect
{
    INT32   dwLeft;                               /* x轴左点值[0,10000]  X axis left point value [0,10000] */
    INT32   dwTop;                                /* y轴顶点值[0,10000]  Y axis top point value [0,10000] */
    INT32   dwRight;                              /* x轴右点值[0,10000]  X axis right point value [0,10000] */
    INT32   dwBottom;                             /* y轴底点值[0,10000]  Y axis bottom point value [0,10000] */
}NETDEV_RECT_S, *LPNETDEV_RECT_S;

/**
 * @struct tagNETDEVPtzOperateAreaInfo
 * @brief 图像区域信息 结构体定义 Image area information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPtzOperateAreaInfo
{
    INT32   dwBeginPointX;                           /* 区域起始点X值[0,10000]  Area start point X value [0,10000] */
    INT32   dwBeginPointY;                           /* 区域起始点Y值[0,10000]  Area start point Y value [0,10000] */
    INT32   dwEndPointX;                             /* 区域结束点X值[0,10000]  Area end point X value [0,10000] */
    INT32   dwEndPointY;                             /* 区域结束点Y值[0,10000]  Area end point Y value [0,10000] */
}NETDEV_PTZ_OPERATEAREA_S, *LPNETDEV_PTZ_OPERATEAREA_S;

/**
 * @struct tagNETDEVPictureData
 * @brief 图像数据 结构体定义 Image data Structure definition
 *        存放解码后图像数据的指针和长度等信息 Storing pointer and length of decoded picture data
 * @attention 无 None
 */
typedef struct tagNETDEVPictureData
{
    BYTE    *pucData[4];                /* pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针  pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32   dwLineSize[4];              /* ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距  ulLineSize[0]: Y line spacing, ulLineSize[1]: U line spacing, ulLineSize[2]: V line spacing */
    INT32   dwPicHeight;                /* 图片高度  Picture height */
    INT32   dwPicWidth;                 /* 图片宽度  Picture width */
    INT32   dwRenderTimeType;           /* 用于渲染的时间数据类型  Time data type for rendering */
    INT64   tRenderTime;                /* 用于渲染的时间数据  Time data for rendering */
}NETDEV_PICTURE_DATA_S, *LPNETDEV_PICTURE_DATA_S;

/**
 * @struct tagNETDEVWaveData
 * @brief 音频数据 结构体定义 Audio data Structure definition
 *        存放解码后音频数据的指针和长度等信息 Storing pointer and length of decoded picture data
 * @attention 无 None
 */
typedef struct tagNETDEVWaveData
{
    CHAR  *pcData;                      /* 音频数据指针  Audio data pointer */
    INT32 dwDataLen;                    /* 音频数据长度  Audio data length */
    INT32 dwWaveFormat;                 /* 解码后音频格式  Format of decoded audio*/
}NETDEV_WAVE_DATA_S, *LPNETDEV_WAVE_DATA_S;

/**
 * @struct tagNETDEVParseVideoData
 * @brief 视频解析数据 结构体定义 Video analytic data Structure definition
 *        存放拼帧后视频数据的指针和长度等信息 Storing pointer and length of framed video data
 * @attention 无 None
 */
typedef struct tagNETDEVParseVideoData
{
    BYTE   *pucData;             /* 视频数据指针  Pointer to video data */
    INT32  dwDataLen;            /* 视频数据长度  Video data length */
    INT32  dwVideoFrameType;     /* 视频帧类型,参考枚举#NETDEV_VIDEO_FRAME_TYPE_E  Frame type, see enumeration #NETDEV_VIDEO_FRAME_TYPE_E */
    INT32  dwVideoCodeFormat;    /* 视频编码格式,参考枚举#NETDEV_VIDEO_CODE_TYPE_E  Video encoding format, see enumeration #NETDEV_VIDEO_CODE_TYPE_E */
    INT32  dwHeight;             /* 视频图像高度  Video image height */
    INT32  dwWidth;              /* 视频图像宽度  Video image width */
    INT64  tTimeStamp;           /* 时间戳（毫秒）  Time stamp (ms) */
    BYTE  byRes[8];              /* 保留字段  Reserved field*/
}NETDEV_PARSE_VIDEO_DATA_S, *LPNETDEV_PARSE_VIDEO_DATA_S;


/**
 * @struct tagNETDEVVideoChlDetailInfo
 * @brief 视频通道详细信息 结构体定义  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoChlDetailInfo
{
    INT32                       dwChannelID;            /* 通道ID  Channel ID */
    INT32                       dwType;                 /* 保留字段  Reserved field*/
    NETDEV_CHANNEL_STATUS_E     enStatus;               /* 通道状态  Channel status */
    INT32                       dwStreamNum;            /* 流个数  Number of streams */
    BYTE                        byRes[68];              /* 保留字段  Reserved field*/
}NETDEV_VIDEO_CHL_DETAIL_INFO_S, *LPNETDEV_VIDEO_CHL_DETAIL_INFO_S;

/**
 * @struct tagNETDEVVideoStreamInfo
 * @brief 通道视频流信息 结构体定义 Channel video stream information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoStreamInfo
{
    NETDEV_LIVE_STREAM_INDEX_E  enStreamType;       /* 码流索引  Stream index */
    INT32                       bEnableFlag;        /* 是否启用  Enable or not */
    INT32                       dwHeight;           /* 视频编码分辨率-Height  Video encoding resolution - Height */
    INT32                       dwWidth;            /* 视频编码分辨率-Width  Video encoding resolution - Width */
    INT32                       dwFrameRate;        /* 视频编码配置帧率  Video encoding configuration frame rate */
    INT32                       dwBitRate;          /* 码率  Bit rate */
    NETDEV_VIDEO_CODE_TYPE_E    enCodeType;         /* 视频编码格式  Video encoding format */
    NETDEV_VIDEO_QUALITY_E      enQuality;          /* 图像质量  Image quality */
    INT32                       dwGop;              /* I帧间隔  I-frame interval */
    BYTE                        byRes[32];          /* 保留字段  Reserved */
}NETDEV_VIDEO_STREAM_INFO_S, *LPNETDEV_VIDEO_STREAM_INFO_S;


/**
 * @struct tagNETDEVLogFindCond
 * @brief 日志查询条件 结构体定义 Log query condition Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVLogFindCond
{
    NETDEV_LOG_MAIN_TYPE_E      enMainType;         /* 主类型  Main type */
    NETDEV_LOG_SUBTYPE_ID_E     enSubType;          /* 次类型  Sub type */
    INT64                       tBeginTime;         /* 起始时间  Start time */
    INT64                       tEndTime;           /* 结束时间  End time */
}NETDEV_LOG_FIND_COND_S, *LPNETDEV_LOG_FIND_COND_S;

/***************** 告警业务  Alarm services**************************************************/
/**
 * @struct tagNETDEVAlarmInfo
 * @brief 告警信息 结构体定义 Alarm information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInfo
{
    INT32   dwAlarmType;        /* 告警类型,参见枚举#NETDEV_ALARM_TYPE_E  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT64   tAlarmTime;         /* 告警发生时间  Alarm time */
    INT32   dwChannelID;        /* 通道号,用于NVR  Channel number for NVR */
    UINT16  wIndex;             /* 索引号,开关量索引号或磁盘槽位索引号  Index number, alarm input/output index number or disk slot index number */
    BYTE    byRes[26];          /* 保留字段  Reserved */
}NETDEV_ALARM_INFO_S, *LPNETDEV_ALARM_INFO_S;

/**
 * @struct tagNETDEVPullAlarmInfo
 * @brief  拉告警信息 结构体定义 Get alarm information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPullAlarmInfo
{
    NETDEV_ALARM_TYPE_E   enAlarm;         /* 告警类型  Alarm type */
    INT32   dwChancelId;                   /* 通道号,用于NVR  Channel number for NVR */
}NETDEV_PULLALARM_INFO_S, *LPNETDEV_PULLALARM_INFO_S;

/*********************** 开关量配置  Boolean configuration***************************** */

/**
 * @struct tagNETDEVAlarmInputInfo
 * @brief  告警开关量输入信息 结构体定义  Alarm boolean inputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInputInfo
{
    CHAR  szName[NETDEV_LEN_64];                                                  /* 输入开关量名称   Name of input alarm */
}NETDEV_ALARM_INPUT_INFO_S, *LPNETDEV_ALARM_INPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmInputInfoList
 * @brief  所有告警开关量输入信息 结构体定义  All Alarm boolean inputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInputInfoList
{
    INT32                        dwSize;                                           /* 输入开关量数量  Number of input alarms */
    NETDEV_ALARM_INPUT_INFO_S    astAlarmInputInfo[NETDEV_MAX_ALARM_IN_NUM];       /* 输入开关量配置信息  Configuration information of input alarms */
}NETDEV_ALARM_INPUT_LIST_S, *LPNETDEV_ALARM_INPUT_LIST_S;

/**
 * @struct tagNETDEVAlarmOutputInfo
 * @brief  告警开关量输出信息 结构体定义 Alarm boolean outputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmOutputInfo
{   
    CHAR    szName[NETDEV_LEN_64];                  /* 开关量名称  Boolean name */
    INT32   dwChancelId;                            /* 通道号 Channel number */
    INT32   enDefaultStatus;                        /* 输出开关量默认状态 参见#NETDEV_BOOLEAN_MODE_E  Default status of boolean output, see enumeration #NETDEV_BOOLEAN_MODE_E */
    INT32   dwDurationSec;                          /* 告警持续时间 单位 S  Alarm duration (s) */
} NETDEV_ALARM_OUTPUT_INFO_S, *LPNETDEV_ALARM_OUTPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmOutputList
 * @brief  所有告警开关量输入信息 结构体定义 All Alarm boolean outputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmOutputList
{   
    INT32                       dwSize;                                                 /* 开关量数量   Number of booleans  */
    NETDEV_ALARM_OUTPUT_INFO_S  astAlarmOutputInfo[NETDEV_MAX_ALARM_OUT_NUM];           /* 开关量配置信息  Boolean configuration information */
} NETDEV_ALARM_OUTPUT_LIST_S, *LPNETDEV_ALARM_OUTPUT_LIST_S;

/**
 * @struct tagNETDEVTriggerAlarmOutput
 * @brief  触发开关量输入告警 结构体定义 Trigger boolean output alarm Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVTriggerAlarmOutput
{   
    CHAR                        szName[NETDEV_LEN_64];          /* 开关量名称  Boolean name */
    NETDEV_RELAYOUTPUT_STATE_E  enOutputState;                  /* 触发状态,参考枚举#NETDEV_RELAYOUTPUT_STATE_E  Trigger status, see enumeration #NETDEV_RELAYOUTPUT_STATE_E */
} NETDEV_TRIGGER_ALARM_OUTPUT_S, *LPNETDEV_TRIGGER_ALARM_OUTPUT_S;

/************************************************ OSD********************************************************/

/**
 * @struct tagNETDEVAreaScope
 * @brief  区域 Area
 * @attention 无 None
 */
typedef struct tagNETDEVAreaScope
{
    INT32  dwLocateX;             /** 顶点x坐标值[0,10000] * Coordinates of top point x [0,10000] */
    INT32  dwLocateY;             /** 顶点y坐标值[0,10000] * Coordinates of top point y [0,10000] */
}NETDEV_AREA_SCOPE_S, *LPNETDEV_AREA_SCOPE_S;

/**
 * @struct tagNETDEVOsdTime
 * @brief OSD时间配置信息 OSD time configuration information
 * @attention 无 None
 */
typedef struct tagNETDEVOsdTime
{
    BOOL                    bEnableFlag;        /** 时间OSD使能, BOOL_TRUE为使能,BOOL_FALSE为非使能 * Enable time OSD, BOOL_TRUE means enable and BOOL_FALSE means disable */
    BOOL                    bWeekEnableFlag;    /** 是否显示星期(预留) * Display week or not (reserved) */
    NETDEV_AREA_SCOPE_S     stAreaScope;        /** 区域坐标 * Area coordinates */
    UINT32                  udwTimeFormat;      /** 时间OSD时间格式,详见NETDEV_OSD_TIME_FORMAT_E * Time OSD format, see NETDEV_OSD_TIME_FORMAT_E */
    UINT32                  udwDateFormat;      /** 日期OSD时间格式,详见NETDEV_OSD_DATE_FMT_E * Date OSD format, see NETDEV_OSD_TIME_FORMAT_E */

}NETDEV_OSD_TIME_S, *LPNETDEV_OSD_TIME_S;

/**
 * @struct tagNETDEVOsdTextOverlay
 * @brief OSD字符叠加信息 OSD text overlay information
 * @attention
 */
typedef struct tagNETDEVOsdTextOverlay
{
    BOOL                    bEnableFlag;                /** OSD字符叠加使能, BOOL_TRUE为使能,BOOL_FALSE为非使能 * Enable OSD text overlay, BOOL_TRUE means enable and BOOL_FALSE means disable */
    NETDEV_AREA_SCOPE_S     stAreaScope;                /** OSD字符叠加区域坐标 * OSD text overlay area coordinates */
    CHAR                    szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /** OSD字符叠加名称字符串 * OSD text overlay name strings */
    BYTE                    byRes[4];                               /* 保留字段  Reserved */
}NETDEV_OSD_TEXT_OVERLAY_S, *LPNETDEV_OSD_TEXT_OVERLAY_S;

/**
 * @struct tagNETDEVOsdCfgInfo
 * @brief 通道OSD的基本属性信息 Basic channel OSD information
 * @attention
 */
typedef struct tagNETDEVOsdCfgInfo
{
    NETDEV_OSD_TIME_S         stTimeOSD;        /* 通道的时间OSD信息  Information of channel time OSD */
    NETDEV_OSD_TEXT_OVERLAY_S stNameOSD;        /* 通道的名称OSD信息  Information of channel name OSD */
    INT16                     wTextNum;         /* 字符OSD个数  Text OSD number */
    NETDEV_OSD_TEXT_OVERLAY_S astTextOverlay[NETDEV_OSD_TEXTOVERLAY_NUM];   /* 通道OSD字符叠加信息  Information of channel OSD text overlay */
}NETDEV_VIDEO_OSD_CFG_S, *LPNETDEV_VIDEO_OSD_CFG_S;

/**
 * @struct tagAreaInfo
 * @brief 区域配置结构体定义 Definition of area configuration structure 
 * @attention
 */
typedef struct tagAreaInfo
{
    INT32   bIsEanbled;           /* 是否启用  Enable or not. */
    INT32   dwTopLeftX;           /* 左上角X [0, 10000]  Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /* 左上角Y [0, 10000]  Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /* 右下角X [0, 10000]  Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /* 右下角Y [0, 10000]  Lower right corner y [0, 10000] */
    INT32   dwIndex;              /* 索引  Index. */
}NETDEV_PRIVACY_MASK_AREA_INFO_S;

/**
 * @struct tagPrivacyMaskPara
 * @brief 隐私遮盖配置信息 Privacy mask configuration information
 * @attention
 */
typedef struct tagPrivacyMaskPara
{
    INT32                                  dwSize;                                     /* 区域个数  Mask area number */ 
    NETDEV_PRIVACY_MASK_AREA_INFO_S        astArea[NETDEV_MAX_PRIVACY_MASK_AREA_NUM];  /* 遮盖区域参数  Mask area parameters */
}NETDEV_PRIVACY_MASK_CFG_S, *LPNETDEV_PRIVACY_MASK_CFG_S;

/************************************************ 视频分析********************************************************/

/**
 * @struct tagNETDEVTamperAlarmInfo
 * @brief 遮挡检测分析信息
 * @attention 无 None
 */
typedef struct tagNETDEVTamperAlarmInfo
{
    INT32  dwSensitivity;                               /* 灵敏度  Sensitivity */
    BYTE   byRes[256];                                  /* 保留字段  Reserved */
}NETDEV_TAMPER_ALARM_INFO_S, *LPNETDEV_TAMPER_ALARM_INFO_S;

/**
 * @struct tagNETDEVMotionAlarmInfo
 * @brief 运动检测分析信息
 * @attention 无 None
 */
typedef struct tagNETDEVMotionAlarmInfo
{
    INT32  dwSensitivity;                                                     /* 灵敏度  Sensitivity */
    INT32  dwObjectSize;                                                      /* 物体大小  Objection Size */
    INT32  dwHistory;                                                         /* 持续时间  History */
    INT16  awScreenInfo[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];   /* 屏幕宏块信息  Screen Info */
    BYTE   byRes[64];                                                         /* 保留字段  Reserved */
}NETDEV_MOTION_ALARM_INFO_S, *LPNETDEV_MOTION_ALARM_INFO_S;

/**
 * @struct tagNETDEVUpnpPortState
 * @brief 协议信息  Protocol info
 * @attention 无 None
 */
typedef struct tagNETDEVUpnpPortState
{
    NETDEV_PROTOCOL_TYPE_E   eType;                            /* 协议类型参见枚举#NETDEV_PROTOCOL_TYPE_E  Protocol type, see enumeration #NETDEV_PROTOCOL_TYPE_E */
    BOOL                     bEnbale;                          /* 是否支持  Supported or not */
    INT32                    dwPort;                           /* 端口号  Port number */
    BYTE                     byRes[128];                       /* 保留字段  Reserved */
}NETDEV_UPNP_PORT_STATE_S, *LPNETDEV_UPNP_PORT_STATE_S;


/**
 * @struct tagNETDEVUpnpNatState
 * @brief 协议信息列表  Protocol info list
 * @attention 无 None
 */
typedef struct tagNETDEVUpnpNatState
{
    INT32   dwSize;                                            /* 协议个数  Number of protocols */
    NETDEV_UPNP_PORT_STATE_S  astUpnpPort[NETDEV_LEN_16];      /* 协议信息  Protocol info */
}NETDEV_UPNP_NAT_STATE_S, *LPNETDEV_UPNP_NAT_STATE_S;


/**
 * @struct tagNetDEVDiscoveryDevInfo
 * @brief 设备发现的设备信息  Info of discovered device
 * @attention 无 None
 */
typedef struct tagNetDEVDiscoveryDevInfo
{
    CHAR    szDevAddr[NETDEV_LEN_64];                            /* 设备地址  Device address */
    CHAR    szDevModule[NETDEV_LEN_64];                          /* 设备型号  Device model */
    CHAR    szDevSerailNum[NETDEV_LEN_64];                       /* 设备序列号  Device serial number */
    CHAR    szDevMac[NETDEV_LEN_64];                             /* 设备MAC地址  Device MAC address */
    CHAR    szDevName[NETDEV_LEN_64];                            /* 设备名称  Device name */
    CHAR    szDevVersion[NETDEV_LEN_64];                         /* 设备版本  Device version */
    NETDEV_DEVICETYPE_E  enDevType;                              /* 设备类型  Device type */
    INT32   dwDevPort;                                           /* 设备端口号  Device port number */
    BYTE    byRes[NETDEV_LEN_260];                               /* 保留字段  Reserved */
}NETDEV_DISCOVERY_DEVINFO_S, *LPNETDEV_DISCOVERY_DEVINFO_S;

/**
* @struct tagNETDEVTime
* @brief 时间参数 结构体定义 Time parameter Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVTime
{
    INT32   dwYear;                       /* 年  Year */
    INT32   dwMonth;                      /* 月  Month */
    INT32   dwDay;                        /* 日  Day */
    INT32   dwHour;                       /* 时  Hour */
    INT32   dwMinute;                     /* 分  Minute */
    INT32   dwSecond;                     /* 秒  Second */
}NETDEV_TIME_S, *LPNETDEV_TIME_S;

/**
* @struct tagNETDEVSystemTimeInfo
* @brief 时间配置 结构体定义 Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeInfo
{
    NETDEV_TIME_ZONE_E   dwTimeZone;                  /* 时区 参见枚举#NETDEV_TIME_ZONE_E  Time zone, see enumeration #NETDEV_TIME_ZONE_E */
    NETDEV_TIME_S        stTime;                      /* 时间  Time */
    BYTE                 byRes[260];                  /* 保留字段  Reserved */
}NETDEV_TIME_CFG_S, *LPNETDEV_TIME_CFG_S;

/* END************************************************ 结构体************************************************** */


/**
* 拼帧前媒体流数据回调函数的指针类型  Type of pointer to media stream data callback function before being framed 
* @param [IN] lpRealHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pucBuffer         存放拼帧前媒体流数据缓冲区指针 Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize         缓冲区大小 Buffer size
* @param [IN] dwMediaDataType   媒体数据类型,参见媒体类型枚举定义#NETDEV_MEDIAFORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       用户设置参数,即用户在调用#NDPlayer_SetSourceMediaDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return 无。 None.
* @note  用户应及时处理输出的媒体流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。 Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpRealHandle,
                                                       IN const BYTE    *pucBuffer,
                                                       IN INT32         dwBufSize,
                                                       IN INT32         dwMediaDataType,
                                                       IN LPVOID        lpUserParam
                                                       );

/**
* 拼帧后视频流数据回调函数的指针类型  Type of pointer to callback function for framed stream data 
* @param [IN] lpRealHandle          当前的实况播放句柄 Current live playing handle
* @param [IN] pstParseVideoData     存放拼帧后视频流数据信息缓冲区指针 Pointer to buffer that stores framed video stream data
* @param [IN] lUserParam            用户设置参数,即用户在调用#NDPlayer_SetParseVideoDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetParseVideoDataCB function
* @return 无。 None.
* @note
* -     用户应及时处理输出的数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。 Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                            IN const NETDEV_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                            IN LPVOID lpUserParam
                                                            );

/**
* 解码后视频流数据回调函数的指针类型  Type of pointer to callback function for decoded video stream data 
* @param [IN] lpRealHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pstPictureData    存放解码后视频流数据信息缓冲区指针 Pointer to buffer that stores decoded video stream data
* @param [IN] lpUserParam       用户设置参数,即用户在调用#NDPlayer_SetDecodeVideoDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetDecodeVideoDataCB function
* @return 无。 None.
* @note
* -     1、用户应及时处理输出的视频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。
* -     1. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
* -     2、视频数据是yv12格式。排列顺序“Y0-Y1-......”,“U0-U1-......”,“V0-V1-......”
* -     2. Video data is in yv12 format in sequence of Y0-Y1-......, U0-U1-......, V0-V1-......
*/
typedef void (STDCALL* NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                             IN const NETDEV_PICTURE_DATA_S *pstPictureData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
* 解码后音频流数据回调函数的指针类型  Type of pointer to callback function for decoded audio stream data 
* @param [IN] lpRealHandle   当前的实况播放句柄 Current live playing handle
* @param [IN] pstWaveData    存放解码后音频流数据信息缓冲区指针 Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NDPlayer_SetDecodeAudioDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return 无。 None.
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                             IN const NETDEV_WAVE_DATA_S *pstWaveData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
* 显示数据回调函数的指针类型 Type of pointer to display data callback function
* @param [IN] lpHandle       当前的实况播放句柄 Current live playing handle
* @param [IN] hdc            显示表面的hdc,用户可以用这个hdc 作图 Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NETDEV_SetPlayDisplayCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return 无。
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理。
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
                                                   IN LPVOID hdc,
                                                   IN LPVOID lpUserParam
                                                   );

/**
* 接收告警消息的回调函数  Callback function to receive alarm information
* @param [IN] lpUserID              用户登录ID User login ID
* @param [IN] dwChannelID           通道号 Channel number
* @param [IN] NETDEV_ALARM_INFO_S   告警信息 Alarm information
* @param [IN] lpBuf                 缓冲区指针 Pointer to buffer
* @param [IN] dwBufLen              告警信息对应结构体的长度 Length of structure for alarm information
* @param [IN] dwBufLen              用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwChannelID,
                                                   IN NETDEV_ALARM_INFO_S   stAlarmInfo,
                                                   IN LPVOID    lpBuf,
                                                   IN INT32     dwBufLen,
                                                   IN LPVOID    lpUserData
                                                   );

/**
* 接收异常、重连等消息的回调函数  Callback function to receive exception and reconnection messages
* @param [IN] lpUserID     用户登录ID User login ID
* @param [IN] dwType       异常或重连等消息的类型:NETDEV_EXCEPTION_TYPE_E Type of exception or reconnection message: NETDEV_EXCEPTION_TYPE_E
* @param [IN] lpExpHandle  出现异常的相应类型的句柄 Exception type handle
* @param [IN] lpUserData   用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_ExceptionCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwType,
                                                   IN LPVOID    lpExpHandle,
                                                   IN LPVOID    lpUserData
                                                   );

/**
* 注册回调函数,接收报警消息等（同时回调登录ID,用以区分不同设备） Register callback function and receive alarm information, etc. (Call back login ID at the same time to distinguish different devices)\n
* @param [IN] lpUserID              用户登录ID User login ID
* @param [IN] cbAlarmMessCallBack   回调函数 Callback function
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBack(IN LPVOID lpUserID,
                                                             IN NETDEV_AlarmMessCallBack_PF cbAlarmMessCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/**
* 注册sdk接收异常、重连等消息的回调函数  Callback function to register SDK, receive exception and reconnection messages, etc.
* @param [IN] cbExceptionCallBack       接收异常消息的回调函数,回调当前异常的相关信息 Callback function to receive exception messages, used to call back information about current exceptions
* @param [IN] lpUserData                用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetExceptionCallBack(IN NETDEV_ExceptionCallBack_PF cbExceptionCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
* 设备发现回调函数
* @param [IN] pstDevInfo                设备信息
* @param [IN] lpUserData                用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_DISCOVERY_CALLBACK_PF)(IN LPNETDEV_DISCOVERY_DEVINFO_S pstDevInfo,
                                                    IN LPVOID lpUserData
                                                    );

/**
* 注册设备发现回调函数
* @param [IN] cbDiscoveryCallBack   回调函数 Callback function
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDiscoveryCallBack(IN NETDEV_DISCOVERY_CALLBACK_PF cbDiscoveryCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
* 设备发现 先注册设备发现相关的回调,再调用此接口发现设备,发现的设备信息在回调中反映
* This interface is used for device discovery. Please first register callback functions related to device discovery and use this interface for device discovery. Discovered device info will be included in the callback function.
* @param [IN]   pszBeginIP                 起始IP地址
* @param [IN]   pszEndIP                   结束IP地址
* @return TRUE表示成功,其他表示失败
* @note 若pszBeginIP和pszEndIP都是"0.0.0.0",则搜索本网段设备
*/
NETDEV_API NEWINTERFACE BOOL  STDCALL NETDEV_Discovery(IN CHAR *pszBeginIP,
                                                       IN CHAR *pszEndIP
                                                       );

/**
* SDK 初始化  SDK initialization
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 线程不安全 Thread not safe
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

/**
* SDK 清理  SDK cleaning
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

/**
* 获取SDK的版本信息 Get SDK version information 
* @return SDK版本信息 SDK version information
* @note
* - 2个高字节表示主版本,2个低字节表示次版本。如0x00030000：表示版本为3.0。
* - The two high bytes indicate the major version, and the two low bytes indicate the minor version. For example, 0x00030000 means version 3.0.
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);



/**
* 用户登录  User login
* @param [IN]  pszDevIP         设备IP Device IP
* @param [IN]  wDevPort         设备服务器端口 Device server port
* @param [IN]  pszUserName      用户名 Username
* @param [IN]  pszPassword      密码 Password
* @param [OUT] pstDevInfo       设备信息结构体指针 Pointer to device information structure
* @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值。 Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
                                                    IN INT16 wDevPort,
                                                    IN char *pszUserName,
                                                    IN char *pszPassword,
                                                    OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                    );

/**
* 用户注销  User logout
* @param [IN] lpUserID    用户登录ID User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

/**
* 查询通道能力集  Query channel capabilities
* @param [IN]    lpUserID           用户登录ID User login ID
* @param [INOUT] pdwChlCount        通道数 Number of channels
* @param [OUT]   pstVideoChlList    通道能力集列表 List of channel capabilities
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlDetailList(IN LPVOID   lpUserID,
                                                                    INOUT INT32 *pdwChlCount,
                                                                    OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlList
                                                                    );


/*************** Begin实况业务  Begin live view services*********************************************/

/**
* 启动实时预览  Start live preview
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pstPreviewInfo       预览参数,参考枚举：NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E。 Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbRealDataCallBack   码流数据回调函数指针 Pointer to callback function of stream data
* @param [IN]  lpUserData           用户数据 User data
* @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值。 Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
                                                       IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                       IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                       IN LPVOID lpUserData
                                                       );

/**
* 停止实时预览  Stop live preview
* @param [IN]  lpRealHandle     预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 对应关闭NETDEV_RealPlay开启的实况 Stop the live view started by NETDEV_RealPlay
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpRealHandle);

/**
* 本地录像  Local recording
* @param [IN]  lpRealHandle         预览句柄 Preview handle
* @param [IN]  pszSaveFileName      保存的文件名 Name of saved file
* @param [IN]  dwFormat             Format of saved file, see #NETDEV_MEDIA_FILE_FORMAT_E 
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SaveRealData(IN LPVOID  lpRealHandle,
                                                         IN CHAR    *pszSaveFileName,
                                                         IN INT32   dwFormat
                                                         );

/**
* 停止本地录像 Stop local recording
* @param [IN]  lpRealHandle     预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopSaveRealData(IN LPVOID lpRealHandle);

/**
* 开启声音  Enable sound
* @param [IN]  lpRealHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenSound(IN LPVOID lpRealHandle);

/**
* 调节扬声器音量
* @param [IN]  lpRealHandle   预览句柄 Preview handle
* @param [IN]  dwVolume       音量 Volume
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SoundVolumeControl(IN LPVOID lpRealHandle, 
                                                               IN INT32 dwVolume
                                                               );

/**
* 关闭声音 Mute
* @param [IN]  lpRealHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseSound(IN LPVOID lpRealHandle);


/**
* 获取窗口码率  Get window bit rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwBitRate       获取的码率指针 Pointer to obtained bit rate
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetBitRate(IN LPVOID lpPlayHandle,
                                                       OUT INT32 *pdwBitRate
                                                       );

/*
* 获取窗口帧率  Get window frame rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwFrameRate     获取的帧率指针 Pointer to obtained frame rate
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetFrameRate(IN LPVOID lpPlayHandle,
                                                         OUT INT32 *pdwFrameRate
                                                         );

/**
* 获取窗口编码格式  Get window encoding format
* @param [IN]  lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [OUT] pdwVideoEncFmt       获取的视频编码格式指针 Pointer to obtained encoding format
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEncodeFmt(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pdwVideoEncFmt
                                                              );


/**
* 获取视频分辨率  Get video resolution
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwWidth         获取的分辨率-宽度指针 Pointer to obtained resolution – width
* @param [OUT] pdwHeight        获取的分辨率-高度指针 Pointer to obtained resolution – height
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetResolution(IN LPVOID lpPlayHandle,
                                                          OUT INT32 *pdwWidth,
                                                          OUT INT32 *pdwHeight
                                                          );

/**
* 获取窗口丢包率  Get window packet loss rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pulRecvPktNum    接收的数据包数量指针 Pointer to number of received packets
* @param [OUT] pulLostPktNum    丢失的数据包数量指针 Pointer to number of lost packets
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetLostPacketRate(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pulRecvPktNum,
                                                              OUT INT32 *pulLostPktNum
                                                              );

/**
* 重置窗口丢包率  Reset window packet loss rate
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetLostPacketRate(IN LPVOID lpPlayHandle);

/**
* 实况抓拍  Live view snapshot
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [IN]  pszFileName      保存图像的文件路径（包括文件名） File path to save images (including file name)
* @param [IN]  dwCaptureMode    保存图像格式,参见#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 文件名中可以不携带抓拍格式的后缀名 File format suffix is not required in the file name
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CapturePicture(IN LPVOID    lpPlayHandle,
                                                           IN char      *pszFileName,
                                                           IN INT32     dwCaptureMode
                                                           );

/**
* 设置视频图像显示比例  Modify image display ratio
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  enRenderScale  视频图像的显示比例 Image display ratio
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRenderScale(IN LPVOID lpPlayHandle,
                                                           IN NETDEV_RENDER_SCALE_E enRenderScale
                                                           );

/**
* 影像参数获取,只获取当前画面参数  Get the current image info
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  pstImageInfo   图像信息列表 Image information list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           OUT LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
* 影像调节,只改变当前画面  Adjust the current image
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  pstImageInfo   图像信息列表 Image information list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           IN LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
* 设置数字放大  Set Digital zoom
* @param [IN] lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN] hWnd           窗口句柄  window handle 
* @param [IN] pstRect        矩形区域 Rectangle Area
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note pstRect为空时,显示全部画面,即退出数字放大
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDigitalZoom(IN LPVOID          lpPlayHandle, 
                                                           IN LPVOID          hWnd,
                                                           IN LPNETDEV_RECT_S pstRect
                                                           );

/**
* 注册码流回调函数:原始码流  Callback function to register streams (original stream)
* @param [IN]  lpRealHandle               实时预览句柄 Live preview handle
* @param [IN]  cbSourceDataCallBack       码流数据回调函数 Callback function for stream data
* @param [IN]  bContinue                  是否继续进行后面的拼帧、解码和显示操作 Whether to continue to following framing, decoding and displaying operations.
* @param [IN]  lpUser                     用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE  BOOL STDCALL NETDEV_SetPlayDataCallBack(IN LPVOID lpPlayHandle,
                                                                 IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUser);

/**
* 注册实况码流回调函数:拼帧后码流数据  Callback function to register live stream (framed stream data)
* @param [IN]  lpPlayHandle              预览\回放句柄 Preview\playback handle
* @param [IN]  cbParsePlayDataCallBack   数据回调函数 Data callback function
* @param [IN]  bContinue                 是否继续 Continue or not
* @param [IN]  lpUserData                用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL。
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseCB(IN LPVOID    lpPlayHandle,
                                                           IN NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF cbParsePlayDataCallBack,
                                                           IN INT32     bContinue,
                                                           IN LPVOID    lpUserData
                                                           );

/**
* 注册实时码流回调函数：解码后视频媒体流数据  Callback function to register live stream (decoded media stream data)
* @param [IN]  lpPlayHandle                 预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDecodeVideoCALLBACK    数据回调函数 Data callback function
* @param [IN]  bContinue                    是否继续 Continue or not
* @param [IN]  lpUserData                   用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL。
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeVideoCB(IN LPVOID  lpPlayHandle,
                                                                 IN NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF cbPlayDecodeVideoCALLBACK,
                                                                 IN INT32   bContinue,
                                                                 IN LPVOID  lpUserData
                                                                 );

/**
* 设置显示后数据回调  Modify displayed data callback
* @param [IN]  lpPlayHandle             预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDisplayCallBack    数据回调函数 Data callback function
* @param [IN]  lpUserData               用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL。
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDisplayCB(IN LPVOID lpPlayHandle,
                                                             IN NETDEV_DISPLAY_CALLBACK_PF cbPlayDisplayCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/***************实况业务 live view service*************************************************/

/***************回放业务 Begin playback service********************************************/

/**
* 根据文件类型、时间查找设备录像文件  Query recording files according to file type and time
* @param [IN]  lpUserID     用户登录ID User login ID
* @param [IN]  pstFindCond    录像查询条件 Search condition
* @return 录像查询业务号,返回0表示失败,其他值作为NETDEV_FindClose等函数的参数。
Recording search service number. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_FindClose.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindFile(IN LPVOID lpUserID,
                                                       IN LPNETDEV_FILECOND_S pstFindCond
                                                       );

/**
* 逐个获取查找到的文件信息  Obtain the information of found files one by one.
* @param [IN]  lpFindHandle     文件查找句柄 File search handle
* @param [OUT] pstFindData       保存文件信息的指针 Pointer to save file information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextFile(IN LPVOID lpFindHandle,
                                                         OUT LPNETDEV_FINDDATA_S pstFindData
                                                         );

/**
* 关闭文件查找,释放资源  Close file search and release resources
* @param [IN] lpFindHandle  文件查找句柄 File search handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindClose(IN LPVOID lpFindHandle);


/**
* 按名称回放录像文件  Play back recording files by name
* @param [IN] lpUserID          用户登录ID User login ID
* @param [IN] pstPlayBackInfo   录像回放结构体指针,参考 LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByName(IN LPVOID lpUserID,
                                                  IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo
                                                  );

/**
* 按时间回放录像文件  Play back recording by time. 
* @param [IN] lpUserID          用户登录ID User login ID
* @param [IN] pstPlayBackCond   按时间录像回放结构体指针  参考 LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByTime(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKCOND_S pstPlayBackInfo
                                                             );

/**
* 停止回放业务  Stop playback service
* @param [IN] lpPlayHandle  回放句柄 Playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPlayBack(IN LPVOID lpPlayHandle);

/**
* 文件名下载录像文件 Download recordings by file name
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pstPlayBackInfo      录像回放结构体指针,参考 LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @param [IN]  *pszSaveFileName     下载后保存到PC机的文件路径,需为绝对路径（包括文件名） Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat             录像文件保存格式 Recording file saving format
* @return 下载句柄, 返回0表示失败,其他值作为NETDEV_StopGetFile等函数的参数。 Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByName(IN LPVOID  lpUserID,
                                                 IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo,
                                                 IN char    *pszSaveFileName,
                                                 IN INT32   dwFormat
                                                 );


/**
* 按时间下载录像文件 Download recordings by time
* @param [IN]  lpUserID                用户登录ID User login ID
* @param [IN]  pstPlayBackCond   按时间录像回放结构体指针,参考 LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @param [IN]  *pszSaveFileName        下载后保存到PC机的文件路径,需为绝对路径（包括文件名） Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat                录像文件保存格式 Recording file saving format
* @return 下载句柄, 返回0表示失败,其他值作为NETDEV_StopGetFile等函数的参数。 Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByTime(IN LPVOID lpUserID, 
                                                            IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond, 
                                                            IN char *pszSaveFileName, 
                                                            IN INT32 dwFormat
                                                            );

/**
* 停止下载录像文件 Stop downloading recording files
* @param [IN]  lpPlayHandle  回放句柄 Playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopGetFile(IN LPVOID lpPlayHandle);


/**
* 控制录像回放的状态  Control recording playback status.
* @param [IN]  lpPlayHandle     回放或下载句柄 Playback or download handle
* @param [IN]  dwControlCode    控制录像回放状态命令 参考枚举：NETDEV_VOD_PLAY_CTRL_E Command for controlling recording playback status, see NETDEV_VOD_PLAY_CTRL_E
* @param [INOUT]  lpBuffer     指向输入/输出参数的指针, 播放速度参考枚举：NETDEV_VOD_PLAY_STATUS_E,播放时间参数类型为：INT64 Pointer to input/output parameters. For playing speed, see NETDEV_VOD_PLAY_STATUS_E. The type of playing time: INT64.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 开始、暂停、恢复播放时,lpBuffer置为NULL When playing, pause or resume videos, set IpBuffer as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PlayBackControl(IN LPVOID   lpPlayHandle,
                                                            IN INT32    dwControlCode,
                                                            INOUT LPVOID lpBuffer
                                                            );




/***********回放业务 End playback service ************************************************ */

/*********** 云台控制  Begin PTZ control ************************************************* */
/**
* 云台预置位操作(需先启动预览)  PTZ preset operation (preview required)
* @param [IN]  lpRealHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZPresetCmd       操作云台预置位命令,参考枚举NETDEV_PTZ_PRESETCMD_E  PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        预置位的名称 Preset name
* @param [IN]  dwPresetID           预置位的序号（从1开始）,最多支持255个预置位 Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset(IN LPVOID lpRealHandle,
                                                      IN INT32  dwPTZPresetCmd,
                                                      IN CHAR   *pszPresetName,
                                                      IN INT32  dwPresetID
                                                      );

/**
* 云台预置位操作(不需要启动预览)  PTZ preset operation (preview not required)
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwPTZPresetCmd       操作云台预置位命令,参考枚举NETDEV_PTZ_PRESETCMD_E PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        预置位的名称 Preset name
* @param [IN]  dwPresetID           预置位的序号（从1开始）,最多支持255个预置位。 Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset_Other(IN LPVOID   lpUserID,
                                                            IN INT32    dwChannelID,
                                                            IN INT32    dwPTZPresetCmd,
                                                            IN CHAR     *pszPresetName,
                                                            IN INT32    dwPresetID
                                                            );

/**
* 云台控制操作(需先启动实况预览)  PTZ control operation (preview required)
* @param [IN]  lpRealHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZCommand         云台控制命令,参见#NETDEV_PTZ_E PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              云台控制的速度,用户按不同解码器的速度控制值设置。取值范围[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl(IN LPVOID    lpRealHandle,
                                                       IN INT32     dwPTZCommand,
                                                       IN INT32     dwSpeed
                                                       );


/**
* 云台控制操作(不启动实况预览)  PTZ control operation (preview not required)
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel Number
* @param [IN]  dwPTZCommand         云台控制命令,参见#NETDEV_PTZ_E
PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              云台控制的速度,用户按不同解码器的速度控制值设置。取值范围[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl_Other(IN LPVOID  lpUserID,
                                                             IN INT32   dwChannelID,
                                                             IN INT32   dwPTZCommand,
                                                             IN INT32   dwSpeed
                                                             );

/**
* 获取云台预置位巡航路径  Get PTZ preset patrol route
* @param [IN]   lpUserID            用户登录ID User login ID
* @param [IN]   dwChannelID         通道号 Channel number
* @param [OUT]  pstCruiseList        巡航路径列表 Patrol route list
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetCruise(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         OUT LPNETDEV_CRUISE_LIST_S pstCruiseList
                                                         );

/**
* 云台预置位巡航操作(不需要启动预览)  PTZ preset patrol operation (preview not required)
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwPTZCruiseCmd       操作云台巡航命令,参考#NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see #NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         云台巡航路径信息,参考#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1、巡航路径,最多支持16条路径（序号从1开始） Patrol route. Up to 16 routes are supported (starting from 1).
* - 2、巡航点,最多支持32个点（序号从1开始） Patrol point. Up to 32 points are supported (starting from 1).
* - 3、预置位(最大255)、时间(最大255)、速度(最大40)  Preset (max 255), time (max 255) and speed (max 40).
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise_Other(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN INT32 dwPTZCruiseCmd,
                                                            IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                            );


/**
* 云台预置位巡航操作(需先启动预览)  PTZ preset patrol operation (preview required)
* @param [IN]  lpRealHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZCruiseCmd       操作云台巡航命令,参考枚举：NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         云台巡航路径信息,参考#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1、巡航路径ID不可修改。 Patrol route ID cannot be modified.
* - 2、新增巡航路径时,默认按顺序新增。  New routes are added one after another.
* - 3、删除、开始、停止巡航路径时,pstCruiseInfo中只需要填写巡航路径ID即可。  When deleting, starting or stopping patrol, enter patrol route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise(IN LPVOID lpRealHandle,
                                                      IN INT32 dwPTZCruiseCmd,
                                                      IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                      );


/**
* 获取云台轨迹巡航路径  Get PTZ patrol route
* @param [IN]   lpUserID            用户登录ID User login ID
* @param [IN]   dwChannelID         通道号 Channel number
* @param [OUT]  pstTrackCruiseInfo        巡航路径列表,参考#LPNETDEV_PTZ_TRACK_INFO_S  Patrol route list, see #LPNETDEV_PTZ_TRACK_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackCruise(IN LPVOID  lpUserID,
                                                              IN INT32   dwChannelID,
                                                              OUT LPNETDEV_PTZ_TRACK_INFO_S pstTrackCruiseInfo
                                                              );

/**
* 云台轨迹巡航操作(不需要启动预览)   PTZ route patrol operation (preview not required)
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwPTZCruiseCmd       操作云台轨迹巡航命令,参考#NETDEV_PTZ_TRACKCMD_E  PTZ route patrol operation commands, see #NETDEV_PTZ_TRACKCMD_E
* @param [INOUT]  pszTrackCruiseName         轨迹巡航名称,建议长度#NETDEV_LEN_64  Route patrol name, suggested length #NETDEV_LEN_64
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1、巡航轨迹路径,最多支持1条路径  Only one patrol route allowed.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZTrackCruise(IN LPVOID lpUserID,
                                                           IN INT32 dwChannelID,
                                                           IN INT32 dwPTZTrackCruiseCmd,
                                                           INOUT CHAR *pszTrackCruiseName
                                                           );

/**
* 拉框放大、缩小(需先启动预览)   Drag to zoom in and out (preview required)
* @param [IN]  lpRealHandle         实时预览句柄 Live preview handle
* @param [IN]  pstPtzOperateArea    拉框放大结构体信息 Drag-to-zoom structure information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 在我司NVR下,需通过私有协议连接我司IPC才支持该接口  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn(IN LPVOID lpRealHandle, 
                                                         IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                         );

/**
* 拉框放大、缩小(不需要启动预览)   Drag to zoom in and out(preview not required)
* @param lpUserID                   用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  pstPtzOperateArea    拉框放大结构体信息 Drag-to-zoom structure information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 在我司NVR下,需通过私有协议连接我司IPC才支持该接口  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn_Other(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID,
                                                               IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                               );

/**********云台控制  End PTZ control ************************************************/

/********** 远程参数配置 Begin remote parameter configuration ***********************/

/**
* 获取设备的配置信息  Get configuration information of device
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   dwChannelID             通道号 Channel number
* @param [IN]   dwCommand               设备配置命令,参见#NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [OUT]  lpOutBuffer             接收数据的缓冲指针 Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         接收数据的缓冲长度(以字节为单位),不能为0 Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned        实际收到的数据长度指针,不能为NULL  Pointer to length of received data, cannot be NULL.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1、巡航路径ID不可修改。  Route ID cannot be modified.
* - 2、新增巡航路径时,默认按顺序新增。  New routes are added one after another.
* - 3、删除、开始、停止巡航路径时,pstCruiseInfo中只需要填写巡航路径ID即可。  When deleting, starting or stoping a patrol route, enter route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         OUT LPVOID lpOutBuffer,
                                                         OUT INT32  dwOutBufferSize,
                                                         OUT INT32  *pdwBytesReturned
                                                         );

/**
* 设置设备的配置信息  Modify device configuration information
* @param [IN]   lpUserID            用户登录ID User login ID
* @param [IN]   dwChannelID         通道号 Channel number
* @param [IN]   dwCommand           设备配置命令,参见#NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [IN]   lpInBuffer          输入数据的缓冲指针 Pointer to buffer of input data
* @param [IN]   dwInBufferSize      输入数据的缓冲长度(以字节为单位) Length of input data buffer (byte)
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         IN LPVOID  lpInBuffer,
                                                         IN INT32   dwInBufferSize
                                                         );

/**************远程参数配置  End remote parameter configuration ******************************/
/**
* 重启设备\n
* Restart device\n
* @param [IN]  lpUserID     用户登录ID User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Reboot(IN LPVOID lpUserID);

/**
* 恢复出厂设置  Restore to factory default settings
* @param [IN]  lpUserID     用户登录ID User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 保留网络配置和用户配置,其他参数恢复到出厂设置。 Restore all parameters to factory settings, except network settings and user settings.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_RestoreConfig(IN LPVOID lpUserID);

/**
* 获取错误码  Get error codes
* @return 错误码 Error codes
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetLastError();

/**
* 主动获取设备告警信息  Get alarm information from the device
* @param [IN]  lpUserID        用户登录ID User login ID
* @param [IN]  dwPullWaitTime  告警等待时间,单位s Alarm wait time (s)
* @param [INOUT] pdwListCnt     告警最大数量,入参数时表示告警信息列表大小,出参时表示实际告警数量Maximum number of alarms. When working as an input parameter, it indicates the length of alarm information list; when working as an output parameter, it indicates the actual number of alarms.
* @param [OUT]   pstPullAlarmList   告警信息列表,此内存需预先分配 List of alarm information. The memory should be allocated in advance.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* note: 函数调用会阻塞login,logout, 不建议长时间等待 Calling the function will block login and logout. It is not recommended to wait for a long time.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PullAlarm(IN LPVOID lpUserID, 
                                                      IN INT32 dwPullWaitTime, 
                                                      INOUT INT32 *pdwListCnt, 
                                                      OUT LPNETDEV_PULLALARM_INFO_S pstPullAlarmList
                                                      );

/**
* 非预览下抓拍  Snapshot without preview
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwStreamType;        码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E 
* @param [IN]  pszFileName          保存图像的文件路径（包括文件名） File path to save images (including file name)
* @param [IN]  dwCaptureMode        保存图像格式,参见#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
        仅支持JPG格式。
        Only JPG format is supported.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CaptureNoPreview(IN LPVOID lpUserID,
                                                             IN INT32 dwChannelID,
                                                             IN INT32 dwStreamType,
                                                             IN CHAR *pszFileName,
                                                             IN INT32 dwCaptureMode
                                                             );

/**
* 动态产生一个关键帧\n 
* Dynamically create an I frame\n 
* @param [IN] lpUserID       用户登录ID  User login ID
* @param [IN] dwChannelID    通道号  Channel number
* @param [IN] dwStreamType   参考枚举NETDEV_LIVE_STREAM_INDEX_E  See enumeration NETDEV_LIVE_STREAM_INDEX_E
* @return NETDEV_E_SUCCEED   表示成功,其他表示失败  NETDEV_E_SUCCEED means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MakeKeyFrame(IN LPVOID lpUserID,
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType
                                                         );

/**
* 设置保活参数
* Set keep-alive parameters
* @param [IN]  dwWaitTime            间隔等待时间  Waiting time
* @param [IN]  dwTrytimes            尝试连接次数  Connecting attempts
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetConnectTime(IN INT32 dwWaitTime,
                                                           IN INT32 dwTrytimes
                                                           );

/**
* 设置设备名称业务\n
* Set device name\n
* @param [IN] lpUserID         用户登录ID User login ID
* @param [IN] pszDeviceName    设备名称  Device name
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyDeviceName(IN LPVOID lpUserID,
                                                             IN CHAR* pszDeviceName
                                                             );

/**
* 获取映射端口业务\n
* @param [IN]   lpUserID     用户登录ID User login ID
* @param [IN]   pstNatState  网络端口号状态信息
* @return TRUE表示成功,     其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUpnpNatState(IN LPVOID lpUserID,
                                                            OUT LPNETDEV_UPNP_NAT_STATE_S pstNatState
                                                            );

/**
* 设置日志路径业务\n
* Set log path\n
* @param [IN]   pszLogPath  日志路径(不包含文件名)  Log path (file name not included)
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetLogPath(IN CHAR* pszLogPath);

/**
* 获取设备系统时间配置\n
* Get device System time configuration\n
* @param [IN]  pstSystemTimeInfo    时间配置结构体指针  Pointer to time configuration structure
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSystemTimeCfg(IN LPVOID lpUserID,
                                                             OUT LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

/**
* 设置设备系统时间配置\n
* Set device system time configuration\n
* @param [IN]  pstSystemTimeInfo    时间配置结构体指针  Pointer to time configuration structure
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetSystemTimeCfg(IN LPVOID lpUserID,
                                                             IN LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */

