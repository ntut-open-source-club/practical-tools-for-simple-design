#include "App.hpp"

#include <SDL.h>

#include "Core/Context.hpp"
#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/PTSDScancode.hpp"
void App::Start() {
    LOG_TRACE("Start");

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    while (Util::Input::Update()) {
        if (Util::Input::IsLButtonPressed()) {
            LOG_DEBUG("Left button pressed");
        }
        if (Util::Input::IsRButtonPressed()) {
            LOG_DEBUG("Right button pressed");
        }
        if (Util::Input::IsMButtonPressed()) {
            LOG_DEBUG("Middle button pressed");
        }
        if (Util::Input::IfScroll()) {
            auto [x, y] = Util::Input::GetScrollDistance();
            LOG_DEBUG("Scrolling: x: {}, y: {}", x, y);
        }
        if (Util::Input::IsMouseMoving()) {
            LOG_DEBUG("Mouse moving");
        }

        if (Util::Input::IsKeyPressed(PTSDScancode::PTSD_SCANCODE_ESCAPE)) {
            m_CurrentState = State::END;
        }
        if (Util::Input::IsKeyPressed(PTSDScancode::PTSD_SCANCODE_A)) {
            LOG_DEBUG("A");
        }
    }
}

    void App::End() {
        Core::Context::SetExit(true);
        LOG_TRACE("End");
    }
