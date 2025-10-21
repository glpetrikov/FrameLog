// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include "common.h"
#include "buffer.h"

void FLPrintColored(const char *color, const char *message, bool newline);
// =============================================================
// Standart Prints
void FLPrint(const char *Message);
void FLPrintln(const char *Message);
// =============================================================
// Trace Prints
void FLTrace(const char *Message);
void FLTraceln(const char *Message);
// =============================================================
// Info Prints
void FLInfo(const char *Message);
void FLInfoln(const char *Message);
// =============================================================
// Warn Prints
void FLWarn(const char *Message);
void FLWarnln(const char *Message);
// =============================================================
// Errors Prints
void FLError(const char *Message);
void FLErrorln(const char *Message);
