#include "stdafx.h"
#include "ProgtessUI.h"

#include <Poco/NotificationCenter.h>
#include "Poco/Observer.h"

#include "ReciveUIQunue.h"
#include "ReciveUINotification.h"

using Poco::NotificationCenter;
using Poco::Observer;


CProgtessUI::CProgtessUI()
:m_Searchfile_count(0), m_CountFile(0), m_InitNotify(true)
{
	
}


CProgtessUI::~CProgtessUI()
{

}

void CProgtessUI::ReceiveSearchFile(SearchFileNotification* pNf)
{
	std::string SendName(_T("SearchFileNotification"));
	if (SendName == pNf->name() || !pNf) return;

	NOTIFICATION_TYPE eNotify;
	int nData;

	eNotify = pNf->GetNotify();
	nData = pNf->GetData();

	switch (eNotify)
	{
	case Notification_Type_Search_File_Process:
		m_Searchfile_count = nData;
		ShowProgress();
		break;
	case Notification_Type_Search_File_TotalSize:
		m_CountFile = nData;
		ShowProgress();
		break;
	case Notification_Type_Search_File_Finish:
		Close();
		break;
	case Notification_Type_Search_File_Failure:
		break;
	default:
		break;
	}
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
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<CProgtessUI, SearchFileNotification>(*this, &CProgtessUI::ReceiveSearchFile));
}

void CProgtessUI::OnFinalMessage(HWND hWnd)
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.removeObserver(Observer<CProgtessUI, SearchFileNotification>(*this, &CProgtessUI::ReceiveSearchFile));

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
	//ReciveUIQunue *queue1 = new ReciveUIQunue();;
	bool b = true;
	//g_queue1->enqueueNotification(new ReciveUINotification(b));
	ReciveUIQunue::GetInstance()->enqueueNotification(new ReciveUINotification(b));
}

