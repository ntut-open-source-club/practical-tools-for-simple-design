#include "Util/BGM.hpp"
#include "Util/Logger.hpp"

namespace Util {

BGM::BGM(const std::string &path)
    : m_BGM(Mix_LoadMUS(path.c_str()), BGM::MusicDeleter()) {
    if (m_BGM == nullptr) {
        LOG_DEBUG("Failed to load BGM: {} {}", path,
                  std::string(Mix_GetError()));
    }
}

int BGM::GetVolume() const {
    return Mix_VolumeMusic(-1);
}

void BGM::SetVolume(const int volume) {
    Mix_VolumeMusic(volume);
}

void BGM::LoadMedia(const std::string &path) {
    m_BGM.reset(Mix_LoadMUS(path.c_str()));
}

void BGM::VolumeUp(const int step) {
    int volume = GetVolume();
    SetVolume(volume + step);
}

void BGM::VolumeDown(const int step) {
    int volume = GetVolume();
    SetVolume(volume - step);
}

void BGM::Play(const int loop) {
    Mix_PlayMusic(m_BGM.get(), loop);
}

void BGM::FadeIn(const int tick, const int loop) {
    Mix_FadeInMusic(m_BGM.get(), loop, tick);
}

void BGM::FadeOut(const int tick) {
    Mix_FadeOutMusic(tick);
}

void BGM::Pause() {
    Mix_PauseMusic();
}
void BGM::Resume() {
    Mix_ResumeMusic();
}

} // namespace Util
