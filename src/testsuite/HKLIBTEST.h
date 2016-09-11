#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "HK/Utility.h"

using namespace DVR::HKLite;
using namespace std;

class HKLIBTEST : public CppUnit::TestCase
{
public:
	HKLIBTEST(const std::string& name);
	~HKLIBTEST();

	static CppUnit::Test* suite();

	void testInit();
	void testClean();

	void testLogin();
	void testLogout();

	void testFindfile();

private:
	string _connectString;
	DVR::HKLite::Utility::HANDLE _handle;
	long _channel;
};

