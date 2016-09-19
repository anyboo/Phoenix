#include "DVR/DVRSessionFactory.h"
#include "JXJ/DVRConnector.h"
#include "JXJ/DVRSessionImpl.h"
#include "JXJ/Utility.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Path.h>




const JXJLiteConnectorRegistrator DvrJXJLiteConnectorRegistrator;


namespace DVR {
	namespace JXJLite {

const std::string DVRConnector::KEY(DVR_CONNECTOR_NAME);

DVRConnector::DVRConnector()
{	
	
	
}


DVRConnector::~DVRConnector()
{
	
}

Poco::AutoPtr<DVR::DVRSessionImpl> DVRConnector::createSession(const std::string& connectionString,
	std::size_t timeout)
{
	return Poco::AutoPtr<DVR::DVRSessionImpl>(new DVRSessionImpl(connectionString, timeout));	
}

void DVRConnector::registerConnector()
{
	DVR::DVRSessionFactory::instance().add(new DVRConnector());
}

void DVRConnector::unregisterConnector()
{
	DVR::DVRSessionFactory::instance().remove(DVR_CONNECTOR_NAME);
}

}}