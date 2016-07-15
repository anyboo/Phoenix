#pragma once
#include <DuiLib/UIlib.h>


class CFileLogInfoUI :
	public WindowImplBase
{
public:
	CFileLogInfoUI();
	~CFileLogInfoUI();

	STDSTRING GetTime();

	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};