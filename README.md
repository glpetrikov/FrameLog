# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C**.

## Version 0.1.4-alpha

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

Verified cross-platform:
- Linux (GCC / Clang)
- Windows (MinGW / MSVC)(tested since version 0.1.3)

## Performance & Size

FrameLog is **extremely lightweight**:
```
Binary Size (with example) and SO files are marked 'SO':
┌─────────────┬──────────────┬────────────┐
│ Library     │ Size         │ Comparison │
├─────────────┼──────────────┼────────────┤
│ FrameLog    │ 14.6 KiB(SO) │ 1x         │
│ log.c       │ ~50 KB       │ 3.4x       │
│ zlog        │ ~2 MB        │ 140x       │
│ spdlog      │ 41 MB(source)│ 2,877x     │
│ Boost.Log   │ 60+ MB       │ 4,210x+    │
└─────────────┴──────────────┴────────────┘
Binary sizes measured with example build (Release, x64, GCC)
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

## Quick Start
```bash
git clone https://github.com/glpetrikov/FrameLog
cd FrameLog && premake5 gmake2 && cd build && make config=release
cd Release && ./sandbox
```

## Building

> [!WARNING]  
> **CRITICAL:** You MUST define `-DFL_ENABLE_LOGS` flag when compiling!  
> Without it, FrameLog will output internal debug messages in all configurations.
>
> - **Debug builds:** `-DFL_ENABLE_LOGS=1` (shows internal logs)  
> - **Release builds:** `-DFL_ENABLE_LOGS=0` (suppresses internal logs)

### Windows

#### GCC
``` bash
cd examples

# Debug (replace C/path/to/FrameLog with your installation path)
gcc -o example example.c -IC/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=1

# Release (replace C/path/to/FrameLog with your installation path)
gcc -o example example.c -IC/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=0

./example.exe
```

#### premake(recommended)
``` bash
premake5 gmake2
cd build/
mingw32-make config=debug && mingw32-make config=release
cd Debug/
./sandbox.exe
cd ..
cd Release/
./sandbox.exe
```

### Linux

#### GCC
``` bash
cd examples

# Debug (replace /path/to/FrameLog with your installation path)
gcc -o example example.c -I/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=1

# Release (replace /path/to/FrameLog with your installation path)
gcc -o example example.c -I/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=0

./example
```

#### premake(recommended)
``` bash
premake5 gmake2
cd build/
make config=debug && make config=release
cd Debug/
./sandbox
cd ..
cd Release/
./sandbox
```

## Example
### Source files:
[Colors](source/FrameLog/Colors.h)

[Prints.c](source/FrameLog/Prints.c)

[Prints.h](source/FrameLog/Prints.h)

### example code:

1. Include FrameLog in your code and use it:
``` c
// C and C++, no difference.
#include <FrameLog.h>

int main(){
    FLPrintln("Hello, World!");

    for(int i = 0; i < 10; i++){
        FLTraceln("output in loop!");
    }
    FLFlushBuffer();
}
```
More examples can be found in the examples folder.
2. build
See the "Building" section above.

## Authors

**Gleb Petrikov**

## Roadmap

### Alpha (Current)
- Buffered output
- Basic output functions
- Color support
- Basic log levels

### Beta (Target: Q1 2026)
- Additional log levels
- Base Custom format patterns
- Base Output pattern scanner
- Minimal File Log

### Release (Target: Q2-Q3 2026) 
- full-fledged Custom format patterns
- full-fledged Output pattern scanner
- Additional buffer capabilities
- File Log