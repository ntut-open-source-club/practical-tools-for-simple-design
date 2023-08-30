#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <SDL_events.h> // for SDL_Event
#include <SDL_stdinc.h> // for Uint8

#include "Util/Keycode.hpp" // for Keycode

namespace Util {

class Input {
public:
    Input() = delete;
    ~Input() = delete;

    static glm::vec2 GetScrollDistance();
    static glm::vec2 GetCursorPosition();

    static bool IsKeyPressed(const Keycode &key);
    static bool IsLButtonPressed();
    static bool IsRButtonPressed();
    static bool IsMButtonPressed();
    static bool IfScroll();

    static bool IsMouseMoving();

    static void Update();

private:
    static SDL_Event s_Event;

    static const Uint8 *s_KeyState;
    static glm::vec2 s_CursorPosition;

    static glm::vec2 s_ScrollDistance;
    static bool s_LBPressed;
    static bool s_RBPressed;
    static bool s_MBPressed;
    static bool s_Scroll;
    static bool s_MouseMoving;
};

} // namespace Util

#endif // UTIL_EVENT_HPP
