// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "common.h"
#include "buffer.h"

void FLPrintColored(const char *BackGroundColor, const char *color, const char *message, bool newline)
{
    if (color == NULL || message == NULL)
    {
        if (FL_ENABLE_ERROR_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Print Error: color or message is NULL", FL_RESET);
        }
        return;
    }
    if (BackGroundColor != NULL)
    {
        FLAddInBuffer(BackGroundColor);
    }
    FLAddInBuffer(color);
    FLAddInBuffer(message);
    FLAddInBuffer(FL_RESET);
    if (newline)
    {
        FLAddInBuffer("\n");
    }
}
// =============================================================
void FLNewLine()
{
    FLAddInBuffer("\n");
}
// =============================================================
// Standart Prints
void FLPrint(const char *Message)
{
    FLPrintColored(NULL, FL_BRIGHT_BLUE, Message, false);
}
void FLPrintln(const char *Message)
{
    FLPrintColored(NULL, FL_BRIGHT_BLUE, Message, true);
}
// =============================================================
// Trace Prints
void FLTrace(const char *Message)
{
    FLPrintColored(NULL, FL_GRAPHITE, Message, false);
}
void FLTraceln(const char *Message)
{
    FLPrintColored(NULL, FL_GRAPHITE, Message, true);
}
// =============================================================
// Info Prints
void FLInfo(const char *Message)
{
    FLPrintColored(NULL, FL_GREEN, Message, false);
}
void FLInfoln(const char *Message)
{
    FLPrintColored(NULL, FL_GREEN, Message, true);
}
// =============================================================
// Warn Prints
void FLWarn(const char *Message)
{
    FLPrintColored(NULL, FL_YELLOW, Message, false);
}
void FLWarnln(const char *Message)
{
    FLPrintColored(NULL, FL_YELLOW, Message, true);
}
// =============================================================
// Errors Prints
void FLError(const char *Message)
{
    FLPrintColored(NULL, FL_RED, Message, false);
}
void FLErrorln(const char *Message)
{
    FLPrintColored(NULL, FL_RED, Message, true);
}
