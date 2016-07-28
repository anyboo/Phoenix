#include "stdafx.h"
#include "Vendor.h"


CVendor::CVendor()
:ppm(nullptr), m_ContListSel(0)
{	
}

CVendor::~CVendor()
{
}

DUI_BEGIN_MESSAGE_MAP(CVendor, CNotifyPump)

DUI_END_MESSAGE_MAP()

void CVendor::SetPaintMagager(CPaintManagerUI* pPaintMgr)
{
	assert(pPaintMgr);
	ppm = pPaintMgr;
}

void CVendor::AddChannelsList(int CurSel, size_t Channel_Count)
{
	CListUI* pList = dynamic_cast<CListUI*>(ppm->FindControl(_T("VendorList")));
	CListContainerElementUI* SubContList = new CListContainerElementUI;

	SubContList = AddChannels(Channel_Count);
	pList->AddAt(SubContList, CurSel + 1);

}

void CVendor::AddVendorList(STDSTRING& VendorName, STDSTRING& VendorIP)
{
	CListUI* pList = dynamic_cast<CListUI*>(ppm->FindControl(_T("VendorList")));
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//DeviceUI.xml"), (UINT)0, NULL, ppm));
	pList->Add(SubList);

	STDSTRING SubListName = STDSTRING(_T("VendorContList")) + to_string(m_ContListSel);
	STDSTRING bt_deleteName = STDSTRING(_T("BT_delete")) + to_string(m_ContListSel);
	CButtonUI* btn = dynamic_cast<CButtonUI*>(ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
	SubList->SetName(SubListName.c_str());
	btn->SetName(bt_deleteName.c_str());
	m_ContListSel = m_ContListSel + 1;

	CLabelUI* Lab_Name = dynamic_cast<CLabelUI*>(ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* Lab_IP = dynamic_cast<CLabelUI*>(ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	Lab_Name->SetText(VendorName.c_str());
	Lab_IP->SetText(VendorIP.c_str());
}


CListContainerElementUI* CVendor::AddChannels(size_t Channel_Count)
{
	CListContainerElementUI* ContList = new CListContainerElementUI;
	CVerticalLayoutUI* vLyt = new CVerticalLayoutUI;

	ContList->SetName(_T("Channel_List"));
	ContList->SetFixedHeight(30 * Channel_Count + 30);
	ContList->SetFixedWidth(185);
	ContList->SetMouseEnabled(false);
	ContList->Add(vLyt);

	for (UINT i = 0; i <= Channel_Count; i++)
	{
		CHorizontalLayoutUI* subHlyt = new CHorizontalLayoutUI;
		COptionUI* subOption = new COptionUI;
		CLabelUI* subLab = new CLabelUI;
		vLyt->Add(subHlyt);
		subHlyt->SetFixedHeight(30);
		subHlyt->Add(subOption);
		subHlyt->Add(subLab);
		if (i == 0)
		{
			subOption->SetAttributeList(_T("name=\"quanxuan\" width=\"22\" height=\"22\" padding=\"20,4,10,4\" normalimage=\"file='skin/quanxuan.png'\" selectedimage=\"file='skin/quanxuanzhuangtai.png'\""));
			subLab->SetAttributeList(_T("text=\"全选\" font=\"5\" textcolor=\"#FFFFFFFF\" valign=\"center\""));
		}
		else{
			subOption->SetAttributeList(_T("width=\"22\" height=\"22\" padding=\"40,4,10,4\" normalimage=\"file='skin/quanxuan.png'\" selectedimage=\"file='skin/quanxuanzhuangtai.png'\""));
			subLab->SetAttributeList(_T("font=\"5\" valign=\"center\" textcolor=\"#FFFFFFFF\""));
			STDSTRING strChannelName = STDSTRING(_T("通道")) + std::to_string(i - 1);
			std::string OptionName = std::string(_T("channel")) + std::to_string(i - 1);
			subOption->SetName(OptionName.c_str());
			subLab->SetText(strChannelName.c_str());
		}		
	}
	return ContList;
}

void CVendor::ShowOfflineVendor()
{
	CListUI* pList = dynamic_cast<CListUI*>(ppm->FindControl(_T("VendorList")));
	int CurSel = pList->GetCurSel();
	CListContainerElementUI* SubList = dynamic_cast<CListContainerElementUI*>(ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, CurSel));
	STDSTRING str = SubList->GetName();
	CControlUI* network = dynamic_cast<CControlUI*>(ppm->FindSubControlByClass(SubList, DUI_CTR_CONTROL, 0));
	network->SetAttribute(_T("bkimage"), _T("file='skin/network_offline.png' dest='10,20,39,48'"));
	SubList->SetBkImage(_T("skin/tdxzanniu.png"));
	SubList->Select(false);
	SubList->SetMouseEnabled(false);

	CListContainerElementUI* nextList = dynamic_cast<CListContainerElementUI*>(ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
	if (nextList != NULL && nextList->GetName() == _T("Channel_List"))
	{
		pList->Remove(nextList, true);
	}
}