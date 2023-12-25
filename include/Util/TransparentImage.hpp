#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Core/TransparentImageBase64.hpp"
#include "Base64.hpp"

constexpr auto transparentImageBase64Decode = DecodeBase64<DecodeBase64Length(TRANSPARENT_IMAGE)>(TRANSPARENT_IMAGE);

SDL_Surface* GetTransparentImageSDLSurface(){
    SDL_RWops* rwop = SDL_RWFromConstMem(transparentImageBase64Decode.data(), transparentImageBase64Decode.size());
    SDL_Surface* aSurface = IMG_LoadTyped_RW(rwop, 1, "PNG");

    if (aSurface == nullptr) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}