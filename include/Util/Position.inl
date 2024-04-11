#include "Util/AssetStore.hpp"

#include <spdlog/spdlog.h>

template <>
struct fmt::formatter<PTSDPosition> : fmt::formatter<std::string> {
    auto format(const PTSDPosition &p, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "PTSDPos ({}, {})", p.x, p.y);
    }
};

template <>
struct fmt::formatter<SDLPosition> : fmt::formatter<std::string> {
    auto format(const SDLPosition &p, format_context &ctx) const
        -> decltype(ctx.out()) {
        return format_to(ctx.out(), "SDLPos ({}, {})", p.x, p.y);
    }
};
