#pragma once
#include <string>

class DVRStreamSocket
{
public:
	DVRStreamSocket();
	~DVRStreamSocket();

	void connect(const std::string& addr, unsigned short port);
	void login(const std::string& user, const std::string& password);
	void logout();
};

