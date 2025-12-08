--============================================================
-- FrameLog - MIT License (c) 2025 Gleb Petrikov
--============================================================

project "FileHandler"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "../build/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    files { "FileHandler.cpp" }

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
-- FileHandler2
--==========================================

project "FileHandler2"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "build/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "FileHandler2.cpp" }

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