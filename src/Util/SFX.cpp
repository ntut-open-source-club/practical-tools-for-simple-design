#include "Util/SFX.hpp"
#include "Util/Logger.hpp"

std::shared_ptr<Mix_Chunk> LoadChunk(const std::string &filepath) {
    auto chunk = std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(filepath.c_str()),
                                            Mix_FreeChunk);

    if (chunk == nullptr) {
        LOG_DEBUG("Failed to load SFX: '{}'", filepath);
        LOG_DEBUG("{}", Mix_GetError());
    }

    return chunk;
}

namespace Util {

SFX::SFX(const std::string &path)
    : m_Chunk(s_Store.Get(path)) {}

int SFX::GetVolume() const {
    return Mix_VolumeChunk(m_Chunk.get(), -1);
}

void SFX::SetVolume(const int volume) {
    Mix_VolumeChunk(m_Chunk.get(), volume);
}

void SFX::LoadMedia(const std::string &path) {
    m_Chunk = s_Store.Get(path);
}

void SFX::VolumeUp(const int step) {
    int volume = GetVolume();
    SetVolume(volume + step);
}

void SFX::VolumeDown(const int step) {
    int volume = GetVolume();
    SetVolume(volume - step);
}
void SFX::Play(const int loop, const int duration) {
    Mix_PlayChannelTimed(-1, m_Chunk.get(), loop, duration);
}
void SFX::FadeIn(const unsigned int tick, const int loop,
                 const unsigned int duration) {
    Mix_FadeInChannelTimed(-1, m_Chunk.get(), loop, static_cast<int>(tick),
                           static_cast<int>(duration));
}

Util::AssetStore<std::shared_ptr<Mix_Chunk>> SFX::s_Store(LoadChunk);

} // namespace Util
