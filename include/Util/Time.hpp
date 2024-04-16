#ifndef UTIL_TIME_H
#define UTIL_TIME_H

#include "pch.hpp" // IWYU pragma: export

namespace Util {

using second_t = double;
using ms_t = double;

/**
 * @class Time
 * @brief A singleton class that provides time-related functionalities.
 *
 * This class provides functionalities such as getting the delta time between
 * frames.
 *
 * @note It is designed as a singleton, meaning only one instance of this class
 * should exist. Therefore, the user should NOT create their own `Time` object.
 */
class Time {
public:
    /**
     * @brief Get the delta time between frames in seconds.
     *
     * This function returns the time difference between the current frame and
     * the last frame. The time difference is measured in seconds.
     *
     * @return The delta time between frames in seconds.
     */
    static second_t GetDeltaTime() { return s_DeltaTime; }

    /**
     * @brief Get the elapsed time from the start of the program in
     * milliseconds.
     *
     * @note To create a timer, one may call this function to record the time,
     * and then call it again to obtain the time difference.
     *
     * @return The elapsed time from the start of the program in milliseconds.
     */
    static ms_t GetElapsedTimeMs();

    /**
     * @brief Update the time.
     *
     * This function updates the current time and the delta time.
     * It is called by Core::Context::Update(). The user is not recommended to
     * call this function.
     */
    static void Update();

private:
    static Uint64 s_Start;

    /**
     * @brief The current time.
     *
     * This variable stores the current time.
     */
    static Uint64 s_Now;

    /**
     * @brief The time of the last frame.
     *
     * This variable stores the time of the last frame.
     */
    static Uint64 s_Last;

    /**
     * @brief The delta time between frames.
     *
     * This variable stores the time difference between the current frame and
     * the last frame.
     */
    static second_t s_DeltaTime;
};
} // namespace Util

#endif /* UTIL_TIME_H */
