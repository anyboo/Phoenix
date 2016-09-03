#pragma once

#include "Poco/CppUnit/TestCase.h"
#include "DZP/Utility.h"
#include "DZP/DVRSessionImpl.h"
#include "DZP/DVRStatementImpl.h"
#include "DZP/DVRConnector.h"




class DZPLIBTEST : public CppUnit::TestCase
{
public:
	DZPLIBTEST(const std::string& name);
	~DZPLIBTEST();

	void testlogin();
	void testSession();	

	static CppUnit::Test* suite();
private:

};

