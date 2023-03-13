workspace "Insane"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Insane"
	location "Insane"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ispch.h"
	pchsource "Insane/src/ispch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IS_PLATFORM_WINDOWS",
			"IS_BUILD_DLL" 
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "IS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Insane/src",
		"Insane/vendor/spdlog/include"
	}

	links
	{
		"Insane"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IS_DIST"
		optimize "On"
