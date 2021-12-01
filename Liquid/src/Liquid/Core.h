#pragma once

#ifdef LQ_PLATFORM_WINDOWS
	#ifdef	LQ_BUILD_DLL
		#define	LIQUID_API __declspec(dllexport)
	#else
		#define	LIQUID_API __declspec(dllimport)
	#endif
#else
	#error Liquid Engine only supports Windows!
#endif 