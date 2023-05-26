#ifndef UTIL_SFX_HPP
#define UTIL_SFX_HPP
#include <SDL_mixer.h>
#include <memory>
#include <string>
namespace Util {

class SFX {
public:

    SFX(const std::string &path);

    int GetVolume() const;

    void SetVolume(const int &volume);

    void LoadMedia(const std::string &path);
    void VolumeUp();
    void VolumeDown();
    void Play(const int &loop = 0, const int &duration = -1);
    void FadeIn(const unsigned int &tick, const int &loop = -1,
                const unsigned int &duration = -1);

private:
    std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)> m_Chunk =
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)>(nullptr, Mix_FreeChunk);
};
} // namespace Util
#endif // UTIL_SFX_HPP