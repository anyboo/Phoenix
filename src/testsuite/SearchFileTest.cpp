#include "SearchFileTest.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

SearchFileTest::SearchFileTest(const std::string& rName)
:CppUnit::TestCase(rName)
{
}


SearchFileTest::~SearchFileTest()
{
}

void SearchFileTest::TestGetSearchFiles()
{
	//DVRSearchFiles seach;
	//std::vector<Search_fileInfo>	files;
	//seach.GetSeachFilesInfo(files);
	//assert(files.size() > 0);
}

void SearchFileTest::TestGetFileByName()
{
	/*DVRSearchFiles seach;
	Search_fileInfo file;
	seach.GetFileInfoByName(std::string("filename2"), file);
	assert(!file.fname.empty());*/
}

CppUnit::Test* SearchFileTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SearchFileTest");

	CppUnit_addTest(pSuite, SearchFileTest, TestGetSearchFiles);

	return pSuite;
}

