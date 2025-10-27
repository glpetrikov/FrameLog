# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

## Version 0.1.3

![Platforms](https://img.shields.io/badge/platforms-cross--platform-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-alpha-orange.svg)


![GitHub issues](https://img.shields.io/github/issues/glpetrikov/FrameLog)

## Features 

1. **Simple** text and log output to the console.

2. **Color support** (e.g., Graphite).

3. **Minimal dependencies—only** the **standard C library**.

## Dependencies
- Standard C library (`libc`)  
- Compatible with **C99** and later 

## License
FrameLog is distributed under the **MIT License**.  
See [LICENSE](LICENSE) for details.

## Supported Platforms

Any platform with the **standard C library** — basically **EVERYWHERE**!

## Performance & Size

FrameLog is **extremely lightweight**:
```
Binary Size (with example):
┌─────────────┬──────────────┬────────────┐
│ Library     │ Size         │ Comparison │
├─────────────┼──────────────┼────────────┤
│ FrameLog    │ 31 KB        │ 1x         │
│ log.c       │ ~50 KB       │ 1.6x       │
│ zlog        │ ~2 MB        │ 65x        │
│ spdlog      │ 41 MB(source)│ 1,322x     │
│ Boost.Log   │ 60+ MB       │ 2,000x+    │
└─────────────┴──────────────┴────────────┘
```

**Why so small?**
- Pure C (no C++ templates)
- Minimal dependencies (only libc)
- No STL overhead
- Efficient buffer management

**Perfect for:**
- Embedded systems (Arduino, ESP32, STM32)
- Docker containers (minimal images)
- Fast compilation times
- Quick program startup
- for projects where you just need a logger

## Status
**FrameLog** is in alpha stage

## Run

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Add a flag to the build system

### Warning! Without this flag, there will be messages about FrameLog errors in any configuration!!

#### Enable internal FrameLog debug messages (for developers)
-DFL_ENABLE_LOGS=1
#### Disable internal logs for release builds
-DFL_ENABLE_LOGS=0

3. Build with GCC and premake:
- gcc
``` bash
# Debug
gcc -o example example.c -Ipath/to/FrameLog/source/ -DFL_ENABLE_LOGS=1

# Release
gcc -o example example.c -IC/Tools/FrameLog/source/ -DFL_ENABLE_LOGS=0
```
- premake - GCC
``` bash
mkdir build
premake5 <your System Build> example: gmake, vs2019, vs2022, xcode4
cd build

For example: 
mkdir build
premake5 gmake
cd build
# On Windows
mingw32-make

# On Linux/macOS
make config=debug
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

### Warning! Without this flag, there will be messages about FrameLog errors in any configuration!!
#### Enable internal FrameLog debug messages (for developers)
-DFL_ENABLE_LOGS=1
#### Disable internal logs for release builds
-DFL_ENABLE_LOGS=0

3. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.

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
```
``` cpp
#include <FrameLog.h>

int main(){
       // Test FrameLog Errors (intentional NULL tests for robustness)
      FL_API FLPrint(NULL);
      FL_API FLPrintln(NULL);
      FL_API FLTraceln(NULL);
      FL_API FLInfoln(NULL);
      FL_API FLWarnln(NULL);
      FL_API FLErrorln(NULL);
      FL_API FLTrace(NULL);

      FL_API FLFlushBuffer();
      FL_API FLClearBuffer();
      // Clear Buffer, The alternative is reset, but it deletes everything from the buffer and does not output
      // Error "FrameLog Buffer Error: Attempt to clear an empty/uninitialized buffer"
      // means that the buffer was freed or flush 2 or more times
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