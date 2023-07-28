#include "Util/Transform.hpp"

namespace Util {
Transform Transform::Rotate(float radians) const {
    glm::mat3 rotationMatrix = {
        std::cos(radians) , std::sin(radians), 0.0F,
        -std::sin(radians), std::cos(radians), 0.0F,
        0.0F              ,  0.0F            , 1.0F,
    }; // dont forget transpose your view
    return Transform(rotationMatrix * m_Mat3);
}

Transform Transform::Translate(const glm::vec2& t) const {   
    glm::mat3 translationMatrix = {
        1.0F, 0.0F, 0.0F,
        0.0F, 1.0F, 0.0F,
        t.x , t.y , 1.0F,
    }; // dont forget transpose your view
    return Transform(translationMatrix * m_Mat3);
}

Transform Transform::Scale(const glm::vec2& s) const {
    glm::mat3 scaleMatrix = {
        s.x , 0.0F, 0.0F,
        0.0F, s.y , 0.0F,
        0.0F, 0.0F, 1.0F,
    };
    return Transform(scaleMatrix * m_Mat3);
}
} // namespace Util
