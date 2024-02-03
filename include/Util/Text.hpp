#ifndef UTIL_TEXT_HPP
#define UTIL_TEXT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"
#include "Util/Transform.hpp"

namespace Util {

/**
 * @class Text
 * @brief A class representing a text.
 *
 * This class encapsulates the properties and behaviors of a text.
 * It includes properties such as texture and surface.
 * It also includes behaviors such as drawing the text.
 */
class Text : public Core::Drawable {
public:
    /**
     * @brief Constructor that takes a font, size, and text.
     *
     * @param font The font of the text.
     * @param size The size of the text.
     * @param text The text to be displayed.
     */
    Text(const std::string &font, int size, const std::string &text);

    /**
     * @brief Draws the text with a given transform and z-index.
     *
     * @param transform The transform to apply to the text.
     * @param zIndex The z-index at which to draw the text.
     */
    void Draw(const Transform &transform, const float zIndex) override;

private:
    /**
     * @brief Initializes the shader program.
     */
    void InitProgram();

    /**
     * @brief Initializes the vertex array.
     */
    void InitVertexArray();

    /**
     * @brief Initializes the uniform buffer.
     *
     * @param transform The transform to apply to the text.
     * @param zIndex The z-index at which to draw the text.
     */
    void InitUniformBuffer(const Util::Transform &transform = Util::Transform(),
                           const float zIndex = -1);

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;

private:
    /**
     * @brief The texture of the text.
     */
    std::unique_ptr<Core::Texture> m_Texture = nullptr;

    /**
     * @brief The surface of the text.
     */
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface =
        nullptr;

    /**
     * @brief The font of the text.
     */
    std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;
};
} // namespace Util

#endif
