#include "stdafx.h"
#include "DVRStreamSocket.h"

/*DHSocket represents a vendor api*/
class DHSocket : public DVRStreamSocket{};
class HKSocket : public DVRStreamSocket{};
class JXJSocket : public DVRStreamSocket{};
class DZPSocket : public DVRStreamSocket{};

DVRStreamSocket::DVRStreamSocket()
{
}


DVRStreamSocket::~DVRStreamSocket()
{
}

void DVRStreamSocket::connect(const std::string& addr, unsigned short port)
{

}

void DVRStreamSocket::login(const std::string& user, const std::string& password)
{

}

void DVRStreamSocket::logout()
{

}

/* sample code

#include <Poco/Net/SocketAddress.h>
#include <string>
using Poco::Net::SocketAddress;

#include <Poco/Net/SocketStream.h>
using Poco::Net::SocketStreamBuf;
class DVRSocketStreamBuf
:public SocketStreamBuf
{
public:
DVRSocketStreamBuf(const DVRSocket& socket)
:SocketStreamBuf(socket)
{

}
~DVRSocketStreamBuf(){}
protected:
int readFromDevice(char* buffer, std::streamsize length)
{
return 0;
}
int writeToDevice(const char* buffer, std::streamsize length)
{
return 0;
}
};


DVRSocketStream handle the stream

#include <Poco/Net/SocketStream.h>

using Poco::Net::SocketIOS;
class DVRSocketStream
	:public SocketIOS, public std::iostream
{
public:
	explicit DVRSocketStream(const DVRSocket& socket)
		:SocketIOS(socket),
		std::iostream(&_buf)
	{

		}
	~DVRSocketStream()
	{

	}
};

*/