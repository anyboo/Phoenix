#include "TDWY/Notifier.h"

namespace DVR {
	namespace TDWYLite {

Notifier::Notifier(const DVRSession& session, EnabledEventType enabled):
	_session(session)
{
	if (enabled & DVRLITE_NOTIFY_DOWNLOAD) enableDownload();
	if (enabled & DVRLITE_NOTIFY_PLAYBACK) enablePlayback();
}


Notifier::~Notifier()
{
	try
	{
		disableAll();
	}
	catch (...)
	{
		poco_unexpected();
	}
}

bool Notifier::enableDownload()
{
	Poco::Mutex::ScopedLock l(_mutex);

	if (Utility::registerUpdateHandler(_session, &dvrDownloadCallbackFn, this))
		_enabledEvents |= DVRLITE_NOTIFY_DOWNLOAD;

	return downloadEnabled();
}

bool Notifier::disableDownload()
{
	Poco::Mutex::ScopedLock l(_mutex);

	if (Utility::registerUpdateHandler(_session, (Utility::EventCallbackType) 0, this))
		_enabledEvents &= ~DVRLITE_NOTIFY_DOWNLOAD;

	return !downloadEnabled();
}

bool Notifier::downloadEnabled() const
{
	return 0 != (_enabledEvents & DVRLITE_NOTIFY_DOWNLOAD);
}

bool Notifier::enablePlayback()
{
	
	Poco::Mutex::ScopedLock l(_mutex);

	if (Utility::registerUpdateHandler(_session, &dvrPlaybackCallbackFn, this))
		_enabledEvents |= DVRLITE_NOTIFY_PLAYBACK;

	return playbackEnabled();
}

bool Notifier::disablePlayback()
{
	Poco::Mutex::ScopedLock l(_mutex);

	if (Utility::registerUpdateHandler(_session, (Utility::EventCallbackType) 0, this))
		_enabledEvents &= ~DVRLITE_NOTIFY_PLAYBACK;

	return !playbackEnabled();
}

bool Notifier::playbackEnabled() const
{
	return 0 != (_enabledEvents & DVRLITE_NOTIFY_PLAYBACK);
}

bool Notifier::disableAll()
{
	return disableDownload() && disablePlayback();
}

void Notifier::dvrDownloadCallbackFn(void* pVal)
{
	//fixed
}

void Notifier::dvrPlaybackCallbackFn(void* pVal)
{
	//fixed
}

}}