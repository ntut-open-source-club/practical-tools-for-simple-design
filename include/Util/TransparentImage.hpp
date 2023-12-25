#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Core/TransparentImageBase64.hpp"
#include "Base64.hpp"

SDL_Surface* GetTransparentImageSDLSurface(){
    std::vector<unsigned char> img_vec = base64_decode(transparentImage);
    SDL_RWops* rwop = SDL_RWFromConstMem(&img_vec[0], img_vec.size());
    SDL_Surface* aSurface = IMG_LoadTyped_RW(rwop, 1, "PNG");

    if (aSurface == NULL) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}