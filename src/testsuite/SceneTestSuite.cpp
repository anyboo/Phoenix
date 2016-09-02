#include "SceneTestSuite.h"
#include "DHCPClientTest.h"
#include "ARPClientTest.h"

CppUnit::Test* SceneTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SceneTestSuite");

	pSuite->addTest(DHCPClientTest::suite());
	pSuite->addTest(ARPClientTest::suite());
	
	return pSuite;
}
