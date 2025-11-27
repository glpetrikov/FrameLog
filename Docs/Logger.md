### **FrameLog Logger API**

The `Logger` class provides a simple, efficient, and color-aware logging interface.

#### **Constructor**

```cpp
Logger(std::string name);
```

Creates a logger with the given name.
No additional setup is required.

---

#### **Log Levels**

```cpp
enum class LogLevel {
    Print,
    Trace,
    Info,
    Warn,
    Error,
    Fatal
};
```

These levels represent different message severities.
*(Currently, they are defined but not all are used internally.)*

---

#### **Logging Functions**

| Function  | Description                | Color          |
| --------- | -------------------------- | -------------- |
| `Print()` | General text output        | Default        |
| `Trace()` | Debug or trace information | Gray           |
| `Info()`  | Informational message      | Green          |
| `Warn()`  | Warning                    | Yellow         |
| `Error()` | Error message              | Red            |
| `Fatal()` | Critical error             | Red background |

Each of the above functions also has a variant ending with `Line`, which automatically appends a newline (`'\n'`):
`PrintLine()`, `TraceLine()`, `InfoLine()`, `WarnLine()`, `ErrorLine()`, `FatalLine()`.

---

#### **Custom Stream Output**

`Custom` enables stream-style logging similar to `std::cout`.
Example:

```cpp
logger.Custom << "Hello, " << user << "!" << logger.EndL();
```

You can chain strings, numbers, colors, and styles:

```cpp
logger.Custom << Colors::Color::Green
              << "[OK] "
              << "Connected"
              << logger.EndL();
```

---

#### **EndL**

```cpp
char EndL();
```

Returns a newline character (`'\n'`).
Used at the end of a custom log chain to mark a line break or trigger output.

---

#### **Buffer Operations**

| Method                  | Description                                   |
| ----------------------- | --------------------------------------------- |
| `Add(std::string)`      | Appends a string to the buffer                |
| `Add(std::string_view)` | Appends a string view                         |
| `Add(const char*)`      | Appends a C-string                            |
| `Add(char)`             | Appends a single character                    |
| `Flush()`               | Prints everything in the buffer and clears it |
| `Free()`                | Clears and releases all buffer memory         |

---
#### Patterns

SetPattern accepts a std::string with the output format. 
After calling it, all messages will have the new format. 
If you call it again, the format will be replaced with 
the new one.

| Specifier | Description                   | Example Output  |
| --------- | ----------------------------- | --------------- |
| `%v`      | Message (the log text itself) | `"Hello world"` |
| `%n`      | Logger name                   | `"Renderer"`    |
| `%l`      | Log level (full name)         | `"INFO"`        |
| `%L`      | Log level (first letter only) | `"I"`           |

| Specifier | Description       | Example Output |
| --------- | ----------------- | -------------- |
| `%T`      | Time (HH:MM:SS)   | `"09:30:45"`   |
| `%H`      | Hour (24h format) | `"09"`         |
| `%M`      | Minutes           | `"30"`         |
| `%S`      | Seconds           | `"45"`         |
| `%e`      | Milliseconds      | `"123"`        |

| Specifier | Description       | Example Output          |
| --------- | ----------------- | ----------------------- |
| `%D`      | Date (YYYY.MM.DD) | `"2025.11.27"`          |
| `%F`      | Full datetime     | `"2025.11.27 09:30:45"` |
| `%Y`      | Year (4 digits)   | `"2025"`                |
| `%m`      | Month (2 digits)  | `"11"`                  |
| `%d`      | Day (2 digits)    | `"27"`                  |

| Specifier | Description | Action                               |
| --------- | ----------- | ------------------------------------ |
| `%^`      | Color start | Enables color according to log level |
| `%$`      | Color end   | Resets ANSI color                    |

| Specifier | Description            | Example Output     |
| --------- | ---------------------- | ------------------ |
| `%t`      | Thread ID              | `"0x7f8a4c001700"` |
| `%P`      | Process ID             | `"12345"`          |
| `%%`      | Literal `%` (escaping) | `"%"`              |
