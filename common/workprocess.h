#pragma once

#include <client\windows\common\ipc_protocol.h>


namespace WorkProcess
{
	static int kCustomInfoCount = 2;
	static google_breakpad::CustomInfoEntry kCustomInfoEntries[] = {
		google_breakpad::CustomInfoEntry(L"prod", L"CrashTestApp"),
		google_breakpad::CustomInfoEntry(L"ver", L"1.0"),
	};

	std::wstring GetGUIDStr();
	void AddExceptionCatch();
	int WorkProcessMain(_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPTSTR    lpCmdLine,
		_In_ int       nCmdShow);	
	void StartServerExe();
	int appinit(_In_ HINSTANCE hInstance);

	// 此代码模块中包含的函数的前向声明: 
	ATOM				MyRegisterClass(HINSTANCE hInstance);
	BOOL				InitInstance(HINSTANCE, int);
	LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
	INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
}