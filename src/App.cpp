#include "App.hpp"

#include <SDL.h>

#include "Core/Context.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    m_CurrentState = State::UPDATE;
    m_BGM = Util::BGM("/home/df/Music/BGM.mp3");
    m_BGM.Play();
    m_SFXs.emplace_back("/home/df/Music/Missed1.wav");
    m_SFXs.emplace_back("/home/df/Music/Missed1.wav");
    m_SFXs.emplace_back("/home/df/Music/Missed1.wav");
    m_SFXs.emplace_back("/home/df/Music/Missed1.wav");
    m_SFXs.emplace_back("/home/df/Music/Missed1.wav");


}

void App::Update() {
    auto input = Util::Input::GetInstance();
    auto [x, y] = input->GetCursorPosition();
    if (input->IsLButtonPressed()) {
        LOG_DEBUG("Left button pressed");
        m_SFXs[0].Play();
    }
    if (input->IsRButtonPressed()) {
        LOG_DEBUG("Right button pressed");
        m_SFXs[1].Play();
    }
    if (input->IsMButtonPressed()) {
        LOG_DEBUG("Middle button pressed");
    }
    if (input->IfScroll()) {
        auto [dx, dy] = input->GetScrollDistance();
        LOG_DEBUG("Scrolling: x: {}, y: {}", dx, dy);
        if (dy != 0) {
            if (dy > 0) {
                m_BGM.VolumeDown();
                for (auto &sfx : m_SFXs) {
                    sfx.Play();
                    sfx.VolumeDown();
                }
            } else {
                for (auto &sfx : m_SFXs) {
                    sfx.VolumeUp();
                }
                m_BGM.VolumeUp();
            }
            LOG_DEBUG(m_SFXs.front().GetVolume());
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
