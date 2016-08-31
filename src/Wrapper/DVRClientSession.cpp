#include "stdafx.h"
#include "DVRClientSession.h"
#include "DVRStreamSocket.h"
#include "DVRStreamSocketFactory.h"

DVRClientSession::DVRClientSession()
:_brand(0)
, _host(0)
, _port(0)
, _isLoggedIn(false)
, _pControlSocket(0)
{

}

DVRClientSession::DVRClientSession(const DVRStreamSocket& DVRSocket)
:_pControlSocket(new DVRStreamSocket(DVRSocket))
{

}

DVRClientSession::DVRClientSession(const std::string& addr, unsigned short port, const std::string& brand)
:_brand(brand)
, _host(addr)
, _port(port)
, _isLoggedIn(false)
{
	_pControlSocket = DVRStreamSocketFactory::instance().get(brand);
	_pControlSocket->connect(addr,port);
}

DVRClientSession::~DVRClientSession()
{
	if (_pControlSocket)
	delete _pControlSocket;
}

void DVRClientSession::login(const std::string& user, const std::string& password)
{
	if (_isLoggedIn)
		logout();

	_pControlSocket->login(user, password);
	_isLoggedIn = true;
}

void DVRClientSession::logout()
{
	_pControlSocket->logout();
	_isLoggedIn = false;
}

#include <fstream>
std::istream& DVRClientSession::beginList(const std::string& path, bool extended)
{
	std::fstream fs;
	//return *_pDataStream;
	return fs;
}

void DVRClientSession::endList()
{
	endTransfer();
}

#include <fstream>
std::istream& DVRClientSession::beginDownload(const std::string& path)
{
	std::fstream fs;
	//return *_pDataStream;
	return fs;
}

void DVRClientSession::endDownload()
{
	endTransfer();
}

void DVRClientSession::abort()
{

}

void DVRClientSession::play(const std::string& filename)
{

}

bool DVRClientSession::isLoggedIn() const
{
	return _isLoggedIn;
}


void DVRClientSession::endTransfer()
{

}