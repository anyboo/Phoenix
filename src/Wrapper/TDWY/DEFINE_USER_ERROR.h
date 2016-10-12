#ifndef _DEFINE_USER_ERROR_H
#define _DEFINE_USER_ERROR_H

//提供给用户的详细错误说明
#define USER_ERROR  0x10000000
#define ERROR_NO_DEV			USER_ERROR+1    //没有找到设备
#define ERROR_UNLOGON			USER_ERROR+2    //未登录
#define ERROR_PARAM_OVER		USER_ERROR+3    //参数越界
#define ERROR_REOPERATION		USER_ERROR+4    //重复操作
#define ERROR_WSASTARTUP		USER_ERROR+5    //WSAStartup执行失败
#define ERROR_CREATEMSG			USER_ERROR+6    //创建消息循环失败
#define ERROR_NOSUPPORTRECORD   USER_ERROR+7    //不支持前端录像　
#define ERROR_INITCHANNELNET    USER_ERROR+8    //通道网络创建失败
#define ERROR_CREATEDDRAW       USER_ERROR+9    //无法创建更多的DirectDraw
#define ERROR_NO_CHANNEL		USER_ERROR+10   //通道没有创建
#define ERROR_NO_FUN            USER_ERROR+11   //无此功能
#define ERROR_PARAM_INVALID     USER_ERROR+12   //参数无效 
#define ERROR_DEV_FULL			USER_ERROR+13   //设备列表已满
#define ERROR_LOGON				USER_ERROR+14   //设备已经登录，正在登录
#define ERROR_CREATECPUTHREAD   USER_ERROR+15   //创建CPU检测线程失败
#define ERROR_CREATEPLAYER      USER_ERROR+16   //创建Player失败
#define ERROR_NOAUTHORITY		USER_ERROR+17   //权限不足
#define ERROR_NOTALK            USER_ERROR+18   //未对讲
#define ERROR_NOCALLBACK		USER_ERROR+19   //没有设备回调函数
#define ERROR_CREATEFILE        USER_ERROR+20   //创建文件失败
#define ERROR_NORECORD			USER_ERROR+21   //不是从当前Player发起的录像
#define ERROR_NOPLAYER			USER_ERROR+22   //没有对应Player
#define ERROR_INITCHANNEL       USER_ERROR+23   //通道没有初始化
#define ERROR_NOPLAYING         USER_ERROR+24   //Player没有播放
#define ERROR_PARAM_LONG		USER_ERROR+25   //字符串参数长度过长
#define ERROR_INVALID_FILE      USER_ERROR+26   //文件不符合要求
#define ERROR_USER_FULL			USER_ERROR+27   //用户列表已满
#define ERROR_USER_DEL			USER_ERROR+28   //当前用户无法删除
#define ERROR_CARD_LOAD			USER_ERROR+29	//加载卡dll失败
#define ERROR_CARD_CORE			USER_ERROR+30	//加载卡内核失败
#define ERROR_CARD_COREFILE		USER_ERROR+31	//加载卡内核文件失败
#define ERROR_CARD_INIT			USER_ERROR+32	//卡初始化失败
#define ERROR_CARD_COREREAD		USER_ERROR+33	//读取卡内核文件失败
#define ERROR_CHARACTER_LOAD	USER_ERROR+34	//加载字库失败
#define ERROR_NOCARD			USER_ERROR+35   //卡未初始化
#define ERROR_SHOW_MODE			USER_ERROR+36   //显示模式未设置
#define ERROR_FUN_LOAD			USER_ERROR+37	//函数未加载
#define ERROR_CREATE_DOWNLOAD	USER_ERROR+38	//没有更多的下载通道可用
#define	ERROR_PROXY_DELACT		USER_ERROR+39   //删除的是主动模式的服务器
#define ERROR_PROXY_HASCONNECT	USER_ERROR+40	//还有连接
#define ERROR_PROXY_NOPROXY		USER_ERROR+41   //代理没有启动
#define ERROR_PROXY_IDENTITY	USER_ERROR+42	//不是代理的身份
#define	ERROR_CONNECT_MAX		USER_ERROR+43	//连接已经到达最大
#define	ERROR_NO_DISK			USER_ERROR+44	//没有挂接存储设备

#define ERROR_ALREADY_INTERTALK			(USER_ERROR+0x32)		//	正在进行双向对讲
#define ERROR_FUNCTION_NOT_SUPPORTED	(USER_ERROR+0x33)		//	功能不被此设备所支持
#define ERROR_DISPLAY_ON_OTHER_WND		(USER_ERROR+0x34)		//	正在其它窗口中显示
#define ERROR_BUFFER_TOO_SMALL	(USER_ERROR+0x35)		//	缓冲区太小
#define ERROR_NVR_NOT_SUPPORT	(USER_ERROR+0x36)		//	此设备不支持NVR相关功能

#define	ERROR_EVENT_NOT_ENABLE	(USER_ERROR+0x38)		//	本规则中此事件没有使能
#define ERROR_RULE_NOT_ENALE	(USER_ERROR+0x39)		//	此规则没有使能
#define ERROR_UNSUPPORT_STREAM	(USER_ERROR+0x40)		//	不支持码流类型

#endif
