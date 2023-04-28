#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include <utility>

#include "Util/PTSDScancode.hpp"
#include <SDL_events.h>
namespace Util {

class Input {
public:
    ~Input();

    std::pair<int, int> GetScrollDistance() const;
    bool IsKeyPressed(const PTSDScancode &key) const;

    bool IsLButtonPressed() const;
    bool IsRButtonPressed() const;
    bool IsMButtonPressed() const;
    bool IfScroll() const;
    bool IsMouseMoving() const;
    bool Update();

    static Input *GetInstance();

private:
    Input() = default;

    SDL_Event m_Event;
    const Uint8 *m_KeyState = SDL_GetKeyboardState(nullptr);

    static Input *s_Instance;
};

} // namespace Util

#endif // UTIL_EVENT_HPP
