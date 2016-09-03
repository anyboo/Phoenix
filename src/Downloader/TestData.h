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


class CTestData
{
private:	
	CTestData() :_playhandle(0), _SessionID(0){}
public:
	
	static CTestData* getInstance();
	void SaveLoginInfo(Vendor_Info& vendor);
	void GetLoginInfo(Vendor_Info& vendor);
	unsigned long GetLoginID();

	void GetSearchFiles(std::vector<SearchFileInfo>& files);

	void SetPlayhandle(int id);
	void GetPlayFileInfo(Serach_fileInfo& file);

private:
	std::map<unsigned long, Vendor_Info>			_Login_Info;
	std::vector<SearchFileInfo>			_Files_Info;
	static CTestData* m_instance;
	unsigned long						_SessionID;
	int									_playhandle;
};

