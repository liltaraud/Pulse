#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Ps {

	class Log
	{
	public:
		static void Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("PULSE");
			s_CoreLogger->set_level(spdlog::level::trace);

			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
		
		static inline std::shared_ptr<spdlog::logger>&		GetCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>&		GetClientLogger() { return s_ClientLogger; }

	private:
		static inline std::shared_ptr<spdlog::logger>	s_CoreLogger;
		static inline std::shared_ptr<spdlog::logger>	s_ClientLogger;
	};


}

// Core log macros
#ifdef RELEASE
	#define PS_CORE_TRACE(...)
	#define PS_CORE_INFO(...)
	#define PS_CORE_WARN(...)
	#define PS_CORE_ERROR(...)
	#define PS_CORE_CRITICAL(...) 
#else
	#define PS_CORE_TRACE(...)    ::Ps::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define PS_CORE_INFO(...)     ::Ps::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define PS_CORE_WARN(...)     ::Ps::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define PS_CORE_ERROR(...)    ::Ps::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define PS_CORE_CRITICAL(...) ::Ps::Log::GetCoreLogger()->critical(__VA_ARGS__)
#endif

// Client log macros
#ifdef RELEASE
	#define PS_TRACE(...)	      
	#define PS_INFO(...)	      
	#define PS_WARN(...)	      
	#define PS_ERROR(...)
	#define PS_CRITICAL(...)
#else
	#define PS_TRACE(...)	      ::Ps::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define PS_INFO(...)	      ::Ps::Log::GetClientLogger()->info(__VA_ARGS__)
	#define PS_WARN(...)	      ::Ps::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define PS_ERROR(...)	      ::Ps::Log::GetClientLogger()->error(__VA_ARGS__)
	#define PS_CRITICAL(...)	  ::Ps::Log::GetClientLogger()->critical(__VA_ARGS__)
#endif