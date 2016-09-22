#include "stdafx.h"
#include "SetIpWnd.h"


CSetIpWnd::CSetIpWnd()
{
}


CSetIpWnd::~CSetIpWnd()
{
}


DUI_BEGIN_MESSAGE_MAP(CSetIpWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSEIPWND, OnCloseWnd)
DUI_ON_CLICK_CTRNAME(BT_ADDSET, OnAddIPSet)
DUI_ON_CLICK_CTRNAME(BT_DELSET, OnDelIPSet)
DUI_ON_MSGTYPE(DUI_MSGTYPE_TEXTCHANGED, OnInputNum)
DUI_ON_CLICK_CTRNAME(BT_USE_IP, OnUseSelectIP)
DUI_END_MESSAGE_MAP()

LPCTSTR CSetIpWnd::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString CSetIpWnd::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CSetIpWnd::GetSkinFile()
{
	return _T("xml\\SetIPWnd.xml");
}

void CSetIpWnd::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CSetIpWnd::InitWindow()
{
	_edit_ip1 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address1")));
	_edit_ip2 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address2")));
	_edit_ip3 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address3")));
	_edit_ip4 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address4")));
	_edit_subnet1 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask1")));
	_edit_subnet2 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask2")));
	_edit_subnet3 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask3")));
	_edit_subnet4 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask4")));
	_edit_broadcast1 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway1")));
	_edit_broadcast2 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway2")));
	_edit_broadcast3 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway3")));
	_edit_broadcast4 = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway4")));
	_pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("IP_List")));
	_lab_setIPaddress = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("IP_Address")));
	_lab_setSubNetAddress = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("Sub_net")));
	_lab_setBroadcastAddress = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("Mr_netAddress")));
	InitShowCurIPAddress();
}

void CSetIpWnd::Notify(TNotifyUI& msg)
{
	WindowImplBase::Notify(msg);
}

void CSetIpWnd::OnCloseWnd(TNotifyUI& msg)
{
	Close();
}

void CSetIpWnd::OnAddIPSet(TNotifyUI& msg)
{
	AddIP_Address();
}

void CSetIpWnd::OnDelIPSet(TNotifyUI& msg)
{
	RemoveSubList();
}

void CSetIpWnd::OnUseSelectIP(TNotifyUI& msg)
{
	if (_pList->GetCurSel() == -1)
		return;
	CListTextElementUI* ListText = dynamic_cast<CListTextElementUI*>(m_PaintManager.FindSubControlByClass(_pList, DUI_CTR_LISTTEXTELEMENT, _pList->GetCurSel()));
	std::string ipAddress = ListText->GetText(0);
	std::string subnetAddress = ListText->GetText(2);
	std::string BroadcastAddress = ListText->GetText(4);
	_lab_setIPaddress->SetText(ipAddress.c_str());
	_lab_setSubNetAddress->SetText(subnetAddress.c_str());
	_lab_setBroadcastAddress->SetText(BroadcastAddress.c_str());
	if(BroadcastAddress == "...")
		BroadcastAddress.clear();
	setip.setNetConfig(ipAddress, subnetAddress, BroadcastAddress);
}

void CSetIpWnd::OnInputNum(TNotifyUI& msg)
{
	CDuiString SendName = msg.pSender->GetName();
	CEditUI* input_edit = static_cast<CEditUI*>(m_PaintManager.FindControl(SendName));
	CDuiString strInput = input_edit->GetText();
	int n = strInput.GetLength() - 1;
	if (n < 0 || (strInput[n] <= '9' && strInput[n] >= '0'))
	{
		if (n == 2 || strInput[n] == '.')
		{
			NextInput(SendName);
		}
	}
	else if (strInput[n] == '.')
	{
		input_edit->SetText(strInput.Left(n));
		NextInput(SendName);
	}
	else
	{
		input_edit->SetText("");
	}
}

void CSetIpWnd::NextInput(CDuiString& SendName)
{
	std::string tag = SendName.Right(1);
	int CurSel = stoi(tag);
	if (CurSel < 4)
	{
		SendName.SetAt(SendName.GetLength() - 1, SendName[SendName.GetLength() - 1] + 1);
		CEditUI* input_edit_next = static_cast<CEditUI*>(m_PaintManager.FindControl(SendName));
		if (input_edit_next->GetText() != _T(""))
		{
			input_edit_next->SetText(_T(""));
		}
		input_edit_next->SetFocus();
	}
}

void CSetIpWnd::AddIP_Address()
{
	CDuiString Apoint(".");
	CDuiString strIP_Address;
	CDuiString strIP_Address1 = _edit_ip1->GetText() + Apoint;
	CDuiString strIP_Address2 = _edit_ip2->GetText() + Apoint;
	CDuiString strIP_Address3 = _edit_ip3->GetText() + Apoint;
	CDuiString strIP_Address4 = _edit_ip4->GetText();
	strIP_Address = strIP_Address1 + strIP_Address2 + strIP_Address3 + strIP_Address4;


	CDuiString strSubNet;
	CDuiString strSubNet1 = _edit_subnet1->GetText() + Apoint;
	CDuiString strSubNet2 = _edit_subnet2->GetText() + Apoint;
	CDuiString strSubNet3 = _edit_subnet3->GetText() + Apoint;
	CDuiString strSubNet4 = _edit_subnet4->GetText();
	strSubNet = strSubNet1 + strSubNet2 + strSubNet3 + strSubNet4;

	CDuiString strBDaress;
	CDuiString strBDaress1 = _edit_broadcast1->GetText() + Apoint;
	CDuiString strBDaress2 = _edit_broadcast2->GetText() + Apoint;
	CDuiString strBDaress3 = _edit_broadcast3->GetText() + Apoint;
	CDuiString strBDaress4 = _edit_broadcast4->GetText();
	strBDaress = strBDaress1 + strBDaress2 + strBDaress3 + strBDaress4;

	InsertList(strIP_Address, strSubNet, strBDaress);
}

void CSetIpWnd::InsertList(CDuiString& strIP, CDuiString& strSubNet, CDuiString& strGateWay)
{
	CListTextElementUI* ListText = new CListTextElementUI;
	int Count = _pList->GetCount();
	_pList->Add(ListText);
	ListText->SetFixedHeight(30);
	ListText->SetText(0, strIP);
	ListText->SetText(2, strSubNet);
	ListText->SetText(4, strGateWay);
	ListText->SetBorderSize(1);
	ListText->SetBorderColor(0x12345678);
}

void CSetIpWnd::RemoveSubList()
{
	int CurSel = _pList->GetCurSel();
	_pList->RemoveAt(CurSel, true);
}

void CSetIpWnd::InitShowCurIPAddress()
{
	IPADDRESSINFO ip_info = setip.GetCurIPAddress();
	_lab_setIPaddress->SetText(ip_info.strIP.c_str());
	_lab_setSubNetAddress->SetText(ip_info.strSubNet.c_str());
	_lab_setBroadcastAddress->SetText(ip_info.strBroadcast.c_str());
}
