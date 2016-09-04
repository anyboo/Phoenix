#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "Scene/ARPClient.h"


class ARPClientTest : public CppUnit::TestCase
{
public:
	ARPClientTest(const std::string& name);
	~ARPClientTest();

	void testTimeSync();

	static CppUnit::Test* suite();
private:
	ARPClient _arpClient;
};
