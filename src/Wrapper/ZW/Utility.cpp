#include "ZW/Utility.h"
#include <Poco/DateTime.h>

#include <memory>

#define check_symbol(fn) if (!Utility::_library.hasSymbol(fn)) \
							throw Poco::NotFoundException(fn)



namespace DVR {
	namespace ZWLite {
		const int Utility::success = TRUE;
		Poco::SharedLibrary Utility::_library("sdk\\ZW\\JCSDK.dll");
		Poco::Mutex Utility::_mutex;

		Utility::Utility()
		{

		}


		Utility::~Utility()
		{
		}

		void Utility::Init()
		{				
			typedef  BOOL (JCSDK_CALLTYPE *FnCSDK_InitSDK)(int nLocStartPort);
			check_symbol("JCSDK_InitSDK");
			FnCSDK_InitSDK InitSDK = (FnCSDK_InitSDK)_library.getSymbol("JCSDK_InitSDK");

			if (success != InitSDK(-1))
				poco_unexpected();

		}

		void Utility::Cleanup()
		{			
			typedef  void (JCSDK_CALLTYPE *FnJCSDK_ReleaseSDK)();
			check_symbol("JCSDK_ReleaseSDK");
			FnJCSDK_ReleaseSDK ReleaseSDK = (FnJCSDK_ReleaseSDK)_library.getSymbol("JCSDK_ReleaseSDK");
			ReleaseSDK();
		}

		void funJCEventCallback(JCLink_t nLinkID, JCEventType etType, DWORD_PTR pData1, DWORD_PTR pData2, LPVOID pUserData)
		{
			DWORD dwMsgID = 0;

			switch (etType)
			{
			case JCET_GetFileListOK://获取远程录像成功
				break;
			case JCET_GetFileListError://获取远程录像失败
				break;
			case JCET_StreamReset://码流重置信号
				break;
			case JCET_ConnectOK://连接成功
				break;

			case JCET_UserAccessError: //用户验证失败
				
				break;

			case JCET_NoChannel://主控通道未开启
				
				break;

			case JCET_ConTypeError://连接类型错误
				
				break;

			case JCET_ConCountLimit://超过主控连接最大数
				
				break;

			case JCET_ConTimeout://连接超时
				
				break;

			case JCET_DisconOK://断开连接成功
				
				break;

			case JCET_ConAbout://连接异常断开
				
				break;

			case JCET_ServiceStop://主控断开连接
				
				break;

			default:
				return;
				break;
			}
		}

		void funJCDataCallback(JCLink_t nLinkID, PJCStreamFrame pFrame, LPVOID pUserData)
		{

		}

		void funJCRawDataCallback(JCLink_t nLinkID, PJCRawFrame pFrame, LPVOID pUserData)
		{

		}

		void funLanSearchCallback(PJCLanDeviceInfo pDevice)
		{

		}

		void Utility::RegisterCallback()
		{
			typedef void (JCSDK_CALLTYPE *FnJCSDK_RegisterCallback)(	JCEventCallback_t funEventCallback,	JCDataCallback_t funDataCallback,JCRawDataCallback_t funRawDataCallback,JCLanSearchDeviceCallback_t funLanSearchDeviceCallback);
			check_symbol("JCSDK_RegisterCallback");
			FnJCSDK_RegisterCallback RegisterCallback = (FnJCSDK_RegisterCallback)_library.getSymbol("JCSDK_RegisterCallback");
			RegisterCallback(funJCEventCallback, funJCDataCallback, funJCRawDataCallback, funLanSearchCallback);
		}
		
		Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& address, const std::string& user, const std::string& password, const long channel)
		{
			typedef JCLink_t (JCSDK_CALLTYPE *FnJCSDK_Connect)(char *szServer, int nPort, int nChannel, char *szNetUser, char *szPwd, BOOL bNumOrIP, LPVOID pUserData);
			
			check_symbol("JCSDK_Connect");

			FnJCSDK_Connect Connect = (FnJCSDK_Connect)_library.getSymbol("JCSDK_Connect");
			std::string ip = address.host().toString();
			unsigned short port = address.port();
			int nError = 0;
			return Connect((char*)ip.c_str(), port, channel, (char*)user.c_str(), (char*)password.c_str(), FALSE, NULL);
		}
		

		bool Utility::logout(Utility::HANDLE handle)
		{
			typedef BOOL (JCSDK_CALLTYPE *FnJCSDK_Disconnect)(JCLink_t nLinkID);

			check_symbol("JCSDK_Disconnect");

			FnJCSDK_Disconnect Disconnect = (FnJCSDK_Disconnect)_library.getSymbol("JCSDK_Disconnect");
			return Disconnect(handle);
		}

		bool Utility::findStream(Utility::HANDLE handle, const Condition& cond)
		{
			typedef BOOL (JCSDK_CALLTYPE *FnJCSDK_GetRemoteRecFileList)(JCLink_t nLinkID, PJCDateBlock pDate);
			check_symbol("JCSDK_GetRemoteRecFileList");

			FnJCSDK_GetRemoteRecFileList GetRemoteRecFileList = (FnJCSDK_GetRemoteRecFileList)_library.getSymbol("JCSDK_GetRemoteRecFileList");
			return GetRemoteRecFileList(handle, (PJCDateBlock)&cond);
		}

		bool Utility::readStream(Utility::HANDLE handle, const Record& record)
		{
			typedef BOOL (JCSDK_CALLTYPE *FnJCSDK_DownloadRemoteFile)(JCLink_t nLinkID, int nFileID);
			check_symbol("JCSDK_DownloadRemoteFile");

			FnJCSDK_DownloadRemoteFile DownloadRemoteFile = (FnJCSDK_DownloadRemoteFile)_library.getSymbol("JCSDK_DownloadRemoteFile");
			return DownloadRemoteFile(handle, record);
		}

		bool Utility::play(Utility::HANDLE handle, const Record& record)
		{
			typedef BOOL (JCSDK_CALLTYPE *FnJCSDK_RemotePlay)(JCLink_t nLinkID, int nFileID);
			check_symbol("JCSDK_RemotePlay");
			FnJCSDK_RemotePlay RemotePlay = (FnJCSDK_RemotePlay)_library.getSymbol("JCSDK_RemotePlay");
			return RemotePlay(handle, record);
		}

		void Utility::throwException(long rc, const std::string& addErrMsg)
		{
			throw Poco::IOException(addErrMsg);
		}

	}
}