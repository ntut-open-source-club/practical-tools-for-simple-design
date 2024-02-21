#include "Util/Input.hpp"

#include "config.hpp"
#include <SDL_events.h> // for SDL_Event

namespace Util {

// init all static members
SDL_Event Input::s_Event = SDL_Event();
const Uint8 *Input::s_KeyState = SDL_GetKeyboardState(nullptr);
glm::vec2 Input::s_CursorPosition = glm::vec2(0.0F);
glm::vec2 Input::s_ScrollDistance = glm::vec2(-1.0F, -1.0F);
bool Input::s_LBPressed = false;
bool Input::s_RBPressed = false;
bool Input::s_MBPressed = false;
bool Input::s_Scroll = false;
bool Input::s_MouseMoving = false;
bool Input::s_Exit = false;

bool Input::IsKeyPressed(const Keycode &key) {
    const auto temp = static_cast<const int>(key);
    return s_KeyState[temp] != 0;
}

bool Input::IsLButtonDown() {
    return s_LBPressed;
}
bool Input::IsRButtonDown() {
    return s_RBPressed;
}
bool Input::IsMButtonDown() {
    return s_MBPressed;
}
bool Input::IsMouseMoving() {
    return s_MouseMoving;
}

bool Input::IfScroll() {
    return s_Scroll;
}

bool Input::IfExit() {
    return s_Exit;
}

glm::vec2 Input::GetScrollDistance() {
    return s_ScrollDistance;
}

void Input::Update() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    s_CursorPosition.x = static_cast<float>(x);
    s_CursorPosition.y = static_cast<float>(y);

    s_CursorPosition.x -= static_cast<float>(WINDOW_WIDTH) / 2;
    s_CursorPosition.y =
        -(s_CursorPosition.y - static_cast<float>(WINDOW_HEIGHT) / 2);

    s_Scroll = s_MouseMoving = false;

    while (SDL_PollEvent(&s_Event) != 0) {
        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_LBPressed = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_LBPressed = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_RBPressed = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_RBPressed = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MBPressed = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MBPressed = true;
        }

        s_Scroll = s_Event.type == SDL_MOUSEWHEEL || s_Scroll;

        if (s_Scroll) {
            s_ScrollDistance.x = static_cast<float>(s_Event.wheel.x);
            s_ScrollDistance.y = static_cast<float>(s_Event.wheel.y);
        }
        s_MouseMoving = s_Event.type == SDL_MOUSEMOTION || s_MouseMoving;
        s_Exit = s_Event.type == SDL_QUIT;
    }
}

glm::vec2 Input::GetCursorPosition() {
    return s_CursorPosition;
}

void Input::SetCursorPosition(const glm::vec2 &pos) {
    SDL_WarpMouseInWindow(nullptr, static_cast<int>(pos.x),
                          static_cast<int>(pos.y));
}
} // namespace Util
