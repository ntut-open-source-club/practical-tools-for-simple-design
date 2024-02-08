#include "GiraffeText.hpp"

#include "Util/Color.hpp"
#include "Util/Time.hpp"

void GiraffeText::Start() {
    m_Text = std::make_unique<Util::Text>(m_Font, m_Size, "0",
                                          Util::Color(1, 1, 1, 1));
    SetDrawable(m_Text);
}

void GiraffeText::Update(const Util::Transform &transform) {
    // auto &pos = m_Transform.translation;
    // auto &scale = m_Transform.scale;
    // auto &rotation = m_Transform.rotation;

    // pos = transform.translation;
    // rotation = std::fmod(rotation + 50.0F, 360.0F);
    // scale = transform.scale;
    m_Text->SetText(fmt::format("{:.02f}", 1.0F / Util::Time::GetDeltaTime()));

    m_Text->SetColor({1, 0, 0, 1});

    // LOG_DEBUG("{} {}", scale.x, scale.y);

    m_Drawable->Draw(m_Transform, m_ZIndex);
}
