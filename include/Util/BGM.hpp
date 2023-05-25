#ifndef UTIL_BGM_HPP
#define UTIL_BGM_HPP
#include <SDL_mixer.h>
#include <string>
namespace Util {

class BGM {
public:
    BGM(const std::string &path);
    ~BGM();

    int GetVolume() const;

    void SetVolume(const int &volume);

    void VolumeUp();
    void VolumeDown();
    void Play(const int &loop = -1);
    void FadeIn(const unsigned int &tick, const int &loop = -1);

private:
    Mix_Music *m_BGM;
};

} // namespace Util

#endif // UTIL_BGM_HPP
