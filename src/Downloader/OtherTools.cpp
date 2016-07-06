#include "stdafx.h"
#include "OtherTools.h"


COtherTools::COtherTools()
{
}


COtherTools::~COtherTools()
{
}

DUI_BEGIN_MESSAGE_MAP(COtherTools, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR COtherTools::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString COtherTools::GetSkinFolder()
{
	return _T("skin");
}

CDuiString COtherTools::GetSkinFile()
{
	return _T("xml//OtherTools.xml");
}

void COtherTools::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void COtherTools::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("DH_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\DaHuaTool\\DiskCopy.exe")));
		}
		if (msg.pSender->GetName() == _T("HK_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\hikPlay\\APT-LPB.exe")));
		}
		if (msg.pSender->GetName() == _T("Record_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\screenRecord\\ScreenCap.exe")));
		}
		if (msg.pSender->GetName() == _T("Video_Play"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\OVPlayer\\OVPlayer_V1.3.7(UK).exe")));
		}
	}
	WindowImplBase::Notify(msg);
}

void COtherTools::OnOpenExeFile(STDSTRING& filePath)
{
	HINSTANCE hIns = ShellExecute(NULL, _T("Open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
	int dret = (int)hIns;
	if (dret < 32)
		MessageBox(NULL, _T("无法打开"), _T("提示"), MB_OK);
}
