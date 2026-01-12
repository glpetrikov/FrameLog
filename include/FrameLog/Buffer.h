//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <mutex>

#include "../../source/Platform.h"
#include "Common.h"

namespace FrameLog
{
	class Buffer
	{
		std::mutex mtx;

	public:
		FRAMELOG_API Buffer()
		{
			std::lock_guard<std::mutex> lock(mtx);

			data.reserve(4096);
		}

		FRAMELOG_API ~Buffer() { data.clear(); }

		FRAMELOG_API Result Add(std::string_view Text)
		{
			std::lock_guard<std::mutex> lock(mtx);

			if (!Text.empty())
			{
				data.append(Text.data(), Text.size());
				return Success;
			}
			else
			{
				return Warning;
			}
		}

		FRAMELOG_API Result Add(const char Text)
		{
			std::lock_guard<std::mutex> lock(mtx);

			if (Text)
			{
				data += Text;
				return Success;
			}
			else
			{
				return Warning;
			}
		}

		FRAMELOG_API std::string GetData()
		{
			std::lock_guard<std::mutex> lock(mtx);

			return data;
		}

		FRAMELOG_API Result Clear()
		{
			std::lock_guard<std::mutex> lock(mtx);

			data.clear();
			return Success;
		}

		FRAMELOG_API Result Clean()
		{
			std::lock_guard<std::mutex> lock(mtx);

			data.clear();
			return Success;
		}

		FRAMELOG_API size_t GetSize()
		{
			std::lock_guard<std::mutex> lock(mtx);
			return data.size();
		}

	private:
		std::string data;
	};
} // namespace FrameLog
