#include "stdafx.h"
#include "PlayWndUI.h"


CPlayWndUI::CPlayWndUI()
:m_bInit(true)
{
}


CPlayWndUI::~CPlayWndUI()
{
}



DUI_BEGIN_MESSAGE_MAP(CPlayWndUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR CPlayWndUI::GetWindowClassName() const
{
	return _T("CPlayWndUI");
}

CDuiString CPlayWndUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CPlayWndUI::GetSkinFile()
{
	return _T("xml\\playLyt.xml");
}

void CPlayWndUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CPlayWndUI::Notify(TNotifyUI& msg)
{
	WindowImplBase::Notify(msg);
}
