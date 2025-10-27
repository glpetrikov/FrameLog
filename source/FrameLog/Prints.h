//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "common.h"
#include "Buffer.h"

FL_API int FLPrintColored(const char *message, const char *color, const char *BackgroundColor, bool newline);
// =============================================================
// Standart Prints
// =============================================================
FL_API void FLPrint(const char *Message);
FL_API void FLPrintln(const char *Message);
// =============================================================
// Trace Prints
// =============================================================
FL_API void FLTrace(const char *Message);
FL_API void FLTraceln(const char *Message);
// =============================================================
// Info Prints
// =============================================================
FL_API void FLInfo(const char *Message);
FL_API void FLInfoln(const char *Message);
// =============================================================
// Warn Prints
// =============================================================
FL_API void FLWarn(const char *Message);
FL_API void FLWarnln(const char *Message);
// =============================================================
// Errors Prints
// =============================================================
FL_API void FLError(const char *Message);
FL_API void FLErrorln(const char *Message);
// =============================================================
// Fatal Prints
// =============================================================
// void FLFatal(const char *Message);
// void FLFatalln(const char *Message);
// =============================================================
// Tools
// =============================================================
FL_API void FLNewLine();
