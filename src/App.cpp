#include "App.hpp"

#include <SDL.h>

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    // TODO: Wrap this into Core
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
            m_CurrentState = State::END;
        }
    }
}

void App::End() {
    LOG_TRACE("End");

    m_Exit = true;
}
