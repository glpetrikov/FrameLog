//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <mutex>

#include "Buffer.hpp"
#include "Common.hpp"

namespace FrameLog {

    Buffer::Buffer() {
        std::lock_guard<std::mutex> lock(mtx);

        data.reserve(4096);
    }

    Buffer::~Buffer() {
        data.clear();
        data.shrink_to_fit();
    }

    bool Buffer::Add(std::string_view Text) {
        std::lock_guard<std::mutex> lock(mtx);

        if (!Text.empty()) {
            data.append(Text.data(), Text.size());
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

    std::string_view Buffer::GetData() {
        std::lock_guard<std::mutex> lock(mtx);

        return std::string_view(data);
    }

    bool Buffer::Clear() {
        std::lock_guard<std::mutex> lock(mtx);

        data.clear();
        data.shrink_to_fit();
        return true;
    }
}
