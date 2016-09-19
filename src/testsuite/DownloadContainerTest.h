#pragma once
#include "Poco/CppUnit/TestCase.h"
#include "DVR/DVRDownloadTask.h"
#include "DVR/DVRDownloadPacket.h"

using namespace DVR;

class DownloadContainerTest
	:public CppUnit::TestCase
{
public:
	DownloadContainerTest(const std::string& name);
	~DownloadContainerTest();

	void TestAddPacket();
	void TestDeletePacket();
	void TestDeleteTaskByName();
	void TestNewAddTaskPacket();
	void TestGetPacket();

	static CppUnit::Test* suite();

private:
	DVRDownloadPacket		_packet_container;
};

