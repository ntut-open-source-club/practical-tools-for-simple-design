#include "App.hpp"

#include <SDL.h>

#include "Util/Logger.hpp"
#include "Util/PTSDScancode.hpp"
void App::Start() {
    LOG_TRACE("Start");

    m_CurrentState = State::UPDATE;
}

void App::Update() {
// don't know how to read if context is closed, so i'm leaving this blank for now

}

void App::End() {
    LOG_TRACE("End");
}
