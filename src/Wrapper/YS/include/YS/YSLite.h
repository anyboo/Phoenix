#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(YSLITE_EXPORTS)
		#define YSLite_API __declspec(dllexport)
	#else
		#define YSLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(YSLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define YSLite_API __attribute__ ((visibility ("default")))
	#else
		#define YSLite_API
	#endif
#endif


//
// Automatically link YSLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(YSLITE_EXPORTS)
		#pragma comment(lib, "YSLite" POCO_LIB_SUFFIX)
	#endif
#endif