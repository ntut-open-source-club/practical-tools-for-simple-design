#include "Util/Position.hpp"
#include "config.hpp"

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
