#include "WSD/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/Exception.h>
#include <memory>

#define check_symbol(fn) if (!Utility::_library.hasSymbol(fn)) \
							throw Poco::NotFoundException(fn)



namespace DVR {
	namespace WSDLite {
		const int Utility::success = TRUE;		
		Poco::SharedLibrary Utility::_library("sdk\\WSD\\NetDEVSDK.dll");
		Poco::Mutex Utility::_mutex;
		DeviceInfo* Utility::_pDevice_info = nullptr;

		Utility::Utility()
		{
			if (!_pDevice_info)
			{
				_pDevice_info = new DeviceInfo();
				memset(_pDevice_info, 0, sizeof(DeviceInfo));
			}
		}


		Utility::~Utility()
		{
			if (_pDevice_info)
			{
				delete _pDevice_info;
				_pDevice_info = 0;
			}
		}

		void Utility::Init()
		{				
			{
				Poco::Mutex::ScopedLock lock(_mutex);
				static Utility u;
			}
			typedef  BOOL (STDCALL *FnNETDEV_Init)(void);
			check_symbol("NETDEV_Init");
			FnNETDEV_Init InitSDK = (FnNETDEV_Init)_library.getSymbol("NETDEV_Init");

			if (success != InitSDK())
				poco_unexpected();

		}

		void Utility::Cleanup()
		{			
			typedef  BOOL (STDCALL *FnNETDEV_Cleanup)(void);
			check_symbol("NETDEV_Cleanup");
			FnNETDEV_Cleanup Cleanup = (FnNETDEV_Cleanup)_library.getSymbol("NETDEV_Cleanup");
			
			if (success != Cleanup())
				poco_unexpected();
		}

		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& address, const std::string& user, const std::string& password)
		{
			typedef  LPVOID (STDCALL *FnNETDEV_Login)(IN char *pszDevIP, IN INT16 wDevPort, IN char *pszUserName,IN char *pszPassword,OUT LPNETDEV_DEVICE_INFO_S pstDevInfo);
			
			check_symbol("NETDEV_Login");

			FnNETDEV_Login Connect = (FnNETDEV_Login)_library.getSymbol("NETDEV_Login");
			std::string ip = address.host().toString();
			unsigned short port = address.port();
			int nError = 0;
			return Connect((char*)ip.c_str(), port, (char*)user.c_str(), (char*)password.c_str(), _pDevice_info);
		}
		

		bool Utility::logout(Utility::HANDLE handle)
		{
			typedef BOOL (STDCALL *FnNETDEV_Logout)(IN LPVOID lpUserID);
			check_symbol("NETDEV_Logout");

			FnNETDEV_Logout Disconnect = (FnNETDEV_Logout)_library.getSymbol("NETDEV_Logout");
			return Disconnect(handle);
		}

		LPVOID Utility::findStream(Utility::HANDLE handle, const Condition& cond)
		{
			typedef LPVOID (STDCALL *FnNETDEV_FindFile)(IN LPVOID lpUserID, IN LPNETDEV_FILECOND_S pstFindCond);
			check_symbol("NETDEV_FindFile");
			
			FnNETDEV_FindFile FindFile = (FnNETDEV_FindFile)_library.getSymbol("NETDEV_FindFile");
			
			return FindFile(handle, (LPNETDEV_FILECOND_S)&cond);
		}

		bool Utility::findNextStream(Utility::HANDLE findHandle, Record& record)
		{
			typedef BOOL (STDCALL *FnNETDEV_FindNextFile)(IN LPVOID lpFindHandle, OUT LPNETDEV_FINDDATA_S pstFindData);
			check_symbol("NETDEV_FindNextFile");
			FnNETDEV_FindNextFile FindNextFile = (FnNETDEV_FindNextFile)_library.getSymbol("NETDEV_FindNextFile");
			return FindNextFile(findHandle, &record);
		}

		bool Utility::closeFindStream(Utility::HANDLE findHandle)
		{
			typedef BOOL (STDCALL *FnNETDEV_FindClose)(IN LPVOID lpFindHandle);
			check_symbol("NETDEV_FindClose");
			FnNETDEV_FindClose FindClose = (FnNETDEV_FindClose)_library.getSymbol("NETDEV_FindClose");
			return FindClose(findHandle);
		}

		Utility::FileHandle Utility::readStream(Utility::HANDLE handle, Play& data, const std::string& newname)
		{
			typedef LPVOID (STDCALL *FnNETDEV_GetFileByName)(IN LPVOID  lpUserID, IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo, IN char *pszSaveFileName, IN INT32 dwFormat);
			check_symbol("NETDEV_GetFileByName");
			FnNETDEV_GetFileByName GetFileByName = (FnNETDEV_GetFileByName)_library.getSymbol("NETDEV_GetFileByName");
			data.hPlayWnd = NULL;
			data.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
			data.dwDownloadSpeed = NETDEV_DOWNLOAD_SPEED_EIGHT;

			return GetFileByName(handle, (LPNETDEV_PLAYBACKINFO_S)&data, (char *)newname.c_str(), NETDEV_MEDIA_FILE_MP4);
		}
		Utility::FileHandle Utility::readStreamByTime(Utility::HANDLE handle, PlayCondition& data, const std::string& newname)
		{
			typedef LPVOID (STDCALL *FnNETDEV_GetFileByTime)(IN LPVOID lpUserID, IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond, IN char *pszSaveFileName, IN INT32 dwFormat);
			check_symbol("NETDEV_GetFileByTime");
			FnNETDEV_GetFileByTime GetFileByName = (FnNETDEV_GetFileByTime)_library.getSymbol("NETDEV_GetFileByTime");
			data.hPlayWnd = NULL;
			data.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
			data.dwDownloadSpeed = NETDEV_DOWNLOAD_SPEED_EIGHT;

			return GetFileByName(handle, (LPNETDEV_PLAYBACKCOND_S)&data, (char *)newname.c_str(), NETDEV_MEDIA_FILE_MP4);
		}

		bool Utility::closeStream(Utility::FileHandle handle)
		{
			typedef BOOL (STDCALL *FnNETDEV_StopGetFile)(IN LPVOID lpPlayHandle);
			check_symbol("NETDEV_StopGetFile");
			FnNETDEV_StopGetFile StopGetFile = (FnNETDEV_StopGetFile)_library.getSymbol("NETDEV_GetFileByTime");
			return StopGetFile(handle);
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