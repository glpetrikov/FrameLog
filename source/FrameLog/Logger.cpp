//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "Logger.hpp"
#include "Common.hpp"

namespace FrameLog {

    Logger::Logger(std::string LoggerName) : Custom(*this) {
        this->LoggerName = std::move(LoggerName);
    }

    Logger::~Logger() {
    }

    char Logger::EndL() {
        return '\n';
    }

    //============================================================
    // Prints
    //============================================================
    int Logger::Trace(std::string Message) {
        ColorPrint(Message, Colors::Color::Graphite, Colors::BGColor::Reset, false);
        return 0;
    }

    // --- Print -----
    int Logger::Print(std::string Message) {
        ColorPrint(Message, Colors::Color::BrightBlue, Colors::BGColor::Reset, false);
        return 0;
    }

    // --- Info -----
    int Logger::Info(std::string Message) {
        ColorPrint(Message, Colors::Color::Green, Colors::BGColor::Reset, false);
        return 0;
    }

    // --- Warn -----
    int Logger::Warn(std::string Message) {
        ColorPrint(Message, Colors::Color::Yellow, Colors::BGColor::Reset, false);
        return 0;
    }

    // --- Error -----
    int Logger::Error(std::string Message) {
        ColorPrint(Message, Colors::Color::Red, Colors::BGColor::Reset, false);
        return 0;
    }

    // --- Fatal -----
    int Logger::Fatal(std::string Message) {
        ColorPrint(Message, Colors::Color::Reset, Colors::BGColor::RedB, false);
        return 0;
    }

    //============================================================
    // Line Prints
    //============================================================
    int Logger::Tracel(std::string Message) {
        ColorPrint(Message, Colors::Color::Graphite, Colors::BGColor::Reset, true);
        return 0;
    }

    // --- Print -----
    int Logger::Printl(std::string Message) {
        ColorPrint(Message, Colors::Color::BrightBlue, Colors::BGColor::Reset, true);
        return 0;
    }

    // --- Info -----
    int Logger::Infol(std::string Message) {
        ColorPrint(Message, Colors::Color::Green, Colors::BGColor::Reset, true);
        return 0;
    }

    // --- Warn -----
    int Logger::Warnl(std::string Message) {
        ColorPrint(Message, Colors::Color::Yellow, Colors::BGColor::Reset, true);
        return 0;
    }

    // --- Error -----
    int Logger::Errorl(std::string Message) {
        ColorPrint(Message, Colors::Color::Red, Colors::BGColor::Reset, true);
        return 0;
    }

    // --- Fatal -----
    int Logger::Fatall(std::string Message) {
        ColorPrint(Message, Colors::Color::Reset, Colors::BGColor::RedB, true);
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
        std::string Result = "";
        std::cin >> Result;
        return Result;
    }

    int Logger::Add(const char Message) {
        buffer.Add(Message);
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
        std::string_view Color = Colors::IsColor(color);
        std::string_view BGColor = Colors::IsColor(backgroundColor);

        buffer.Add(Color);
        buffer.Add(BGColor);
        buffer.Add(Message);
        buffer.Add(IsColor(Colors::Style::Reset));
        buffer.Add(NewLine ? std::string_view("\n") : std::string_view(""));
        return 0;
    }
}