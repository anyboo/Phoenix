#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "DZP/Utility.h"
#include <vector>

using namespace DVR::DZPLite;
using namespace std;


class DZPLIBTEST : public CppUnit::TestCase
{
public:
	DZPLIBTEST(const std::string& name);
	~DZPLIBTEST();

	void testInit();
	void testClean();

	void testLogin();
	void testLogout();

	void testFindfile();

	void testDownloadfilebyname();
	void testDownloadfilebytime();
	void testDownloadstop();
	void testDownloadgetpos();
	
	void testPlaybackbyname();
	void testPlaybackbytime();
	void testPlaybackstop();
	void testPlaybackgetpos();
	void testPlaybacksetpos();

	static CppUnit::Test* suite();
private:
	string _connectString;
	Utility::HANDLE _handle;
	long _channel;	
	long _downloadhandle;
	long _playhandle;	
	HWND _hwnd;

};

