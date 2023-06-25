#include "Util/Image.hpp"

namespace Util {
Image::Image(const std::string &filepath, const glm::mat3 &transform)
    : Core::Drawable(transform),
      m_Surface(IMG_Load(filepath.c_str()), SDL_FreeSurface) {
    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    m_Mode = m_Surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
}

void Image::Draw() {
    s_Program->Bind();
}
} // namespace Util
