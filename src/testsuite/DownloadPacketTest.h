#pragma once
#include "Poco/CppUnit/TestCase.h"
#include "DVR/DVRDownloadTask.h"
#include "DVR/DVRDownloadPacket.h"

using namespace DVR;

class DownloadPacketTest
	:public CppUnit::TestCase
{
public:
	DownloadPacketTest(const std::string& name);
	~DownloadPacketTest();

	void TestAddPacket();

	static CppUnit::Test* suite();

private:
	DVRDownloadPacket		_packet;
};

