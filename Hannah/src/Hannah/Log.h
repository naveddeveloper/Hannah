#pragma once

#include "spdlog/spdlog.h"
#include "Core.h"
#include <memory>
 
namespace Hannah {
	class HANNAH_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static  std::shared_ptr<spdlog::logger> s_CoreLogger;
		static  std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define HN_CORE_TRACE(...)  ::Hannah::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define HN_CORE_INFO(...)   ::Hannah::Log::GetCoreLogger()->info(__VA_ARGS__);
#define HN_CORE_WARN(...)   ::Hannah::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define HN_CORE_ERROR(...)  ::Hannah::Log::GetCoreLogger()->error(__VA_ARGS__);
#define HN_CORE_FATAL(...)  ::Hannah::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client Log Macros
#define HN_TRACE(...)  ::Hannah::Log::GetClientLogger()->trace(__VA_ARGS__);
#define HN_INFO(...)   ::Hannah::Log::GetClientLogger()->info(__VA_ARGS__);
#define HN_WARN(...)   ::Hannah::Log::GetClientLogger()->warn(__VA_ARGS__);
#define HN_ERROR(...)  ::Hannah::Log::GetClientLogger()->error(__VA_ARGS__);
#define HN_FATAL(...)  ::Hannah::Log::GetClientLogger()->fatal(__VA_ARGS__);