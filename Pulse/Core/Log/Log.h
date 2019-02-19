#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Ps {

	class Log
	{
	public:
		static void init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("PULSE");
			s_CoreLogger->set_level(spdlog::level::trace);

			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
		
		static inline std::shared_ptr<spdlog::logger>&		getCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>&		getClientLogger() { return s_ClientLogger; }

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
	#define PS_CORE_TRACE(...)    ::Ps::Log::getCoreLogger()->trace(__VA_ARGS__)
	#define PS_CORE_INFO(...)     ::Ps::Log::getCoreLogger()->info(__VA_ARGS__)
	#define PS_CORE_WARN(...)     ::Ps::Log::getCoreLogger()->warn(__VA_ARGS__)
	#define PS_CORE_ERROR(...)    ::Ps::Log::getCoreLogger()->error(__VA_ARGS__)
	#define PS_CORE_CRITICAL(...) ::Ps::Log::getCoreLogger()->critical(__VA_ARGS__)
#endif

// Client log macros
#ifdef RELEASE
	#define PS_TRACE(...)	      
	#define PS_INFO(...)	      
	#define PS_WARN(...)	      
	#define PS_ERROR(...)
	#define PS_CRITICAL(...)
#else
	#define PS_TRACE(...)	      ::Ps::Log::getClientLogger()->trace(__VA_ARGS__)
	#define PS_INFO(...)	      ::Ps::Log::getClientLogger()->info(__VA_ARGS__)
	#define PS_WARN(...)	      ::Ps::Log::getClientLogger()->warn(__VA_ARGS__)
	#define PS_ERROR(...)	      ::Ps::Log::getClientLogger()->error(__VA_ARGS__)
	#define PS_CRITICAL(...)	  ::Ps::Log::getClientLogger()->critical(__VA_ARGS__)
#endif