#pragma once
#include <DuiLib/UIlib.h>


class CPlayVideoWnd :
	public WindowImplBase
{
public:
	CPlayVideoWnd();
	~CPlayVideoWnd();


	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void GetPlayHwnd();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};