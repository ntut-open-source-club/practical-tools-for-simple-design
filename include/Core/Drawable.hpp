#ifndef CORE_DRAWABLE_HPP
#define CORE_DRAWABLE_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Transform.hpp"

namespace Core {
struct Matrices {
    glm::mat4 m_Model;
    glm::mat4 m_Projection;
};

class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void Draw(const Core::Matrices &data) = 0;
    virtual glm::vec2 GetSize() const = 0;
};
} // namespace Core

#endif
