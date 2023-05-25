#include "Util/SFX.hpp"

namespace Util {

SFX::SFX(const std::string &path) {
    m_SFX = Mix_LoadWAV(path.c_str());
}
SFX::~SFX() {
    Mix_FreeChunk(m_SFX);
}
int SFX::GetVolume() const {
    return Mix_VolumeChunk(m_SFX, -1);
}
void SFX::SetVolume(const int &volume) {
    Mix_VolumeChunk(m_SFX, volume);
}
void SFX::VolumeUp() {
    int volume = GetVolume();
    if (volume < MIX_MAX_VOLUME) {
        SetVolume(volume + 1);
    }
}
void SFX::VolumeDown() {
    int volume = GetVolume();
    if (volume > 0) {
        SetVolume(volume - 1);
    }
}
void SFX::Play(const int &loop, const unsigned int &duration) {
    Mix_PlayChannelTimed(-1, m_SFX, loop, duration);
}
void SFX::FadeIn(const unsigned int &tick, const int &loop,
                 const unsigned int &duration) {
    Mix_FadeInChannelTimed(-1, m_SFX, loop, tick, duration);
}
} // namespace Util