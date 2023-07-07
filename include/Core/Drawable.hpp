#ifndef CORE_DRAWABLE_HPP
#define CORE_DRAWABLE_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Core/Program.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"
#include "Texture.hpp"

namespace Core {
struct Matrices {
    glm::mat2 m_Model;
    glm::mat2 m_Projection;
};

/**
 * Currently the shader only has one texture but this reserves space for
 * multi-texture support in the future
 */
constexpr int UNIFORM_SURFACE_LOCATION = 0;

class Drawable {
public:

    virtual void Draw() = 0;

    int GetUniformSurfaceLocation() const { return UNIFORM_SURFACE_LOCATION; }

protected:
    glm::mat3 m_Transform;

    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>> m_Surface =
        nullptr;
    std::unique_ptr<Texture> m_Texture = nullptr;

private:
};
} // namespace Core

#endif
