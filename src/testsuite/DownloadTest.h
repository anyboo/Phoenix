#pragma once
#include "Poco/CppUnit/TestCase.h"
#include "DVR/DVRDownloadTask.h"
#include "DZP/Utility.h"

using namespace DVR;

class DownloadTest:
	public CppUnit::TestCase
{
public:
	DownloadTest(const std::string& name);
	~DownloadTest();

	void TestGetDownloadPacket();
	void TestDeleteTaskByName();
	void TestDeleteDownloadTask();

	static CppUnit::Test* suite();
};

