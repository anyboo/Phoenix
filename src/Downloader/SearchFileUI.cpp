#include "stdafx.h"
#include "SearchFileUI.h"
#include "PlayVideoWnd.h"
#include "FileLogInfoUI.h"
#include <time.h>
#include "TestData.h"
#include "DVR/DVRSearchFilesContainer.h"

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
	BuildControlDDX();
	OnShowFileList();
}

void SearchFileUI::BuildControlDDX()
{
	_pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	_oCheckAll = dynamic_cast<COptionUI*>(m_PaintManager.FindControl(_T("All")));
	_lab_CountText = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("file_Count")));
}


void SearchFileUI::OnCloseWnd(TNotifyUI& msg)
{
	m_IsDownLoad = closeWnd;
	Close();
}

bool SearchFileUI::IsBeginDownload()
{
	if (m_IsDownLoad == beginDownload)
		return true;
	else
		return false;
}

void SearchFileUI::OnDownLoadFile(TNotifyUI& msg)
{
	if (_checked_files.size() == 0)
	{
		MessageBox(GetHWND(), "请选择下载文件！", "警告", MB_OK);
		return;
	}
	m_IsDownLoad = beginDownload;

	std::auto_ptr<CFileLogInfoUI> pDlg(new CFileLogInfoUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();

//	CTestData::getInstance()->SetDownloadfiles(_checked_files);

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
	GetFileCountAndSize();
}

void SearchFileUI::OnShowFileList()
{
	std::vector<DVR::DVRSearchFiles*> files;
//	DVRSearchFilesContainer::GetSearchFiles(files);
	
	int filesize = files.size();
	for (int i = 0; i < filesize; i++)
	{
		CDialogBuilder builder;
		CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//SearchFileList.xml"), (UINT)0, NULL, &m_PaintManager));
		_pList->Add(SubList);
		COptionUI* SubOption = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_OPTION));
		CButtonUI* btn_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
		CDuiString optionName, buttonName, SubListName;
		optionName.Format("option%d", i);
		buttonName.Format("BT_Play%d", i);
		SubListName.Format("FileInfoList%d", i);
		
		SubOption->SetName(optionName);
		btn_play->SetName(buttonName);
		SubList->SetName(SubListName);


		CLabelUI* Lab_Name = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
		CLabelUI* Lab_Channel = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
		CLabelUI* Lab_stime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
		CLabelUI* Lab_etime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
		CLabelUI* Lab_size = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));

		std::string filename = files[i]->fname();
		int channel = files[i]->channel();
		Poco::DateTime stime = files[i]->startTime();
		Poco::DateTime etime = files[i]->stopTime();
		size_t size = files[i]->fsize();

		CDuiString startTime = TimeChange(stime);
		CDuiString stopTime = TimeChange(etime);

		Lab_Name->SetText(filename.c_str());
		Lab_Channel->SetText(to_string(channel).c_str());
		Lab_stime->SetText(startTime);
		Lab_etime->SetText(stopTime);
		Lab_size->SetText(std::to_string(size).c_str());
	}
}


CDuiString SearchFileUI::TimeChange(Poco::DateTime inputTime)
{
	CDuiString strOutTime;

	strOutTime.Format("%d-%02d-%02d  %02d:%02d", inputTime.year(), inputTime.month(), inputTime.day(), inputTime.hour(), inputTime.minute());
	return strOutTime;
}

void SearchFileUI::GetFileInfo(std::string& SendName)
{
}

void SearchFileUI::OnPlayVideo(int CurSel)
{
	CTestData::getInstance()->SetPlayhandle(CurSel);
	std::auto_ptr<CPlayVideoWnd> pDlg(new CPlayVideoWnd);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
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
	GetFileCountAndSize();
}

void SearchFileUI::GetFileCountAndSize()
{
	std::vector<SearchFileInfo> _file_info;
	CTestData::getInstance()->GetSearchFiles(_file_info);
	size_t filesize = 0;
	int fileCount = _checked_files.size();
	for (size_t i = 0; i < _checked_files.size(); i++)
	{
		filesize += _file_info[_checked_files[i]].size;
	}

	CDuiString CountText;
	CountText.Format("files count is %d, size is %d", fileCount, filesize);
	_lab_CountText->SetText(CountText);

}



