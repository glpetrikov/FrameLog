//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Colors.h"
#include <stdbool.h> // bool, true, false
#include "Platform.h"

typedef enum FLToken
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
} FLToken;

//============================================================
// Defines
//============================================================
#ifndef FL_ENABLE_LOGS
#warning "FL_ENABLE_LOGS not defined! Errors will be suppressed!"
#warning "FL_ENABLE_LOGS will be defined as 1 (true), but in future builds, set the flag"
#define FL_ENABLE_LOGS 1 // Default: enabled (for development)
#endif
