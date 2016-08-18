#include "stdafx.h"
#include "DownLoadWnd.h"
#include "CalendarUI.h"
#include "VideoLoginUI.h"
#include "SearchFileUI.h"
#include "ProgtessUI.h"

DownLoadWnd::DownLoadWnd()
:m_FileCount(1), m_beginTag(TRUE)
{
	ReadJsonFile();
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

void DownLoadWnd::InitWindow()
{
}

void DownLoadWnd::HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf)
{
}

void DownLoadWnd::SetNetWorkState(NOTIFICATION_TYPE& eNotify)
{
	CControlUI* NetWorkUI = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
	if (eNotify == Notification_Type_Network_status_Connect)
		NetWorkUI->SetBkImage(_T("skin/network_online.png"));
	else if (eNotify == Notification_Type_Network_status_Disconnect)
		NetWorkUI->SetBkImage(_T("skin/network_offline.png"));
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

void DownLoadWnd::ShowOnlineDevice()
{
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
}

void DownLoadWnd::OnSearchFileWnd(TNotifyUI& msg)
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	std::auto_ptr<CProgtessUI> pDlg(new CProgtessUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	
	std::auto_ptr<SearchFileUI> pSearchDlg(new SearchFileUI(m_Device));
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
		ShowOnlineDevice();
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
			ShowTotalFileList();
		}
		if (!strSendName.compare(0, BTNAMELONG, BTNAMETAG))
		{
 			RemoveSubList(strSendName);
		}
	}
	if (msg.sType == DUI_MSGTYPE_ITEMCLICK && !strSendName.compare(0, 14, _T("VendorContList")))
	{
		Show_Off_VendorList(strSendName);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && strSendName == _T("quanxuan"))
	{
		All_SelectChannels();
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && !strSendName.compare(0, 7, _T("channel")))
	{
		OnUseSearchCtrl(strSendName);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && !strSendName.compare(0, 9, _T("BT_delete")))
	{
		RemoveVendor(strSendName);
	}
	WindowImplBase::Notify(msg);
}

void DownLoadWnd::OnUseSearchCtrl(std::string& SendName)
{
	CButtonUI* bt_search = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Search")));
	CListUI* VendorList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CDuiPtrArray* array = m_PaintManager.FindSubControlsByClass(VendorList, DUI_CTR_OPTION);
	int option_size = array->GetSize();
	for (int i = 1; i < option_size; i++)
	{
		COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(VendorList, DUI_CTR_OPTION, i));
		std::string strName = option->GetName();
		if (option->IsSelected() && SendName != strName)
		{
			bt_search->SetEnabled(true);
			return;
		}
	}
	COptionUI* TOption = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByName(VendorList, SendName.c_str()));
	if (TOption->IsSelected() == false && SendName.compare(_T("quanxuan")))
	{
		bt_search->SetEnabled(true);
		return;
	}
	bt_search->SetEnabled(false);
}

void DownLoadWnd::SearchFile()
{	
	GetDataTime();
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

void DownLoadWnd::ShowTotalFileList()
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

	CLabelUI* lab_name = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_size = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lastTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_state = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));
	lab_name->SetText("name");
	lab_size->SetText("size");
	lab_speed->SetText("speed");
	lab_lastTime->SetText("01:20");
	lab_state->SetText("finish");

	m_FileCount = m_FileCount + 1;

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

void DownLoadWnd::AddSubFileList(size_t CurSel)
{
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, &m_PaintManager));

	CListUI* m_List = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));
	m_List->AddAt(SubList, CurSel);
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
	CLabelUI* lab_name = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_size = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lastTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_state = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));
	SubList->SetAttribute(_T("inset"), _T("30,0,0,0"));
	SubList->SetUserData(_T("Sub"));
	BT_CanCel->SetVisible(false);
	lab_name->SetText("name");
	lab_size->SetText("size");
	lab_speed->SetText("speed");
	lab_lastTime->SetText("01:20");
	lab_state->SetText("finish");	
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
			for (int i = CurSel + 1; i <= CurSel + filesize; i++)
			{
				AddSubFileList(i);
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
	}
	else{
		if (ContList->GetUserData() == _T("0") && SubContList->GetUserData() != _T("Sub"))
		{
			for (int j = CurSel + 1; j <= CurSel + filesize; j++)
			{
				AddSubFileList(j);
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
		if (ContList->GetUserData() != _T("0") && SubContList->GetUserData() == _T("Sub"))
		{
			strUserData = ContList->GetUserData();
			int Count = stoi(strUserData);

			for (int k = CurSel + 1; k <= CurSel + Count; k++)
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
	int Count = stoi(SubListCount);

	for (int i = 0; i <= Count; i++)
	{
		pList->RemoveAt(ContListserial, true);
	}
}

void DownLoadWnd::Show_Off_VendorList(STDSTRING& strSendName)
{
	CListUI* VendorList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CListContainerElementUI* Channel_List = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, _T("Channel_List")));
	CListContainerElementUI* CurSelList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, strSendName.c_str()));
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(CurSelList, DUI_CTR_LABEL, 1));
	m_DeviceID = Lab_IP->GetText();
	int CurSel = GetSubListCurSel(CurSelList, VendorList);

	if (Channel_List == NULL)
	{
		//m_Vendor.AddChannelsList(CurSel, Channel_Count);
	}
	else
	{
		int Channel_List_CurSel = GetSubListCurSel(Channel_List, VendorList);
		VendorList->RemoveAt(Channel_List_CurSel, true);
		if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel > CurSel)
		{
			//m_Vendor.AddChannelsList(CurSel, Channel_Count);
		}
		else if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel < CurSel)
		{
			//m_Vendor.AddChannelsList(CurSel - 1, Channel_Count);
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
			OnUseSearchCtrl(std::string(_T("quanxuan")));
		}
		else{
			option->Selected(false);
			OnUseSearchCtrl(std::string(_T("quanxuan")));
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
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(CurSelList, DUI_CTR_LABEL, 1));
	if (NextList != NULL && NextList->GetName() == _T("Channel_List"))
	{
		VendorList->RemoveAt(CurSel + 1, true);
	}
	VendorList->RemoveAt(CurSel, true);
	
	STDSTRING strIP = Lab_IP->GetText();
	//CLoginDevice::getInstance().Logout(strIP);
	for (size_t i = 0; i < m_onlineIP.size(); i++)
	{
		if (m_onlineIP[i] == strIP)
		{
			m_onlineIP.erase(m_onlineIP.begin() + i);
		}
	}
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

void DownLoadWnd::ReadJsonFile()
{
	STDSTRING configFile;
	TCHAR PATH[MAX_PATH] = { 0 };
	STDSTRING AppPath = STDSTRING(PATH, ::GetModuleFileNameA(NULL, PATH, MAX_PATH));
	configFile = AppPath.substr(0, AppPath.find_last_of("\\") + 1) + STDSTRING(_T("Device.json"));

	ifstream ifs(configFile);
	locale utf8;
	ifs.imbue(utf8);
	IStreamWrapper isw(ifs);
	Document d;
	d.ParseStream(isw);
	size_t file_size = isw.Tell();
	if (isw.Tell() == 0)
		return;

	typedef Value::ConstMemberIterator Iter;
	for (Iter it = d.MemberBegin(); it != d.MemberEnd(); it++)
	{
		STDSTRING TypeName = it->name.GetString();
		const Value& a = d[TypeName.c_str()];
		assert(a.IsArray());
		if (!a.IsArray())
			continue;
		STDSTRING spell = a[0].GetString();
		STDSTRING VendorDeviceName = a[1].GetString();

		int type = stoi(TypeName);
		m_VnameAndType.insert(pair<int, string>(type, VendorDeviceName));
	}
}