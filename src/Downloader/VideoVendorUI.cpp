#include "stdafx.h"
#include "VideoVendorUI.h"


CVideoVendorUI::CVideoVendorUI()
:m_Init(TRUE), m_pageCount(20), m_pages(1)
{
	m_pDb = QMSqlite::getInstance();
	m_pDb->dropTable(DROP_SEARCH_FACTORY_TABLE);
	m_pDb->createTable(CREATE_SEARCH_FACTORY_TABLE);
	InsertToDB();
}

CVideoVendorUI::~CVideoVendorUI()
{
}

DUI_BEGIN_MESSAGE_MAP(CVideoVendorUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_OK, OnSelect)
DUI_ON_CLICK_CTRNAME(BT_PREV_PAGE, GetPrevPage)
DUI_ON_CLICK_CTRNAME(BT_NEXT_PAGE, GetNextPage)
DUI_ON_CLICK_CTRNAME(BT_CLOSE, OnCancel)
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
	if (m_Init)
	{		
		ShowVendorDevice(1);
		m_Init = FALSE;
	}
	if (msg.sType == DUI_MSGTYPE_TEXTCHANGED && msg.pSender->GetName() == _T("Edit_Input"))
	{
		CEditUI* Edit_Name = dynamic_cast<CEditUI*>(m_PaintManager.FindControl(_T("Edit_Input")));
		STDSTRING Input = Edit_Name->GetText();
		InitDevice(Input);
	}
	if (msg.sType == DUI_MSGTYPE_ITEMSELECT && msg.pSender->GetName() == _T("equipment_List"))
	{
		SelectEquipment();
	}

	WindowImplBase::Notify(msg);
}

void CVideoVendorUI::GetPrevPage(TNotifyUI& msg)
{
	if (m_pages > 1 && m_pages != 0)
	{
		m_pages -= 1;
		ShowVendorDevice(m_pages);
	}
}

void CVideoVendorUI::GetNextPage(TNotifyUI& msg)
{
	if (m_pages < m_pageCount)
	{
		m_pages += 1;
		ShowVendorDevice(m_pages);
	}
}

void CVideoVendorUI::OnCancel(TNotifyUI& msg)
{
	m_Select = GetNothing;
	Close();
}

void CVideoVendorUI::OnSelect(TNotifyUI& msg)
{
	m_Select = GetDeviceName;
	Close();
}

void CVideoVendorUI::SelectEquipment()
{
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("equipment_List")));
	int CurSel = pList->GetCurSel();
	STDSTRING SubOptionName = STDSTRING(_T("CheckBox")) + to_string(CurSel);
	COptionUI* SubOPtion = dynamic_cast<COptionUI*>(m_PaintManager.FindControl(SubOptionName.c_str()));
	SubOPtion->Selected(true);
}

void CVideoVendorUI::InitDevice(STDSTRING& Input)
{

	for (int j = 0; j < Input.size(); j++)
	{
		if (Input[j] >= 97 && Input[j] <= 122)
		{
			Input[j] -= 32;
		}
	}
	m_sRecord.clear();
	STDSTRING tmp = Input;
	m_pDb->searchFactoryName(Input, m_sRecord);
	int Count = m_sRecord.size();
	if (Count % 7 == 0){
		m_pageCount = Count / 7;
	}
	else{
		m_pageCount = Count / 7 + 1;
	}
	CLabelUI* Lab_Page = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(_T("pages")));
	STDSTRING Lab_show = STDSTRING(_T("1/") + to_string(m_pageCount));
	Lab_Page->SetText(Lab_show.c_str());
	if (Count == 0)
	{
		Lab_Page->SetText(_T("0/0"));
	}

	ShowVendorDevice(1);
}


void CVideoVendorUI::InsertToDB()
{
	STDSTRING configFile;
	TCHAR PATH[MAX_PATH] = { 0 };
	STDSTRING AppPath = STDSTRING(PATH, ::GetModuleFileNameA(NULL, PATH, MAX_PATH));
	configFile = AppPath.substr(0, AppPath.find_last_of("\\") + 1) + STDSTRING(_T("Device.json"));

	ifstream ifs(configFile);
	locale utf8;
	ifs.imbue(utf8);
	IStreamWrapper isw(ifs);
	Document d;
	d.ParseStream(isw);
	size_t file_size = isw.Tell();
	if (isw.Tell() == 0)
		return;

	std::vector<SearchFactory> sfRecord;
	SearchFactory sf;


	typedef Value::ConstMemberIterator Iter;
	for (Iter it = d.MemberBegin(); it != d.MemberEnd(); it++)
	{
		STDSTRING TypeName = it->name.GetString();
		const Value& a = d[TypeName.c_str()];
		assert(a.IsArray());
		if (!a.IsArray())
			continue;
		STDSTRING spell = a[0].GetString();
		STDSTRING VendorDeviceName = a[1].GetString();

		sf.set<0>(spell);
		sf.set<1>(VendorDeviceName);
		sfRecord.push_back(sf);
		m_sRecord.push_back(VendorDeviceName);
	}

	m_pDb->writeDataByVector(INSERT_SEARCH_FACTORY, sfRecord);
}

void CVideoVendorUI::ShowVendorDevice(int page)
{
	int page_begin = 7 * (page - 1);
	int page_end = 7 * page;
	for (int i = page_begin; i < page_end; i++)
	{
		int temp = i % 7 * 2 + 1;
		STDSTRING DeviceName = STDSTRING(_T("equipment_name")) + to_string(temp);
		CLabelUI* Lab_DeviceName = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(DeviceName.c_str()));
		if (i < m_sRecord.size())
		{
			Lab_DeviceName->SetText(m_sRecord[i].c_str());
		}
		else
		{
			Lab_DeviceName->SetText(_T(""));
		}

	}
}

STDSTRING CVideoVendorUI::GetDevice()
{
	if (m_Select == GetNothing)
		return _T("");
	CListUI* pList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("equipment_List")));
	STDSTRING optionName;
	for (int i = 0; i < 7; i++)
	{
		COptionUI* option = dynamic_cast<COptionUI*>(m_PaintManager.FindSubControlByClass(pList, DUI_CTR_OPTION, i));
		if (option->IsSelected())
		{
			optionName = option->GetName();
			break;
		}
	}
	STDSTRING tag = optionName.substr(optionName.find_last_of(_T("CheckBox")) + 1);
	STDSTRING LableName = STDSTRING(_T("equipment_name")) + tag;
	CLabelUI* Lab_Device = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(LableName.c_str()));
	STDSTRING DeviceName =  Lab_Device->GetText();
	return DeviceName;
}