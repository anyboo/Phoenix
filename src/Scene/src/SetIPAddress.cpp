#include "Scene/SetIPAddress.h"
#include <Poco/Exception.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/ActiveMethod.h>
using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;

CSetIPAddress::CSetIPAddress()
{
	InitNetIF();
}


CSetIPAddress::~CSetIPAddress()
{
}

void CSetIPAddress::InitNetIF()
{
	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& netInter = it->second;
		if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
		{
			_inft = netInter;
		}
	}
}

IPADDRESS_INFO CSetIPAddress::GetCurIPAddress()
{
	IPADDRESS_INFO ipaddress_Info;
	NetworkInterface::AddressList ipList = _inft.addressList();
	size_t n = ipList.size();
	if (n == 0)
	{
		ipaddress_Info.strIP.clear();
		ipaddress_Info.strSubNet.clear();
		ipaddress_Info.strBroadcast.clear();
	}
	else
	{
		IPAddress ipAddress = ipList[n - 1].get<0>();
		IPAddress subnetAddress = ipList[n - 1].get<1>();
		IPAddress broadcastAddress = ipList[n - 1].get<2>();
		ipaddress_Info.strIP = ipAddress.toString();
		ipaddress_Info.strSubNet = subnetAddress.toString();
		ipaddress_Info.strBroadcast = broadcastAddress.toString();
	}
	return ipaddress_Info;
}

#include <shellapi.h>
bool CSetIPAddress::setNetConfig(const std::string& sIP, const std::string& sMask, const std::string& sGate)
{
	std::string mask(" mask=");
	mask.append(sMask);
	std::string sssname = _inft.name();
	int len = MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)sssname.c_str(), -1, NULL, 0);
	wchar_t * wszGBK = new wchar_t[len];
	memset(wszGBK, 0, len);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)sssname.c_str(), -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	std::string sNetName(szGBK);
	delete[] szGBK;
	delete[] wszGBK;

	std::string name(" name = \"");
	name += sNetName;
	name.append("\"");
	std::string addr(" addr=");
	addr += sIP;
	std::string argList;

	if (!sGate.empty())
	{
		argList = "interface ip set address";
		argList += name;
		argList.append(" source = static ");
		argList = argList + addr + mask;
		std::string gateway(" gateway=");
		gateway += sGate;
		argList += gateway;

	}
	else
	{
		argList = "interface ip add address";
		argList += name;
		argList = argList + addr + mask;
	}
	int nRun = (int)::ShellExecuteA(NULL, (LPCSTR)"open", (LPCSTR)"netsh.exe", (LPCSTR)argList.c_str(), NULL, SW_HIDE);
	if (nRun <= 32)
		return false;

	return true;
}

