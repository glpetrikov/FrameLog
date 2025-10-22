// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "Buffer.h"
#include <string.h>

char *Buffer = NULL;
int BufferSize = 100;
size_t BufferLength = 0;

void FLInitBuffer()
{
    if (Buffer == NULL)
    {
        Buffer = malloc(BufferSize * sizeof(char));
        if (Buffer == NULL)
        {
            FLErrorln("Failed to allocate FrameLog buffer");
            return;
        }
    }
    BufferLength = 0;
    Buffer[0] = '\0';
}
void FLAddInBuffer(const char *Message)
{
    size_t MessageLength = strlen(Message);
    if (Buffer == NULL)
    {
        FLInitBuffer();
    }

    while (BufferLength + MessageLength + 1 > BufferSize)
    {
        FLExpandBuffer(BufferSize * 2);
    }
    memcpy(Buffer + BufferLength, Message, MessageLength);
    BufferLength += MessageLength;
    Buffer[BufferLength] = '\0';
}
void FLExpandBuffer(size_t NewSize)
{
    char *Temp = realloc(Buffer, NewSize * sizeof(char));
    if (Temp != NULL)
    {
        BufferSize = NewSize;
        Buffer = Temp;
    }
    else
    {
        FLErrorln("Failed to expand FrameLog buffer");
    }
}
void FLFlushBuffer()
{
    if (Buffer != NULL)
    {
        printf("%s", Buffer);
        free(Buffer);
        Buffer = NULL;
        FLInitBuffer();
    }
}
