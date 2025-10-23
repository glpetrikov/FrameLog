# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

![Platforms](https://img.shields.io/badge/platforms-cross--platform-lightgrey.svg)

![Language](https://img.shields.io/badge/language-C-blue.svg)

![License](https://img.shields.io/badge/license-MIT-green.svg)

![Status](https://img.shields.io/badge/status-alpha-orange.svg)

## Features 

1. **Simple** text and log output to the console.

2. **Color support** (e.g., Graphite).

3. **Minimal dependencies—only** the **standard C library**.

## Dependencies

Standard C library(libc).

Compatible with C13 and later.

## License

**FrameLog** is licensed under the MIT License.
[See LICENSE for details](LICENSE)

## Supported Platforms

Any platform with the **standard C library** — basically **EVERYWHERE**!

## Status
**FrameLog** is in alpha stage

## Run

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Add a flag to the build system

### Warning! Without this flag, there will be NO messages about FrameLog errors in any configuration!!

- Debug FL_ENABLE_ERROR_LOGS=0      FrameLog Error Message = true
- Release FL_ENABLE_ERROR_LOGS=1    FrameLog Error Message = false

3. Build
- gcc
``` bash
gcc -o example example.c -Ipath/to/FrameLog/source/ -DFL_ENABLE_ERROR_LOGS=0

For example:
gcc -o example example.c -IC/Tools/FrameLog/source/ -DFL_ENABLE_ERROR_LOGS=0
```
- premake
``` bash
mkdir build
premake5 <your System Build>
cd build

For example: 
mkdir build
premake5 gmake
cd build
mingw32-make
```


## Example
### Source files:
[Colors](source/FrameLog/Colors.h)

[Prints.c](source/FrameLog/Prints.c)

[Prints.h](source/FrameLog/Prints.h)

### example code:

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`
2. Add a flag to the build system

#### Warning! Without this flag, there will be NO messages about FrameLog errors in any configuration!!
- Debug FL_ENABLE_ERROR_LOGS=0      FrameLog Error Message = true
- Release FL_ENABLE_ERROR_LOGS=1    FrameLog Error Message = false

3. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.

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
    // Flush the buffer to output
    FLFlushBuffer();


    // Test FrameLog Errors
    FLPrint(NULL);
    FLPrintln(NULL);
    FLTraceln(NULL);
    FLInfoln(NULL);
    FLWarnln(NULL);
    FLErrorln(NULL);
    FLTrace(NULL);

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
```

## Developers

**Gleb Petrikov**

## Roadmap

### Alpha (Current)
- Buffered output
- Basic output functions
- Color support
- Basic log levels

### Beta
**in the coming month(as of 2025, October 21)**
- Additional log levels
- Base Custom format patterns
- Base Output pattern scanner
- Minimal File Log

### Release
**in the coming months (3-4)(as of 2025, October 21)**
- full-fledged Custom format patterns
- full-fledged Output pattern scanner
- Additional buffer capabilities
- File Log