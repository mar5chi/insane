#pragma once

#include <memory>  // Shared ptr

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Insane {

	class INSANE_API Log
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
#define IS_CORE_TRACE(...)	::Insane::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IS_CORE_INFO(...)	::Insane::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IS_CORE_WARN(...)	::Insane::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IS_CORE_ERROR(...)	::Insane::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IS_CORE_FATAL(...)	::Insane::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define IS_TRACE(...)		::Insane::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IS_INFO(...)		::Insane::Log::GetClientLogger()->info(__VA_ARGS__)
#define IS_WARN(...)		::Insane::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IS_ERROR(...)		::Insane::Log::GetClientLogger()->error(__VA_ARGS__)
#define IS_FATAL(...)		::Insane::Log::GetClientLogger()->critical(__VA_ARGS__)
