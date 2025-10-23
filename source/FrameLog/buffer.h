// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include "common.h"
#include "Prints.h"

void FLInitBuffer();
void FLAddInBuffer(const char *Message);
bool FLExpandBuffer(size_t RequiredSpace);
void FLFreeBuffer();
void FLFlushBuffer();
bool FLIncreaseBufferSize(size_t NewSize);
