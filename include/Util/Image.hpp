#ifndef UTIL_IMAGE_HPP
#define UTIL_IMAGE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <glm/fwd.hpp>

#include "Core/Drawable.hpp"
#include "Core/Program.hpp"
#include "Core/Texture.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"

#include "Util/AssetStore.hpp"

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
     * @param useAA Flag indicating whether anti-aliasing should be enabled
     * (default is true).
     */
    Image(const std::string &filepath, bool useAA = true);

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
     * @brief Sets whether anti-aliasing (AA) should be enabled or disabled.
     *
     * @param useAA A boolean value indicating whether anti-aliasing should be
     * enabled (true) or disabled (false).
     *
     * @note This function only sets the internal flag for anti-aliasing and
     * does not directly affect rendering. The actual effect of anti-aliasing
     * depends on the rendering pipeline and the graphics hardware capabilities.
     *
     * @sa https://en.wikipedia.org/wiki/Spatial_anti-aliasing
     */
    void UseAntiAliasing(bool useAA);

    /**
     * @brief Draws the image with a given transform and z-index.
     *
     * This function draws the image at the specified z-index and applies the
     * given transform.
     *
     * @param transform The transform to apply to the image.
     * @param zIndex The z-index at which to draw the image.
     */
    void Draw(const Core::Matrices &data) override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    std::unique_ptr<Core::UniformBuffer<Core::Matrices>> m_UniformBuffer;

    static Util::AssetStore<std::shared_ptr<SDL_Surface>> s_Store;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;

    std::string m_Path;
    glm::vec2 m_Size;
};
} // namespace Util

#endif
