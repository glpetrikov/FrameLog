// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include <stdio.h>
#include <FrameLog.h>

int main()
{
    FLPrint("Hello, World!");
    FLPrintln("");
    FLPrintln("");
    FLTraceln("Hello, FrameLog!");
    FLInfoln("This is an info message.");
    FLWarnln("This is a warning message.");
    FLErrorln("This is an error message.");
    FLTrace("This is a trace message.\n");

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog!", FL_RESET);
    return 0;
}