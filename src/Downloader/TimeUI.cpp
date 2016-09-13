#include "stdafx.h"
#include "TimeUI.h"


CTimeUI::CTimeUI()
:_site(0)
{
}


CTimeUI::~CTimeUI()
{
}


DUI_BEGIN_MESSAGE_MAP(CTimeUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_VERIFY, OnVerify)
DUI_ON_CLICK_CTRNAME(BT_RESET, OnReset)
DUI_END_MESSAGE_MAP()

LPCTSTR CTimeUI::GetWindowClassName() const
{
	return _T("CTimeUI");
}

CDuiString CTimeUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CTimeUI::GetSkinFile()
{
	return _T("xml\\Time.xml");
}

void CTimeUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CTimeUI::InitWindow()
{
	_lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
}

void CTimeUI::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString sender_name = msg.pSender->GetName();
		if (!sender_name.Left(3).Compare(_T("num")))
		{
			InputControl(sender_name);
		}
	}
	WindowImplBase::Notify(msg);
}

void CTimeUI::OnVerify(TNotifyUI& msg)
{
	_setTime = _lab_time->GetText();
	for (int i = 0; i < _setTime.GetLength(); i++)
	{
		if (_setTime[i] == '-')
		{
			_setTime.SetAt(i, '0');
		}
	}
	_site = 0;
	Close();
}

void CTimeUI::OnReset(TNotifyUI& msg)
{
	_site = 0;
	SetBtNumEnabled(0, 2, true);
	SetBtNumEnabled(3, 9, false);
	_lab_time->SetText(_T("--:--"));
}

void CTimeUI::InputControl(CDuiString& Input)
{
	CDuiString num = Input.Right(Input.GetLength() - 3);
	CDuiString strTime = _lab_time->GetText();
	if (_site == 0)
	{
		strTime.Format("%s-:--", num);
		_lab_time->SetText(strTime);
		if (num == _T("2"))
		{
			SetBtNumEnabled(0, 3, true);
			SetBtNumEnabled(4, 9, false);
		}
		else if (num == (_T("0")) || num == (_T("1")))
		{
			SetBtNumEnabled(0, 9, true);
		}
	}
	else if (_site == 1){
		strTime.SetAt(_site, num[0]);
		SetBtNumEnabled(0, 5, true);
		SetBtNumEnabled(6, 9, false);
	}
	else if (_site == 2)
	{
		strTime.SetAt(_site + 1, num[0]);
		SetBtNumEnabled(0, 9, true);
	}
	else if (_site == 3)
	{
		strTime.SetAt(_site + 1, num[0]);
		SetBtNumEnabled(0, 2, true);
		SetBtNumEnabled(3, 9, false);
	}
	_lab_time->SetText(strTime);
	_site < 3 ? _site += 1 : _site = 0;
}

void CTimeUI::SetBtNumEnabled(int begin_num, int end_num, bool IsEnabled)
{
	CDuiString button_name;
	for (int i = begin_num; i <= end_num; i++)
	{
		button_name.Format("num%d", i);
		CButtonUI* btNum = static_cast<CButtonUI*>(m_PaintManager.FindControl(button_name));
		btNum->SetEnabled(IsEnabled);
	}
}

CDuiString CTimeUI::GetTime()
{
	return _setTime;
}

