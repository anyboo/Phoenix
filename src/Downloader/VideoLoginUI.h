#pragma once
#include <DuiLib/UIlib.h>

#include "QMSqlite.h"

class CNotificationNetworkStatus;

#define BT_VideoVendor			(_T("select_Vendor"))
#define BT_LOGIN				(_T("LogIn"))
#define BT_PREVPAGE				(_T("Prev_page"))
#define BT_NEXTPAGE				(_T("Next_page"))
#define BT_CLOSELOGWND				(_T("closebtn"))

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
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnLogIn(TNotifyUI& msg);
	void OnPrevPage(TNotifyUI& msg);
	void OnNextPage(TNotifyUI& msg);
	void OnClose(TNotifyUI& msg);

	void OnOpenVideoVendorWnd(TNotifyUI& msg);
	void OnShowDeviceInfo(STDSTRING& SendName);
	void OnShowDevice(int pages);

	void GetNextPage();
	void GetPrevPage();

	void ShowPagesLable(int page);

	void CountDevice();

	void InsertVendorToDB();
	void SearchVendorList();
	void InsertVendorToList();

	void CreateSubvLyt();

	void SetNetWorkState(NOTIFICATION_TYPE& eNotify);
	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);
private:
	DEVICE_INFO_LIST		m_DeviceList;
	ISLogIn			m_IsLogIn;
	Device*					m_Device;
	bool			m_Init;
	size_t						m_page_Count;
	size_t				m_pages;
	QMSqlite*				m_pDb;
	std::vector<string> m_sRecord;
	std::map<int, string>		m_CnameAndType;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};