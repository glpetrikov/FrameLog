//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "common.h"
#include "Buffer.h"

FL_API int FLPrintColored(const char *Message, const char *Color, const char *BackgroundColor, bool Newline)
{
    if (Message == NULL)
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Print Error: message is NULL", FL_RESET);
        }
        return -1;
    }

    // Colors
    if (BackgroundColor != NULL)
    {
        FLAddInBuffer(BackgroundColor);
    }
    if (Color != NULL)
    {
        FLAddInBuffer(Color);
    }

    // Message
    FLAddInBuffer(Message);

    // Reset and NewLine
    if (Color != NULL && BackgroundColor != NULL)
    {
        FLAddInBuffer(FL_RESET);
    }
    if (Newline)
    {
        FLAddInBuffer("\n");
    }
    return 0;
}
// =============================================================
// Standart Prints
// =============================================================
FL_API void FLPrint(const char *Message)
{
    FLPrintColored(Message, FL_BRIGHT_BLUE, NULL, false);
}
FL_API void FLPrintln(const char *Message)
{
    FLPrintColored(Message, FL_BRIGHT_BLUE, NULL, true);
}
// =============================================================
// Trace Prints
// =============================================================
FL_API void FLTrace(const char *Message)
{
    FLPrintColored(Message, FL_GRAPHITE, NULL, false);
}
FL_API void FLTraceln(const char *Message)
{
    FLPrintColored(Message, FL_GRAPHITE, NULL, true);
}
// =============================================================
// Info Prints
// =============================================================
FL_API void FLInfo(const char *Message)
{
    FLPrintColored(Message, FL_GREEN, NULL, false);
}
FL_API void FLInfoln(const char *Message)
{
    FLPrintColored(Message, FL_GREEN, NULL, true);
}
// =============================================================
// Warn Prints
// =============================================================
FL_API void FLWarn(const char *Message)
{
    FLPrintColored(Message, FL_YELLOW, NULL, false);
}
FL_API void FLWarnln(const char *Message)
{
    FLPrintColored(Message, FL_YELLOW, NULL, true);
}
// =============================================================
// Errors Prints
// =============================================================
FL_API void FLError(const char *Message)
{
    FLPrintColored(Message, FL_RED, NULL, false);
}
FL_API void FLErrorln(const char *Message)
{
    FLPrintColored(Message, FL_RED, NULL, true);
}
// =============================================================
// Tools
// =============================================================
FL_API void FLNewLine()
{
    FLAddInBuffer("\n");
}
