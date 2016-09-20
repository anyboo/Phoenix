#include "DownloadContainerTest.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

DownloadContainerTest::DownloadContainerTest(const std::string& rName)
:CppUnit::TestCase(rName)
{
}


DownloadContainerTest::~DownloadContainerTest()
{
}

void DownloadContainerTest::TestAddPacket()
{

}

void DownloadContainerTest::TestNewAddTaskPacket()
{
	
}

void DownloadContainerTest::TestDeletePacket()
{
	
}

void DownloadContainerTest::TestDeleteTaskByName()
{

}

void DownloadContainerTest::TestGetPacket()
{
}

CppUnit::Test* DownloadContainerTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DownloadContainerTest");

	CppUnit_addTest(pSuite, DownloadContainerTest, TestAddPacket);
	CppUnit_addTest(pSuite, DownloadContainerTest, TestGetPacket);
	CppUnit_addTest(pSuite, DownloadContainerTest, TestNewAddTaskPacket);
	CppUnit_addTest(pSuite, DownloadContainerTest, TestDeleteTaskByName);
	CppUnit_addTest(pSuite, DownloadContainerTest, TestDeletePacket);
	CppUnit_addTest(pSuite, DownloadContainerTest, TestDeleteTaskByName);
	
	return pSuite;
}
