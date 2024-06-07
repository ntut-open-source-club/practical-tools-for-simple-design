#include <SDL.h>
#include <SDL_image.h>
#include <Util/Logger.hpp>

#include "Util/MissingTexture.hpp"

namespace Util {
SDL_Surface *GetMissingImageTextureSDLSurface() {
    SDL_RWops *rwop =
        SDL_RWFromConstMem(MISSING_IMAGE_TEXTURE_BASE64_DECODE.data(),
                           MISSING_IMAGE_TEXTURE_BASE64_DECODE.size());
    SDL_Surface *aSurface = IMG_LoadTyped_RW(rwop, 1, "PNG");

    if (aSurface == nullptr) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}

SDL_Surface *GetMissingFontTextureSDLSurface() {
    SDL_RWops *rwop =
        SDL_RWFromConstMem(MISSING_FONT_TEXTURE_BASE64_DECODE.data(),
                           MISSING_FONT_TEXTURE_BASE64_DECODE.size());
    SDL_Surface *aSurface = IMG_LoadTyped_RW(rwop, 1, "JPG");

    if (aSurface == nullptr) {
        LOG_ERROR("base64ToSurface");
    }

    return aSurface;
}
} // namespace Util
