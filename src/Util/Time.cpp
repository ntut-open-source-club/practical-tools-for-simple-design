#include "Util/Time.hpp"

#include <SDL.h>

namespace Util {

Time Time(); // static lifetime object

ms_t Time::GetElapsedTimeMs() {
    return static_cast<ms_t>(1000 * (SDL_GetPerformanceCounter() - s_Start)) /
           (SDL_GetPerformanceFrequency());
}

void Time::Update() {
    s_Last = s_Now;
    s_Now = SDL_GetPerformanceCounter();

    s_DeltaTime = static_cast<double>(s_Now - s_Last) /
                  static_cast<double>(SDL_GetPerformanceFrequency());
}

Uint64 Time::s_Start = SDL_GetPerformanceCounter();
Uint64 Time::s_Now = SDL_GetPerformanceCounter();
Uint64 Time::s_Last = 0;
second_t Time::s_DeltaTime = 0;

} // namespace Util
