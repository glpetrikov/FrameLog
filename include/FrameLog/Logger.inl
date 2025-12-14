#pragma once

namespace FrameLog
{
	template <typename... Args>
	FL_API int Logger::Print(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::Trace(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::Info(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::Warn(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::Error(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::Fatal(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, false);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::PrintLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::TraceLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::InfoLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::WarnLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::ErrorLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, true);
		}
		return 0;
	}

	template <typename... Args>
	FL_API int Logger::FatalLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, true);
		}
		return 0;
	}
} // namespace FrameLog
