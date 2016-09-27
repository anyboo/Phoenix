#include "YS/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/Exception.h>
#include <memory>

#define check_symbol(fn) if (!Utility::_library.hasSymbol(fn)) \
							throw Poco::NotFoundException(fn)



namespace DVR {
	namespace YSLite {
		const int Utility::success = TRUE;
		Poco::SharedLibrary Utility::_library("sdk\\YS\\NetDEVSDK.dll");
		Poco::Mutex Utility::_mutex;
		DeviceInfo* Utility::_pDevice_info = nullptr;

		Utility::Utility()
		{

		}


		Utility::~Utility()
		{
		}

		void Utility::Init()
		{				
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

		bool Utility::seek(Utility::PlayHandle handle, int pos)
		{
			return true;
		}

		void Utility::throwException(long rc, const std::string& addErrMsg)
		{
			throw Poco::IOException(addErrMsg);
		}

		void Utility::readDeviceInfo(DeviceInfo& info)
		{
			poco_check_ptr(_pDevice_info);
			memcpy(&info, _pDevice_info, sizeof(DeviceInfo));
		}
	}
}