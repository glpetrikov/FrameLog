# **FrameLog — Logger API**

The `FrameLog::Logger` class provides a lightweight, efficient, color-aware logging system with support for formatting
patterns, log levels, file output, and stream-style logging.

---

## **Constructor**

```cpp
Logger(std::string_view loggerName, bool writeToFile = true);
```

Creates a logger with the given name.

* `loggerName` — Name of the logger (used in output and file name).
* `writeToFile` — If `true`, all log messages are also written to a file with the logger name.

No additional setup is required.

---

## **Log Levels**

```cpp
enum class LogLevel {
    Trace,
    Print,
    Info,
    Warn,
    Error,
    Fatal
};
```

Log levels represent message severity.
They are filtered using the **minimal log level** (see below).

| Level | Purpose                     |
|-------|-----------------------------|
| Trace | Debug / tracing information |
| Print | General output              |
| Info  | Informational messages      |
| Warn  | Warnings                    |
| Error | Errors                      |
| Fatal | Critical / fatal errors     |

---

## **Minimal Log Level**

```cpp
void SetMinimalLogLevel(LogLevel level);
```

Sets the minimal log level that will be printed.
Messages with a lower severity are ignored.

Example:

```cpp
logger.SetMinimalLogLevel(LogLevel::Warn);
```

---

## **Logging Functions**

Each function prints a message with a predefined color and severity.

| Function  | Description           |
|-----------|-----------------------|
| `Trace()` | Debug / trace output  |
| `Print()` | General output        |
| `Info()`  | Informational message |
| `Warn()`  | Warning               |
| `Error()` | Error                 |
| `Fatal()` | Fatal error           |

### **Line Variants**

Each logging function has a `Line` variant that automatically appends a newline:

```cpp
PrintLine()
TraceLine()
InfoLine()
WarnLine()
ErrorLine()
FatalLine()
```

Example:

```cpp
logger.InfoLine("Initialization completed");
```

---

## **Logger Name**

```cpp
void SetName(std::string_view newName);
```

Changes the logger name at runtime.

* Updates the name shown in console output
* Closes the current log file
* Creates a new log file using the new name

---

## **Pattern Formatting**

```cpp
void SetPattern(const std::string& pattern);
```

Sets a custom output format for all log messages.
Calling this function again replaces the previous pattern.

### **Default Pattern**

```text
%^[%D] [%T] %n:%$ %v
```

---

### **Pattern Specifiers**

#### Message & Logger

| Specifier | Description              |
|-----------|--------------------------|
| `%v`      | Log message              |
| `%n`      | Logger name              |
| `%l`      | Log level (full name)    |
| `%L`      | Log level (first letter) |

#### Time & Date

| Specifier | Description       |
|-----------|-------------------|
| `%T`      | Time (HH:MM:SS)   |
| `%H`      | Hour (24h)        |
| `%M`      | Minutes           |
| `%S`      | Seconds           |
| `%e`      | Milliseconds      |
| `%D`      | Date (YYYY.MM.DD) |
| `%F`      | Full datetime     |
| `%Y`      | Year              |
| `%m`      | Month             |
| `%d`      | Day               |

#### Process & Thread

| Specifier | Description |
|-----------|-------------|
| `%t`      | Thread ID   |
| `%P`      | Process ID  |

#### Color Control

| Specifier | Description                       |
|-----------|-----------------------------------|
| `%^`      | Enable color (based on log level) |
| `%$`      | Reset color                       |

#### Other

| Specifier | Description |
|-----------|-------------|
| `%%`      | Literal `%` |

---

## **Stream-Style Logging**

The logger supports `operator<<` chaining similar to `std::cout`.

```cpp
logger << "Hello, " << userName << logger.EndL();
```

### **Supported Types**

* `std::string`
* `const char*`
* `char`
* `int`
* `double`
* `bool`
* `Colors::Color`
* `Colors::BGColor`
* `Colors::Style`

Example with colors:

```cpp
logger << Colors::Color::Green
       << "[OK] "
       << "Connected"
       << logger.EndL();
```

---

## **EndL**

```cpp
char EndL();
```

Returns a newline character (`'\n'`).

Used to terminate stream-style logging chains.

---

## **Buffer Operations**

| Method                  | Description                        |
|-------------------------|------------------------------------|
| `Add(char)`             | Append a character to the buffer   |
| `Add(std::string_view)` | Append text to the buffer          |
| `Flush()`               | Print buffer contents and clear it |
| `Free()`                | Clear and release buffer memory    |
| `Read()`                | Read a line from standard input    |

---

## **File Operations**

```cpp
void FlushFile();
```

Flushes the log file associated with the logger.

---

## **Utility Formatting**

```cpp
template<typename... Args>
static std::string Format(std::format_string<Args...> fmt, Args&&... args);
```

Wrapper around `std::format` for convenience.

Example:

```cpp
logger.Info(FrameLog::Logger::Format(
    "Loaded {} resources in {} ms", count, time
));
```

---
