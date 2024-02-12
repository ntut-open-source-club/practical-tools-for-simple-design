#ifndef UTIL_LOGGER_HPP
#define UTIL_LOGGER_HPP

#include "pch.hpp" // IWYU pragma: export

#include <spdlog/spdlog.h>

#include "Util/Transform.hpp"

namespace Util::Logger {
/**
 * @enum Level
 * @brief Enum representing the logging levels.
 *
 * This enum encapsulates the different levels of logging.
 */
enum class Level {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL,
};

/**
 * @brief Initializes the logger.
 *
 * This function initializes the logger for the application.
 */
void Init();

/**
 * @brief Sets the logging level.
 *
 * This function sets the logging level for the application.
 * Logging levels are TRACE, DEBUG, INFO, WARN, ERROR, and CRITICAL.
 * @note If the current log's level is lower than the set level, the log will
 * be omitted.
 *
 * @param level The new logging level.
 */
void SetLevel(Level level);

/**
 * @brief Gets the current logging level.
 *
 * This function returns the current logging level of the application.
 *
 * @return The current logging level.
 */
Level GetLevel();

#define LOG_TRACE(...) spdlog::trace(__VA_ARGS__)
#define LOG_DEBUG(...) spdlog::debug(__VA_ARGS__)
#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
} // namespace Util::Logger

template <>
struct fmt::formatter<Util::Transform> : fmt::formatter<std::string> {
    auto format(Util::Transform t, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "T: {} R: {} rad S: {}",
                         glm::to_string(t.translation), t.rotation,
                         glm::to_string(t.scale));
    }
};

#endif
