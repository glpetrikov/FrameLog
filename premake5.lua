--============================================================
-- FrameLog - MIT License (c) 2025 Gleb Petrikov
--============================================================

workspace "FrameLog"
   architecture "x64"
   configurations { "Debug", "Release" }

   location "build"

project "FrameLog"
    kind "SharedLib"
    language "C"
    cdialect "C99"

    targetdir "build/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "source/**.c", "source/**.h" }

    includedirs { "source/", "source/FrameLog/" }

    
    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

--==========================================
-- Operation System
--==========================================

    -- Windows
    filter { "system:windows", "kind:SharedLib" }
        targetextension ".dll"
        linkoptions { "-Wl,--out-implib,lib%{prj.name}.a" }


--==========================================
-- Compilers
--==========================================


-- === MSVC ======


    filter "action:vs*"
        buildoptions { "/W4", "/std=c99" }


-- === Clang / GCC ======


    filter { "toolset:gcc or toolset:clang" }
        buildoptions {
            "-fstack-protector-strong",
            "-D_FORTIFY_SOURCE=2",
            "-fno-strict-aliasing",
            "-fno-omit-frame-pointer",
            "-std=c99",
        }


-- === GCC ======


    filter "toolset:gcc"
        buildoptions { "-Wall" }


-- === CLang ======


    filter "toolset:clang"
         buildoptions {
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-Wshadow",
            "-Wconversion",
            "-Wunreachable-code",
            "-Werror=format-security",
            "-fcolor-diagnostics",
        }
        linkoptions { "-fuse-ld=lld" }

--==========================================
-- Configs
--==========================================

    filter "configurations:Debug"
        defines { "DEBUG", "FL_ENABLE_LOGS=1", "FRAMELOG_BUILD" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG", "FL_ENABLE_LOGS=0", "FRAMELOG_BUILD" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
        }

    filter {}

--==========================================
-- Sandbox
--==========================================

project "sandbox"
    kind "ConsoleApp"
    language "C"
    cdialect "C99"

    targetdir "build/%{cfg.buildcfg}"
    objdir "build/obj/%{cfg.buildcfg}"

    files { "examples/**.c", "examples/**.h" }

    links { "FrameLog" }
    libdirs { "build/%{cfg.buildcfg}" }
    includedirs { "source", "source/FrameLog" }

    
    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

--==========================================
-- Operation System
--==========================================

    -- Windows
    filter { "system:windows", "kind:SharedLib" }
        targetextension ".dll"
        linkoptions { "-Wl,--out-implib,lib%{prj.name}.a" }


--==========================================
-- Compilers
--==========================================


-- === MSVC ======


    filter "action:vs*"
        buildoptions { "/W4", "/std=c99" }


-- === Clang / GCC ======


    filter { "toolset:gcc or toolset:clang" }
        buildoptions {
            "-fstack-protector-strong",
            "-D_FORTIFY_SOURCE=2",
            "-fno-strict-aliasing",
            "-fno-omit-frame-pointer",
            "-std=c99",
        }


-- === GCC ======


    filter "toolset:gcc"
        buildoptions { "-Wall" }


-- === CLang ======


    filter "toolset:clang"
         buildoptions {
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            "-Wshadow",
            "-Wconversion",
            "-Wunreachable-code",
            "-Werror=format-security",
            "-fcolor-diagnostics",
        }
        linkoptions { "-fuse-ld=lld" }

--==========================================
-- Configs
--==========================================

    filter "configurations:Debug"
        defines { "DEBUG", "FL_ENABLE_LOGS=1", "FRAMELOG_BUILD" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG", "FL_ENABLE_LOGS=0", "FRAMELOG_BUILD" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
        }

    filter {}