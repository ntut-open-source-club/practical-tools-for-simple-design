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

/*
 * I have no idea what this does
 *
 * Credit to: https://github.com/fmtlib/fmt/issues/3306#issuecomment-1432711988
 */
// NOLINTBEGIN
template <glm::length_t L, typename Pre>
struct fmt::formatter<glm::vec<L, Pre>> : fmt::formatter<Pre> {
    auto format(const glm::vec<L, Pre> &vec, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "{}", glm::to_string(vec));
    }
};

template <glm::length_t C, glm::length_t R, typename Pre>
struct fmt::formatter<glm::mat<C, R, Pre>> : fmt::formatter<Pre> {
    auto format(const glm::mat<C, R, Pre> &mat, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "{}", glm::to_string(mat));
    }
};

template <>
struct fmt::formatter<Util::Transform> : fmt::formatter<std::string> {
    auto format(const Util::Transform &t, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "T: {} R: {} rad S: {}", t.translation,
                         t.rotation, t.scale);
    }
};
// NOLINTEND

#endif
