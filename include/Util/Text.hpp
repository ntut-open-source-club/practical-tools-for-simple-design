#ifndef UTIL_TEXT_HPP
#define UTIL_TEXT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"

namespace Util {
class Text {
public:
    Text(const std::string &font, int size, const std::string &text,
         const glm::mat3 &transform = {});

    void Draw();

private:
    std::unique_ptr<Core::Drawable> m_Drawable;

    std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface;
    std::unique_ptr<Core::Texture> m_Texture;
};
} // namespace Util

#endif
