#include "stdafx.h"
#include "VideoLoginUI.h"
#include "VideoVendorUI.h"
#include "DVR/DVRSession.h"
#include "DVR/DVRDeviceContainer.h"
#include "TestData.h"
#include "DZP/DVRConnector.h"

VideoLoginUI::VideoLoginUI()
:m_pages(1), _name("")
{
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
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_TEXTCHANGED, Edit_SearchVendor, OnSearchVendorList)
DUI_END_MESSAGE_MAP()

LPCTSTR VideoLoginUI::GetWindowClassName() const
{
	return _T("VideoLoginUI");
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

void VideoLoginUI::InitWindow()
{
	BuildControlDDX();
	CountDevice();
	OnShowDevice(1);
}

void VideoLoginUI::BuildControlDDX()
{
	_brand_edit = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	_ip_edit = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	_port_edit = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	_user = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("UserName")));
	_pswd = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("UserPswd")));
	_vendorCount = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("VendorCount")));
	_login_info_lyt = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("LogIn_Info_Lyt")));
	_HLayout = dynamic_cast<CHorizontalLayoutUI*>(m_PaintManager.FindControl(_T("vLyt")));
	_vendorList = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("VendorList")));
	_device_list = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));
	_pages = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
}

void VideoLoginUI::OnLogIn(TNotifyUI& msg)
{
	CDuiString brand = _brand_edit->GetText();
	CDuiString ip = _ip_edit->GetText();
	CDuiString port = _port_edit->GetText();
	CDuiString user = _user->GetText();
	CDuiString passwd = _pswd->GetText();
	
	//user.Append("admin");

	if (ip.IsEmpty() || port.IsEmpty()) return;
	if (CTestData::getInstance()->IsLogIn(ip.GetData()))return;

	CDuiString connectString;
	connectString.Format("%s:", ip);
	connectString = connectString + port;
	DVR::DVRSession *session = new DVR::DVRSession("DZP", connectString.GetData());
//	DVR::DVRSession session("DZP", connectString.GetData());
	session->login(user.GetData(),passwd.GetData());
	if (session->isLoggedIn())
	{
		m_IsLogIn = LogInDevice;
	}
	else
	{
		m_IsLogIn = NoLogDevice;
		return;
	}

	DVR::DVRDevice* device = new DVR::DVRDevice(*session);
	DVR::DVRDeviceContainer::getInstance().add(device);
	_name = device->name();
	Close();
}

std::string VideoLoginUI::GetLogInName() const
{
	return _name;
}

void VideoLoginUI::OnPrevPage(TNotifyUI& msg)
{
	if (m_pages > 1 && m_page_Count != 0)
	{
		m_pages -= 1;
		OnShowDevice(m_pages);
	}
}

void VideoLoginUI::OnNextPage(TNotifyUI& msg)
{
	if (m_pages < m_page_Count)
	{
		m_pages += 1;
		OnShowDevice(m_pages);
	}
}

void VideoLoginUI::OnClose(TNotifyUI& msg)
{
	m_IsLogIn = NoLogDevice;
	Close();
}

bool VideoLoginUI::GetLoginState()
{
	if (m_IsLogIn == LogInDevice)
		return true;
	else
		return false;
}

void VideoLoginUI::Notify(TNotifyUI& msg)
{
	CDuiString sender_name = msg.pSender->GetName();
	if (msg.sType == DUI_MSGTYPE_CLICK && (!sender_name.Left(6).Compare(_T("Device"))))
	{
		CButtonUI* sub_Button = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(sender_name));
		CDuiString VendorName = sub_Button->GetText();
		_brand_edit->SetText(VendorName);
		CreateSubvLyt();		
	}
	if (msg.sType == DUI_MSGTYPE_ITEMCLICK && (!sender_name.Left(7).Compare(_T("SubList"))))
	{
		OnShowDeviceInfo(sender_name);
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

	CDuiString brandname = pDlg->GetVendorName();
	if (brandname.IsEmpty())return;
	_brand_edit->SetText(brandname);
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
		/*int size = m_DeviceList.size();
		if (i < size)
		{
			int DeviceSType = m_DeviceList[i]->nSDKType;
			std::string DeviceName = m_CnameAndType[DeviceSType];
			CDuiString IP(m_DeviceList[i]->szIp);
			Lab_DName->SetText(DeviceName.c_str());
			Lab_IP->SetText(IP);
			Lab1->SetVisible(true);
			Lab2->SetVisible(true);
		}
		else
		{
			Lab_DName->SetText(_T(""));
			Lab_IP->SetText(_T(""));
			Lab1->SetVisible(false);
			Lab2->SetVisible(false);
		}*/
	}
	ShowPagesLable(pages);
}

void VideoLoginUI::OnShowDeviceInfo(CDuiString& SendName)
{
	//CVerticalLayoutUI* SubvLyt = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("LogIn_Info_Lyt")));
	/*if (_login_info_lyt == nullptr)
		CreateSubvLyt();
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("Device_List")));
	CListContainerElementUI* SubList = dynamic_cast<CListContainerElementUI*>(m_PaintManager.FindSubControlByName(pList, SendName));
	CLabelUI* Lab_DName = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(m_PaintManager.FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	CEditUI* Edit_Device = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("brand_Edit")));
	CEditUI* Edit_IP = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Edit")));
	CEditUI* Edit_Port = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Port_Edit")));
	std::string name;
	
	CDuiString strIP = Lab_IP->GetText();
	CDuiString strName = Lab_DName->GetText();
	if (strName == strIP)
	{
		_brand_edit->SetText("");
		_ip_edit->SetText("");
		_port_edit->SetText("");
		return;
	}
		
	int port;
	for (UINT i = 0; i < m_DeviceList.size(); i++)
	{
		CDuiString IP(m_DeviceList[i]->szIp);
		if (IP == strIP)
		{			
			port = m_DeviceList[i]->nPort;
		}
	}
	_brand_edit->SetText(strName);
	_ip_edit->SetText(strIP);
	_port_edit->SetText(to_string(port).c_str());
	*/
}

void VideoLoginUI::ShowPagesLable(int page)
{
	CDuiString text;
	text.Format(_T("%d / %d"), m_pages, m_page_Count);
	/*
	if (m_page_Count == 0)
		_pages->SetText(_T("0/0"));
	else
		_pages->SetText(text);
	*/
}

void VideoLoginUI::CountDevice()
{
	CDuiString text;
	text.Format(_T("*Find %d device"),1000);
	_vendorCount->SetText(text);
}

void VideoLoginUI::LogIn()
{
	
}

void VideoLoginUI::OnSearchVendorList(TNotifyUI& msg)
{
	CHorizontalLayoutUI* vLyt = dynamic_cast<CHorizontalLayoutUI*>(m_PaintManager.FindControl(_T("vLyt")));
	CVerticalLayoutUI* SubvLyt = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(vLyt, _T("LogIn_Info_Lyt")));
	CVerticalLayoutUI* subList = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(vLyt, _T("VendorList")));

	std::string Input = _brand_edit->GetText();
	for (int j = 0; j < Input.size(); j++)
	{
		if (Input[j] >= 97 && Input[j] <= 122)
		{
			Input[j] -= 32;
		}
	}
	m_sRecord.clear();
	std::vector<string>  text;
	text = m_sRecord;
	int Count = Input == _T("") ? 0 : m_sRecord.size();

	if (_brand_edit->GetText() != _T("") && Count != 0)
	{
		CreateSubvLyt();
		InsertVendorToList();
	}
	else if ((Count == 0 || _brand_edit->GetText() == _T("")))
	{
		CreateSubvLyt();
	}
}

void VideoLoginUI::InsertVendorToList()
{
	int count = m_sRecord.size();
	for (int i = 0; i < 8; i ++)
	{
		/*CButtonUI* button = dynamic_cast<CButtonUI*>(m_PaintManager.FindSubControlByClass(_HLayout, DUI_CTR_BUTTON, i));
		if (i < count)
			button->SetText(m_sRecord[i].c_str());
		else
			button->SetText(_T(""));*/
	}
}

void VideoLoginUI::CreateSubvLyt()
{
	/*
	CDialogBuilder builder;
	CHorizontalLayoutUI* MvLyt = dynamic_cast<CHorizontalLayoutUI*>(m_PaintManager.FindControl(_T("vLyt")));
	CVerticalLayoutUI* subList = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(MvLyt, _T("VendorList")));
	CVerticalLayoutUI* SubvLyt = dynamic_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(MvLyt, _T("LogIn_Info_Lyt")));
	if (subList == nullptr)
	{
		CVerticalLayoutUI* Sub_List = (CVerticalLayoutUI*)(builder.Create(_T("xml//VendorListWnd.xml"), (UINT)0, NULL, &m_PaintManager));
		MvLyt->Remove(_login_info_lyt);
		MvLyt->Add(Sub_List);
	}
	else if (_login_info_lyt == nullptr)
	{
		CVerticalLayoutUI* sub_vlyt = (CVerticalLayoutUI*)(builder.Create(_T("xml//LogIn_Info_Lyt.xml"), (UINT)0, NULL, &m_PaintManager));
		MvLyt->Remove(subList);
		MvLyt->Add(sub_vlyt);
	}
	*/	
}
