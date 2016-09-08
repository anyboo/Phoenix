#include "DownloadTest.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

DownloadTest::DownloadTest(const std::string& rName) :
CppUnit::TestCase(rName)
{
}


DownloadTest::~DownloadTest()
{
}

void DownloadTest::TestGetDownloadPacket()
{
	std::cout << "DownloadTest Begin: "  << std::endl;
	std::vector<Download_packet> packet;
	DVRDownloadTask download;
	download.GetDownloadPacketInfo(packet);
	assert(packet.size() > 0);
}

void DownloadTest::TestDeleteTaskByName()
{
	std::string testName("task2");
	DVRDownloadTask download;
	bool bRet = download.DeleteTaskByName(testName);
	assert(bRet);
}

void DownloadTest::TestDeleteDownloadTask()
{
	DVRDownloadTask download;
	bool bRet = download.DeleteWholeTask();
	assert(bRet);
}

CppUnit::Test* DownloadTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DownloadTest");

	CppUnit_addTest(pSuite, DownloadTest, TestGetDownloadPacket);
	CppUnit_addTest(pSuite, DownloadTest, TestDeleteTaskByName);
	CppUnit_addTest(pSuite, DownloadTest, TestDeleteDownloadTask);

	return pSuite;
}
