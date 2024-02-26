#ifndef UTIL_MISSING_TEXTURE_HPP
#define UTIL_MISSING_TEXTURE_HPP

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <Util/Logger.hpp>

#include "Base64.hpp"
#include "Core/MissingTextureBase64.hpp"

static constexpr auto MISSING_TEXTURE_BASE64_DECODE_LENGTH = DecodeBase64Length(MISSING_TEXTURE);
static constexpr auto MISSING_TEXTURE_BASE64_DECODE = DecodeBase64<MISSING_TEXTURE_BASE64_DECODE_LENGTH>(MISSING_TEXTURE);

SDL_Surface* GetMissingTextureSDLSurface();

#endif
