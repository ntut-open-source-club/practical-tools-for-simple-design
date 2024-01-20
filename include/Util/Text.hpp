#ifndef UTIL_TEXT_HPP
#define UTIL_TEXT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"
#include "Util/Transform.hpp"

namespace Util {
class Text : public Core::Drawable {
public:
    Text(const std::string &font, int size, const std::string &text);

    void Draw(const Transform &transform, const float zIndex) override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer(const Util::Transform &transform = Util::Transform(),
                           const float zIndex = -1);

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface =
        nullptr;

    std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;
};
} // namespace Util

#endif
