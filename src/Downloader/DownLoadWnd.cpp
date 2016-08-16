#include "stdafx.h"
#include "DownLoadWnd.h"
#include "CalendarUI.h"
#include "VideoLoginUI.h"
#include "SearchFileUI.h"
#include "ProgtessUI.h"

#define	BT_Calendar1			(_T("DataTime1"))
#define	BT_Calendar2			(_T("DataTime2"))
#define BT_OnVideoLoginUI		(_T("Add_device"))
#define BTNAMELONG				9
#define SUBLISTNAMELONG				8
#define BTNAMETAG				(_T("BT_Cancel"))
#define SUBLISTNAMETAG			(_T("ContList"))
#define BT_TIMEWND1				(_T("daytime1"))
#define BT_TIMEWND2				(_T("daytime2"))
#define BT_SEARCHFILE			(_T("Search"))
#define BT_CLOSE_D				(_T("CloseWnd"))


#define STARTDATE				(_T("DatatimeText1"))
#define STOPDATE				(_T("DatatimeText2"))
#define STARTTIME				(_T("daytimeText1"))
#define STOPTIME				(_T("daytimeText2"))

#define CTR_SELECT_TIME			(_T("Select_time"))
#define CTR_CHANNEL				(_T("channel"))

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
DUI_ON_CLICK_CTRNAME(BT_OnVideoLoginUI, OnLogin)
DUI_ON_CLICK_CTRNAME(BT_SEARCHFILE, OnSearch)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_D, OnCloseWnd)

DUI_ON_CLICK_CTRNAME(BT_Calendar1, OnSelectCalendar)
DUI_ON_CLICK_CTRNAME(BT_Calendar2, OnSelectCalendar)

DUI_ON_CLICK_CTRNAME(BT_TIMEWND1, OnSelectDayTime)
DUI_ON_CLICK_CTRNAME(BT_TIMEWND2, OnSelectDayTime)

DUI_ON_CLICK_CTRNAME(CTR_CHANNEL, OnUseSearchCtrl)

DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_VALUECHANGED, CTR_SELECT_TIME, OnSelectTimeType)
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

void DownLoadWnd::BuildControlDDX()
{
	_StartDate = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(STARTDATE));
	_StopDate = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(STOPDATE));
	_StartTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(STARTTIME));
	_StopTime = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(STOPTIME));
}

void DownLoadWnd::InitWindow()
{
}

void DownLoadWnd::OnSelectTimeType(TNotifyUI& msg)
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

void DownLoadWnd::OnSelectCalendar(TNotifyUI& msg)
{
	std::auto_ptr<CalendarUI> pDlg(new CalendarUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	std::string strData = pDlg->GetData();
	if (strData.empty()) return;
	//set datetime's text and image
	//CDuiString pSender = msg.pSender->GetName();
	//std::string NameTag = pSender[pSender.GetLength()];
	//std::string Lab_name = std::string(_T("DatatimeText")) + NameTag;
	//std::string Btn_name = std::string(_T("DataTime")) + NameTag;
	//CLabelUI* Lab_time = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
	//Lab_time->SetText(strData.c_str());
	//
	//std::string day = strData.substr(strData.length() - 2);//Esc crash
	//SetBtDataImage(Btn_name, day);
}

void DownLoadWnd::OnSelectDayTime(TNotifyUI& msg)
{
	std::auto_ptr<CTimeUI> pDlg(new CTimeUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();

	
	std::string strData = pDlg->GetTime();
	//set datetime 's text
	/*
	std::string NameTag = SendName.substr(SendName.length() - 1);
	std::string Lab_name = std::string(_T("daytimeText")) + NameTag;
	CLabelUI* Lab_time = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(Lab_name.c_str()));
	Lab_time->SetText(strData.c_str());
	*/
}

void DownLoadWnd::OnLogin(TNotifyUI& msg)
{
	std::auto_ptr<VideoLoginUI> pDlg(new VideoLoginUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 1024, 768, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
}

void DownLoadWnd::OnSearch(TNotifyUI& msg)
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
		//ShowOnlineDevice();
		m_beginTag = FALSE;
	}
	/*std::string strSendName = msg.pSender->GetName();
	if (msg.sType == DUI_MSGTYPE_VALUECHANGED && strSendName == _T("Select_time")){
		OnSelectTimeType();
	}
	
	if (msg.sType == DUI_MSGTYPE_CLICK){
		if (strSendName == BT_Calendar1 || strSendName == BT_Calendar2){
			OnSelectCalendar(strSendName);
		}
		if (strSendName == BT_TIMEWND1 || strSendName == BT_TIMEWND2){
			OnSelectDayTime(strSendName);		
		}
		
	}
	
	
	if (msg.sType == DUI_MSGTYPE_CLICK && !strSendName.compare(0, 7, _T("channel")))
	{
		OnUseSearchCtrl(strSendName);
	}*/
	
	WindowImplBase::Notify(msg);
}

void DownLoadWnd::OnUseSearchCtrl(TNotifyUI& msg)
{
	_SearchControl->SetEnabled(false);
}

void DownLoadWnd::InitTime()
{
	::GetLocalTime(&m_sysTime);

	CDuiString date, time;
	date.Format("%d-%02d-%02d", m_sysTime.wYear, m_sysTime.wMonth, m_sysTime.wDay);
	time.Format("%02d:%02d", m_sysTime.wHour, m_sysTime.wMinute);

	std::string day = std::to_string(m_sysTime.wDay);

	SetBtDataImage(std::string(_T("DataTime1")), day);
	SetBtDataImage(std::string(_T("DataTime2")), day);

	_StartDate->SetText(date);
	_StopDate->SetText(date);
	_StopTime->SetText(time);
}

void DownLoadWnd::SetBtDataImage(std::string& BT_Name, std::string& day)
{	
	int days = stoi(day);
	char strValue[200] = { 0 };
	sprintf_s(strValue, _T("file='skin/Data/%d.png' dest='15,8,39,39'"), days);
	std::string pictureInfo(strValue);
	CButtonUI* btn_data = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(BT_Name.c_str()));
	btn_data->SetAttribute(_T("foreimage"), pictureInfo.c_str());
}

void DownLoadWnd::ReadJsonFile()
{
	std::string configFile;
	TCHAR PATH[MAX_PATH] = { 0 };
	std::string AppPath = std::string(PATH, ::GetModuleFileNameA(NULL, PATH, MAX_PATH));
	configFile = AppPath.substr(0, AppPath.find_last_of("\\") + 1) + std::string(_T("Device.json"));

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
		std::string TypeName = it->name.GetString();
		const Value& a = d[TypeName.c_str()];
		assert(a.IsArray());
		if (!a.IsArray())
			continue;
		std::string spell = a[0].GetString();
		std::string VendorDeviceName = a[1].GetString();

		int type = stoi(TypeName);
		m_VnameAndType.insert(pair<int, string>(type, VendorDeviceName));
	}
}