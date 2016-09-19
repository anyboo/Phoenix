#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "JXJ/Utility.h"


using namespace DVR::JXJLite;
using namespace std;

class JXJLIBTEST : public CppUnit::TestCase
{
public:
	JXJLIBTEST(const std::string& name);
	~JXJLIBTEST();

	static CppUnit::Test* suite();

	void testInit();
	void testClean();

	void testLogin();
	void testLogout();

	void testFindfile();

private:
	string _connectString;
	DVR::JXJLite::Utility::HANDLE _handle;
	long _channel;
};

