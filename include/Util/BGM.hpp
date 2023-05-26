#ifndef UTIL_BGM_HPP
#define UTIL_BGM_HPP
#include <SDL_mixer.h>
#include <memory>
#include <string>
namespace Util {

class BGM {
public:
    BGM() = default;
    BGM(const std::string &path);

    int GetVolume() const;

    void SetVolume(const int &volume);

    void LoadMedia(const std::string &path);
    void VolumeUp();
    void VolumeDown();
    void Play(const int &loop = -1);
    void FadeIn(const int &tick, const int &loop = -1);

private:
    std::unique_ptr<Mix_Music, void (*)(Mix_Music *)> m_BGM =
        std::unique_ptr<Mix_Music, void (*)(Mix_Music *)>(nullptr,
                                                          Mix_FreeMusic);
};

} // namespace Util

#endif // UTIL_BGM_HPP
