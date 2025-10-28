// FrameLog - MIT License (c) 2025 Gleb Petrikov
/*
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
    FLBufferSize();

    // New line
    FLNewLine();
    // Flush the buffer to output
    FLFlushBuffer();

    FLPrintln("long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long… in short, a very long message");
    FLBufferSize();

    //===============================================================
    // low-level API
    //===============================================================
    FLPrintColored("Colored output using FrameLog!", FL_GREEN, NULL, true);
    // 1. Message
    // 2.
    // 3. Color
    // 4. New line or not

    FLAddInBuffer("This is a custom buffered message.\n");
    // Add message to buffer
    FLAddInBuffer(FL_BLACK);
    FLAddInBuffer("here's a custom black one and it hit the buffer!\n");
    FLAddInBuffer(FL_RESET); // without it, everything will be in the selected color, which is unpleasant

    FLAddInBuffer(NULL); // Test
    FLBufferSize();

    FLFlushBuffer();
    // Flush the buffer to output

    FLPrint("...");
    FLFlushBuffer();

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog and libc!", FL_RESET);
    return 0;
}
*/
/*
#include <FrameLog.h>

int main(){
    //============================================================
    // Tests
    //============================================================

    // Test FrameLog Errors (intentional NULL tests for robustness)
    FLPrint(NULL);
    FLPrintln(NULL);
    FLTraceln(NULL);
    FLInfoln(NULL);
    FLWarnln(NULL);
    FLErrorln(NULL);
    FLTrace(NULL);

    FLFlushBuffer();
    FLClearBuffer();
    // Clear Buffer, The alternative is reset, but it deletes everything from the buffer and does not output
    // Error "FrameLog Buffer Error: Attempt to clear an empty/uninitialized buffer"
    // means that the buffer was freed or flush 2 or more times
    return 0;
}
*/
