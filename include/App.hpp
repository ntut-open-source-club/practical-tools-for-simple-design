#ifndef APP_HPP
#define APP_HPP

#include <SDL.h>

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    void Start();
    void Update();
    void End();

    State GetCurrentState() const { return m_CurrentState; }

private:
    State m_CurrentState = State::START;

    int m_KeyLen;
    const Uint8 *m_KeyState = SDL_GetKeyboardState(&m_KeyLen);
};

#endif
