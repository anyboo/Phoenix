#include "stdafx.h"
#include "FileLogInfoUI.h"
#include "CommDlg.h"

CFileLogInfoUI::CFileLogInfoUI()
{
}


CFileLogInfoUI::~CFileLogInfoUI()
{
}


DUI_BEGIN_MESSAGE_MAP(CFileLogInfoUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_SAVE_PATH, OnSaveDownloadPath)
DUI_ON_CLICK_CTRNAME(BT_SELECT_PATH, OnSelectPath)
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
	WindowImplBase::Notify(msg);
}

void CFileLogInfoUI::OnSaveDownloadPath(TNotifyUI& msg)
{
	Close();
}

void CFileLogInfoUI::OnSelectPath(TNotifyUI& msg)
{
	TCHAR szBuffer[MAX_PATH] = { 0 };

	OPENFILENAME  ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFilter = _T("TXT文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0");//file subfix   
	ofn.lpstrInitialDir = _T("D:\\");//Default Path
	ofn.lpstrFile = szBuffer;//File Buffer  
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT;//add OFN_ALLOWMULTISELECT if need multiple selection
	BOOL bSel = GetOpenFileName(&ofn);

	CDuiString FileSavePath = ofn.lpstrInitialDir;
}