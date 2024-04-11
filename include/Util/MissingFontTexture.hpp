#ifndef UTIL_MISSING_FONT_TEXTURE_HPP
#define UTIL_MISSING_FONT_TEXTURE_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <Util/Logger.hpp>

#include "Base64.hpp"
#include "Core/MissingFontTextureBase64.hpp"

static constexpr auto MISSING_FONT_TEXTURE_BASE64_DECODE_LENGTH =
    DecodeBase64Length(MISSING_FONT_TEXTURE);
static constexpr auto MISSING_FONT_TEXTURE_BASE64_DECODE =
    DecodeBase64<MISSING_FONT_TEXTURE_BASE64_DECODE_LENGTH>(
        MISSING_FONT_TEXTURE);

SDL_Surface *GetMissingFontTextureSDLSurface();

#endif
