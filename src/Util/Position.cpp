#include "Util/Position.hpp"
#include "config.hpp"

namespace Util {
PTSDPosition PTSDPosition::operator+(const glm::vec2 vec2) const {
    return PTSDPosition(x + vec2.x, y + vec2.y);
}

PTSDPosition PTSDPosition::FromSDL(int sdlx, int sdly) {
    return PTSDPosition{static_cast<float>(sdlx) - WINDOW_WIDTH / 2,
                        static_cast<float>(sdly) - WINDOW_HEIGHT / 2};
}

SDLPosition PTSDPosition::ToSDLPosition() const {
    return SDLPosition(static_cast<int>(this->x + WINDOW_WIDTH / 2),
                       static_cast<int>(this->y + WINDOW_HEIGHT / 2));
}
} // namespace Util
