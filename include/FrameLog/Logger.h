//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <chrono>
#include <ctime>
#include <format>

#include "Buffer.h"
#include "Colors.h"
#include "Common.h"
#include "FileHandler.h"

namespace FrameLog
{

	enum class LogLevel
	{
		Trace,
		Print,
		Info,
		Warn,
		Error,
		Fatal
	};

	class Logger
	{
	public:
		Logger(std::string_view LoggerName = "", bool IsWriteIFile = true);
		~Logger();

		FL_API Result SetMinimalLogLevel(LogLevel MinimalLogLevel);
		FL_API Result SetPattern(const std::string& pattern);

		inline Result SetIsPrintingLoggerName(bool Is)
		{
			IsPrintingLoggerName = Is;
			return Success;
		}

		FL_API char EndL();

		FL_API Result Print(std::string Message);
		FL_API Result Trace(std::string Message);
		FL_API Result Info(std::string Message);
		FL_API Result Warn(std::string Message);
		FL_API Result Error(std::string Message);
		FL_API Result Fatal(std::string Message);

		FL_API Result PrintLine(std::string Message);
		FL_API Result TraceLine(std::string Message);
		FL_API Result InfoLine(std::string Message);
		FL_API Result WarnLine(std::string Message);
		FL_API Result ErrorLine(std::string Message);
		FL_API Result FatalLine(std::string Message);


		template <typename... Args>
		FL_API Result Print(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result Trace(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result Info(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result Warn(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result Error(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result Fatal(std::format_string<Args...> fmt, Args&&... args);

		template <typename... Args>
		FL_API Result PrintLine(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result TraceLine(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result InfoLine(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result WarnLine(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result ErrorLine(std::format_string<Args...> fmt, Args&&... args);
		template <typename... Args>
		FL_API Result FatalLine(std::format_string<Args...> fmt, Args&&... args);


		Logger& operator<<(const std::string& Message);
		Logger& operator<<(const char& Message);
		Logger& operator<<(const char* Message);
		Logger& operator<<(int Value);
		Logger& operator<<(double Value);
		Logger& operator<<(bool Value);
		Logger& operator<<(Colors::Style style);
		Logger& operator<<(Colors::Color color);
		Logger& operator<<(Colors::BGColor bgcolor);

		FL_API Result Add(const char Message);
		FL_API Result Add(std::string_view Message);
		FL_API std::string Read();
		FL_API Result Flush();
		FL_API Result Free();

		template <typename... Args>
		FL_API inline static std::string Format(std::format_string<Args...> fmt, Args&&... args)
		{
			return std::format(fmt, std::forward<Args>(args)...);
		}

		FL_API inline Result FlushFile()
		{
			fileHandler.Flush();
			return Success;
		}

		FL_API inline Result SetName(std::string_view newName)
		{
			LoggerName = newName;
			fileHandler.CloseFile();
			fileHandler.SetFile(newName);
			return Success;
		}

		FL_API inline std::string GetDefaultFormat() { return "%^[%D] [%T] %n:%$ %v"; }

		FL_API static inline std::string GetDefaultFormat(int empty = 0)
		{
			return "%^[%D] [%T] %n:%$ %v";
			(void)empty;
		}

	private:
		Buffer buffer;
		std::string LoggerName;
		LogLevel MinimalLevel = LogLevel::Trace;
		bool IsPrintingLoggerName = true;
		std::string m_Pattern = "%^[%D] [%T] %n:%$ %v";

		int ColorPrint(std::string Message, LogLevel level, FrameLog::Colors::Color color,
					   FrameLog::Colors::BGColor backgroundColor, bool NewLine);

		std::string FormatPattern(const std::string& message, LogLevel level, const std::string& colorCode);

		std::string_view GetLevelString(LogLevel level);
		std::string_view GetLevelColor(LogLevel level);

		FileHandler fileHandler;
	};

	FL_API bool IsPrinting(LogLevel Level, LogLevel MinimalLogLevel);
} // namespace FrameLog

#include "Logger.inl"

////////////////////////////////////////////////////////////
///					   extern C part					 ///
////////////////////////////////////////////////////////////
extern "C" {
inline Result Print(const char* Message)
{
	FrameLog::Logger log("");
	return log.Print(std::string(Message));
}
}
