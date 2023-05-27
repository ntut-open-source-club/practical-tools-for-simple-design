#ifndef UTIL_SFX_HPP
#define UTIL_SFX_HPP
#include <SDL_mixer.h>
#include <memory>
#include <string>
namespace Util {

/**
 * @class SFX
 * @brief Class for handling sound effects.
 */
class SFX {
public:
    /**
     * @brief Default constructor for creating an empty SFX object.
     * @note This constructor does not load any media.
     *            The LoadMedia() method <b>MUST</b> be called afterward.
     */
    SFX() = default;

    /**
     * @brief Constructor that initializes the SFX object and loads the sound
     *            effect from the specified file path.
     * @param path The file path of the sound effect to be loaded.
     */
    SFX(const std::string &path);

    /**
     * @brief Retrieves the current volume of the sound effect.
     * @return The current volume of the sound effect.
     */
    int GetVolume() const;

    /**
     * @brief Sets the volume of the background music.
     * @param volume The desired volume level for the background music. The
     *                          valid range is [0, 128].<br>
     *                          A value of 0 mutes the music, and a value of 128
     *                          sets the maximum volume.
     */
    void SetVolume(const int &volume);

    /**
     * @brief Loads the sound effect from the specified file path.
     * @param path The file path of the sound effect to be loaded.
     */
    void LoadMedia(const std::string &path);

    /**
     * @brief Increases the volume of the sound effect by one.
     */
    void VolumeUp();

    /**
     * @brief Decreases the volume of the sound effect by one.
     */
    void VolumeDown();

    /**
     * @brief Plays the sound effect.
     * @param loop The number of times the sound effect will loop.<br>
     *                     A value of 0 means it will play once (no looping).
     * @param duration The duration of the sound effect in milliseconds. <br>
     *                            A value of -1 means it will play the entire sound effect.
     */
    void Play(const int &loop = 0, const int &duration = -1);

    /**
     * @brief Fades in the sound effect gradually.
     * @param tick The duration of the fade-in effect, in milliseconds.
     * @param loop The number of times the sound effect will loop after the
     *                     fade-in is complete. <br>
     *                     A value of -1 means it will loop indefinitely.
     * @param duration The duration of the sound effect in milliseconds.<br>
     *                            A value of -1 means it will play the entire sound effect.
     */
    void FadeIn(const unsigned int &tick, const int &loop = -1,
                const unsigned int &duration = -1);

private:
    std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)> m_Chunk =
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk *)>(nullptr,
                                                          Mix_FreeChunk);
};

} // namespace Util
#endif // UTIL_SFX_HPP