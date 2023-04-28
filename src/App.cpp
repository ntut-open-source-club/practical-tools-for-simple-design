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
    // don't know how to read if context is closed, so i'm leaving this blank
    // for now
    auto *input = Util::Input::GetInstance();
    while (input->Update()) {
        if (input->IsLButtonPressed()) {
            LOG_DEBUG("Left button pressed");
        }
        if (input->IsRButtonPressed()) {
            LOG_DEBUG("Right button pressed");
        }
        if (input->IsMButtonPressed()) {
            LOG_DEBUG("Middle button pressed");
        }
        if (input->IfScroll()) {
            auto [x, y] = input->GetScrollDistance();
            LOG_DEBUG("Scrolling: x: {}, y: {}", x, y);
        }
        if (input->IsMouseMoving()) {
            LOG_DEBUG("Mouse moving");
        }

        if (input->IsKeyPressed(PTSDScancode::PTSD_SCANCODE_ESCAPE)) {
            m_CurrentState = State::END;
        }
        if (input->IsKeyPressed(PTSDScancode::PTSD_SCANCODE_A)) {
            LOG_DEBUG("A");
        }
    }
}

    void App::End() {
        Core::Context::GetInstance()->SetExit(true);
        LOG_TRACE("End");
    }
