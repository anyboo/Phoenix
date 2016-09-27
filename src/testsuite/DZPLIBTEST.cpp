#include "DZPLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"
#include "DZP/DVRStatementImpl.h"
#include "DZP/DVRSessionImpl.h"


DZPLIBTEST::DZPLIBTEST(const std::string& name) 
	: CppUnit::TestCase(name),
	_connectString("192.168.0.32:34567"),
	_handle(0),
	_downloadhandle(0),
	_playhandle(0),
	_hwnd(0)
{

}

DZPLIBTEST::~DZPLIBTEST()
{
}

void DZPLIBTEST::testInit()
{
	int ret = Utility::Init();
	assert(ret == Utility::success);
}

void DZPLIBTEST::testClean()
{
	assert(Utility::CleanUp() == Utility::success);
}

void DZPLIBTEST::testLogin()
{
	Utility::Init();
	Utility::DVRINFO info = { 0 };
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "", info);

	cout << "testLogin _handle: " << _handle << endl;
	_channel = info.nTotalChannel;
	assert(_handle > 0); 	
	assert(_channel > 0);
}


void DZPLIBTEST::testLogout()
{
	testLogin();
	cout << "testlogout _handle: " << _handle << endl;
	assert(_handle > 0);	
	assert(Utility::logout(_handle) > 0);
}

void DZPLIBTEST::testFindfile()
{
	testLogin();
	cout << "testFindfile _handle: " << _handle << endl;

	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
}


void DZPLIBTEST::testDownloadfilebyname()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	
	Utility::FILEINFO	file_info = { 0 };
	std::string Path("D:\\");
	int rc = Utility::GetFile(_handle, file_info, Path);
	assert(rc == Utility::success);

	/*	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
		DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
		stateImpl.donwloadByName(time1.sFileName);*/
}

void DZPLIBTEST::testDownloadfilebytime()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);

	std::string path("D:\\");
	int rc = Utility::GetFile(_handle, time1, path, false);
	assert(rc == Utility::success);

	//DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	//DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	//Poco::DateTime Dtime;
	//stateImpl.downloadByTime(Dtime);
}

void DZPLIBTEST::testDownloadgetpos()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	stateImpl.donwloadByName(time1.sFileName);

	int iRet = Utility::getDownloadPos(_downloadhandle);
}

void DZPLIBTEST::testDownloadstop()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	stateImpl.donwloadByName(time1.sFileName);
}

void DZPLIBTEST::testPlaybackbyname()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	stateImpl.playByName(time1.sFileName);
}

void DZPLIBTEST::testPlaybackbytime()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	Poco::DateTime Dtime;
	stateImpl.playByTime(Dtime);
}

void DZPLIBTEST::testPlaybackgetpos()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	stateImpl.playByName(time1.sFileName);

	int pos = 0;
	Utility::getPlaybackPos(_playhandle, &pos);
}

void DZPLIBTEST::testPlaybacksetpos()
{
	testLogin();
	Utility::TIMEINFO time1 = { 0 };
	time1.ch = 1;

	time1.stEndTime = _time64(NULL);
	struct tm *ptm = _localtime64(&time1.stEndTime);
	ptm->tm_mday--;
	time1.stBeginTime = _mktime64(ptm);
	int count = Utility::FindFile(_handle, time1, 5000);
	assert(count > 0);
	DVR::DZPLite::DVRSessionImpl sessionImpl(_connectString);
	DVR::DZPLite::DVRStatementImpl stateImpl(sessionImpl, _handle);
	stateImpl.playByName(time1.sFileName);

	int pos = 0;
	Utility::setPlaybackPos(_playhandle, pos);
}


CppUnit::Test* DZPLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DZPLIBTEST");	
	
	CppUnit_addTest(pSuite, DZPLIBTEST, testInit);
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogin);	
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogout);
	CppUnit_addTest(pSuite, DZPLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, DZPLIBTEST, testClean);
	CppUnit_addTest(pSuite, DZPLIBTEST, testDownloadfilebyname);
	CppUnit_addTest(pSuite, DZPLIBTEST, testDownloadfilebytime);
	CppUnit_addTest(pSuite, DZPLIBTEST, testDownloadgetpos);
	CppUnit_addTest(pSuite, DZPLIBTEST, testDownloadstop);
	CppUnit_addTest(pSuite, DZPLIBTEST, testPlaybackbyname);
	CppUnit_addTest(pSuite, DZPLIBTEST, testPlaybackbytime);
	CppUnit_addTest(pSuite, DZPLIBTEST, testPlaybackgetpos);
	CppUnit_addTest(pSuite, DZPLIBTEST, testPlaybacksetpos);


	return pSuite;
}