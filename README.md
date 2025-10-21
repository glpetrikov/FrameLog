# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-alpha-orange.svg)

## Features 

1. **Simple text and log output to the console**.

2. **Color support** (e.g., Graphite).

3. **Minimal dependencies—only** the **standard C library**.

## Dependencies

Standard C library

## License

**FrameLog** is licensed under the MIT License.
[License](LICENSE)

## Supported Platforms

Any platform with the **standard C library** — basically **EVERYWHERE**!

## Status
**FrameLog** is in alpha stage

## Example
[Colors](source/FrameLog/Colors.h)

[Prints.c](source/FrameLog/Prints.c)

[Prints.h](source/FrameLog/Prints.h)

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.
// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include <stdio.h>
#include <FrameLog.h>

int main()
{
    // high-level API
    FLPrint("Hello, World!");
    FLPrintln("");
    FLPrintln("");
    FLTraceln("Hello, FrameLog!");
    FLInfoln("This is an info message.");
    FLWarnln("This is a warning message.");
    FLErrorln("This is an error message.");
    FLTrace("This is a trace message.\n");

    // low-level API
    FLPrintColored(FL_GREEN, "Colored output using FrameLog!", true);
    // 1. Color
    // 2. Message
    // 3. New line or not

    printf("%s%s%s\n", FL_GREEN, "Colored output using FrameLog!", FL_RESET);
    return 0;
}
```

## Developers

**Gleb Petrikov**

## Roadmap

### Alpha (Current)
- Basic output functions
- Color support
- Basic log levels

### Beta 
in the coming month(as of 2025Y.10M.21D)
- Buffered output
- Additional log levels

### Release
in the coming months (4-5)(as of 2025Y.10M.21D)
- Custom format patterns
- Output pattern scanner
- Additional buffer capabilities
- File Log