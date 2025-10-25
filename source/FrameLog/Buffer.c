// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "Buffer.h"
#include <string.h>

char *Buffer = NULL;
size_t BufferSize = 100;
size_t BufferLength = 0;

//============================================================
// Main Buffer Functions, USER API
//============================================================
int FLAddInBuffer(const char *Message)
{
    if (Message == NULL)
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: Message is NULL", FL_RESET);
        }
        return -1;
    }
    size_t MessageLength = strlen(Message);
    if (Buffer == NULL)
    {
        int ReturnCode = FLInitBuffer();
        if (ReturnCode == -1)
        {
            return -1;
        }
    }
    int ReturnCode = FLExpandBuffer(MessageLength + 1);
    if (ReturnCode == -1)
    {
        return -1;
    }

    memcpy(Buffer + BufferLength, Message, MessageLength);
    BufferLength += MessageLength;
    Buffer[BufferLength] = '\0';
    return 0;
}
//============================================================
// Buffer Size, USER API
//============================================================
int FLBufferSize()
{
    printf("%s%zu\n", "BufferSize: ", BufferSize);
    return 0;
}
//============================================================
// Flush Buffer and Free Buffer, USER API
//============================================================
int FLFlushBuffer()
{
    if (Buffer != NULL && BufferLength != 0)
    {
        printf("%s", Buffer);
        free(Buffer);
        Buffer = NULL;
        BufferSize = 100;
        BufferLength = 0;
        return 0;
    }
    else
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: Attempt to flush an empty/uninitialized buffer", FL_RESET);
        }
        return -1;
    }
}
int FLClearBuffer()
{
    if (Buffer != NULL && BufferLength != 0)
    {
        free(Buffer);
        Buffer = NULL;
        BufferSize = 100;
        BufferLength = 0;
        return 0;
    }
    else
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: Attempt to clear an empty/uninitialized buffer", FL_RESET);
        }
        return -1;
    }
}
//============================================================
// Expand Buffer
//============================================================
int FLExpandBuffer(size_t RequiredSpace)
{
    while (BufferLength + RequiredSpace > BufferSize)
    {
        int ReturnCode = FLIncreaseBufferSize(BufferSize * 2);
        if (ReturnCode == -1)
        {
            return -1;
        }
    }
    return 0;
}
int FLIncreaseBufferSize(size_t NewSize)
{
    char *SaveBuffer = Buffer;
    char *Temp = realloc(Buffer, NewSize * sizeof(char));
    if (Temp != NULL)
    {
        BufferSize = NewSize;
        Buffer = Temp;
        return 0;
    }
    else
    {
        Buffer = SaveBuffer;
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: unsuccessful buffer relocation", FL_RESET);
        }
        return -1;
    }
}
//============================================================
// Initialization Buffer
//============================================================
int FLInitBuffer()
{
    if (Buffer == NULL)
    {
        Buffer = malloc(BufferSize * sizeof(char));
        if (Buffer == NULL)
        {
            if (FL_ENABLE_LOGS == 1)
            {
                printf("%s%s%s%s\n", FL_RESET, FL_RED, "FrameLog Buffer Error: unsuccessful initialization", FL_RESET);
            }
            return 0;
        }
    }

    if (BufferLength > 0)
    {
        if (FL_ENABLE_LOGS == 1)
        {
            printf("%s%s%s%s\n", FL_RESET, FL_YELLOW, "FrameLog Buffer Warning: Buffer has already been initialized", FL_RESET);
        }
        return -1;
    }
    else
    {
        BufferLength = 0;
        Buffer[0] = '\0';
    }
    return 0;
}
