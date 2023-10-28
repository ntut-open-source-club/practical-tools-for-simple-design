
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Util/Transform.hpp"
#include "Util/GameObject.hpp"
#include "Giraffe.hpp"
#include "Util/Time.hpp"
#include "config.hpp"


void GiraffeText::Update() {

}

void GiraffeText::Start() {
    this->SetDrawable(std::make_unique<Util::Text>(m_Font, m_Size, m_Text));
}

void Giraffe::Start() {
    SetDrawable(std::make_unique<Util::Image>("../assets/sprites/giraffe.png"));
    auto gf = std::make_shared<GiraffeText>("../assets/fonts/Inter.ttf", 500, "Giraffe");
    gf->Start();
    AppendChild(gf);
}

void Giraffe::Update() {
    static glm::vec2 dir = {1, 0.5};

    auto &pos =m_Drawable->m_Transform.translation;
    auto &scale = m_Drawable->m_Transform.scale;
    auto &rotation = m_Drawable->m_Transform.rotation;

    if (pos.y > WINDOW_HEIGHT || pos.y + WINDOW_HEIGHT < 0) {
        dir.y *= -1;
    }
    if (pos.x > WINDOW_WIDTH || pos.x + WINDOW_WIDTH < 0) {
        dir.x *= -1;
    }

    auto delta = static_cast<float>(Util::Time::GetDeltaTime());
    pos += dir * delta * 1000.0F;
    rotation += 2 * delta;
    scale = glm::vec2(1, 1) * (std::sin(rotation / 2) + 1.0F) * 100.0F;

    LOG_DEBUG("GIRA: x: {}, y: {}", pos.x, pos.y);

}
