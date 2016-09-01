#include "ARPClientTest.h"
#include <Poco/CppUnit/TestCaller.h>
#include <Poco/CppUnit/TestSuite.h>
#include <Poco/Net/NetWorkInterface.h>


ARPClientTest::ARPClientTest(const std::string& rName) :
CppUnit::TestCase(rName)
{
}


ARPClientTest::~ARPClientTest()
{
}


void ARPClientTest::testTimeSync()
{
	assert(_arpClient.Request(std::string("local")));
}


CppUnit::Test* ARPClientTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ARPClientTest");

	CppUnit_addTest(pSuite, ARPClientTest, testTimeSync);

	return pSuite;
}
