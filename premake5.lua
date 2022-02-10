workspace "Liquid"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Disk"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (Solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Liquid/vendor/GLFW/include"

include "Liquid/vendor/GLFW"

project "Liquid"
	location "Liquid"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lqpch.h"
	pchsource "Liquid/src/lqpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LQ_PLATFORM_WINDOWS",
			"LQ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
		}

	filter "configurations:Debug"
		defines "LQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LQ_Dist"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Liquid/vendor/spdlog/include",
		"Liquid/src"
	}

	links
	{
		"Liquid"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LQ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LQ_DIST"
		symbols "On"

 