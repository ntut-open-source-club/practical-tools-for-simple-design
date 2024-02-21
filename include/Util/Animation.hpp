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
     * @brief Enum representing the state of the animation.
     */
    enum class State {
        PLAY,  /**< Animation is playing. */
        PAUSE, /**< Animation is paused. */
    };

    /**
     * @brief Constructor for Animation class.
     * @param paths Vector of file paths for the frames.
     * @param bool Whether the animation should play right away.
     * @param interval Interval between frames in milliseconds.
     * @param looping Whether the animation should loop.
     * @param cooldown Cooldown time in milliseconds before the animation can
     * restart.
     */
    Animation(const std::vector<std::string> &paths, bool play,
              std::size_t interval, bool looping = true,
              std::size_t cooldown = 100);

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
     * @brief Get the index of the current frame.
     * @return Index of the current frame.
     */
    std::size_t GetCurrentFrameIndex() const { return m_Index; }

    /**
     * @brief Get the total number of frames in the animation.
     * @return Total number of frames.
     */
    std::size_t GetFrameCount() const { return m_Frames.size(); }

    /**
     * @brief Get the current state of the animation
     * @return The current state of the animation
     */
    State GetState() const { return m_State; }

    /**
     * @brief Get the size of the current frame.
     * @return Size of the current frame.
     */
    glm::vec2 GetSize() const override { return m_Frames[m_Index]->GetSize(); }

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

    /**
     * @brief Draw the current frame.
     * @param transform Transformation matrix for drawing.
     * @param zIndex Z-index for drawing.
     */
    void Draw(const Util::Transform &transform, const float zIndex) override;

    /**
     * @brief Reset the animation to its initial frame.
     */
    void Reset() {
        // TODO: use `SetCurrentFrame(0)` when it's implemented
        m_Index = 0;
    }

    /**
     * @brief Start playing the animation.
     * If the animation is already playing, this method won't do anything.
     * If the animation has ended and `looping` is set to `false`, this would
     * replay the animation once.
     */
    void Play();

    /**
     * @brief Pause the animation.
     * If the animation has already been paused, this method won't do anything.
     */
    void Pause();

private:
    /**
     * @brief Update the animation frames.
     */
    void Update();

private:
    State m_State = State::PLAY;

    unsigned long m_StartTime;

    unsigned long m_PauseTime;
    unsigned long m_PauseOffset = 0;

    std::size_t m_Interval;
    bool m_Looping;
    std::size_t m_Cooldown;
    bool m_HasEnded;

    std::vector<std::shared_ptr<Util::Image>> m_Frames;
    std::size_t m_Index;
};
} // namespace Util

#endif
