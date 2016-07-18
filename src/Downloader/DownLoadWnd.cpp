#include "stdafx.h"
#include "DownLoadWnd.h"
#include "CalendarUI.h"
#include "VideoLoginUI.h"
#include "SearchFileUI.h"
#include "ProgtessUI.h"

#include "SearchVideo.h"
#include "SearchDevice.h"

DownLoadWnd::DownLoadWnd()
:m_FileCount(1), m_beginTag(TRUE)
{
	m_Vendor.SetPaintMagager(&m_PaintManager);
	AddVirtualWnd(_T("Vendor"), &m_Vendor);
}


DownLoadWnd::~DownLoadWnd()
{
	RemoveVirtualWnd(_T("Vendor"));
}


DUI_BEGIN_MESSAGE_MAP(DownLoadWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_OnVideoLoginUI, OnVideoLoginWnd)
DUI_ON_CLICK_CTRNAME(BT_SEARCHFILE, OnSearchFileWnd)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_D, OnCloseWnd)
DUI_END_MESSAGE_MAP()

LPCTSTR DownLoadWnd::GetWindowClassName() const
{
	return _T("DownLoadWnd");
}

CDuiString DownLoadWnd::GetSkinFolder()
{
	return _T("skin");
}

CDuiString DownLoadWnd::GetSkinFile()
{
	return _T("xml\\Download.xml");
}

void DownLoadWnd::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void DownLoadWnd::OnCloseWnd(TNotifyUI& msg)
{
	Close();
}

void DownLoadWnd::OnSelectTimeType()
{
	CSliderUI* Slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("Select_time")));
	if (Slider->GetValue() > 50)
	{
		Slider->SetValue(100);
	}
	else
	{
		Slider->SetValue(0);
	}
}

void DownLoadWnd::OnSelectCalendar(STDSTRING& SendName)
{
	
	std::auto_ptr<CalendarUI> pDlg(new CalendarUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	STDSTRING strData = pDlg->GetData();
	STDSTRING NameTag = SendName.substr(SendName.length() - 1);
	STDSTRING Lab_name = STDSTRING(_T("DatatimeText")) + NameTag;
	STDSTRING Btn_name = STDSTRING(_T("DataTime")) + NameTag;
	CLabelUI* Lab_time = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
	Lab_time->SetText(strData.c_str());
	
	STDSTRING day = strData.substr(strData.length() - 2);
	SetBtDataImage(Btn_name, day);
}

void DownLoadWnd::OnSelectDayTime(STDSTRING& SendName)
{
	std::auto_ptr<CTimeUI> pDlg(new CTimeUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	STDSTRING strData = pDlg->GetTime();
	STDSTRING NameTag = SendName.substr(SendName.length() - 1);
	STDSTRING Lab_name = STDSTRING(_T("daytimeText")) + NameTag;
	CLabelUI* Lab_time = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
	Lab_time->SetText(strData.c_str());
}

void DownLoadWnd::OnVideoLoginWnd(TNotifyUI& msg)
{
	std::auto_ptr<VideoLoginUI> pDlg(new VideoLoginUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();

	pDlg->LogIn();
	m_Device = pDlg->GetLonInDevice();
	if (m_Device == nullptr)
		return;
	m_ChannelCount = m_Device->getMaxChannel();
	NET_SDK_TYPE VendorType = m_Device->GetSDKType();
	STDSTRING strVendor = to_string(VendorType);
	STDSTRING strIP = m_Device->getIP();
	m_Vendor.AddVendorList(strVendor, strIP);

}

void DownLoadWnd::OnSearchFileWnd(TNotifyUI& msg)
{
	/*std::auto_ptr<CProgtessUI> pDlg(new CProgtessUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 1024, 600);
	pDlg->CenterWindow();
	pDlg->ShowModal();*/
	SearchFile();

	std::auto_ptr<SearchFileUI> pSearchDlg(new SearchFileUI);
	assert(pSearchDlg.get());
	pSearchDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 1024, 600);
	pSearchDlg->CenterWindow();
	pSearchDlg->ShowModal();
}

void DownLoadWnd::Notify(TNotifyUI& msg)
{
	if (m_beginTag)
	{
		InitTime();
		m_beginTag = FALSE;
	}
	STDSTRING strSendName = msg.pSender->GetName();
	if (msg.sType == DUI_MSGTYPE_VALUECHANGED && strSendName == _T("Select_time")){
		OnSelectTimeType();
	}
	if (msg.sType == DUI_MSGTYPE_ITEMCLICK && !strSendName.compare(0, SUBLISTNAMELONG, SUBLISTNAMETAG)){
		Show_Off_SubList(strSendName);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK){
		if (strSendName == BT_Calendar1 || strSendName == BT_Calendar2){
			OnSelectCalendar(strSendName);
		}
		if (strSendName == BT_TIMEWND1 || strSendName == BT_TIMEWND2){
			OnSelectDayTime(strSendName);		
		}
		if (strSendName == _T("test2"))
		{
			ShowFileList();
		}
		if (!strSendName.compare(0, BTNAMELONG, BTNAMETAG))
		{
 			RemoveSubList(strSendName);
		}
	}
	if (msg.sType == DUI_MSGTYPE_ITEMCLICK && !strSendName.compare(0, 14, _T("VendorContList")))
	{
		Show_Off_VendorList(strSendName, m_ChannelCount);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && strSendName == _T("quanxuan"))
	{
		All_SelectChannels();
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && !strSendName.compare(0, 9, _T("BT_delete")))
	{
		RemoveVendor(strSendName);
	}
	WindowImplBase::Notify(msg);
}


void DownLoadWnd::SearchFile()
{	
	GetChannel();
	GetDataTime();

	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CListContainerElementUI* Channel_List = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, _T("Channel_List")));
	if (Channel_List == NULL)
	{
		return;
	}
	int CurSel = GetSubListCurSel(Channel_List, pList) - 1;
	CListContainerElementUI* CurSel_List = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, CurSel));
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(CurSel_List, DUI_CTR_LABEL, 1));
	STDSTRING strIP = Lab_IP->GetText();
	m_Device = CLoginDevice::getInstance().GetDevice(strIP);
	
  	CSearchVideo::getInstance().SearchFile(m_Device, m_timeRangeSearch, m_Channel);

}

void DownLoadWnd::GetChannel()
{
	m_Channel.clear();
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CDuiPtrArray* array = m_PaintManager.FindSubControlsByClass(pList, DUI_CTR_OPTION);
	int option_size = array->GetSize();
	for (int i = 1; i < option_size; i++)
	{
		COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i));
		if (option->IsSelected())
		{
			m_Channel.push_back(i - 1);
		}
	}
}

void DownLoadWnd::GetDataTime()
{
	CLabelUI* Lab_StartData = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText1")));
	CLabelUI* Lab_StopData = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText2")));
	CLabelUI* Lab_StartTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("daytimeText1")));
	CLabelUI* Lab_StopTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("daytimeText2")));
	STDSTRING sData = Lab_StartData->GetText();
	STDSTRING sTime = Lab_StartTime->GetText();
	STDSTRING eData = Lab_StopData->GetText();
	STDSTRING eTime = Lab_StopTime->GetText();

	struct tm startTime, stopTime;
	startTime = { 0 };
	stopTime = { 0 };
	
	sscanf(sData.c_str(), "%d-%d-%d", &startTime.tm_year, &startTime.tm_mon, &startTime.tm_mday);
	sscanf(sTime.c_str(), "%d:%d", &startTime.tm_hour, &startTime.tm_min);

	sscanf(eData.c_str(), "%d-%d-%d", &stopTime.tm_year, &stopTime.tm_mon, &stopTime.tm_mday);
	sscanf(eTime.c_str(), "%d:%d", &stopTime.tm_hour, &stopTime.tm_min);

	startTime.tm_year -= 1900;
	startTime.tm_mon -= 1;
	stopTime.tm_year -= 1900;
	stopTime.tm_mon -= 1;
	m_timeRangeSearch.start = mktime(&startTime);
	m_timeRangeSearch.end = mktime(&stopTime);
}

void DownLoadWnd::ShowFileList()
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, &m_PaintManager));
	pList->Add(SubList);

	STDSTRING SubListName = SUBLISTNAMETAG + to_string(m_FileCount);
	SubList->SetUserData(_T("0"));
	SubList->SetName(SubListName.c_str());
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
	STDSTRING bt_name = BTNAMETAG + to_string(m_FileCount);
	BT_CanCel->SetName(bt_name.c_str());
	m_FileCount = m_FileCount + 1;

}

CListContainerElementUI* DownLoadWnd::Add_FileInfoList()
{
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, &m_PaintManager));
	SubList->SetAttribute(_T("inset"), _T("30,0,0,0"));
	return SubList;
}

int DownLoadWnd::GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList)
{
	CListContainerElementUI* SubListTmp = new CListContainerElementUI;
	int CurSel = -1;
	for (int i = 0; i < pList->GetCount(); i++)
	{
		SubListTmp = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, i));
		if (SubListTmp->GetName() == SubList->GetName())
		{
			CurSel = i;
			break;
		}
	}
	return CurSel;
}

void DownLoadWnd::Show_Off_SubList(STDSTRING& strSendName)
{
	CListUI* m_List = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));

	int filesize = 5;
	STDSTRING strUserData;
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(m_List, strSendName.c_str()));
	int CurSel = GetSubListCurSel(ContList, m_List);
	CListContainerElementUI* SubContList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(m_List, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
	if (SubContList == NULL)
	{
		if (ContList->GetUserData() == _T("0"))
		{
			CListContainerElementUI* SubList = new CListContainerElementUI;
			for (int i = CurSel + 1; i <= CurSel + filesize; i++)
			{
				SubList = Add_FileInfoList();
				SubList->SetUserData(_T("Sub"));
				m_List->AddAt(SubList, i);
				CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
	}
	else{
		if (ContList->GetUserData() == _T("0") && SubContList->GetUserData() != _T("Sub"))
		{
			CListContainerElementUI* SubList = new CListContainerElementUI;
			for (int i = CurSel + 1; i <= CurSel + filesize; i++)
			{
				SubList = Add_FileInfoList();
				SubList->SetUserData(_T("Sub"));
				m_List->AddAt(SubList, i);
				CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
		if (ContList->GetUserData() != _T("0") && SubContList->GetUserData() == _T("Sub"))
		{
			strUserData = ContList->GetUserData();
			int Count = stoi(strUserData.c_str());

			for (int j = CurSel + 1; j <= CurSel + Count; j++)
			{
				m_List->RemoveAt(CurSel + 1, false);
			}
			ContList->SetUserData(_T("0"));
		}
	}
}

void DownLoadWnd::RemoveSubList(STDSTRING& strSendName)
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));
	CButtonUI* bt_cancel = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(pList, strSendName.c_str()));
	STDSTRING tag = strSendName.substr(BTNAMELONG);
	STDSTRING SubListName = SUBLISTNAMETAG + tag;
	//CListContainerElementUI* ContList1 = (CListContainerElementUI*)(bt_cancel->GetParent());
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SubListName.c_str()));
	int ContListserial = GetSubListCurSel(ContList, pList);
	STDSTRING SubListCount = ContList->GetUserData();
	int Count = stoi(SubListCount.c_str());

	for (int i = 0; i <= Count; i++)
	{
		pList->RemoveAt(ContListserial, true);
	}
}

void DownLoadWnd::Show_Off_VendorList(STDSTRING& strSendName, size_t Channel_Count)
{
	CListUI* VendorList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CListContainerElementUI* Channel_List = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, _T("Channel_List")));
	CListContainerElementUI* CurSelList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, strSendName.c_str()));
	int CurSel = GetSubListCurSel(CurSelList, VendorList);
	if (Channel_List == NULL)
	{
		m_Vendor.AddChannelsList(CurSel, Channel_Count);
	}
	else
	{
		int Channel_List_CurSel = GetSubListCurSel(Channel_List, VendorList);
		VendorList->RemoveAt(Channel_List_CurSel, true);
		if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel > CurSel)
		{
			m_Vendor.AddChannelsList(CurSel, Channel_Count);
		}
		else if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel < CurSel)
		{
			m_Vendor.AddChannelsList(CurSel - 1, Channel_Count);
		}
	}
}

void DownLoadWnd::All_SelectChannels()
{
	CListUI* VendorList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	COptionUI* option_All = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(VendorList, _T("quanxuan")));
	CDuiPtrArray* array = m_PaintManager.FindSubControlsByClass(VendorList, DUI_CTR_OPTION);
	int option_size = array->GetSize();
	for (int i = 1; i < option_size; i++)
	{
		COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(VendorList, DUI_CTR_OPTION, i));
		if (!option_All->IsSelected()){
			option->Selected(true);
		}
		else{
			option->Selected(false);
		}
	}
}

void DownLoadWnd::RemoveVendor(STDSTRING& strSendName)
{
	CListUI* VendorList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CButtonUI* BT_delete = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(VendorList, strSendName.c_str()));
	STDSTRING Serial = strSendName.substr(9);
	STDSTRING ContListName = STDSTRING(_T("VendorContList")) + Serial;
	CListContainerElementUI* CurSelList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, ContListName.c_str()));
	int CurSel = GetSubListCurSel(CurSelList, VendorList);
	CListContainerElementUI* NextList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(VendorList, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
	if (NextList != NULL && NextList->GetName() == _T("Channel_List"))
	{
		VendorList->RemoveAt(CurSel + 1, true);
	}
	VendorList->RemoveAt(CurSel, true);
}

void DownLoadWnd::InitTime()
{
	::GetLocalTime(&m_sysTime);
	char strData[100] = { 0 };
	char strTime[100] = { 0 };
	sprintf_s(strData, "%d-%02d-%02d", m_sysTime.wYear, m_sysTime.wMonth, m_sysTime.wDay);
	sprintf_s(strTime, "%02d:%02d", m_sysTime.wHour, m_sysTime.wMinute);
	STDSTRING ShowData(strData);
	STDSTRING ShowTime(strTime);
	STDSTRING day = to_string(m_sysTime.wDay);

	SetBtDataImage(STDSTRING(_T("DataTime1")), day);
	SetBtDataImage(STDSTRING(_T("DataTime2")), day);

	CLabelUI* Lab_time1 = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText1")));
	CLabelUI* Lab_time2 = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText2")));
	CLabelUI* Lab_time3 = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("daytimeText2")));
	Lab_time1->SetText(ShowData.c_str());
	Lab_time2->SetText(ShowData.c_str());
	Lab_time3->SetText(ShowTime.c_str());
}

void DownLoadWnd::SetBtDataImage(STDSTRING& BT_Name, STDSTRING& day)
{	
	int days = stoi(day);
	char strValue[200] = { 0 };
	sprintf_s(strValue, _T("file='skin/Data/%d.png' dest='15,8,39,39'"), days);
	STDSTRING pictureInfo(strValue);
	CButtonUI* btn_data = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(BT_Name.c_str()));
	btn_data->SetAttribute(_T("foreimage"), pictureInfo.c_str());
}