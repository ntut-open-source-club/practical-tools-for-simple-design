#include "Util/Audio.hpp"

#include "Util/Logger.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

namespace Util {

Audio::Audio() {
    // init SDL_Audio and SDL_Mixer
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        LOG_DEBUG("SDL_Audio init failed");
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        LOG_DEBUG("SDL_Mixer init failed");
        exit(1);
    }
}

Audio::~Audio() {
    if (s_Instance != nullptr) {
        // Prevent the callback functions of channels rebuilding the audio
        // instance after the program entered this destructor
        Mix_ChannelFinished(nullptr);
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
void Audio::PlayBGM(const unsigned &index = 0, const int &loopTimes = -1) {
    assert(index < m_BGM.size());
    assert(Mix_PlayMusic(m_BGM.at(index), loopTimes) == 0);
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

void Audio::PlaySFX(const unsigned int &index, const int &loopTimes) {
    assert(index < m_SFX.size());
    for (size_t i = 0; i < m_Channels.size(); ++i) {
        if (!m_Channels.at(i)) {
            Mix_PlayChannel(i, m_SFX.at(index), loopTimes);
            Mix_ChannelFinished([](int channel) {
                Audio::GetInstance()->m_Channels.at(channel) = false;
            });
            m_Channels.at(i) = true;
            break;
        }
    }
}

void Audio::SetSFXVolume(const int &volume) {
    for (auto &i : m_SFX) {
        Mix_VolumeChunk(i, volume);
    }
}
void Audio::SetBGMVolume(const int &volume) {
    Mix_VolumeMusic(volume);
}

std::shared_ptr<Audio> Audio::s_Instance = nullptr;
std::shared_ptr<Audio> Audio::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance.reset(new Audio());
    }
    return s_Instance;
}
void Audio::SetMasterVolume(const int &volume) {
    Mix_VolumeMusic(volume * 0.5 + GetBGMVolume() * 0.5);
    Mix_MasterVolume(volume);
}

} // namespace Util