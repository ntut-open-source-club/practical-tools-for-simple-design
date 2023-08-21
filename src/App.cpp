#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    auto input = Util::Input::GetInstance();
    auto cursorPos = input->GetCursorPosition();
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
        auto delta = input->GetScrollDistance();
        LOG_DEBUG("Scrolling: x: {}, y: {}", delta.x, delta.y);
    }
    if (input->IsMouseMoving()) {
        LOG_DEBUG("Mouse moving! x:{}, y{}", cursorPos.x, cursorPos.y);
    }

    if (input->IsKeyPressed(Util::Keycode::ESCAPE)) {
        m_CurrentState = State::END;
    }
    m_Triangle.Update();
    if (input->IsKeyPressed(Util::Keycode::A)) {
        LOG_DEBUG("A");
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
