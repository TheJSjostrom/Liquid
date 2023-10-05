#pragma once
#include "spdlog/spdlog.h"
#include "Core.h"
#include "spdlog/fmt/ostr.h"

namespace Liquid {

	class LIQUID_API Log
	{
	
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define LQ_CORE_TRACE(...)   ::Liquid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LQ_CORE_INFO(...)    ::Liquid::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LQ_CORE_WARN(...)    ::Liquid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LQ_CORE_ERROR(...)   ::Liquid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LQ_CORE_FATAL(...)   ::Liquid::Log::GetCoreLogger()->fatal(__VA_ARGS__)
 
// Client log macros
#define LQ_TRACE(...)        ::Liquid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LQ_INFO(...)         ::Liquid::Log::GetClientLogger()->info(__VA_ARGS__)
#define LQ_WARN(...)         ::Liquid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LQ_ERROR(...)        ::Liquid::Log::GetClientLogger()->error(__VA_ARGS__)
#define LQ_FATAL(...)        ::Liquid::Log::GetClientLogger()->fatal(__VA_ARGS__)