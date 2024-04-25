#include "Util/Time.hpp"

#include <SDL.h>

namespace Util {

ms_t Time::GetElapsedTimeMs() {
    return static_cast<float>(SDL_GetPerformanceCounter() - s_Start) /
           static_cast<float>((SDL_GetPerformanceFrequency())) * 1000.0F;
}

void Time::Update() {
    s_Last = s_Now;
    s_Now = SDL_GetPerformanceCounter();

    s_DeltaTime = static_cast<float>(s_Now - s_Last) /
                  static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0F;
}

sdl_count_t Time::s_Start = SDL_GetPerformanceCounter();
sdl_count_t Time::s_Now = Time::s_Start;
sdl_count_t Time::s_Last = 0;
ms_t Time::s_DeltaTime = 0;

} // namespace Util
