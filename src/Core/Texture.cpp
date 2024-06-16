#include "Core/Texture.hpp"

#include "Core/TextureUtils.hpp"

#include "Util/Logger.hpp"

namespace Core {
Texture::Texture(GLint format, int width, int height, const void *data,
                 bool useAA) {
    glGenTextures(1, &m_TextureId);
    UseAntiAliasing(useAA);
    UpdateData(format, width, height, data);
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
void Texture::UpdateData(GLint format, int width, int height,
                         const void *data) {
    glBindTexture(GL_TEXTURE_2D, m_TextureId);

    // Reference:
    // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml
    glTexImage2D(GL_TEXTURE_2D, 0, GlFormatToGlInternalFormat(format), width,
                 height, 0, format, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_MinFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_MagFilter);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::UseAntiAliasing(bool useAA) {
    /**
     * additional docs
     * https://www.khronos.org/opengl/wiki/Texture
     * https://www.khronos.org/opengl/wiki/Sampler_Object#Sampling_parameters
     */
    if (useAA) {
        m_MinFilter = GL_LINEAR_MIPMAP_LINEAR;
        m_MagFilter = GL_LINEAR;
    } else {
        m_MinFilter = GL_NEAREST_MIPMAP_NEAREST;
        m_MagFilter = GL_NEAREST;
    }
}
} // namespace Core
