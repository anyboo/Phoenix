#include "DZP/DVRSessionImpl.h"
#include "DZP/DVRConnector.h"
#include "DZP/Utility.h"
#include "DVR/DVRSession.h"
#include "netsdk.h"

#include <sstream>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTime.h>
#include <Poco/DateTimeParser.h>

namespace DVR {
namespace DZPLite {

DVRSessionImpl::DVRSessionImpl(const std::string& deviceLocation,
	std::size_t timeout):
	DVR::AbstractSessionImpl<DVRSessionImpl>(deviceLocation, timeout),
	_connector(DVRConnector::KEY),
	_timeout(timeout),//common use by DVR::DVRSessionImpl
	_connected(false),
	_addr(deviceLocation),
	_pDvr(new dvrhandle)
{
	poco_check_ptr(_pDvr);
	setLoginTimeout(_timeout);
	setProperty("handle", _pDvr);
}

DVRSessionImpl::~DVRSessionImpl()
{
	try
	{
		logout();
		delete _pDvr;
	}
	catch (...)
	{
		poco_unexpected();
	}
}

void DVRSessionImpl::login(const std::string& user, const std::string& password)
{
	if (isLoggedIn()) return;
	//deviceLocation = "192.168.1.25:32";
	std::string usr(user);
	std::string pwd(password);
	if (usr.empty()) usr = "admin";
	if (pwd.empty()) pwd = "admin";

	std::string host = _addr.host().toString();
	unsigned short port = _addr.port();
	
	dvrinfo info;
	int error = 0;
	memset(&info, 0, sizeof(dvrinfo));

	poco_check_ptr(_pDvr);
	*_pDvr = H264_DVR_Login(const_cast<char*>(host.c_str()), port,
		const_cast<char*>(usr.c_str()), const_cast<char*>(pwd.c_str()),
		&info, &error, SocketStyle::UDPSOCKET); //how do I know the type of socket,OMG FAITH

	if (*_pDvr <= 0) Utility::throwException(error);
	//notify device information
	
	_connected = true;
}

void DVRSessionImpl::logout()
{
	poco_assert(*_pDvr > 0);
	bool rc = H264_DVR_Logout(*_pDvr);
	if (!rc) Utility::lastError(_pDvr);
	//throw
	*_pDvr = 0;
	_connected = false;
}

bool DVRSessionImpl::isLoggedIn()const
{
	poco_assert(*_pDvr > 0);
	return _connected;
}

void DVRSessionImpl::setLoginTimeout(std::size_t timeout)
{
	bool rc = H264_DVR_SetConnectTime(timeout, TRY_TIMES);
	if (!rc) Utility::lastError(_pDvr);
	//thorw
}

std::size_t DVRSessionImpl::getLoginTimeout() const
{
	return _timeout;
}

void DVRSessionImpl::beginList(const std::string& BeginDatetime, const std::string& DatetimeEnd)
{
	using Poco::DateTime;
	using Poco::DateTimeParser;

	int timeZoneDifferential = 0;
	DateTime begin = DateTimeParser::parse(BeginDatetime, timeZoneDifferential);
	DateTime end = DateTimeParser::parse(DatetimeEnd, timeZoneDifferential);
}

void DVRSessionImpl::beginList(const std::string& path, bool extended)
{
	typedef H264_DVR_FINDINFO CONDITION;
	typedef H264_DVR_FILE_DATA RESULT;

	CONDITION condition;
	std::vector<RESULT> result(1000);

	int count = 0;
	int maxCount = 1000;
	int timeout = 5000;
	poco_assert(*_pDvr > 0);
	//将多天的查询范围，切分成1天的范围多次查询，多次通知
	int rc = H264_DVR_FindFile(*_pDvr, &condition, &result.front(), maxCount, &count, timeout);
	if (rc == 0) Utility::throwException(rc);
	
	std::stringstream message;

	for (auto var : result)
	{
		message << var.ch << var.hWnd << var.sFileName << var.size;
		poco_stdout_dbg(message.str());
	}
	//Notifier to SearchUI
}

void DVRSessionImpl::beginDownload(const std::string& path)
{
	//beginDonwload pushes the file(which will be download) in the queue, then dispatcher by handlethread
	//rule 1 : a channel - a thread
	//if same file is downloding, must cancel first.
	//Should be download per file one thread
	
	typedef fDownLoadPosCallBack DownloadPositionCallbackType;
	DownloadPositionCallbackType PositioncallbackFn;

	typedef fRealDataCallBack RealDateCallbackType;
	RealDateCallbackType datacallbcakFn;

	long pParam;

	//1.download by name
	typedef H264_DVR_FILE_DATA RESULT;
	RESULT result;
	std::string path;
	int handle = H264_DVR_GetFileByName(*_pDvr, &result, const_cast<char*>(path.c_str()),
		PositioncallbackFn, pParam, datacallbcakFn);

	//if failed , download by time
	if (handle <= 0)
	{
		typedef H264_DVR_FINDINFO CONDITION;
		CONDITION cond;

		handle = H264_DVR_GetFileByTime(*_pDvr, &cond, const_cast<char*>(path.c_str()),false,
			PositioncallbackFn, pParam, datacallbcakFn);
	}
	bool rc = 0;
	if ((rc = handle) <= 0 )
		Utility::throwException(rc);
	//rename filename
	//notifier to ui
}

void DVRSessionImpl::play(const std::string& filename)
{
	typedef fDownLoadPosCallBack DownloadPositionCallbackType;
	DownloadPositionCallbackType PositioncallbackFn;

	typedef fRealDataCallBack_V2 RealDateCallbackType;
	RealDateCallbackType datacallbcakFn;

	long pParam;

	typedef H264_DVR_FILE_DATA RESULT;
	RESULT result;
	int handle = H264_DVR_PlayBackByName_V2(*_pDvr, &result, PositioncallbackFn, datacallbcakFn, pParam);

	if (handle <= 0)
	{
		typedef fRealDataCallBack RealDateCallbackType;
		RealDateCallbackType datacallbcakFn;

		typedef H264_DVR_FINDINFO CONDITION;
		CONDITION cond; long pParamPos;

		handle = H264_DVR_PlayBackByTimeEx(*_pDvr, &cond, datacallbcakFn, pParam, PositioncallbackFn, pParamPos);
	}
	bool rc = 0;
	if ((rc = handle) <= 0)
		Utility::throwException(rc);
	//notify ui
}

void DVRSessionImpl::pause()
{
	playControl(paused);
}

void DVRSessionImpl::playControl(StatePlayType state)
{
	int value = 0;
	bool rc = H264_DVR_PlayBackControl(*_pDvr, state, value);
	if (!rc) Utility::throwException(rc);
}

void DVRSessionImpl::abort()
{

}

// NOTE: Utility::dvrHandle() has been moved here from Utility.cpp
// as a workaround for a failing AnyCast with Clang.
// for a discussion.

dvrhandle* Utility::dvrHandle(const DVRSession& session)
{
	return Poco::AnyCast<dvrhandle*>(session.getProperty("handle"));
}

}}