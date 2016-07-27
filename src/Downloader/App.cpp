// App.cpp : Defines the entry point for the application.
//
#include "stdafx.h"

#include "cmdline_parse.h"
#include "guardprocess.h"
#include "workprocess.h"

static VENDOR_LIST pVendorList;

void HideTaskBar()
{
	LPARAM lParam;
	lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;
	HWND task = FindWindow(_T("Shell_TrayWnd"), NULL);
	::ShowWindow(task, SW_HIDE);

	APPBARDATA apBar;
	memset(&apBar, 0, sizeof(apBar));
	apBar.cbSize = sizeof(apBar);
	apBar.hWnd = task;
	if (apBar.hWnd != NULL)
	{
		apBar.lParam = lParam;
		SHAppBarMessage(ABM_SETSTATE, &apBar);
	}
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	string strCmdLine(lpCmdLine);
	wstring wsCmdLine(strCmdLine.begin(), strCmdLine.end());
	
	CmdlineParser cmd_parse(wsCmdLine);
	std::wstring server_start_event_name = cmd_parse.GetValueByKey(L"crash_server");
	if (!server_start_event_name.empty())
	{
		GuardProcess::GuardProcessMain(server_start_event_name);
		return 0;
	}
	else
	{
		WorkProcess::WorkProcessMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
		return 0;
	}

	return 0;
}


