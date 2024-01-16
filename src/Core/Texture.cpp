#include "Core/Texture.hpp"

#include "Util/Logger.hpp"

GLint ChannelsToInternalFormat(unsigned int channels) {
    switch (channels) {
    case 3:
        return GL_RGB16;
    case 4:
        return GL_RGBA16;
    default:
        LOG_ERROR("Format currently unsupported");
        return -1;
    }
};

GLint ChannelsToFormat(unsigned int channels) {
    // Since the color channel in MacOS is invert, we need to return the channel by the condition.
    // Solved #57
    switch (channels) {
    case 3:
#ifdef __APPLE__
        return GL_BGR;
#else
        return GL_RGB;
#endif
    case 4:
#ifdef __APPLE__
        return GL_BGRA;
#else
        return GL_RGBA;
#endif
    default:
        LOG_ERROR("Format currently unsupported");
        return -1;
    }
};

namespace Core {
Texture::Texture(unsigned int channels, int width, int height,
                 const void *data) {
    glGenTextures(1, &m_TextureId);
    UpdateData(channels, width, height, data);
}

Texture::Texture(Texture &&texture) {
    m_TextureId = texture.m_TextureId;
    texture.m_TextureId = 0;
}

Texture::~Texture() {
    glDeleteTextures(1, &m_TextureId);
}

Texture &Texture::operator=(Texture &&other) {
    m_TextureId = other.m_TextureId;
    other.m_TextureId = 0;
    return *this;
}

void Texture::Bind(int slot) const {
    int maxCount;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxCount);

    if (slot >= maxCount) {
        LOG_ERROR("Maximum texture count exceeded");
        return;
    }

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_TextureId);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 * Although this function doesn't modify it's object state, it changes states in
 * OpenGL under the hood, so it doesn't make sense to mark it as `const`
 */
// NOLINTNEXTLINE(readability-make-member-function-const)
void Texture::UpdateData(unsigned int channels, int width, int height,
                         const void *data) {
    glBindTexture(GL_TEXTURE_2D, m_TextureId);

    glTexImage2D(GL_TEXTURE_2D, 0, ChannelsToInternalFormat(channels), width,
                 height, 0, ChannelsToFormat(channels), GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
} // namespace Core
