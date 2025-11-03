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
        Logger(std::string_view LoggerName);
        ~Logger();

        FL_API char EndL();

        FL_API int Print(std::string Message);
        FL_API int Trace(std::string Message);
        FL_API int Info(std::string Message);
        FL_API int Warn(std::string Message);
        FL_API int Error(std::string Message);
        FL_API int Fatal(std::string Message);

        FL_API int PrintLine(std::string Message);
        FL_API int TraceLine(std::string Message);
        FL_API int InfoLine(std::string Message);
        FL_API int WarnLine(std::string Message);
        FL_API int ErrorLine(std::string Message);
        FL_API int FatalLine(std::string Message);

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

        CustomMessage Custom; // logger.Custom

        FL_API int Add(const char Message);

        FL_API int Add(std::string_view Message);

        FL_API std::string Read();

        FL_API int Flush();

        FL_API int Free();

    private:
        Buffer buffer;
        int ColorPrint(std::string Message, FrameLog::Colors::Color color, FrameLog::Colors::BGColor backgroundColor, bool NewLine);
    };
}