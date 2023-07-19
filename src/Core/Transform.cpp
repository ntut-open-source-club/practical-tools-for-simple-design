#include "Core/Transform.hpp"

namespace Core {
Transform Transform::RotateByRadians(float radians) const {
    glm::mat3 rotationMatrix = {
        std::cos(radians), -std::sin(radians), 0,
        std::sin(radians),  std::cos(radians), 0,
        0                ,  0                , 1,
    };
    return Transform(rotationMatrix * m_mat3);
}

Transform Transform::Translate(const glm::vec2& translation) const {   
    glm::mat3 translationMatrix(1.0f);
    translationMatrix[2] = glm::vec3(translation, 1.0f);

    return Transform(translationMatrix * m_mat3);
}

Transform Transform::Scale(const glm::vec2& scale) const {
    glm::mat3 scaleMatrix(1.0f);
    scaleMatrix[0][0] = scale.x;
    scaleMatrix[1][1] = scale.y;

    return Transform(scaleMatrix * m_mat3);
}
} // namespace Core
