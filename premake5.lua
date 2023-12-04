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
IncludeDir["Glad"] = "Liquid/vendor/Glad/include"
IncludeDir["ImGui"] = "Liquid/vendor/imgui"

include "Liquid/vendor/GLFW"
include "Liquid/vendor/Glad"
include "Liquid/vendor/imgui"

project "Liquid"
	location "Liquid"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"Dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LQ_PLATFORM_WINDOWS",
			"LQ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
		}

	filter "configurations:Debug"
		defines "LQ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LQ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LQ_Dist"
		runtime "Release"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines
		{
			"LQ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LQ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LQ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LQ_DIST"
		runtime "Release"
		symbols "On"
		

 