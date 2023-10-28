#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Giraffe.hpp"
#include "Triangle.hpp"
#include "Util/RenderQueue.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    State m_CurrentState = State::START;

    Util::RenderQueue m_RenderQueue;
    Triangle m_Triangle;
    std::shared_ptr<Giraffe> m_Giraffe= std::make_shared<Giraffe>();
};

#endif
