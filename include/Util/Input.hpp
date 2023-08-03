#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <SDL_events.h> // for SDL_Event
#include <SDL_stdinc.h> // for Uint8

#include "Util/Keycode.hpp" // for Keycode

namespace Util {

class Input {
public:
    static std::shared_ptr<Input> GetInstance();

    glm::vec2 GetScrollDistance() const;

    glm::vec2 GetCursorPosition() const;
    bool IsKeyPressed(const Keycode &key) const;
    bool IsLButtonPressed() const;
    bool IsRButtonPressed() const;
    bool IsMButtonPressed() const;
    bool IfScroll() const;

    bool IsMouseMoving() const;

    void Update();

private:
    Input() = default;

    static std::shared_ptr<Input> s_Instance;

    SDL_Event m_Event;

    const Uint8 *m_KeyState = SDL_GetKeyboardState(nullptr);
    glm::vec2 m_CursorPosition = {-1, -1};

    glm::vec2 m_ScrollDistance = {0, 0};
    bool m_LBPressed = false;
    bool m_RBPressed = false;
    bool m_MBPressed = false;
    bool m_Scroll = false;

    bool m_MouseMoving = false;
};

} // namespace Util

#endif // UTIL_EVENT_HPP
