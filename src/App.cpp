#include "App.hpp"

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

    if (input->IsKeyPressed(Util::Keycode::ESCAPE)) {
        m_CurrentState = State::END;
    }

    m_Triangle.Update();
    m_Giraffe.Update();
}

void App::End() {
    Core::Context::GetInstance()->SetExit(true);
    LOG_TRACE("End");
}
