#include <SDL.h>
#include <SDL_events.h>
#include <utility>

#include "Util/Input.hpp"

namespace Util {

bool Input::IsKeyPressed(const PTSDScancode &key) const {
    const auto temp = static_cast<const int>(key);
    return m_KeyState[temp] != 0;
}

bool Input::IsLButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_LEFT;
}
bool Input::IsRButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_RIGHT;
}
bool Input::IsMButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_MIDDLE;
}
bool Input::IsMouseMoving() const {
    return m_Event.type == SDL_MOUSEMOTION;
}

bool Input::IfScroll() const {
    return m_Event.type == SDL_MOUSEWHEEL;
}
std::pair<int, int> Input::GetScrollDistance() const {
    if (IfScroll()) {
        return {m_Event.wheel.x, m_Event.wheel.y};
    }
    return {0, 0};
}
bool Input::Update() {
    return SDL_PollEvent(&m_Event) != 0;
}
Input* Input::s_Instance = nullptr;
Input *Input::GetInstance() {
    if (s_Instance == nullptr){
        s_Instance = new Input();
    }
    return s_Instance;
}
Input::~Input() {
    delete s_Instance;
}
} // namespace Util