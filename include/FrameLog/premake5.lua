project "FrameLog"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir "../../../build/%{cfg.buildcfg}"
    objdir "../../../build/obj/%{cfg.buildcfg}"

    files { "../../source/**.cpp" }

    includedirs {  "../../include/" }

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
