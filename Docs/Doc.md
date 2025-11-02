# **FrameLog**

### Lightweight • Buffered • Colorized • Cross-Platform

*(MIT License © 2025 — Gleb Petrikov)*

---

## **Overview**

**FrameLog** is a **fast, lightweight C++ logging library** with:

* **Buffered output** (efficient printing)
* **ANSI/TrueColor (RGB) support**
* **Custom stream-style logging** (`<<` syntax like `std::cout`)
* **File I/O helpers** (FileReader/FileWriter)
* **Cross-platform compatibility** (Windows, Linux, macOS, mobile)

No external dependencies. Just `#include <FrameLog.hpp>` and log.

---

## **Installation**

Include FrameLog in your project:

```cpp
#include <FrameLog.hpp>
using namespace FrameLog;
```

No build steps are required other than including headers. Optional macros for dynamic/shared builds:

* `FRAMELOG_BUILD` — marks the library for export/import
* `FL_API` — cross-platform API visibility

---

## **Logger API**

The main interface for logging messages.

### **Creating a Logger**

```cpp
auto log = Logger("Main");
```

or with type alias:

```cpp
auto log = NewLogger("Main");
```

`LoggerName` is optional but useful for distinguishing modules.

---

### **Log Levels**

| Method                 | Description        | Default Color   |
| ---------------------- | ------------------ | --------------- |
| `Print()` / `Printl()` | General output     | Bright Blue     |
| `Trace()` / `Tracel()` | Debug / Trace info | Gray            |
| `Info()` / `Infol()`   | Informational      | Green           |
| `Warn()` / `Warnl()`   | Warning            | Yellow          |
| `Error()` / `Errorl()` | Error              | Red             |
| `Fatal()` / `Fatall()` | Critical / Fatal   | White on Red BG |

**Note:** Methods ending with `l` append a newline automatically.

---

### **Basic Logging**

```cpp
log.Print("Hello");
log.Printl("Hello with newline");
log.Info("Status OK");
log.Warnl("Low memory");
log.Errorl("Error occurred");
log.Fatall("Fatal error");
```

Call `log.Flush()` to print all buffered logs.

---

### **Custom Stream Logging**

The `Custom` object supports chained logging using `<<`:

```cpp
log.Custom << Colors::Color::Green
           << "[OK] "
           << Colors::Style::Bold
           << "Operation complete"
           << log.EndL();
```

Supports:

* Strings (`std::string`, `const char*`)
* Numbers (`int`, `double`)
* Booleans
* Colors (`Colors::Color`)
* Background colors (`Colors::BGColor`)
* Text styles (`Colors::Style`)

---

### **EndL**

```cpp
char EndL();
```

Returns `'\n'`. Use at the end of a `Custom` log chain to insert a newline.

---

## **Buffer API**

`Logger` uses an internal `Buffer` class. Methods are exposed for manual control.

| Method                  | Description                     |
| ----------------------- | ------------------------------- |
| `Add(std::string)`      | Append string                   |
| `Add(std::string_view)` | Append string_view              |
| `Add(const char*)`      | Append C-string                 |
| `Add(char)`             | Append single character         |
| `Flush()`               | Print buffer contents and clear |
| `Free()`                | Clear buffer without printing   |

**Example:**

```cpp
log.Add("Buffered text ");
log.Add("more text");
log.Flush();
```

---

## **Colors API**

### Predefined Colors

```cpp
FrameLog::Colors::Color::Red
FrameLog::Colors::Color::Green
FrameLog::Colors::Color::BrightBlue
```

### Background Colors

```cpp
FrameLog::Colors::BGColor::RedB
FrameLog::Colors::BGColor::BlueB
```

### Text Styles

```cpp
FrameLog::Colors::Style::Bold
FrameLog::Colors::Style::Italic
FrameLog::Colors::Style::Underline
FrameLog::Colors::Style::Reset
```

### TrueColor (RGB)

```cpp
log.Custom << Colors::RGB(255,100,50)
           << "Custom RGB Text"
           << Colors::Style::Reset;
```

---

## **FileReader API**

Read files easily:

```cpp
FileReader reader("config.txt");

// Get a specific line
std::string line = reader.FindLine(3);

// Read full file
std::string content = reader.ReadFile();

// Open another file
reader.OpenFile("other.txt");
```

---

## **FileWriter API**

Write logs to files:

```cpp
FileWriter writer("log.txt", TypeWrite::Write);

// Write a line
writer.WriteLine("Log entry");

// Flush and close
writer.Flush();
writer.CloseFile();

// Delete file
writer.DeleteFile();
```

`TypeWrite` options:

* `ReWrite` — overwrite file
* `Write` — append to file

---

## **Input API**

```cpp
std::string userInput = log.Read();
```

Reads input from `std::cin`.

---

## **Platform Compatibility**

| Platform    | Supported | Notes                                         |
| ----------- | --------- | --------------------------------------------- |
| Windows 10+ | ✅         | PowerShell 7+ or Windows Terminal recommended |
| Linux       | ✅         | Full ANSI support                             |
| macOS       | ✅         | Terminal.app / iTerm2                         |
| Android/iOS | ⚙️        | Colors disabled                               |

---

## **Full Example**

```cpp
#include <FrameLog.hpp>
using namespace FrameLog;

int main() {
    auto log = Logger("App");

    log.Infol("App started");
    log.Warnl("Using default configuration");

    log.Custom << Colors::Color::Cyan
               << "Custom styled message "
               << Colors::Style::Bold
               << "(highlighted)"
               << Colors::Style::Reset;

    log.Flush();
}
```

---

## **Version Info**

| Macro        | Value     |
| ------------ | --------- |
| `FL_VERSION` | `"1.3.1"` |
| `FL_STATUS`  | `"beta"`  |

---

## **Notes**

* Always call **`Flush()`** to print buffered logs.
* **`Free()`** clears the buffer without printing.
* Multiple loggers can coexist.
* Ideal for **games**, **CLI tools**, or **embedded systems**.
* Minimal binary size (~46 KiB).