# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## Dependencies

Standard C library

## License

**FrameLog** is licensed under the MIT License.
Copyright (c) 2025 Gleb Petrikov

## Supported Platforms


Any platform with the **standard C library** — basically **EVERYTHING**!

## Author

**Gleb Petrikov**

## Example

1. Add the path to FrameLog sources in your build system:  
   `path/to/FrameLog/source/`

2. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.
#include <FrameLog.h>

int main(){
    FLPrint("HelloWorld!"); // Graphite color
    FLPrintln(" HelloWorld!"); // Graphite color with newline
    return 0;
}
```
