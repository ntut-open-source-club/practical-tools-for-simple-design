#include "Util/Transform.hpp"

namespace Util {

// NOLINTBEGIN(readability-identifier-length)
// NOLINTBEGIN(readability-magic-numbers)

Transform Transform::Rotate(float r) const {
    glm::mat3 rotationMatrix = {
        std::cos(r),  std::sin(r), 0.0F, //
        -std::sin(r), std::cos(r), 0.0F, //
        0.0F,         0.0F,        1.0F, //
    };                                   // dont forget transpose your view
    return {rotationMatrix * m_Mat3};
}

Transform Transform::Translate(const glm::vec2 &t) const {
    glm::mat3 translationMatrix = {
        1.0F, 0.0F, 0.0F, //
        0.0F, 1.0F, 0.0F, //
        t.x,  t.y,  1.0F, //
    };                    // dont forget transpose your view
    return {translationMatrix * m_Mat3};
}

Transform Transform::Scale(const glm::vec2 &s) const {
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
        std::cos(r) * es.x,  std::sin(r) * es.y, 0,   //
        -std::sin(r) * es.x, std::cos(r) * es.y, 0,   //
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
        std::cos(er) * s.x,  std::sin(er) * s.y, 0,   //
        -std::sin(er) * s.x, std::cos(er) * s.y, 0,   //
        m_Mat3[2][0],   m_Mat3[2][1],  1.0f //
    };                                      // dont forget transpose your view
}

float Transform::GetRotation() const {
    auto radians = std::atan2(m_Mat3[0][1], m_Mat3[0][0]);
    return static_cast<float>(radians >= 0 ? radians : radians + 4 * std::acos(0.0));
}

glm::vec2 Transform::GetTranslation() const {
    return {m_Mat3[2][0], m_Mat3[2][1]};
}

glm::vec2 Transform::GetScale() const {
    return {glm::length(glm::vec2(m_Mat3[0][0], m_Mat3[1][0])),
            glm::length(glm::vec2(m_Mat3[0][1], m_Mat3[1][1]))};
}

// NOLINTEND(readability-identifier-length)
// NOLINTEND(readability-magic-numbers)

} // namespace Util
