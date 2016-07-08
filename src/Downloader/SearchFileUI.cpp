#include "stdafx.h"
#include "SearchFileUI.h"
#include "PlayVideoWnd.h"




SearchFileUI::SearchFileUI()
{
}


SearchFileUI::~SearchFileUI()
{
}

DUI_BEGIN_MESSAGE_MAP(SearchFileUI, WindowImplBase)
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

void SearchFileUI::Notify(TNotifyUI& msg)
{	
	if (msg.sType == DUI_MSGTYPE_CLICK){
		STDSTRING SendName = msg.pSender->GetName();
		if (SendName == _T("close_bt"))
		{
			Close();
		}
		if (SendName == _T("test"))
		{
			SearchTest();
		}
		if (!SendName.compare(0, 6, _T("option")))
		{
			GetFileCountAndSize();
		}
		if (SendName == _T("All"))
		{
			CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
			COptionUI* option_All = static_cast<COptionUI*>(m_PaintManager.FindSubControlByName(pList, _T("All")));
			int nCount = pList->GetCount();
			for (int i = 1; i <= nCount; i++)
			{
				COptionUI* option = static_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i));
				if (!option_All->IsSelected()){
					option->Selected(true);
				}
				else{
					option->Selected(false);
				}
			}
			GetFileCountAndSize();
		}
		if (!SendName.compare(0, 7, _T("BT_Play")))
		{
			std::auto_ptr<CPlayVideoWnd> pSearchDlg(new CPlayVideoWnd);
			assert(pSearchDlg.get());
			pSearchDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
			pSearchDlg->CenterWindow();
			pSearchDlg->ShowModal();
		//	GetFileInfo(SendName);
		}
	}

	WindowImplBase::Notify(msg);
}


void SearchFileUI::SearchTest()
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
//	pList->RemoveAll();	
	STDSTRING optionName, buttonName, SubListName;
	int filesize = 10;
	for (int i = 0; i < filesize; i++)
	{
		CDialogBuilder builder;
		CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//SearchFileList.xml"), (UINT)0, NULL, &m_PaintManager));
		pList->Add(SubList);
		COptionUI* SubOption = static_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_OPTION));
		CButtonUI* btn_play = static_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
		optionName = STDSTRING(_T("option")) + to_string(i);
		buttonName = STDSTRING(_T("BT_Play")) + to_string(i);
		SubListName = STDSTRING(_T("FileInfoList")) + to_string(i);
		SubOption->SetName(optionName.c_str());
		btn_play->SetName(buttonName.c_str());
		SubList->SetName(SubListName.c_str());

		CLabelUI* Lab_Name = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
		CLabelUI* Lab_Channel = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
		CLabelUI* Lab_stime = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
		CLabelUI* Lab_etime = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
		CLabelUI* Lab_size = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));

		Lab_Name->SetText(to_string(i).c_str());
		Lab_Channel->SetText(to_string(i).c_str());
		Lab_stime->SetText(to_string(i).c_str());
		Lab_etime->SetText(to_string(i).c_str());
		Lab_size->SetText(to_string(i).c_str());
	}
}


void SearchFileUI::GetFileInfo(STDSTRING& SendName)
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	CButtonUI* bt_play = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(pList, SendName.c_str()));
	STDSTRING btName = bt_play->GetName();
	STDSTRING nametag = btName.substr(7);
	STDSTRING SubListName = STDSTRING(_T("FileInfoList")) + nametag;
	CListContainerElementUI* SubList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SubListName.c_str()));

	CLabelUI* Lab_name = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* Lab_Channel = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* Lab_stime = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
	CLabelUI* Lab_etime = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));

	
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

void SearchFileUI::GetFileCountAndSize()
{
	int file_Count = 0;
	int file_size = 0;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("domainlist")));
	int SubListCount = pList->GetCount();
	if (SubListCount != 0)
	{
		for (int i = 0; i <= SubListCount; i++)
		{
			COptionUI* option = static_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i + 1));
			if (option->IsSelected())
			{
				file_Count++;
			}
		}
		 
	}

	//CLabelUI* Lab = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("file_Count")));
	//char str[200] = { 0 };
	//sprintf_s(str, "提示：共选中文件%d个，总文件大小%dM！", file_Count, 100);
	//STDSTRING LabText(str);
	//Lab->SetText(LabText.c_str());
}
