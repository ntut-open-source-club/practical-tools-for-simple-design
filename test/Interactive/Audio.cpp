#include <istream>
#include <memory>

#include <SDL_mixer.h>
#include <gtest/gtest.h>

#include "Util/BGM.hpp"
#include "Util/Logger.hpp"
#include "Util/SFX.hpp"

bool UserCheck(const std::string &text) {
    while (true) {
        std::cout << text << "[Y/n] ";
        std::string line;
        std::getline(std::cin, line);

        if (line[0] == 'Y' || line[0] == 'y' || line.empty()) {
            return true;
        }

        if (line[0] == 'N' || line[0] == 'n') {
            return false;
        }

        std::cout << "Invalid input\n";
    }
}

void EXCEPT_INPUT_YES(const std::string &text) {
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

class AudioTest : public ::testing::Test {
protected:
    void SetUp() override {
        Util::Logger::Init();
        AudioInit();
    }

    void TearDown() override { AudioQuit(); }
};

TEST_F(AudioTest, BGM_TEST) {
    auto bgm = Util::BGM("../assets/audio/testbgm.mp3");

    bgm.Play();
    EXCEPT_INPUT_YES("Do you hear the bgm?");

    bgm.SetVolume(30);
    EXCEPT_INPUT_YES("Is the volume down?");

    bgm.SetVolume(100);
    EXCEPT_INPUT_YES("Is the volume up?");

    bgm.Pause();
    EXCEPT_INPUT_YES("Is it paused?");

    bgm.Resume();
    EXCEPT_INPUT_YES("Is it resumed?");

    bgm.FadeIn(1000);
    EXCEPT_INPUT_YES("Is it fading in?");

    bgm.FadeOut(1000);
    EXCEPT_INPUT_YES("Is it fading out?");
}

TEST_F(AudioTest, SFX_TEST) {
    auto sfx = Util::SFX("../assets/audio/Click.wav");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");

    sfx.SetVolume(30);
    sfx.Play();
    EXCEPT_INPUT_YES("Is the volume lower than last time?");

    sfx.SetVolume(100);
    sfx.Play();
    EXCEPT_INPUT_YES("Is the volume louder than last time?");
}

TEST_F(AudioTest, BGM_SFX_TEST) {
    auto bgm = Util::BGM("../assets/audio/testbgm.mp3");
    auto sfx = Util::SFX("../assets/audio/Click.wav");

    bgm.SetVolume(100);
    sfx.SetVolume(100);

    bgm.Play();
    EXCEPT_INPUT_YES("Do you hear the bgm?");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");

    bgm.Pause();
    EXCEPT_INPUT_YES("Is the bgm paused?");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");

    bgm.Resume();
    EXCEPT_INPUT_YES("Is the bgm resumed?");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");

    bgm.FadeIn(1000);
    EXCEPT_INPUT_YES("Is the bgm fading in?");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");

    bgm.FadeOut(1000);
    EXCEPT_INPUT_YES("Is the bgm fading out?");

    sfx.Play();
    EXCEPT_INPUT_YES("Do you hear the sfx?");
}
