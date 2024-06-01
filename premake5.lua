workspace "Hannah"
	architecture "x64"
	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hannah"
	location "Hannah"
	kind "SharedLib"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"


		defines 
		{
			"HN_PLATFORM_WINDOWS",
			"HN_BUILD_DLL",
			""
		}

		postbuildcommands 
		{
			("{COPY} ../bin/" .. outputdir .. "/Hannah/*.dll ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "HN_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "HN_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "HN_DIST"
			optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	targetdir ("bin/" .. outputdir .. "/Sandbox/")
	objdir ("bin-int/" .. outputdir .. "/Sandbox/")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Hannah/vendor/spdlog/include",
		"Hannah/src/",
		("%{prj.name}")
	}

	links 
	{
		"Hannah"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"


	defines 
	{
		"HN_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "HN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HN_DIST"
		optimize "On"


