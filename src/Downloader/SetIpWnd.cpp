#include "stdafx.h"
#include "SetIpWnd.h"


CSetIpWnd::CSetIpWnd()
{
}


CSetIpWnd::~CSetIpWnd()
{
}


DUI_BEGIN_MESSAGE_MAP(CSetIpWnd, WindowImplBase)

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
	delete this;
}

void CSetIpWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_TEXTCHANGED)
	{
		STDSTRING SendName = msg.pSender->GetName();
		EditInput(SendName);
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("Add_Setting"))
	{
		AddIP_Address();
	}
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("Delete"))
	{
		RemoveSubList();
	}
	WindowImplBase::Notify(msg);
}

void CSetIpWnd::EditInput(STDSTRING& SendName)
{
	CEditUI* Edit = static_cast<CEditUI*>(m_PaintManager.FindControl(SendName.c_str()));

	STDSTRING strInput = Edit->GetText();
	int n = strInput.size() - 1;
	if (n < 0)
		return;
	if (strInput[n] > '9' || strInput[n] < '0')
	{
		strInput[n] = '\0';
		Edit->SetText(strInput.c_str());
	}
	else
		return;	
}

void CSetIpWnd::AddIP_Address()
{
	CEditUI* Edit_IP1 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address1")));
	CEditUI* Edit_IP2 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address2")));
	CEditUI* Edit_IP3 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address3")));
	CEditUI* Edit_IP4 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("IP_Address4")));
	STDSTRING strIP_Address1 = Edit_IP1->GetText();
	STDSTRING strIP_Address2 = Edit_IP2->GetText();
	STDSTRING strIP_Address3 = Edit_IP3->GetText();
	STDSTRING strIP_Address4 = Edit_IP4->GetText();
	STDSTRING strIP_Address = strIP_Address1 + STDSTRING(_T(".")) + strIP_Address2 + STDSTRING(_T(".")) + strIP_Address3 + STDSTRING(_T(".")) + strIP_Address4;

	CEditUI* Edit_Subnet1 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask1")));
	CEditUI* Edit_Subnet2 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask2")));
	CEditUI* Edit_Subnet3 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask3")));
	CEditUI* Edit_Subnet4 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("Subnet_mask4")));
	STDSTRING strSubNet1 = Edit_Subnet1->GetText();
	STDSTRING strSubNet2 = Edit_Subnet2->GetText();
	STDSTRING strSubNet3 = Edit_Subnet3->GetText();
	STDSTRING strSubNet4 = Edit_Subnet4->GetText();
	STDSTRING strSubNet = strSubNet1 + STDSTRING(_T(".")) + strSubNet2 + STDSTRING(_T(".")) + strSubNet3 + STDSTRING(_T(".")) + strSubNet4;

	CEditUI* Edit_GateWay1 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway1")));
	CEditUI* Edit_GateWay2 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway2")));
	CEditUI* Edit_GateWay3 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway3")));
	CEditUI* Edit_GateWay4 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("gateway4")));
	STDSTRING strGateWay1 = Edit_GateWay1->GetText();
	STDSTRING strGateWay2 = Edit_GateWay2->GetText();
	STDSTRING strGateWay3 = Edit_GateWay3->GetText();
	STDSTRING strGateWay4 = Edit_GateWay4->GetText();
	STDSTRING strGateWay = strGateWay1 + STDSTRING(_T(".")) + strGateWay2 + STDSTRING(_T(".")) + strGateWay3 + STDSTRING(_T(".")) + strGateWay4;
	InsertList(strIP_Address, strSubNet, strGateWay);
}

void CSetIpWnd::InsertList(STDSTRING& strIP, STDSTRING& strSubNet, STDSTRING& strGateWay)
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("IP_List")));
	CListTextElementUI* ListText = new CListTextElementUI;
	int Count = pList->GetCount();
	ListText->SetTag(Count);
	pList->Add(ListText);
	ListText->SetFixedHeight(30);
	ListText->SetText(0, strIP.c_str());
	ListText->SetText(2, strSubNet.c_str());
	ListText->SetText(4, strGateWay.c_str());
	ListText->SetBorderSize(1);
	ListText->SetBorderColor(0x12345678);
}

void CSetIpWnd::RemoveSubList()
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("IP_List")));
	int CurSel = pList->GetCurSel();
	pList->RemoveAt(CurSel, true);
}