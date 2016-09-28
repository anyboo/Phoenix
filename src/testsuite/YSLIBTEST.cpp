
#include "YSLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"

YSLIBTEST::YSLIBTEST(const std::string& name)
	: CppUnit::TestCase(name),
	_connectString("10.168.0.88:0"),
	_handle(0),
	_channel(0)
{
	
}

YSLIBTEST::~YSLIBTEST()
{
}

void YSLIBTEST::testInit()
{
	cout << "YS test start" << endl;
	Utility::Init();
}

void YSLIBTEST::testClean()
{
	Utility::Cleanup();
	cout << "YS test end" << endl;
}

void YSLIBTEST::testLogin()
{	
	Poco::Net::SocketAddress addr(_connectString);
	_handle = Utility::login(addr, "admin", "admin");

	cout << "testLogin _handle: " << _handle << endl;
	DeviceInfo info = { 0 };
	Utility::readDeviceInfo(info);
	_channel = info.dwChannelNum;
	cout << "channel: " << _channel << endl;
	assert(_handle > 0);
	assert(_channel > 0);
}

void YSLIBTEST::testLogout()
{
	testLogin();
	cout << "testlogout _handle: " << _handle << endl;
	assert(_handle > 0);
	assert(Utility::logout(_handle) > 0);
}

void YSLIBTEST::testFindfile()
{	
	testLogin();
	int count = 0;
	cout << "testFindfile _handle: " << _handle << endl;	
	Condition cond = { 0 };
	cond.dwChannelID = 4; //通道
	cond.tEndTime = _time64(NULL); //开始时间
	cond.tBeginTime = time(NULL) - 24 * 3600 * 60;	 //结束时间
	
	LPVOID dwFileHandle = 0;
	dwFileHandle = Utility::findStream(_handle, cond);
	assert(dwFileHandle > 0);

	if (dwFileHandle > 0)
	{
		Record rd = { 0 };
		while (Utility::findNextStream(dwFileHandle, rd))
		{
			cout << rd.szFileName << endl;
			count++;
		}

		cout << "count: " << count << endl;
		Utility::closeFindStream(dwFileHandle);
	}	

	assert(count > 0);
} 

void YSLIBTEST::testDownload()
{
	testLogin();

	Condition cond = { 0 };
	cond.dwChannelID = 4; //通道
	cond.tEndTime = _time64(NULL); //开始时间
	cond.tBeginTime = time(NULL) - 24 * 3600 * 60;	 //结束时间

	LPVOID dwFileHandle = 0;
	dwFileHandle = Utility::findStream(_handle, cond);
	assert(dwFileHandle > 0);

	if (dwFileHandle > 0)
	{
		Record rd = { 0 };
		if (Utility::findNextStream(dwFileHandle, rd))
		{
			cout << rd.szFileName << endl;
			NETDEV_PLAYBACKINFO_S stPlayBackInfo = { 0 };
			strncpy(stPlayBackInfo.szName, rd.szFileName, NETDEV_FILE_NAME_LEN - 1);
			stPlayBackInfo.tBeginTime = rd.tBeginTime;
			stPlayBackInfo.tEndTime = rd.tEndTime;
			Utility::FileHandle fHandle = Utility::readStream(_handle, stPlayBackInfo, "D:\\DownLoadVideo\\ys1.mp4");
			if (fHandle == NULL)
			{
				NETDEV_PLAYBACKCOND_S stPlayInfo = { 0 };
				stPlayInfo.dwChannelID = cond.dwChannelID;
				stPlayInfo.tBeginTime = rd.tBeginTime;
				stPlayInfo.tEndTime = rd.tEndTime;
			}
			Sleep(1000 * 60 * 3);			
		}

		
		Utility::closeFindStream(dwFileHandle);
	}
}

CppUnit::Test* YSLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("YSLIBTEST");
	
	CppUnit_addTest(pSuite, YSLIBTEST, testInit);
	CppUnit_addTest(pSuite, YSLIBTEST, testLogin);	
	CppUnit_addTest(pSuite, YSLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, YSLIBTEST, testDownload);
	CppUnit_addTest(pSuite, YSLIBTEST, testLogout);
	CppUnit_addTest(pSuite, YSLIBTEST, testClean);
	

	return pSuite;
}