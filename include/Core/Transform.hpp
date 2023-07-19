#ifndef CORE_TRANSFORM_HPP
#define CORE_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Core {
class Transform {
public:
    Transform() : m_mat3(glm::mat3(1.0f)) {};
    Transform(glm::mat3 mat3) : m_mat3(mat3) {};

    Transform Rotated(float degrees) const { return RotatedByRadians(glm::radians(degrees)); }
    Transform RotatedByRadians(float radians) const;
    Transform& Rotate(float degrees) { return RotateByRadians(glm::radians(degrees)); }
    Transform& RotateByRadians(float radians) { *this = RotatedByRadians(radians); return *this; }

    Transform Translated(const glm::vec2& translation) const;
    Transform Translated(float x, float y) const { return Translated(glm::vec2(x,y)); }
    Transform& Translate(const glm::vec2& translation) { *this = Translated(translation); return *this; }
    Transform& Translate(float x, float y) { return Translate(glm::vec2(x,y)); }

    Transform Scaled(const glm::vec2& translation) const;
    Transform Scaled(float x, float y) const { return Scaled(glm::vec2(x,y)); }
    Transform& Scale(const glm::vec2& scale) { *this = Scaled(scale); return *this; }
    Transform& Scale(float x, float y) { return Scale(glm::vec2(x,y)); }

    /* wrapped operator */
    Transform operator*(Transform const& other) { return Transform(m_mat3 * other.m_mat3); }
    
    /* unwrap (getter) */
    glm::mat3 Mat3() const { return m_mat3; }
protected:
    glm::mat3 m_mat3;
};
} // namespace Core

#endif /* CORE_TRANSFORM_HPP */
