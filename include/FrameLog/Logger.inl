#pragma once

namespace FrameLog
{
	template <typename... Args>
	FL_API Result Logger::Print(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Trace(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Info(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Warn(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Error(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::Fatal(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, false);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::PrintLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Print, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Print, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::TraceLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Trace, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Trace, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::InfoLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Info, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Info, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::WarnLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Warn, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Warn, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::ErrorLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Error, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Error, true);
		}
		return Success;
	}

	template <typename... Args>
	FL_API Result Logger::FatalLine(std::format_string<Args...> fmt, Args&&... args)
	{
		std::string Message = std::format(fmt, std::forward<Args>(args)...);

		if (IsPrinting(LogLevel::Fatal, MinimalLevel))
		{
			ColorPrint(Message, LogLevel::Fatal, true);
		}
		return Success;
	}
} // namespace FrameLog
