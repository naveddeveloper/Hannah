#pragma once
 
#ifdef HN_PLATFORM_WINDOWS
	#ifdef HN_BUILD_DLL
		#define HANNAH_API __declspec(dllexport)
	#else
		#define HANNAH_API __declspec(dllimport)
	#endif // HN_BUILD_DLL
#else
	#error Hannah only support Windows!
#endif // HN_FLATFORM_WINDOWS