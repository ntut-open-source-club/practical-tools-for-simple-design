#include "Util/Input.hpp"

#include <SDL_events.h> // for SDL_Event

#include "config.hpp"

namespace Util {

// init all static members
SDL_Event Input::s_Event = SDL_Event();
const Uint8 *Input::s_CurrentKeyState = SDL_GetKeyboardState(nullptr);
std::unordered_map<int, bool> Input::s_LastKeyState = {};

glm::vec2 Input::s_CursorPosition = glm::vec2(0.0F);
glm::vec2 Input::s_ScrollDistance = glm::vec2(-1.0F, -1.0F);

std::unordered_map<Keycode, std::pair<bool, bool>> Input::s_MouseState = {
    std::make_pair(Keycode::MOUSE_LB, std::make_pair(false, false)),
    std::make_pair(Keycode::MOUSE_RB, std::make_pair(false, false)),
    std::make_pair(Keycode::MOUSE_MB, std::make_pair(false, false)),
};

bool Input::s_Scroll = false;
bool Input::s_MouseMoving = false;
bool Input::s_Exit = false;

bool Input::IsKeyPressed(const Keycode &key) {
    if (key > Keycode::NUM_SCANCODES) {
        return s_MouseState[key].second; // && !s_MouseState[key].first;
    }

    const auto index = static_cast<const int>(key);
    return s_CurrentKeyState[index] != 0 && s_LastKeyState[index] != 0;
}

bool Input::IsKeyDown(const Keycode &key) {
    if (key > Keycode::NUM_SCANCODES) {
        return s_MouseState[key].second && !s_MouseState[key].first;
    }

    const auto index = static_cast<const int>(key);
    return s_CurrentKeyState[index] != 0 && s_LastKeyState[index] == 0;
}

bool Input::IsKeyUp(const Keycode &key) {
    if (key > Keycode::NUM_SCANCODES) {
        return s_MouseState[key].second && !s_MouseState[key].first;
    }

    const auto index = static_cast<const int>(key);
    return s_CurrentKeyState[index] == 0 && s_LastKeyState[index] != 0;
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

    for (int i = 0; i < 512; ++i) {
        s_LastKeyState[i] = s_CurrentKeyState[i];
    }

    s_MouseState[Keycode::MOUSE_LB].first =
        s_MouseState[Keycode::MOUSE_LB].second;

    s_MouseState[Keycode::MOUSE_RB].first =
        s_MouseState[Keycode::MOUSE_RB].second;

    s_MouseState[Keycode::MOUSE_MB].first =
        s_MouseState[Keycode::MOUSE_MB].second;

    while (SDL_PollEvent(&s_Event) != 0) {
        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_MouseState[Keycode::MOUSE_LB].second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_LEFT) {
            s_MouseState[Keycode::MOUSE_LB].second = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_MouseState[Keycode::MOUSE_RB].second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_RIGHT) {
            s_MouseState[Keycode::MOUSE_RB].second = true;
        }

        if (s_Event.type == SDL_MOUSEBUTTONUP &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MouseState[Keycode::MOUSE_MB].second = false;
        }
        if (s_Event.type == SDL_MOUSEBUTTONDOWN &&
            s_Event.button.button == SDL_BUTTON_MIDDLE) {
            s_MouseState[Keycode::MOUSE_MB].second = true;
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
