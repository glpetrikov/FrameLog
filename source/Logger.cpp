//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <chrono>
#include <ctime>
#include <format>
#include <iomanip>
#include <sstream>

#include <string_view>
#include <thread>
#include <unistd.h>
#include "Common.hpp"
#include "Logger.hpp"

namespace FrameLog
{

	Logger::Logger(std::string_view LoggerName, bool IsWriteIFile) : custom(*this)
	{
		this->LoggerName = std::move(LoggerName);
		if (IsWriteIFile)
		{
			fileHandler.SetFile(LoggerName);
		}
	}

	Logger::~Logger() { fileHandler.CloseFile(); }

	char Logger::EndL() { return '\n'; }

	void Logger::SetMinimalLogLevel(LogLevel MinimalLogLevel) { MinimalLevel = MinimalLogLevel; }

	//============================================================
	// Formats
	//============================================================

	void Logger::SetPattern(const std::string& pattern) { m_Pattern = pattern; }

	std::string_view Logger::GetLevelString(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Trace:
			return "TRACE";
		case LogLevel::Print:
			return "PRINT";
		case LogLevel::Info:
			return "INFO";
		case LogLevel::Warn:
			return "WARN";
		case LogLevel::Error:
			return "ERROR";
		case LogLevel::Fatal:
			return "FATAL";
		default:
			return "UNKNOWN";
		}
	}

	std::string_view Logger::GetLevelColor(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Trace:
			return Colors::IsColor(Colors::Color::Graphite);
		case LogLevel::Print:
			return Colors::IsColor(Colors::Color::BrightBlue);
		case LogLevel::Info:
			return Colors::IsColor(Colors::Color::Green);
		case LogLevel::Warn:
			return Colors::IsColor(Colors::Color::Yellow);
		case LogLevel::Error:
			return Colors::IsColor(Colors::Color::Red);
		case LogLevel::Fatal:
			return Colors::IsColor(Colors::BGColor::RedB);
		default:
			return "";
		}
	}

	std::string Logger::FormatPattern(const std::string& message, LogLevel level, const std::string& colorCode)
	{
		auto now = std::chrono::system_clock::now();
		auto time_t = std::chrono::system_clock::to_time_t(now);
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
		std::tm tm = *std::localtime(&time_t);

		char time_buf[32], date_buf[32], datetime_buf[64];
		char year_buf[16], month_buf[4], day_buf[4];
		char hour_buf[8], min_buf[4], sec_buf[4];

		strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &tm);
		strftime(date_buf, sizeof(date_buf), "%Y.%m.%d", &tm);
		strftime(datetime_buf, sizeof(datetime_buf), "%Y.%m.%d %H:%M:%S", &tm);

		snprintf(year_buf, sizeof(year_buf), "%04d", tm.tm_year + 1900);
		snprintf(month_buf, sizeof(month_buf), "%02d", tm.tm_mon + 1);
		snprintf(day_buf, sizeof(day_buf), "%02d", tm.tm_mday);
		snprintf(hour_buf, sizeof(hour_buf), "%02d", tm.tm_hour);
		snprintf(min_buf, sizeof(min_buf), "%02d", tm.tm_min);
		snprintf(sec_buf, sizeof(sec_buf), "%02d", tm.tm_sec);

		std::string levelStr(GetLevelString(level));
		std::string result;
		result.reserve(m_Pattern.size() + message.size() + 128);

		for (size_t i = 0; i < m_Pattern.size(); ++i)
		{
			if (m_Pattern[i] == '%' && i + 1 < m_Pattern.size())
			{
				char next = m_Pattern[i + 1];

				switch (next)
				{
				case '^':
					result += colorCode;
					i++;
					break;
				case '$':
					if (colorCode == "")
					{
						++i;
						break;
					}
					result += Colors::IsColor(Colors::Style::Reset);
					i++;
					break;
				case 'v':
					result += message;
					i++;
					break;
				case 'n':
					result += LoggerName;
					i++;
					break;
				case 'l':
					result += levelStr;
					i++;
					break;
				case 'L':
					result += levelStr.substr(0, 1);
					i++;
					break;
				case 'T':
					result += time_buf;
					i++;
					break;
				case 'D':
					result += date_buf;
					i++;
					break;
				case 'F':
					result += datetime_buf;
					i++;
					break;
				case 'Y':
					result += year_buf;
					i++;
					break;
				case 'm':
					result += month_buf;
					i++;
					break;
				case 'd':
					result += day_buf;
					i++;
					break;
				case 'H':
					result += hour_buf;
					i++;
					break;
				case 'M':
					result += min_buf;
					i++;
					break;
				case 'S':
					result += sec_buf;
					i++;
					break;
				case 'e':
					{
						char ms_buf[8];
						snprintf(ms_buf, sizeof(ms_buf), "%03d", (int)ms.count());
						result += ms_buf;
						i++;
						break;
					}
				case 't':
					{
						std::ostringstream oss;
						oss << std::this_thread::get_id();
						result += oss.str();
						i++;
						break;
					}
				case 'P':
					{
#ifdef _WIN32
						result += std::to_string(GetCurrentProcessId());
#else
						result += std::to_string(getpid());
#endif
						i++;
						break;
					}
				case '%':
					result += '%';
					i++;
					break;
				default:
					result += m_Pattern[i];
					break;
				}
			}
			else
			{
				result += m_Pattern[i];
			}
		}

		return result;
	}

	//============================================================
	// Prints
	//============================================================
	int Logger::Trace(std::string Message)
	{
		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	int Logger::Print(std::string Message)
	{
		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	int Logger::Info(std::string Message)
	{
		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	int Logger::Warn(std::string Message)
	{
		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	int Logger::Error(std::string Message)
	{
		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	int Logger::Fatal(std::string Message)
	{
		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, false);
		}
		return 0;
	}

	//============================================================
	// Line Prints
	//============================================================
	int Logger::TraceLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	int Logger::PrintLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	int Logger::InfoLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	int Logger::WarnLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	int Logger::ErrorLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	int Logger::FatalLine(std::string Message)
	{
		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, true);
		}
		return 0;
	}

	//============================================================
	// Operators
	//============================================================
	Logger& Logger::operator<<(const std::string& Message)
	{
		Add(Message);
		return *this;
	}

	Logger& Logger::operator<<(const char& Message)
	{
		Add(Message);
		return *this;
	}

	Logger& Logger::operator<<(const char* Message)
	{
		Add(Message);
		return *this;
	}

	Logger& Logger::operator<<(int Value)
	{
		Add(std::to_string(Value));
		return *this;
	}

	Logger& Logger::operator<<(double Value)
	{
		Add(std::to_string(Value));
		return *this;
	}

	Logger& Logger::operator<<(bool Value)
	{
		.Add(Value ? "true" : "false");
		return *this;
	}

	Logger& Logger::operator<<(Colors::Style style)
	{
		Add(Colors::IsColor(style));
		return *this;
	}

	Logger& Logger::operator<<(Colors::Color color)
	{
		Add(Colors::IsColor(color));
		return *this;
	}

	Logger& Logger::operator<<(Colors::BGColor bgcolor)
	{
		Add(Colors::IsColor(bgcolor));
		return *this;
	}

	std::string Logger::Read()
	{
		std::string Result;
		std::getline(std::cin, Result);
		return Result;
	}

	//============================================================
	// Buffer Functions
	//============================================================
	int Logger::Add(const char Message)
	{
		buffer.Add(Message);
		return 0;
	}

	int Logger::Add(std::string_view Message)
	{
		buffer.Add(Message);
		return 0;
	}

	int Logger::Flush()
	{
		std::string data = std::string(buffer.GetData());
		std::cout << data;
		buffer.Clear();
		return 0;
	}

	int Logger::Free()
	{
		buffer.Clear();
		return 0;
	}

	//============================================================
	// ColorPrint
	//============================================================
	int Logger::ColorPrint(std::string Message, LogLevel level, FrameLog::Colors::Color color,
						   FrameLog::Colors::BGColor backgroundColor, bool NewLine)
	{
		if (Message.empty())
		{
			std::cerr << "Logger Error: Message is empty" << std::endl;
			return -1;
		}

		fileHandler.Write(std::string(FormatPattern(Message, level, "")));
		fileHandler.Write(NewLine ? std::string_view("\n") : std::string_view(""));

		std::string colorCode = std::string(GetLevelColor(level));
		std::string formatted = std::string(FormatPattern(Message, level, colorCode));

		buffer.Add(formatted);
		buffer.Add(NewLine ? std::string_view("\n") : std::string_view(""));
		return 0;
	}

	bool IsPrinting(LogLevel Level, LogLevel MinimalLogLevel)
	{
		return static_cast<int>(Level) >= static_cast<int>(MinimalLogLevel);
	}
} // namespace FrameLog
