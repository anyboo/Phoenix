#pragma once

typedef struct  
{
	size_t id;
	size_t channel;
	size_t size;
	std::string name;
	std::time_t startTime;
	std::time_t endTime;
}DownloadItem, *pDownloadItem;

typedef std::list<DownloadItem*> DownloadListItem;

class DownloadPackage
{
public:
	DownloadPackage();
	~DownloadPackage();

public:
	void Add(pDownloadItem& item);
	std::string GetFileName(size_t CurSel);
	void Remove();
public:
	DownloadListItem downloadlist;
};

