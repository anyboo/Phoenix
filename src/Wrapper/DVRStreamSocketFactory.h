#pragma once

#include <map>
#include <string>

class DVRStreamSocket;
class DVRStreamSocketFactory
{
public:
	DVRStreamSocketFactory();
	~DVRStreamSocketFactory();

	static DVRStreamSocketFactory& instance();
	DVRStreamSocket* get(const std::string& brand);
private:
	typedef std::map<std::string, DVRStreamSocket*> DVRStreamSocketPool;
	typedef DVRStreamSocketPool::iterator Iter;
	typedef DVRStreamSocketPool::const_iterator Const_Iter;

	DVRStreamSocketPool _pool;
};

