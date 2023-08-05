#include "Util/Transform.hpp"

namespace Util {
Transform Transform::Rotate(float r) const { // NOLINT
    glm::mat3 rotationMatrix = {
        std::cos(r),  std::sin(r), 0.0F, //
        -std::sin(r), std::cos(r), 0.0F, //
        0.0F,         0.0F,        1.0F, //
    };                                   // dont forget transpose your view
    return {rotationMatrix * m_Mat3};
}

Transform Transform::Translate(const glm::vec2 &t) const { // NOLINT
    glm::mat3 translationMatrix = {
        1.0F, 0.0F, 0.0F, //
        0.0F, 1.0F, 0.0F, //
        t.x,  t.y,  1.0F, //
    };                    // dont forget transpose your view
    return {translationMatrix * m_Mat3};
}

Transform Transform::Scale(const glm::vec2 &s) const { // NOLINT
    glm::mat3 scaleMatrix = {
        s.x,  0.0F, 0.0F, //
        0.0F, s.y,  0.0F, //
        0.0F, 0.0F, 1.0F, //
    };
    return {scaleMatrix * m_Mat3};
}
} // namespace Util
