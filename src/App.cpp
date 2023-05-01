#include "App.hpp"

#include <SDL.h>

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    // TODO: Wrap this into Core
    if (m_KeyState[SDL_SCANCODE_ESCAPE] != 0) {
        m_CurrentState = State::END;
    }
    m_Triangle.Update();
}

void App::End() {
    LOG_TRACE("End");
}
