//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <stdlib.h>
#include "Platform.h"

extern char *Buffer;
extern size_t BufferSize;
extern size_t BufferLength;

FL_API int FLAddInBuffer(const char *Message);
// Size
FL_API int FLBufferSize();
// Flush
FL_API int FLFlushBuffer();
FL_API int FLClearBuffer();
// Expands
FL_API int FLExpandBuffer(size_t RequiredSpace);
FL_API int FLIncreaseBufferSize(size_t NewSize);
// Init
FL_API int FLInitBuffer();
