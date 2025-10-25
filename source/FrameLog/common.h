// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Colors.h"
#include <stdbool.h> // bool, true, false

#ifndef FL_ENABLE_LOGS
#warning "FL_ENABLE_ERROR_LOGS not defined! Errors will be suppressed!"
#warning "FL_ENABLE_ERROR_LOGS will be defined as 0 (true), but in future builds, set the flag"
#define FL_ENABLE_LOGS 0
#endif
