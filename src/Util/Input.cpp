#include "Util/Input.hpp"

#include <SDL_events.h> // for SDL_Event

#include "config.hpp"

namespace Util {

// init all static members
SDL_Event Input::s_Event = SDL_Event();
Util::PTSDPosition Input::s_CursorPosition = Util::PTSDPosition(0.0F, 0.0F);
glm::vec2 Input::s_ScrollDistance = glm::vec2(-1.0F, -1.0F);

std::unordered_map<Keycode, std::pair<bool, bool>> Input::s_KeyState = {
    std::make_pair(Keycode::MOUSE_LB, std::make_pair(false, false)),
    std::make_pair(Keycode::MOUSE_RB, std::make_pair(false, false)),
    std::make_pair(Keycode::MOUSE_MB, std::make_pair(false, false)),
};

bool Input::s_Scroll = false;
bool Input::s_MouseMoving = false;
bool Input::s_Exit = false;

ImGuiIO Input::s_Io; // allocate memory only because it is invalid
                     // to call `ImGui::GetIO()` at this time

bool Input::IsKeyPressed(const Keycode &key) {

    return s_KeyState[key].second;
}

bool Input::IsKeyDown(const Keycode &key) {

    return s_KeyState[key].second && !s_KeyState[key].first;
}

bool Input::IsKeyUp(const Keycode &key) {

    return !s_KeyState[key].second && s_KeyState[key].first;
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

void Input::UpdateKeyState(const SDL_Event *event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        s_KeyState[static_cast<Keycode>(512 + event->button.button)].second =
            true;
    } else if (event->type == SDL_MOUSEBUTTONUP) {
        s_KeyState[static_cast<Keycode>(512 + event->button.button)].second =
            false;
    } else if (event->type == SDL_KEYDOWN) {
        s_KeyState[static_cast<Keycode>(event->key.keysym.scancode)].second =
            true;
    } else if (event->type == SDL_KEYUP) {
        s_KeyState[static_cast<Keycode>(event->key.keysym.scancode)].second =
            false;
    }
}

void Input::Update() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    s_CursorPosition = Util::PTSDPosition::FromSDL(x, y);

    s_Scroll = s_MouseMoving = false;

    for (auto &[_, i] : s_KeyState) {
        i.first = i.second;
    }

    s_Io = ImGui::GetIO();

    while (SDL_PollEvent(&s_Event) != 0) {
        if (s_Io.WantCaptureMouse) {
            ImGui_ImplSDL2_ProcessEvent(&s_Event);
            continue;
        }
        if (s_Event.type == SDL_KEYDOWN || s_Event.type == SDL_KEYUP) {
            UpdateKeyState(&s_Event);
        } else if (s_Event.type == SDL_MOUSEBUTTONDOWN ||
                   s_Event.type == SDL_MOUSEBUTTONUP) {
            UpdateKeyState(&s_Event);
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

Util::PTSDPosition Input::GetCursorPosition() {
    return s_CursorPosition;
}

void Input::SetCursorPosition(const Util::PTSDPosition &ptsdPos) {
    auto sdlPos = ptsdPos.ToSDLPosition();
    SDL_WarpMouseInWindow(nullptr, sdlPos.x, sdlPos.y);
}

} // namespace Util
