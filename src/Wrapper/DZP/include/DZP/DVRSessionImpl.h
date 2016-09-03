#pragma once
#include "DZPLite.h"
#include "DVR/AbstractSessionImpl.h"
#include "DZP/Utility.h"
#include <Poco/Net/SocketAddress.h>

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
	~DVRSessionImpl();

	void login(const std::string& user = "", const std::string& password = "");
	void logout();
	bool isLoggedIn()const;

	void list();
	void download();
	void playback();
	void abort();
	const std::string& connectorName() const;
	void setLoginTimeout(std::size_t timeout);
	std::size_t getLoginTimeout() const;

	DVR::DVRStatementImpl* createStatementImpl();

private:
	std::string _connector;
	Utility::HANDLE	_handle;
	bool        _connected;
	int         _timeout;

	Poco::Mutex _mutex;
	Poco::Net::SocketAddress _addr;
};

inline const std::string& DVRSessionImpl::connectorName() const
{
	return _connector;
}


}}

