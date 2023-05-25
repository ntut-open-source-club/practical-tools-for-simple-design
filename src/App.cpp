#include "App.hpp"

#include <SDL.h>

#include "Core/Context.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;

    m_Audio->AddBGM("/home/df/Music/BGM.mp3");
    m_Audio->AddSFX("/home/df/Music/Click.wav");
    m_Audio->AddSFX("/home/df/Music/Hello.wav");

    m_Audio->PlayBGM(0, -1);
}

void App::Update() {
    auto input = Util::Input::GetInstance();
    auto [x, y] = input->GetCursorPosition();

    if (input->IsLButtonPressed()) {
        LOG_DEBUG("Left button pressed");
        m_Audio->PlaySFX(0);
    }
    if (input->IsRButtonPressed()) {
        LOG_DEBUG("Right button pressed");
        m_Audio->PlaySFX(1);
    }
    if (input->IsMButtonPressed()) {
        LOG_DEBUG("Middle button pressed");
    }
    if (input->IfScroll()) {
        auto [dx, dy] = input->GetScrollDistance();
        LOG_DEBUG("Scrolling: x: {}, y: {}", dx, dy);
        if (dy != 0){
            if (dy > 0) {
                m_Audio->SetMasterVolume(m_Audio->GetMasterVolume() + 10);
            } else {
                m_Audio->SetMasterVolume(m_Audio->GetMasterVolume() - 10);
            }
            LOG_DEBUG(m_Audio->GetMasterVolume());
        }
    }
    if (input->IsMouseMoving()) {
        LOG_DEBUG("Mouse moving! x:{}, y{}", x, y);
    }

    if (input->IsKeyPressed(PTSDScancode::ESCAPE)) {
        m_CurrentState = State::END;
    }
    m_Triangle.Update();
    if (input->IsKeyPressed(PTSDScancode::A)) {
        LOG_DEBUG("A");
    }
}

void App::End() {
    Core::Context::GetInstance()->SetExit(true);
    LOG_TRACE("End");
}
