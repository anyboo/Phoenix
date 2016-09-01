
#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include <sstream>

#define BT_CloseVwnd			(_T("close_btn"))

enum Select
{
	GetDeviceName,
	GetNothing
};

class CVideoVendorUI :
	public WindowImplBase
{
public:
	CVideoVendorUI();
	~CVideoVendorUI();
	STDSTRING GetVendorName();

	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCloseWnd(TNotifyUI& msg);

private:
	STDSTRING m_VendorName;
	Select		m_IsGetVendorName;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
