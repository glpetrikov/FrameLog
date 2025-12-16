#pragma once

namespace FrameLog
{
	template <typename... Args>
	FL_API Result Logger::Print(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Trace(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Info(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Warn(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Error(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Fatal(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::PrintLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, Colors::Color::BrightBlue, Colors::BGColor::Empty, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::TraceLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, Colors::Color::Graphite, Colors::BGColor::Empty, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::InfoLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, Colors::Color::Green, Colors::BGColor::Empty, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::WarnLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, Colors::Color::Yellow, Colors::BGColor::Empty, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::ErrorLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, Colors::Color::Red, Colors::BGColor::Empty, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::FatalLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, Colors::Color::Empty, Colors::BGColor::RedB, true);
		}
		return Success;
	}
} // namespace FrameLog
