# FrameLog Documentation

## API Overview

### Log Levels
```c
FLTraceln("Detailed trace");      // Trace level (gray)
FLInfoln("Information");          // Info (cyan)
FLWarnln("Warning message");      // Warning (yellow)
FLErrorln("Error occurred!");     // Error (red)
```

### Basic Output
```c
FLPrint("text");        // Print without newline
FLPrintln("text");      // Print with newline
FLNewLine();            // Add blank line
```

### Buffer Control
```c
FLFlushBuffer();        // Output all buffered logs (REQUIRED!)
FLClearBuffer();        // Clear buffer without output
FLBufferSize();         // Display current buffer usage
```

### Advanced API
```c
// Custom colored output
FLPrintColored("Success!", FL_GREEN, NULL, true);
//             message     fg_color   bg_color  add_newline?

// Manual buffer manipulation
FLAddInBuffer("custom text\n");
FLAddInBuffer(FL_CYAN);      // Add color code to buffer
FLAddInBuffer("colored\n");
FLAddInBuffer(FL_RESET);     // Reset color (important!)
```

---

## Format Tokens (Planned for Beta)
```
Pattern tokens for custom log formatting:

| Token      | Output   | Description            |
|------------|----------|------------------------|
| `#y2`      | 25       | Two-digit year         |
| `#y4`      | 2025     | Four-digit year        |
| `#m`       | 10       | Month (01-12)          |
| `#d`       | 20       | Day (01-31)            |
| `#h12`     | 04       | Hour 12-format (01-12) |
| `#h24`     | 16       | Hour 24-format (00-23) |
| `#M`       | 05       | Minutes (00-59)        |
| `#s`       | 01       | Seconds (00-59)        |
| `#ms`      | 123      | Milliseconds (000-999) |
| `#message` | User text| Log message content    |

```

**Example usage (Beta):**
```c
// Coming in Beta release
FLSetFormat("[#y4-#m-#d #h24:#M:#s] #message");
FLInfoln("Server started");
// Output: [2025-10-28 16:05:01] Server started
```

---

## Color Codes

### Foreground Colors

#### Grayscale
```c
FL_BLACK    = "\033[30m"   // Black text
FL_GRAPHITE = "\033[90m"   // Gray text (bright black)
FL_WHITE    = "\033[37m"   // White text
```

#### Standard Colors
```c
FL_RED      = "\033[31m"   // Red text
FL_GREEN    = "\033[32m"   // Green text
FL_YELLOW   = "\033[33m"   // Yellow text
FL_BLUE     = "\033[34m"   // Blue text
FL_MAGENTA  = "\033[35m"   // Magenta text (if available)
FL_CYAN     = "\033[36m"   // Cyan text (if available)
```

#### Special
```c
FL_RESET    = "\033[0m"    // Reset all formatting (ALWAYS use after colors!)
```

### Background Colors
```c
FL_BLACKB   = "\033[40m"   // Black background
FL_REDB     = "\033[41m"   // Red background
FL_GREENB   = "\033[42m"   // Green background
FL_YELLOWB  = "\033[43m"   // Yellow background
FL_BLUEB    = "\033[44m"   // Blue background
FL_WHITEB   = "\033[47m"   // White background
```

### Color Usage Examples
```c
// Simple colored text
FLPrint(FL_GREEN);
FLPrint("Success!");
FLPrint(FL_RESET);  // Always reset!
FLNewLine();

// Using FLPrintColored (recommended)
FLPrintColored("Warning!", FL_YELLOW, NULL, true);

// Foreground + Background
FLPrintColored("Error!", FL_WHITE, FL_REDB, true);

// Manual buffer with colors
FLAddInBuffer(FL_CYAN);
FLAddInBuffer("Cyan text\n");
FLAddInBuffer(FL_RESET);
FLFlushBuffer();
```

---

## Important Notes

### Always Flush the Buffer!
FrameLog uses buffered output for performance. **You must call `FLFlushBuffer()` to see output!**

```c
FLInfoln("This won't show yet...");
FLWarnln("This too...");
FLFlushBuffer();  // NOW it appears!
```

### Always Reset Colors!
After using colors, **always use `FL_RESET`** to avoid color leaking to other output:

```c
// BAD - color leaks to rest of terminal
FLPrint(FL_RED);
FLPrint("Error\n");

// GOOD - color is contained
FLPrint(FL_RED);
FLPrint("Error");
FLPrint(FL_RESET);
FLPrint("\n");

// BEST - use FLPrintColored
FLPrintColored("Error", FL_RED, NULL, true);
```

### NULL Safety
All FrameLog functions handle NULL inputs gracefully:

```c
FLPrint(NULL);      // Outputs error, doesn't crash
FLPrintln(NULL);    // Safe
FLTraceln(NULL);    // Safe
```

---

## Platform-Specific Notes

### Windows
- Colors work in **Windows 10+** with modern terminal (Windows Terminal, PowerShell 7+)
- Legacy `cmd.exe` may not support colors
- ANSI escape codes enabled by default on Windows 10 1511+

### Linux/macOS
- Colors work in all standard terminals
- Tested on: GNOME Terminal, Konsole, iTerm2, Terminal.app

### Embedded Systems
- Colors may not work on serial consoles
- Use `-DFL_ENABLE_LOGS=0` to suppress internal FrameLog messages
- Buffer size is configurable (see source/FrameLog/Buffer.h)

---

## Compilation Flags

### Required Flags
```bash
# Debug builds (shows FrameLog internal logs)
-DFL_ENABLE_LOGS=1

# Release builds (suppresses internal logs)
-DFL_ENABLE_LOGS=0
```

### Optional Flags
```bash
# Custom buffer size (default: 4096 bytes)
-DFL_BUFFER_SIZE=8192

# Disable colors entirely (for systems without ANSI support)
-DFL_DISABLE_COLORS=1
```

---

## API Reference

### Functions

#### `void FLPrint(const char* message)`
Print text without newline.

#### `void FLPrintln(const char* message)`
Print text with newline.

#### `void FLTraceln(const char* message)`
Print trace-level log (gray color).

#### `void FLInfoln(const char* message)`
Print info-level log (cyan color).

#### `void FLWarnln(const char* message)`
Print warning-level log (yellow color).

#### `void FLErrorln(const char* message)`
Print error-level log (red color).

#### `void FLNewLine(void)`
Print blank line.

#### `void FLFlushBuffer(void)`
Output all buffered logs to console. **Required to see output!**

#### `void FLClearBuffer(void)`
Clear buffer without output. Use when you want to discard buffered logs.

#### `void FLBufferSize(void)`
Display current buffer usage (for debugging).

#### `void FLPrintColored(const char* message, const char* fg, const char* bg, bool newline)`
Print colored text with optional background color.
- `message`: Text to print
- `fg`: Foreground color (e.g., `FL_GREEN`)
- `bg`: Background color (e.g., `FL_REDB`) or `NULL` for default
- `newline`: Add newline after text (`true`/`false`)

#### `void FLAddInBuffer(const char* text)`
Manually add text to buffer. Can be used to add color codes or custom text.

---

## Examples

### Simple Logging
```c
#include <FrameLog.h>

int main() {
    FLInfoln("Application started");
    FLWarnln("Low memory warning");
    FLErrorln("Connection failed");
    
    FLFlushBuffer();
    return 0;
}
```

### Loop Logging
```c
#include <FrameLog.h>

int main() {
    for (int i = 0; i < 100; i++) {
        FLTraceln("Processing item...");
    }
    
    FLFlushBuffer();  // Output all at once
    return 0;
}
```

### Custom Colors
```c
#include <FrameLog.h>

int main() {
    FLPrintColored("SUCCESS", FL_GREEN, NULL, true);
    FLPrintColored("CRITICAL", FL_WHITE, FL_REDB, true);
    
    FLFlushBuffer();
    return 0;
}
```

### Manual Buffer Control
```c
#include <FrameLog.h>

int main() {
    FLAddInBuffer("Custom log: ");
    FLAddInBuffer(FL_YELLOW);
    FLAddInBuffer("important data");
    FLAddInBuffer(FL_RESET);
    FLAddInBuffer("\n");
    
    FLFlushBuffer();
    return 0;
}
```

---

## Troubleshooting

### No output appears
**Solution:** Call `FLFlushBuffer()` after logging.

### Colors don't work on Windows
**Solution:** Use Windows Terminal or PowerShell 7+ instead of cmd.exe.

### Buffer overflow errors
**Solution:** Increase buffer size with `-DFL_BUFFER_SIZE=8192` or flush more frequently.

### Internal FrameLog errors in release build
**Solution:** Compile with `-DFL_ENABLE_LOGS=0` flag.

---

## License
FrameLog is distributed under the MIT License.

## Author
Gleb Petrikov