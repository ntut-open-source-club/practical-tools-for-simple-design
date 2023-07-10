#ifndef UTIL_IMAGE_HPP
#define UTIL_IMAGE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"

namespace Util {
class Image : public Core::Drawable {
public:
    Image(const std::string &filepath, glm::mat3 transform = {});

    void Draw() override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    glm::mat3 m_Transform;
    std::unique_ptr<Core::Texture> m_Texture = nullptr;
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface =
        nullptr;

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;
};
} // namespace Util

#endif
