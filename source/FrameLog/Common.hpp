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
#define FRAMELOG_API FL_API

#define FL_VERSION "1.5.1"
#define FL_STATUS "beta"

#define FL_SIZE 42.8 // KB

#define FL_VERSION_MAJOR 1
#define FL_VERSION_MINOR 5
#define FL_VERSION_PATCH 1
}
