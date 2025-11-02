//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "Buffer.hpp"
#include "Colors.hpp"
#include "Common.hpp"

namespace FrameLog {
    enum class LogLevel {
        Print,
        Trace,
        Info,
        Warn,
        Error,
        Fatalм
    };

    class Logger {
        std::string LoggerName;

    public:
        Logger(std::string LoggerName);
        ~Logger();

        FL_API char EndL();

        FL_API int Print(std::string Message);
        FL_API int Trace(std::string Message);
        FL_API int Info(std::string Message);
        FL_API int Warn(std::string Message);
        FL_API int Error(std::string Message);
        FL_API int Fatal(std::string Message);

        FL_API int Printl(std::string Message);
        FL_API int Tracel(std::string Message);
        FL_API int Infol(std::string Message);
        FL_API int Warnl(std::string Message);
        FL_API int Errorl(std::string Message);
        FL_API int Fatall(std::string Message);

        struct CustomMessage {
            Logger &logger;

            CustomMessage(Logger &l) : logger(l) {}

            CustomMessage &operator<<(const std::string &Message);
            CustomMessage &operator<<(const char &Message);
            CustomMessage &operator<<(const char *Message);
            CustomMessage &operator<<(int Value);
            CustomMessage &operator<<(double Value);
            CustomMessage &operator<<(bool Value);
            CustomMessage &operator<<(Colors::Style style);
            CustomMessage &operator<<(Colors::Color color);
            CustomMessage &operator<<(Colors::BGColor bgcolor);
        };

        CustomMessage Custom; // <<
        FL_API std::string Read();

        FL_API inline int Flush() {
            buffer.Flush();
            return 0;
        }

        FL_API inline int Free() {
            buffer.Free();
            return 0;
        }

        FL_API int Add(const char Message);

        FL_API inline int Add(std::string Message) {
            buffer.Add(Message);
            return 0;
        }

        FL_API inline int Add(std::string_view Message) {
            buffer.Add(Message);
            return 0;
        }

        FL_API inline int Add(const char *Message) {
            buffer.Add(Message);
            return 0;
        }

    private:
        Buffer buffer;
        int ColorPrint(std::string Message, FrameLog::Colors::Color color, FrameLog::Colors::BGColor backgroundColor, bool NewLine);
    };
}