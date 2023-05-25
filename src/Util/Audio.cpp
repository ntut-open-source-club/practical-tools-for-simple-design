#include "Util/Audio.hpp"

#include "Util/Logger.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

namespace Util {

Audio::Audio() {
    // init SDL_Audio and SDL_Mixer
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        LOG_DEBUG("SDL_Audio init failed" + std::string(SDL_GetError()));
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        LOG_DEBUG("SDL_Mixer init failed" + std::string(Mix_GetError()));
        exit(1);
    }
}

Audio::~Audio() {
    if (s_Instance != nullptr) {
        Mix_HaltGroup(-1);
        for (auto &i : m_BGM) {
            Mix_FreeMusic(i);
        }
        for (auto &i : m_SFX) {
            Mix_FreeChunk(i);
        }
        Mix_Quit();
    }
}

void Audio::SetMasterVolume(const int &volume) {
    SetBGMVolume((volume + GetBGMVolume()) / 2);
    Mix_MasterVolume(volume);
}
void Audio::SetBGMVolume(const int &volume) {
    Mix_VolumeMusic(volume);
}
void Audio::SetSFXVolume(const int &volume) {
    for (auto &i : m_SFX) {
        Mix_VolumeChunk(i, volume);
    }
}

void Audio::AddBGM(const std::string &path) {
    auto *temp = Mix_LoadMUS(path.c_str());
    assert(temp != nullptr);
    m_BGM.push_back(std::move(temp));
}
void Audio::DeleteBGM(const unsigned &index) {
    assert(index < m_BGM.size());
    Mix_FreeMusic(m_BGM.at(index));
    m_BGM.erase(m_BGM.begin() + index);
}
void Audio::PlayBGM(const unsigned &index, const int &loopTimes,
                    const bool &fadeIn, const int &fadeInTicks) {
    if (fadeIn) {
        Mix_FadeInMusic(m_BGM.at(index), loopTimes, fadeInTicks);
    } else {
        Mix_PlayMusic(m_BGM.at(index), loopTimes);
    }
}
void Audio::StopBGM() {
    Mix_PauseMusic();
}

void Audio::ResumeBGM() {
    if (Mix_PausedMusic() != 0) {
        Mix_ResumeMusic();
    }
}

void Audio::AddSFX(const std::string &path) {
    auto *temp = Mix_LoadWAV(path.c_str());
    assert(temp != nullptr);
    m_SFX.push_back(temp);
}

void Audio::DeleteSFX(const unsigned &index) {
    assert(index < m_SFX.size());
    Mix_FreeChunk(m_SFX.at(index));
    m_SFX.erase(m_SFX.begin() + index);
}

void Audio::PlaySFX(const unsigned &index, const int &loopTimes,
                    const bool &fadeIn, const int &fadeInTicks) {
    assert(index < m_SFX.size());
    if (fadeIn) {
        Mix_FadeInChannel(-1, m_SFX.at(index), loopTimes, fadeInTicks);
    } else {
        Mix_PlayChannel(-1, m_SFX.at(index), loopTimes);
    }
}
std::shared_ptr<Audio> Audio::s_Instance = nullptr;
std::shared_ptr<Audio> Audio::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance.reset(new Audio());
    }
    return s_Instance;
}

} // namespace Util