//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

// C++ Library
#include <iostream>
#include <string>

// Project Files
#include "Colors.hpp"
#include "Platform.hpp"

namespace FrameLog {
    namespace Patterns {

        enum class FLToken {
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

//============================================================
// Defines
//============================================================
#define FL_VERSION "1.3.1"
#define FL_STATUS "beta"
}