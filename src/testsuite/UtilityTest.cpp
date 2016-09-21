#include "UtilityTest.h"
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/Net/SocketAddress.h>
#include <DZP/Utility.h>
#include "DZP/netsdk.h"
#include <Poco/Thread.h>
#include <Poco/Event.h>

using namespace DVR::DZPLite;
Utility::HANDLE UtilityTest::_handle = 0;;
bool UtilityTest::_logined = false;
Record* UtilityTest::_pRecord = nullptr;
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
	std::cout << _handle << std::endl;
}

void UtilityTest::testlogout()
{
	if (!_logined) return;
	bool rc = Utility::logout(_handle);
	assert(rc);
	_logined = false;
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
	Utility::setTimeOut(5000, 3);
}

void UtilityTest::testGetFile()
{
	assertNotNullPtr(_pRecord);
	std::cout << "start download file..." << std::endl;
	Utility::FileHandle file = Utility::readStream(_handle, _pRecord[1], "D:\\test\\kkk32.avi");
	if (file > 0)
	{
		int pos = 0;
		do
		{
			pos = Utility::readStreamPos(file);
			std::cout << "downloading process : " << pos << std::endl;
			Poco::Thread::sleep(1 * 1000);
		} while (pos >= 0 && pos < 100);
	}
	bool rc = Utility::closeStream(file);
	std::cout << "download file finished!" << "close Stream status : " << rc << std::endl;
}

void UtilityTest::testPlayback()
{
	_pRecord[0].hWnd = ::GetDesktopWindow();
	Utility::PlayHandle play = Utility::playStream(_handle, _pRecord[0]);
	if (play > 0)
	{
		std::cout << "start playback file ..." << play << std::endl;
		float pos = 0;
		bool doneA = false;
		bool doneB = false;
		do
		{
			pos = Utility::playPos(play);
			Poco::Thread::sleep(1 * 1000);
			std::cout << "play pos : " << pos << std::endl;
			
			if (pos > 10 && !doneA)
			{
				bool rc = Utility::seek(play, 30);
				doneA = rc;
				std::cout << "seek 50% status : " << rc << std::endl;
			}
			
			if (pos > 50 && !doneB)
			{
				bool rc = Utility::pause(play);
				std::cout << "pause status : " << rc << std::endl;
				Poco::Thread::sleep(10 * 1000);
				rc = Utility::play(play);
				std::cout << "play status : " << rc << std::endl;
				doneB = rc;
			}
		} while (pos >= 0 && pos < 100);
	}
	bool rc = Utility::stopStream(play);
	std::cout << "stop play status : " << rc << std::endl;
}

void UtilityTest::testFindFile()
{
	_pRecord = new Record[100];

	H264_DVR_TIME startTime, endTime;
	startTime.dwYear = 2016;
	startTime.dwMonth = 8;
	startTime.dwDay = 1;
	startTime.dwHour = 0;
	startTime.dwMinute = 0;
	startTime.dwSecond = 0;
	
	endTime.dwYear = 2016;
	endTime.dwMonth = 9;
	endTime.dwDay = 21;
	endTime.dwHour = 12;
	endTime.dwMinute = 10;
	endTime.dwSecond = 23;

	Condition cond;
	cond.nChannelN0 = 1;
	cond.nFileType = SDK_File_Type::SDK_RECORD_ALL;
	cond.startTime = startTime;
	cond.endTime = endTime;
	cond.hWnd = 0;
	memset(cond.szFileName, 0, 32);

	int count = 0;
	assertNotNullPtr(_pRecord);
	std::cout << _handle << std::endl;

	size_t findcount = Utility::findStream(_handle, cond, *_pRecord, 100);
	std::cout << findcount << std::endl;
	assert(findcount >= 0);
	std::cout << "findstream by name" << std::endl;
	
	for (int i = 0; i < findcount; i++)
	{
		std::cout << _pRecord[i].ch << _pRecord[i].sFileName
			<< _pRecord[i].size << std::endl;
	}
	std::cout << "find file finished!" << std::endl;
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
//	CppUnit_addTest(pSuite, UtilityTest, testGetFile);
//	CppUnit_addTest(pSuite, UtilityTest, testPlayback);
	CppUnit_addTest(pSuite, UtilityTest, testlogout);
//	CppUnit_addTest(pSuite, UtilityTest, testCleanUp);

	return pSuite;
}