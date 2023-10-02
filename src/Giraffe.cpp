#include "Giraffe.hpp"

#include "Util/Input.hpp"
#include "Util/Time.hpp"

#include "config.hpp"

void Giraffe::Update() {
    //    auto cursorPos = Util::Input::GetCursorPosition();
    static glm::vec2 dir = {1, 0.5};
    auto pos = m_Image.m_Transform.GetTranslation();

    if (pos.y > WINDOW_HEIGHT || pos.y + WINDOW_HEIGHT < 0) {
        dir.y *= -1;
    }
    if (pos.x > WINDOW_WIDTH || pos.x + WINDOW_WIDTH < 0) {
        dir.x *= -1;
    }

    m_Image.m_Transform.SetTranslation(pos + dir);

    // auto r = m_Image.m_Transform.GetRotation();
    // m_Image.m_Transform.SetRotation(r + 0.01);
//    m_Image.m_Transform = m_Image.m_Transform.Rotate(2 * Util::Time::GetDeltaTime());

//    static float r = 0;
//    r += Util::Time::GetDeltaTime();
//    m_Image.m_Transform.SetScale(glm::vec2(std::sin(r) * 5));

    LOG_DEBUG("GIRA: x: {}, y: {}", pos.x, pos.y);
    m_Image.Draw();
    m_Text.m_Transform.SetTranslation(pos + dir);
//    m_Text.Draw();
}
