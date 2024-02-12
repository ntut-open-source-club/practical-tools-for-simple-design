#ifndef UTIL_COLOR_HPP
#define UTIL_COLOR_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Util {
/**
 * @class Color
 * @brief A class representing a color.
 *
 * This class is an extend of glm::vec4. It provides functionalities to
 * convert from and to SDL_Color format.
 */
class Color : public glm::vec4 {
public:
    using glm::vec4::vec;

    /*
     * @brief Parameterized constructor.
     *
     * @param vec The color in glm::vec4 format.
     */
    Color(const glm::vec4 &vec)
        : glm::vec4(vec) {}

    /*
     * @brief Parameterized constructor.
     */
    Color(glm::vec4 &&vec)
        : glm::vec4(std::move(vec)) {}

    /*
     * @brief Parameterized constructor.
     *
     * @param color The color in SDL_Color format.
     */
    Color(const SDL_Color &color)
        : glm::vec4({
              static_cast<float>(color.r) / 255.0F,
              static_cast<float>(color.g) / 255.0F,
              static_cast<float>(color.b) / 255.0F,
              static_cast<float>(color.a) / 255.0F,
          }) {}

    /**
     * @brief Converts the color to SDL_Color format.
     *
     * @return The color in SDL_Color format.
     */
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
