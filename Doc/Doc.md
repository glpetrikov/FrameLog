# FrameLog Documentation

## Overview

FrameLog is a lightweight C++ logging library providing colorized, buffered console output with multiple log levels, ANSI color control, and customizable formatting.

---

## Basic Usage

```cpp
#include <FrameLog.hpp>

int main() {
    auto log = FrameLog::NewLogger("Main");

    log.Printl("Hello FrameLog!");
    log.Infol("Initialization complete");
    log.Warnl("Low memory warning");
    log.Errorl("Something went wrong");
    log.Fatall("Critical error");

    log.Flush();
}
````

---

## Creating a Logger

```cpp
auto log = FrameLog::NewLogger("Network");
```

Creates a new logger instance with name `"Network"`.
`LoggerName` is optional but helps identify modules in complex projects.

---

## Log Levels

| Function               | Description              | Default Color           |
| ---------------------- | ------------------------ | ----------------------- |
| `Print()` / `Printl()` | General output           | Bright Blue             |
| `Trace()` / `Tracel()` | Detailed trace info      | Gray                    |
| `Info()` / `Infol()`   | Informational message    | Green                   |
| `Warn()` / `Warnl()`   | Warning message          | Yellow                  |
| `Error()` / `Errorl()` | Error message            | Red                     |
| `Fatal()` / `Fatall()` | Critical / Fatal message | White on Red background |

Methods ending with **l** automatically append a newline.
Call `Flush()` to output buffered logs.

---

## Buffer API

| Function                | Description                  |
| ----------------------- | ---------------------------- |
| `Add(std::string)`      | Add string to buffer         |
| `Add(std::string_view)` | Add string_view to buffer    |
| `Add(const char*)`      | Add C-string to buffer       |
| `Flush()`               | Output buffer to `std::cout` |
| `Free()`                | Clear buffer without output  |

### Example

```cpp
auto log = FrameLog::NewLogger("BufferTest");

log.Add("Custom buffer usage ");
log.Add("works fine!");
log.Flush();
```

---

## Custom Formatted Output

You can manually control color, background, and text style using `log.Custom`.

### Example

```cpp
auto log = FrameLog::NewLogger("Format");

log.Custom 
    << FrameLog::Colors::Color::Green
    << "Success: "
    << FrameLog::Colors::Style::Bold
    << "Operation Complete"
    << FrameLog::Colors::Style::Reset;

log.Flush();
```

---

## Colors API

### Enums

```cpp
FrameLog::Colors::Color::Red
FrameLog::Colors::BGColor::BlueB
FrameLog::Colors::Style::Bold
```

### Example: Mixed Formatting

```cpp
auto log = FrameLog::NewLogger("Colors");

log.Custom
    << FrameLog::Colors::Color::Yellow
    << FrameLog::Colors::Style::Bold
    << "[Warning] "
    << FrameLog::Colors::Style::Reset
    << "Disk space low";

log.Flush();
```

---

## Custom RGB Colors

```cpp
using namespace FrameLog::Colors;

auto log = FrameLog::NewLogger("RGB");

log.Custom << RGB(255, 100, 50)
           << "Custom RGB Text"
           << Style::Reset;

log.Flush();
```

---

## Input

```cpp
std::string name = log.Read();
```

Reads a input strings from standard input.

---

## Platform Compatibility

| Platform      | Supported  | Notes                                      |
| ------------- | ---------- | ------------------------------------------ |
| Windows 10+   | ✅         | Works in PowerShell 7+ or Windows Terminal |
| Linux         | ✅         | Works in all major terminals               |
| macOS         | ✅         | Tested on Terminal.app and iTerm2          |
| Android / iOS | ⚙️         | Basic output only, no color                |

---

## Full Example

```cpp
#include <FrameLog.hpp>
using namespace FrameLog;

int main() {
    auto log = NewLogger("App");

    log.Infol("App started");
    log.Warnl("Using default configuration");

    log.Custom
        << Colors::Color::Cyan
        << "Custom styled message "
        << Colors::Style::Bold
        << "(highlighted)"
        << Colors::Style::Reset;

    log.Flush();
}
```

---

## Notes

* Always call `Flush()` after printing to ensure buffered output is displayed.
* `Free()` clears the buffer without printing.
* Multiple loggers can exist simultaneously.
* Designed for real-time applications and small tools.

---

```
```