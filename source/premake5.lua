workspace "FrameLog"
   architecture "x64"
   configurations { "Debug", "Release" }

   location "build"

project "FrameLog"
    kind "ConsoleApp"
    language "C"

    targetdir "build/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "**.c", "**.h" }

    includedirs { "." }

    filter "action:vs*"
        buildoptions { "/W3" }   -- MSVC
    filter "toolset:gcc"
        buildoptions { "-Wall" } -- GCC / MinGW

    filter "configurations:Debug"
        defines { "DEBUG", "FL_ENABLE_ERROR_LOGS=1" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG", "FL_ENABLE_ERROR_LOGS=0" }
        optimize "On"
        symbols "Off"