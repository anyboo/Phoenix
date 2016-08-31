#include "SceneTestSuite.h"
#include "DHCPClientTest.h"

CppUnit::Test* SceneTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SceneTestSuite");

	pSuite->addTest(DHCPClientTest::suite());

	return pSuite;
}
