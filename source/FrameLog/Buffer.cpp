//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <mutex>

#include "Buffer.hpp"
#include "Common.hpp"

namespace FrameLog {

    Buffer::Buffer() {
        std::lock_guard<std::mutex> lock(mtx);

        data.reserve(1024);
    }

    Buffer::~Buffer() {
        std::lock_guard<std::mutex> lock(mtx);

        data.clear();
    }

    bool Buffer::Add(std::string_view Text) {
        std::lock_guard<std::mutex> lock(mtx);

        if (!Text.empty()) {
            data += Text;
            return true;
        } else {
            return false;
        }
    }

    bool Buffer::Add(const char Text) {
        std::lock_guard<std::mutex> lock(mtx);

        if (Text) {
            data += Text;
            return true;
        } else {
            return false;
        }
    }

    std::string Buffer::GetData() {
        std::lock_guard<std::mutex> lock(mtx);

        return data;
    }

    bool Buffer::Clear() {
        std::lock_guard<std::mutex> lock(mtx);

        data.clear();
        data = "";
        return true;
    }
}