#ifndef UTIL_MISSING_TEXTURE_HPP
#define UTIL_MISSING_TEXTURE_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <Util/Logger.hpp>

#include "Base64.hpp"
#include "Core/MissingFontTextureBase64.hpp"
#include "Core/MissingImageTextureBase64.hpp"

static constexpr auto MISSING_FONT_TEXTURE_BASE64_DECODE_LENGTH =
    DecodeBase64Length(MISSING_FONT_TEXTURE);
static constexpr auto MISSING_FONT_TEXTURE_BASE64_DECODE =
    DecodeBase64<MISSING_FONT_TEXTURE_BASE64_DECODE_LENGTH>(
        MISSING_FONT_TEXTURE);

static constexpr auto MISSING_IMAGE_TEXTURE_BASE64_DECODE_LENGTH =
    DecodeBase64Length(MISSING_IMAGE_TEXTURE);
static constexpr auto MISSING_IMAGE_TEXTURE_BASE64_DECODE =
    DecodeBase64<MISSING_IMAGE_TEXTURE_BASE64_DECODE_LENGTH>(
        MISSING_IMAGE_TEXTURE);

namespace Util {
SDL_Surface *GetMissingFontTextureSDLSurface();
SDL_Surface *GetMissingImageTextureSDLSurface();
} // namespace Util

#endif
