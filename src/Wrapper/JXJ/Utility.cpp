#include "JXJ/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>
#include <memory>
#include "JNetSDK.h"
#include "j_sdk.h"
#include "AVPlayer.h"
#include "Jtype.h"


extern "C"
{

	typedef int (*PJNetInit)(LPCTSTR lpszLogName);
	typedef int (*PJNetCleanup)();

	typedef long (*PJNetLogin)(LPCTSTR lpszIP, int iDevPort, LPCTSTR lpszUser, LPCTSTR lpszPassword,
		int iTimeOut, fcbJEvent* pfcbEvent, void* pUserParam, DWORD dwProtocol, long& lLogin, PSTJProxyParam pstProxy);
	typedef long (*PJNetLogout)(long lLogin);

	typedef long (*PJNetGetParam)(long lLogin, int iChn, int iParamID, void* lpData, int iDataLen, fcbJGetParam* pfcbGetParam, void* pUser);

	typedef long (*PJNetRecOpen4Time)(long lLogin,
		LPCTSTR lpszDevIP, int iChn, int iStreamID, LPCTSTR lpszBeginTime, LPCTSTR lpszEndTime, int iRecType,
		int iIsPlay, fcbJStream* pfcbStream, void* pUserData, long& lRec);
	typedef long (*PJNetRecCtrl)(long lRec, eJNetPBCtrl eCtrlCmd, void* lpCtrlValue);
	typedef long (*PJNetRecClose)(long lRec);
	

	typedef int (*PAVP_Init)();
	typedef int (*PAVP_Cleanup)();
	typedef int (*PAVP_CreateRecFile)(LPCTSTR lpszPath, DWORD dwProtocol, DWORD dwEncoder);
	typedef int (*PAVP_WriteRecFile)(int iFile, void* lpFrame, int iFrameLen, void* lpBuf2, int iBufLen2);
	typedef int (*PAVP_PutFrame)(int iPort, void* pFrame);
	typedef int (*PAVP_SetPlayPriority)(int iPort, int iPriorityType);
	typedef int (*PAVP_SetDataProtocol)(int iPort, DWORD dwProtocol);
	typedef int (*PAVP_SetCoder)(int iPort, LPCTSTR lpszCoderName);
	typedef int (*PAVP_AddPlayWnd)(int iPort, PSTDisplayDev pstDispDev, HWND hWnd, LPRECT lpDrawOffset, LPRECT lpSrcOffset);
	typedef int (*PAVP_Play)(int iPort);
	typedef int (*PAVP_GetFreePort)();
	typedef int (*PAVP_Stop)(int iPort);
	typedef int (*PAVP_ReleasePort)(int iPort);
	typedef int (*PAVP_Seek)(int iPort, DWORD dwTime);
	typedef int (*PAVP_CloseRecFile)(int iFile);

}


extern Poco::SharedLibrary sl;
extern Poco::SharedLibrary avplayer;





namespace DVR {
	namespace JXJLite {



		Utility::Utility()
		{

		}


		Utility::~Utility()
		{
		}

		std::string Utility::lastError(int error)
		{
			switch (error)
			{
			case JNETErrSuccess: return "成功";
			case JNETErrUnInit: return "未初始化";
			case JNETErrHandle: return "句柄不存在";
			case JNETErrParam: return "参数错误";
			case JNETErrBuffSize: return "缓存满";
			case JNETErrNoMem: return "内存不足";
			case JNETErrRecv: return "接收错误";
			case JNETErrSend: return "发送错误";
			case JNETErrOperate: return "操作错误";
			case JNETErrURL: return "URL有误";
			case JNETErrLogining: return "用户正在登录";
			case JNETErrLogout: return "已经登出";
			case JNETErrNoFreePort: return "没有空闲通道";
			case JNETErrProtocol: return "协议错误";
			case JNETErrXMLFormat: return "错误的XML数据";
			case JNETErrNotSupport: return "不支持的操作";
			case JNETErrGetParam: return "获取参数错误";
			case JNETErrSetParam: return "设置参数错误";
			case JNETErrOpenFile: return "打开文件出错";
			case JNETErrUpgOpen: return "升级出错";

			}

			return "未定义";
		}

		std::string Utility::lastError(const DVRSession& session)
		{
			return "error";
		}

		void Utility::throwException(Utility::HANDLE handle)
		{

		}

		void Utility::throwException(int rc, const std::string& addErrMsg)
		{

		}

		void NetTimeToTM(const JTime& nt, tm& t)
		{
			t.tm_year = nt.year;
			t.tm_mon = nt.month - 1;
			t.tm_mday = nt.date;
			t.tm_hour = nt.hour;
			t.tm_min = nt.minute;
			t.tm_sec = nt.second;
		}

		void TMToNetTime(const tm& t, JTime& nt)
		{
			nt.year = t.tm_year;
			nt.month = t.tm_mon + 1;
			nt.date = t.tm_mday;
			nt.hour = t.tm_hour;
			nt.minute = t.tm_min;
			nt.second = t.tm_sec;
			nt.weekday = t.tm_wday + 1;
		}
		
		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& _addr,
			const std::string& user,
			const std::string& password,
			DVRINFO& info)
		{
			Utility::HANDLE handle = -1;				
			int nError = 0;
			Utility::HANDLE ret = 0;

			poco_assert(sl.hasSymbol("JNetLogin"));
			PJNetLogin JNetLogin = (PJNetLogin)sl.getSymbol("JNetLogin");		

			poco_assert(sl.hasSymbol("JNetGetParam"));
			PJNetGetParam JNetGetParam = (PJNetGetParam)sl.getSymbol("JNetGetParam");

			sockaddr_in* pSin = (sockaddr_in*)_addr.addr();
			std::cout << "IP: " << inet_ntoa(pSin->sin_addr) << " port:" << _addr.port() << std::endl;
			
			ret = JNetLogin(inet_ntoa(pSin->sin_addr), _addr.port(), (char *)user.c_str(), (char *)password.c_str(), 1000, NULL, NULL, JNET_PRO_T_JPF, handle, NULL);
			if ( ret < 0)			
			{
				std::cout << "login error:" << lastError(ret) << std::endl;
				return -1;
			}		
			std::cout << "login handle: " << handle << std::endl;

			::Sleep(1000);
			JDeviceInfo deviceinfo /*= { 0 }*/;
			ret = JNetGetParam(handle, 0, PARAM_DEVICE_INFO, (char *)&deviceinfo, sizeof(deviceinfo), NULL, NULL);
			if (ret != JNETErrSuccess)
			{
				std::cout << "get channel error:" << lastError(ret) << std::endl;
				return -1;
			}
			info.nTotalChannel = deviceinfo.channel_num;

			std::cout << "login handle: " << handle << " channel: " << info.nTotalChannel << std::endl;			

			return handle;
		}

		int Utility::logout(Utility::HANDLE handle)
		{			
			poco_assert(sl.hasSymbol("JNetLogout"));
			PJNetLogout JNetLogout = (PJNetLogout)sl.getSymbol("JNetLogout");
			std::cout << "logout handle: " << handle << std::endl;
			return JNetLogout(handle);			
		}

		int Utility::setTimeOut(std::size_t timeout, std::size_t times)
		{						
			return 0;
		}

		int Utility::Init()
		{
			std::cout << "init " << std::endl;	
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("JNetInit"));
			PJNetInit JNetInit = (PJNetInit)sl.getSymbol("JNetInit");

			poco_assert(avplayer.isLoaded());
			poco_assert(avplayer.hasSymbol("AVP_Init"));
			PAVP_Init AVP_Init = (PAVP_Init)avplayer.getSymbol("AVP_Init");
			AVP_Init();

			if (JNETErrSuccess == JNetInit(NULL))
				return Utility::success;
			return -1;
		}

		int Utility::CleanUp()
		{			
			std::cout << "CleanUp" << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("JNetCleanup"));
			PJNetCleanup JNetCleanup = (PJNetCleanup)sl.getSymbol("JNetCleanup");

			poco_assert(avplayer.isLoaded());
			poco_assert(avplayer.hasSymbol("AVP_Cleanup"));
			PAVP_Cleanup AVP_Cleanup = (PAVP_Cleanup)avplayer.getSymbol("AVP_Cleanup");

			AVP_Cleanup();
			if (JNETErrSuccess == JNetCleanup())
				return Utility::success;
			return  -1;
		}

		int  __stdcall Utility::JRecDownload(long lHandle, LPBYTE pBuff, DWORD dwRevLen, void* pUserParam)
		{
			poco_assert(avplayer.isLoaded());
			poco_assert(avplayer.hasSymbol("AVP_WriteRecFile"));
			PAVP_WriteRecFile AVP_WriteRecFile = (PAVP_WriteRecFile)avplayer.getSymbol("AVP_WriteRecFile");

			DownloadInfo *pDlg = (DownloadInfo *)pUserParam;
			while (pBuff)
			{
				DownloadInfo *pDlg = (DownloadInfo *)pUserParam;

				j_frame_t *pFrame = (j_frame_t *)pBuff;

				if (pDlg->mDownloadBeginTime == -1)
				{
					pDlg->mDownloadBeginTime = pFrame->timestamp_sec;
				}

				AVP_WriteRecFile(pDlg->mDownloadHandle, pBuff, dwRevLen, NULL, 0);
			}
			return success;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
		{
			
			return success;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
		{			
			poco_assert(sl.hasSymbol("JNetRecOpen4Time"));
			PJNetRecOpen4Time JNetRecOpen4Time = (PJNetRecOpen4Time)sl.getSymbol("JNetRecOpen4Time");
			poco_assert(sl.hasSymbol("JNetRecCtrl"));
			PJNetRecCtrl JNetRecCtrl = (PJNetRecCtrl)sl.getSymbol("JNetRecCtrl");
			
			struct tm Tm;
			char startTime[30] = { 0 };
			char endTime[30] = { 0 };
			
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
			strftime(startTime, 80, "%Y%m%d%H%M%S", &Tm);
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
			strftime(endTime, 80, "%Y%m%d%H%M%S", &Tm);
			
			long recHandle = 0;
			DownloadInfo *pInfo = new DownloadInfo();
			long downloadHandle = JNetRecOpen4Time(handle, "", timeinfo.ch, 0, startTime, endTime, 4096, 0, JRecDownload, pInfo, recHandle);
			if (downloadHandle < 0)
			{
				delete pInfo;
				lastError(handle);
				return false;
			}
			
			Sleep(1000);
			JNetRecCtrl(recHandle, JNET_PB_CTRL_START, NULL);
			
				
			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
		{			
			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, int& Channel)
		{			
			poco_assert(sl.hasSymbol("JNetRecOpen4Time"));
			PJNetRecOpen4Time JNetRecOpen4Time = (PJNetRecOpen4Time)sl.getSymbol("JNetRecOpen4Time");
			poco_assert(sl.hasSymbol("JNetRecCtrl"));
			PJNetRecCtrl JNetRecCtrl = (PJNetRecCtrl)sl.getSymbol("JNetRecCtrl");

			poco_assert(avplayer.hasSymbol("AVP_GetFreePort"));
			PAVP_GetFreePort AVP_GetFreePort = (PAVP_GetFreePort)avplayer.getSymbol("AVP_GetFreePort");
			poco_assert(avplayer.hasSymbol("AVP_SetPlayPriority"));
			PAVP_SetPlayPriority AVP_SetPlayPriority = (PAVP_SetPlayPriority)avplayer.getSymbol("AVP_SetPlayPriority");
			poco_assert(avplayer.hasSymbol("AVP_SetDataProtocol"));
			PAVP_SetDataProtocol AVP_SetDataProtocol = (PAVP_SetDataProtocol)avplayer.getSymbol("AVP_SetDataProtocol");
			poco_assert(avplayer.hasSymbol("AVP_AddPlayWnd"));
			PAVP_AddPlayWnd AVP_AddPlayWnd = (PAVP_AddPlayWnd)avplayer.getSymbol("AVP_AddPlayWnd");
			poco_assert(avplayer.hasSymbol("AVP_Play"));
			PAVP_Play AVP_Play = (PAVP_Play)avplayer.getSymbol("AVP_Play");
			poco_assert(avplayer.hasSymbol("AVP_SetCoder"));
			PAVP_SetCoder AVP_SetCoder = (PAVP_SetCoder)avplayer.getSymbol("AVP_SetCoder");

			struct tm Tm;
			char startTime[30] = { 0 };
			char endTime[30] = { 0 };

			_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
			strftime(startTime, 80, "%Y%m%d%H%M%S", &Tm);
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
			strftime(endTime, 80, "%Y%m%d%H%M%S", &Tm);

			Channel = AVP_GetFreePort();
			if (Channel < 0)
			{
				return false;
			}

			long recHandle = 0;
			DownloadInfo *pInfo = new DownloadInfo();
			long downloadHandle = JNetRecOpen4Time(handle, "", timeinfo.ch, 0, startTime, endTime, 4096, 0, JRecStream, pInfo, recHandle);
			if (downloadHandle < 0)
			{
				delete pInfo;
				lastError(handle);
				return false;
			}

			Sleep(1000);
			JNetRecCtrl(recHandle, JNET_PB_CTRL_START, NULL);
			AVP_SetPlayPriority(Channel, AVPPlaySmooth);
			AVP_SetDataProtocol(Channel, AVP_PROTOCOL_JPF);
			int iRet = AVP_SetCoder(Channel, AVP_CODER_JXJ);
			if (iRet != AVPErrSuccess)
			{								
				return false;
			}

			AVP_AddPlayWnd(Channel, NULL, timeinfo.hwnd, NULL, NULL);
			AVP_Play(Channel);

			return Channel;
		}


		int Utility::FindFile(Utility::HANDLE handle, const Utility::TIMEINFO timeinfo, std::size_t timeout)
		{
			int count = 0;
			std::cout << "find file" << std::endl;
			poco_assert(sl.hasSymbol("JNetGetParam"));
			PJNetGetParam JNetGetParam = (PJNetGetParam)sl.getSymbol("JNetGetParam");

					
			tm STime;
			tm ETime;
			_localtime64_s(&STime, (const time_t*)&timeinfo.stBeginTime);
			_localtime64_s(&ETime, (const time_t*)&timeinfo.stEndTime);

			JStoreLog info = { 0 };
			TMToNetTime(STime, info.beg_time);
			TMToNetTime(ETime, info.end_time);

			info.rec_type = ALL_RECODE;
			info.beg_node = 0;
			info.end_node = J_SDK_MAX_STORE_LOG_SIZE - 1;
			info.sess_id = -1;
			bool beg = true;

			while (beg || info.beg_node < info.total_count)
			{
				beg = false;
				LONG lfind = JNetGetParam(handle, timeinfo.ch, PARAM_STORE_LOG, &info, sizeof(JStoreLog), NULL, NULL);
				if (lfind != JNETErrSuccess)
				{
					lastError(lfind);
					return -1;
				}

				for (int i = 0; i < info.node_count; i++)
				{
					//Store& s = storeLog.store[i];
					count++;
				}
				info.beg_node += J_SDK_MAX_STORE_LOG_SIZE;
				info.end_node += J_SDK_MAX_STORE_LOG_SIZE;
				if (info.end_node >= info.total_count)
				{
					info.end_node = info.total_count - 1;
				}

			}
			
			
			std::cout << "find file count: " << count << std::endl;

			////////////////////////////test download
			////////////download by file
			//Utility::FILEINFO fileinfo = { 0 };			
			//strncpy(fileinfo.sFileName, nriFileinfo->sFileName, strlen(nriFileinfo->sFileName));
			//fileinfo.size = nriFileinfo->dwFileSize;

			//std::cout << "download file size: " << fileinfo.size << std::endl;

			//std::string strfilpath = "D:\\DownLoadVideo\\1.mp4";		 

			//GetFile(handle, fileinfo, strfilpath);
			//Sleep(90000);		
			//////////////////////download by time 
			//Utility::TIMEINFO info1 = { 0 };
			//info1.ch = fileinfo[0].ch;
			//strncpy(info1.sFileName, fileinfo[0].filename, strlen(fileinfo[0].filename));
			//info1.size = fileinfo[0].size;
			//tm STime1;
			//tm ETime1;
			//timeDHToStd(&fileinfo[0].starttime, &STime1);
			//info1.stBeginTime = _mktime64(&STime1);
			//timeDHToStd(&fileinfo[0].endtime, &ETime1);
			//info1.stEndTime = _mktime64(&ETime1);			

			//std::cout << "download file size: " << info1.size << std::endl;
			//std::string strfilpath = "D:\\DownLoadVideo\\2.mp4";
			//GetFile(handle, info1, strfilpath, false);
			//Sleep(90000);
			////////////////////////////////////
			return count;			
		}

		
		

		int Utility::stopPlayback(long lPlayHandle, int Channel)
		{
			poco_assert(avplayer.hasSymbol("AVP_Stop"));
			PAVP_Stop AVP_Stop = (PAVP_Stop)avplayer.getSymbol("AVP_Stop");
			poco_assert(avplayer.hasSymbol("AVP_ReleasePort"));
			PAVP_ReleasePort AVP_ReleasePort = (PAVP_ReleasePort)avplayer.getSymbol("AVP_ReleasePort");
			poco_assert(sl.hasSymbol("JNetRecClose"));
			PJNetRecClose JNetRecClose = (PJNetRecClose)sl.getSymbol("JNetRecClose");

			AVP_Stop(Channel);
			AVP_ReleasePort(Channel);
				
			return JNetRecClose(lPlayHandle);
		}

		int Utility::setPlaybackPos(__int64 playbackHandle, int Channel, __int32 pos)
		{
			poco_assert(avplayer.hasSymbol("AVP_Seek"));
			PAVP_Seek AVP_Seek = (PAVP_Seek)avplayer.getSymbol("AVP_Seek");
			poco_assert(sl.hasSymbol("JNetRecCtrl"));
			PJNetRecCtrl JNetRecCtrl = (PJNetRecCtrl)sl.getSymbol("JNetRecCtrl");

			AVP_Seek(Channel, pos);

			return JNetRecCtrl(playbackHandle, JNET_PB_CTRL_SET_TIME, (void *)pos);
			
		}

		int Utility::getPlaybackPos(__int64 playbackHandle, __int32 *pos)
		{						
			return 0;
		}

		int Utility::getDownloadPos(__int64 downloadHandle)
		{			
			return 0;
		}

		int Utility::pausePlayback(long lPlayHandle, BOOL bPause)
		{
			return success;
		}
		
		int Utility::JRecStream(long lHandle, LPBYTE pBuff, DWORD dwRevLen, void* pUserParam)
		{
			TIMEINFO *pDlg = (TIMEINFO *)pUserParam;
			poco_assert(avplayer.hasSymbol("AVP_PutFrame"));
			PAVP_PutFrame AVP_PutFrame = (PAVP_PutFrame)avplayer.getSymbol("AVP_PutFrame");

			j_frame_t *pFrame = (j_frame_t *)pBuff;			
			
			return AVP_PutFrame(pDlg->ch, pBuff);
		}

		int Utility::stopDownload(long lPlayHandle, int Channel)
		{
			poco_assert(avplayer.hasSymbol("AVP_CloseRecFile"));
			PAVP_CloseRecFile AVP_CloseRecFile = (PAVP_CloseRecFile)avplayer.getSymbol("AVP_CloseRecFile");
			poco_assert(sl.hasSymbol("JNetRecCtrl"));
			PJNetRecCtrl JNetRecCtrl = (PJNetRecCtrl)sl.getSymbol("JNetRecCtrl");
			poco_assert(sl.hasSymbol("JNetRecClose"));
			PJNetRecClose JNetRecClose = (PJNetRecClose)sl.getSymbol("JNetRecClose");

			JNetRecCtrl(lPlayHandle, JNET_PB_CTRL_STOP, NULL);
			AVP_CloseRecFile(Channel);


			return JNetRecClose(lPlayHandle);
		}

	}
}