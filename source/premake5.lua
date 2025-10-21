workspace "FrameLog"
   architecture "x64"
   configurations { "Debug", "Release" }

   location "build"

project "FrameLog"
    kind "ConsoleApp"
    language "C"

    targetdir "build/bin/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "**.c", "**.h" }

    includedirs { "." }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        symbols "Off"


