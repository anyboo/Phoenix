#pragma once
#include <DuiLib/UIlib.h>


class CPlayWndUI :
	public WindowImplBase
{
public:
	CPlayWndUI();
	~CPlayWndUI();


	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};