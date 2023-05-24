#ifndef UTIL_LOGGER_HPP
#define UTIL_LOGGER_HPP

#include "pch.hpp" // IWYU pragma: export

#include <spdlog/spdlog.h>

namespace Util::Logger {
enum class Level {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL,
};

void Init();

void SetLevel(Level level);
Level GetLevel();

#define LOG_TRACE(...) spdlog::trace(__VA_ARGS__)
#define LOG_DEBUG(...) spdlog::debug(__VA_ARGS__)
#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
} // namespace Util::Logger

#endif
