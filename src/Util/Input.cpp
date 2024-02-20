#include "Util/Input.hpp"

#include <SDL_events.h> // for SDL_Event

#include "config.hpp"

namespace Util {

// init all static members
SDL_Event Input::s_Event = SDL_Event();
const Uint8 *Input::s_currentKeyState = SDL_GetKeyboardState(nullptr);
std::vector<bool> Input::s_lastKeyState(512, false);

glm::vec2 Input::s_CursorPosition = glm::vec2(0.0F);
glm::vec2 Input::s_ScrollDistance = glm::vec2(-1.0F, -1.0F);

std::pair<bool, bool> Input::s_LBPressed = {false, false};
std::pair<bool, bool> Input::s_RBPressed = {false, false};
std::pair<bool, bool> Input::s_MBPressed = {false, false};

bool Input::s_Scroll = false;
bool Input::s_MouseMoving = false;
bool Input::s_Exit = false;

bool Input::IsKeyPressed(const Keycode &key) {
    const auto temp = static_cast<const int>(key);
    return s_currentKeyState[temp] != 0;
}

bool Input::IsKeyDown(const Keycode &key) {
    return s_currentKeyState[static_cast<int>(key)] &&
           !s_lastKeyState[static_cast<int>(key)];
}
bool Input::IsKeyUp(const Keycode &key) {
    return !s_currentKeyState[static_cast<int>(key)] &&
           s_lastKeyState[static_cast<int>(key)];
}

bool Input::IsLButtonPressed() {
    return s_LBPressed.second;
}
bool Input::IsLButtonDown() {
    return s_LBPressed.second && !s_LBPressed.first;
}
bool Input::IsLButtonUp() {
    return !s_LBPressed.second && s_LBPressed.first;
}

bool Input::IsRButtonPressed() {
    return s_RBPressed.second;
}
bool Input::IsRButtonDown() {
    return s_RBPressed.second && !s_RBPressed.first;
}
bool Input::IsRButtonUp() {
    return !s_RBPressed.second && s_RBPressed.first;
}
bool Input::IsMButtonPressed() {
    return s_MBPressed.second;
}

bool Input::IsMButtonDown() {
    return s_MBPressed.second && !s_MBPressed.first;
}

bool Input::IsMButtonUp() {
    return !s_MBPressed.second && s_MBPressed.first;
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

    s_LBPressed.first = s_LBPressed.second;
    s_RBPressed.first = s_RBPressed.second;
    s_MBPressed.first = s_MBPressed.second;

    for (int i = 0; i < 512; ++i) {
        s_lastKeyState[i] = s_currentKeyState[i];
    }

    while (SDL_PollEvent(&s_Event) != 0) {
        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_LBPressed.second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_LBPressed.second = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_RBPressed.second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_RBPressed.second = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MBPressed.second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MBPressed.second = true;
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
