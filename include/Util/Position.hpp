#ifndef PTSD_UTIL_POSITION_HPP
#define PTSD_UTIL_POSITION_HPP

#include <glm/glm.hpp>

namespace Util {

struct PTSDPosition;

struct SDLPosition {
    int x{};
    int y{};
    SDLPosition() = delete;
    SDLPosition(int x, int y)
        : x{x},
          y{y} {};
    explicit SDLPosition(PTSDPosition &&);
    explicit SDLPosition(const PTSDPosition &);
    explicit SDLPosition(const glm::vec2 &v)
        : x(static_cast<int>(v.x)),
          y(static_cast<int>(v.y)) {}

    explicit operator glm::vec2() const { return {x, y}; }

    SDLPosition operator+(const glm::vec2 &&) const;
    SDLPosition operator-(const glm::vec2 &&vec2) const {
        return (*this) + (vec2 * (-1.0f));
    }

    PTSDPosition toPTSDPosition() const;
};

struct PTSDPosition {
    float x{};
    float y{};
    PTSDPosition() = delete;
    PTSDPosition(SDLPosition &&);
    PTSDPosition(const SDLPosition &);
    PTSDPosition(float x, float y)
        : x{x},
          y{y} {};
    [[deprecated("Implicit conversion will be removed. Use explicit conversion "
                 "instead")]] // clang-format would remove this newline ==
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

    SDLPosition toSDLPosition() const;
};

} // namespace Util

#include "Position.inl"

#endif /* PTSD_UTIL_POSITION_HPP */
