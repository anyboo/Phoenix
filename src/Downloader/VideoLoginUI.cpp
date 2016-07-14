#include "stdafx.h"
#include "VideoLoginUI.h"
#include "VideoVendorUI.h"

#include "SearchDevice.h"

VideoLoginUI::VideoLoginUI()
:m_Init(false), m_pages(1)
{
	/************************* 初始化播放窗帘句柄 **********************/
	TestWindows::getInstance().Init();

	/************************* 初始化数据库 **********************/
	//获取指针
	QMSqlite *pDb = QMSqlite::getInstance();
	//删除表
	pDb->dropTable(DROP_SEARCH_VIDEO_TABLE);
	//创建记录表
	pDb->createTable(CREATE_SEARCH_VIDEO_TABLE);

	/************************* 初始化SDK厂商 **********************/
	VENDOR_LIST pVendorList;
	CJXJVendor jxjVendor;
	CDZPVendor dzpVendor;
	DHVendor dhVendor;
	HKVendor hkVendor;

	pVendorList.push_back(&jxjVendor);
//	pVendorList.push_back(&dzpVendor);
	//pVendorList.push_back(&dhVendor);
	//pVendorList.push_back(&hkVendor);

	/************************* 初始化IP列表 **********************/
	DEVICE_INFO_SIMPLE_LIST listDeviceSimpleInfo;
	std::string strIP = "";
	int nPort = 0;

	// DZP
#if 0
	NET_DEVICE_INFO_SIMPLE* devInfoSimple1 = new NET_DEVICE_INFO_SIMPLE;
	memset(devInfoSimple1, 0, sizeof(NET_DEVICE_INFO_SIMPLE));
	strIP = "192.168.0.66";
	nPort = 34567;
	memcpy(devInfoSimple1->szIP, strIP.c_str(), strIP.length());
	devInfoSimple1->nPort = nPort;
	listDeviceSimpleInfo.push_back(devInfoSimple1);
#endif

	// JXJ
#if 1
	NET_DEVICE_INFO_SIMPLE* devInfoSimple2 = new NET_DEVICE_INFO_SIMPLE;
	memset(devInfoSimple2, 0, sizeof(NET_DEVICE_INFO_SIMPLE));
	strIP = "192.168.0.89";
	nPort = 3321;
	memcpy(devInfoSimple2->szIP, strIP.c_str(), strIP.length());
	devInfoSimple2->nPort = nPort;
	listDeviceSimpleInfo.push_back(devInfoSimple2);
#endif

	// HK
#if 0
	NET_DEVICE_INFO_SIMPLE* devInfoSimple3 = new NET_DEVICE_INFO_SIMPLE;
	memset(devInfoSimple3, 0, sizeof(NET_DEVICE_INFO_SIMPLE));
	strIP = "192.168.0.92";
	nPort = 8000;
	memcpy(devInfoSimple3->szIP, strIP.c_str(), strIP.length());
	devInfoSimple3->nPort = nPort;
	listDeviceSimpleInfo.push_back(devInfoSimple3);
#endif

	// DH
#if 0
	NET_DEVICE_INFO_SIMPLE* devInfoSimple4 = new NET_DEVICE_INFO_SIMPLE;
	memset(devInfoSimple4, 0, sizeof(NET_DEVICE_INFO_SIMPLE));
	strIP = "192.168.0.96";
	nPort = 37777;
	memcpy(devInfoSimple4->szIP, strIP.c_str(), strIP.length());
	devInfoSimple4->nPort = nPort;
	listDeviceSimpleInfo.push_back(devInfoSimple4);
#endif

	/************************* 设备发现 **********************/
	CSearchDevice::getInstance().Search(pVendorList, listDeviceSimpleInfo);
	m_DeviceList = CSearchDevice::getInstance().GetDeviceInfoList();
	m_page_Count = m_DeviceList.size() / 5;
	if (m_DeviceList.size() % 5 != 0)
	{
		m_page_Count += 1;
	}

}


VideoLoginUI::~VideoLoginUI()
{
}

DUI_BEGIN_MESSAGE_MAP(VideoLoginUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_VideoVendor, OnOpenVideoVendorWnd)
DUI_ON_CLICK_CTRNAME(BT_LOGIN, OnLogIn)
DUI_ON_CLICK_CTRNAME(BT_PREVPAGE, OnPrevPage)
DUI_ON_CLICK_CTRNAME(BT_NEXTPAGE, OnNextPage)
DUI_ON_CLICK_CTRNAME(BT_CLOSELOGWND, OnClose)
DUI_END_MESSAGE_MAP()

LPCTSTR VideoLoginUI::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString VideoLoginUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString VideoLoginUI::GetSkinFile()
{
	return _T("xml\\VideoLoginUI.xml");
}

void VideoLoginUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void VideoLoginUI::OnLogIn(TNotifyUI& msg)
{
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	STDSTRING strIP = Edit_IP->GetText();
	STDSTRING strPort = Edit_Port->GetText();
	if (strIP == strPort)
		return;
	m_IsLogIn = LogInDevice;
	Close();
}

void VideoLoginUI::OnPrevPage(TNotifyUI& msg)
{
	GetPrevPage();
}

void VideoLoginUI::OnNextPage(TNotifyUI& msg)
{
	GetNextPage();
}

void VideoLoginUI::OnClose(TNotifyUI& msg)
{
	m_IsLogIn = NoLogDevice;
	Close();
}

void VideoLoginUI::Notify(TNotifyUI& msg)
{
	if (!m_Init)
	{
		CountDevice();
		OnShowDevice(1);
		m_Init = true;
	}
	if (msg.sType == DUI_MSGTYPE_TEXTCHANGED && msg.pSender->GetName() == _T("brand_Edit"))
	{
		CEditUI* Edit_name = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
		CHorizontalLayoutUI* vLyt = dynamic_cast<CHorizontalLayoutUI*>(m_PaintManager.FindControl(_T("vLyt")));
		CVerticalLayoutUI* SubvLyt = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(vLyt, _T("LogIn_Info_Lyt")));
		CVerticalLayoutUI* subList = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(vLyt, _T("VendorList")));
		if (Edit_name->GetText() != _T("") && SubvLyt != nullptr)
		{
			vLyt->Remove(SubvLyt);
			CDialogBuilder builder;
			CVerticalLayoutUI* Sub_List = (CVerticalLayoutUI*)(builder.Create(_T("xml//VendorListWnd.xml"), (UINT)0, NULL, &m_PaintManager));
			vLyt->Add(Sub_List);
		}
		else if (subList != nullptr && Edit_name->GetText() == _T(""))
		{
			vLyt->Remove(subList);
			CDialogBuilder builder;
			CVerticalLayoutUI* sub_vlyt = (CVerticalLayoutUI*)(builder.Create(_T("xml//LogIn_Info_Lyt.xml"), (UINT)0, NULL, &m_PaintManager));
			vLyt->Add(sub_vlyt);
		}
	}
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		POINT pt = { msg.ptMouse.x, msg.ptMouse.y };
	}
	if (msg.sType == DUI_MSGTYPE_ITEMCLICK)
	{
		STDSTRING SendName = msg.pSender->GetName();
		if (!SendName.compare(0, 7, _T("SubList")))
		{
			OnShowDeviceInfo(SendName);
		}
	}
	WindowImplBase::Notify(msg);
}

void VideoLoginUI::OnOpenVideoVendorWnd(TNotifyUI& msg)
{
	std::auto_ptr<CVideoVendorUI> pDlg(new CVideoVendorUI);
	assert(pDlg.get());
	pDlg->Create(this->GetHWND(), NULL, UI_WNDSTYLE_EX_DIALOG, 0L, 0, 0, 0, 0);
	pDlg->CenterWindow();
	pDlg->ShowModal();

	STDSTRING strDevice = pDlg->GetDevice();
	if (strDevice == _T(""))
		return;
	CEditUI* Edit_Device = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	Edit_Device->SetText(strDevice.c_str());
	Edit_IP->SetText(_T(""));
	Edit_Port->SetText(_T(""));
}

void VideoLoginUI::OnShowDevice(int pages)
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));
	
	int start = 5 * (pages - 1);
	int stop = 5 * pages;
	for (int i = start; i < stop; i++)
	{
		CListContainerElementUI* SubList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, i%5));
		CLabelUI* Lab1 = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
		CLabelUI* Lab_DName = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
		CLabelUI* Lab2 = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
		CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
		int size = m_DeviceList.size();
		if (i < size)
		{
			int DeviceSType = m_DeviceList[i]->nSDKType;
			STDSTRING IP(m_DeviceList[i]->szIp);
			Lab_DName->SetText(to_string(DeviceSType).c_str());
			Lab_IP->SetText(IP.c_str());
			Lab1->SetVisible(true);
			Lab2->SetVisible(true);
		}
		else
		{
			Lab_DName->SetText(_T(""));
			Lab_IP->SetText(_T(""));
			Lab1->SetVisible(false);
			Lab2->SetVisible(false);
		}
	}
	ShowPagesLable(pages);
}

void VideoLoginUI::OnShowDeviceInfo(STDSTRING& SendName)
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));
	CListContainerElementUI* SubList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SendName.c_str()));
	CLabelUI* Lab_DName = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	CEditUI* Edit_Device = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	STDSTRING strIP = Lab_IP->GetText();
	STDSTRING strName = Lab_DName->GetText();
	if (strName == strIP)
	{
		Edit_Device->SetText(nullptr);
		Edit_IP->SetText(nullptr);
		Edit_Port->SetText(nullptr);
		return;
	}
		
	int port;
	for (UINT i = 0; i < m_DeviceList.size(); i++)
	{
		STDSTRING IP(m_DeviceList[i]->szIp);
		if (IP == strIP)
		{			
			port = m_DeviceList[i]->nPort;
		}
	}
	Edit_Device->SetText(strName.c_str());
	Edit_IP->SetText(strIP.c_str());
	Edit_Port->SetText(to_string(port).c_str());
}

void VideoLoginUI::GetPrevPage()
{
	if (m_pages > 1 && m_page_Count != 0)
	{
		m_pages -= 1;
		OnShowDevice(m_pages);
	}
}

void VideoLoginUI::GetNextPage()
{
	if (m_pages < m_page_Count)
	{
		m_pages += 1;
		OnShowDevice(m_pages);
	}	
}

void VideoLoginUI::ShowPagesLable(int page)
{
	CLabelUI* Lab_page = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
	STDSTRING strText = to_string(m_pages) + STDSTRING(_T("/")) + to_string(m_page_Count);
	if (m_page_Count == 0)
		Lab_page->SetText(_T("0/0"));
	else
		Lab_page->SetText(strText.c_str());
}

void VideoLoginUI::CountDevice()
{
	CLabelUI* Lable_Count = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("VendorCount")));
	char str[200] = { 0 };
	sprintf_s(str, "*搜索到%d台设备", m_DeviceList.size());
	STDSTRING ShowText(str);
	Lable_Count->SetText(ShowText.c_str());
}

void VideoLoginUI::LogIn()
{
	if (m_IsLogIn == NoLogDevice)
		return;
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	STDSTRING strIP = Edit_IP->GetText();
	STDSTRING strPort = Edit_Port->GetText();
	int port = stoi(strPort.c_str());

//	CDZPVendor* pDzp = new CDZPVendor();
	CJXJVendor* pJxj = new CJXJVendor();

	CLoginDevice::getInstance().Login(pJxj, strIP, port);
}

Device* VideoLoginUI::GetLonInDevice()
{
	if (m_IsLogIn == NoLogDevice)
		return nullptr;
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	STDSTRING strIP = Edit_IP->GetText();
	m_Device = CLoginDevice::getInstance().GetDevice(strIP);
	return m_Device;
}
