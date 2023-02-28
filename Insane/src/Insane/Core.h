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

# define BIT(x) (1 << x)
