#include "DVR/DVRSessionFactory.h"
#include "TDWY/DVRConnector.h"
#include "TDWY/DVRSessionImpl.h"
#include "TDWY/Utility.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Path.h>




const TDWYLiteConnectorRegistrator DvrTDWYLiteConnectorRegistrator;




namespace DVR {
	namespace TDWYLite {

const std::string DVRConnector::KEY(DVR_CONNECTOR_NAME);

DVRConnector::DVRConnector()
{	
	/*int rc = Utility::Init();
	
	if (Utility::success != rc) Utility::throwException(rc);*/
}


DVRConnector::~DVRConnector()
{
	/*int rc = Utility::CleanUp();
	
	if (Utility::success != rc)  Utility::throwException(rc);*/
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