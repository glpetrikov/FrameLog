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

    includedirs { ".", "FrameLog/" }

    
    warnings "Extra"
    symbols "On"
    floatingpoint "Strict"
    conformancemode "On"

        --
        -- MSVC
        --

    filter "action:vs*"
        buildoptions { "/W4" }

        --
        -- Clang / GCC
        --

    filter { "toolset:gcc or toolset:clang" }
        buildoptions {
            "-fstack-protector-strong",
            "-D_FORTIFY_SOURCE=2",
            "-fno-strict-aliasing",
            "-fno-omit-frame-pointer",
        }

        --
        -- GCC
        --

    filter "toolset:gcc"
        buildoptions { "-Wall" }

        --
        -- CLang
        --

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

        --
        -- Configs
        --

    filter "configurations:Debug"
        defines { "DEBUG", "FL_ENABLE_LOGS=1" }
        symbols "On"
        buildoptions {
            "-O0",
            "-g3",
        }

    filter "configurations:Release"
        defines { "NDEBUG", "FL_ENABLE_LOGS=0" }
        optimize "Speed"
        symbols "Off"
        buildoptions {
            "-march=native",
            "-O3",
        }

    filter {}