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

        enum class Tokens {
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
#define FL_VERSION "1.8.0"
#define FL_STATUS " release"

#define FL_SIZE 75.0 // KB

#define FL_VERSION_MAJOR 1
#define FL_VERSION_MINOR 8
#define FL_VERSION_PATCH 0
}
