// FrameLog - MIT License (c) 2025 Gleb Petrikov

#pragma once

#include "common.h"
#include "Prints.h"

extern char *Buffer;
extern size_t BufferSize;
extern size_t BufferLength;

int FLAddInBuffer(const char *Message);
// Size
int FLBufferSize();
// Flush
int FLFlushBuffer();
int FLClearBuffer();
// Expands
int FLExpandBuffer(size_t RequiredSpace);
int FLIncreaseBufferSize(size_t NewSize);
// Init
int FLInitBuffer();
