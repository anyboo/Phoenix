#include "stdafx.h"
#include "TestData.h"
#include <mutex> 
#include "DVR/DVRSession.h"
std::mutex mtx;


CTestData *CTestData::m_instance = nullptr;

CTestData* CTestData::getInstance()
{
	if (nullptr == m_instance)
	{
		mtx.lock();
		if (NULL == m_instance)
		{
			m_instance = new CTestData;
		}
		mtx.unlock();
	}
	return m_instance;
}

void CTestData::SaveLoginInfo(Vendor_Info& vendor)
{
	_SessionID += 1;
	vendor.channels = 4;
	_Login_Info.insert(pair<unsigned long, Vendor_Info>(_SessionID, vendor));
}

void CTestData::GetLoginInfo(Vendor_Info& vendor)
{
	vendor = _Login_Info[_SessionID];
}

unsigned long CTestData::GetLoginID()
{
	return _SessionID;
}

bool CTestData::IsLogIn(const std::string ip)
{
	std::map<unsigned long, Vendor_Info>::iterator itor = _Login_Info.begin();
	for (; itor != _Login_Info.end();itor++)
	{
		if ((itor->second).ipAddr == ip)
		{
			return true;
		}
	}
	return false;
}

DVR::DVRSession* CTestData::GetSessionByID(unsigned long id)
{
	return _Login_Info[id].session;
}

void CTestData::GetSearchFiles(std::vector<SearchFileInfo>& files)
{
	time_t now_time;
	now_time = time(NULL);

	Serach_fileInfo file_info;
	for (int i = 1; i <= 10; i++)
	{
		file_info.channel = 1;
		file_info.filename = std::string("filename") + to_string(i);
		file_info.startTime = now_time - 10000;
		file_info.stopTime = now_time;
		file_info.size = 324213;
		files.push_back(file_info);
	}
	_Files_Info = files;
}

void CTestData::SetPlayhandle(int id)
{
	_playhandle = id;
}

void CTestData::GetPlayFileInfo(Serach_fileInfo& file)
{
	file = _Files_Info[_playhandle];
}

void CTestData::SetDownloadfiles(const std::vector<int> fileID)
{
	_file_ID = fileID;
	_downloadpacket_id += 1;
	std::vector<DownLoad_Info> download_Info;
	for (size_t i = 0; i < _file_ID.size(); i++)
	{
		DownLoad_Info files;
		files.filename = _Files_Info[_file_ID[i]].filename;
		files.lastTime = 100;
		files.progress = 0;
		files.filesize = 2312312;
		files.speed = 4;
		files.state = 0;
		download_Info.push_back(files);
	}
	_downloadpacket.insert(pair<unsigned long, std::vector<DownLoad_Info>>(_downloadpacket_id, download_Info));
}

int CTestData::GetDownloadSize(const unsigned long download_id)
{
	return _downloadpacket[download_id].size();
}

unsigned long CTestData::GetCurrentDid()
{
	return _downloadpacket_id;
}

void CTestData::GetDownloadInfo(const unsigned long id, std::vector<DownLoad_Info>& downlaod_packet)
{
	if (ndex > 100)
	{
		ndex = 0;
	}
	downlaod_packet = _downloadpacket[id];
	for (int i = 0; i < downlaod_packet.size(); i++)
	{
		downlaod_packet[i].lastTime = 100 - 1 * ndex;
		downlaod_packet[i].progress = 0 + 1 * ndex;
	}
	ndex++;
}

