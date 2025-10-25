// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "common.h"
#include "buffer.h"

void FLPrintColored(const char *Message, const char *Color, const char *BackgroundColor, bool Newline)
{
    if (Message == NULL)
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Print Error: message is NULL", FL_RESET);
        }
        return;
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
    FLPrintColored(Message, FL_BRIGHT_BLUE, NULL, false);
}
void FLPrintln(const char *Message)
{
    FLPrintColored(Message, FL_BRIGHT_BLUE, NULL, true);
}
// =============================================================
// Trace Prints
void FLTrace(const char *Message)
{
    FLPrintColored(Message, FL_GRAPHITE, NULL, false);
}
void FLTraceln(const char *Message)
{
    FLPrintColored(Message, FL_GRAPHITE, NULL, true);
}
// =============================================================
// Info Prints
void FLInfo(const char *Message)
{
    FLPrintColored(Message, FL_GREEN, NULL, false);
}
void FLInfoln(const char *Message)
{
    FLPrintColored(Message, FL_GREEN, NULL, true);
}
// =============================================================
// Warn Prints
void FLWarn(const char *Message)
{
    FLPrintColored(Message, FL_YELLOW, NULL, false);
}
void FLWarnln(const char *Message)
{
    FLPrintColored(Message, FL_YELLOW, NULL, true);
}
// =============================================================
// Errors Prints
void FLError(const char *Message)
{
    FLPrintColored(Message, FL_RED, NULL, false);
}
void FLErrorln(const char *Message)
{
    FLPrintColored(Message, FL_RED, NULL, true);
}
