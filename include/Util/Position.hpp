#ifndef PTSD_UTIL_POSITION_HPP
#define PTSD_UTIL_POSITION_HPP

#include <glm/glm.hpp>

struct PTSDPosition;

struct SDLPosition {
    int x {};
    int y {};
    SDLPosition() = delete;
    SDLPosition(int x, int y) : x{x}, y{y} {};
    explicit SDLPosition(PTSDPosition&&);
    explicit SDLPosition(const PTSDPosition&);

    SDLPosition operator+(const glm::vec2&&) const;
    SDLPosition operator-(const glm::vec2&& vec2) const {
        return (*this) + (vec2*(-1.0f));
    }

    PTSDPosition toPTSDPosition() const;
};

struct PTSDPosition {
    float x {};
    float y {};
    PTSDPosition() = delete;
    PTSDPosition(SDLPosition&&);
    PTSDPosition(const SDLPosition&);
    PTSDPosition(float x, float y) : x{x}, y{y} {};

    PTSDPosition operator+(const glm::vec2) const;
    PTSDPosition operator-(const glm::vec2 vec2) const {
        return (*this) + (vec2*(-1.0f));
    }
    
    SDLPosition toSDLPosition() const;
};

#include "Position.inl"

#endif /* PTSD_UTIL_POSITION_HPP */
