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
// Fatal Prints
// =============================================================
FL_API void FLFatal(const char* Message)
{
    FLPrintColored(Message, NULL, FL_REDB, false);
}
FL_API void FLFatalln(const char* Message){
    FLPrintColored(Message, NULL, FL_REDB, true);
}
// =============================================================
// Readers
// =============================================================
FL_API int FLReadInt(const char *Message){
    int value = 0;
    printf("%s", Message);


    while (scanf("%d", &value) != 1) {
        printf("FL Input Error: Input not number\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return value;
}


FL_API float FLReadFloat(const char* Message){
    float value = 0;
    printf("%s", Message);


    while (scanf("%f", &value) != 1) {
        printf("FL Input Error: Input not number\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return value;
}


FL_API double FLReadDouble(const char* Message){
    double value = 0;
    printf("%s", Message);


    while (scanf("%lf", &value) != 1) {
        printf("FL Input Error: Input not number\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return value;
}


FL_API char FLReadChar(const char* Message) {
    char c = 0;
    printf("%s", Message);

    c = getchar();
    while (getchar() != '\n');
    return c;
}


FL_API const char* FLReadString(const char* Message) {
    static char buffer[2000];
    printf("%s", Message);


    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        return buffer;
    }
    return "";
}
// =============================================================
// Tools
// =============================================================
FL_API void FLNewLine()
{
    FLAddInBuffer("\n");
}