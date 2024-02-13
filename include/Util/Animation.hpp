#ifndef UTIL_ANIMATION_HPP
#define UTIL_ANIMATION_HPP

#include "pch.hpp"

#include "Util/Image.hpp"

namespace Util {
/**
 * @class Animation
 * @brief Class representing an animation with frames.
 */
class Animation {
public:
    /**
     * @brief Constructor for Animation class.
     * @param paths Vector of file paths for the frames.
     * @param interval Interval between frames in milliseconds.
     * @param looping Whether the animation should loop.
     * @param cooldown Cooldown time in milliseconds before the animation can
     * restart.
     */
    Animation(const std::vector<std::string> &paths, int interval,
              bool looping = true, int cooldown = 100);

    /**
     * @brief Get the interval between frames.
     * @return Interval between frames in milliseconds.
     */
    int GetInterval() const { return m_Interval; }

    /**
     * @brief Check if the animation loops.
     * @return True if the animation loops, false otherwise.
     */
    bool GetLooping() const { return m_Looping; }

    /**
     * @brief Get the cooldown time.
     * @return Cooldown time in milliseconds.
     */
    int GetCooldown() const { return m_Cooldown; }

    /**
     * @brief Get the current frame of the animation.
     * @return Pointer to the current frame image.
     */
    std::shared_ptr<Util::Image> GetCurrentFrame();

    /**
     * @brief Set the interval between frames.
     * @param interval Interval between frames in milliseconds.
     */
    void SetInterval(int interval) { m_Interval = interval; }

    /**
     * @brief Set whether the animation loops.
     * @param looping True to enable looping, false to disable.
     */
    void SetLooping(bool looping) { m_Looping = looping; }

    /**
     * @brief Set the cooldown time.
     * @param cooldown Cooldown time in milliseconds.
     */
    void SetCooldown(int cooldown) { m_Cooldown = cooldown; }

    /**
     * @brief Set the current frame of the animation.
     * @param index Index of the frame to set as current.
     */
    void SetCurrentFrame(std::size_t index) { m_Index = index; };

    /**
     * @brief Reset the animation to its initial frame.
     */
    void Reset() { SetCurrentFrame(0); }

private:
    unsigned long m_StartTime;
    int m_Interval;
    bool m_Looping;
    int m_Cooldown;

    std::vector<std::shared_ptr<Util::Image>> m_Frames;
    std::size_t m_Index;
};
} // namespace Util

#endif
