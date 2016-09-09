#pragma once
#include <vector>
#include <map>
#include "DVR/DVRSession.h"
class DVR::DVRSession;

typedef struct VendorInfo
{
	DVR::DVRSession* session;
	int channels;
	std::string vendorName;
	std::string ipAddr;
}Vendor_Info, *pVendor_Info;

typedef struct SearchFileInfo
{
	std::string filename;
	int			channel;
	__time64_t  startTime;
	__time64_t  stopTime;
	size_t		size;
}Serach_fileInfo, *pSearch_fileInfo;

typedef struct DownloadInfo
{
	std::string filename;
	size_t		filesize;
	int			progress;
	int			speed;
	int			lastTime;
	int			state;
}DownLoad_Info, *pDownLoad_Info;

class CTestData
{
private:	
	CTestData() :_playhandle(0), ndex(0), _SessionID(0), _downloadpacket_id(0){}
public:
	
	static CTestData* getInstance();
	void SaveLoginInfo(Vendor_Info& vendor);
	void GetLoginInfoByID(unsigned long vendor_id, Vendor_Info& vendor);
	void DeleteVendorByID(const unsigned long vendor_id);
	unsigned long GetLoginID();
	void GetAllLoginDIs(std::vector<unsigned long>& LoginIDs);
	bool IsLogIn(const std::string ip);

	DVR::DVRSession* GetSessionByID(unsigned long id);
	void GetSearchFiles(std::vector<SearchFileInfo>& files);

	void SetPlayhandle(int id);
	void GetPlayFileInfo(Serach_fileInfo& file);

	void SetDownloadfiles(const std::vector<int> fileID);

	int GetDownloadSize(const unsigned long download_id);
	unsigned long GetCurrentDid();
	void GetDownloadAllpacketID(std::vector<unsigned long>& IDs);
	void GetDownloadInfo(const unsigned long id, std::vector<DownLoad_Info>& downlaod_packet);

	void DeleteTaskByFileName(const std::string fName, unsigned long packet_id);
	void DeleteWholeTaskByID(const unsigned long packet_id);

private:
	std::map<unsigned long, Vendor_Info>			_Login_Info;
	std::vector<SearchFileInfo>			_Files_Info;
	int ndex;
	std::map<unsigned long, std::vector<DownLoad_Info>>   _downloadpacket;
	std::vector<int>						_file_ID;
	static CTestData* m_instance;
	unsigned long						_SessionID;
	unsigned long						_downloadpacket_id;
	int									_playhandle;
};

