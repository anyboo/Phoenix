#include "stdafx.h"
#include "ProgtessUI.h"

CProgtessUI::CProgtessUI()
:_files_count(0), _search_file_count(0)
{
	
}


CProgtessUI::~CProgtessUI()
{

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
}


void CProgtessUI::OnCancelSearch(TNotifyUI& msg)
{
	Close();
}

