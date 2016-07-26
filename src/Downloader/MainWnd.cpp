#include "stdafx.h"
#include "MainWnd.h"
#include "DownLoadWnd.h"
#include "LogUI.h"
#include "VideoLoginUI.h"
#include "OtherTools.h"
#include "SetIpWnd.h"
#include "OVPlayerUI.h"
#include "MenuWnd.h"

#include <io.h>
#include <fcntl.h>
#include <Poco/NotificationCenter.h>
#include "Poco/Observer.h"

#include "MessagePump.h"

using Poco::NotificationCenter;
using Poco::Observer;



CMainWnd::CMainWnd()
:m_IsMinWnd(false), m_IsMaxWnd(false)
{


/*#ifdef _DEBUG  
	OpenConsole();
#endif*/ 

	//NotificationCenter& nc = NotificationCenter::defaultCenter();
	//nc.addObserver(Observer<CMainWnd, CNotificationNetworkStatus>(*this, &CMainWnd::HandleNotificationNetworkStatus));

}


CMainWnd::~CMainWnd()
{
	
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

void CMainWnd::InitWindow()
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<CMainWnd, CNotificationNetworkStatus>(*this, &CMainWnd::HandleNotificationNetworkStatus));

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
		Show_HideTask(true);
	}
	m_IsMinWnd = false;

	bHandled = false;
	return false;
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
			ResizeClient(1280, 800);
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Max"));
			CPaintManagerUI::ReloadSkin();	
			m_IsMaxWnd = TRUE;
		}
		else
		{
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));
			CPaintManagerUI::ReloadSkin();
			ResizeClient(1024, 768);
			m_IsMaxWnd = FALSE;
		}
	}
	return WindowImplBase::NotifyPump(msg);
}

void CMainWnd::SetNetWorkState(NOTIFICATION_TYPE& eNotify)
{
	CControlUI* NetWorkUI = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
	if (eNotify == Notification_Type_Network_status_Connect)
		NetWorkUI->SetBkImage(_T("skin/network_online.png"));
	else if (eNotify == Notification_Type_Network_status_Disconnect)
		NetWorkUI->SetBkImage(_T("skin/network_offline.png"));
}

void CMainWnd::HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf)
{
	if (pNf == nullptr)
		return;
	if (pNf->name().compare("class CNotificationNetworkStatus"))
		return;

	NOTIFICATION_TYPE eNotify;
	eNotify = pNf->GetNotificationType();
	SetNetWorkState(eNotify);
}

void CMainWnd::Show_HideTask(bool IsHide)
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
