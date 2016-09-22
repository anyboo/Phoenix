#pragma once
#include "DVR/DVR.h"
#include <Poco/SharedPtr.h>
#include <Poco/DateTime.h>
#include "DVR/DVRSessionImpl.h"
#include <sstream>

namespace DVR {
	struct RecordFile
	{
		RecordFile()
		{
			channel = 0;
			size = 0;
			pPrivateData = nullptr;
			PrivateDataDataSize = 0;
		}

		~RecordFile()
		{
			if (nullptr != pPrivateData)
			{
				delete pPrivateData;
				pPrivateData = nullptr;
				PrivateDataDataSize = 0;
			}
		}

		RecordFile(const RecordFile& other)
		{
			channel = other.channel;
			size = other.size;
			name = other.name;
			beginTime = other.beginTime;
			endTime = other.endTime;
			pPrivateData = nullptr;
			PrivateDataDataSize = 0;
			setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
		}

		RecordFile& operator= (const RecordFile& other)
		{
			if (&other == this)
			{
				return *this;
			}
			channel = other.channel;
			size = other.size;
			name = other.name;
			beginTime = other.beginTime;
			endTime = other.endTime;
			setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
			return *this;
		}

		void setPrivateData(void* pData, int size)
		{
			if (nullptr != pPrivateData)
			{
				delete pPrivateData;
				pPrivateData = nullptr;
				PrivateDataDataSize = 0;
			}


			if (size > 0)
			{
				pPrivateData = new char[size];
				PrivateDataDataSize = size;
				memcpy(pPrivateData, pData, size);
			}
		}
		//取得私有数据
		void* getPrivateData() const
		{
			return pPrivateData;
		}
		__int32 getPrivateDataSize() const
		{
			return PrivateDataDataSize;
		}

		size_t channel;      //通道
		size_t size;         //文件大小(byte)
		std::string  name;    //文件名称
		Poco::DateTime beginTime; //本地时间
		Poco::DateTime endTime;   //本地时间
		char* pPrivateData;   //私有数据
		__int32 PrivateDataDataSize;//私有数据大小
	};

	class DVR_API DVRStatementImpl
	{
	public:
		typedef Poco::SharedPtr<DVRStatementImpl> Ptr;

		DVRStatementImpl(DVRSessionImpl& rSession);
		virtual ~DVRStatementImpl();

		template <typename T>
		void add(const T& t)
		{
			_ostr << t;
		}

	public:
		virtual void donwloadByName(const std::string& filename) = 0;
		virtual void downloadByTime(const Poco::DateTime& time) = 0;
		
		virtual void playByName(const RecordFile& filename, HWND& hwnd) = 0;
		virtual void playByTime(const Poco::DateTime& time) = 0;

		virtual void list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime, const std::vector<int>& channels, std::vector<RecordFile>& files) = 0;

		virtual bool canDownloadByName() = 0;
		virtual bool canPlayByName() = 0;

		DVRSessionImpl& session();

	private:
		DVRSessionImpl&	_rSession;
		std::ostringstream  _ostr;
	};
}
