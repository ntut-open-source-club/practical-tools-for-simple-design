#include "Util/SFX.hpp"
#include "Util/Logger.hpp"

namespace Util {



SFX::SFX(const std::string &path) {
    m_Chunk = std::unique_ptr<Mix_Chunk, void(*)(Mix_Chunk*)>(Mix_LoadWAV(path.c_str()), Mix_FreeChunk);
    if (m_Chunk == nullptr) {
        LOG_DEBUG("Failed to load SFX: " + path + std::string(Mix_GetError()));
    }
}

int SFX::GetVolume() const {
    assert(m_Chunk != nullptr);
    return Mix_VolumeChunk(m_Chunk.get(), -1);
}

void SFX::SetVolume(const int &volume) {
    assert(m_Chunk != nullptr);
    Mix_VolumeChunk(m_Chunk.get(), volume);
}

void SFX::LoadMedia(const std::string &path) {
    if (m_Chunk != nullptr) {
        Mix_FreeChunk(m_Chunk.get());
    }
    m_Chunk .reset( Mix_LoadWAV(path.c_str()));
}

void SFX::VolumeUp() {
    assert(m_Chunk != nullptr);
    int volume = GetVolume();
    SetVolume(volume + 1);
}

void SFX::VolumeDown() {
    assert(m_Chunk != nullptr);
    int volume = GetVolume();
    SetVolume(volume - 1);
}
void SFX::Play(const int &loop, const int &duration) {
    assert(m_Chunk != nullptr);
    Mix_PlayChannelTimed(-1, m_Chunk.get(), loop, duration);
}
void SFX::FadeIn(const unsigned int &tick, const int &loop,
                 const unsigned int &duration) {
    Mix_FadeInChannelTimed(-1, m_Chunk.get(), loop, tick, duration);
}

} // namespace Util