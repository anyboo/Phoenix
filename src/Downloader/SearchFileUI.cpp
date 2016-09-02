#include "stdafx.h"
#include "SearchFileUI.h"
#include "PlayVideoWnd.h"
#include "FileLogInfoUI.h"

SearchFileUI::SearchFileUI()
:m_DownloadID(1)
{
}


SearchFileUI::~SearchFileUI()
{
}

DUI_BEGIN_MESSAGE_MAP(SearchFileUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_SEARCHWND, OnCloseWnd)
DUI_ON_CLICK_CTRNAME(BT_BEGINDOWNLOAD, OnDownLoadFile)
DUI_ON_CLICK_CTRNAME(BT_SELECT_ALL, OnCheckAll)
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

void SearchFileUI::InitWindow()
{
	OnShowFileList();
}

void SearchFileUI::BuildControlDDX()
{
	_pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	_oCheckAll = dynamic_cast<COptionUI*>(m_PaintManager.FindControl(_T("All")));
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
	if (msg.sType == DUI_MSGTYPE_CLICK){
		CDuiString sender_name = msg.pSender->GetName();
		if (!sender_name.Left(6).Compare(_T("option")))
		{
			GetSelectOption(sender_name);
		}
		if (!sender_name.Left(7).Compare(_T("BT_Play")))
		{
			CDuiString serial = sender_name.Right(sender_name.GetLength() - 7);
			int CurSel = stoi(std::string(serial));
			OnPlayVideo(CurSel);
		}
	}
	WindowImplBase::Notify(msg);
}

void SearchFileUI::OnCheckAll(TNotifyUI& msg)
{
	_checked_files.clear();
	int nCount = _pList->GetCount();
	for (int i = 1; i <= nCount; i++)
	{
		COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(_pList, DUI_CTR_OPTION, i));
		if (!_oCheckAll->IsSelected()){
			option->Selected(true);
			_checked_files.push_back(i - 1);
		}
		else{
			option->Selected(false);
		}
	}
}

void SearchFileUI::OnShowFileList()
{
	std::string optionName, buttonName, SubListName;
}

std::string SearchFileUI::TimeChange(__time64_t inputTime)
{
	struct tm OutTime;
	OutTime = { 0 };
	
	//OutTime = *localtime(&inputTime);
	OutTime.tm_year += 1900;
	OutTime.tm_mon += 1;
	char strTime[200] = { 0 };
	sprintf_s(strTime, "%d-%02d-%02d  %02d:%02d", OutTime.tm_year, OutTime.tm_mon, OutTime.tm_mday, OutTime.tm_hour, OutTime.tm_min);
	return std::string(strTime);
}

void SearchFileUI::GetFileInfo(std::string& SendName)
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

void SearchFileUI::GetSelectOption(CDuiString& optionName)
{
	CDuiString serial = optionName.Right(optionName.GetLength() - 6);
	size_t tag = stoi(std::string(serial));
	COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(_pList, optionName));
	if (option->IsSelected())
	{
		for (size_t j = 0; j < _checked_files.size(); j++)
		{
			if (_checked_files[j] == tag)
			{
				_checked_files.erase(_checked_files.begin() + j);
			}
		}
	}
	else
	{
		_checked_files.push_back(tag);
	}
}

