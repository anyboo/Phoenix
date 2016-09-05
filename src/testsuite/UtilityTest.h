#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "DZP/Utility.h"

#include <list>

class UtilityTest : public CppUnit::TestCase
{
public:
	UtilityTest(const std::string& name);
	~UtilityTest();

	void testloginout();
	void testInit();
	void testCleanUp();
	void testsetTimeOut();
	void testGetFile();
	void testPlayback();
	void testFindFile();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	std::string _connectString;
	std::string _connectorName;
};

