#ifndef APP_HPP
#define APP_HPP

#include <SDL.h>

#include "Triangle.hpp"
#include "Util/Audio.hpp"
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

    Triangle m_Triangle;
    std::shared_ptr<Util::Audio> m_Audio = Util::Audio::GetInstance();
};

#endif
