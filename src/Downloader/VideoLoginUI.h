#pragma once
#include <DuiLib/UIlib.h>

#define BT_VideoVendor			(_T("Vendor"))

class VideoLoginUI :
	public WindowImplBase
{
public:
	VideoLoginUI();
	~VideoLoginUI();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnOpenVideoVendorWnd(TNotifyUI& msg);

	void OnShowDevice(int pages);

private:
	BOOL	m_Init;
	DEVICE_INFO_LIST		m_DeviceList;

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};