#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "YS/Utility.h"

using namespace DVR::YSLite;
using namespace std;

class YSLIBTEST : public CppUnit::TestCase
{
public:
	YSLIBTEST(const std::string& name);
	~YSLIBTEST();

	static CppUnit::Test* suite();

	void testInit();
	void testClean();

	void testLogin();
	void testLogout();

	void testFindfile();

private:
	string _connectString;
	DVR::YSLite::Utility::HANDLE _handle;
	long _channel;
};

