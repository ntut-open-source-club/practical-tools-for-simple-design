#ifndef UTIL_TIME_H
#define UTIL_TIME_H

#include "pch.hpp" // IWYU pragma: export

namespace Util {
/**
 * A singleton object that lives through the entire life cycle of the program
 *
 * Note: Do NOT create your own `Time` object
 */
class Time {
public:
    static void Update();

    /**
     * @brief Get the delta time between frames in seconds
     */
    static double GetDeltaTime() { return s_DeltaTime; }

private:
    static unsigned long s_Now;
    static unsigned long s_Last;

    static double s_DeltaTime;
};
} // namespace Util

#endif
