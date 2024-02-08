#ifndef CORE_TEXTURE_UTILS_HPP
#define CORE_TEXTURE_UTILS_HPP

#include "pch.hpp"

#include "Util/Logger.hpp"

namespace Core {
GLint SdlFormatToGlFormat(Uint32 format);

GLint GlFormatToGlInternalFormat(GLint format);
} // namespace Core

#endif
