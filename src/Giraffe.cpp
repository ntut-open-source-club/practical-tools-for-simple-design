
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Util/Transform.hpp"
#include "Util/GameObject.hpp"
#include "Giraffe.hpp"
#include "Util/Time.hpp"
#include "config.hpp"


void GiraffeText::Update(const Util::Transform &transform) {
    auto &pos = m_Drawable->m_Transform.translation;
    auto &scale = m_Drawable->m_Transform.scale;
    auto &rotation = m_Drawable->m_Transform.rotation;

    pos += transform.translation;
    rotation += transform.rotation;
    scale = transform.scale;
}

void GiraffeText::Start() {
    this->SetDrawable(std::make_unique<Util::Text>(m_Font, m_Size, m_Text));
}

void Giraffe::Start() {

}

void Giraffe::Update(const Util::Transform &transform) {
    static glm::vec2 dir = {1, 0.5};

    auto &pos = m_Drawable->m_Transform.translation;
    auto &scale = m_Drawable->m_Transform.scale;
    auto &rotation = m_Drawable->m_Transform.rotation;

    if (pos.y > WINDOW_HEIGHT || pos.y + WINDOW_HEIGHT < 0) {
        dir.y *= -1;
    }
    if (pos.x > WINDOW_WIDTH || pos.x + WINDOW_WIDTH < 0) {
        dir.x *= -1;
    }

    auto delta = static_cast<float>(Util::Time::GetDeltaTime());
    Util::Transform deltaTransform{
            dir * delta * 1000.0F,
            2 * delta,
            glm::vec2(1, 1) * (std::sin(rotation / 2) + 1.0F) * 100.0F
    };

    pos += deltaTransform.translation;
    rotation += deltaTransform.rotation;
    scale = deltaTransform.scale;
    for (auto &child : m_Children) {
        child->Update(deltaTransform);
    }

    LOG_DEBUG("GIRA: x: {}, y: {}", pos.x, pos.y);

}
