#include "DH/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>



extern "C"
{
	typedef BOOL (CALL_METHOD *PCLIENT_Init)(fDisConnect cbDisConnect, LDWORD dwUser);
	typedef void (CALL_METHOD *PCLIENT_Cleanup)();

	typedef LLONG (CALL_METHOD *PCLIENT_Login)(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error);
	typedef BOOL (CALL_METHOD *PCLIENT_Logout)(LLONG lLoginID);
	typedef BOOL (CALL_METHOD *PCLIENT_QueryDevState)(LLONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime);
	typedef void (CALL_METHOD *PCLIENT_SetConnectTime)(int nWaitTime, int nTryTimes);


	typedef BOOL (CALL_METHOD *PCLIENT_QueryRecordFile)(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, 
		char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime, BOOL bTime);

	typedef LLONG (CALL_METHOD *PCLIENT_DownloadByRecordFile)(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);
	typedef LLONG (CALL_METHOD *PCLIENT_DownloadByTime)(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, fTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData);
	typedef BOOL (CALL_METHOD *PCLIENT_GetDownloadPos)(LLONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

	typedef LLONG (CALL_METHOD *PCLIENT_PlayBackByRecordFile)(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);
	typedef BOOL (CALL_METHOD *PCLIENT_StopPlayBack)(LLONG lPlayHandle);
	typedef BOOL (CALL_METHOD *PCLIENT_PausePlayBack)(LLONG lPlayHandle, BOOL bPause);
	typedef BOOL (CALL_METHOD *PCLIENT_SeekPlayBack)(LLONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

	typedef DWORD (CALL_METHOD *PCLIENT_GetLastError)(void);
	
}


extern Poco::SharedLibrary sl;



namespace DVR {
	namespace DHLite {



		Utility::Utility()
		{

		}


		Utility::~Utility()
		{
		}

		std::string Utility::lastError(Utility::HANDLE handle)
		{
			poco_assert(sl.hasSymbol("CLIENT_GetLastError"));
			PCLIENT_GetLastError CLIENT_GetLastError = (PCLIENT_GetLastError)sl.getSymbol("CLIENT_GetLastError");

			std::string strError;
			DWORD dwError = CLIENT_GetLastError();
			switch (dwError)
			{	
			case NET_NOERROR:							strError = "No error";
				break;
			case NET_ERROR:								strError = "Unknown error";
				break;
			case NET_SYSTEM_ERROR:						strError = "Windows system error";
				break;
			case NET_NETWORK_ERROR:						strError = "Network error, probably because of network-time-out";
				break;
			case NET_DEV_VER_NOMATCH:					strError = "No match protocol";
				break;
			case NET_INVALID_HANDLE:					strError = "Invalid handle";
				break;
			case NET_OPEN_CHANNEL_ERROR:				strError = "Failed to open channel";
				break;
			case NET_CLOSE_CHANNEL_ERROR:				strError = "Failed to close channel";
				break;
			case NET_ILLEGAL_PARAM:						strError = "Illegal parameter";
				break;
			case NET_SDK_INIT_ERROR:					strError = "Failed to initialize SDK";
				break;
			case NET_SDK_UNINIT_ERROR:					strError = "Failed to uninitialize SDK";
				break;
			case NET_RENDER_OPEN_ERROR:					strError = "Unknown error";
				break;
			case NET_DEC_OPEN_ERROR:					strError = "Unknown error";
				break;
			case NET_DEC_CLOSE_ERROR:					strError = "Unknown error";
				break;
			case NET_MULTIPLAY_NOCHANNEL:				strError = "Unknown error";
				break;
			case NET_TALK_INIT_ERROR:					strError = "Unknown error";
				break;
			case NET_TALK_NOT_INIT:						strError = "Unknown error";
				break;
			case NET_TALK_SENDDATA_ERROR:				strError = "Unknown error";
				break;
			case NET_NO_TALK_CHANNEL:					strError = "Unknown error";
				break;
			case NET_NO_AUDIO:							strError = "Unknown error";
				break;
			case NET_REAL_ALREADY_SAVING:				strError = "Unknown error";
				break;
			case NET_NOT_SAVING:						strError = "Unknown error";
				break;
			case NET_OPEN_FILE_ERROR:					strError = "Unknown error";
				break;
			case NET_PTZ_SET_TIMER_ERROR:				strError = "Unknown error";
				break;
			case NET_RETURN_DATA_ERROR:					strError = "Unknown error";
				break;
			case NET_INSUFFICIENT_BUFFER:				strError = "Unknown error";
				break;
			case NET_NOT_SUPPORTED:						strError = "Unknown error";
				break;
			case NET_NO_RECORD_FOUND:					strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_PASSWORD:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_USER:					strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_TIMEOUT:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_RELOGGIN:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_LOCKED:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_BLACKLIST:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_BUSY:					strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_CONNECT:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_NETWORK:				strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_MAXCONNECT:			strError = "Unknown error";
				break;
			case NET_LOGIN_ERROR_PROTOCOL3_ONLY:		strError = "Unknown error";
				break;
			case NET_RENDER_SOUND_ON_ERROR:				strError = "Unknown error";
				break;
			case NET_RENDER_SOUND_OFF_ERROR:			strError = "Unknown error";
				break;
			case NET_RENDER_SET_VOLUME_ERROR:			strError = "Unknown error";
				break;
			case NET_RENDER_ADJUST_ERROR:				strError = "Unknown error";
				break;
			case NET_RENDER_PAUSE_ERROR:				strError = "Unknown error";
				break;
			case NET_RENDER_SNAP_ERROR:					strError = "Unknown error";
				break;
			case NET_RENDER_STEP_ERROR:					strError = "Unknown error";
				break;
			case NET_RENDER_FRAMERATE_ERROR:			strError = "Unknown error";
				break;
			case NET_CONFIG_DEVBUSY:					strError = "Unknown error";
				break;
			case NET_CONFIG_DATAILLEGAL:				strError = "Unknown error";
				break;
			case NET_NO_INIT:							strError = "Unknown error";
				break;
			case NET_DOWNLOAD_END:						strError = "Unknown error";
				break;
			default:									strError = "Unknown error";
			
			}
			return strError;			
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

		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& _addr,
			const std::string& user,
			const std::string& password,
			DVRINFO& info)
		{
			Utility::HANDLE handle = 0;		
						
			NET_DEVICEINFO DevInfo = { 0 };
			int nError = 0;

			poco_assert(sl.hasSymbol("CLIENT_Login"));
			PCLIENT_Login CLIENT_Login = (PCLIENT_Login)sl.getSymbol("CLIENT_Login");
			poco_assert(sl.hasSymbol("CLIENT_QueryDevState"));
			PCLIENT_QueryDevState CLIENT_QueryDevState = (PCLIENT_QueryDevState)sl.getSymbol("CLIENT_QueryDevState");

			sockaddr_in* pSin = (sockaddr_in*)_addr.addr();
			std::cout << "IP:" << inet_ntoa(pSin->sin_addr) << "port:" << _addr.port() << std::endl;
			
			handle = CLIENT_Login(inet_ntoa(pSin->sin_addr), _addr.port(), (char *)user.c_str(), (char *)password.c_str(), &DevInfo, &nError);
			if (handle > 0)
			{
				NET_DEV_CHN_COUNT_INFO stuChn = { sizeof(NET_DEV_CHN_COUNT_INFO) };
				stuChn.stuVideoIn.dwSize = sizeof(stuChn.stuVideoIn);
				stuChn.stuVideoOut.dwSize = sizeof(stuChn.stuVideoOut);
				int nRetLen = 0;
				if (CLIENT_QueryDevState(handle, DH_DEVSTATE_DEV_CHN_COUNT, (char*)&stuChn, stuChn.dwSize, &nRetLen, 1000))
				{
					info.nTotalChannel = stuChn.stuVideoIn.nMaxTotal;
				}
				else
				{
					info.nTotalChannel = DevInfo.byChanNum;
				}
			}
			else
			{
				switch (nError)
				{
				case 1:
					std::cout << "Incorrect Password" << std::endl;
					break;
				case 2:
					std::cout << "User not Exist" << std::endl;
					break;
				case 3:
					std::cout << "Login Timeout" << std::endl;
					break;
				case 4:
					std::cout << "Curent User Has Logined" << std::endl;
					break;
				case 5:
					std::cout << "Curent User Locked" << std::endl;
					break;
				case 6:
					std::cout << "Curent User Invalid" << std::endl;
					break;
				case 7:
					std::cout << "System Busy" << std::endl;
					break;
				case 8:
					std::cout << "Cant find host" << std::endl;
					break;
				case 9:
					std::cout << "Cant find host" << std::endl;
					break;
				case 10:
					std::cout << "Max Conncet" << std::endl;
					break;
				case 11:
					std::cout << "Protocol 3 Only" << std::endl;
					break;
				case 12:
					std::cout << "Protocol 3 Only" << std::endl;
					break;
				case 13:
					std::cout << "UKey Lost" << std::endl;
					break;
				default:
					std::cout << "Network Error" << std::endl;
					break;
				}
			}

			std::cout << "login handle: " << handle << " channel: " << info.nTotalChannel << std::endl;			

			return handle;
		}

		int Utility::logout(Utility::HANDLE handle)
		{			
			poco_assert(sl.hasSymbol("CLIENT_Logout"));
			PCLIENT_Logout CLIENT_Logout = (PCLIENT_Logout)sl.getSymbol("CLIENT_Logout");
			std::cout << "logout handle: " << handle << std::endl;
			return CLIENT_Logout(handle);			
		}

		int Utility::setTimeOut(std::size_t timeout, std::size_t times)
		{			
			poco_assert(sl.hasSymbol("CLIENT_SetConnectTime"));
			PCLIENT_SetConnectTime CLIENT_SetConnectTime = (PCLIENT_SetConnectTime)sl.getSymbol("CLIENT_SetConnectTime");
			CLIENT_SetConnectTime(timeout, times);
			return success;
		}

		int Utility::Init()
		{
			std::cout << "init " << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("CLIENT_Init"));
			PCLIENT_Init CLIENT_Init = (PCLIENT_Init)sl.getSymbol("CLIENT_Init");
			return CLIENT_Init(NULL, NULL);			
		}

		int Utility::CleanUp()
		{			
			std::cout << "CleanUp" << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("CLIENT_Cleanup"));
			PCLIENT_Cleanup CLIENT_Cleanup = (PCLIENT_Cleanup)sl.getSymbol("CLIENT_Cleanup");
			CLIENT_Cleanup();
			return success;
		}

		static void timeStdToDH(tm *pTimeStd, NET_TIME *pTimeDH)
		{
			pTimeDH->dwYear = pTimeStd->tm_year + 1900;
			pTimeDH->dwMonth = pTimeStd->tm_mon + 1;
			pTimeDH->dwDay = pTimeStd->tm_mday;
			pTimeDH->dwHour = pTimeStd->tm_hour;
			pTimeDH->dwMinute = pTimeStd->tm_min;
			pTimeDH->dwSecond = pTimeStd->tm_sec;
		}

		static void timeDHToStd(NET_TIME *pTimeDH, tm *pTimeStd)
		{
			pTimeStd->tm_year = pTimeDH->dwYear - 1900;
			pTimeStd->tm_mon = pTimeDH->dwMonth - 1;
			pTimeStd->tm_mday = pTimeDH->dwDay;
			pTimeStd->tm_hour = pTimeDH->dwHour;
			pTimeStd->tm_min = pTimeDH->dwMinute;
			pTimeStd->tm_sec = pTimeDH->dwSecond;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
		{
			poco_assert(sl.hasSymbol("CLIENT_DownloadByRecordFile"));
			PCLIENT_DownloadByRecordFile CLIENT_DownloadByRecordFile = (PCLIENT_DownloadByRecordFile)sl.getSymbol("CLIENT_DownloadByRecordFile");


			NET_RECORDFILE_INFO info = { 0 };			
			info.ch = fileinfo.ch;
			strncpy(info.filename, (const char *)fileinfo.sFileName, strlen(fileinfo.sFileName));
			info.size = fileinfo.size;
			struct tm Tm;
			_localtime64_s(&Tm, (const time_t*)&fileinfo.stBeginTime);
			timeStdToDH(&Tm, &info.starttime);
			_localtime64_s(&Tm, (const time_t*)&fileinfo.stEndTime);
			timeStdToDH(&Tm, &info.endtime);
			info.driveno = fileinfo.driveno;
			info.startcluster = fileinfo.startcluster;

			long ret = CLIENT_DownloadByRecordFile(handle, &info, (char *)path.c_str(), CallbackFn, NULL);
			std::cout << "download ret: " << ret << std::endl;
			if (ret <= 0)
				return false;
			
			return success;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
		{			
			poco_assert(sl.hasSymbol("CLIENT_DownloadByTime"));
			PCLIENT_DownloadByTime CLIENT_DownloadByTime = (PCLIENT_DownloadByTime)sl.getSymbol("CLIENT_DownloadByTime");


			NET_TIME stime, etime;
			struct tm Tm;
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
			timeStdToDH(&Tm, &stime);
			_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
			timeStdToDH(&Tm, &etime);

			long ret = CLIENT_DownloadByTime(handle, timeinfo.ch - 1, 0, &stime, &etime, (char *)path.c_str(), DownLoadTimePos, 0);

			if (ret <= 0)
				return false;
			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
		{			
			poco_assert(sl.hasSymbol("CLIENT_PlayBackByRecordFile"));
			PCLIENT_PlayBackByRecordFile CLIENT_PlayBackByRecordFile = (PCLIENT_PlayBackByRecordFile)sl.getSymbol("CLIENT_PlayBackByRecordFile");

			NET_RECORDFILE_INFO info = { 0 };
			info.ch = fileinfo.ch;
			strncpy(info.filename, (const char *)fileinfo.sFileName, strlen(fileinfo.sFileName));
			info.size = fileinfo.size;
			struct tm Tm;
			_localtime64_s(&Tm, (const time_t*)&fileinfo.stBeginTime);
			timeStdToDH(&Tm, &info.starttime);
			_localtime64_s(&Tm, (const time_t*)&fileinfo.stEndTime);
			timeStdToDH(&Tm, &info.endtime);

			return CLIENT_PlayBackByRecordFile(handle, &info, fileinfo.hwnd, CallbackFn, NULL);
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo)
		{
			return success;
		}


		int Utility::FindFile(Utility::HANDLE handle, const Utility::TIMEINFO timeinfo, std::size_t timeout)
		{
			int count = 0;
			std::cout << "find file" << std::endl;
			poco_assert(sl.hasSymbol("CLIENT_QueryRecordFile"));
			PCLIENT_QueryRecordFile CLIENT_QueryRecordFile = (PCLIENT_QueryRecordFile)sl.getSymbol("CLIENT_QueryRecordFile");

			NET_TIME stime;
			NET_TIME etime;			
			tm STime;
			tm ETime;
			_localtime64_s(&STime, (const time_t*)&timeinfo.stBeginTime);
			_localtime64_s(&ETime, (const time_t*)&timeinfo.stEndTime);
			timeStdToDH(&STime, &stime);
			timeStdToDH(&ETime, &etime);

			NET_RECORDFILE_INFO fileinfo[2000];
			ZeroMemory(fileinfo, sizeof(fileinfo));
			if (!CLIENT_QueryRecordFile(handle, timeinfo.ch - 1, 0,	&stime,	&etime,	0, fileinfo, sizeof(fileinfo), &count, 5000, true))
			{
				std::cout << "find failer" << std::endl;
				return 0;
			}
			std::cout << "find file count: " << count << std::endl;

			//////////////////////////////test download
			//Utility::FILEINFO info = { 0 };
			//info.ch = fileinfo[0].ch;
			//strncpy(info.sFileName, fileinfo[0].filename, strlen(fileinfo[0].filename));
			//info.size = fileinfo[0].size;
			//tm STime1;
			//tm ETime1;
			//timeDHToStd(&fileinfo[0].starttime, &STime1);
			//info.stBeginTime = _mktime64(&STime1);
			//timeDHToStd(&fileinfo[0].endtime, &ETime1);
			//info.stEndTime = _mktime64(&ETime1);
			//info.driveno = fileinfo[0].driveno;
			//info.startcluster = fileinfo[0].startcluster;

			//std::cout << "download file size: " << info.size << std::endl;

			//std::string strfilpath = "D:\\DownLoadVideo\\1.mp4";
			// 

			//GetFile(handle, info, strfilpath);
			//Sleep(90000);		
			////////////////////////////////
			return count;			
		}

		void Utility::CallbackFn(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser)
		{
			std::cout << "download pos handle: " << lPlayHandle << "  size: " << dwTotalSize << " current size: " << dwDownLoadSize  << std::endl;
		}

		void CALLBACK Utility::DownLoadTimePos(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser)
		{
			
		}

		int Utility::DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode)
		{
			return 0;
		}

		int Utility::stopPlayback(long lPlayHandle)
		{
			poco_assert(sl.hasSymbol("CLIENT_StopPlayBack"));
			PCLIENT_StopPlayBack CLIENT_StopPlayBack = (PCLIENT_StopPlayBack)sl.getSymbol("CLIENT_StopPlayBack");

			return  CLIENT_StopPlayBack(lPlayHandle);
		}

		int Utility::setPlaybackPos(__int64 playbackHandle, __int64 filesize, __int32 pos)
		{
			poco_assert(sl.hasSymbol("CLIENT_SeekPlayBack"));
			PCLIENT_SeekPlayBack CLIENT_SeekPlayBack = (PCLIENT_SeekPlayBack)sl.getSymbol("CLIENT_SeekPlayBack");

			return CLIENT_SeekPlayBack(playbackHandle, 0xFFFFFFFF, pos * filesize / 100);
		}

		/*int Utility::getPlaybackPos(__int64 playbackHandle, __int32 *pos)
		{			
			return 1;
		}*/

		int Utility::getDownloadPos(__int64 downloadHandle)
		{
			poco_assert(sl.hasSymbol("CLIENT_GetDownloadPos"));
			PCLIENT_GetDownloadPos  CLIENT_GetDownloadPos = (PCLIENT_GetDownloadPos)sl.getSymbol("CLIENT_GetDownloadPos");

			int total = 0, cur = 0;	
			int pos = 0;
			if (CLIENT_GetDownloadPos(downloadHandle, &total, &cur))
			{
				pos = cur / total *100;
			}
			return pos;
		}

		int Utility::pausePlayback(long lPlayHandle, BOOL bPause)
		{
			poco_assert(sl.hasSymbol("CLIENT_PausePlayBack"));
			PCLIENT_PausePlayBack CLIENT_PausePlayBack = (PCLIENT_PausePlayBack)sl.getSymbol("CLIENT_PausePlayBack");

			return  CLIENT_PausePlayBack(lPlayHandle, bPause);
		}

	}
}