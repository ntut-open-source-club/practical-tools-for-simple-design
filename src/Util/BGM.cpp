#include "Util/BGM.hpp"
#include <cassert>

namespace Util {

BGM::BGM(const std::string &path) {
    m_BGM = Mix_LoadMUS(path.c_str());
}
BGM::~BGM() {
    Mix_FreeMusic(m_BGM);
}
int BGM::GetVolume() const {
    return Mix_VolumeMusic(-1);
}
void BGM::SetVolume(const int &volume) {
    Mix_VolumeMusic(volume);
}
void BGM::VolumeUp() {
    int volume = GetVolume();
    if (volume < MIX_MAX_VOLUME) {
        SetVolume(volume + 1);
    }
}
void BGM::VolumeDown() {
    int volume = GetVolume();
    if (volume > 0) {
        SetVolume(volume - 1);
    }
}
void BGM::Play(const int &loop) {
//    assert(m_BGM != nullptr);
    Mix_PlayMusic(m_BGM, loop);
}
void BGM::FadeIn(const unsigned int &tick, const int &loop) {
    Mix_FadeInMusic(m_BGM, loop, tick);
}
} // namespace Util