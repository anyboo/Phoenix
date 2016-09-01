#pragma once
#include "DZPLite.h"
#include "DVR/AbstractSessionImpl.h"
#include <Poco/Net/SocketAddress.h>

extern "C"
{
	typedef struct _H264_DVR_DEVICEINFO dvrinfo;
	typedef long dvrhandle;
}

namespace DVR {
namespace DZPLite {

class DZPLite_API DVRSessionImpl :public DVR::AbstractSessionImpl<DVRSessionImpl>
{
public:
	typedef char StatePlayType;
	static const StatePlayType paused = 0;
	static const StatePlayType continued = 1;
	static const StatePlayType seek = 2;
	static const StatePlayType fast = 3;
	static const StatePlayType slow = 4;
	static const StatePlayType percent = 5;

	static const std::size_t TRY_TIMES = 3;//try 3 times

	DVRSessionImpl(const std::string& deviceLocation, /*192.168.1.22:35*/
		std::size_t timeout = LOGIN_TIMEOUT_DEFAULT);
	virtual ~DVRSessionImpl();

	virtual void login(const std::string& user = "", const std::string& password = "");
	virtual void logout();
	virtual bool isLoggedIn()const;

	virtual void setLoginTimeout(std::size_t timeout);
	virtual std::size_t getLoginTimeout() const;

	virtual void beginList(const std::string& path = "", bool extended = false);
	virtual void beginDownload(const std::string& path);
	virtual void play(const std::string& filename);
	virtual void abort();
protected:
	void pause();
	void playControl(StatePlayType state);

	void beginList(const std::string& BeginDatetime, const std::string& DatetimeEnd);
private:
	std::string _connector;
	dvrhandle*	_pDvr;
	bool        _connected;
	int         _timeout;

	Poco::Mutex _mutex;
	Poco::Net::SocketAddress _addr;
};

}}

