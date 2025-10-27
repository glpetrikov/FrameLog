//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "Colors.h"
#include <stdio.h>
#include <stdlib.h>

char *FL_RGB_buffer = NULL;
char *FL_RGB_BG_buffer = NULL;

const char* FL_RGB(int r, int g, int b) {
    static char buf[32];
    snprintf(buf, sizeof(buf), "\033[38;2;%d;%d;%dm", r, g, b);
    return buf;
}

const char* FL_RGB_BG(int r, int g, int b) {
    static char buf[32];
    snprintf(buf, sizeof(buf), "\033[48;2;%d;%d;%dm", r, g, b);
    return buf;
}


const char *FL_RESET = "\033[0m";

const char *FL_BLINK = "\033[5m";
const char *FL_REVERSE = "\033[7m";

const char *FL_BOLD = "\033[1m";
const char *FL_DIM = "\033[2m";
const char *FL_ITALIC = "\033[3m";
const char *FL_UNDERLINE = "\033[4m";

const char *FL_BLACK = "\033[30m";
const char *FL_GRAPHITE = "\033[90m";
const char *FL_WHITE = "\033[37m";

const char *FL_RED = "\033[31m";
const char *FL_GREEN = "\033[32m";
const char *FL_YELLOW = "\033[33m";
const char *FL_BLUE = "\033[34m";
const char *FL_BRIGHT_BLUE = "\033[94m";

const char *FL_BLACKB = "\033[40m";
const char *FL_REDB = "\033[41m";
const char *FL_GREENB = "\033[42m";
const char *FL_YELLOWB = "\033[43m";
const char *FL_BLUEB = "\033[44m";
const char *FL_WHITEB = "\033[47m";
