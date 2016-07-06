#include "stdafx.h"
#include "ProgtessUI.h"


CProgtessUI::CProgtessUI()
{
}


CProgtessUI::~CProgtessUI()
{
}

DUI_BEGIN_MESSAGE_MAP(CProgtessUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR CProgtessUI::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString CProgtessUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CProgtessUI::GetSkinFile()
{
	return _T("xml//ProgressUI.xml");
}

void CProgtessUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CProgtessUI::Notify(TNotifyUI& msg)
{	
	WindowImplBase::Notify(msg);
}


