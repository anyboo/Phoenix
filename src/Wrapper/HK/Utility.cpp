#include "HK/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>
#include <memory>



extern "C"
{
	typedef BOOL (__stdcall *PNET_DVR_Init)();
	typedef BOOL (__stdcall *PNET_DVR_Cleanup)();

	typedef LONG (__stdcall *PNET_DVR_Login_V30)(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
	typedef BOOL (__stdcall *PNET_DVR_Logout)(LONG lUserID);
	typedef BOOL (__stdcall *PNET_DVR_GetDVRConfig)(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
	typedef BOOL (__stdcall *PNET_DVR_SetConnectTime)(DWORD dwWaitTime, DWORD dwTryTimes);

	typedef LONG (__stdcall *PNET_DVR_FindFile_V40)(LONG lUserID, LPNET_DVR_FILECOND_V40 pFindCond);
	typedef LONG (__stdcall *PNET_DVR_FindNextFile_V40)(LONG lFindHandle, LPNET_DVR_FINDDATA_V40 lpFindData);
	typedef BOOL (__stdcall *PNET_DVR_FindClose_V30)(LONG lFindHandle);

	typedef LONG (__stdcall *PNET_DVR_GetFileByName)(LONG lUserID, char *sDVRFileName, char *sSavedFileName);
	typedef LONG (__stdcall *PNET_DVR_GetFileByTime_V40)(LONG lUserID, char *sSavedFileName, LPNET_DVR_PLAYCOND  pDownloadCond);
	typedef BOOL (__stdcall *PNET_DVR_PlayBackControl_V40)(LONG lPlayHandle, DWORD dwControlCode, LPVOID lpInBuffer, DWORD dwInLen, LPVOID lpOutBuffer, DWORD *lpOutLen);

	typedef LONG (__stdcall *PNET_DVR_PlayBackByName)(LONG lUserID, char *sPlayBackFileName, HWND hWnd);
	typedef LONG (__stdcall *PNET_DVR_PlayBackByTime_V40)(LONG lUserID, NET_DVR_VOD_PARA const* pVodPara);
	typedef BOOL (__stdcall *PNET_DVR_StopPlayBack)(LONG lPlayHandle);
	typedef int (__stdcall *PNET_DVR_GetDownloadPos)(LONG lFileHandle);

	typedef char* (__stdcall *PNET_DVR_GetErrorMsg)(LONG *pErrorNo);
	
}


extern Poco::SharedLibrary sl;



namespace DVR {
	namespace HKLite {



		Utility::Utility()
		{

		}


		Utility::~Utility()
		{
		}

		std::string Utility::lastError(Utility::HANDLE handle)
		{
			poco_assert(sl.hasSymbol("NET_DVR_GetErrorMsg"));
			PNET_DVR_GetErrorMsg NET_DVR_GetErrorMsg = (PNET_DVR_GetErrorMsg)sl.getSymbol("NET_DVR_GetErrorMsg");

			long error = 0;
			std::string strError = NET_DVR_GetErrorMsg(&error);		
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

		void NetTimeToTM(const NET_DVR_TIME& nt, tm& t)
		{
			t.tm_year = nt.dwYear - 1900;
			t.tm_mon = nt.dwMonth - 1;
			t.tm_mday = nt.dwDay;
			t.tm_hour = nt.dwHour;
			t.tm_min = nt.dwMinute;
			t.tm_sec = nt.dwSecond;
		}
		void TMToNetTime(const tm& t, NET_DVR_TIME& nt)
		{
			nt.dwYear = t.tm_year + 1900;
			nt.dwMonth = t.tm_mon + 1;
			nt.dwDay = t.tm_mday;
			nt.dwHour = t.tm_hour;
			nt.dwMinute = t.tm_min;
			nt.dwSecond = t.tm_sec;
		}

		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& _addr,
			const std::string& user,
			const std::string& password,
			DVRINFO& info)
		{
			Utility::HANDLE handle = 0;		
						
			NET_DVR_DEVICEINFO_V30 DevInfo = { 0 };
			int nError = 0;

			poco_assert(sl.hasSymbol("NET_DVR_Login_V30"));
			PNET_DVR_Login_V30 NET_DVR_Login_V30 = (PNET_DVR_Login_V30)sl.getSymbol("NET_DVR_Login_V30");
			poco_assert(sl.hasSymbol("NET_DVR_GetDVRConfig"));
			PNET_DVR_GetDVRConfig NET_DVR_GetDVRConfig = (PNET_DVR_GetDVRConfig)sl.getSymbol("NET_DVR_GetDVRConfig");

			sockaddr_in* pSin = (sockaddr_in*)_addr.addr();
			std::cout << "IP:" << inet_ntoa(pSin->sin_addr) << "port:" << _addr.port() << std::endl;
			
			handle = NET_DVR_Login_V30(inet_ntoa(pSin->sin_addr), _addr.port(), (char *)user.c_str(), (char *)password.c_str(), &DevInfo);
			if (handle == -1)
			{
				std::cout << "login error:" << lastError(handle) << std::endl;
				return 0;
			}
		
			NET_DVR_PICCFG_V40 channelInfo = { 0 };
			DWORD nRetLen = 0;
			for (int i = 0; i < DevInfo.byChanNum; i++)
			{
				if (NET_DVR_GetDVRConfig(handle, NET_DVR_GET_PICCFG_V40, DevInfo.byStartChan + i, &channelInfo, sizeof(NET_DVR_PICCFG_V40), &nRetLen) != FALSE)
				{
					info.channels[DevInfo.byStartChan + i] = std::string((char *)channelInfo.sChanName);
				}
				else
				{
					info.channels[DevInfo.byStartChan + i];
				}
			}
			for (int i = 0; i < DevInfo.byIPChanNum + 255 * DevInfo.byHighDChanNum; i++)
			{
				if (NET_DVR_GetDVRConfig(handle, NET_DVR_GET_PICCFG_V40, DevInfo.byStartDChan + i, &channelInfo, sizeof(NET_DVR_PICCFG_V40), &nRetLen) != FALSE)
				{
					info.channels[DevInfo.byStartDChan + i] = std::string((char *)channelInfo.sChanName);
				}
				else
				{
					info.channels[DevInfo.byStartDChan + i];
				}
			}	
			info.nTotalChannel = DevInfo.byChanNum + DevInfo.byIPChanNum + 255 * DevInfo.byHighDChanNum;

			std::cout << "login handle: " << handle << " channel: " << info.nTotalChannel << std::endl;			

			return handle;
		}

		int Utility::logout(Utility::HANDLE handle)
		{			
			poco_assert(sl.hasSymbol("NET_DVR_Logout"));
			PNET_DVR_Logout NET_DVR_Logout = (PNET_DVR_Logout)sl.getSymbol("NET_DVR_Logout");
			std::cout << "logout handle: " << handle << std::endl;
			return NET_DVR_Logout(handle);			
		}

		int Utility::setTimeOut(std::size_t timeout, std::size_t times)
		{			
			poco_assert(sl.hasSymbol("NET_DVR_SetConnectTime"));
			PNET_DVR_SetConnectTime NET_DVR_SetConnectTime = (PNET_DVR_SetConnectTime)sl.getSymbol("NET_DVR_SetConnectTime");
			return NET_DVR_SetConnectTime(timeout, times);			
		}

		int Utility::Init()
		{
			std::cout << "init " << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("NET_DVR_Init"));
			PNET_DVR_Init NET_DVR_Init = (PNET_DVR_Init)sl.getSymbol("NET_DVR_Init");
			return NET_DVR_Init();			
		}

		int Utility::CleanUp()
		{			
			std::cout << "CleanUp" << std::endl;
			poco_assert(sl.isLoaded());
			poco_assert(sl.hasSymbol("NET_DVR_Cleanup"));
			PNET_DVR_Cleanup NET_DVR_Cleanup = (PNET_DVR_Cleanup)sl.getSymbol("NET_DVR_Cleanup");
			return NET_DVR_Cleanup();			
		}

		

		int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
		{
			poco_assert(sl.hasSymbol("NET_DVR_GetFileByName"));
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
			}

			return success;
		}

		int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
		{			
			poco_assert(sl.hasSymbol("NET_DVR_GetFileByTime_V40"));
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
			}
				
			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
		{			
			poco_assert(sl.hasSymbol("NET_DVR_PlayBackByName"));
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
			}

			return success;
		}

		int Utility::Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo)
		{
			poco_assert(sl.hasSymbol("NET_DVR_PlayBackByTime_V40"));
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
			}

			return success;
		}


		int Utility::FindFile(Utility::HANDLE handle, const Utility::TIMEINFO timeinfo, std::size_t timeout)
		{
			int count = 0;
			std::cout << "find file" << std::endl;
			poco_assert(sl.hasSymbol("NET_DVR_FindFile_V40"));
			PNET_DVR_FindFile_V40 NET_DVR_FindFile_V40 = (PNET_DVR_FindFile_V40)sl.getSymbol("NET_DVR_FindFile_V40");
			poco_assert(sl.hasSymbol("NET_DVR_FindNextFile_V40"));
			PNET_DVR_FindNextFile_V40 NET_DVR_FindNextFile_V40 = (PNET_DVR_FindNextFile_V40)sl.getSymbol("NET_DVR_FindNextFile_V40");
			poco_assert(sl.hasSymbol("NET_DVR_FindClose_V30"));
			PNET_DVR_FindClose_V30 NET_DVR_FindClose_V30 = (PNET_DVR_FindClose_V30)sl.getSymbol("NET_DVR_FindClose_V30");

					
			tm STime;
			tm ETime;
			_localtime64_s(&STime, (const time_t*)&timeinfo.stBeginTime);
			_localtime64_s(&ETime, (const time_t*)&timeinfo.stEndTime);

			NET_DVR_FILECOND_V40 info = { 0 };
			TMToNetTime(STime, info.struStartTime);
			TMToNetTime(ETime, info.struStopTime);

			info.dwFileType = 0xff;
			info.dwIsLocked = 0xff;
			info.dwUseCardNo = 0;
			info.lChannel = timeinfo.ch;
			info.sCardNumber[0] = 0;

			
			LONG lfind = NET_DVR_FindFile_V40(handle, &info);
			if (lfind == -1)
			{
				lastError(handle);
				return -1;
			}

			std::shared_ptr<NET_DVR_FINDDATA_V40> nriFileinfo(new NET_DVR_FINDDATA_V40());
			LONG re = NET_DVR_FindNextFile_V40(lfind, nriFileinfo.get());	
			
			while (re == NET_DVR_ISFINDING || re == NET_DVR_FILE_SUCCESS)
			{
				if (re == NET_DVR_FILE_SUCCESS && nriFileinfo->dwFileSize > 0)
				{					
					count++;
				}
				else
				{
					::Sleep(5);
				}

				re = NET_DVR_FindNextFile_V40(lfind, nriFileinfo.get());
			}
			
			
			std::cout << "find file count: " << count << std::endl;

			////////////////////////////test download
			//////////download by file
			Utility::FILEINFO fileinfo = { 0 };			
			strncpy(fileinfo.sFileName, nriFileinfo->sFileName, strlen(nriFileinfo->sFileName));
			fileinfo.size = nriFileinfo->dwFileSize;

			std::cout << "download file size: " << fileinfo.size << std::endl;

			std::string strfilpath = "D:\\DownLoadVideo\\1.mp4";		 

			GetFile(handle, fileinfo, strfilpath);
			Sleep(90000);		
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
			poco_assert(sl.hasSymbol("NET_DVR_StopPlayBack"));
			PNET_DVR_StopPlayBack NET_DVR_StopPlayBack = (PNET_DVR_StopPlayBack)sl.getSymbol("NET_DVR_StopPlayBack");

			return  NET_DVR_StopPlayBack(lPlayHandle);			
		}

		int Utility::setPlaybackPos(__int64 playbackHandle, __int64 filesize, __int32 pos)
		{
			return setPlayBackControl(playbackHandle, NET_DVR_PLAYSETPOS, pos, 0);			
		}

		int Utility::getPlaybackPos(__int64 playbackHandle, __int32 *pos)
		{			
			return setPlayBackControl(playbackHandle, NET_DVR_PLAYGETPOS, 0, pos);
		}

		int Utility::getDownloadPos(__int64 downloadHandle)
		{
			poco_assert(sl.hasSymbol("NET_DVR_GetDownloadPos"));
			PNET_DVR_GetDownloadPos  NET_DVR_GetDownloadPos = (PNET_DVR_GetDownloadPos)sl.getSymbol("NET_DVR_GetDownloadPos");
			
			return NET_DVR_GetDownloadPos(downloadHandle);
		}

		int Utility::pausePlayback(long lPlayHandle, BOOL bPause)
		{
			setPlayBackControl(lPlayHandle, NET_DVR_PLAYPAUSE, 0, 0);
			return success;
		}

		int Utility::setPlayBackControl(Utility::DOWNLOAD_HANDLE handle, int Opcode, __int32 in, __int32* out)
		{
			poco_assert(sl.hasSymbol("NET_DVR_PlayBackControl_V40"));
			PNET_DVR_PlayBackControl_V40 NET_DVR_PlayBackControl_V40 = (PNET_DVR_PlayBackControl_V40)sl.getSymbol("NET_DVR_PlayBackControl_V40");

			return NET_DVR_PlayBackControl_V40(handle, Opcode, &in, 0, out, NULL);
		}

	}
}