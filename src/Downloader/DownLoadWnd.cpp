#include "stdafx.h"
#include "DownLoadWnd.h"
#include "CalendarUI.h"
#include "VideoLoginUI.h"
#include "SearchFileUI.h"
#include "ProgtessUI.h"

#include "RearchFile/SearchVideo.h" 
#include "Device.h" 
#include "DHVendor.h"

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


void DownLoadWnd::OnSelectTimeType()
{
	CSliderUI* Slider = static_cast<CSliderUI*>(m_PaintManager.FindControl(_T("Select_time")));
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
	CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
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
	CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
	Lab_time->SetText(strData.c_str());
}

void DownLoadWnd::OnVideoLoginWnd(TNotifyUI& msg)
{
	std::auto_ptr<VideoLoginUI> pDlg(new VideoLoginUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_CONTAINER, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void DownLoadWnd::OnSearchFileWnd()
{
	/*std::auto_ptr<CProgtessUI> pDlg(new CProgtessUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 1024, 600);
	pDlg->CenterWindow();
	pDlg->ShowModal();*/

		time_range range;
		range.start = 1467475200;
		range.end = 1467561600;

		m_Channel.push_back(1);
	 	//通过设备类来调用海康的SDK 
		DHVendor hkObj;
	 	//初始化设备类 
	 	Device dObj(&hkObj);
	 	//海康的登录 
		STDSTRING strIP(_T("192.168.0.96"));
		STDSTRING strUser(_T("admin"));
		STDSTRING strPswd(_T(""));
		BOOL bRet1 = dObj.Login(strIP, 37777, strUser, strPswd);


		//视频文件查询类 
		CSearchVideo svObj;
		svObj.SearchFile(&dObj, range, m_Channel);
	

		//保存文件查询的信息
		std::vector<readSearchVideo> RSVObj;
		BOOL bRet = svObj.ReadDataFromTable(RSVObj);
		if (bRet)
		{
			//pDlg->Close();
		}
	

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
		if (strSendName == _T("Search")){
			OnSearchFileWnd();
		}
		if (strSendName == _T("test"))
		{
			m_Vendor.AddVendorList();

		}
		if (strSendName == _T("test3"))
		{
			m_Vendor.ShowOfflineVendor();
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
		Show_Off_VendorList(strSendName);
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


BOOL DownLoadWnd::SearchFiles()
{
	return true;
	//m_fileInfo.clear();
	//search files
}

void DownLoadWnd::ShowFileList()
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));
	//pList->RemoveAll();
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, &m_PaintManager));
	pList->Add(SubList);

	STDSTRING SubListName = SUBLISTNAMETAG + to_string(m_FileCount);
	SubList->SetUserData(_T("0"));
	SubList->SetName(SubListName.c_str());
	CButtonUI* BT_CanCel = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
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
		SubListTmp = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, i));
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
	CListUI* m_List = static_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));

	int filesize = 5;
	STDSTRING strUserData;
	CListContainerElementUI* ContList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(m_List, strSendName.c_str()));
	int CurSel = GetSubListCurSel(ContList, m_List);
	CListContainerElementUI* SubContList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(m_List, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
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
				CButtonUI* BT_CanCel = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
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
				CButtonUI* BT_CanCel = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
		if (ContList->GetUserData() != _T("0") && SubContList->GetUserData() == _T("Sub"))
		{
			strUserData = ContList->GetUserData();
			int Count = StringToInt(strUserData.c_str());

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
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("DownloadList")));
	CButtonUI* bt_cancel = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(pList, strSendName.c_str()));
	STDSTRING tag = strSendName.substr(BTNAMELONG);
	STDSTRING SubListName = SUBLISTNAMETAG + tag;
	//CListContainerElementUI* ContList1 = (CListContainerElementUI*)(bt_cancel->GetParent());
	CListContainerElementUI* ContList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SubListName.c_str()));
	int ContListserial = GetSubListCurSel(ContList, pList);
	STDSTRING SubListCount = ContList->GetUserData();
	int Count = StringToInt(SubListCount.c_str());

	for (int i = 0; i <= Count; i++)
	{
		pList->RemoveAt(ContListserial, true);
	}
}

void DownLoadWnd::Show_Off_VendorList(STDSTRING& strSendName)
{
	CListUI* VendorList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CListContainerElementUI* Channel_List = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, _T("Channel_List")));
	CListContainerElementUI* CurSelList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, strSendName.c_str()));
	int CurSel = GetSubListCurSel(CurSelList, VendorList);
	if (Channel_List == NULL)
	{
		m_Vendor.AddChannelsList(CurSel);
	}
	else
	{
		int Channel_List_CurSel = GetSubListCurSel(Channel_List, VendorList);
		VendorList->RemoveAt(Channel_List_CurSel, true);
		if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel > CurSel)
		{
			m_Vendor.AddChannelsList(CurSel);
		}
		else if (Channel_List_CurSel != CurSel + 1 && Channel_List_CurSel < CurSel)
		{
			m_Vendor.AddChannelsList(CurSel - 1);
		}
	}
}

void DownLoadWnd::All_SelectChannels()
{
	CListUI* VendorList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	COptionUI* option_All = static_cast<COptionUI*>(m_PaintManager.FindSubControlByName(VendorList, _T("quanxuan")));
	CDuiPtrArray* array = m_PaintManager.FindSubControlsByClass(VendorList, DUI_CTR_OPTION);
	int option_size = array->GetSize();
	for (int i = 1; i < option_size; i++)
	{
		COptionUI* option = static_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(VendorList, DUI_CTR_OPTION, i));
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
	CListUI* VendorList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("VendorList")));
	CButtonUI* BT_delete = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(VendorList, strSendName.c_str()));
	STDSTRING Serial = strSendName.substr(9);
	STDSTRING ContListName = STDSTRING(_T("VendorContList")) + Serial;
	CListContainerElementUI* CurSelList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(VendorList, ContListName.c_str()));
	int CurSel = GetSubListCurSel(CurSelList, VendorList);
	CListContainerElementUI* NextList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(VendorList, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
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

	CLabelUI* Lab_time1 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText1")));
	CLabelUI* Lab_time2 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("DatatimeText2")));
	CLabelUI* Lab_time3 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("daytimeText2")));
	Lab_time1->SetText(ShowData.c_str());
	Lab_time2->SetText(ShowData.c_str());
	Lab_time3->SetText(ShowTime.c_str());
}

void DownLoadWnd::SetBtDataImage(STDSTRING& BT_Name, STDSTRING& day)
{
	if (day[0] == '0')
		day = day.substr(1);
	char strValue[200] = { 0 };
	sprintf_s(strValue, _T("file='skin/Data/%s.png' dest='15,8,39,39'"), day.c_str());
	STDSTRING pictureInfo(strValue);
	CButtonUI* btn_data = static_cast<CButtonUI*>(m_PaintManager.FindControl(BT_Name.c_str()));
	btn_data->SetAttribute(_T("foreimage"), pictureInfo.c_str());
}