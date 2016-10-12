#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(WSDLITE_EXPORTS)
		#define WSDLite_API __declspec(dllexport)
	#else
		#define WSDLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(WSDLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define WSDLite_API __attribute__ ((visibility ("default")))
	#else
		#define WSDLite_API
	#endif
#endif


//
// Automatically link WSDLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(WSDLITE_EXPORTS)
		#pragma comment(lib, "WSDLite" POCO_LIB_SUFFIX)
	#endif
#endif