#include "JXJ/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>
#include <memory>
#include "j_sdk.h"


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
}


extern Poco::SharedLibrary sl;



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

			JDeviceInfo deviceinfo = { 0 };
			ret = JNetGetParam(handle, 0, PARAM_DEVICE_INFO, (char *)&deviceinfo, sizeof(deviceinfo), NULL, NULL);
			if (ret != JNETErrSuccess)
			{
				std::cout << "get channel error:" << lastError(ret) << std::endl;
				return -1;
			}
			info.nTotalChannel = deviceinfo.channel_num;

			std::cout << "login handle: " << handle << " channel: " << info.nTotalChannel << std::endl;			

			return ret;
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
			return JNetInit(NULL);			
		}

		int Utility::CleanUp()
		{			
			std::cout << "CleanUp" << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("JNetCleanup"));
			PJNetCleanup JNetCleanup = (PJNetCleanup)sl.getSymbol("JNetCleanup");
			return JNetCleanup();
		}

		

		int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
		{
			/*poco_assert(sl.hasSymbol("NET_DVR_GetFileByName"));
			PNET_DVR_GetFileByName NET_DVR_GetFileByName = (PNET_DVR_GetFileByName)sl.getSymbol("NET_DVR_GetFileByName");

			long downloadHandle = NET_DVR_GetFileByName(handle, (char *)fileinfo.sFileName, (char *)path.c_str());
			std::cout << "download ret: " << downloadHandle << std::endl;
			if (downloadHandle < 0)
			{
				lastError(handle);
				return false;
			}		
			
			if (!setPlayBackControl(downloadHandle, NET_DVR_PLAYSTART, 0, 0))
			{
				lastError(handle);
				return false;
			}*/

			return success;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
		{			
			/*poco_assert(sl.hasSymbol("NET_DVR_GetFileByTime_V40"));
			PNET_DVR_GetFileByTime_V40 NET_DVR_GetFileByTime_V40 = (PNET_DVR_GetFileByTime_V40)sl.getSymbol("NET_DVR_GetFileByTime_V40");


			NET_DVR_PLAYCOND struDownloadCond = { 0 };
			struct tm Tm;
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
			TMToNetTime(Tm, struDownloadCond.struStartTime);
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
			TMToNetTime(Tm, struDownloadCond.struStopTime);
			
			long downloadHandle = NET_DVR_GetFileByTime_V40(handle, (char *)path.c_str(), &struDownloadCond);

			if (downloadHandle < 0)
			{
				lastError(handle);
				return false;
			}

			if (!setPlayBackControl(downloadHandle, NET_DVR_PLAYSTART, 0, 0))
			{
				lastError(handle);
				return false;
			}*/
				
			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
		{			
			/*poco_assert(sl.hasSymbol("NET_DVR_PlayBackByName"));
			PNET_DVR_PlayBackByName NET_DVR_PlayBackByName = (PNET_DVR_PlayBackByName)sl.getSymbol("NET_DVR_PlayBackByName");			

			long playHandle = NET_DVR_PlayBackByName(handle, (char *)fileinfo.sFileName, fileinfo.hwnd);	
			if (playHandle < 0)
			{
				lastError(handle);
				return false;
			}
			if (!setPlayBackControl(playHandle, NET_DVR_PLAYSTART, 0, 0))
			{
				lastError(handle);
				return false;
			}*/

			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo)
		{
			/*poco_assert(sl.hasSymbol("NET_DVR_PlayBackByTime_V40"));
			PNET_DVR_PlayBackByTime_V40 NET_DVR_PlayBackByTime_V40 = (PNET_DVR_PlayBackByTime_V40)sl.getSymbol("NET_DVR_PlayBackByTime_V40");

			NET_DVR_VOD_PARA struVodPara = { 0 };			
			struVodPara.dwSize = sizeof(struVodPara);
			struVodPara.struIDInfo.dwChannel = timeinfo.ch;
			struVodPara.hWnd = timeinfo.hwnd;

			struct tm Tm;
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
			TMToNetTime(Tm, struVodPara.struBeginTime);

			_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
			TMToNetTime(Tm, struVodPara.struEndTime);

			long playHandle = NET_DVR_PlayBackByTime_V40(handle, &struVodPara);
			if (playHandle < 0)
			{
				lastError(handle);				
				return false;
			}
			if (!setPlayBackControl(playHandle, NET_DVR_PLAYSTART, 0, 0))
			{
				lastError(handle);
				return false;
			}*/

			return success;
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

			
			LONG lfind = JNetGetParam(handle, timeinfo.ch, PARAM_STORE_LOG, &info, sizeof(JStoreLog), NULL, NULL);
			if (lfind != JNETErrSuccess)
			{
				lastError(lfind);
				return -1;
			}			
			
			std::cout << "find file count: " << count << std::endl;

			////////////////////////////test download
			//////////download by file
			/*Utility::FILEINFO fileinfo = { 0 };			
			strncpy(fileinfo.sFileName, nriFileinfo->sFileName, strlen(nriFileinfo->sFileName));
			fileinfo.size = nriFileinfo->dwFileSize;

			std::cout << "download file size: " << fileinfo.size << std::endl;

			std::string strfilpath = "D:\\DownLoadVideo\\1.mp4";		 

			GetFile(handle, fileinfo, strfilpath);
			Sleep(90000);		*/
			//////////////////download by time 
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
			//////////////////////////////////
			return count;			
		}

		void Utility::CallbackFn(long lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, long dwUser)
		{
			
		}
		

		int Utility::DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode)
		{
			return 0;
		}

		int Utility::stopPlayback(long lPlayHandle)
		{
		/*	poco_assert(sl.hasSymbol("NET_DVR_StopPlayBack"));
			PNET_DVR_StopPlayBack NET_DVR_StopPlayBack = (PNET_DVR_StopPlayBack)sl.getSymbol("NET_DVR_StopPlayBack");

			return  NET_DVR_StopPlayBack(lPlayHandle);	*/		
			return 0;
		}

		int Utility::setPlaybackPos(__int64 playbackHandle, __int64 filesize, __int32 pos)
		{
			//return setPlayBackControl(playbackHandle, NET_DVR_PLAYSETPOS, pos, 0);		
			return 0;
		}

		int Utility::getPlaybackPos(__int64 playbackHandle, __int32 *pos)
		{			
			//return setPlayBackControl(playbackHandle, NET_DVR_PLAYGETPOS, 0, pos);
			return 0;
		}

		int Utility::getDownloadPos(__int64 downloadHandle)
		{
			/*poco_assert(sl.hasSymbol("NET_DVR_GetDownloadPos"));
			PNET_DVR_GetDownloadPos  NET_DVR_GetDownloadPos = (PNET_DVR_GetDownloadPos)sl.getSymbol("NET_DVR_GetDownloadPos");
			
			return NET_DVR_GetDownloadPos(downloadHandle);*/
			return 0;
		}

		int Utility::pausePlayback(long lPlayHandle, BOOL bPause)
		{
			/*setPlayBackControl(lPlayHandle, NET_DVR_PLAYPAUSE, 0, 0);*/
			return success;
		}

		int Utility::setPlayBackControl(Utility::DOWNLOAD_HANDLE handle, int Opcode, __int32 in, __int32* out)
		{
			/*poco_assert(sl.hasSymbol("NET_DVR_PlayBackControl_V40"));
			PNET_DVR_PlayBackControl_V40 NET_DVR_PlayBackControl_V40 = (PNET_DVR_PlayBackControl_V40)sl.getSymbol("NET_DVR_PlayBackControl_V40");

			return NET_DVR_PlayBackControl_V40(handle, Opcode, &in, 0, out, NULL);*/
			return 0;
		}

	}
}