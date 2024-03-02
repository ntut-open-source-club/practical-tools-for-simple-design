#include "SpriteSheetTester.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include <memory>

SpriteSheetTester::SpriteSheetTester()
    : image(std::make_shared<Util::Image>("../assets/sprites/cat/cat-0.bmp")) {
    m_Transform.translation = {200, -200};
    SetDrawable(image);
}

void SpriteSheetTester::Update() {
    if (Util::Input::IsKeyDown(Util::Keycode::Y)) {
        image->SetDrawRect({20, 20, 250, 250});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::Y)) {
        image->SetDrawRect({0, 0, 498, 314});
    }
}
