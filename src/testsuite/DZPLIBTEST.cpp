#include "DZPLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"



DZPLIBTEST::DZPLIBTEST(const std::string& name) 
	: CppUnit::TestCase(name),
	_connectString("192.168.0.32:34567"),
	_handle(0),
	_downloadhandle(0),
	_playhandle(0)
{

}

DZPLIBTEST::~DZPLIBTEST()
{
}

void DZPLIBTEST::testInit()
{
	int ret = Utility::Init();
	assert(ret == Utility::success);
}

void DZPLIBTEST::testClean()
{
	assert(Utility::CleanUp() == Utility::success);
}

void DZPLIBTEST::testLogin()
{
	Utility::DVRINFO info = { 0 };
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "", info);
	
	cout << "testLogin _handle: " << _handle << endl;
	_channel = info.nTotalChannel;
	assert(_handle > 0); 	
}


void DZPLIBTEST::testLogout()
{
	testLogin();
	cout << "_handle: " << _handle << endl;
	assert(_handle > 0);	
	assert(Utility::logout(_handle) > 0);
}

CppUnit::Test* DZPLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DZPLIBTEST");
	
	CppUnit_addTest(pSuite, DZPLIBTEST, testInit);
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogin);	
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogout);
	CppUnit_addTest(pSuite, DZPLIBTEST, testClean);

	return pSuite;
}