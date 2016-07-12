#pragma once
#include <DuiLib/UIlib.h>

#define BT_VideoVendor			(_T("Vendor"))
#define BT_LOGIN				(_T("LogIn"))

enum ISLogIn
{
	LogInDevice,
	NoLogDevice
};

class VideoLoginUI :
	public WindowImplBase
{
public:
	VideoLoginUI();
	~VideoLoginUI();

	void LogIn();
	Device* GetLonInDevice();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnOpenVideoVendorWnd(TNotifyUI& msg);
	void OnShowDeviceInfo(STDSTRING& SendName);
	void OnShowDevice(int pages);

	void GetNextPage();
	void GetPrevPage();

	void ShowPagesLable(int page);


private:
	BOOL	m_Init;
	DEVICE_INFO_LIST		m_DeviceList;
	ISLogIn			m_IsLogIn;
	Device*					m_Device;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};