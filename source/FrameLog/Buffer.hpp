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
        FRAMELOG_API Buffer();
        FRAMELOG_API ~Buffer();

        FRAMELOG_API bool Add(std::string_view Message);
        FRAMELOG_API bool Add(const char);
        FRAMELOG_API std::string_view GetData();
        FRAMELOG_API bool Clear();

    private:
        std::string data;
    };
}