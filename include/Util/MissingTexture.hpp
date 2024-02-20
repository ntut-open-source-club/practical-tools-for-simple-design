#ifndef UTIL_TRANSPARENT_IMAGE_HPP
#define UTIL_TRANSPARENT_IMAGE_HPP

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <Util/Logger.hpp>

#include "Base64.hpp"
#include "Core/MissingTextureBase64.hpp"

static constexpr auto MISSING_TEXTURE_BASE64_DECODE_LENGTH = DecodeBase64Length(MISSING_TEXTURE);
static constexpr auto MISSING_TEXTURE_BASE64_DECODE = DecodeBase64<MISSING_TEXTURE_BASE64_DECODE_LENGTH>(MISSING_TEXTURE);

SDL_Surface* GetMissingTextureSDLSurface(){
    SDL_RWops* rwop = SDL_RWFromConstMem(MISSING_TEXTURE_BASE64_DECODE.data(), MISSING_TEXTURE_BASE64_DECODE.size());
    SDL_Surface* aSurface = IMG_LoadTyped_RW(rwop, 1, "PNG");

    if (aSurface == nullptr) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}

#endif
