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
    };                    // dont forget transpose your view
    return {scaleMatrix * m_Mat3};
}

void Transform::SetRotation(float r) {
    glm::vec2 es = GetScale(); // existing Scale
    m_Mat3 = {
        cos(r) * es.x,  sin(r) * es.y, 0,   //
        -sin(r) * es.x, cos(r) * es.y, 0,   //
        m_Mat3[2][0],   m_Mat3[2][1],  1.0f //
    };                                      // dont forget transpose your view
}

void Transform::SetTranslation(const glm::vec2 &t) {
    m_Mat3[2][0] = t.x;
    m_Mat3[2][1] = t.y;
}

void Transform::SetScale(const glm::vec2 &s) {
    float er = GetRotation(); // existing Rotation
    m_Mat3 = {
        cos(er) * s.x,  sin(er) * s.y, 0,   //
        -sin(er) * s.x, cos(er) * s.y, 0,   //
        m_Mat3[2][0],   m_Mat3[2][1],  1.0f //
    };                                      // dont forget transpose your view
}

float Transform::GetRotation() const {
    auto radians = atan2(m_Mat3[1][0], m_Mat3[0][0]);
    return radians > 0 ? radians : radians + 4 * acos(0.0);
}

glm::vec2 Transform::GetTranslation() const {
    return {m_Mat3[2][0], m_Mat3[2][1]};
}

glm::vec2 Transform::GetScale() const {
    return {glm::length(glm::vec2(m_Mat3[0][0], m_Mat3[1][0])),
            glm::length(glm::vec2(m_Mat3[0][1], m_Mat3[1][1]))};
}

} // namespace Util
