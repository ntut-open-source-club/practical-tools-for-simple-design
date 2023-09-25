#ifndef CORE_DRAWABLE_HPP
#define CORE_DRAWABLE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

#include "Core/Program.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"
#include "Texture.hpp"

namespace Core {
struct Matrices {
    glm::mat4 m_Model;
    glm::mat4 m_Projection;
};

class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void Draw() = 0;
};
} // namespace Core

#endif
