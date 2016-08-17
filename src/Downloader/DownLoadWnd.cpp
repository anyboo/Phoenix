#include "stdafx.h"
#include "DownLoadWnd.h"
#include "CalendarUI.h"
#include "VideoLoginUI.h"
#include "SearchFileUI.h"
#include "ProgtessUI.h"

DownLoadWnd::DownLoadWnd()
{
	ReadJsonFile();
	m_Vendor.SetPaintMagager(&m_PaintManager);
	AddVirtualWnd(_T("Vendor"), &m_Vendor);
}


DownLoadWnd::~DownLoadWnd()
{
	RemoveVirtualWnd(_T("Vendor"));
}

#define	BT_Calendar1			(_T("DataTime1"))
#define	BT_Calendar2			(_T("DataTime2"))
#define BT_OnVideoLoginUI		(_T("Add_device"))
#define BT_TIMEWND1				(_T("daytime1"))
#define BT_TIMEWND2				(_T("daytime2"))
#define BT_SEARCHFILE			(_T("Search"))
#define BT_CLOSE_D				(_T("CloseWnd"))
#define CTR_SELECT_TIME			(_T("Select_time"))

DUI_BEGIN_MESSAGE_MAP(DownLoadWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_OnVideoLoginUI, OnLogin)
DUI_ON_CLICK_CTRNAME(BT_SEARCHFILE, OnSearch)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_D, OnBackward)
DUI_ON_CLICK_CTRNAME(BT_Calendar1, OnSelectCalendar)
DUI_ON_CLICK_CTRNAME(BT_Calendar2, OnSelectCalendar)
DUI_ON_CLICK_CTRNAME(BT_TIMEWND1, OnSelectDayTime)
DUI_ON_CLICK_CTRNAME(BT_TIMEWND2, OnSelectDayTime)
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_VALUECHANGED, CTR_SELECT_TIME, FixedSliderPosition)
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

void DownLoadWnd::OnBackward(TNotifyUI& msg)
{
	Close();
}

void DownLoadWnd::BuildControlDDX()
{
	AddControl<CLabelUI>(startdate);
	AddControl<CLabelUI>(stopdate);
	AddControl<CLabelUI>(starttime);
	AddControl<CLabelUI>(stoptime);

	AddControl<CButtonUI>(ico_startdate);
	AddControl<CButtonUI>(ico_stopdate);

	AddControl<CSliderUI>(timetype);
}

void DownLoadWnd::InitWindow()
{
	BuildControlDDX();
	InitTime();
}

void DownLoadWnd::FixedSliderPosition(TNotifyUI& msg)
{
	CSliderUI& slider = *(GetControl<CSliderUI>(timetype));

	int Top = slider.GetMaxValue();
	int Bottom = slider.GetMinValue();
	int Middle = (Top + Bottom) / 2;
	int MousePos = slider.GetValue();
	assert(MousePos >= 0);

	if (MousePos > Middle && MousePos <= Top)
		slider.SetValue(Top);
	else
		slider.SetValue(Bottom);
}

CDuiString DownLoadWnd::AppenText(const CDuiString& str)
{
	std::string S = str;
	char I = S.back();
	S.pop_back();
	S.append("Text");
	S.push_back(I);
	return CDuiString(S.c_str());
}

void DownLoadWnd::OnSelectCalendar(TNotifyUI& msg)
{
	std::auto_ptr<CalendarUI> pDlg(new CalendarUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	std::string data = pDlg->GetData();
	if (data.empty()) return;

	DUI__Trace(msg.pSender->GetName());
	//implicit relationship between DatatimeText and DataTime
	CDuiString str = msg.pSender->GetName();
	SetLabelText(AppenText(str), data.c_str());

	if (data.length() >= 2)
	{
		std::string day = data.substr(data.length() - 2);
		SetButtonImage(str, day.c_str());
	}
}

void DownLoadWnd::OnSelectDayTime(TNotifyUI& msg)
{
	std::auto_ptr<CTimeUI> pDlg(new CTimeUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();
	//set datetime 's text
	SetLabelText(AppenText(msg.pSender->GetName()), pDlg->GetTime().c_str());

	DUI__Trace(msg.pSender->GetName());
	DUI__Trace(pDlg->GetTime().c_str());
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
	
	/* start to search file on specify device.
	std::auto_ptr<SearchFileUI> pSearchDlg(new SearchFileUI(m_Device));
	assert(pSearchDlg.get());
	pSearchDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 1024, 600);
	pSearchDlg->CenterWindow();
	pSearchDlg->ShowModal();
	*/
}

void DownLoadWnd::Notify(TNotifyUI& msg)
{
	WindowImplBase::Notify(msg);
}

void DownLoadWnd::InitTime()
{
	::GetLocalTime(&m_sysTime);

	CDuiString date, time, day;
	date.Format("%d-%02d-%02d", m_sysTime.wYear, m_sysTime.wMonth, m_sysTime.wDay);
	time.Format("%02d:%02d", m_sysTime.wHour, m_sysTime.wMinute);
	day.Format("%d", m_sysTime.wDay);

	SetButtonImage(ico_startdate, day);
	SetButtonImage(ico_stopdate, day);

	SetLabelText(startdate, date);
	SetLabelText(stopdate, date);
	SetLabelText(stoptime, time);
}


void DownLoadWnd::SetLabelText(const CDuiString& ctr_name, const CDuiString& text)
{
	CLabelUI* c = GetControl<CLabelUI>(ctr_name);
	if (c) c->SetText(text);
}

void DownLoadWnd::SetButtonImage(const CDuiString& ctr_name, const CDuiString& data)
{	
	CDuiString value;
	value.Format(_T("file='skin/Data/%d.png' dest='15,8,39,39'"), std::stoi(data.GetData()));
	CButtonUI* c = GetControl<CButtonUI>(ctr_name);
	if (c) c->SetAttribute(_T("foreimage"), value);
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
		//m_VnameAndType.insert(pair<int, string>(type, VendorDeviceName));
	}
}