#include "DVR/DVRStatementImpl.h"
#include <Poco/DateTimeParser.h>
namespace DVR {

DVRStatementImpl::DVRStatementImpl(DVRSessionImpl& rSession):
_rSession(rSession),
_ostr()
{
}


DVRStatementImpl::~DVRStatementImpl()
{
}


}

