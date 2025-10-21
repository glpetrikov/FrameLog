// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "common.h"
#include "buffer.h"

static void FLPrintColored(const char *color, const char *message, bool newline)
{
    printf("%s%s%s%s", color, message, FL_RESET, newline ? "\n" : "");
}
// =============================================================
// Standart Prints
void FLPrint(const char *Message)
{
    FLPrintColored(FL_BRIGHT_BLUE, Message, false);
}
void FLPrintln(const char *Message)
{
    FLPrintColored(FL_BRIGHT_BLUE, Message, true);
}
// =============================================================
// Trace Prints
void FLTrace(const char *Message)
{
    FLPrintColored(FL_GRAPHITE, Message, false);
}
void FLTraceln(const char *Message)
{
    FLPrintColored(FL_GRAPHITE, Message, true);
}
// =============================================================
// Info Prints
void FLInfo(const char *Message)
{
    FLPrintColored(FL_GREEN, Message, false);
}
void FLInfoln(const char *Message)
{
    FLPrintColored(FL_GREEN, Message, true);
}
// =============================================================
// Warn Prints
void FLWarn(const char *Message)
{
    FLPrintColored(FL_YELLOW, Message, false);
}
void FLWarnln(const char *Message)
{
    FLPrintColored(FL_YELLOW, Message, true);
}
// =============================================================
// Errors Prints
void FLError(const char *Message)
{
    FLPrintColored(FL_RED, Message, false);
}
void FLErrorln(const char *Message)
{
    FLPrintColored(FL_RED, Message, true);
}
