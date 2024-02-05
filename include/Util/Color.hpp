#ifndef UTIL_COLOR_HPP
#define UTIL_COLOR_HPP

#include "pch.hpp" // IWYU pragma: export

#include <SDL2/SDL_pixels.h>

namespace Util {
class Color : public glm::vec4 {
public:
    using glm::vec4::vec;

    Color(const glm::vec4 &vec)
        : glm::vec4(vec) {}
    Color(glm::vec4 &&vec)
        : glm::vec4(std::move(vec)) {}

    Color(const SDL_Color &color)
        : glm::vec4({
              static_cast<float>(color.r) / 255.0F,
              static_cast<float>(color.g) / 255.0F,
              static_cast<float>(color.b) / 255.0F,
              static_cast<float>(color.a) / 255.0F,
          }) {}

    SDL_Color ToSdlColor() const {
        return SDL_Color{
            static_cast<Uint8>(r * 255),
            static_cast<Uint8>(g * 255),
            static_cast<Uint8>(b * 255),
            static_cast<Uint8>(a * 255),
        };
    }
};
} // namespace Util

#endif
