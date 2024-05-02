#include "Util/Position.hpp"
#include "config.hpp"

namespace Util {
PTSDPosition PTSDPosition::operator+(const glm::vec2 vec2) const {
    return PTSDPosition(x + vec2.x, y + vec2.y);
}

PTSDPosition PTSDPosition::FromSDL(int sdlx, int sdly) {
    return PTSDPosition{
        static_cast<float>(sdlx) -
            static_cast<float>(PTSD_Config::WINDOW_WIDTH) / 2.0F,
        static_cast<float>(sdly) -
            static_cast<float>(PTSD_Config::WINDOW_HEIGHT) / 2.0F};
}

SDLPosition PTSDPosition::ToSDLPosition() const {
    return SDLPosition(
        static_cast<int>(this->x +
                         static_cast<float>(PTSD_Config::WINDOW_WIDTH) / 2.0F),
        static_cast<int>(
            this->y + static_cast<float>(PTSD_Config::WINDOW_HEIGHT) / 2.0F));
}
} // namespace Util
