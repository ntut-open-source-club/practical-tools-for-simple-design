#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include <utility> // for std::pair

#include "Util/PTSDScancode.hpp"
#include <SDL_events.h>

namespace Util {

class Input {
public:
    static std::pair<int, int> GetScrollDistance();
    static bool IsKeyPressed(const PTSDScancode &key);
    static bool IsLButtonPressed();
    static bool IsRButtonPressed();
    static bool IsMButtonPressed();
    static bool IfScroll();
    static bool IsMouseMoving();

    static bool Update();

private:
    static SDL_Event s_Event;
    static const Uint8 *s_KeyState;
};

} // namespace Util

#endif // UTIL_EVENT_HPP
