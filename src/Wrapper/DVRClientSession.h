#pragma once
#include <string>

class DVRStreamSocket;
class DVRSocketStream;

class DVRClientSession
{
public:
	DVRClientSession();
	explicit DVRClientSession(const DVRStreamSocket& DVRSocket);
	DVRClientSession(const std::string& addr, unsigned short port, const std::string& brand = "auto");
	~DVRClientSession();

	void login(const std::string& user, const std::string& password);
	void logout();

	std::istream& beginList(const std::string& path = "", bool extended = false);
	void endList();

	std::istream& beginDownload(const std::string& path);
	void endDownload();

	void abort();

	void play(const std::string& filename);

	bool isLoggedIn() const;
protected:
	void endTransfer();
private:
	DVRStreamSocket* _pControlSocket;
	DVRSocketStream* _pDataStream;

	std::string _brand;
	std::string _host;
	unsigned short _port;
	bool _isLoggedIn;
};


