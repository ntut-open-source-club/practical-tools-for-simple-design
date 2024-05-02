#include "Util/Position.hpp"

#include <spdlog/spdlog.h>

template <>
struct fmt::formatter<Util::PTSDPosition> : fmt::formatter<std::string> {
    auto format(const Util::PTSDPosition &p, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "PTSDPos ({}, {})", p.x, p.y);
    }
};
