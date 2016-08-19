#include "stdafx.h"
#include "VideoVendorUI.h"


CVideoVendorUI::CVideoVendorUI()
:m_VendorName(_T(""))
{
}

CVideoVendorUI::~CVideoVendorUI()
{
}

DUI_BEGIN_MESSAGE_MAP(CVideoVendorUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CloseVwnd, OnCloseWnd)
DUI_END_MESSAGE_MAP()

LPCTSTR CVideoVendorUI::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString CVideoVendorUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CVideoVendorUI::GetSkinFile()
{
	return _T("xml//VideoVendor.xml");
}

void CVideoVendorUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CVideoVendorUI::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString SendName = msg.pSender->GetName();
		DUI__Trace(SendName);
		/*if (!SendName.compare(0, 11, _T("VendorName_")))
		{
			CButtonUI* button = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(SendName.c_str()));
			m_VendorName = button->GetText();
			m_IsGetVendorName = GetDeviceName;
			Close();
		}*/
	}
	WindowImplBase::Notify(msg);
}

void CVideoVendorUI::OnCloseWnd(TNotifyUI& msg)
{
	m_IsGetVendorName = GetNothing;
	Close();
}

CDuiString CVideoVendorUI::GetVendorName()
{
	if (m_IsGetVendorName == GetNothing)
		return _T("");
	return m_VendorName;
}

