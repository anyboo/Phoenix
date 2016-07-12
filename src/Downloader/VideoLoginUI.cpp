#include "stdafx.h"
#include "VideoLoginUI.h"
#include "VideoVendorUI.h"

#include "SearchDevice.h"

VideoLoginUI::VideoLoginUI()
:m_Init(FALSE)
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
	//pVendorList.push_back(&dzpVendor);
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

	/************************* 设备登陆 **********************/
	NET_DEVICE_INFO* devInfo = m_DeviceList[0];
	//if (CLoginDevice::getInstance().Login(devInfo->pVendor, devInfo->szIp, devInfo->nPort))
	//{
	//	return;
	//}
}


VideoLoginUI::~VideoLoginUI()
{
}

DUI_BEGIN_MESSAGE_MAP(VideoLoginUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_VideoVendor, OnOpenVideoVendorWnd)
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

void VideoLoginUI::Notify(TNotifyUI& msg)
{
	if (!m_Init)
	{
		OnShowDevice(1);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("Prev_page"))
		{
			GetPrevPage();
		}
		if (msg.pSender->GetName() == _T("Next_page"))
		{
			GetNextPage();
		}
		if (msg.pSender->GetName() == _T("LogIn"))
		{
			m_IsLogIn = LogInDevice;
			Close();
		}
		if (msg.pSender->GetName() == _T("closebtn"))
		{
			m_IsLogIn = NoLogDevice;
			Close();
		}
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
	CEditUI* Edit_Device = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	CEditUI* Edit_IP = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	Edit_Device->SetText(strDevice.c_str());
	Edit_IP->SetText(_T(""));
	Edit_Port->SetText(_T(""));
}

void VideoLoginUI::OnShowDevice(int pages)
{
	STDSTRING IP(m_DeviceList[0]->szIp);
	int DeviceSType = m_DeviceList[0]->nSDKType;
	int size = m_DeviceList.size();
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));

	int start = 5 * (pages - 1);
	int stop = 5 * pages;
	for (int i = start; i < stop; i++)
	{
		STDSTRING DeviceName = STDSTRING(_T("SubList")) + to_string(i + 1);
		CListContainerElementUI* SubList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, i));
		CLabelUI* Lab1 = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
		CLabelUI* Lab_DName = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
		CLabelUI* Lab2 = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
		CLabelUI* Lab_IP = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
		if (i < m_DeviceList.size())
		{
			Lab_DName->SetText(to_string(DeviceSType).c_str());
			Lab_IP->SetText(m_DeviceList[i]->szIp);
		}
		else
		{
			Lab1->SetText(_T(""));
			Lab2->SetText(_T(""));
		}
	}
	ShowPagesLable(pages);
}

void VideoLoginUI::OnShowDeviceInfo(STDSTRING& SendName)
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));
	CListContainerElementUI* SubList = static_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SendName.c_str()));
	CLabelUI* Lab_DName = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* Lab_IP = static_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	STDSTRING strIP = Lab_IP->GetText();
	STDSTRING strName = Lab_DName->GetText();
	int port;
	for (UINT i = 0; i < m_DeviceList.size(); i++)
	{
		STDSTRING IP(m_DeviceList[i]->szIp);
		if (IP == strIP)
		{			
			port = m_DeviceList[i]->nPort;
		}
	}

	CEditUI* Edit_Device = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	CEditUI* Edit_IP = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	Edit_Device->SetText(strName.c_str());
	Edit_IP->SetText(strIP.c_str());
	Edit_Port->SetText(to_string(port).c_str());
}

void VideoLoginUI::GetPrevPage()
{
	CLabelUI* Lab_Page = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
	STDSTRING strText = Lab_Page->GetText();
	STDSTRING strPage = strText.substr(0, strText.find_first_of("/"));
	STDSTRING page_count = strText.substr(strText.find_first_of("/") + 1);
	if (strText == STDSTRING(_T("0/0")) || strPage == STDSTRING(_T("1")))
		return;
	int page = StringToInt(strPage.c_str());
	page = page - 1;
	OnShowDevice(page);
}

void VideoLoginUI::GetNextPage()
{
	CLabelUI* Lab_Page = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
	STDSTRING strText = Lab_Page->GetText();
	STDSTRING strPage = strText.substr(0, strText.find_first_of("/"));
	STDSTRING page_count = strText.substr(strText.find_first_of("/") + 1);
	if (strPage == page_count)
		return;
	int page = StringToInt(strPage.c_str());
	page = page + 1;
	OnShowDevice(page);
}

void VideoLoginUI::ShowPagesLable(int page)
{
	int page_count = 0;
	UINT size = m_DeviceList.size();
	if (size % 5 == 0)
	{
		page_count = size / 5;
	}
	if (size % 5 != 0)
	{
		page_count = size / 5 + 1;
	}

	CLabelUI* Lab_page = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
	STDSTRING strText = to_string(page) + STDSTRING(_T("/")) + to_string(page_count);
	Lab_page->SetText(strText.c_str());

	if (page_count == 0)
	{
		Lab_page->SetText(_T("0/0"));
	}
}

void VideoLoginUI::LogIn()
{
	if (m_IsLogIn == NoLogDevice)
	{
		m_Device = NULL;
		return;
	}
	CEditUI* Edit_IP = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	STDSTRING strIP = Edit_IP->GetText();
	STDSTRING strPort = Edit_Port->GetText();
	int port = StringToInt(strPort.c_str());
	CJXJVendor jxjVendor;	

	BOOL bRet =  CLoginDevice::getInstance().Login(&jxjVendor, strIP, port);
	m_Device = CLoginDevice::getInstance().GetDevice(strIP);
}

Device* VideoLoginUI::GetLonInDevice()
{
	return m_Device;
}
