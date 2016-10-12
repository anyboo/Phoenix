#include "stdafx.h"
#include "MainWnd.h"
#include "DownLoadWnd.h"
#include "LogUI.h"
#include "VideoLoginUI.h"
#include "OtherTools.h"
#include "SetIpWnd.h"
#include "OVPlayerUI.h"
#include "MenuWnd.h"


#define BT_CLOSE			(_T("closebtn"))
#define	BT_MINWIND			(_T("minbtn"))
#define BT_DOWNLOAD			(_T("download"))
#define BT_LogWnd			(_T("Log_manager"))
#define BT_OtherTools		(_T("Other_tools"))
#define BT_VideoPlay		(_T("VideoPlay"))
#define BT_ABOUT			(_T("aboutbt"))
#define BT_SKINCHANGE		(_T("menu_Replace"))
#define BT_IPCONFIG			(_T("menu_SetIP"))


CMainWnd::CMainWnd()
:m_IsMinWnd(false), bMaxResolution(false)
{
	// fixed bug : need auto adjust resolution
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
DUI_ON_CLICK_CTRNAME(BT_ABOUT, OnAbout)
DUI_ON_MSGTYPE(BT_SKINCHANGE, OnSkinChanged)
DUI_ON_MSGTYPE(BT_IPCONFIG, OnIPConfiguration)
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
	BuildControlDDX();
	ShowVersion();
}

void CMainWnd::BuildControlDDX()
{
	_Network		= dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
	_un_use			= dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("un_use")));
	_DownloadUI		= dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("download")));
	_VideoUI		= dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("VideoPlay")));
	_LogUI			= dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Log_manager")));
	_ToolUI			= dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Other_tools")));
	_Version		= dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("version")));
}

void CMainWnd::ShowVersion()
{
	std::string Version = "2.0.0.006";//MVersion::getVersion();
	_Version->SetText(Version.c_str());
}

void CMainWnd::OnClose(TNotifyUI& msg)
{
	::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_SHOW);
	::PostQuitMessage(0L);
}

void CMainWnd::OnMin(TNotifyUI& msg)
{
	::ShowWindow(::FindWindow("Shell_TrayWnd", NULL), SW_SHOW);
	m_IsMinWnd = true;
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainWnd::OnAbout(TNotifyUI& msg)
{
	//fixed bug: Can not display About Dialog
	CMenuWnd* pMenu = new CMenuWnd();
	if (pMenu == NULL) { return; }
	POINT pt = { msg.ptMouse.x - 65, 30 };
	::ClientToScreen(m_hWnd, &pt);
	pMenu->Init(msg.pSender, pt);
}

void CMainWnd::OnSkinChanged(TNotifyUI& msg)
{
	bMaxResolution = !bMaxResolution;

	if (bMaxResolution)
	{
		ResizeClient(1280, 800);
		_Network->SetAttribute(_T("padding"), _T("660,10,10,5"));
		_un_use->SetAttribute(_T("pos"), _T("606,375,672,444"));
		_DownloadUI->SetAttributeList(_T("pos=\"293,140,636,405\" normalimage=\"file='skin/mdownload_normal.png'\""));
		_VideoUI->SetAttributeList(_T("pos=\"642,140,985,405\" normalimage=\"file='skin/mvideo_normal.png'\""));
		_LogUI->SetAttributeList(_T("pos=\"293,414,636,680\" normalimage=\"file='skin/mlog_normal.png'\""));
		_ToolUI->SetAttributeList(_T("pos=\"642,414,985,680\" normalimage=\"file='skin/mtool_normal.png'\""));
		CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Max"));
	}
	else
	{
		ResizeClient(1024, 768);
		_Network->SetAttribute(_T("padding"), _T("400,10,10,5"));
		_un_use->SetAttribute(_T("pos"), _T("483,361,543,421"));
		_DownloadUI->SetAttributeList(_T("pos=\"235,134,512,390\" normalimage=\"skin/download_normal.png\""));
		_VideoUI->SetAttributeList(_T("pos=\"515,134,789,389\" normalimage=\"skin/video_normal.png\""));
		_LogUI->SetAttributeList(_T("pos=\"235,393,512,649\" normalimage=\"skin/log_normal.png\""));
		_ToolUI->SetAttributeList(_T("pos=\"515,393,789,649\" normalimage=\"skin/tool_normal.png\""));
		CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));
	}

	CPaintManagerUI::ReloadSkin();
}
void CMainWnd::OnIPConfiguration(TNotifyUI& msg)
{
	std::auto_ptr<CSetIpWnd> pDlg(new CSetIpWnd);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
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
	return WindowImplBase::NotifyPump(msg);
}


void CMainWnd::OnStatusChanged(NETWORK_STATUS st)
{
	if (st == ON_LINE)
		_Network->SetBkImage(_T("skin/network_online.png"));
	else if (st == OFF_LINE)
		_Network->SetBkImage(_T("skin/network_offline.png"));
}

