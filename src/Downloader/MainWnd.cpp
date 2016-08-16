#include "stdafx.h"
#include "MainWnd.h"

#include "DownLoadWnd.h"
#include "LogUI.h"
#include "VideoLoginUI.h"
#include "OtherTools.h"
#include "SetIpWnd.h"
#include "OVPlayerUI.h"
#include "MenuWnd.h"

#include "Mversion.h"

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

}


CMainWnd::~CMainWnd()
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.removeObserver(Observer<CMainWnd, CNotificationNetworkStatus>(*this, &CMainWnd::HandleNotificationNetworkStatus));
}

DUI_BEGIN_MESSAGE_MAP(CMainWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE, OnClose)
DUI_ON_CLICK_CTRNAME(BT_MINWIND, OnMin)
DUI_ON_CLICK_CTRNAME(BT_DOWNLOAD, OnDownLoadWnd)
DUI_ON_CLICK_CTRNAME(BT_LogWnd, OnLogWnd)
DUI_ON_CLICK_CTRNAME(BT_OtherTools, OnOtherToolsWnd)
DUI_ON_CLICK_CTRNAME(BT_VideoPlay, OnVideoPlayWnd)
DUI_ON_CLICK_CTRNAME(BT_ABOUT, OnAbout)
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

	ShowVersion();
}

void CMainWnd::ShowVersion()
{
	std::string Version = MVersion::getVersion();
	CLabelUI* lab_version = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("version")));
	lab_version->SetText(Version.c_str());
}

void CMainWnd::OnClose(TNotifyUI& msg)
{
	::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_SHOW);
	::PostQuitMessage(0L);
}

void CMainWnd::OnMin(TNotifyUI& msg)
{
	::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_SHOW);
	m_IsMinWnd = TRUE;
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainWnd::OnAbout(TNotifyUI& msg)
{
	CMenuWnd* pMenu = new CMenuWnd();
	if (pMenu == NULL) { return; }
	POINT pt = { msg.ptMouse.x - 65, 30 };
	::ClientToScreen(m_hWnd, &pt);
	pMenu->Init(msg.pSender, pt);
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
		::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_HIDE);
	}
	m_IsMinWnd = false;

	bHandled = false;
	return false;
}


void CMainWnd::Notify(TNotifyUI& msg)
{
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
			CControlUI* contrl = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
			CControlUI* contrl2 = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("un_use")));
			CButtonUI* button1 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("download")));
			CButtonUI* button2 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("VideoPlay")));
			CButtonUI* button3 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Log_manager")));
			CButtonUI* button4 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Other_tools")));
			contrl->SetAttribute(_T("padding"), _T("660,10,10,5"));
			contrl2->SetAttribute(_T("pos"), _T("606,375,672,444"));
			button1->SetAttributeList(_T("pos=\"293,140,636,405\" normalimage=\"file='skin/mdownload_normal.png'\""));
			button2->SetAttributeList(_T("pos=\"642,140,985,405\" normalimage=\"file='skin/mvideo_normal.png'\""));
			button3->SetAttributeList(_T("pos=\"293,414,636,680\" normalimage=\"file='skin/mlog_normal.png'\""));
			button4->SetAttributeList(_T("pos=\"642,414,985,680\" normalimage=\"file='skin/mtool_normal.png'\""));
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Max"));
			CPaintManagerUI::ReloadSkin();
			m_IsMaxWnd = TRUE;
		}
		else
		{
			
			ResizeClient(1024, 768);
			CControlUI* contrl = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
			CControlUI* contrl2 = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("un_use")));
			CButtonUI* button1 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("download")));
			CButtonUI* button2 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("VideoPlay")));
			CButtonUI* button3 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Log_manager")));
			CButtonUI* button4 = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Other_tools")));
			contrl->SetAttribute(_T("padding"), _T("400,10,10,5"));
			contrl2->SetAttribute(_T("pos"), _T("483,361,543,421"));
			button1->SetAttributeList(_T("pos=\"235,134,512,390\" normalimage=\"skin/download_normal.png\""));
			button2->SetAttributeList(_T("pos=\"515,134,789,389\" normalimage=\"skin/video_normal.png\""));
			button3->SetAttributeList(_T("pos=\"235,393,512,649\" normalimage=\"skin/log_normal.png\""));
			button4->SetAttributeList(_T("pos=\"515,393,789,649\" normalimage=\"skin/tool_normal.png\""));
			CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));
			CPaintManagerUI::ReloadSkin();
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

