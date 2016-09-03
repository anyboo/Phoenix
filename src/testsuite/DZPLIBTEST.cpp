#include "DZPLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"


DZPLIBTEST::DZPLIBTEST(const std::string& name) : CppUnit::TestCase(name)
{

}

DZPLIBTEST::~DZPLIBTEST()
{
}

void DZPLIBTEST::testConnect()
{
	DVR::DZPLite::DVRConnector connect;
}

void DZPLIBTEST::testSession()
{
	std::cout << "test Session" << std::endl;
	int i = 0;
	assert(i == 0);
}

CppUnit::Test* DZPLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DZPLIBTEST");

	CppUnit_addTest(pSuite, DZPLIBTEST, testSession);

	return pSuite;
}