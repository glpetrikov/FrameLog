// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "common.h"
#include "buffer.h"

// =============================================================
// Standart Prints
void FLPrint(const char *Message)
{
    printf("%s%s%s", FL_BLUE, Message, FL_RESET);
}
void FLPrintln(const char *Message)
{
    printf("%s%s%s\n", FL_BLUE, Message, FL_RESET);
}
// =============================================================
// Trace Prints
void FLTrace(const char *Message)
{
    printf("%s%s%s", FL_GRAPHITE, Message, FL_RESET);
}
void FLTraceln(const char *Message)
{
    printf("%s%s%s\n", FL_GRAPHITE, Message, FL_RESET);
}
// =============================================================
// Info Prints
void FLInfo(const char *Message)
{
    printf("%s%s%s", FL_GREEN, Message, FL_RESET);
}
void FLInfoln(const char *Message)
{
    printf("%s%s%s\n", FL_GREEN, Message, FL_RESET);
}
// =============================================================
// Warn Prints
void FLWarn(const char *Message)
{
    printf("%s%s%s", FL_YELLOW, Message, FL_RESET);
}
void FLWarnln(const char *Message)
{
    printf("%s%s%s\n", FL_YELLOW, Message, FL_RESET);
}
// =============================================================
// Errors Prints
void FLError(const char *Message)
{
    printf("%s%s%s", FL_RED, Message, FL_RESET);
}
void FLErrorln(const char *Message)
{
    printf("%s%s%s\n", FL_RED, Message, FL_RESET);
}
