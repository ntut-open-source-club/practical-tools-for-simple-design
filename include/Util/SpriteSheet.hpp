#ifndef UTIL_SPRITESHEET_HPP
#define UTIL_SPRITESHEET_HPP

#include "Core/Drawable.hpp"
#include "SDL_rect.h"
#include "Util/Image.hpp"
#include "Util/Logger.hpp"
#include <memory>
namespace Util {
class SpriteSheet : public Core::Drawable {
public:
    SpriteSheet(const std::string &filepath);
    /**
     * @brief Draws the image with a given transform and z-index.
     *
     * This function draws the image at the specified z-index and applies the
     * given transform.
     *
     * @param transform The transform to apply to the image.
     * @param zIndex The z-index at which to draw the image.
     */
    void Draw(const Util::Transform &transform, const float zIndex) override;
    /**
     * @brief Retrieves the size of the image.
     *
     * This function returns the size of the image.
     *
     * @return The size of the image as a vec2(x, y).
     */
    glm::vec2 GetSize() const override;
    /**
     * @brief Sets the image to the specified file path.
     *
     * This function sets the image to the specified file path.
     * it will reset the DrawRect
     *
     * @param filepath The file path to the image.
     */
    void SetImage(const std::string &filepath);

    /**
     * @brief Set draw range.
     *
     * @param displayRect The Rect of draw range
     */
    void SetDrawRect(const SDL_Rect displayRect);

    void RestDrawRect();

private:
    std::unique_ptr<Image> m_Image;
    SDL_Rect m_OriginRect;
};

} // namespace Util

#endif
