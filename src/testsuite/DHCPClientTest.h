#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "Scene/DHCPClient.h"


class DHCPClientTest : public CppUnit::TestCase
{
public:
	DHCPClientTest(const std::string& name);
	~DHCPClientTest();

	void testTimeSync();

	static CppUnit::Test* suite();
private:
	DHCPClient _dhcpClient;
};
