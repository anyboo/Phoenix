#include "stdafx.h"
#include "SearchFileUI.h"
#include "PlayVideoWnd.h"
#include "FileLogInfoUI.h"

SearchFileUI::SearchFileUI(Device* device)
:m_InitShowFileList(false), m_DownloadID(1)
{
	m_device = device;
}


SearchFileUI::~SearchFileUI()
{
}

DUI_BEGIN_MESSAGE_MAP(SearchFileUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_SEARCHWND, OnCloseWnd)
DUI_ON_CLICK_CTRNAME(BT_BEGINDOWNLOAD, OnDownLoadFile)
DUI_END_MESSAGE_MAP()


LPCTSTR SearchFileUI::GetWindowClassName() const
{
	return _T("SearchFileUI");
}

CDuiString SearchFileUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString SearchFileUI::GetSkinFile()
{
	return _T("xml\\VideoSearch.xml");
}

void SearchFileUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void SearchFileUI::OnCloseWnd(TNotifyUI& msg)
{
	m_IsDownLoad = closeWnd;
	Close();
}

void SearchFileUI::OnDownLoadFile(TNotifyUI& msg)
{
	m_IsDownLoad = beginDownload;

	std::auto_ptr<CFileLogInfoUI> pDlg(new CFileLogInfoUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();

	Close();
}

void SearchFileUI::Notify(TNotifyUI& msg)
{	
	if (!m_InitShowFileList)
	{
		OnShowFileList();
		m_InitShowFileList = true;
	}
	if (msg.sType == DUI_MSGTYPE_CLICK){
		STDSTRING SendName = msg.pSender->GetName();
		if (!SendName.compare(0, 6, _T("option")))
		{
			GetSelectOption(SendName);
		}
		if (SendName == _T("All"))
		{
			m_Select_file.clear();
			CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
			COptionUI* option_All = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(pList, _T("All")));
			int nCount = pList->GetCount();
			for (int i = 1; i <= nCount; i++)
			{
				COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i));
				if (!option_All->IsSelected()){
					option->Selected(true);
					m_Select_file.push_back(i - 1);
				}
				else{
					option->Selected(false);
				}
			}
		}
		if (!SendName.compare(0, 7, _T("BT_Play")))
		{
			std::string strTag = SendName.substr(7);
			int CurSel = stoi(strTag);
			OnPlayVideo(CurSel);
		}
	}

	WindowImplBase::Notify(msg);
}


void SearchFileUI::OnShowFileList()
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	STDSTRING optionName, buttonName, SubListName;
}

STDSTRING SearchFileUI::TimeChange(__time64_t inputTime)
{
	struct tm OutTime;
	OutTime = { 0 };
	
	OutTime = *localtime(&inputTime);
	OutTime.tm_year += 1900;
	OutTime.tm_mon += 1;
	char strTime[200] = { 0 };
	sprintf_s(strTime, "%d-%02d-%02d  %02d:%02d", OutTime.tm_year, OutTime.tm_mon, OutTime.tm_mday, OutTime.tm_hour, OutTime.tm_min);
	return STDSTRING(strTime);
}

void SearchFileUI::GetFileInfo(STDSTRING& SendName)
{
}

void SearchFileUI::OnPlayVideo(int CurSel)
{
	/*std::auto_ptr<CPlayVideoWnd> pDlg(new CPlayVideoWnd(m_device, file));
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();*/
}

void SearchFileUI::GetSelectOption(STDSTRING& optionName)
{
	std::string strTag = optionName.substr(6);
	size_t tag = stoi(strTag);

	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(pList, optionName.c_str()));
	if (option->IsSelected())
	{
		for (size_t j = 0; j < m_Select_file.size(); j++)
		{
			if (m_Select_file[j] == tag)
			{
				m_Select_file.erase(m_Select_file.begin() + j);
			}
		}
	}
	else
	{
		m_Select_file.push_back(tag);
	}
}

