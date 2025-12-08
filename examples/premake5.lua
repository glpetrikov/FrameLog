--============================================================
-- FrameLog - MIT License (c) 2025 Gleb Petrikov
--============================================================

--==========================================
-- Examples
--==========================================

--==========================================
-- SimpleExample
--==========================================

project "SimpleExample"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "../build/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    files { "SimpleExample.cpp" }

    links { "FrameLog" }
    libdirs { "build/%{cfg.buildcfg}" }
    includedirs { "../source", "../source/FrameLog" }

    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

--==========================================
-- Configs
--==========================================

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
            "-fno-rtti",
            "-fno-exceptions",
            "-fvisibility=hidden",
            "-flto",               
            "-s",
        }

    filter {}

--==========================================
-- File Example
--==========================================
project "FileExample"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "../build/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    files { "FileExample.cpp" }

    links { "FrameLog" }
    libdirs { "build/%{cfg.buildcfg}" }
    includedirs { "../source", "../source/FrameLog" }

    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

--==========================================
-- Configs
--==========================================

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
            "-fno-rtti",
            "-fno-exceptions",
            "-fvisibility=hidden",
            "-flto",               
            "-s",
        }

    filter {}

--==========================================
-- Hello, FrameLog!
--==========================================
project "HelloFrameLog"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "../build/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    files { "HelloFrameLog.cpp" }

    links { "FrameLog" }
    libdirs { "../build/%{cfg.buildcfg}" }
    includedirs { "../source", "../source/FrameLog" }

    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

--==========================================
-- Configs
--==========================================

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
            "-fno-rtti",
            "-fno-exceptions",
            "-fvisibility=hidden",
            "-flto",               
            "-s",
        }

    filter {}