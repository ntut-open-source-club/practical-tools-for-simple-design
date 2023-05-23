#ifndef UTIL_AUDIO_HPP
#define UTIL_AUDIO_HPP

#include <SDL_mixer.h>
#include <memory>
#include <string>
#include <vector>

namespace Util {
// this thing is kinda mess, will have a remake later
class Audio {
public:
    Audio(const Audio &) = delete;
    Audio(Audio &&) = delete;

    ~Audio();

    Audio &operator=(const Audio &) = delete;
    Audio &operator=(Audio &&) = delete;

    void SetMusicVolume(int volume);
    void SetSoundVolume(int volume);

    size_t GetMusicCount() const;
    int GetMusicVolume() const;
    int GetSoundVolume(int index = -1) const;
    bool ifPlaying() const;

    void LoadMusic(const std::string &path);

    void PlayMusic(int loops, unsigned index);
    void PauseMusic(int index = -1);
    void ResumeMusic(int index = -1);
    void StopMusic(int index = -1);

    static std::shared_ptr<Audio> GetInstance();

private:
    Audio();

    std::vector<std::shared_ptr<Mix_Music>> m_Music;

    static std::shared_ptr<Audio> s_Instance;
};
}

#endif // UTIL_AUDIO_HPP
