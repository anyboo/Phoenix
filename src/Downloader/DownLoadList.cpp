#include "stdafx.h"
#include "DownLoadList.h"
#include "DVR/DVRSearchFilesContainer.h"
#include "DVR/DVRStatement.h"
#include "DVR/DVRDeviceContainer.h"
#include "DVR/DVRDevice.h"
#include "DVR/DVRDownloadPacket.h"
#include "DVR/DVRDownloadPakcetContainer.h"
#include "log.h"

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

void CDownLoadList::AddDownloadTask(long searchhandle)
{
	std::cout << "AddDownloadTask" << std::endl;
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

	
	DVR::Download_Info	file_info;
	DVR::DVRDownloadPacket *pDownload = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(searchhandle);
	poco_assert(pDownload);
	if (!pDownload)
		return;
	pDownload->GetMainTask(file_info);	
	lab_filename->SetText(file_info.fname.c_str());
	lab_filesize->SetText(std::to_string(file_info.fsize).c_str());
	lab_speed->SetText(std::to_string(file_info.speed).c_str());
	lab_lasttime->SetText(std::to_string(file_info.lasttime).c_str());
	lab_status->SetText("开始下载");
//	SubList->SetTag(packet_id);
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));

	CDuiString taskListName, buttonName;
	taskListName.Format("taskList%d", _taskCount);
	buttonName.Format("btn_Cancel%d", _taskCount);
	_download_items.push_back(searchhandle);

	SubList->SetUserData(_T("0"));
	SubList->SetName(taskListName);
	BT_CanCel->SetName(buttonName);

//	AddDataToSubList(SubList, packet_id, 0);
	_taskCount = _taskCount + 1;
}

void CDownLoadList::AddDataToSubList(CListContainerElementUI* TaskList, const long search, const size_t fileID)
{
	std::cout << "AddDataToSubList search: " << search << " id: " << fileID << std::endl;
	if (TaskList == nullptr)return;
	CLabelUI* lab_filename = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_filesize = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lasttime = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_status = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 4));
	CProgressUI* progress = dynamic_cast<CProgressUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_PROGRESS, 0));

	std::vector<size_t> downloadOrder;
	std::cout << "AddDataToSubList 0" << std::endl;
	DVR::DVRDownloadPacket* pDownload = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(search);
	poco_assert(pDownload);
	pDownload->GetDownloadIDs(downloadOrder);	
	DVR::Download_Info*	file = pDownload->GetTaskPacket(downloadOrder[fileID]);
	poco_assert(file);
	std::cout << "file name:" << file->fname << std::endl;
	lab_filename->SetText(file->fname.c_str());
	lab_filesize->SetText(std::to_string(file->fsize).c_str());	
	if (file->lasttime == 99999999)
	{
		char lasttime[50] = { 0 };
		sprintf_s(lasttime, "%d秒", file->lasttime);
	}
	else
	{
		char lasttime[50] = { 0 };
		sprintf_s(lasttime, "%d分%d秒", file->lasttime / 60, file->lasttime % 60);
		lab_lasttime->SetText(lasttime);
	}
	
	lab_speed->SetText(std::to_string(file->speed).c_str());
	progress->SetValue(file->proValue);
	switch (file->status)
	{
	case DVR::DL_STATUS_DOWNLOADING:
		lab_status->SetText("下载中");
		break;
	case DVR::DL_STATUS_FINISH:
		lab_status->SetText("完成");
		break;
	case DVR::DL_STATUS_WAITING:
		lab_status->SetText("等待");
		break;
	default:
		break;
	}	
	std::cout << "AddDataToSubList end" << std::endl;
}


void CDownLoadList::Show_Off_SubList(CDuiString& strSendName)
{
	poco_information_f1(logger_handle, "show off sublist: %s", std::string(strSendName.GetData()));
	CListUI* m_List = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));

	std::string strUserData;
	CListContainerElementUI* ContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByName(m_List, strSendName));
	if (ContList->GetUserData() == _T("Sub"))return;
	std::string strindex(strSendName.GetData());
	int index = std::stoi(strindex.substr(strindex.find("taskList") + strlen("taskList"))) - 1;
	int CurSel = GetSubListCurSel(ContList, m_List);
	std::cout << "select: " << CurSel << std::endl;
	CListContainerElementUI* SubContList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(m_List, DUI_CTR_LISTCONTAINERELEMENT, CurSel + 1));
	DVR::DVRDownloadPacket* pDownload = NULL;
	pDownload = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(_download_items[index]);
	poco_assert(pDownload);
	int filesize = pDownload->GetDownloadSize();
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
				AddDataToSubList(SubList, _download_items[index], i - CurSel - 1);
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
				AddDataToSubList(SubList, _download_items[index], i - CurSel - 1);
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
///		pList->Remove(ContList, true);
//		CLabelUI* lab_name = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(ContList, DUI_CTR_LABEL, 0));
//		std::string filename = lab_name->GetText();
//		unsigned long packet_id = ContList->GetTag();
//		CTestData::getInstance()->DeleteTaskByFileName(filename, packet_id);
	}
	else
	{
		StopDownload(_download_items[stoi(tag)]);
		int Count = stoi(SubListCount);

		for (int i = 0; i <= Count; i++)
		{
			pList->RemoveAt(ContListserial, true);
		}
		//DVR::DVRDownloadPacket::getInstance().DeleteWholeTask();
	}
}

void CDownLoadList::RenewList()
{
	std::cout << "RenewList" << std::endl;
	int index = 0;
	int tmp = 0;
	int downloadindex = 0;
	CListUI* pList = dynamic_cast<CListUI*>(_ppm->FindControl(_T("DownloadList")));
	int count = pList->GetCount();
	while (count != index)
	{
		CListContainerElementUI* taskList = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index));
		int sublistCount = atoi(taskList->GetUserData());
		
		std::cout << "sublistCount: " << sublistCount << " name：" << taskList->GetName().GetData() << std::endl;
		
		DVR::DVRDownloadPacket* pDownload = NULL;
		pDownload = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(_download_items[downloadindex]);
		poco_assert(pDownload);

		int filesize = pDownload->GetDownloadSize();
		int Max = sublistCount == 0 ? sublistCount : filesize;
		RenewPacketList(downloadindex, taskList);
		std::cout << "Max: " << Max << std::endl;
		for (int i = 0; i < Max; i++)
		{
			std::cout << "renewlist item 0:" << i << std::endl;
			CListContainerElementUI* sublist = dynamic_cast<CListContainerElementUI*>(_ppm->FindSubControlByClass(pList, DUI_CTR_LISTCONTAINERELEMENT, index + i + 1));
			if (sublist == nullptr)break;
			std::cout << "renewlist item:" << _download_items[downloadindex] << " i:" << i << std::endl;
			AddDataToSubList(sublist, _download_items[downloadindex], i);
			std::cout << "renewlist add data end" << std::endl;		
			tmp++;
		}
		index = index + tmp + 1;
		tmp = 0;
		downloadindex++;
				
	}
	
}

void CDownLoadList::AddSubListAttr(CListContainerElementUI* SubList)
{
	CButtonUI* BT_CanCel = dynamic_cast<CButtonUI*>(_ppm->FindSubControlByClass(SubList, DUI_CTR_BUTTON));
	BT_CanCel->SetAttribute(_T("padding"), _T("5,5,35,5"));
	CDuiString taskListName, buttonName;
	taskListName.Format("taskItem%d", _taskCount);
	buttonName.Format("btn_Cancel%d", _taskCount);

	SubList->SetName(taskListName);
	BT_CanCel->SetName(buttonName);
	BT_CanCel->SetVisible(false);
	//_taskCount = _taskCount + 1;
}

void CDownLoadList::RenewPacketList(int i, CListContainerElementUI* TaskList)
{
	std::cout << "RenewPacketList" << std::endl;
	if (TaskList == nullptr)return;
	CLabelUI* lab_filename = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 0));
	CLabelUI* lab_filesize = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 1));
	CLabelUI* lab_speed = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 2));
	CLabelUI* lab_lasttime = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 3));
	CLabelUI* lab_status = dynamic_cast<CLabelUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_LABEL, 4));
	CProgressUI* progress = dynamic_cast<CProgressUI*>(_ppm->FindSubControlByClass(TaskList, DUI_CTR_PROGRESS, 0));


	DVR::Download_Info	file;
	DVR::DVRDownloadPacket *pDownload = NULL;
	pDownload = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(_download_items[i]);
	poco_assert(pDownload);

	pDownload->GetMainTask(file);
	lab_filename->SetText(file.fname.c_str());
	lab_filesize->SetText(std::to_string(file.fsize).c_str());
	if (file.lasttime == 99999999)
	{
		char lasttime[50] = { 0 };
		sprintf_s(lasttime, "%d秒", file.lasttime);
	}
	else
	{
		char lasttime[50] = { 0 };
		sprintf_s(lasttime, "%d分%d秒", file.lasttime / 60, file.lasttime % 60);
		lab_lasttime->SetText(lasttime);
	}
	lab_speed->SetText(std::to_string(file.speed).c_str());
	progress->SetValue(file.proValue);
	if (file.proValue == 100)
	{
		lab_status->SetText("完成");
	}
	else if (file.proValue > 0)
	{
		lab_status->SetText("开始下载");
	}

	
}

void CDownLoadList::StopDownload(long searchhandle)
{
	DVR::DVRDownloadPacket* pDownloadItem = DVR::DVRDownloadPakcetContainer::getInstance().GetDownloadItem(searchhandle);
	std::string devicename;
	pDownloadItem->GetDeivceName(devicename);
	DVR::DVRDevice& Device = DVR::DVRDeviceContainer::getInstance().get(devicename);
	DVR::DVRStatement statement(Device.session());

	vector<size_t> ids;
	pDownloadItem->GetDownloading(ids);
	for (int i = 0; i < ids.size(); i++)
	{
		int status = pDownloadItem->GetDownloadStatus(ids[i]);

		switch (status)
		{
		case DVR::DL_STATUS_DOWNLOADING:
		{
			statement.StopDownload(pDownloadItem->GetDownloadHandle(ids[i]));

			break;
		}

		}
	}
}