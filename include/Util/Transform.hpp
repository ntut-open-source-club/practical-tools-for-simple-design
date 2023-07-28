#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
class Transform {
public:
    Transform() : m_Mat3(glm::mat3(1.0F)) {};
    Transform(glm::mat3 mat3) : m_Mat3(mat3) {};

    Transform Rotate(float radians) const;

    Transform Translate(const glm::vec2& translation) const;

    Transform Scale(const glm::vec2& scale) const;

    /* wrapped operator */
    Transform operator*(Transform const& other) { return {m_Mat3 * other.m_Mat3}; }
    
    /* unwrap (getter) */
    glm::mat3 Mat3() const { return m_Mat3; }
protected:
    glm::mat3 m_Mat3;
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
