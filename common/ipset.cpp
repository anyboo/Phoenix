#include "stdafx.h"
#include "ipset.h"
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include "windowutils.h"
#include "PING.h"
#include "log.h"

using namespace std;


void IPSet::ipsetting()
{
	int i;
	//net card status
	if (!WindowUtils::isOnLine())
	{
		return;
	}

	std::shared_ptr<string> pIP = std::make_shared<string>();
	std::shared_ptr<string> pNetGate = std::make_shared<string>();
	std::shared_ptr<string> pMask = std::make_shared<string>("255.255.255.0");
	std::shared_ptr<bool> bDhcpResult = std::make_shared<bool>(false);
	std::shared_ptr<bool> bResult = std::make_shared<bool>(false);

	std::set<string> Ips;	
	vector<string> scanips;
	set<string>::iterator itor;
	set<string> Domains;
	set<string> findIps;


	//dhcp setting ip
	WindowUtils::setIPByDHCP(*pIP, *pMask, *pNetGate);	
	poco_information_f2(logger_handle, "Dhcp set ip : %s, netgate: %s", *pIP, *pNetGate);
	//listen arp packet
	*bResult = WindowUtils::getDirectDevice(Ips, findIps);
	if (*bResult)
	{
		//direct connection 
		if (Ips.size() == 1)
		{
			itor = Ips.begin();
			string strIp = *itor;
			string strnum = strIp.substr(strIp.find_last_of(".") + 1, strIp.size());
			strIp = strIp.substr(0, strIp.find_last_of(".") + 1);
			int number = stoi(strnum) + 1;
			strIp = strIp.append(to_string(number));
			*pIP = strIp;
			*pNetGate = *itor;
			if (!WindowUtils::setNetConfig(WindowUtils::getLocalUuid(), *pIP, "255.255.255.0", *pNetGate, true))
			{				
				poco_error(logger_handle, "direct set ip error ! ");
			}
			return;
		}
		

		for (itor = Ips.begin(); itor != Ips.end(); itor++)
		{
			string sDomain = *itor;
			sDomain = sDomain.substr(0, sDomain.find_last_of("."));
			Domains.insert(sDomain);
		}
		//check rand ip
		int iSecret;
		for (itor = Domains.begin(); itor != Domains.end(); itor++)
		{
			//set net gate
			string sNetGate(*itor);
			sNetGate.append(".1");
			//set net ip
			string sIP(*itor);
			sIP.append(".144");
			//setting
			if (!WindowUtils::setNetConfig(WindowUtils::getLocalUuid(), sIP, "255.255.255.0", sNetGate, true))
			{
				continue;
			}

			//send ping 
			string stmp = *itor;
			stmp.append(".1");
			scanips.push_back(stmp);
			CPing::instance().instance().Ping(stmp.c_str(), 0, false);
			for (i = 1; i < 6; i++)
			{
				srand(time(NULL) * i);
				iSecret = std::rand() / 100 % 100 + 100;
				stmp = *itor;
				stmp.append(".");
				stmp.append(std::to_string(iSecret));
				scanips.push_back(stmp);
				CPing::instance().instance().Ping(stmp.c_str(), 1, false);
			}
		}
		Sleep(1000*2);		
		WindowUtils::getMacByArpTable(scanips, findIps);			
		poco_information_f1(logger_handle, "get arp table size: %d", (int)findIps.size());
		for (itor = findIps.begin(); itor != findIps.end(); itor++)
		{						
			poco_information_f1(logger_handle, "find ips, ip:  %s", *itor);
		}
		
		vector<string>::iterator vitor;
		for (vitor = scanips.begin(); vitor != scanips.end(); vitor++)
		{
			string sgate("1");
			string stmp = *vitor;
			stmp = stmp.substr(stmp.find_last_of(".") + 1, stmp.size());
			if (stmp.compare(sgate) == 0)
			{
				vitor = scanips.erase(vitor);
				continue;
			}

			for (itor = findIps.begin(); itor != findIps.end(); itor++)
			{				
				if ((*vitor).compare(*itor) == 0)
				{
					vitor = scanips.erase(vitor);
					break;
				}
			}
		}

		for (vitor = scanips.begin() + 1; vitor != scanips.end(); vitor++)
		{
			vector<string>::iterator vfirst;
			vfirst = vitor;
			vfirst--;
			string ipfirst = *vfirst;
			string ipsecond = *vitor;
			ipfirst = ipfirst.substr(0, ipfirst.find_last_of("."));
			ipsecond = ipsecond.substr(0, ipsecond.find_last_of("."));

			for (itor = Domains.begin(); itor != Domains.end(); itor++)
			{
				if ((ipfirst.compare(*itor) == 0) && (ipsecond.compare(*itor) == 0))
				{
					vitor = scanips.erase(vfirst);
					break;
				}
			}
		}

		

		//set ip and net gate
		if ((*pNetGate).empty() || (*pNetGate).compare(string("0.0.0.0")) == 0)
		{
			bool bSetGate = false;
			for (itor = Domains.begin(); itor != Domains.end(); itor++)
			{
				for (i = 0; i < scanips.size(); i++)
				{
					string iptmp = scanips[i];
					string domaintmp = iptmp.substr(0, iptmp.find_last_of("."));

					*pIP = "";
					*pNetGate = "";
					if (domaintmp.compare(*itor) == 0)
					{
						*pIP = iptmp;
						set<string>::iterator finditor;
						for (finditor = findIps.begin(); finditor != findIps.end(); finditor++)
						{
							string tmp = domaintmp;
							tmp.append(".1");							
							if (tmp.compare(*finditor) == 0)
							{
								*pNetGate = tmp;
								Domains.erase(itor);
								bSetGate = true;								
								poco_information_f2(logger_handle, "ip: %s, gate: %s", *pIP, *pNetGate);
								if (!WindowUtils::setNetConfig(WindowUtils::getLocalUuid(), *pIP, "255.255.255.0", *pNetGate, true))
								{									
									poco_error_f2(logger_handle, "set ip gate error !ip: %s,  gate: %s", *pIP, *pNetGate);
									*bResult = false;
								}
								goto addip;
							}
						}						
					}
				}				
			}
		}
		else
		{
			string sDhcpIP = *pIP;
			sDhcpIP = sDhcpIP.substr(0, sDhcpIP.find_last_of("."));
			for (itor = Domains.begin(); itor != Domains.end(); itor++)
			{
				if (sDhcpIP.compare(*itor) == 0)
				{
					Domains.erase(itor);
					break;
				}
			}
			if (!WindowUtils::setNetConfig(WindowUtils::getLocalUuid(), *pIP, "255.255.255.0", *pNetGate, true))
			{				
				poco_error_f2(logger_handle, "set ip gate error !ip: %s, gate: %s", *pIP, *pNetGate);
				*bResult = false;
			}
		}
addip:	
		//add ip
		for (itor = Domains.begin(); itor != Domains.end(); itor++)
		{
			for (i = 0; i < scanips.size(); i++)
			{
				string iptmp = scanips[i];
				string domaintmp = iptmp.substr(0, iptmp.find_last_of("."));

				*pIP = "";
				*pNetGate = "";
				if (domaintmp.compare(*itor) == 0)
				{
					*pIP = iptmp;					
					poco_information_f2(logger_handle, "0 ip: %s, gate: %s", *pIP, *pNetGate);
					if (!WindowUtils::setNetConfig(WindowUtils::getLocalUuid(), *pIP, "255.255.255.0", *pNetGate, true))
					{						
						poco_error_f2(logger_handle, "error set ip: %s, net gate: %s", *pIP, *pNetGate);
					}
					break;
				}
			}
		}
	}
}

void IPSet::run()
{
	time_t t_start, t_end;
	t_start = time(NULL);
	ipsetting();
	t_end = time(NULL);
	poco_information_f1(logger_handle, "0 time: %.0f s\n", difftime(t_end, t_start));

}

bool IPSet::sortByIp(string srFirst, string srSecond)
{
	unsigned long lIp1 = inet_addr(srFirst.c_str());
	unsigned long lIp2 = inet_addr(srSecond.c_str());

	return (lIp1 < lIp2);
}

