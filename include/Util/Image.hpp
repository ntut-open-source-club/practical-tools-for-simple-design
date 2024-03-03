#ifndef UTIL_IMAGE_HPP
#define UTIL_IMAGE_HPP

#include "SDL_surface.h"
#include "pch.hpp" // IWYU pragma: export

#include <functional>
#include <glm/fwd.hpp>
#include <memory>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"
#include "Util/Transform.hpp"

namespace Util {
/**
 * @class Image
 * @brief A class representing an image.
 *
 * This class encapsulates the properties and behaviors of an image.
 * It includes properties such as texture and surface.
 * It also includes behaviors such as drawing the image.
 */
class Image : public Core::Drawable {
public:
    /**
     * @brief Constructor that takes a file path to the image.
     *
     * @param filepath The file path to the image.
     */
    explicit Image(const std::string &filepath);

    /**
     * @brief Retrieves the size of the image.
     *
     * This function returns the size of the image.
     *
     * @return The size of the image as a vec2(x, y).
     */
    glm::vec2 GetSize() const override { return m_Size; };

    /**
     * @brief Sets the image to the specified file path.
     *
     * This function sets the image to the specified file path.
     *
     * @param filepath The file path to the image.
     */
    void SetImage(const std::string &filepath);

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
     * @brief Get the SDL_Surface that current draw.
     *
     * This function return the SDL_Surface that current draw.
     *
     */
    SDL_Surface &GetSDLSurface() const { return *m_Surface.get(); }
    /**
     * @brief Update TextureDate by SDL_Surface
     *
     * This function Update TextureDate by SDL_Surface.
     *
     */
    void UpdateTextureData(const SDL_Surface &surface);

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface;
    std::string m_Path;
    glm::vec2 m_Size;
};
} // namespace Util

#endif
