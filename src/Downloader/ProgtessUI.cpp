#include "stdafx.h"
#include "ProgtessUI.h"

CProgtessUI::CProgtessUI()
:m_Searchfile_count(0), m_CountFile(0), m_InitNotify(true)
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

void CProgtessUI::InitWindow()
{
}

void CProgtessUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CProgtessUI::Notify(TNotifyUI& msg)
{	
	DUITRACE(msg.sType);
	WindowImplBase::Notify(msg);
}

void CProgtessUI::ShowProgress()
{
	DUITRACE("ShowProgress");
	std::string progress;
	progress = to_string(m_Searchfile_count) + std::string("/") + to_string(m_CountFile);
	CLabelUI* Lab_pro = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("text2")));
	CProgressUI* Search_Pro = dynamic_cast<CProgressUI*>(m_PaintManager.FindControl(_T("electric")));
	Lab_pro->SetText(progress.c_str());
	int pro_value = m_CountFile == 0 ? 0 : (100 * m_Searchfile_count) / m_CountFile;
	Search_Pro->SetValue(pro_value);
}


void CProgtessUI::OnCancelSearch(TNotifyUI& msg)
{
	bool b = true;
	Close();
}

