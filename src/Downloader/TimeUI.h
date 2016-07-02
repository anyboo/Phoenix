#pragma once
#include <DuiLib/UIlib.h>


class CTimeUI :
	public WindowImplBase
{
public:
	CTimeUI();
	~CTimeUI();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
private:
	int				m_Site;

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};