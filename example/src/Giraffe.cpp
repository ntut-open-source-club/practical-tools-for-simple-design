#include "Giraffe.hpp"

#include <cmath>

#include "Util/Time.hpp"
#include "Util/Transform.hpp"

#include "config.hpp"

void Giraffe::Start() {
    m_GiraffeText =
        std::make_shared<GiraffeText>("../assets/fonts/Inter.ttf", 50);
    m_GiraffeText->SetZIndex(this->GetZIndex() - 1);
    m_GiraffeText->Start();
    this->AddChild(m_GiraffeText);
}

void Giraffe::Update() {
    static glm::vec2 dir = {1, 0.5};

    auto &pos = m_Transform.translation;
    auto &scale = m_Transform.scale;
    auto &rotation = m_Transform.rotation;

    if (pos.y >= static_cast<float>(WINDOW_HEIGHT) / 2 ||
        pos.y + static_cast<float>(WINDOW_HEIGHT) / 2 <= 0) {
        dir.y *= -1;
    }
    if (pos.x >= static_cast<float>(WINDOW_WIDTH) / 2 ||
        pos.x + static_cast<float>(WINDOW_WIDTH) / 2 <= 0) {
        dir.x *= -1;
    }

    // sonarcloud called it redundant, but ms_t = float is just a coincidence.
    auto delta = static_cast<float>(Util::Time::GetDeltaTimeMs());
    Util::Transform deltaTransform{
        dir * delta, 0.002F * delta,
        glm::vec2(1, 1) * (std::sin(rotation / 2) + 1.0F) * 100.0F};

    pos += deltaTransform.translation;
    rotation += deltaTransform.rotation;

    m_GiraffeText->Update();
}
