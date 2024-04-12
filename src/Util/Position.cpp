#include "Util/Position.hpp"
#include "config.hpp"

namespace Util {

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

PTSDPosition::PTSDPosition(const SDLPosition &sdlPos) :
    x(static_cast<float>(sdlPos.x) - WINDOW_WIDTH/2),
    y(static_cast<float>(sdlPos.y) - WINDOW_HEIGHT/2) {}

PTSDPosition::PTSDPosition(SDLPosition &&sdlPos) :
    PTSDPosition(sdlPos) {}

SDLPosition PTSDPosition::toSDLPosition() const {
    return SDLPosition(*this);
}

SDLPosition::SDLPosition(const PTSDPosition &ptsdPos)  :
    x(ptsdPos.x + WINDOW_WIDTH/2),
    y(ptsdPos.y + WINDOW_HEIGHT/2) {}
    
SDLPosition::SDLPosition(PTSDPosition &&ptsdPos)  :
    SDLPosition(ptsdPos) {}

PTSDPosition SDLPosition::toPTSDPosition() const {
    return PTSDPosition(*this);
}

} // namespace Util
