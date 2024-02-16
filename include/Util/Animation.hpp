#ifndef UTIL_ANIMATION_HPP
#define UTIL_ANIMATION_HPP

#include "pch.hpp"

#include <exception>

#include "Core/Drawable.hpp"

#include "Util/Image.hpp"

namespace Util {
/**
 * @class Animation
 * @brief Class representing an animation with frames.
 */
class Animation : public Core::Drawable {
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
     * @brief Set the interval between frames.
     * @param interval Interval between frames in milliseconds.
     * @todo This method is not yet implemented
     */
    void SetInterval(int interval) {
        (void)interval;
        throw std::logic_error("Not implemented");
    }

    /**
     * @brief Set whether the animation loops.
     * @param looping True to enable looping, false to disable.
     * @todo This method is not yet implemented
     */
    void SetLooping(bool looping) {
        (void)looping;
        throw std::logic_error("Not implemented");
    }

    /**
     * @brief Set the cooldown time.
     * @param cooldown Cooldown time in milliseconds.
     * @todo This method is not yet implemented
     */
    void SetCooldown(int cooldown) {
        (void)cooldown;
        throw std::logic_error("Not implemented");
    }

    /**
     * @brief Set the current frame of the animation.
     * @param index Index of the frame to set as current.
     * @todo This method is not yet implemented
     */
    void SetCurrentFrame(std::size_t index) {
        (void)index;
        throw std::logic_error("Not implemented");
    };

    void Draw(const Util::Transform &transform, const float zIndex) override;

    glm::vec2 GetSize() const override { return m_Frames[m_Index]->GetSize(); }

    /**
     * @brief Reset the animation to its initial frame.
     */
    void Reset() {
        // TODO: use `SetCurrentFrame(0)` when it's implemented
        m_Index = 0;
    }

private:
    /**
     * @brief Update the animation frames.
     */
    void Update();

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
