#include "Util/BGM.hpp"
#include "Util/Logger.hpp"

std::shared_ptr<Mix_Music> LoadMusic(const std::string &filepath) {
    auto music = std::shared_ptr<Mix_Music>(Mix_LoadMUS(filepath.c_str()),
                                            Mix_FreeMusic);

    if (music == nullptr) {
        LOG_DEBUG("Failed to load BGM: '{}'", filepath);
        LOG_DEBUG("{}", Mix_GetError());
    }

    return music;
}

namespace Util {

BGM::BGM(const std::string &path)
    : m_BGM(s_Store.Get(path)) {}

int BGM::GetVolume() const {
    return Mix_VolumeMusic(-1);
}

void BGM::SetVolume(const int volume) {
    Mix_VolumeMusic(volume);
}

void BGM::LoadMedia(const std::string &path) {
    m_BGM = s_Store.Get(path);
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

Util::AssetStore<std::shared_ptr<Mix_Music>> BGM::s_Store(LoadMusic);

} // namespace Util
