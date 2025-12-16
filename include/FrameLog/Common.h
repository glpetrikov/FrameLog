//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

// C++ Library
#include <iostream>
#include <string>

// Project Files
#include "Colors.h"
#include "Platform.h"

namespace FrameLog
{

//============================================================
// Defines
//============================================================
#define FL_VERSION "1.9.0"
#define FL_STATUS " release"

#define FL_SIZE 75.0 // KB

#define FL_VERSION_MAJOR 1
#define FL_VERSION_MINOR 9
#define FL_VERSION_PATCH 0
} // namespace FrameLog

extern "C" {

typedef enum
{
	Success,
	Warning,
	Error,
} Result;
}
