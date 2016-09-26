#include "DVR/DVRStatement.h"
#include "DVR/DVRSession.h"
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR {

DVRStatement::DVRStatement(DVRStatementImpl::Ptr pImpl):
_pImpl(pImpl)
{
	poco_check_ptr(pImpl);
}


DVRStatement::~DVRStatement()
{
}


DVRStatement::DVRStatement(DVRSession& rSession)
{
	reset(rSession);
}

DVRStatement::DVRStatement(const DVRStatement& stmt):
_pImpl(stmt._pImpl)
{

}

DVRStatement& DVRStatement::operator = (const DVRStatement& stmt)
{
	DVRStatement tmp(stmt);
	swap(tmp);
	return *this;
}

void DVRStatement::swap(DVRStatement& other)
{
	using std::swap;
	swap(_pImpl, other._pImpl);
}

DVRStatement& DVRStatement::reset(DVRSession& rSession)
{
	DVRStatement stmt(rSession.createStatementImpl());
	swap(stmt);
	return *this;
}


void DVRStatement::DownloadByName(const std::vector<size_t>& IDs, const std::string path, std::vector<long>& handles)
{
	std::vector<long> _download_handle;
	time_t nowtime;
	time(&nowtime);
	std::vector<RecordFile>  files;
	DVRSearchFilesContainer::getInstance().GetDownloadfiles(IDs, files);
	for (size_t i = 0; i < IDs.size(); i++)
	{
		nowtime++;
		std::string vedioname = std::to_string(nowtime) + std::string(".h264");
		std::string download_path = path + std::string("\\") + vedioname;
		long handle = _pImpl->donwloadByName(files[i], download_path);
		_download_handle.push_back(handle);
	}
	handles = _download_handle;
}

int DVRStatement::GetDownloadPro(const long handle)
{
	int pos = _pImpl->getdownloadPos(handle);
	return pos;
}

void DVRStatement::DownloadByTime(const Poco::DateTime stime, const Poco::DateTime etime)
{
	
}

void DVRStatement::stopPlay(int playhandle)
{
	_pImpl->stopPlayback(playhandle);
}

int DVRStatement::getplayPos(const int playhandle)
{
	int pos = _pImpl->getplayPos(playhandle);
	return pos;
}

void DVRStatement::setplayPos(const int playhandle, const int Pos)
{
	_pImpl->setplayPos(playhandle, Pos);
}

void DVRStatement::Searchfile(const Poco::DateTime stime, const Poco::DateTime etime, const std::vector<int>& Channels)
{
	std::vector<RecordFile>  files;
	_pImpl->list(stime, etime, Channels, files);
	DVRSearchFilesContainer::getInstance().Clear();
	DVRSearchFilesContainer::getInstance().Add(files);
}

int DVRStatement::playByName(const size_t fileID, HWND& hwnd)
{
	RecordFile& file = DVRSearchFilesContainer::getInstance().GetFileById(fileID);
	return _pImpl->playByName(file, hwnd);
}

void DVRStatement::playByTime(const size_t fileID, HWND& hwnd)
{
	RecordFile& file = DVRSearchFilesContainer::getInstance().GetFileById(fileID);
	_pImpl->playByName(file, hwnd);
}

}