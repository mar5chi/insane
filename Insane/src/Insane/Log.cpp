#include "ispch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Insane {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		// Set the pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");  // (color [timestamp] name of logger: log message)
		s_CoreLogger = spdlog::stdout_color_mt("INSANE");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
