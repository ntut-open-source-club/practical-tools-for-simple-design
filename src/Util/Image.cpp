#include "Util/Image.hpp"

namespace Util {
Image::Image(const std::string &filepath, const glm::mat3 &transform)
    : m_Surface(IMG_Load(filepath.c_str()), SDL_FreeSurface) {
    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    m_Mode = m_Surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;

    m_Drawable = std::make_unique<Core::Drawable>(transform);
}

void Image::Draw() {
    m_Drawable->Draw();
}
} // namespace Util
