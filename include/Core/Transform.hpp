#ifndef CORE_TRANSFORM_HPP
#define CORE_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Core {
class Transform {
public:
    Transform() : m_mat3(glm::mat3(1.0f)) {};
    Transform(glm::mat3 mat3) : m_mat3(mat3) {};

    Transform Rotate(float degrees) const { return RotateByRadians(glm::radians(degrees)); }
    Transform RotateByRadians(float radians) const;

    Transform Translate(const glm::vec2& translation) const;
    Transform Translate(float x, float y) const { return Translate(glm::vec2(x,y)); }

    Transform Scale(const glm::vec2& scale) const;
    Transform Scale(float x, float y) const { return Scale(glm::vec2(x,y)); }

    /* wrapped operator */
    Transform operator*(Transform const& other) { return Transform(m_mat3 * other.m_mat3); }
    
    /* unwrap (getter) */
    glm::mat3 Mat3() const { return m_mat3; }
protected:
    glm::mat3 m_mat3;
};
} // namespace Core

#endif /* CORE_TRANSFORM_HPP */
