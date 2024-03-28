#include "Util/SpriteSheet.hpp"

namespace Util {
SpriteSheet::SpriteSheet(const std::string &filepath)
    : m_Image(std::make_unique<Image>(filepath)) {
    m_OriginRect.x = 0;
    m_OriginRect.y = 0;
    m_OriginRect.w = m_Image->GetSize().x;
    m_OriginRect.h = m_Image->GetSize().y;
}

void SpriteSheet::SetImage(const std::string &filepath) {
    m_Image->SetImage(filepath);
    m_OriginRect.x = 0;
    m_OriginRect.y = 0;
    m_OriginRect.w = m_Image->GetSize().x;
    m_OriginRect.h = m_Image->GetSize().y;
}

void SpriteSheet::Draw(const Util::Transform &transform, const float zIndex) {
    m_Image->Draw(transform, zIndex);
}

glm::vec2 SpriteSheet::GetSize() const {
    return m_Image->GetSize();
}

void SpriteSheet::RestDrawRect() {
    SetDrawRect(m_OriginRect);
}

void SpriteSheet::SetDrawRect(const SDL_Rect displayRect) {
    // can't just simplely use SDL_SetClipRect, because we use opengl to render
    // and I'm not sure this way if cost a lot performance?
    SDL_Surface &originSDLSurface = m_Image->GetSDLSurface();

    if (displayRect.h + displayRect.y > originSDLSurface.h ||
        displayRect.w + displayRect.x > originSDLSurface.w) {
        LOG_DEBUG("SetDrawRect OverRange");
        return;
    }

    auto targetSurface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
            SDL_CreateRGBSurfaceWithFormat(
                0, displayRect.w, displayRect.h,
                originSDLSurface.format->BitsPerPixel,
                originSDLSurface.format->format),
            SDL_FreeSurface,
        };

    int isCopyWork = SDL_BlitSurface(&originSDLSurface, &displayRect,
                                     targetSurface.get(), NULL);
    if (isCopyWork != 0) {
        LOG_ERROR("{}", SDL_GetError());
        return;
    }
    m_Image->UpdateTextureData(*targetSurface.get());
}

} // namespace Util
