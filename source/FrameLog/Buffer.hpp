//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "Platform.hpp"
#include "Common.hpp"

namespace FrameLog
{
    class Buffer
    {
    public:
        Buffer();
        ~Buffer();

        FL_API int Add(std::string Message);
        FL_API int Add(std::string_view Message);
        FL_API int Add(const char *Message);
        FL_API int Flush();
        FL_API int Free();

    private:
        std::string data;
    };
}