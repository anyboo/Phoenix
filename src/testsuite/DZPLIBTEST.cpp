#include "DZPLIBTEST.h"
#include "Poco/CppUnit/TestCaller.h"
#include "Poco/CppUnit/TestSuite.h"



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

//message proc  
LRESULT CALLBACK WindowProc(
	_In_  HWND hwnd,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
	)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

HWND DZPLIBTEST::createHwnd()
{
	HINSTANCE hInstance;
	hInstance = GetModuleHandle(NULL);
	WNDCLASS Draw;
	Draw.cbClsExtra = 0;
	Draw.cbWndExtra = 0;
	Draw.hCursor = LoadCursor(hInstance, IDC_ARROW);;
	Draw.hIcon = LoadIcon(hInstance, IDI_APPLICATION);;
	Draw.lpszMenuName = NULL;
	Draw.style = CS_HREDRAW | CS_VREDRAW;
	Draw.hbrBackground = (HBRUSH)COLOR_WINDOW;
	Draw.lpfnWndProc = WindowProc;
	Draw.lpszClassName = ("DDraw");
	Draw.hInstance = hInstance;


	RegisterClass(&Draw);

	HWND hwnd = CreateWindow(
		("DDraw"),           //class name    
		"PLAY",				 //window title  
		WS_OVERLAPPEDWINDOW, //window style    
		150,				 //X points    
		50,                  //Y points    
		640,                 //window width    
		480,                 //window height   
		NULL,                //no parent window is NULL    
		NULL,                //no menu is NULL    
		hInstance,           // process  handle 
		NULL);               //    

	
	//show window 
	ShowWindow(hwnd, SW_SHOW);

	//update window    
	UpdateWindow(hwnd);

	// message loop    
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return hwnd;
}


void DZPLIBTEST::testDownloadfilebyname()
{

}

void DZPLIBTEST::testDownloadfilebytime()
{

}

void DZPLIBTEST::testDownloadgetpos()
{

}

void DZPLIBTEST::testDownloadstop()
{
}

void DZPLIBTEST::testPlaybackbyname()
{
	_hwnd = createHwnd();
}

void DZPLIBTEST::testPlaybackbytime()
{

}

void DZPLIBTEST::testPlaybackgetpos()
{

}

void DZPLIBTEST::testPlaybacksetpos()
{

}


CppUnit::Test* DZPLIBTEST::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DZPLIBTEST");	
	
	CppUnit_addTest(pSuite, DZPLIBTEST, testInit);
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogin);	
	CppUnit_addTest(pSuite, DZPLIBTEST, testLogout);
	CppUnit_addTest(pSuite, DZPLIBTEST, testFindfile);
	CppUnit_addTest(pSuite, DZPLIBTEST, testClean);
	CppUnit_addTest(pSuite, DZPLIBTEST, testPlaybackbyname);

	return pSuite;
}