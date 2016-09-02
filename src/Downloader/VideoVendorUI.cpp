#include "stdafx.h"
#include "VideoVendorUI.h"


CVideoVendorUI::CVideoVendorUI()
:_vendor_name(_T(""))
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
	return _T("CVideoVendorUI");
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
		CDuiString sender_name = msg.pSender->GetName();
		if (!sender_name.Left(11).Compare(_T("VendorName_")))
		{
			CButtonUI* button = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(sender_name));
			_vendor_name = button->GetText();
			_is_select = GetDeviceName;
			Close();
		}
	}
	WindowImplBase::Notify(msg);
}

void CVideoVendorUI::OnCloseWnd(TNotifyUI& msg)
{
	_is_select = GetNothing;
	Close();
}

CDuiString CVideoVendorUI::GetVendorName()
{
	if (_is_select == GetNothing)
		return _T("");
	return _vendor_name;
}

