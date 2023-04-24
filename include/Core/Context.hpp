#ifndef CORE_CONTEXT_HPP
#define CORE_CONTEXT_HPP

#include <SDL.h>

namespace Core {
class Context {
public:
    /**
     * @brief Initialize context for SDL, OpenGL, and create a window
     */
    Context();
    Context(const Context &) = delete;
    Context &operator=(const Context &) = delete;

    ~Context();

    void Update();

private:
    SDL_Window *m_Window;
    SDL_GLContext m_GlContext;
};
} // namespace Core

#endif
