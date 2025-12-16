//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <mutex>

#include "Common.h"
#include "Platform.h"

namespace FrameLog
{
	class Buffer
	{
		std::mutex mtx;

	public:
		FRAMELOG_API Buffer();
		FRAMELOG_API ~Buffer();

		FRAMELOG_API Result Add(std::string_view Message);
		FRAMELOG_API Result Add(const char);
		FRAMELOG_API std::string GetData();
		FRAMELOG_API Result Clear();
		FRAMELOG_API Result Clean();
		FRAMELOG_API size_t GetSize();

	private:
		std::string data;
	};
} // namespace FrameLog
