#ifndef PTSD_UTIL_POSITION_HPP
#define PTSD_UTIL_POSITION_HPP

#include <glm/glm.hpp>

namespace Util {

struct PTSDPosition;

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

struct PTSDPosition {
    float x{};
    float y{};
    PTSDPosition() = delete;
    static PTSDPosition FromSDL(int sdlx, int sdly);
    PTSDPosition(float x, float y)
        : x{x},
          y{y} {};
    [[deprecated("Implicit conversion will be removed. Use explicit conversion "
                 "instead")]] // `\_(:/)_/`
    PTSDPosition(glm::vec2 v)
        : x{v.x},
          y{v.y} {};

    PTSDPosition operator+(const glm::vec2) const;
    PTSDPosition operator-(const glm::vec2 vec2) const {
        return (*this) + (vec2 * (-1.0f));
    }

    [[deprecated("Implicit conversion will be removed. Use explicit conversion "
                 "instead")]]
    operator glm::vec2() const {
        return {x, y};
    }

    SDLPosition ToSDLPosition() const;
};

} // namespace Util

#include "Position.inl"

#endif /* PTSD_UTIL_POSITION_HPP */
