#include "stdafx.h"
#include "MainWnd.h"
#include "DownLoadWnd.h"
#include "LogUI.h"
#include "VideoLoginUI.h"
#include "OtherTools.h"
#include "SetIpWnd.h"
#include "OVPlayerUI.h"
#include "MenuWnd.h"

#include "portscan.h"
#include "QMFileSqlite.h"
#include "QMSqlite.h"

#include "SearchDevice.h"
#include "DeviceManager.h"

#include "JXJVendor.h"
#include "DZPVendor.h"
#include "DHVendor.h"
#include "HKVendor.h"

#include <fstream>

#include <Poco/NotificationCenter.h>
#include "Poco/Observer.h"

#include "MessagePump.h"

using Poco::NotificationCenter;
using Poco::Observer;

static VENDOR_LIST pVendorList;

//extern NotificationQueue queuePortScan;
//extern NotificationQueue queueSearchDevice;

void  CheckDB()
{
	fstream _file;
	_file.open("phoenix.db", ios::in);
	if (!_file)
	{
		QFileSqlite *pFileDb = QFileSqlite::getInstance();
		pFileDb->dropTable(DROP_LOGIN_DEVICE_INFO_TABLE);
		pFileDb->createTable(CREATE_LOGIN_DEVICE_INFO_TABLE);
	}
}

void InitSDK()
{
	CJXJVendor* jxjVendor = new CJXJVendor();
	CDZPVendor* dzpVendor = new CDZPVendor();
	DHVendor* dhVendor = new DHVendor();
	HKVendor* hkVendor = new HKVendor();

	pVendorList.push_back(jxjVendor);
	//pVendorList.push_back(dzpVendor);
	//pVendorList.push_back(dhVendor);
	//pVendorList.push_back(hkVendor);
}

void InitIP()
{
	/************************* Init IP **********************/
	PortScan portScan(MessagePump::queuePortScan);
	ThreadPool::defaultPool().start(portScan);
}

void InitSearchDevice()
{
	DEVICE_INFO_SIMPLE_LIST listDeviceSimpleInfo = CSearchDevice::GetDeviceInfoSimpleList();

	std::cout << CCommonUtrl::getInstance().GetCurTime() << "Search Device Start!" << std::endl;
	CSearchDevice sd(pVendorList, listDeviceSimpleInfo, MessagePump::queueSearchDevice);
	ThreadPool::defaultPool().start(sd);

	//queueSearchDevice.enqueueNotification(new CNotificationSearchDevice(Notification_Type_Search_Device_Cancel));
}

void InitDeviceManager()
{
	CDeviceManager dm(pVendorList, MessagePump::queueDeviceManager);
	ThreadPool::defaultPool().start(dm);

	//queueDeviceManager.enqueueNotification(new CNotificationDeviceManager(Notification_Type_Device_Manager_Cancel));
}

CMainWnd::CMainWnd()
:m_IsMinWnd(FALSE), m_IsMaxWnd(FALSE)
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<CMainWnd, CNotificationNetworkStatus>(*this, &CMainWnd::HandleNotificationNetworkStatus));
	nc.addObserver(Observer<CMainWnd, ScanNotification>(*this, &CMainWnd::HandleNotificationScanPort));
	nc.addObserver(Observer<CMainWnd, CNotificationSearchDevice>(*this, &CMainWnd::HandleNotificationSearchDevice));

	CheckDB();
	InitSDK();
	InitIP();
}


CMainWnd::~CMainWnd()
{
	
}

void CMainWnd::HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf)
{
	if (pNf->name().compare("CNotificationNetworkStatus"))
	{
		int a = 0;
	}
}
void CMainWnd::HandleNotificationScanPort(ScanNotification* pNf)
{
	InitSearchDevice();
	InitDeviceManager();
}
void CMainWnd::HandleNotificationSearchDevice(CNotificationSearchDevice* pNf)
{
	int a = 0;
}

DUI_BEGIN_MESSAGE_MAP(CMainWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE, OnClose)
DUI_ON_CLICK_CTRNAME(BT_MINWIND, OnMin)
DUI_ON_CLICK_CTRNAME(BT_DOWNLOAD, OnDownLoadWnd)
DUI_ON_CLICK_CTRNAME(BT_LogWnd, OnLogWnd)
DUI_ON_CLICK_CTRNAME(BT_OtherTools, OnOtherToolsWnd)
DUI_ON_CLICK_CTRNAME(BT_VideoPlay, OnVideoPlayWnd)
DUI_END_MESSAGE_MAP()


LPCTSTR CMainWnd::GetWindowClassName() const
{
	return _T("MainWnd");
}

CDuiString CMainWnd::GetSkinFolder()
{	
	return _T("skin");
}

CDuiString CMainWnd::GetSkinFile()
{	
	return _T("xml\\MainWnd.xml");
}

void CMainWnd::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CMainWnd::OnClose(TNotifyUI& msg)
{
	Show_HideTask(FALSE);
	::PostQuitMessage(0L);
}

void CMainWnd::OnMin(TNotifyUI& msg)
{
	Show_HideTask(FALSE);
	m_IsMinWnd = TRUE;
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainWnd::OnDownLoadWnd(TNotifyUI& msg)
{
	std::auto_ptr<DownLoadWnd> pDlg(new DownLoadWnd);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_FRAME, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void CMainWnd::OnLogWnd(TNotifyUI& msg)
{
	std::auto_ptr<CLogUI> pDlg(new CLogUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void CMainWnd::OnVideoPlayWnd(TNotifyUI& msg)
{
	std::auto_ptr<COVPlayerUI> pDlg(new COVPlayerUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void CMainWnd::OnOtherToolsWnd(TNotifyUI& msg)
{
	std::auto_ptr<COtherTools> pDlg(new COtherTools);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

LRESULT CMainWnd::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (m_IsMinWnd)
	{
		Show_HideTask(TRUE);
	}
	m_IsMinWnd = FALSE;

	bHandled = FALSE;
	return FALSE;
}


void CMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("aboutbt"))
	{
		CMenuWnd* pMenu = new CMenuWnd();
		if (pMenu == NULL) { return; }
		POINT pt = { msg.ptMouse.x - 65, 30 };
		::ClientToScreen(m_hWnd, &pt);
		pMenu->Init(msg.pSender, pt);
	}
	if (msg.sType == _T("menu_SetIP"))
	{
		std::auto_ptr<CSetIpWnd> pDlg(new CSetIpWnd);
		assert(pDlg.get());
		pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
		pDlg->CenterWindow();
		pDlg->ShowModal();
	}
	if (msg.sType == _T("menu_Replace"))
	{
		if (!m_IsMaxWnd)
		{
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Max"));
			CPaintManagerUI::ReloadSkin();
			m_IsMaxWnd = TRUE;
		}
		else
		{
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));
			CPaintManagerUI::ReloadSkin();
			m_IsMaxWnd = FALSE;
		}
	}
	return WindowImplBase::NotifyPump(msg);
}


void CMainWnd::Show_HideTask(BOOL IsHide)
{
	int nCwdShow = -1;
	LPARAM lParam;
	HWND task = FindWindow(_T("Shell_TrayWnd"), NULL);
	if (IsHide)
	{
		lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;
		nCwdShow = SW_HIDE;
	}
	else
	{
		lParam = ABS_ALWAYSONTOP;
		nCwdShow = SW_SHOW;
	}

	::ShowWindow(task, nCwdShow);

	APPBARDATA apBar;
	memset(&apBar, 0, sizeof(apBar));
	apBar.cbSize = sizeof(apBar);
	apBar.hWnd = task;
	if (apBar.hWnd != NULL)
	{
		apBar.lParam = lParam;
		SHAppBarMessage(ABM_SETSTATE, &apBar);
	}
}
