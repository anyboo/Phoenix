#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "DH/Utility.h"

using namespace DVR::DHLite;
using namespace std;

class DHLIBTEST : public CppUnit::TestCase
{
public:
	DHLIBTEST(const std::string& name);
	~DHLIBTEST();

	static CppUnit::Test* suite();

	void testInit();
	void testClean();

	void testLogin();
	void testLogout();

	void testFindfile();

private:
	string _connectString;
	DVR::DHLite::Utility::HANDLE _handle;
	long _channel;
};

