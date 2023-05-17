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
    unsigned int GetWindowWidth() const { return m_WindowWidth; }
    unsigned int GetWindowHeight() const { return m_WindowHeight; }

    void SetExit(bool exit) { m_Exit = exit; }
    void SetWindowWidth(unsigned int width) { m_WindowWidth = width; }
    void SetWindowHeight(unsigned int height) { m_WindowHeight = height; }

private:
    SDL_Window *m_Window;
    SDL_GLContext m_GlContext;

    SDL_Event m_Event;

    bool m_Exit;

    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;
};
} // namespace Core

#endif
