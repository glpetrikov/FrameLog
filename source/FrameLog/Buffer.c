// FrameLog - MIT License (c) 2025 Gleb Petrikov

#include "Buffer.h"
#include <string.h>

char *Buffer = NULL;
int BufferSize = 100;
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
        Buffer[0] = '\0';
    }
}
void FLAddInBuffer(const char *Message)
{
    size_t CurrentLength;
    size_t MessageLength = strlen(Message);
    if (Buffer != NULL)
    {
        CurrentLength = strlen(Buffer);
    }
    else
    {
        FLInitBuffer();
        if (Buffer == NULL)
        {
            return;
        }
        CurrentLength = strlen(Buffer);
    }

    while (CurrentLength + MessageLength + 1 > BufferSize)
    {
        FLExpandBuffer(BufferSize * 2);
    }
    strcat(Buffer, Message);
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
