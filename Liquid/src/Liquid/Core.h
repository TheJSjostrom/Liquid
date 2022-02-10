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

#ifdef LQ_ENABLE_ASSERTS
	#define LQ_ASSERT(x, ...) { if(!(x)) { LQ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LQ_CORE_ASSERT(x, ...) { if(!(x)) { LQ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LQ_ASSERT(x, ...)
	#define LQ_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)