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
    Context(Context &&) = delete;
    Context &operator=(Context &&) = delete;

    ~Context();

    void Update();

    bool GetExit() const { return m_Exit; }
    void SetExit(bool exit) { m_Exit = exit; }

private:
    SDL_Window *m_Window;
    SDL_GLContext m_GlContext;

    SDL_Event m_Event;

    bool m_Exit = false;
};
} // namespace Core

#endif
