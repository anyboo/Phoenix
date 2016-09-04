#include "stdafx.h"
#include "ProgtessUI.h"

CProgtessUI::CProgtessUI()
:_files_count(5), _search_file_count(0), _bCancel(false)
{
	
}


CProgtessUI::~CProgtessUI()
{
	KillTimer(GetHWND(), 1);
}

DUI_BEGIN_MESSAGE_MAP(CProgtessUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_SEARCH_CANCEL, OnCancelSearch)
DUI_END_MESSAGE_MAP()

LPCTSTR CProgtessUI::GetWindowClassName() const
{
	return _T("CProgtessUI");
}

CDuiString CProgtessUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CProgtessUI::GetSkinFile()
{
	return _T("xml//ProgressUI.xml");
}

void CProgtessUI::InitWindow()
{
	SetTimer(GetHWND(), 1, 1000, nullptr);
	_lab_progress = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("text2")));
	_pro_search = dynamic_cast<CProgressUI*>(m_PaintManager.FindControl(_T("electric")));
}

void CProgtessUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CProgtessUI::Notify(TNotifyUI& msg)
{	
	WindowImplBase::Notify(msg);
}

void CProgtessUI::ShowProgress()
{
	CDuiString progress;
	progress.Format("%d/%d", _search_file_count, _files_count);
	_lab_progress->SetText(progress);
	int value = _files_count == 0 ? 0 : (100 * _search_file_count) / _files_count;
	_pro_search->SetValue(value);
	if (value == 100)
	{
		Close();
	}
}

bool CProgtessUI::IsCancelSearch()
{
	return _bCancel;
}

void CProgtessUI::OnCancelSearch(TNotifyUI& msg)
{
	_bCancel = true;
	Close();
}

LRESULT CProgtessUI::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = 0;
	switch (uMsg)
	{
	case WM_TIMER: lRes = OnTimer(uMsg, wParam, lParam, bHandled); break;
	}
	bHandled = FALSE;
	return 0;
}

LRESULT CProgtessUI::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (wParam == 1)
	{
		_search_file_count += 1;
		ShowProgress();
	}
	return 0;
}

