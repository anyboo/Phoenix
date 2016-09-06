#include "stdafx.h"
#include "DownLoadList.h"
#include "TestData.h"


CDownLoadList::CDownLoadList()
:_ppm(nullptr), _taskCount(1)
{
}


CDownLoadList::~CDownLoadList()
{
}

void CDownLoadList::SetPaintMagager(CPaintManagerUI* pPaintMgr)
{
	assert(pPaintMgr);
	_ppm = pPaintMgr;
}

void CDownLoadList::AddDownloadTask(const unsigned long packet_id)
{
	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, _ppm));
	pList->Add(SubList);
	
	SubList->SetTag(packet_id);
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));

	CDuiString taskListName, buttonName;
	taskListName.Format("taskList%d", _taskCount);
	buttonName.Format("btn_Cancel%d", _taskCount);

	SubList->SetUserData(_T("0"));
	SubList->SetName(taskListName);
	BT_CanCel->SetName(buttonName);

	AddDataToSubList(SubList, packet_id, 0);
	_taskCount = _taskCount + 1;
}

void CDownLoadList::AddDataToSubList(CListContainerElementUI* TaskList, const unsigned long download_ID, const int id)
{
	if (TaskList == nullptr)return;
	CLabelUI* lab_filename = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_filesize = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lasttime = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_status = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 4));
	CProgressUI* progress = dynamic_cast<CProgressUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_PROGRESS, 0));

	std::vector<DownLoad_Info> downloadfiles;
	CTestData::getInstance()->GetDownloadInfo(download_ID, downloadfiles);
	TaskList->SetTag(download_ID);

	lab_filename->SetText(downloadfiles[id].filename.c_str());
	lab_filesize->SetText(std::to_string(downloadfiles[id].filesize).c_str());
	lab_speed->SetText(std::to_string(downloadfiles[id].speed).c_str());
	lab_lasttime->SetText(std::to_string(downloadfiles[id].lastTime).c_str());
	lab_status->SetText(std::to_string(downloadfiles[id].state).c_str());
	progress->SetValue(downloadfiles[id].progress);
}


void CDownLoadList::Show_Off_SubList(CDuiString& strSendName)
{
	CListUI* m_List = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));

	std::string strUserData;
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByName(m_List, strSendName));
	if (ContList->GetUserData() == _T("Sub"))return;
	unsigned long downland_id = ContList->GetTag();
	int filesize = CTestData::getInstance()->GetDownloadSize(downland_id);
	int CurSel = GetSubListCurSel(ContList, m_List);
	CListContainerElementUI* SubContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(m_List, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
	if (SubContList == NULL)
	{
		if (ContList->GetUserData() == _T("0"))
		{
			CListContainerElementUI* SubList = new CListContainerElementUI;
			for (int i = CurSel + 1; i <= CurSel + filesize; i++)
			{
				SubList = Add_FileInfoList();
				SubList->SetUserData(_T("Sub"));
				m_List->AddAt(SubList, i);
				AddSubListAttr(SubList);
				AddDataToSubList(SubList, downland_id, i - CurSel - 1);
		/*		CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);*/
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
	}
	else{
		if (ContList->GetUserData() == _T("0") && SubContList->GetUserData() != _T("Sub"))
		{
			CListContainerElementUI* SubList = new CListContainerElementUI;
			for (int i = CurSel + 1; i <= CurSel + filesize; i++)
			{
				SubList = Add_FileInfoList();
				SubList->SetUserData(_T("Sub"));
				m_List->AddAt(SubList, i);
				AddSubListAttr(SubList);
				AddDataToSubList(SubList, downland_id, i - CurSel - 1);
			/*	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);*/
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
		if (ContList->GetUserData() != _T("0") && SubContList->GetUserData() == _T("Sub"))
		{
			strUserData = ContList->GetUserData();
			int Count = stoi(strUserData);

			for (int j = CurSel + 1; j <= CurSel + Count; j++)
			{
				m_List->RemoveAt(CurSel + 1, false);
			}
			ContList->SetUserData(_T("0"));
		}
	}
}


int CDownLoadList::GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList)
{
	CListContainerElementUI* SubListTmp = new CListContainerElementUI;
	int CurSel = -1;
	for (int i = 0; i < pList->GetCount(); i++)
	{
		SubListTmp = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, i));
		if (SubListTmp->GetName() == SubList->GetName())
		{
			CurSel = i;
			break;
		}
	}
	return CurSel;
}

CListContainerElementUI* CDownLoadList::Add_FileInfoList()
{
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, _ppm));
	SubList->SetAttribute(_T("inset"), _T("30,0,0,0"));

	return SubList;
}

void CDownLoadList::RemoveSubList(CDuiString& strSendName)
{
	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	CButtonUI* bt_cancel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByName(pList, strSendName));
	std::string tag = strSendName.Right(strSendName.GetLength() - 10).GetData();
	std::string SubListName = std::string(_T("taskList")) + tag;
	//CListContainerElementUI* ContList1 = (CListContainerElementUI*)(bt_cancel->GetParent());
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByName(pList, SubListName.c_str()));
	int ContListserial = GetSubListCurSel(ContList, pList);
	std::string SubListCount = ContList->GetUserData();
	if (ContList->GetUserData() == _T("Sub"))
	{
		pList->Remove(ContList, true);
		CLabelUI* lab_name = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(ContList, DUI_CTR_LABEL, 0));
		std::string filename = lab_name->GetText();
		unsigned long packet_id = ContList->GetTag();
		CTestData::getInstance()->DeleteTaskByFileName(filename, packet_id);
	}
	else
	{
		int Count = stoi(SubListCount);

		for (int i = 0; i <= Count; i++)
		{
			pList->RemoveAt(ContListserial, true);
		}
	}
}

void CDownLoadList::RenewList()
{
	int index = 0;
	int tmp = 0;
	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	int count = pList->GetCount();
	while (count > 0)
	{
		CListContainerElementUI* taskList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index));
		int sublistCount = atoi(taskList->GetUserData());
		unsigned long packet_id = taskList->GetTag();
		std::vector<DownLoad_Info> files;
		CTestData::getInstance()->GetDownloadInfo(packet_id, files);
		int filesize = files.size();
		AddDataToSubList(taskList, packet_id, 0);
		for (int i = 0; i < filesize; i++)
		{
			CListContainerElementUI* sublist = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index + i + 1));
			if (sublist == nullptr)break;
			AddDataToSubList(sublist, packet_id, i);
			tmp++;
		}
		index = tmp + 1;
		count = count - index;
	}
	
}

void CDownLoadList::AddSubListAttr(CListContainerElementUI* SubList)
{
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
	BT_CanCel->SetAttribute(_T("padding"), _T("5,5,35,5"));
	CDuiString taskListName, buttonName;
	taskListName.Format("taskList%d", _taskCount);
	buttonName.Format("btn_Cancel%d", _taskCount);

	SubList->SetName(taskListName);
	BT_CanCel->SetName(buttonName);
	_taskCount = _taskCount + 1;
}