#include "SpriteSheetTester.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/SpriteSheet.hpp"
#include <memory>

SpriteSheetTester::SpriteSheetTester()
    : m_Spritesheet(std::make_shared<Util::SpriteSheet>(
          "../assets/sprites/cat/cat-0.bmp")) {
    m_Transform.translation = {200, -200};
    SetDrawable(m_Spritesheet);
}

void SpriteSheetTester::Update() {
    if (Util::Input::IsKeyDown(Util::Keycode::Y)) {
        m_Spritesheet->SetDrawRect({20, 20, 250, 250});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::Y)) {
        m_Spritesheet->RestDrawRect();
    }
}
