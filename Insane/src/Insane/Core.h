#pragma once

#ifdef IS_PLATFORM_WINDOWS
	#ifdef IS_BUILD_DLL
		#define INSANE_API __declspec(dllexport)
	#else
		#define INSANE_API __declspec(dllimport)
	#endif // IS_BUILD_DLL
#else
	#error Insane only supports Windows
#endif

#ifdef IS_ENABLE_ASSERTS
	#define IS_ASSERT(x, ...) { if(!(x)) { IS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define IS_CORE_ASSERT(x, ...) { if(!(x)) { IS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define IS_ASSERT(x, ...)
	#define IS_CORE_ASSERT(x, ...)
#endif

# define BIT(x) (1 << x)
