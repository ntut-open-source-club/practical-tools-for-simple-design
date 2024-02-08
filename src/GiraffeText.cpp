#include "GiraffeText.hpp"

#include "Util/Color.hpp"
#include "Util/Time.hpp"

void GiraffeText::Start() {
    m_Text = std::make_unique<Util::Text>(m_Font, m_Size, "0",
                                          Util::Color(1, 1, 1, 1));
    SetDrawable(m_Text);
}

void GiraffeText::Update() {
    m_Text->SetText(fmt::format("{:.02f}", 1.0F / Util::Time::GetDeltaTime()));

    m_Text->SetColor({1, 0, 0, 1});
}
