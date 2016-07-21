#include "stdafx.h"
#include "SearchFileUI.h"
#include "PlayVideoWnd.h"
#include "SearchFileWorker.h"

#include "SearchDevice.h"

#include "FileLogInfoUI.h"


SearchFileUI::SearchFileUI()
:m_InitShowFileList(false)
{
	ReadDataFromTable();
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
			GetFileCountAndSize(SendName);
		}
		if (SendName == _T("All"))
		{
			CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
			COptionUI* option_All = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(pList, _T("All")));
			int nCount = pList->GetCount();
			for (int i = 1; i <= nCount; i++)
			{
				COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i));
				if (!option_All->IsSelected()){
					option->Selected(true);
				}
				else{
					option->Selected(false);
				}
			}
			GetFileCountAndSize(SendName);
		}
	}

	WindowImplBase::Notify(msg);
}


void SearchFileUI::OnShowFileList()
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
//	pList->RemoveAll();	
	STDSTRING optionName, buttonName, SubListName;
	int filesize = m_FileList.size();
	for (int i = 0; i < filesize; i++)
	{
		CDialogBuilder builder;
		CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//SearchFileList.xml"), (UINT)0, NULL, &m_PaintManager));
		pList->Add(SubList);
		COptionUI* SubOption = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_OPTION));
		CButtonUI* btn_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
		optionName = STDSTRING(_T("option")) + to_string(i);
		buttonName = STDSTRING(_T("BT_Play")) + to_string(i);
		SubListName = STDSTRING(_T("FileInfoList")) + to_string(i);
		SubOption->SetName(optionName.c_str());
		btn_play->SetName(buttonName.c_str());
		SubList->SetName(SubListName.c_str());
		

		CLabelUI* Lab_Name = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
		CLabelUI* Lab_Channel = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
		CLabelUI* Lab_stime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
		CLabelUI* Lab_etime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
		CLabelUI* Lab_size = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));

		STDSTRING filename = m_FileList[i].get<0>();
		int Channel = m_FileList[i].get<1>();
		__time64_t stime = m_FileList[i].get<2>();
		__time64_t etime = m_FileList[i].get<3>();
		__int64 size = m_FileList[i].get<4>();
		int ID = m_FileList[i].get<5>();
		STDSTRING startTime = TimeChange(stime);
		STDSTRING stopTime = TimeChange(etime);
		STDSTRING strSize = to_string(size / (1024 * 1024)) + STDSTRING(_T("M"));

		Lab_Name->SetText(filename.c_str());
		Lab_Channel->SetText(to_string(Channel).c_str());
		Lab_stime->SetText(startTime.c_str());
		Lab_etime->SetText(stopTime.c_str());
		Lab_size->SetText(strSize.c_str());
	}
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
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	CButtonUI* bt_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(pList, SendName.c_str()));
	STDSTRING btName = bt_play->GetName();
	STDSTRING nametag = btName.substr(7);
	STDSTRING SubListName = STDSTRING(_T("FileInfoList")) + nametag;
	CListContainerElementUI* SubList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SubListName.c_str()));

	CLabelUI* Lab_name = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* Lab_Channel = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* Lab_stime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
	CLabelUI* Lab_etime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));

	
	STDSTRING filename = Lab_name->GetText();
	STDSTRING channel = Lab_Channel->GetText();
	STDSTRING stime = Lab_stime->GetText();
	STDSTRING etime = Lab_etime->GetText();

	OnPlayVideo(filename, channel, stime, etime);
}

void SearchFileUI::OnPlayVideo(STDSTRING& filename, STDSTRING& channel, STDSTRING& stime, STDSTRING& etime)
{
	std::auto_ptr<CPlayVideoWnd> pDlg(new CPlayVideoWnd);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void SearchFileUI::GetFileCountAndSize(STDSTRING& optionName)
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	int SubListCount = pList->GetCount();
	__int64 filesize = 0;
	int fileCount = 0;
	if (SubListCount != 0)
	{
		for (int i = 0; i < SubListCount; i++)
		{
			COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i + 1));	
			if (option->IsSelected())
			{
				filesize += m_FileList[i].get<4>();
				fileCount++;
			}
		}
	}
	if (!optionName.compare(0, 6, _T("option")))
	{
		COptionUI* SelectOption = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(pList, optionName.c_str()));
		STDSTRING nameTag = optionName.substr(6);
		int CurSel = stoi(nameTag);
		
		if (!SelectOption->IsSelected())
		{
			filesize += m_FileList[CurSel].get<4>();
			fileCount += 1;
		}
		else
		{
			filesize -= m_FileList[CurSel].get<4>();
			fileCount -= 1;
		}
	}
	
	CLabelUI* Lab = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("file_Count")));
	char str[200] = { 0 };
	filesize = filesize / (1024 * 1024);
	if (filesize > 1024)
	{
		float file_size = (float)filesize / 1024;
		sprintf_s(str, "提示：共选中文件%d个，总文件大小%6.2fG！", fileCount, file_size);
	}
	else{
		sprintf_s(str, "提示：共选中文件%d个，总文件大小%dM！", fileCount, filesize);
	}
	STDSTRING LabText(str);
	Lab->SetText(LabText.c_str());
}

bool SearchFileUI ::ReadDataFromTable()
{
	m_FileList.clear();

	QMSqlite *pDb = QMSqlite::getInstance();
	std::string strSql = SELECT_ALL_SEARCH_VIDEO;
	return pDb->GetData(strSql, m_FileList);
}
