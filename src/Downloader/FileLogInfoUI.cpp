#include "stdafx.h"
#include "FileLogInfoUI.h"


CFileLogInfoUI::CFileLogInfoUI()
{
}


CFileLogInfoUI::~CFileLogInfoUI()
{
}

DUI_BEGIN_MESSAGE_MAP(CFileLogInfoUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR CFileLogInfoUI::GetWindowClassName() const
{
	return _T("DownLoadLogInfo");
}

CDuiString CFileLogInfoUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CFileLogInfoUI::GetSkinFile()
{
	return _T("xml\\DownLoadLogInfo.xml");
}


void CFileLogInfoUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CFileLogInfoUI::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("ok_btn"))
	{
		Close();
	}
	WindowImplBase::Notify(msg);
}