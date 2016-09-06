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
	_edit_path = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("path")));
	TCHAR open_path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, open_path);
	_edit_path->SetText(open_path);
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

	//fixed later, convert UUID to humanreadable name

	std::wstring path(NAME);
	std::string text;
	if (sizeof(TCHAR) == 1){
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		text = conv.to_bytes(path);
	}

	_edit_path->SetText(text.c_str());
}