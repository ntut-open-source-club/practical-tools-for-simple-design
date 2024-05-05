#ifndef CORE_TEXTURE_HPP
#define CORE_TEXTURE_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Core {
class Texture {
public:
    Texture(GLint format, int width, int height, const void *data, bool useAA);
    Texture(const Texture &) = delete;
    Texture(Texture &&texture);

    ~Texture();

    Texture &operator=(const Texture &) = delete;
    Texture &operator=(Texture &&other);

    GLuint GetTextureId() const { return m_TextureId; }

    void Bind(int slot) const;
    void Unbind() const;

    void UpdateData(GLint format, int width, int height, const void *data);
    void UseAntiAliasing(bool useAA);

private:
    GLuint m_TextureId;

    GLenum m_MinFilter;
    GLenum m_MagFilter;
};
} // namespace Core

#endif
