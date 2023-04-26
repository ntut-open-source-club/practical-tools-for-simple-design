#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include <utility>

#include <SDL_events.h>
#include "Util/PTSDScancode.hpp"
namespace Util {

class Event {
public:
    ~Event() = default;
    bool IsKeyPressed(const PTSDScancode &key) const;
    bool IsLButtonPressed() const;
    bool IsRButtonPressed() const;
    bool IsMButtonPressed() const;
    bool IfScrolling() const;
    bool IsMouseMoving() const;
    std::pair<int, int> GetScrollDistance() const;
    bool Poll();

private:
    SDL_Event m_Event;
    const Uint8 *m_KeyState = SDL_GetKeyboardState(nullptr);

};

} // namespace Util

#endif // UTIL_EVENT_HPP
