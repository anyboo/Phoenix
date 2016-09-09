#include "stdafx.h"
#include "FileLogInfoUI.h"
#include <Objbase.h>
#include <Shobjidl.h>
#include <locale>
#include <codecvt>

CFileLogInfoUI::CFileLogInfoUI()
{
}


CFileLogInfoUI::~CFileLogInfoUI()
{
}


DUI_BEGIN_MESSAGE_MAP(CFileLogInfoUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_SAVE_PATH, OnSaveDownloadPath)
DUI_ON_CLICK_CTRNAME(BT_SELECT_PATH, OnSelectPath)
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_ITEMSELECT, CMB_SELECT_CASE, OnSelectCaseToSave)
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

void CFileLogInfoUI::InitWindow()
{
	_comb_case = dynamic_cast<CComboUI*>(m_PaintManager.FindControl(_T("Case_Numb")));
	_edit_path = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("path")));
	_edit_time = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("collect_time")));
	InitDownloadConfig();
}

void CFileLogInfoUI::InitDownloadConfig()
{
	TCHAR open_path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, open_path);
	CDuiString SavePath, CasePath;
	CasePath.Format("case%d", _comb_case->GetCurSel() + 1);
	SavePath.Format("%s", open_path);
	SavePath.Append("\\");
	SavePath = SavePath + CasePath;
	_edit_path->SetText(SavePath);

	SYSTEMTIME systime;
	CDuiString time;
	::GetLocalTime(&systime);
	time.Format("%d-%d-%d  %d:%d:%d", systime.wYear, systime.wMonth, systime.wDay, \
		systime.wHour, systime.wMinute, systime.wSecond);
	_edit_time->SetText(time);
}

void CFileLogInfoUI::OnSelectCaseToSave(TNotifyUI& msg)
{
	CDuiString CasePath;
	CasePath.Format("case%d", _comb_case->GetCurSel() + 1);
	CDuiString SavePath = _edit_path->GetText();
	SavePath = SavePath.Left(SavePath.GetLength() - CasePath.GetLength()) + CasePath;

	_edit_path->SetText(SavePath);
}

void CFileLogInfoUI::OnSelectPath(TNotifyUI& msg)
{
	IFileOpenDialog* pfd;
	HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&pfd));

	if (FAILED(hr)) return;
	DWORD dwOptions;
	hr = pfd->GetOptions(&dwOptions);
	if (FAILED(hr)) return;
	hr = pfd->SetOptions(dwOptions | FOS_PICKFOLDERS | FOS_PATHMUSTEXIST);
	if (FAILED(hr)) return;
	hr = pfd->Show(NULL);
	if (FAILED(hr)) return;
	IShellItemArray *psiaResults;
	hr = pfd->GetResults(&psiaResults);
	DWORD conut = 0;
	hr = psiaResults->GetCount(&conut);

	LPWSTR NAME;
	IShellItem *item;
	psiaResults->GetItemAt(0, &item);
	hr = item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &NAME);
	psiaResults->Release();
	pfd->Release();

	std::wstring path(NAME);
	std::string SavePath;
	if (sizeof(TCHAR) == 1){
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		SavePath = conv.to_bytes(path);
	}

	std::string CasePath = std::to_string(_comb_case->GetCurSel() + 1);
	CasePath = std::string(_T("case")) + CasePath;
	SavePath.append(_T("\\"));
	SavePath = SavePath + CasePath;
	_edit_path->SetText(SavePath.c_str());
}