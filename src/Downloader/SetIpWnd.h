#pragma once
#include <DuiLib/UIlib.h>


class CSetIpWnd :
	public WindowImplBase
{
public:
	CSetIpWnd();
	~CSetIpWnd();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void EditInput(STDSTRING& SendName);

	void AddIP_Address();

	void InsertList(STDSTRING& strIP, STDSTRING& strSubNet, STDSTRING& strGateWay);
	void RemoveSubList();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};