#include "UtilityTest.h"
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/Net/SocketAddress.h>
#include <DZP/Utility.h>
#include "DZP/netsdk.h"

using namespace DVR::DZPLite;
Utility::HANDLE UtilityTest::_handle = 0;;
bool UtilityTest::_logined = false;
UtilityTest::UtilityTest(const std::string& name):
	CppUnit::TestCase(name),
	_connectString("192.168.0.32:34567"),
	_connectorName("DZP")
{
}


UtilityTest::~UtilityTest()
{
	testlogout();
}

void UtilityTest::testlogin()
{
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "");
	assert(_handle > 0);
	if (_handle > 0) _logined = true;
}

void UtilityTest::testlogout()
{
	if (!_logined) return;
	bool rc = Utility::logout(_handle);
	assert(rc);
}

void UtilityTest::testInit()
{
	Utility::Init();
}

void UtilityTest::testCleanUp()
{
	Utility::Cleanup();
}

void UtilityTest::testsetTimeOut()
{
	//Utility::setTimeOut(3000, 3);
}

void UtilityTest::testGetFile()
{
	/*Record data;
	bool rc = readStream(_handle, data, "D:\\test\\kkk22.avi");*/
}

void UtilityTest::testPlayback()
{

}

void UtilityTest::testFindFile()
{
	Record record[100];

	H264_DVR_TIME startTime, endTime;
	startTime.dwYear = 2016;
	startTime.dwMonth = 9;
	startTime.dwDay = 1;
	startTime.dwHour = 0;
	startTime.dwMinute = 0;
	startTime.dwSecond = 0;
	
	endTime.dwYear = 2016;
	endTime.dwMonth = 9;
	endTime.dwDay = 9;
	endTime.dwHour = 12;
	endTime.dwMinute = 10;
	endTime.dwSecond = 23;

	Condition cond;
	cond.nChannelN0 = 0;
	cond.nFileType = SDK_File_Type::SDK_RECORD_ALL;
	cond.startTime = startTime;
	cond.endTime = endTime;
	cond.hWnd = 0;
	memset(cond.szFileName, 0, 32);

	int count = 0;

	size_t findcount = Utility::findStream(_handle, cond, record[0], 100);
	assert(findcount >= 0);
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
	CppUnit_addTest(pSuite, UtilityTest, testlogin);
	CppUnit_addTest(pSuite, UtilityTest, testFindFile);
	CppUnit_addTest(pSuite, UtilityTest, testGetFile);
	CppUnit_addTest(pSuite, UtilityTest, testPlayback);
	CppUnit_addTest(pSuite, UtilityTest, testlogout);
	CppUnit_addTest(pSuite, UtilityTest, testCleanUp);

	return pSuite;
}