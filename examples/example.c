// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include <stdio.h>
#include <FrameLog.h>

int main()
{
    // high-level API
    FL_API FLPrint("Hello, World!");
    FL_API FLPrintln("");
    FL_API FLNewLine();
    FL_API FLTraceln("Hello, FrameLog!");
    FL_API FLInfoln("This is an info message.");
    FL_API FLWarnln("This is a warning message.");
    FL_API FLErrorln("This is an error message.");
    FL_API FLTrace("This is a trace message.\n");
    FL_API FLBufferSize();

    // New line
    FL_API FLNewLine();
    // Flush the buffer to output
    FL_API FLFlushBuffer();

    FL_API FLPrintln("long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long… in short, a very long message");
    FL_API FLBufferSize();

    //===============================================================
    // low-level API
    //===============================================================
    FL_API FLPrintColored("Colored output using FrameLog!", FL_GREEN, NULL, true);
    // 1. Message
    // 2.
    // 3. Color
    // 4. New line or not

    FL_API FLAddInBuffer("This is a custom buffered message.\n");
    // Add message to buffer
    FL_API FLAddInBuffer(FL_BLACK);
    FL_API FLAddInBuffer("here's a custom black one and it hit the buffer!\n");
    FL_API FLAddInBuffer(FL_RESET); // without it, everything will be in the selected color, which is unpleasant

    FL_API FLAddInBuffer(NULL); // Test
    FL_API FLBufferSize();

    FL_API FLFlushBuffer();
    // Flush the buffer to output

    FL_API FLPrint("...");
    FL_API FLFlushBuffer();

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog and libc!", FL_RESET);
    return 0;
}
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
