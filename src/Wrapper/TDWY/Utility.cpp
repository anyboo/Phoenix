#include "TDWY/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/Exception.h>
#include <memory>

#define check_symbol(fn) if (!Utility::_library.hasSymbol(fn)) \
							throw Poco::NotFoundException(fn)



namespace DVR {
	namespace TDWYLite {
		const int Utility::success = 0;		
		Poco::SharedLibrary Utility::_library("sdk\\TDWY\\NVSSDK.dll");
		Poco::Mutex Utility::_mutex;
		

		Utility::Utility()
		{
			
		}


		Utility::~Utility()
		{
			
		}

		void Utility::Init()
		{				
			{
				Poco::Mutex::ScopedLock lock(_mutex);
				static Utility u;
			}
			typedef  int (__stdcall *FnNetClient_Startup_V4)(int _iServerPort/*=3000*/, int _iClientPort/*=6000*/, int _iWnd/*=0*/);
			check_symbol("NetClient_Startup_V4");
			FnNetClient_Startup_V4 Startup_V4 = (FnNetClient_Startup_V4)_library.getSymbol("NetClient_Startup_V4");

			

			if (success != Startup_V4(3000, 6000, 0))
				poco_unexpected();

		}

		void Utility::SetNotifyFunction(PVOID pNotify)
		{
			typedef int(__stdcall *FnNetClient_SetNotifyFunction_V4)(MAIN_NOTIFY_V4 _MainNotify,
				ALARM_NOTIFY_V4 _AlarmNotify, PARACHANGE_NOTIFY_V4  _ParaNotify,
				COMRECV_NOTIFY_V4 _ComNotify, PROXY_NOTIFY _ProxyNotify);
			check_symbol("NetClient_SetNotifyFunction_V4");
			FnNetClient_SetNotifyFunction_V4 SetNotifyFunction_V4 = (FnNetClient_SetNotifyFunction_V4)_library.getSymbol("NetClient_SetNotifyFunction_V4");
			SetNotifyFunction_V4((MAIN_NOTIFY_V4)pNotify, NULL, NULL, NULL, NULL);
		}

		void Utility::Cleanup()
		{			
			typedef  int (__stdcall *FnNetClient_Cleanup)();
			check_symbol("NetClient_Cleanup");
			FnNetClient_Cleanup Cleanup = (FnNetClient_Cleanup)_library.getSymbol("NetClient_Cleanup");
			
			if (success != Cleanup())
				poco_unexpected();
		}

		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& address, const std::string& user, const std::string& password)
		{
			typedef int (__stdcall *FnNetClient_Logon)(char* _cProxy, char* _cIP, char* _cUserName, char* _cPwd, char* _cProductID, int _iPort);
			
			check_symbol("NetClient_Logon");

			FnNetClient_Logon Connect = (FnNetClient_Logon)_library.getSymbol("NetClient_Logon");
			std::string ip = address.host().toString();
			unsigned short port = address.port();
			int nError = 0;
			if (success > Connect(NULL, (char*)ip.c_str(), (char*)user.c_str(), (char*)password.c_str(), NULL, port))
				return false;

			return true;
		}
		
		bool Utility::getChannel(Utility::HANDLE handle, int *count)
		{
			typedef int (__stdcall *FnNetClient_GetChannelNum)(int _iLogonID, int* _iChannelNum);
			check_symbol("NetClient_GetChannelNum");
			FnNetClient_GetChannelNum getChannel = (FnNetClient_GetChannelNum)_library.getSymbol("NetClient_GetChannelNum");

			if (getChannel(handle, count) != success)
				return false;

			return true;
		}

		bool Utility::logout(Utility::HANDLE handle)
		{
			typedef int (__stdcall *FnNetClient_Logoff)(int _iLogonID);
			check_symbol("NetClient_Logoff");

			FnNetClient_Logoff Disconnect = (FnNetClient_Logoff)_library.getSymbol("NetClient_Logoff");
			if (success != Disconnect(handle))
				return false;

			return true;
		}

		bool Utility::findStream(Utility::HANDLE handle, const Condition& cond)
		{
			typedef int (__stdcall *FnNetClient_NetFileQuery)(int _iLogonID, PNVS_FILE_QUERY _fileQuery);
			check_symbol("NetClient_NetFileQuery");
			
			FnNetClient_NetFileQuery FindFile = (FnNetClient_NetFileQuery)_library.getSymbol("NetClient_NetFileQuery");
			
			if (success != FindFile(handle, (PNVS_FILE_QUERY)&cond))
				return false;

			return true;
		}

		bool Utility::getFindCount(Utility::HANDLE handle, int *count)
		{
			typedef int (__stdcall *FnNetClient_NetFileGetFileCount)(int _iLogonID, int *_iTotalCount, int *_iCurrentCount);
			check_symbol("NetClient_NetFileGetFileCount");

			int iTotalCount = 0;
			FnNetClient_NetFileGetFileCount getCount = (FnNetClient_NetFileGetFileCount)_library.getSymbol("NetClient_NetFileGetFileCount");
			if (success != getCount(handle, &iTotalCount, count))
				return false;

			return true;
		}

		bool Utility::getFindResult(Utility::HANDLE handle, int iIndex, Record& data)
		{
			typedef int (__stdcall *FnNetClient_NetFileGetQueryfile)(int _iLogonID, int _iFileIndex, PNVS_FILE_DATA _fileInfo);
			check_symbol("NetClient_NetFileGetQueryfile");

			FnNetClient_NetFileGetQueryfile NetFileGetQueryfile = (FnNetClient_NetFileGetQueryfile)_library.getSymbol("NetClient_NetFileGetQueryfile");
			if (success != NetFileGetQueryfile(handle, iIndex, &data))
				return false;

			return true;
		}		

		Utility::FileHandle Utility::readStream(Utility::HANDLE handle, Play& data, const std::string& newname)
		{
			typedef int (__stdcall *FnNetClient_NetFileDownloadFile)(unsigned int *_ulID,
				int _iLogonID,
				char* _cRemoteFilename,
				char* _cLocalFilename,
				int	_iFlag,
				int	_iPosition,
				int	_Speed);
			check_symbol("NetClient_NetFileDownloadFile");
			FnNetClient_NetFileDownloadFile GetFileByName = (FnNetClient_NetFileDownloadFile)_library.getSymbol("NetClient_NetFileDownloadFile");			

			Utility::FileHandle iDownloadId = 0;
			if (success < GetFileByName(&iDownloadId, handle, data.cFileName, (char *)newname.c_str(), 0, 0, 4))
				return 0;
			return iDownloadId;
		}

		Utility::FileHandle Utility::readStreamByTime(Utility::HANDLE handle, Play& data, const std::string& newname)
		{
			typedef int (__stdcall *FnNetClient_NetFileDownloadByTimeSpanEx)(unsigned int* _ulConID, int _iLogonID, char* _pcLocalFile,
				int _iChannelNO, NVS_FILE_TIME *_pTimeBegin, NVS_FILE_TIME *_pTimeEnd,
				int _iFlag, int _iPosition, int _iSpeed);

			check_symbol("NetClient_NetFileDownloadByTimeSpanEx");
			FnNetClient_NetFileDownloadByTimeSpanEx GetFileByTime = (FnNetClient_NetFileDownloadByTimeSpanEx)_library.getSymbol("NetClient_NetFileDownloadByTimeSpanEx");
			Utility::FileHandle iDownloadId = 0;
			if (success < GetFileByTime(&iDownloadId, handle, (char *)newname.c_str(), data.iChannel, &data.struStartTime, &data.struStoptime, 0, 0, 4))
				return 0;

			return iDownloadId;
		}

		int Utility::readStreamPos(Utility::FileHandle handle)
		{

		}
		
		Utility::PlayHandle Utility::playStream(Utility::HANDLE handle, Play& data)
		{
			typedef LPVOID (STDCALL *FnNETDEV_PlayBackByName)(IN LPVOID lpUserID, IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo);
			check_symbol("NETDEV_PlayBackByName");
			FnNETDEV_PlayBackByName RemotePlay = (FnNETDEV_PlayBackByName)_library.getSymbol("NETDEV_PlayBackByName");

			data.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
			data.dwDownloadSpeed = NETDEV_DOWNLOAD_SPEED_ONE;
			return RemotePlay(handle, (LPNETDEV_PLAYBACKINFO_S)&data);
		}

		

		Utility::PlayHandle Utility::playStreamByTime(Utility::HANDLE handle, PlayCondition& data)
		{
			typedef LPVOID (STDCALL *FnNETDEV_PlayBackByTime)(IN LPVOID lpUserID, IN LPNETDEV_PLAYBACKCOND_S pstPlayBackInfo);
			check_symbol("NETDEV_PlayBackByTime");
			FnNETDEV_PlayBackByTime RemotePlay = (FnNETDEV_PlayBackByTime)_library.getSymbol("NETDEV_PlayBackByTime");

			data.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
			data.dwDownloadSpeed = NETDEV_DOWNLOAD_SPEED_ONE;
			return RemotePlay(handle, (LPNETDEV_PLAYBACKCOND_S)&data);
		}

		bool Utility::playPos(Utility::PlayHandle handle, INT64 *iTime)
		{
			typedef BOOL (STDCALL *FnNETDEV_PlayBackControl)(IN LPVOID   lpPlayHandle, IN INT32    dwControlCode, INOUT LPVOID lpBuffer);
			check_symbol("NETDEV_PlayBackControl");
			FnNETDEV_PlayBackControl PlayBackControl = (FnNETDEV_PlayBackControl)_library.getSymbol("NETDEV_PlayBackControl");
			
			return PlayBackControl(handle, NETDEV_PLAY_CTRL_GETPLAYTIME, iTime);
		}

		bool Utility::stopStream(Utility::PlayHandle handle)
		{
			typedef BOOL(STDCALL *FnNETDEV_StopPlayBack)(IN LPVOID lpPlayHandle);
			check_symbol("NETDEV_StopPlayBack");
			FnNETDEV_StopPlayBack StopPlayBack = (FnNETDEV_StopPlayBack)_library.getSymbol("NETDEV_StopPlayBack");

			return StopPlayBack(handle);
		}

		bool Utility::seek(Utility::PlayHandle handle, INT64 pos)
		{
			typedef BOOL(STDCALL *FnNETDEV_PlayBackControl)(IN LPVOID   lpPlayHandle, IN INT32    dwControlCode, INOUT LPVOID lpBuffer);
			check_symbol("NETDEV_PlayBackControl");
			FnNETDEV_PlayBackControl PlayBackControl = (FnNETDEV_PlayBackControl)_library.getSymbol("NETDEV_PlayBackControl");

			return PlayBackControl(handle, NETDEV_PLAY_CTRL_SETPLAYTIME, &pos);
		}

		bool Utility::pause(Utility::PlayHandle handle)
		{
			typedef BOOL(STDCALL *FnNETDEV_PlayBackControl)(IN LPVOID   lpPlayHandle, IN INT32    dwControlCode, INOUT LPVOID lpBuffer);
			check_symbol("NETDEV_PlayBackControl");
			FnNETDEV_PlayBackControl PlayBackControl = (FnNETDEV_PlayBackControl)_library.getSymbol("NETDEV_PlayBackControl");

			return PlayBackControl(handle, NETDEV_PLAY_CTRL_PAUSE, NULL);
		}

		bool Utility::resume(Utility::PlayHandle handle)
		{
			typedef BOOL(STDCALL *FnNETDEV_PlayBackControl)(IN LPVOID   lpPlayHandle, IN INT32    dwControlCode, INOUT LPVOID lpBuffer);
			check_symbol("NETDEV_PlayBackControl");
			FnNETDEV_PlayBackControl PlayBackControl = (FnNETDEV_PlayBackControl)_library.getSymbol("NETDEV_PlayBackControl");

			return PlayBackControl(handle, NETDEV_PLAY_CTRL_RESUME, NULL);
		}

		void Utility::throwException(long rc, const std::string& addErrMsg)
		{
			switch (rc){
			case NETDEV_E_COMMON_FAILED:
			case NETDEV_E_DEV_COMMON_FAILED:
			case NETDEV_E_SYSCALL_FALIED:
			case NETDEV_E_NULL_POINT:
			case NETDEV_E_INVALID_PARAM:
			case NETDEV_E_INVALID_MODULEID:
			case NETDEV_E_NO_MEMORY:
			case NETDEV_E_NOT_SUPPORT:
			case NETDEV_E_SDK_SOCKET_LSN_FAIL:
			case NETDEV_E_INIT_MUTEX_FAIL:
			case NETDEV_E_INIT_SEMA_FAIL:
			case NETDEV_E_ALLOC_RESOURCE_ERROR:
			case NETDEV_E_SDK_NOINTE_ERROR:
			case NETDEV_E_ALREDY_INIT_ERROR:
			case NETDEV_E_HAVEDATA:
			case NETDEV_E_NEEDMOREDATA:
			case NETDEV_E_CONNECT_ERROR:
			case NETDEV_E_SEND_MSG_ERROR:
			case NETDEV_E_TIMEOUT:
			case NETDEV_E_DECODE_RSP_ERROR:
			case NETDEV_E_SOCKET_RECV_ERROR:
			case NETDEV_E_NUM_MAX_ERROR:
			case NETDEV_E_GET_PORT_ERROR:
			case NETDEV_E_CREATE_THREAD_FAIL:
			case NETDEV_E_NOENOUGH_BUF:
			case NETDEV_E_GETLOCALIPANDMACFAIL:
			case NETDEV_E_RESCODE_NO_EXIST:
			case NETDEV_E_MSG_DATA_INVALID:
			case NETDEV_E_GET_CAPABILITY_ERROR:
			case NETDEV_E_USER_NOT_BIND:
			case NETDEV_E_AUTHORIZATIONFAIL:
			case NETDEV_E_BINDNOTIFY_FAIL:
			case NETDEV_E_NOTADMIN:
			case NETDEV_E_DEVICE_FACTURER_ERR:
			case NETDEV_E_NONSUPPORT:
			case NETDEV_E_TRANSFILE_FAIL:
			case NETDEV_E_JSON_ERROR:
			case NETDEV_E_NO_RESULT:
			case NETDEV_E_USER_WRONG_PASSWD:
			case NETDEV_E_USER_LOGIN_MAX_NUM:
			case NETDEV_E_USER_NOT_ONLINE:
			case NETDEV_E_USER_NO_SUCH_USER:
			case NETDEV_E_USER_NO_AUTH:
			case NETDEV_E_USER_MAX_NUM:
			case NETDEV_E_USER_EXIST:
			case NETDEV_E_USER_PASSWORD_CHANGE:
			case NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD:
			case NETDEV_E_VOD_PLAY_END:
			case NETDEV_E_VOD_NO_CM:
			case NETDEV_E_VOD_OVER_ABILITY:
			case NETDEV_E_VOD_NO_RECORDING_CM:
			case NETDEV_E_VOD_NO_RECORDING:
			case NETDEV_E_VOD_NO_REPLAYURL:
				throw Poco::IOException(addErrMsg);
			default:
				throw Poco::IOException("default exception!");
			}
		}

		int Utility::lastError()
		{
			typedef INT32 (STDCALL *FnNETDEV_GetLastError)();			
			check_symbol("NETDEV_GetLastError");
			FnNETDEV_GetLastError GetLastErro = (FnNETDEV_GetLastError)Utility::_library.getSymbol("NETDEV_GetLastError");

			return GetLastErro();
		}

		void Utility::readDeviceInfo(DeviceInfo& info)
		{
			poco_check_ptr(_pDevice_info);
			memcpy(&info, _pDevice_info, sizeof(DeviceInfo));
		}
	}
}