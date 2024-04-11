#include "Util/Position.hpp"
#include "config.hpp"

SDLPosition SDLPosition::operator+(const glm::vec2 && vec2) const {
    return SDLPosition(
        x + vec2.x,
        y + vec2.y
    );
}

PTSDPosition PTSDPosition::operator+(const glm::vec2 vec2) const {
    return PTSDPosition(
        x + vec2.x,
        y + vec2.y
    );
}

SDLPosition PTSDPosition::toSDLPosition() const {
    return SDLPosition(
        x + WINDOW_WIDTH/2,
        y + WINDOW_HEIGHT/2
    );
}

PTSDPosition SDLPosition::toPTSDPosition() const {
    return PTSDPosition(
        (float)x - WINDOW_WIDTH/2,
        (float)y - WINDOW_HEIGHT/2
    );
}

PTSDPosition::PTSDPosition(SDLPosition && sdlPos) :
        x((float)sdlPos.x - WINDOW_WIDTH/2),
        y((float)sdlPos.y - WINDOW_HEIGHT/2) {}

PTSDPosition::PTSDPosition(const SDLPosition & sdlPos) :
    x((float)sdlPos.x - WINDOW_WIDTH/2),
    y((float)sdlPos.y - WINDOW_HEIGHT/2) {}

SDLPosition::SDLPosition(PTSDPosition && ptsdPos)  :
    x(ptsdPos.x + WINDOW_WIDTH/2),
    y(ptsdPos.y + WINDOW_HEIGHT/2) {}

SDLPosition::SDLPosition(const PTSDPosition & ptsdPos)  :
    x(ptsdPos.x + WINDOW_WIDTH/2),
    y(ptsdPos.y + WINDOW_HEIGHT/2) {}
