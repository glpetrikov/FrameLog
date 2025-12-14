//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <format>
#include <chrono>
#include <ctime>

#include "Colors.hpp"
#include "Common.hpp"
#include "Buffer.hpp"
#include "FileHandler.hpp"

namespace FrameLog {
    enum class LogLevel {
        Trace,
        Print,
        Info,
        Warn,
        Error,
        Fatal
    };

    class Logger {
    public:
        Logger(std::string_view LoggerName, bool IsWriteIFile = true);
        ~Logger();

        FL_API void SetMinimalLogLevel(LogLevel MinimalLogLevel);
        FL_API void SetPattern(const std::string& pattern);

        inline void SetIsPrintingLoggerName(bool Is){
            IsPrintingLoggerName = Is;
        }

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


    	Logger &operator<<(const std::string &Message);
    	Logger &operator<<(const char &Message);
    	Logger &operator<<(const char *Message);
    	Logger &operator<<(int Value);
    	Logger &operator<<(double Value);
    	Logger &operator<<(bool Value);
    	Logger &operator<<(Colors::Style style);
    	Logger &operator<<(Colors::Color color);
    	Logger &operator<<(Colors::BGColor bgcolor);

        FL_API int Add(const char Message);
        FL_API int Add(std::string_view Message);
        FL_API std::string Read();
        FL_API int Flush();
        FL_API int Free();

        template<typename... Args>
        FL_API inline static std::string Format(std::format_string<Args...> fmt, Args&&... args) {
            return std::format(fmt, std::forward<Args>(args)...);
        }

        FL_API inline void FlushFile(){
            fileHandler.Flush();
        }
        FL_API inline void SetName(std::string_view newName){
            LoggerName = newName;
            fileHandler.CloseFile();
            fileHandler.SetFile(newName);
            return;
        }

    private:
        Buffer buffer;
        std::string LoggerName;
        LogLevel MinimalLevel = LogLevel::Trace;
        bool IsPrintingLoggerName = true;
        std::string m_Pattern = "%^[%D] [%T] %n:%$ %v";

        int ColorPrint(std::string Message, LogLevel level,
                      FrameLog::Colors::Color color,
                      FrameLog::Colors::BGColor backgroundColor,
                      bool NewLine);

        std::string FormatPattern(const std::string& message,
                                 LogLevel level,
                                 const std::string& colorCode);

        std::string_view GetLevelString(LogLevel level);
        std::string_view GetLevelColor(LogLevel level);

        FileHandler fileHandler;
    };

    FL_API bool IsPrinting(LogLevel Level, LogLevel MinimalLogLevel);
}