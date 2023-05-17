#ifndef CORE_CONTEXT_HPP
#define CORE_CONTEXT_HPP

#include <memory> // for std::shared_ptr

#include <SDL.h>

#include "Util/Input.hpp" // for Input

namespace Core {
class Context {
public:
    Context(const Context &) = delete;
    Context(Context &&) = delete;

    ~Context();

    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&) = delete;

    bool GetExit() const { return m_Exit; }

    void SetExit(bool exit) { m_Exit = exit; }

    void Update();

    static std::shared_ptr<Context> GetInstance();

private:
    /**
     * @brief Initialize context for SDL, OpenGL, and create a window
     */
    Context();

    SDL_Window *m_Window;
    SDL_GLContext m_GlContext;
    bool m_Exit = false;

    static std::shared_ptr<Context> s_Instance;
};

} // namespace Core
#endif
