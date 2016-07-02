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
	delete this;
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
			STDSTRING num = strSendName.substr(3);
			CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
			STDSTRING strTime = Lab_time->GetText();
			if (m_Site < 2){
				strTime[m_Site] = num[0];
			}
			else{
				strTime[m_Site + 1] = num[0];
			}
			Lab_time->SetText(strTime.c_str());
			if (m_Site < 4)
			{
				m_Site += 1;
			}
			else{
				m_Site = 0;
			}
			
		}
		if (strSendName == _T("bt_delete"))
		{
			m_Site = 0;
			CLabelUI* Lab_time = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("time_text")));
			Lab_time->SetText(_T("00:00"));
		}
	}
	WindowImplBase::Notify(msg);
}