//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "Buffer.hpp"
#include "Common.hpp"

namespace FrameLog {

    Buffer::Buffer() {
        data.reserve(1024);
    }

    Buffer::~Buffer() {
        Flush();
    }

    int Buffer::Add(std::string Message) {
        if (!Message.empty()) {
            data += Message;
            return 0;
        } else {
            return -1;
        }
    }

    int Buffer::Add(std::string_view Message) {
        if (!Message.empty()) {
            data += Message;
            return 0;
        } else {
            return -1;
        }
    }

    int Buffer::Add(const char *Message) {
        if (Message) {
            data += Message;
            return 0;
        } else {
            return -1;
        }
    }

    int Buffer::Add(const char Message) {
        if (Message) {
            data += Message;
            return 0;
        } else {
            return -1;
        }
    }

    int Buffer::Flush() {
        std::cout << Buffer::data;
        Buffer::data = "";
        return 0;
    }

    int Buffer::Free() {
        Buffer::data = "";
        return 0;
    }
}