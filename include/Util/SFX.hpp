#ifndef UTIL_SFX_HPP
#define UTIL_SFX_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/AssetStore.hpp"

namespace Util {

/**
 * @class SFX
 * @brief Class for handling sound effects.
 * @see One should use Util::BGM for long audio files since it loads audio from
 * disk instead of memory.
 *            (https://wiki.libsdl.org/SDL2_mixer/Mix_LoadMUS#remarks)
 */
class SFX {
public:
    SFX() = delete;

    /**
     * @brief Constructor that initializes the SFX object and loads the sound
     *            effect from the specified file path.
     * @param path The file path of the sound effect to be loaded.
     */
    explicit SFX(const std::string &path);

    /**
     * @brief Deleted copy constructor to prevent copying of SFX objects.
     */
    SFX(const SFX &) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying of SFX
     *            objects.
     */
    SFX &operator=(const SFX &) = delete;

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
    void SetVolume(int volume);

    /**
     * @brief Loads the sound effect from the specified file path.
     * @param path The file path of the sound effect to be loaded.
     */
    void LoadMedia(const std::string &path);

    /**
     * @brief Increases the volume of the sound effect by one.
     * @param step The amount to increase the volume by.
     */
    void VolumeUp(int step = 1);

    /**
     * @brief Decreases the volume of the sound effect by one.
     * @param step The amount to decrease the volume by.
     */
    void VolumeDown(int step = 1);

    /**
     * @brief Plays the sound effect.
     * @param loop The number of times the sound effect will loop.<br>
     *                     A value of 0 means it will play once (no looping).
     * @param duration The duration of the sound effect in milliseconds. <br>
     *                            A value of -1 means it will play the entire
     * sound effect.
     */
    void Play(int loop = 0, int duration = -1);

    /**
     * @brief Fades in the sound effect gradually.
     * @param tick The duration of the fade-in effect, in milliseconds.
     * @param loop The number of times the sound effect will loop after the
     *                     fade-in is complete. <br>
     *                     A value of -1 means it will loop indefinitely.
     * @param duration The duration of the sound effect in milliseconds.<br>
     *                            A value of -1 means it will play the entire
     * sound effect.
     */
    void FadeIn(unsigned int tick, int oop = -1, unsigned int duration = -1);

private:
    static Util::AssetStore<std::shared_ptr<Mix_Chunk>> s_Store;

private:
    std::shared_ptr<Mix_Chunk> m_Chunk;
};

} // namespace Util
#endif // UTIL_SFX_HPP
