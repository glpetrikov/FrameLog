//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <mutex>

#include "Common.hpp"
#include "Platform.hpp"

namespace FrameLog {
    class Buffer {
        std::mutex mtx;

    public:
        Buffer();
        ~Buffer();

        FL_API int Add(std::string_view Message);
        FL_API int Add(const char);
        FL_API int Flush();
        FL_API int Free();

    private:
        std::string data;
    };
}