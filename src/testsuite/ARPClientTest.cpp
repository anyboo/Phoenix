#include "ARPClientTest.h"
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/Net/NetWorkInterface.h>

using Poco::Net::NetworkInterface;

ARPClientTest::ARPClientTest(const std::string& rName) :
CppUnit::TestCase(rName)
{
}


ARPClientTest::~ARPClientTest()
{
}


void ARPClientTest::testTimeSync()
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
			assert(_arpClient.Request(strName));
		}
	}
}


CppUnit::Test* ARPClientTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ARPClientTest");

	CppUnit_addTest(pSuite, ARPClientTest, testTimeSync);

	return pSuite;
}
