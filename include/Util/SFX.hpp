#ifndef UTIL_SFX_HPP
#define UTIL_SFX_HPP
#include <SDL_mixer.h>
#include <string>
namespace Util {

class SFX {
public:
    SFX(const std::string &path);
    ~SFX();

    int GetVolume() const;

    void SetVolume(const int &volume);

    void VolumeUp();
    void VolumeDown();
    void Play(const int &loop, const unsigned int &duration);
    void FadeIn(const unsigned int &tick, const int &loop = -1,
                const unsigned int &duration = -1);

private:
    Mix_Chunk *m_SFX;
};

} // namespace Util

#endif // UTIL_SFX_HPP
