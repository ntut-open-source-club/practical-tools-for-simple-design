#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

#include "GiraffeText.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Giraffe->SetDrawable(
        std::make_shared<Util::Image>("../assets/sprites/giraffe.png"));
    m_Giraffe->SetZIndex(5);
    m_Giraffe->Start();

    m_Root.AddChild(m_Giraffe);

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    if (Util::Input::IsLButtonPressed()) {
        LOG_DEBUG("Left button preesed");
    }
    if (Util::Input::IsRButtonDown()) {
        LOG_DEBUG("Right button down");
    }
    if (Util::Input::IsMButtonUp()) {
        LOG_DEBUG("Middle button up");
    }
    if (Util::Input::IfScroll()) {
        auto delta = Util::Input::GetScrollDistance();
        LOG_DEBUG("Scrolling: x: {}, y: {}", delta.x, delta.y);
    }
    if (Util::Input::IsMouseMoving()) {
        // LOG_DEBUG("Mouse moving! x:{}, y{}", cursorPos.x, cursorPos.y);
    }

    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        LOG_DEBUG("A");
    }
    if (Util::Input::IsKeyDown(Util::Keycode::B)) {
        LOG_DEBUG("B");
        Util::Input::SetCursorPosition({0.0F, 0.0F});
    }

    m_Giraffe->Update();

    m_Root.Update();
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
