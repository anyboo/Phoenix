#include "DVR/DVRSessionFactory.h"
#include "JXJ/DVRConnector.h"
#include "JXJ/DVRSessionImpl.h"
#include "JXJ/Utility.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Path.h>


Poco::SharedLibrary avutil("sdk\\JXJ\\avutil-50.dll");
Poco::SharedLibrary avcore("sdk\\JXJ\\avcore-0.dll");
Poco::SharedLibrary avcodec52("sdk\\JXJ\\avcodec-52.dll");
Poco::SharedLibrary swscale("sdk\\JXJ\\swscale-0.dll");
Poco::SharedLibrary jxjcodec("sdk\\JXJ\\jxjcodec.dll");
Poco::SharedLibrary avplayer("sdk\\JXJ\\AVPlayer.dll");

Poco::SharedLibrary sl("sdk\\JXJ\\JNetSDK.dll");

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