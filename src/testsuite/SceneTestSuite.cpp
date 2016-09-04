#include "SceneTestSuite.h"
#include "DHCPClientTest.h"

#include "ARPClientTest.h"

#include "DZPLIBTEST.h"


CppUnit::Test* SceneTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SceneTestSuite");

	pSuite->addTest(DHCPClientTest::suite());

	pSuite->addTest(ARPClientTest::suite());
	

	pSuite->addTest(DZPLIBTEST::suite());


	return pSuite;
}
