#include "Util/Audio.hpp"
#include "Util/Logger.hpp"

namespace Util {

void Audio::LoadMusic(const std::string &path) {
    Mix_Music *music = Mix_LoadMUS(path.c_str());
    if (music == nullptr) {
        std::string error = Mix_GetError();
        LOG_DEBUG(R"(Failed to load music:)" + error);
        return;
    }
    m_Music.push_back(std::shared_ptr<Mix_Music>(music, Mix_FreeMusic));
}
void Audio::SetMusicVolume(int volume) {
    Mix_VolumeMusic(volume);
}
void Audio::SetSoundVolume(int volume) {
    Mix_Volume(-1, volume);
}
size_t Audio::GetMusicCount() const {
    return m_Music.size();
}
int Audio::GetMusicVolume() const {
    return Mix_VolumeMusic(-1);
}
int Audio::GetSoundVolume(int index) const {
    return Mix_Volume(index, -1);
}
void Audio::PlayMusic(int loops, unsigned int index) {
    if (index >= m_Music.size()) {
        LOG_DEBUG(R"(Failed to play music: index out of range)");
        return;
    }
    Mix_PlayMusic(m_Music[index].get(), loops);
}
void Audio::PauseMusic(int index) {
    if (index >= m_Music.size()) {
        LOG_DEBUG(R"(Failed to pause music: index out of range)");
        return;
    }
    Mix_PauseMusic();
}
void Audio::ResumeMusic(int index) {
    if (index >= m_Music.size()) {
        LOG_DEBUG(R"(Failed to resume music: index out of range)");
        return;
    }
    Mix_ResumeMusic();
}
void Audio::StopMusic(int index) {
    if (index >= m_Music.size()) {
        LOG_DEBUG(R"(Failed to stop music: index out of range)");
        return;
    }
    Mix_HaltMusic();
}
std::shared_ptr<Audio> Audio::s_Instance = nullptr;
std::shared_ptr<Audio> Audio::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance.reset(new Audio());
    }
    return s_Instance;
}
bool Audio::ifPlaying() const {
    return Mix_PlayingMusic() != 0;
}
Audio::Audio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::string error = Mix_GetError();
        LOG_DEBUG(R"(Failed to initialize SDL_mixer:)" + error);
        return;
    }
}
Audio::~Audio() {
    for (auto &i : m_Music) {
        Mix_FreeMusic(i.get());
        i.reset();
    }
    Mix_CloseAudio();
}

} // namespace Util