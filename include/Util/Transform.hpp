#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
class Transform {
public:
    Transform()
        : m_Mat3(glm::mat3(1.0F)){};

    Transform Translate(const glm::vec2 &translation) const;
    Transform Rotate(float radians) const;
    Transform Scale(const glm::vec2 &scale) const;

    void SetTranslation(const glm::vec2 &translation);
    void SetRotation(float radians);
    void SetScale(const glm::vec2 &scale);

    glm::vec2 GetTranslation() const;
    float GetRotation() const;
    glm::vec2 GetScale() const;

    Transform operator*(const Transform &other) {
        return {m_Mat3 * other.m_Mat3};
    }

protected:
    Transform(glm::mat3 mat3)
        : m_Mat3(mat3){};
    glm::mat3 m_Mat3;
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
