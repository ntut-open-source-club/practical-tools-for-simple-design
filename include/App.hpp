#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Giraffe.hpp"
#include "Triangle.hpp"

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
    Giraffe m_Giraffe;
};

#endif
