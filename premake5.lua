--premake5.lua

workspace "PPoem" -- 设置工作区目录
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- cfg就是configurations的缩写
-- 拼接结果类似：Debug-windows-x86_64

project "PPoem"
	location "PPoem"
	kind "SharedLib"
language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PP_PLATFORM_WINDOWS",
			"PP_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			-- {COPY}复制，之后的命令以空格来划分
			-- %{cfg.buildtarget.relpath} = 'bin\Debug-windows-x86_64\PPoem\PPoem.dll'
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

		filter "configurations:Debug"
			defines "PP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "PP_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "PP_DIST"
			optimize "On"

			
project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"

	}

	includedirs
	{
		"PPoem/ThirdParty/spdlog/include",
		"PPoem/source/include"
	}

	links
	{
		"PPoem"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PP_PLATFORM_WINDOWS",

		}

		filter "configurations:Debug"
			defines "PP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "PP_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "PP_DIST"
			optimize "On"