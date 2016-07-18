#include "stdafx.h"
#include "TimeUI.h"


CTimeUI::CTimeUI()
:m_Site(0)
{
}


CTimeUI::~CTimeUI()
{
}


DUI_BEGIN_MESSAGE_MAP(CTimeUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR CTimeUI::GetWindowClassName() const
{
	return _T("CLogUI");
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

void CTimeUI::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		STDSTRING strSendName = msg.pSender->GetName();
		if (strSendName == _T("bt_ok"))
		{
			CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
			STDSTRING strTime = Lab_time->GetText();
			m_Site = 0;
		}
		if (!strSendName.compare(0, 3, _T("num")))
		{
			InputControl(strSendName);
		}
		if (strSendName == _T("bt_delete"))
		{
			m_Site = 0;
			SetBtNumEnabled(0, 2, true);
			SetBtNumEnabled(3, 9, false);
			CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
			Lab_time->SetText(_T("--:--"));
		}
		if (strSendName == _T("bt_ok"))
		{
			Close();
		}
	}
	WindowImplBase::Notify(msg);
}

void CTimeUI::InputControl(STDSTRING& Input)
{
	STDSTRING num = Input.substr(3);
	CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
	STDSTRING strTime = Lab_time->GetText();
	if (m_Site == 0)
	{
		strTime[0] = num[0];
		strTime[1] = '-';
		strTime[3] = '-';
		strTime[4] = '-';
		Lab_time->SetText(strTime.c_str());
		if (num == STDSTRING(_T("2")))
		{
			SetBtNumEnabled(0, 3, true);
			SetBtNumEnabled(4, 9, false);
		}
		else if (num == STDSTRING(_T("0")) || num == STDSTRING(_T("1")))
		{
			SetBtNumEnabled(0, 9, true);
		}
	}
	if (m_Site == 1){
		strTime[m_Site] = num[0];
		SetBtNumEnabled(0, 5, true);
		SetBtNumEnabled(6, 9, false);
	}
	if (m_Site == 2)
	{
		strTime[m_Site + 1] = num[0];
		SetBtNumEnabled(0, 9, true);
	}
	if (m_Site == 3)
	{
		strTime[m_Site + 1] = num[0];
		SetBtNumEnabled(0, 2, true);
		SetBtNumEnabled(3, 9, false);
	}
	Lab_time->SetText(strTime.c_str());
	if (m_Site < 3)
	{
		m_Site += 1;
	}
	else{
		m_Site = 0;
	}

}

void CTimeUI::SetBtNumEnabled(int begin_num, int end_num, bool IsEnabled)
{
	STDSTRING strBtName;
	for (int i = begin_num; i <= end_num; i++)
	{
		strBtName = STDSTRING(_T("num")) + to_string(i);
		CButtonUI* btNum = static_cast<CButtonUI*>(m_PaintManager.FindControl(strBtName.c_str()));
		btNum->SetEnabled(IsEnabled);
	}
}

STDSTRING CTimeUI::GetTime()
{
	CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
	STDSTRING returnTime = Lab_time->GetText();
	for (UINT i = 0; i < returnTime.size(); i++)
	{
		if (returnTime[i] == '-'){
			returnTime[i] = '0';
		}
	}
	return returnTime;
}