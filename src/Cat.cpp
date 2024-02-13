#include "Cat.hpp"

Cat::Cat()
    : m_Animation(
          {
              "../assets/sprites/cat/cat-0.bmp",
              "../assets/sprites/cat/cat-1.bmp",
              "../assets/sprites/cat/cat-2.bmp",
              "../assets/sprites/cat/cat-3.bmp",
              "../assets/sprites/cat/cat-4.bmp",
              "../assets/sprites/cat/cat-5.bmp",
              "../assets/sprites/cat/cat-6.bmp",
              "../assets/sprites/cat/cat-7.bmp",
          },
          100) {
    m_Transform.translation = {-200, 200};
}

void Cat::Update() {
    m_Drawable = m_Animation.GetCurrentFrame();
}
