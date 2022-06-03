#pragma once

#ifdef PP_PLATFORM_WINDOWS
	#ifdef PP_BUILD_DLL
		#define PPOEM_API __declspec(dllexport)
	#else
		#define PPOEM_API __declspec(dllimport)
	#endif
#else
	#error PPoem only support Windows!
#endif
