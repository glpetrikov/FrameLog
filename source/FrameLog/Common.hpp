//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

// C++ Library
#include <iostream>
#include <string>

// Project Files
#include "Platform.hpp"
#include "Colors.hpp"

namespace FrameLog
{
#define FL_VERSION "1.0.0"
#define FL_STATUS "beta"

    namespace Patterns
    {

        enum class FLToken
        {
            FLTime,
            FLYear4,
            FLYear2,
            FLMonth,
            FLDay,
            FLHour24,
            FLHour12,
            FLMinute,
            FLSeconds,
            FLMilliSeconds,
            FLMessage,
            FLEnd,
            FLMessageType
        };
    }
}

//============================================================
// Defines
//============================================================
