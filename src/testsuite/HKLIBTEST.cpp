
#include "HKLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

HKLIBTEST::HKLIBTEST(const std::string& name)
	: CppUnit::TestCase(name),
	_connectString("192.168.0.22:8000"),
	_handle(0),
	_channel(0)
{
	
}

HKLIBTEST::~HKLIBTEST()
{
}

void HKLIBTEST::testInit()
{
	cout << "HK test start" << endl;
	assert(Utility::Init() == Utility::success);
}

void HKLIBTEST::testClean()
{
	assert(Utility::CleanUp() == Utility::success);
	cout << "HK test end" << endl;
}

void HKLIBTEST::testLogin()
{
	Utility::DVRINFO info = { 0 };
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "12345", info);

	cout << "testLogin _handle: " << _handle << endl;
	_channel = info.nTotalChannel;
	assert(_handle >= 0);
	assert(_channel > 0);
}

void HKLIBTEST::testLogout()
{
	testLogin();
	cout << "testlogout _handle: " << _handle << endl;
	assert(_handle > 0);
	assert(Utility::logout(_handle) > 0);
}

void HKLIBTEST::testFindfile()
{
	testLogin();
	cout << "testFindfile _handle: " << _handle << endl;

	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
}

CppUnit::Test* HKLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("HKLIBTEST");
	
	CppUnit_addTest(pSuite, HKLIBTEST, testInit);
	CppUnit_addTest(pSuite, HKLIBTEST, testLogin);
	CppUnit_addTest(pSuite, HKLIBTEST, testLogout);
	CppUnit_addTest(pSuite, HKLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, HKLIBTEST, testClean);
	

	return pSuite;
}