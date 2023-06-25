#ifndef UTIL_IMAGE_HPP
#define UTIL_IMAGE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"

#include "Util/Logger.hpp"

namespace Util {
class Image final : public Core::Drawable {
public:
    Image(const std::string &filepath, const glm::mat3 &transform);

    void Draw() override;

private:
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface;

    unsigned int m_Mode;
};
} // namespace Util

#endif
