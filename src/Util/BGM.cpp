#include "Util/BGM.hpp"
#include "Util/Logger.hpp"
#include <cassert>
#include <iostream>

namespace Util {

BGM::BGM(const std::string &path) {
    m_BGM = std::unique_ptr<Mix_Music, void(*)(Mix_Music *)>(Mix_LoadMUS(path.c_str()), Mix_FreeMusic);
    if (m_BGM == nullptr) {
        LOG_DEBUG("Failed to load BGM: " + path + std::string(Mix_GetError()));
    }
}

int BGM::GetVolume() const {
    assert(m_BGM != nullptr);
    return Mix_VolumeMusic(-1);
}

void BGM::SetVolume(const int &volume) {
    assert(m_BGM != nullptr);
    Mix_VolumeMusic(volume);
}

void BGM::LoadMedia(const std::string &path) {
    m_BGM.reset(Mix_LoadMUS(path.c_str()));
}

void BGM::VolumeUp() {
    assert(m_BGM != nullptr);
    int volume = GetVolume();
    SetVolume(volume + 1);
}

void BGM::VolumeDown() {
    assert(m_BGM != nullptr);
    int volume = GetVolume();
    SetVolume(volume - 1);
}

void BGM::Play(const int &loop) {
    assert(m_BGM != nullptr);
    Mix_PlayMusic(m_BGM.get(), loop);
}

void BGM::FadeIn(const int &tick, const int &loop) {
    assert(m_BGM != nullptr);
    Mix_FadeInMusic(m_BGM.get(), loop, tick);
}
} // namespace Util