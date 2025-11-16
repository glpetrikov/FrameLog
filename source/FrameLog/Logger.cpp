//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <format>

#include "Logger.hpp"
#include "Common.hpp"

namespace FrameLog {

    Logger::Logger(std::string_view LoggerName) : Custom(*this) {
        this->LoggerName = std::move(LoggerName);
    }

    Logger::~Logger() {
    }

    char Logger::EndL() {
        return '\n';
    }

    void Logger::SetMinimalLogLevel(LogLevel MinimalLogLevel){
        MinimalLevel = MinimalLogLevel;
    }

    //============================================================
    // Prints
    //============================================================
    int Logger::Trace(std::string Message) {
        if(IsPrinting(LogLevel::Trace, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Graphite, Colors::BGColor::Empty, false);
        }
        return 0;
    }

    // --- Print -----
    int Logger::Print(std::string Message) {
        if(IsPrinting(LogLevel::Print, MinimalLevel)){
            ColorPrint(Message, Colors::Color::BrightBlue, Colors::BGColor::Empty, false);
        }
        return 0;
    }

    // --- Info -----
    int Logger::Info(std::string Message) {
        if(IsPrinting(LogLevel::Info, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Green, Colors::BGColor::Empty, false);
        }
        return 0;
    }

    // --- Warn -----
    int Logger::Warn(std::string Message) {
        if(IsPrinting(LogLevel::Warn, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Yellow, Colors::BGColor::Empty, false);
        }
        return 0;
    }

    // --- Error -----
    int Logger::Error(std::string Message) {
        if(IsPrinting(LogLevel::Error, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Red, Colors::BGColor::Empty, false);
        }
        return 0;
    }

    // --- Fatal -----
    int Logger::Fatal(std::string Message) {
        if(IsPrinting(LogLevel::Fatal, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Empty, Colors::BGColor::RedB, false);
        }
        return 0;
    }

    //============================================================
    // Line Prints
    //============================================================
    int Logger::TraceLine(std::string Message) {
        if(IsPrinting(LogLevel::Trace, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Graphite, Colors::BGColor::Empty, true);
        }
        return 0;
    }

    // --- Print Line -----
    int Logger::PrintLine(std::string Message) {
        if(IsPrinting(LogLevel::Print, MinimalLevel)){
            ColorPrint(Message, Colors::Color::BrightBlue, Colors::BGColor::Empty, true);
        }
        return 0;
    }

    // --- Info Line -----
    int Logger::InfoLine(std::string Message) {
        if(IsPrinting(LogLevel::Info, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Green, Colors::BGColor::Empty, true);
        }
        return 0;
    }

    // --- Warn Line -----
    int Logger::WarnLine(std::string Message) {
        if(IsPrinting(LogLevel::Warn, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Yellow, Colors::BGColor::Empty, true);
        }
        return 0;
    }

    // --- Error Line -----
    int Logger::ErrorLine(std::string Message) {
        if(IsPrinting(LogLevel::Error, MinimalLevel)){
            ColorPrint(Message, Colors::Color::Red, Colors::BGColor::Empty, true);
        }
        return 0;
    }

    // --- Fatal Line -----
    int Logger::FatalLine(std::string Message) {
        if(IsPrinting(LogLevel::Fatal, MinimalLevel)){
        ColorPrint(Message, Colors::Color::Empty, Colors::BGColor::RedB, true);
        }
        return 0;
    }

    //============================================================
    // Operators
    //============================================================
    Logger::CustomMessage &Logger::CustomMessage::operator<<(const std::string &Message) {
        logger.Add(Message);
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(const char &Message) {
        logger.Add(Message);
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(const char *Message) {
        logger.Add(Message);
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(int Value) {
        logger.Add(std::to_string(Value));
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(double Value) {
        logger.Add(std::to_string(Value));
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(bool Value) {
        logger.Add(Value ? "true" : "false");
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(Colors::Style style) {
        logger.Add(Colors::IsColor(style));
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(Colors::Color color) {
        logger.Add(Colors::IsColor(color));
        return *this;
    }

    Logger::CustomMessage &Logger::CustomMessage::operator<<(Colors::BGColor bgcolor) {
        logger.Add(Colors::IsColor(bgcolor));
        return *this;
    }

    std::string Logger::Read() {
        std::string Result;
        std::getline(std::cin, Result);
        return Result;
    }

    //============================================================
    // Buffer Functions
    //============================================================
    int Logger::Add(const char Message) {
        buffer.Add(Message);
        return 0;
    }

    int Logger::Add(std::string_view Message) {
        buffer.Add(Message);
        return 0;
    }

    int Logger::Flush() {
        std::string data = std::string(buffer.GetData());
        std::cout << data;
        buffer.Clear();
        return 0;
    }

    int Logger::Free() {
        buffer.Clear();
        return 0;
    }

    //============================================================
    // ColorPrint
    //============================================================
    int Logger::ColorPrint(std::string Message, FrameLog::Colors::Color color, FrameLog::Colors::BGColor backgroundColor, bool NewLine) {
        if (Message.empty()) {
            std::cerr << "Logger Error: Message is empty" << std::endl;
            return -1;
        }

        buffer.Add(Colors::IsColor(color));
        buffer.Add(Colors::IsColor(backgroundColor));
        buffer.Add(Message);
        buffer.Add(Colors::IsColor(Colors::Style::Reset));
        buffer.Add(NewLine ? std::string_view("\n") : std::string_view(""));
        return 0;
    }

// IsPrinting
    bool IsPrinting(LogLevel Level, LogLevel MinimalLogLevel){
        return static_cast<int>(Level) >= static_cast<int>(MinimalLogLevel);
    }
}