#include "DVR/DVRSessionFactory.h"
#include "DZP/DVRConnector.h"
#include "DZP/DVRSessionImpl.h"
#include "DZP/Utility.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Path.h>

std::string path = Poco::Path::current() + "\\sdk\\DZP\\NetSdk.dll";
Poco::SharedLibrary sl(path);

const DZPLiteConnectorRegistrator DvrDZPLiteConnectorRegistrator;




namespace DVR {
namespace DZPLite {

const std::string DVRConnector::KEY(DVR_CONNECTOR_NAME);

DVRConnector::DVRConnector()
{	
	int rc = Utility::Init();
	
	if (Utility::success != rc) Utility::throwException(rc);
}


DVRConnector::~DVRConnector()
{
	int rc = Utility::CleanUp();
	
	if (Utility::success != rc)  Utility::throwException(rc);
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