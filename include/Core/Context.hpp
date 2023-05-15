#ifndef CORE_CONTEXT_HPP
#define CORE_CONTEXT_HPP

#include "Util/Input.hpp"
#include <SDL.h>

namespace Core {
class Context {
public:
    static void Init();
    static void Quit();

    static bool GetExit() { return s_Exit; }

    static void SetExit(bool exit) { s_Exit = exit; }

    static void Update();


private:
    /**
     * @brief Initialize context for SDL, OpenGL, and create a window
     */

    static SDL_Window *s_Window;
    static SDL_GLContext s_GlContext;
    static bool s_Exit;
};

} // namespace Core
#endif
