#include "DZP/Notifier.h"

namespace DVR {
namespace DZPLite {

Notifier::Notifier(const DVRSession& session):
_session(session)
{
}


Notifier::~Notifier()
{
}

void Notifier::ProcessCallbackFn(long lPlayHandle, long lTotalSize, long lDownLoadSize, long pVal)
{
	poco_assert(lPlayHandle > 0);
	Notifier* pV = reinterpret_cast<Notifier*>(pVal);
	/*if (opCode == Notifier::DOWNLOAD)
	{
		pV->_row = row;
		pV->insert.notify(pV);
	}
	else if (opCode == Notifier::PLAY)
	{
		pV->_row = row;
		pV->update.notify(pV);
	}*/
}

}}