#include "stdafx.h"
#include "DownloadPackage.h"


DownloadPackage::DownloadPackage()
{
}


DownloadPackage::~DownloadPackage()
{
}

void DownloadPackage::Add(pDownloadItem& item)
{
	downloadlist.push_back(item);
}

void DownloadPackage::Remove()
{

}

std::string DownloadPackage::GetFileName(size_t CurSel)
{
	std::list<DownloadItem*>::iterator iter = downloadlist.begin();
	size_t i = 0;
	while (i != CurSel)
	{
		iter++;
		i++;
	}
	DownloadItem* item = (DownloadItem*)(*iter);
	std::string strName = item->name;
	return strName;
}

