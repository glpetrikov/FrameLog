project "FrameLog"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir "../../../build/%{cfg.buildcfg}"
    objdir "../../../build/obj/%{cfg.buildcfg}"

    files { "../../source/**.cpp", "../../source/**.h", "../../source/**.hpp" }

    includedirs { "../../source/", "../../source/FrameLog/", "../../source/FrameLog/Files/", "../../include/FrameLog/" }

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
        buildoptions { "/W4", "-std=c++23" }

-- === Clang / GCC ======
    filter { "toolset:gcc or toolset:clang" }
        buildoptions {
            "-fstack-protector-strong",
            "-D_FORTIFY_SOURCE=2",
            "-fno-strict-aliasing",
            "-fno-omit-frame-pointer",
            "-std=c++23",
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
