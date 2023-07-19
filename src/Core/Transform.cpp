#include "Core/Transform.hpp"

namespace Core {
Transform Transform::RotatedByRadians(float radians) const {
    glm::mat3 rotationMatrix = {
        std::cos(radians) , std::sin(radians), 0.0f,
        -std::sin(radians), std::cos(radians), 0.0f,
        0.0f              ,  0.0f            , 1.0f,
    }; // dont forget transpose your view
    return Transform(rotationMatrix * m_mat3);
}

Transform Transform::Translated(const glm::vec2& t) const {
    glm::mat3 translationMatrix = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        t.x , t.y , 1.0f,
    }; // dont forget transpose your view
    return Transform(translationMatrix * m_mat3);
}

Transform Transform::Scaled(const glm::vec2& s) const {
    glm::mat3 scaleMatrix = {
        s.x , 0.0f, 0.0f,
        0.0f, s.y , 0.0f,
        0.0f, 0.0f, 1.0f,
    };
    return Transform(scaleMatrix * m_mat3);
}
} // namespace Core
