#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(JXJLITE_EXPORTS)
		#define JXJLite_API __declspec(dllexport)
	#else
		#define JXJLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(JXJLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define JXJLite_API __attribute__ ((visibility ("default")))
	#else
		#define JXJLite_API
	#endif
#endif


//
// Automatically link JXJLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(JXJLITE_EXPORTS)
		#pragma comment(lib, "JXJLite" POCO_LIB_SUFFIX)
	#endif
#endif