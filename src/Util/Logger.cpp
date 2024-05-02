#include "Util/Logger.hpp"

#include "config.hpp"

namespace Util {
void Logger::Init() {
    spdlog::set_pattern("%n [%^%l%$] %v");
    SetLevel(Level::INFO);
}

void Logger::SetLevel(Logger::Level level) {
    spdlog::set_level(static_cast<spdlog::level::level_enum>(level));
}

Logger::Level GetLevel() {
    return static_cast<Logger::Level>(spdlog::get_level());
}
} // namespace Util
