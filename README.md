# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

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

## Example
### Source files:
[Colors](source/FrameLog/Colors.h)

[Prints.c](source/FrameLog/Prints.c)

[Prints.h](source/FrameLog/Prints.h)

### example code:

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Include FrameLog in your code and use it:
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

    // New line example
    FLNewLine();

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
- Base Custom format patterns
- Base Output pattern scanner

### Beta
**in the coming month(as of 2025, October 21)**
- Buffered output
- Additional log levels

### Release
**in the coming months (3-4)(as of 2025, October 21)**
- full-fledged Custom format patterns
- full-fledged Output pattern scanner
- Additional buffer capabilities
- File Log