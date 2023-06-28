#include "Util/Image.hpp"

#include "Core/Texture.hpp"

namespace Util {
Image::Image(const std::string &filepath, const glm::mat3 &transform) {
    m_Surface = {IMG_Load(filepath.c_str()), SDL_FreeSurface};

    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    m_Drawable = std::make_unique<Core::Drawable>(transform);

    m_Texture = std::make_unique<Core::Texture>(
        m_Surface->format->BytesPerPixel, m_Surface->w, m_Surface->h,
        m_Surface->pixels);
}

void Image::Draw() {
    m_Texture->Bind(m_Drawable->GetUniformSurfaceLocation());
    m_Drawable->Draw();
}
} // namespace Util
