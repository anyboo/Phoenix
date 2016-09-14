#pragma once
#include <Poco/CppUnit/TestCase.h>
#include <DVR/DVRDeviceContainer.h>

class DeviceContainerTest : public CppUnit::TestCase
{
protected:
	DVR::DVRDeviceContainer _container;
public:
	DeviceContainerTest(const std::string& name);
	~DeviceContainerTest();
protected:
	void setUp();
	void tearDown();
	void testAdd();
	void testRemove();
	void testHas();
	void testGet();
	void testCount();
};

