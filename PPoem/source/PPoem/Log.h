#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace PPoem {
	class PPOEM_API Log
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

// Coure Log
#define PP_CORE_TRACE(...)      ::PPoem::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PP_CORE_INFO(...)       ::PPoem::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PP_CORE_WARN(...)       ::PPoem::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PP_CORE_ERROR(...)      ::PPoem::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PP_CORE_FATAL(...)      ::PPoem::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log
#define PP_TRACE(...)    ::PPoem::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PP_INFO(...)     ::PPoem::Log::GetClientLogger()->info(__VA_ARGS__)
#define PP_WARN(...)     ::PPoem::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PP_ERROR(...)    ::PPoem::Log::GetClientLogger()->error(__VA_ARGS__)
#define PP_FATAL(...)    ::PPoem::Log::GetClientLogger()->fatal(__VA_ARGS__)



