#include "DVR/DVRSessionFactory.h"
#include "DH/DVRConnector.h"
#include "DH/DVRSessionImpl.h"
#include "DH/Utility.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Path.h>



const DHLiteConnectorRegistrator DvrDHLiteConnectorRegistrator;




namespace DVR {
	namespace DHLite {

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