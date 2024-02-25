#include "Util/Time.hpp"

#include <SDL.h>

Util::Time Time(); // static lifetime object

unsigned long Util::Time::GetElapsedTimeMs() {
    return 1000 * (SDL_GetPerformanceCounter() - s_Start) /
           (SDL_GetPerformanceFrequency());
}

void Util::Time::Update() {
    s_Last = s_Now;
    s_Now = static_cast<unsigned long>(SDL_GetPerformanceCounter());

    s_DeltaTime = static_cast<double>(s_Now - s_Last) /
                  static_cast<double>(SDL_GetPerformanceFrequency());
}

unsigned long Util::Time::s_Start = SDL_GetPerformanceCounter();
unsigned long Util::Time::s_Now = SDL_GetPerformanceCounter();
unsigned long Util::Time::s_Last = 0;
double Util::Time::s_DeltaTime = 0;
