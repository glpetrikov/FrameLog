// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include "common.h"
// #include "buffer.h"

void FLPrint(const char *message)
{
    printf("%s%s%s", FL_GRAPHITE, message, FL_RESET);
}
void FLPrintln(const char *message)
{
    printf("%s%s%s\n", FL_GRAPHITE, message, FL_RESET);
}
