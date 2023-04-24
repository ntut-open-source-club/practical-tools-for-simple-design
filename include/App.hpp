#ifndef APP_HPP
#define APP_HPP

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
    bool GetExit() const { return m_Exit; }

private:
    State m_CurrentState = State::START;
    bool m_Exit = false;
};

#endif
