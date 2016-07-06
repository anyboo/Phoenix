#include "stdafx.h"
#include "OVPlayerUI.h"


COVPlayerUI::COVPlayerUI()
{
}


COVPlayerUI::~COVPlayerUI()
{
}

DUI_BEGIN_MESSAGE_MAP(COVPlayerUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR COVPlayerUI::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString COVPlayerUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString COVPlayerUI::GetSkinFile()
{
	return _T("xml//OVPlayerUI.xml");
}

void COVPlayerUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void COVPlayerUI::Notify(TNotifyUI& msg)
{

	WindowImplBase::Notify(msg);
}
