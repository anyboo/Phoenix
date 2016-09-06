#include "UtilityTest.h"
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/Net/SocketAddress.h>

using namespace DVR::DZPLite;

UtilityTest::UtilityTest(const std::string& name):
	CppUnit::TestCase(name),
	_connectString("192.168.0.32:34567"),
	_connectorName("DZP")
{
}


UtilityTest::~UtilityTest()
{
}

void UtilityTest::testloginout()
{
	Utility::HANDLE handle = 0;
	Poco::Net::SocketAddress addr(_connectString);
	Utility::DVRINFO info;
	handle  = Utility::login(addr, "admin", "", info);
	assert(handle > 0);
	int rc = Utility::logout(handle);
	assert(Utility::success == rc);
}

void UtilityTest::testInit()
{
	int rc = Utility::Init();
	assert(Utility::success == rc);
}

void UtilityTest::testCleanUp()
{
	int rc = Utility::CleanUp();
	assert(Utility::success == rc);
}

void UtilityTest::testsetTimeOut()
{
	int rc = Utility::setTimeOut(2000, 1);
	assert(Utility::success == rc);
}

void UtilityTest::testGetFile()
{
	/*Utility::FILEINFO fileinfo;
	fileinfo.ch = 2;
	
	const std::string& path("c:\\windows\\temp\\");
	int rc = Utility::GetFile(_handle, fileinfo, path);
	assert(Utility::success == rc);*/
}

void UtilityTest::testPlayback()
{

}

void UtilityTest::testFindFile()
{

}

void UtilityTest::setUp()
{

}

void UtilityTest::tearDown()
{

}

CppUnit::Test* UtilityTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("UtilityTest");

	CppUnit_addTest(pSuite, UtilityTest, testInit);
	CppUnit_addTest(pSuite, UtilityTest, testsetTimeOut);
	CppUnit_addTest(pSuite, UtilityTest, testloginout);
	CppUnit_addTest(pSuite, UtilityTest, testCleanUp);

	return pSuite;
}