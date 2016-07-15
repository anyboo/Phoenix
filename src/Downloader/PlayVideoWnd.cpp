#include "stdafx.h"
#include "PlayVideoWnd.h"


CPlayVideoWnd::CPlayVideoWnd()
{
}


CPlayVideoWnd::~CPlayVideoWnd()
{
}

DUI_BEGIN_MESSAGE_MAP(CPlayVideoWnd, WindowImplBase)
DUI_END_MESSAGE_MAP()

LPCTSTR CPlayVideoWnd::GetWindowClassName() const
{
	return _T("PlayVideoWnd");
}

CDuiString CPlayVideoWnd::GetSkinFolder()
{
	return _T("skin");
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
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("close"))
	{
		CVerticalLayoutUI* PlayLyt = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("wnd_lyt")));
		CPaintManagerUI* vLytppm = PlayLyt->GetManager();
		HWND play_hwnd = vLytppm->GetPaintWindow();
		Close();
	}
	WindowImplBase::Notify(msg);
}

void CPlayVideoWnd::GetPlayHwnd()
{

}