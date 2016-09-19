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
	/*std::cout << "DownloadTest Begin: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		DVRDownloadTask* packet = new DVRDownloadTask;
		_packet_container.AddTaskPacket(packet);
	}*/
}

void DownloadContainerTest::TestNewAddTaskPacket()
{
	//for (int i = 0; i < 4; i++)
	//{
	//	DVRDownloadTask* packet = new DVRDownloadTask;
	//	_packet_container.AddTaskPacket(packet);
	//}
	//std::string strName = _packet_container.GetNewAddTaskID();
	//assert(!strName.empty());
}

void DownloadContainerTest::TestDeletePacket()
{
	//for (int i = 0; i < 4; i++)
	//{
	//	DVRDownloadTask* packet = new DVRDownloadTask;
	//	_packet_container.AddTaskPacket(packet);
	//}
	//std::string strName = _packet_container.GetNewAddTaskID();
	//bool bRet = _packet_container.DeleteTaskPacket(strName);
	//assert(bRet);
}

void DownloadContainerTest::TestDeleteTaskByName()
{
	//for (int i = 0; i < 4; i++)
	//{
	//	DVRDownloadTask* packet = new DVRDownloadTask;
	//	_packet_container.AddTaskPacket(packet);
	//}
	//std::string strName = _packet_container.GetNewAddTaskID();
	//bool bRet = _packet_container.DeleteSubTask(strName, std::string("task2"));
	//assert(bRet);
}

void DownloadContainerTest::TestGetPacket()
{
	//for (int i = 0; i < 4; i++)
	//{
	//	DVRDownloadTask* packet = new DVRDownloadTask;
	//	_packet_container.AddTaskPacket(packet);
	//}
	//std::string strName = _packet_container.GetNewAddTaskID();
	//DVRDownloadTask* packet = _packet_container.GetTaskPacketByName(strName);
	//assert(packet != nullptr);
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
