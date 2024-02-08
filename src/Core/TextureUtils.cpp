#include "Core/TextureUtils.hpp"

namespace Core {
GLint SdlFormatToGlFormat(Uint32 format) {
    switch (format) {
    case SDL_PIXELFORMAT_RGB24:
        return GL_RGB;
    case SDL_PIXELFORMAT_BGR24:
        return GL_BGR;
    case SDL_PIXELFORMAT_XRGB8888:
    case SDL_PIXELFORMAT_ARGB8888:
        return GL_BGRA;
    case SDL_PIXELFORMAT_XBGR8888:
    case SDL_PIXELFORMAT_ABGR8888:
        return GL_RGBA;
    default:
        LOG_ERROR("Format currently unsupported: {}",
                  SDL_GetPixelFormatName(format));
        return -1;
    }
}

GLint GlFormatToGlInternalFormat(GLint format) {
    switch (format) {
    case GL_RGB:
    case GL_BGR:
        return GL_RGB16;
    case GL_RGBA:
    case GL_BGRA:
        return GL_RGBA16;
    default:
        LOG_ERROR("Format currently unsupported");
        return -1;
    }
}
} // namespace Core
