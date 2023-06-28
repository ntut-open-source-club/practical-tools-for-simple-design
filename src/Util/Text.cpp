#include "Util/Text.hpp"

#include "Core/Texture.hpp"

namespace Util {
Text::Text(const std::string &font, int size, const std::string &text,
           const glm::mat3 &transform) {
    m_Font = {TTF_OpenFont(font.c_str(), size), TTF_CloseFont};

    if (m_Font == nullptr) {
        LOG_ERROR("Failed to load font: '{}'", text);
        LOG_ERROR("{}", TTF_GetError());
    }

    m_Surface = {TTF_RenderUTF8_Blended_Wrapped(m_Font.get(), text.c_str(),
                                                SDL_Color{255, 0, 255, 0}, 0),
                 SDL_FreeSurface};

    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to create text");
        LOG_ERROR("{}", TTF_GetError());
    }

    m_Drawable = std::make_unique<Core::Drawable>(transform);

    m_Texture = std::make_unique<Core::Texture>(
        m_Surface->format->BytesPerPixel,
        m_Surface->pitch / m_Surface->format->BytesPerPixel, m_Surface->h,
        m_Surface->pixels);
}

void Text::Draw() {
    m_Texture->Bind(m_Drawable->GetUniformSurfaceLocation());
    m_Drawable->Draw();
}
} // namespace Util
