# FrameLog

FrameLog is a lightweight library for outputting logs to the console in **C++**.

## Version 1.0.0-beta

![Platforms](https://img.shields.io/badge/platforms-cross--platform-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-beta-orange.svg)


![GitHub issues](https://img.shields.io/github/issues/glpetrikov/FrameLog)

## Features 

- **Lightweight** - Only 26.6 KiB when compiled in Release mode (smallest C++ logger with colors!)
- **Buffered output** - Efficient string accumulation before flush
- **Stream API** - `logger.Custom << "Message " << value << "\n";`
- **Color support** - ANSI colors + RGB (24-bit true color)
- **Simple API** - Trace, Print, Info, Warn, Error, Fatal levels
- **Cross-platform** - Linux, Windows, macOS
- **Minimal dependencies** - Only standard C++ library

## Dependencies
- Standard C++ library (`std`)  
- Compatible with **C++17** and later (C++20 recommended)

## License
FrameLog is distributed under the **MIT License**.  
See [LICENSE](LICENSE) for details.

## Supported Platforms

Any platform with the **standard C++ library**

## Performance & Size

FrameLog is **lightweight**:
Binary Size Comparison:

| Library     | Size           | vs FrameLog   | Language | Notes                    |
|-------------|----------------|---------------|----------|--------------------------|
| FrameLog    | 26.6 KiB (SO)  | 1×            | C++      | Buffered, colors, stream |
| log.c       | ~50 KiB        | 1.9× bigger   | C        | Minimal                  |
| easylogging++| ~150 KiB      | 5.6× bigger   | C++      | Header-only              |
| plog        | ~200 KiB       | 7.5× bigger   | C++      | Header-only              |
| g3log       | ~500 KiB       | 18.8× bigger  | C++      | Async, crash-safe        |
| NanoLog     | ~800 KiB       | 30× bigger    | C++      | Ultra-fast               |
| quill       | ~1.2 MiB       | 45× bigger    | C++      | Low-latency              |
| zlog        | ~2 MiB         | 75× bigger    | C        | Config files             |
| log4cplus   | ~3 MiB         | 113× bigger   | C++      | Java log4j port          |
| log4cpp     | ~4 MiB         | 150× bigger   | C++      | Apache project           |
| glog        | ~5 MiB         | 188× bigger   | C++      | Google logging           |
| spdlog      | 41 MiB (src)   | 1,541× bigger | C++      | Fast, fmt-based          |
| Boost.Log   | 60+ MiB        | 2,256× bigger | C++      | Full-featured            |

*Measured: Release builds, x64, premake5, gcc15, make*
*Source sizes shown for header-only libraries (marked "src")*


**Why so small?**
- no C++ templates
- Minimal dependencies (only std)
- Efficient buffer management

**Perfect for:**
- Docker containers (minimal images)
- Fast compilation times
- Quick program startup
- for projects where you just need a logger

## Status
**FrameLog** is currently in **Beta** stage

## Quick Start
```bash
git clone https://github.com/glpetrikov/FrameLog
cd FrameLog && premake5 gmake2 && cd build && make config=release
cd Release && ./sandbox
```

## Building

> [!WARNING]  
> If there are bugs in FrameLog API calls, they will be displayed in ANY configuration

### Windows

#### GCC
``` bash
cd examples

# Debug (replace C/path/to/FrameLog with your installation path)
g++ -o example SimpleExample.cpp -IC/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=1

# Release (replace C/path/to/FrameLog with your installation path)
g++ -o example SimpleExample.cpp -IC/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=0

./example.exe
```

#### premake(recommended)
``` bash
premake5 vs2022    # Visual Studio 2022
premake5 gmake2    # make
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
g++ -o example SimpleExample.cpp -I/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=1

# Release (replace /path/to/FrameLog with your installation path)
g++ -o example SimpleExample.cpp -I/path/to/FrameLog/source/ -DFL_ENABLE_LOGS=0

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
[Colors](source/FrameLog/Colors.hpp)

[Logger.cpp](source/FrameLog/Logger.cpp)

[Logger.hpp](source/FrameLog/Logger.hpp)

### example code:

1. Include FrameLog in your code and use it:
``` cpp
#include <FrameLog.hpp>
using namespace FrameLog;
#include <iostream>

int main()
{
    Logger logger = NewLogger();
    logger.Tracel("Hello, World!");
    logger.Custom << "Hello World! " << 7534 << "\n";
    std::string rgb = Colors::RGB(100, 100, 100);
    logger.Custom << rgb << "Custom Color! " << "\n";
    logger.Flush();
}
```
More examples can be found in the examples folder.
2. build
See the "Building" section above.

## Authors

**Gleb Petrikov**

## Roadmap

### Alpha (Completed)
- Buffered output
- Basic output functions
- Color support
- Basic log levels

### Beta (Current)
- Additional log levels
- Base Custom format patterns
- Base Output pattern scanner
- Minimal File Log

### Release (Target: Q2-Q3 2026) 
- full-fledged Custom format patterns
- full-fledged Output pattern scanner
- Additional buffer capabilities
- File Log