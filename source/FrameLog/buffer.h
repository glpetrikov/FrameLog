// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include "common.h"
#include "Prints.h"

void FLInitBuffer();
void FLAddInBuffer(const char *Message);
void FLExpandBuffer(size_t NewSize);
void FLFreeBuffer();
void FLFlushBuffer();
