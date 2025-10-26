//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

// Reset
#define FL_RESET "\033[0m"

// Text Styles
#define FL_BLINK "\033[5m"
#define FL_REVERSE "\033[7m"

#define FL_BOLD "\033[1m"
#define FL_DIM "\033[2m"
#define FL_ITALIC "\033[3m"
#define FL_UNDERLINE "\033[4m"

// True Color Support (24-bit)
#define FL_RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
#define FL_RGB_BG(r, g, b) "\033[48;2;" #r ";" #g ";" #b "m"

// Gray-scale Colors
#define FL_BLACK "\033[30m"
#define FL_GRAPHITE "\033[90m"
#define FL_WHITE "\033[37m"

// Standart Colors
#define FL_RED "\033[31m"
#define FL_GREEN "\033[32m"
#define FL_YELLOW "\033[33m"
#define FL_BLUE "\033[34m"
#define FL_BRIGHT_BLUE "\033[94m"

// BackGround Colors
#define FL_BLACKB "\033[40m"
#define FL_REDB "\033[41m"
#define FL_GREENB "\033[42m"
#define FL_YELLOWB "\033[43m"
#define FL_BLUEB "\033[44m"
#define FL_WHITEB "\033[47m"
