#include "stdafx.h"
#include "PlayVideoWnd.h"
#include "PlayWndUI.h"

CPlayVideoWnd::CPlayVideoWnd()
:m_IsPlay(true), m_stopPos(0)
{
}

CPlayVideoWnd::~CPlayVideoWnd()
{
}

DUI_BEGIN_MESSAGE_MAP(CPlayVideoWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_PLWND, OnCloseWnd)
DUI_ON_CLICK_CTRNAME(BT_PLAY_STOP, OnStartStop)
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_VALUECHANGED, SLIDER_PLAYPOS, OnAdjustPlayPos)
DUI_END_MESSAGE_MAP()

LPCTSTR CPlayVideoWnd::GetWindowClassName() const
{
	return _T("PlayVideoWnd");
}

CDuiString CPlayVideoWnd::GetSkinFolder()
{
	return _T("skin");
}


void CPlayVideoWnd::InitWindow()
{
}

CDuiString CPlayVideoWnd::GetSkinFile()
{
	return _T("xml\\PlayVideoWnd.xml");
}

void CPlayVideoWnd::OnFinalMessage(HWND hWnd)
{	
	WindowImplBase::OnFinalMessage(hWnd);
}

void CPlayVideoWnd::Notify(TNotifyUI& msg)
{
	WindowImplBase::Notify(msg);
}

void CPlayVideoWnd::OnCloseWnd(TNotifyUI& msg)
{
	Close();
}

void CPlayVideoWnd::OnStartStop(TNotifyUI& msg)
{
	if (m_IsPlay)
	{
		CButtonUI* btn_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Start_stop")));
		btn_play->SetText(_T("播放"));
		CSliderUI* slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
		int m_stopPos = slider->GetValue();
		m_IsPlay = false;
	}
	else if (!m_IsPlay)
	{
		CButtonUI* btn_stop = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Start_stop")));
		btn_stop->SetText(_T("暂停"));
		m_IsPlay = true;
	}
}

void CPlayVideoWnd::OnAdjustPlayPos(TNotifyUI& msg)
{
	CSliderUI* slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
	m_stopPos = slider->GetValue();
}


HWND CPlayVideoWnd::GetPlayHwnd()
{	 
	std::auto_ptr<CPlayWndUI> pDlg(new CPlayWndUI);
	assert(pDlg.get());
	HWND pHwnd = pDlg->Create(GetHWND(), NULL, UI_WNDSTYLE_CHILD, NULL, 0, 0, 0, 0, 0);

	CDuiRect rcWnd;
	GetWindowRect(pHwnd, &rcWnd);
	::SetWindowPos(pHwnd, NULL, rcWnd.left, rcWnd.top + 40, rcWnd.GetWidth(), rcWnd.GetHeight(), SWP_NOZORDER | SWP_NOSIZE | SWP_DRAWFRAME | SWP_SHOWWINDOW);

	GetWindowRect(pHwnd, &rcWnd);
	return pHwnd;
}
