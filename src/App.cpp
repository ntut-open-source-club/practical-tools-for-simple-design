#include "App.hpp"

#include <SDL.h>

#include "Core/Context.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    auto input = Util::Input::GetInstance();
    auto [x, y] = input->GetCursorPosition();

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
        LOG_DEBUG("Mouse moving! x:{}, y{}" , x, y);
    }

    if (input->IsKeyPressed(PTSDScancode::ESCAPE)) {
        m_CurrentState = State::END;
    }
    if (input->IsKeyPressed(PTSDScancode::A)) {
        LOG_DEBUG("A");
    }

//    LOG_DEBUG("Mouse Pos: x:{}, y:{} ", x, y);

}

void App::End() {
    Core::Context::GetInstance()->SetExit(true);
    LOG_TRACE("End");
}
