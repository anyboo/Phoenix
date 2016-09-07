
#include "DHLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

DHLIBTEST::DHLIBTEST(const std::string& name)
	: CppUnit::TestCase(name),
	_connectString("192.168.0.55:37777"),
	_handle(0),
	_channel(0)
{
	
}

DHLIBTEST::~DHLIBTEST()
{
}

void DHLIBTEST::testInit()
{
	cout << "DH test start" << endl;
	assert(Utility::Init() == Utility::success);
}

void DHLIBTEST::testClean()
{
	assert(Utility::CleanUp() == Utility::success);
	cout << "DH test end" << endl;
}

void DHLIBTEST::testLogin()
{
	Utility::DVRINFO info = { 0 };
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "112233", info);

	cout << "testLogin _handle: " << _handle << endl;
	_channel = info.nTotalChannel;
	assert(_handle > 0);
	assert(_channel > 0);
}

void DHLIBTEST::testLogout()
{
	testLogin();
	cout << "testlogout _handle: " << _handle << endl;
	assert(_handle > 0);
	assert(Utility::logout(_handle) > 0);
}

void DHLIBTEST::testFindfile()
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

CppUnit::Test* DHLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DHLIBTEST");
	
	CppUnit_addTest(pSuite, DHLIBTEST, testInit);
	CppUnit_addTest(pSuite, DHLIBTEST, testLogin);
	CppUnit_addTest(pSuite, DHLIBTEST, testLogout);
	CppUnit_addTest(pSuite, DHLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, DHLIBTEST, testClean);
	

	return pSuite;
}