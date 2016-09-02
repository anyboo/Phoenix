#include "DHCPClientTest.h"
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/Net/NetWorkInterface.h>

using Poco::Net::NetworkInterface;

DHCPClientTest::DHCPClientTest(const std::string& rName) :
CppUnit::TestCase(rName)
{
}


DHCPClientTest::~DHCPClientTest()
{
}


void DHCPClientTest::testTimeSync()
{
	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& intf = it->second;
		NetworkInterface::Type networkType = intf.type();

		if (networkType == intf.NI_TYPE_ETHERNET_CSMACD && intf.isUp())
		{
			std::string strName = intf.name();
			assert(_dhcpClient.Request(strName));
		}
	}
}


CppUnit::Test* DHCPClientTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DHCPClientTest");

	CppUnit_addTest(pSuite, DHCPClientTest, testTimeSync);

	return pSuite;
}
