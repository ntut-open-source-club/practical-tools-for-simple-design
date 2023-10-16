#include "Giraffe.hpp"

#include "Util/Input.hpp"
#include "Util/Time.hpp"

#include "config.hpp"

void Giraffe::Update() {
    auto cursorPos = Util::Input::GetCursorPosition();
    static glm::vec2 dir = {1, 0.5};
    auto &pos = m_Image.m_Transform.translation;
    auto &scale = m_Image.m_Transform.scale;
    auto &rotation = m_Image.m_Transform.rotation;

    if (pos.y > WINDOW_HEIGHT || pos.y + WINDOW_HEIGHT < 0) {
        dir.y *= -1;
    }
    if (pos.x > WINDOW_WIDTH || pos.x + WINDOW_WIDTH < 0) {
        dir.x *= -1;
    }


    auto delta =  static_cast<float>(Util::Time::GetDeltaTime());
    pos += dir * delta * 1000.0F;
    rotation += 2 * delta;
    scale = glm::vec2(1,1) * (std::sin(rotation/2) + 1.0F  ) * 100.0F;

    LOG_DEBUG("GIRA: x: {}, y: {}", pos.x, pos.y);
    m_Image.Draw();
    m_Text.Draw();
}
