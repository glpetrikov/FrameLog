//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <mutex>

#include "Buffer.h"
#include "Common.h"

namespace FrameLog
{

	Buffer::Buffer()
	{
		std::lock_guard<std::mutex> lock(mtx);

		data.reserve(4096);
	}

	Buffer::~Buffer() { data.clear(); }

	Result Buffer::Add(std::string_view Text)
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

	Result Buffer::Add(const char Text)
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

	std::string Buffer::GetData()
	{
		std::lock_guard<std::mutex> lock(mtx);

		return data;
	}

	Result Buffer::Clear()
	{
		std::lock_guard<std::mutex> lock(mtx);

		data.clear();
		return Success;
	}

	Result Buffer::Clean()
	{
		std::lock_guard<std::mutex> lock(mtx);

		data.clear();
		return Success;
	}

	size_t Buffer::GetSize()
	{
		std::lock_guard<std::mutex> lock(mtx);
		return data.size();
	}
} // namespace FrameLog
