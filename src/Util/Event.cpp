#include <SDL.h>
#include <SDL_events.h>
#include <utility>

#include "Util/Event.hpp"

namespace Util {

bool Event::IsKeyPressed(const PTSDScancode &key) const {
    const auto temp = static_cast<const int>(key);
    return m_KeyState[temp] != 0;
}

bool Event::IsLButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_LEFT;
}
bool Event::IsRButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_RIGHT;
}
bool Event::IsMButtonPressed() const {
    return m_Event.type == SDL_MOUSEBUTTONDOWN && m_Event.button.button == SDL_BUTTON_MIDDLE;
}
bool Event::IsMouseMoving() const {
    return m_Event.type == SDL_MOUSEMOTION;
}

bool Event::IfScrolling() const {
    return m_Event.type == SDL_MOUSEWHEEL;
}
std::pair<int, int> Event::GetScrollDistance() const {
    if (IfScrolling()) {
        return {m_Event.wheel.x, m_Event.wheel.y};
    }
    return {0, 0};
}
bool Event::Poll() {
    return SDL_PollEvent(&m_Event) != 0;
}
} // namespace Util