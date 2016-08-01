#pragma once
/*
The test window can be deleted in the project later
*/

#include <Windows.h>


class TestWindows
{
public:
	TestWindows();
	~TestWindows();

	static TestWindows& getInstance();
	void Init();

	ATOM MyRegisterClass();
	BOOL InitInstance();

	HWND GetHWnd(){ return m_hWnd; }

private:
	HWND m_hWnd;
	HINSTANCE m_hInst;
};

