
#include "JXJLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

JXJLIBTEST::JXJLIBTEST(const std::string& name)
	: CppUnit::TestCase(name),
	_connectString("172.16.0.67:3321"),
	_handle(0),
	_channel(0)
{
	
}

JXJLIBTEST::~JXJLIBTEST()
{
}

void JXJLIBTEST::testInit()
{
	cout << "JXJ test start" << endl;
	assert(Utility::Init() == Utility::success);
}

void JXJLIBTEST::testClean()
{
	assert(Utility::CleanUp() == Utility::success);
	cout << "JXJ test end" << endl;
}

void JXJLIBTEST::testLogin()
{
	Utility::DVRINFO info = { 0 };
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "", info);

	cout << "testLogin _handle: " << _handle << endl;
	_channel = info.nTotalChannel;
	assert(_handle >= 0);
	assert(_channel > 0);
}

void JXJLIBTEST::testLogout()
{
	testLogin();
	cout << "testlogout _handle: " << _handle << endl;
	assert(_handle > 0);
	assert(Utility::logout(_handle) > 0);
}

void JXJLIBTEST::testFindfile()
{
	testLogin();
	cout << "testFindfile _handle: " << _handle << endl;

	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mon = ptm->tm_mon -2;
	cout << "month: " << ptm->tm_mon << endl;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
}

CppUnit::Test* JXJLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("JXJLIBTEST");
	
	CppUnit_addTest(pSuite, JXJLIBTEST, testInit);
	CppUnit_addTest(pSuite, JXJLIBTEST, testLogin);
	CppUnit_addTest(pSuite, JXJLIBTEST, testLogout);
	CppUnit_addTest(pSuite, JXJLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, JXJLIBTEST, testClean);
	

	return pSuite;
}