#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
class Transform {
public:
    Transform() : m_Mat3(glm::mat3(1.0F)) {};

    Transform Rotate(float radians) const;
    Transform Translate(const glm::vec2& translation) const;
    Transform Scale(const glm::vec2& scale) const;

    void SetRotation(float radians);
    void SetTranslation(const glm::vec2& translation);
    void SetScale(const glm::vec2& scale);

    float GetRotation() const;
    glm::vec2 GetTranslation() const;
    glm::vec2 GetScale() const;

    Transform operator*(const Transform& other) { return {m_Mat3 * other.m_Mat3}; }
    
protected:
    glm::mat3 m_Mat3;
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
