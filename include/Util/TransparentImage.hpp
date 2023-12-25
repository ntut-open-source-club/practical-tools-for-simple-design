#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Core/TransparentImageBase64.hpp"
#include "Base64.hpp"

const auto TRANSPARENT_IMAGE_BASE64_DECODE_LENGTH = DecodeBase64Length(TRANSPARENT_IMAGE);
const auto TRANSPARENT_IMAGE_BASE64_DECODE = DecodeBase64<TRANSPARENT_IMAGE_BASE64_DECODE_LENGTH>(TRANSPARENT_IMAGE);

SDL_Surface* GetTransparentImageSDLSurface(){
    SDL_RWops* rwop = SDL_RWFromConstMem(TRANSPARENT_IMAGE_BASE64_DECODE.data(), TRANSPARENT_IMAGE_BASE64_DECODE.size());
    SDL_Surface* aSurface = IMG_LoadTyped_RW(rwop, 1, "PNG");

    if (aSurface == nullptr) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}