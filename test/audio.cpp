#include "Core/Context.hpp"
#include "Util/BGM.hpp"
#include "Util/SFX.hpp"
#include <SDL_mixer.h>
#include <gtest/gtest.h>

bool user_check(const std::string text) {
	std::cout << text << "[Y/n]";
	auto yn = std::cin.get();
	std::cin.clear();
	return yn != 'n';
}
void EXCEPT_USER_SAY_YES(const std::string text) {
	if (user_check(text)) {
		/* pass */
	} else {
		ADD_FAILURE() << "user test: ["+text+"] is false";
	}
}

/*
 * Or should I just use Core::Context than you will see a window include void
 */
void AUDIO_INIT() {
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        FAIL() << "Failed to initialize SDL_mixer";
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        FAIL() << "Failed to initialize SDL_mixer";
    }
}
void AUDIO_UNINIT() {
    Mix_HaltGroup(-1);
    Mix_CloseAudio();

    Mix_Quit();
}

//TEST(GTestTest, UserInputMacro) {
//	//EXPECT_TRUE(user_check("do you yes?"));
//	EXCEPT_USER_SAY_YES("do you yes?");
//	EXCEPT_USER_SAY_YES("do you not no?");
//}



TEST(Audio, BGM_TEST) {
    AUDIO_INIT();
    auto bgm = Util::BGM("../assets/audio/testbgm.mp3");
    bgm.SetVolume(100);

    bgm.Play();
    EXCEPT_USER_SAY_YES("Do you hear the bgm?");

    bgm.SetVolume(30);
    EXCEPT_USER_SAY_YES("Is the volume down?");

    bgm.SetVolume(100);
    EXCEPT_USER_SAY_YES("Is the volume up?");

    bgm.Pause();
    EXCEPT_USER_SAY_YES("Is it pause?");

    bgm.Resume();
    EXCEPT_USER_SAY_YES("Is it resume?");

    bgm.FadeIn(1000);
    EXCEPT_USER_SAY_YES("Is it fading in?");

    AUDIO_UNINIT();

}

TEST(Audio, SFX_TEST){
    AUDIO_INIT();
    auto sfx = Util::SFX("../assets/audio/Click.wav");

    sfx.Play();
    EXCEPT_USER_SAY_YES("Do you hear the sfx?");

    sfx.SetVolume(30);
    sfx.Play();
    EXCEPT_USER_SAY_YES("Is the volume lower than last time?");

    sfx.SetVolume(100);
    sfx.Play();
    EXCEPT_USER_SAY_YES("Is the volume louder than last time?");


    AUDIO_UNINIT();
}