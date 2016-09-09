#pragma once
#include "Poco/CppUnit/TestCase.h"
#include "DVR/DVRSearchFiles.h"

using namespace DVR;

class SearchFileTest
	:public CppUnit::TestCase
{
public:
	SearchFileTest(const std::string& name);
	~SearchFileTest();

	void TestGetSearchFiles();

	void TestGetFileByName();

	static CppUnit::Test* suite();
};

