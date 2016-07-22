#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN

#endif

#include <WinSock2.h>
#include <windows.h>
#include <string>
#include <vector>
#include <thread>
#include <list>
#include <memory>
#include <mutex>
using namespace std;
//
#pragma comment(lib, "Ws2_32.lib")

#define DEF_PACKET_SIZE 32
#define ECHO_REQUEST 8
#define ECHO_REPLY 0

struct IPHeader
{
	BYTE m_byVerHLen;   //4 bit version + 4 bit len
	BYTE m_byTOS;       //type
	USHORT m_usTotalLen; //length
	USHORT m_usID;      //id
	USHORT m_usFlagFragOffset; //
	BYTE m_byTTL; //TTL
	BYTE m_byProtocol; //protocol
	USHORT m_usHChecksum; //ip check sum
	ULONG m_ulSrcIP; //src ip 
	ULONG m_ulDestIP; //dst ip
};

struct ICMPHeader
{ 
	BYTE m_byType;   //type
	BYTE m_byCode;   //code 
	USHORT m_usChecksum; //check sum
	USHORT m_usID; //id
	USHORT m_usSeq; //seq
	ULONG m_ulTimeStamp; //time head
};

struct PingReply
{
	USHORT m_usSeq;
	DWORD m_dwRoundTripTime;
	DWORD m_dwBytes;
	DWORD m_dwTTL;
};
struct OnePingInfo
{
    SOCKET m_sockRaw;
    WSAEVENT m_event;
    bool m_bStop;
    char* m_szICMPData;
    std::shared_ptr<std::thread> m_pReadThread;
    OnePingInfo();
    ~OnePingInfo();
};
class CPing
{

    static CPing* spInstance;
    CPing(); 
    bool init(std::shared_ptr<OnePingInfo> pingInfo);
    ~CPing();
    
public:
    static CPing& instance(){
        if (NULL == spInstance)
        {
            spInstance = new CPing();
        }
        
        return *spInstance;
    }

    void ScanIp(vector<string> &vecIp, bool bArp = false, std::shared_ptr<bool> bpCancel = std::shared_ptr<bool>());
    void ScanIPs(vector<string> &vecIP, const string& netIp, bool bArp = false, std::shared_ptr<bool> bpCancel = std::shared_ptr<bool>());
    bool ScanOneIP(string &ip, const string& netIp, bool bArp = false);
    BOOL Ping(DWORD dwDestIP, long dwTimeout = 20, bool bArp = false);
    BOOL Ping(const char *szDestIP, long dwTimeout = 20, bool bArp = false);

private:
    BOOL PingCore(DWORD dwDestIP, long dwTimeout, std::shared_ptr<OnePingInfo> pingInfo, bool bArp = false);
	USHORT CalCheckSum(USHORT *pBuffer, int nSize);
	ULONG GetTickCountCalibrate();
private:

	USHORT m_usCurrentProcID;



    std::shared_ptr<OnePingInfo> mpLastPingInfo;
    std::recursive_mutex mMtLastPingInfo;
private:
	static ULONG s_usPacketSeq;
    
};