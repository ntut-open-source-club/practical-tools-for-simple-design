#include "Util/Input.hpp"

#include <SDL_events.h> // for SDL_Event

namespace Util {

bool Input::IsKeyPressed(const PTSDScancode &key) const {
    const auto temp = static_cast<const int>(key);
    return m_KeyState[temp] != 0;
}

bool Input::IsLButtonPressed() const {
    return m_LBPressed;
}
bool Input::IsRButtonPressed() const {
    return m_RBPressed;
}
bool Input::IsMButtonPressed() const {
    return m_MBPressed;
}
bool Input::IsMouseMoving() const {
    return m_MouseMoving;
}

bool Input::IfScroll() const {
    return m_Scroll;
}
std::pair<int, int> Input::GetScrollDistance() const {
    return m_ScrollDistance;
}
void Input::Update() {
    SDL_GetMouseState(&m_CursorPosition.first, &m_CursorPosition.second);
    m_LBPressed = m_RBPressed = m_MBPressed = m_Scroll = m_MouseMoving = false;
    while (SDL_PollEvent(&m_Event) != 0) {
        m_LBPressed = (m_Event.type == SDL_MOUSEBUTTONDOWN &&
                       m_Event.button.button == SDL_BUTTON_LEFT) ||
                      m_LBPressed;
        m_RBPressed = (m_Event.type == SDL_MOUSEBUTTONDOWN &&
                       m_Event.button.button == SDL_BUTTON_RIGHT) ||
                      m_RBPressed;
        m_MBPressed = (m_Event.type == SDL_MOUSEBUTTONDOWN &&
                       m_Event.button.button == SDL_BUTTON_MIDDLE) ||
                      m_MBPressed;
        m_Scroll = m_Event.type == SDL_MOUSEWHEEL || m_Scroll;
        if (m_Scroll) {
            m_ScrollDistance.first = m_Event.wheel.x;
            m_ScrollDistance.second = m_Event.wheel.y;
        }
        m_MouseMoving = m_Event.type == SDL_MOUSEMOTION || m_MouseMoving;
    }
}

std::shared_ptr<Input> Input::s_Instance = nullptr;
std::shared_ptr<Input> Input::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance.reset(new Input());
    }
    return s_Instance;
}
std::pair<int, int> Input::GetCursorPosition() const {
    return m_CursorPosition;
}
} // namespace Util