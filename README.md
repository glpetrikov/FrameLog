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
Copyright (c) 2025 Gleb Petrikov

## Supported Platforms

Any platform with the **standard C library** — basically **EVERYWHERE**!

## Status
**FrameLog** is in alpha stage

## Example

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.
#include <FrameLog.h>

int main(){

        FLTrace("HelloWorld!\n");    // Dark gray (graphite) color
        FLTraceln(" HelloWorld!");   // Dark gray with newline

    return 0;
}
```

## Author

**Gleb Petrikov**

## Roadmap

### Alpha (Current)
- Basic output functions
- Color support
- Basic log levels

### Beta
- Buffered output
- Additional log levels

### Release
- Custom format patterns
- Output pattern scanner
- Additional buffer capabilities
- File Log