#include <istream>
#include <memory>

#include <SDL_mixer.h>
#include <gtest/gtest.h>

#include "Util/BGM.hpp"
#include "Util/SFX.hpp"

bool UserCheck(const std::string &text) {
    std::cout << text << "[Y/n]";
    auto temp = std::cin.get();
    std::cin.clear();
    return temp != 'n';
}

void ASSERT_INPUT_YES(const std::string &text) {
    if (!UserCheck(text)) {
        ADD_FAILURE() << "user test: [" + text + "] is false";
    }
}

/*
 * Or should I just use Core::Context then you will see a window include void
 */
void AudioInit() {
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        FAIL() << "Failed to initialize SDL_mixer";
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        FAIL() << "Failed to initialize SDL_mixer";
    }
}
void AudioQuit() {
    Mix_HaltGroup(-1);
    Mix_CloseAudio();

    Mix_Quit();
}

TEST(Audio, BGM_TEST) {
    AudioInit();
    auto bgm = Util::BGM("../assets/audio/testbgm.mp3");

    bgm.Play();
    ASSERT_INPUT_YES("Do you hear the bgm?");

    bgm.SetVolume(30);
    ASSERT_INPUT_YES("Is the volume down?");

    bgm.SetVolume(100);
    ASSERT_INPUT_YES("Is the volume up?");

    bgm.Pause();
    ASSERT_INPUT_YES("Is it paused?");

    bgm.Resume();
    ASSERT_INPUT_YES("Is it resumed?");

    bgm.FadeIn(1000);
    ASSERT_INPUT_YES("Is it fading in?");

    bgm.FadeOut(1000);
    ASSERT_INPUT_YES("Is it fading out?");

    AudioQuit();
}

TEST(Audio, SFX_TEST) {
    AudioInit();
    auto sfx = Util::SFX("../assets/audio/Click.wav");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    sfx.SetVolume(30);
    sfx.Play();
    ASSERT_INPUT_YES("Is the volume lower than last time?");

    sfx.SetVolume(100);
    sfx.Play();
    ASSERT_INPUT_YES("Is the volume louder than last time?");

    AudioQuit();
}

TEST(Audio, BGM_SFX_TEST) {
    AudioInit();
    auto bgm = Util::BGM("../assets/audio/testbgm.mp3");
    auto sfx = Util::SFX("../assets/audio/Click.wav");

    bgm.SetVolume(100);
    sfx.SetVolume(100);

    bgm.Play();
    ASSERT_INPUT_YES("Do you hear the bgm?");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    bgm.Pause();
    ASSERT_INPUT_YES("Is the bgm paused?");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    bgm.Resume();
    ASSERT_INPUT_YES("Is the bgm resumed?");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    bgm.FadeIn(1000);
    ASSERT_INPUT_YES("Is the bgm fading in?");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    bgm.FadeOut(1000);
    ASSERT_INPUT_YES("Is the bgm fading out?");

    sfx.Play();
    ASSERT_INPUT_YES("Do you hear the sfx?");

    AudioQuit();
}