#ifndef PTSD_UTIL_POSITION_HPP
#define PTSD_UTIL_POSITION_HPP

#include <glm/glm.hpp>

namespace Util {

struct PTSDPosition;

/**
 * @struct SDLPosition
 * @brief A class representing a position in screen coordinates.
 *
 * This class is used to store the X and Y coordinates of a point in a screen
 * coordinate system where:
 * - The origin (0, 0) is at the upper-left corner of the window.
 * - X increases to the right.
 * - Y increases downwards.
 */
struct SDLPosition {
public:
    const int x;
    const int y;
    SDLPosition() = delete;

private:
    friend PTSDPosition;
    SDLPosition(float x, float y)
        : x(x),
          y(y) {}
};

/**
 * @struct PTSDPosition
 * @brief A class representing a position in a Cartesian coordinates.
 *
 * This class is used to store the X and Y coordinates of a point in a Cartesian
 * coordinate system where:
 * - The origin (0, 0) is at the center of the window.
 * - X increases to the right.
 * - Y increases upwards.
 */
struct PTSDPosition {
    float x{};
    float y{};
    PTSDPosition() = delete;
    static PTSDPosition FromSDL(int sdlx, int sdly);
    PTSDPosition(float x, float y)
        : x{x},
          y{y} {};
    [[deprecated("Implicit conversion will be removed. Use explicit conversion "
                 "instead")]]
    // `\_(:/)_/`
    PTSDPosition(glm::vec2 v)
        : x{v.x},
          y{v.y} {};

    PTSDPosition operator+(const glm::vec2) const;
    PTSDPosition operator-(const glm::vec2 vec2) const {
        return (*this) + (vec2 * (-1.0f));
    }

    [[deprecated("Implicit conversion will be removed. Use explicit conversion "
                 "instead")]] //
    operator glm::vec2() const {
        return {x, y};
    }

    SDLPosition ToSDLPosition() const;
};

} // namespace Util

#include "Position.inl"

#endif /* PTSD_UTIL_POSITION_HPP */
