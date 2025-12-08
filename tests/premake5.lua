--============================================================
-- FrameLog - MIT License (c) 2025 Gleb Petrikov
--============================================================

--==========================================
-- Full Test
--==========================================

project "FullTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "../build/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    files { "FullTest.cpp" }

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
            "-march=native",
            "-O3"
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