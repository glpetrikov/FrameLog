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
    printf("%s%zu\n", "Buffer Size: ", sizeof(Buffer));

    // New line
    FLNewLine();
    // Flush the buffer to output
    FLFlushBuffer();

    // Test FrameLog Errors (intentional NULL tests for robustness)
    FLPrint(NULL);
    FLPrintln(NULL);
    FLTraceln(NULL);
    FLInfoln(NULL);
    FLWarnln(NULL);
    FLErrorln(NULL);
    FLTrace(NULL);
    FLPrintln("long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long long… in short, a very long message");
    printf("%s%zu\n", "Buffer Size: ", sizeof(Buffer));

    //===============================================================
    // low-level API
    //===============================================================
    FLPrintColored(NULL, FL_GREEN, "Colored output using FrameLog!", true);
    // 1. Color
    // 2. Message
    // 3. New line or not

    FLAddInBuffer("This is a custom buffered message.\n");
    // Add message to buffer
    FLAddInBuffer(FL_BLACK);
    FLAddInBuffer("here's a custom black one and it hit the buffer!\n");
    FLAddInBuffer(FL_RESET); // without it, everything will be in the selected color, which is unpleasant

    FLAddInBuffer(NULL); // Test
    printf("%s%zu\n", "Buffer Size: ", sizeof(Buffer));

    FLFlushBuffer();
    // Flush the buffer to output

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog!", FL_RESET);
    return 0;
}