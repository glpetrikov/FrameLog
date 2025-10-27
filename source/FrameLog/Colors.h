//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "common.h"
#include "Platform.h"

// Reset
FL_API extern const char *FL_RESET;

// Text Styles
FL_API extern const char *FL_BLINK;
FL_API extern const char *FL_REVERSE;
FL_API extern const char *FL_BOLD;
FL_API extern const char *FL_DIM;
FL_API extern const char *FL_ITALIC;
FL_API extern const char *FL_UNDERLINE;

// True Color Support (24-bit)
FL_API const char* FL_RGB(int r, int g, int b);
FL_API const char* FL_RGB_BG(int r, int g, int b);

// Gray-scale Colors
FL_API extern const char *FL_BLACK;
FL_API extern const char *FL_GRAPHITE;
FL_API extern const char *FL_WHITE;

// Standard Colors
FL_API extern const char *FL_RED;
FL_API extern const char *FL_GREEN;
FL_API extern const char *FL_YELLOW;
FL_API extern const char *FL_BLUE;
FL_API extern const char *FL_BRIGHT_BLUE;

// Background Colors
FL_API extern const char *FL_BLACKB;
FL_API extern const char *FL_REDB;
FL_API extern const char *FL_GREENB;
FL_API extern const char *FL_YELLOWB;
FL_API extern const char *FL_BLUEB;
FL_API extern const char *FL_WHITEB;
