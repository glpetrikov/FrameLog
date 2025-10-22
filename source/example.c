// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include <stdio.h>
#include <FrameLog.h>

int main()
{
    // high-level API
    FLPrint("Hello, World!");
    FLPrintln("");
    FLNewLine();
    FLTraceln("Hello, FrameLog!");
    FLInfoln("This is an info message.");
    FLWarnln("This is a warning message.");
    FLErrorln("This is an error message.");
    FLTrace("This is a trace message.\n");

    // New line
    FLNewLine();
    FLFlushBuffer();
    // Flush the buffer to output

    //===============================================================
    // low-level API
    //===============================================================
    FLPrintColored(FL_GREEN, "Colored output using FrameLog!", true);
    // 1. Color
    // 2. Message
    // 3. New line or not

    FLAddInBuffer("This is a custom buffered message.\n");
    // Add message to buffer
    FLAddInBuffer(FL_BLACK);
    FLAddInBuffer("here's a custom black one and it hit the buffer!\n");
    FLAddInBuffer(FL_RESET); // without it, everything will be in the selected color, which is unpleasant

    FLFlushBuffer();
    // Flush the buffer to output

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog!", FL_RESET);
    return 0;
}