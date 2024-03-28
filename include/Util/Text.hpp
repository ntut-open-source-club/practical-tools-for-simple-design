#ifndef UTIL_TEXT_HPP
#define UTIL_TEXT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/AssetStore.hpp"
#include "Util/Color.hpp"
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
    enum class Alignment {
        LEFT = TTF_WRAPPED_ALIGN_LEFT,
        CENTER = TTF_WRAPPED_ALIGN_CENTER,
        RIGHT = TTF_WRAPPED_ALIGN_RIGHT,
    };

    /**
     * @brief Constructor for the Text class.
     *
     * @param font The font to use for the text.
     * @param size The size of the text.
     * @param text The actual text content.
     * @param color The color of the text (default is gray).
     * @param alignment The alignment of the text (default is right-aligned).
     * @param wrapLength The maximum length at which text should wrap (default
     * is 0, no wrapping).
     */
    Text(const std::string &font, int size, const std::string &text,
         const Util::Color &color = Color(127, 127, 127),
         Alignment alignment = Alignment::LEFT, int wrapLength = 0);

    glm::vec2 GetSize() const override { return m_Size; };

    /**
     * @brief Sets the text to the specified string.
     *
     * @param text The string to set.
     */
    void SetText(const std::string &text) {
        m_Text = text;
        ApplyTexture();
    }

    /**
     * @brief Sets the color of the text.
     *
     * @param color The color to set.
     */
    void SetColor(const Util::Color &color) {
        m_Color = color;
        ApplyTexture();
    };

    /**
     * @brief Set the maximum length at which text should wrap.
     *
     * The text will only wrap on `\n` when set to 0
     *
     * @param wrapLength The maximum length at which text should wrap.
     */
    void SetWrapLength(int wrapLength) {
        m_WrapLength = wrapLength;
        ApplyTexture();
    }

    /**
     * @brief Set the alignment of the text.
     *
     * @param alignment The alignment to set.
     */
    void SetAlignment(Alignment alignment);

    /**
     * @brief Draws the text with a given transform and z-index.
     *
     * @param transform The transform to apply to the text.
     * @param zIndex The z-index at which to draw the text.
     */
    void Draw(const Transform &transform, const float zIndex) override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    /**
     * @brief Applies the texture to the text.
     * @note The user should call this function after updating the texture in
     * case of custom methods/functions are used.
     */
    void ApplyTexture();

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;

    // loads resources using `TTF_OpenFontRW`
    static Util::AssetStore<std::shared_ptr<SDL_RWops>> s_Store;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;
    std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;

    std::string m_Text;
    Util::Color m_Color;
    glm::vec2 m_Size;
    int m_WrapLength;
};
} // namespace Util

#endif
