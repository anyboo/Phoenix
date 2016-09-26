#include "stdafx.h"
#include "DownLoadList.h"
#include "DVR/DVRSearchFilesContainer.h"
#include "DVR/DVRStatement.h"
#include "DVR/DVRDeviceContainer.h"
#include "DVR/DVRDevice.h"

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

void CDownLoadList::AddDownloadTask(const std::vector<size_t>& IDs, const std::vector<long>& handle, const std::string name)
{
	_download_handle = handle;
	_download_filesID = IDs;
	_device_name = name;
	for (size_t i = 0; i < IDs.size(); i++)
	{
		_prev_pro.push_back(0);
	}

	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	CDialogBuilder builder;
	CListContainerElementUI* SubList = (CListContainerElementUI*)(builder.Create(_T("xml//FileSubList.xml"), (UINT)0, NULL, _ppm));
	pList->Add(SubList);
	CLabelUI* lab_filename = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_filesize = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lasttime = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_status = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_LABEL, 4));
	CProgressUI* progress = dynamic_cast<CProgressUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_PROGRESS, 0));
	
	lab_filename->SetText("DZPFiles");
	lab_filesize->SetText("454451");
	lab_speed->SetText("0");
	lab_lasttime->SetText("-");
	lab_status->SetText("no");
//	SubList->SetTag(packet_id);
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));

	CDuiString taskListName, buttonName;
	taskListName.Format("taskList%d", _taskCount);
	buttonName.Format("btn_Cancel%d", _taskCount);

	SubList->SetUserData(_T("0"));
	SubList->SetName(taskListName);
	BT_CanCel->SetName(buttonName);

//	AddDataToSubList(SubList, packet_id, 0);
	_taskCount = _taskCount + 1;
}

void CDownLoadList::AddDataToSubList(CListContainerElementUI* TaskList, const size_t fileID)
{
	if (TaskList == nullptr)return;
	CLabelUI* lab_filename = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_filesize = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lasttime = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_status = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 4));
	CProgressUI* progress = dynamic_cast<CProgressUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_PROGRESS, 0));

	DVR::DVRDevice& Device = DVR::DVRDeviceContainer::getInstance().get(_device_name);
	DVR::DVRStatement statement(Device.session());

	DVR::RecordFile rf = DVR::DVRSearchFilesContainer::getInstance().GetFileById(fileID);
	int proValue = statement.GetDownloadPro(_download_handle[fileID]);
	int speed = (proValue - _prev_pro[fileID]) * rf.size / 100;
	int lasttime = 0;
	if (proValue != 0 && _prev_pro[fileID] != 100)
		lasttime = (100 - proValue) / (proValue - _prev_pro[fileID]);
	_prev_pro[fileID] = proValue;

	lab_filename->SetText(rf.name.c_str());
	lab_filesize->SetText(std::to_string(rf.size).c_str());
	lab_speed->SetText(std::to_string(speed).c_str());
	lab_lasttime->SetText(std::to_string(lasttime).c_str());
	lab_status->SetText("no");
	if (proValue == 100)
		lab_status->SetText("finish");
	progress->SetValue(proValue);
}


void CDownLoadList::Show_Off_SubList(CDuiString& strSendName)
{
	CListUI* m_List = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));

	std::string strUserData;
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByName(m_List, strSendName));
	if (ContList->GetUserData() == _T("Sub"))return;
	int filesize = _download_filesID.size();
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
				AddDataToSubList(SubList, i - CurSel - 1);
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
				AddDataToSubList(SubList, i - CurSel - 1);
			/*	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
				BT_CanCel->SetVisible(false);*/
			}
			strUserData = to_string(filesize);
			ContList->SetUserData(strUserData.c_str());
		}
		if (ContList->GetUserData() != _T("0") && SubContList->GetUserData() == _T("Sub"))
		{
			for (int j = CurSel + 1; j <= CurSel + filesize; j++)
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
//		CTestData::getInstance()->DeleteTaskByFileName(filename, packet_id);
	}
	else
	{
		int Count = stoi(SubListCount);

		for (int i = 0; i <= Count; i++)
		{
			pList->RemoveAt(ContListserial, true);
		}
		unsigned long packet_id = ContList->GetTag();
//		CTestData::getInstance()->DeleteWholeTaskByID(packet_id);
	}
}

void CDownLoadList::RenewList()
{
	int index = 0;
	int tmp = 0;
	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	int count = pList->GetCount();
	while (count != index)
	{
		CListContainerElementUI* taskList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index));
		int sublistCount = atoi(taskList->GetUserData());
	
		int filesize = _download_filesID.size();
		int Max = sublistCount == 0 ? sublistCount : filesize;
//		AddDataToSubList(taskList, 1);
		for (int i = 0; i < Max; i++)
		{
			CListContainerElementUI* sublist = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index + i + 1));
			if (sublist == nullptr)break;
			AddDataToSubList(sublist, i);
			tmp++;
		}
		index = index + tmp + 1;
		tmp = 0;
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