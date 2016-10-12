#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(TDWYLITE_EXPORTS)
		#define TDWYLite_API __declspec(dllexport)
	#else
		#define TDWYLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(TDWYLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define TDWYLite_API __attribute__ ((visibility ("default")))
	#else
		#define TDWYLite_API
	#endif
#endif


//
// Automatically link TDWYLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(TDWYLITE_EXPORTS)
		#pragma comment(lib, "TDWYLite" POCO_LIB_SUFFIX)
	#endif
#endif