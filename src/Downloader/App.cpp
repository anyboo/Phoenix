// App.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "MainWnd.h"
#include "resource.h"
#include "AppInitialize.h"
#include "ipset.h"
#include "InitNetConfig.h"
#include "log.h"

#include <io.h>
#include <fcntl.h>
static void OpenConsole()
{
	AllocConsole();
	HANDLE   handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int   hCrt = _open_osfhandle((long)handle, _O_TEXT);
	FILE   *   hf = _fdopen(hCrt, "w");
	*stdout = *hf;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

//#ifdef _DEBUG  
//	OpenConsole();
//#endif
//	CInitNetConfig Init;
	Loggering::Setup_logger();
	
	CAppInitialize appInit;
	std::auto_ptr<CMainWnd> pFrame(new CMainWnd);
	assert(pFrame.get());
	pFrame->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_ACCEPTFILES);
	pFrame->SetIcon(IDI_ICON1);
	pFrame->CenterWindow();
	pFrame->ShowWindow(true);

//	::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_HIDE);

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();

	return 0;
}


