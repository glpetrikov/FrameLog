// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "Buffer.h"
#include <string.h>

char *Buffer = NULL;
int BufferSize = 100;
size_t BufferLength = 0;

//============================================================
// Main Buffer Functions, USER API
//============================================================
void FLAddInBuffer(const char *Message)
{
    size_t MessageLength = strlen(Message);
    if (Buffer == NULL)
    {
        FLInitBuffer();
        if (Buffer == NULL)
        {
            return;
        }
    }
    if (!FLExpandBuffer(MessageLength + 1))
    {
        return;
    }
    // PRECONDITION: Message must not be NULL (caller's responsibility)
    memcpy(Buffer + BufferLength, Message, MessageLength);
    BufferLength += MessageLength;
    Buffer[BufferLength] = '\0';
}
//============================================================
// Expand Buffer
//============================================================
bool FLExpandBuffer(size_t RequiredSpace)
{
    while (BufferLength + RequiredSpace > BufferSize)
    {
        size_t oldSize = BufferSize;
        FLIncreaseBufferSize(BufferSize * 2);
        if (BufferSize == oldSize)
        {
            if (FL_ENABLE_ERROR_LOGS == 1)
            {
                printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: Expand Error", FL_RESET);
            }
            return false;
        }
    }
    return true;
}
//============================================================
// Flush Buffer and Free Buffer, USER API
//============================================================
void FLFlushBuffer()
{
    if (Buffer != NULL)
    {
        printf("%s", Buffer);
        free(Buffer);
        Buffer = NULL;
        BufferSize = 100;
        BufferLength = 0;
    }
}
void FLFreeBuffer()
{
    if (Buffer != NULL)
    {
        free(Buffer);
        Buffer = NULL;
        BufferSize = 100;
        BufferLength = 0;
    }
}
//============================================================
// Initialization and Expansion
//============================================================
void FLInitBuffer()
{
    if (Buffer == NULL)
    {
        Buffer = malloc(BufferSize * sizeof(char));
        if (Buffer == NULL)
        {
            if (FL_ENABLE_ERROR_LOGS == 1)
            {
                printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: unsuccessful initialization", FL_RESET);
            }
            return;
        }
    }
    BufferLength = 0;
    Buffer[0] = '\0';
}
//
//
bool FLIncreaseBufferSize(size_t NewSize)
{
    char *Temp = realloc(Buffer, NewSize * sizeof(char));
    if (Temp != NULL)
    {
        BufferSize = NewSize;
        Buffer = Temp;
        return true;
    }
    else
    {
        printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: unsuccessful buffer relocation", FL_RESET);
        return false;
    }
}
