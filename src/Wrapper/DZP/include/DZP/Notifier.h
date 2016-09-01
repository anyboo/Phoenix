#pragma once

#include "DZPLite.h"
#include "DVR/DVRSession.h"
#include <Poco/BasicEvent.h>

namespace DVR {
namespace DZPLite {

class DZPLite_API Notifier
{
public:
	typedef unsigned char EnabledEventType;

	typedef Poco::BasicEvent<void> Event;

	Event downloadPos;

	static const EnabledEventType DVR_NOTIFY_DOWNLOADPOS = 1;

	Notifier(const DVRSession& session,
		EnabledEventType enabled = DVR_NOTIFY_DOWNLOADPOS);

	~Notifier();

	bool enableDownlaodPos();
	bool disableDownloadPos();
	bool DownloadPosEnabled() const;

	bool operator == (const Notifier& other) const;
	Poco::Int64 getPos() const;

private:
	Notifier();
	Notifier(const Notifier&);
	Notifier& operator=(const Notifier&);

	const DVRSession&  _session;
	Poco::Int64        _pos;
	EnabledEventType   _enabledEvents;
	Poco::Mutex        _mutex;
};

}}