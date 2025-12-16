# FrameLog

FrameLog is a lightweight library for outputting logs to the console and file in **C++**.

## Version 1.9.0-release

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-greeen.svg)

![Status](https://img.shields.io/badge/status-Release-lightgrey.svg)
[![Size](https://img.shields.io/badge/Size-75.0_KiB-blue.svg)]()
[![C++](https://img.shields.io/badge/C%2B%2B-17%2B-blue.svg)]()

\
![GitHub Repo stars](https://img.shields.io/github/stars/glpetrikov/FrameLog?style=social)
![GitHub forks](https://img.shields.io/github/forks/glpetrikov/FrameLog?style=social)
![GitHub issues](https://img.shields.io/github/issues/glpetrikov/FrameLog)

> [!WARNING]
> Lua in GitHub statistics is just a build system. Don't pay attention and don't think there's anything wrong with Lua.

## Features

- **Lightweight** - Only 79.1 KiB when compiled in Release mode
- **Buffered console output** - Efficient string accumulation before flush
- **File logging** - Simple file writer with append/overwrite modes
- **Stream API** - `logger.custom << "Message " << value << "\n";`
- **Color support** - ANSI colors + RGB (24-bit true color)
- **Simple API** - Trace, Print, Info, Warn, Error, Fatal levels
- **Cross-platform** - Linux, Windows, macOS
- **Minimal dependencies** - Only standard C++ library
- **Patterns** - output with the required data
  (for example, time, date, LogLevel)

## Dependencies

- Standard C++ library (`std`)
- Compatible with **C++17** and later

## Output Example:

![Color-Example](OutputExample.png)

## License

FrameLog is distributed under the **MIT License**.  
See [LICENSE](LICENSE) for details.

## Supported Platforms

Any platform with the **standard C++ library**

## Connect to your premake-file

add line:
include "FrameLog/include/FrameLog/premake5.lua"

## Performance & Size

FrameLog is **lightweight**:
Binary Size Comparison:

| Library       | Size (KiB) | vs FrameLog (×)         | Language | Notes                          |
|---------------|------------|-------------------------|----------|--------------------------------|
| FrameLog      | 79.1       | 1.0×                    | C++      | Buffered, colors, stream       |
| log.c         | 50.0       | 50.0 / 79.1 ≈ 0.63×     | C        | Minimal                        |
| easylogging++ | 150.0      | 150.0 / 79.1 ≈ 1.90×    | C++      | Header-only                    |
| plog          | 200.0      | 200.0 / 79.1 ≈ 2.53×    | C++      | Header-only                    |
| g3log         | 500.0      | 500.0 / 79.1 ≈ 6.32×    | C++      | Async, crash-safe              |
| NanoLog       | 800.0      | 800.0 / 79.1 ≈ 10.11×   | C++      | Ultra-fast                     |
| quill         | 1229.0     | 1229.0 / 79.1 ≈ 15.53×  | C++      | Low-latency                    |
| zlog          | 2048.0     | 2048.0 / 79.1 ≈ 25.88×  | C        | Config files                   |
| log4cplus     | 3072.0     | 3072.0 / 79.1 ≈ 38.83×  | C++      | Java log4j port                |
| log4cpp       | 4096.0     | 4096.0 / 79.1 ≈ 51.77×  | C++      | Apache project                 |
| glog          | 5120.0     | 5120.0 / 79.1 ≈ 64.73×  | C++      | Google logging                 |
| spdlog        | 41984.0    | 41984.0 / 79.1 ≈ 530.5× | C++      | Very Fast, fmt-based, patterns |
| Boost.Log     | 61440.0    | 61440.0 / 79.1 ≈ 776.6× | C++      | Full-featured                  |

*Measured FrameLog: Release builds, x64, premake5, gcc15, make*

*Source sizes shown for header-only libraries (marked "src")*

**Why so small?**

- Minimal dependencies (only std)

**Perfect for:**

- Docker containers (minimal images)
- Fast compilation times
- Quick program startup
- for projects where you just need a logger

## Status

**FrameLog** is currently in **Release** stage

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

#### premake

``` bash
premake5 vs2022
```

open visual studio(2022)

press f5

### Linux

#### premake

``` bash
./run.sh
```

## Example

### Source files:

[Colors](include/FrameLog/Colors.h)\
[Logger.cpp](source/Logger.cpp)\
[Logger.hpp](include/FrameLog/Logger.h)

### example code:

1. Include FrameLog in your code and use it:

``` cpp
#include <FrameLog/FrameLog.h>

using namespace FrameLog;

int main() {
    Logger logger("Main");

    logger.custom << "Hello, FrameLog" << FL_VERSION << "-" << FL_STATUS << logger.EndL();
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

### Beta (Completed)

- Additional log levels
- Base Custom format patterns
- Base Output pattern scanner
- File Log
- Minimal Log Level

### Release (Current)(Completed)

- full-fledged Custom format patterns
- full-fledged Output pattern scanner
- Additional buffer capabilities