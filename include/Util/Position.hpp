#ifndef PTSD_UTIL_POSITION_HPP
#define PTSD_UTIL_POSITION_HPP

#include "config.hpp"

struct PTSDPosition;

struct SDLPosition {
    int x {};
    int y {};
    SDLPosition() = delete;
    SDLPosition(int x, int y) : x{x}, y{y} {};

    SDLPosition operator+(const glm::vec2 && vec2) const {
        return SDLPosition(
            x + vec2.x,
            y + vec2.y
        );
    }
    SDLPosition operator-(const glm::vec2 && vec2) const {
        return (*this) + (vec2*(-1.0f));
    }

    PTSDPosition toPTSDPosition() const;
    // friend PTSDPosition toPTSDPosition(SDLPosition const& self) const;
};

struct PTSDPosition {
    float x {};
    float y {};
    PTSDPosition() = delete;
    PTSDPosition(const SDLPosition && sdlPos) :
        x((float)sdlPos.x - WINDOW_WIDTH/2),
        y((float)sdlPos.y - WINDOW_HEIGHT/2) {}
    PTSDPosition(const SDLPosition sdlPos) :
        x((float)sdlPos.x - WINDOW_WIDTH/2),
        y((float)sdlPos.y - WINDOW_HEIGHT/2) {}
    PTSDPosition(float x, float y) : x{x}, y{y} {};

    PTSDPosition operator+(const glm::vec2 vec2) const {
        return PTSDPosition(
            x + vec2.x,
            y + vec2.y
        );
    }
    PTSDPosition operator-(const glm::vec2 vec2) const {
        return (*this) + (vec2*(-1.0f));
    }
    
    SDLPosition toSDLPosition() const;
};

#endif /* PTSD_UTIL_POSITION_HPP */
