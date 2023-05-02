#include <utility> // for std::pair

#include <SDL_events.h>

#include "Util/Input.hpp"

namespace Util {

bool Input::IsKeyPressed(const PTSDScancode &key)  {
    const auto temp = static_cast<const int>(key);
    return s_KeyState[temp] != 0;
}

bool Input::IsLButtonPressed()  {
    return s_Event.type == SDL_MOUSEBUTTONDOWN &&
           s_Event.button.button == SDL_BUTTON_LEFT;
}
bool Input::IsRButtonPressed()  {
    return s_Event.type == SDL_MOUSEBUTTONDOWN &&
           s_Event.button.button == SDL_BUTTON_RIGHT;
}
bool Input::IsMButtonPressed()  {
    return s_Event.type == SDL_MOUSEBUTTONDOWN &&
           s_Event.button.button == SDL_BUTTON_MIDDLE;
}
bool Input::IsMouseMoving()  {
    return s_Event.type == SDL_MOUSEMOTION;
}

bool Input::IfScroll()  {
    return s_Event.type == SDL_MOUSEWHEEL;
}
std::pair<int, int> Input::GetScrollDistance()  {
    if (IfScroll()) {
        return {s_Event.wheel.x, s_Event.wheel.y};
    }
    return {0, 0};
}
bool Input::Update() {
    return SDL_PollEvent(&s_Event) != 0;
}

SDL_Event Input::s_Event = SDL_Event();
const Uint8 *Input::s_KeyState = SDL_GetKeyboardState(nullptr);
} // namespace Util