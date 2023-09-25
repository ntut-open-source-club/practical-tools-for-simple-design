#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {

class Transform {
public:
    Transform() = default;

    Transform Translate(const glm::vec2 &translation) const;
    Transform Rotate(float radians) const;
    Transform Scale(const glm::vec2 &scale) const;

    void SetTranslation(const glm::vec2 &translation);
    void SetRotation(float radians);
    void SetScale(const glm::vec2 &scale);

    glm::vec2 GetTranslation() const;
    float GetRotation() const;
    glm::vec2 GetScale() const;

//    Transform operator*(const Transform &other) {
//        return {m_Mat4 * other.m_Mat4};
//    }

public:
    glm::mat4 GetMat4() {
        constexpr glm::mat4 eye(1.F);

        return glm::translate(eye, {m_Translation,0}) *
            glm::rotate(eye, m_Rotation, glm::vec3(0,0,1)) *
            glm::scale(eye, {m_Scale,1});
    }

private:
    glm::vec2 m_Translation = {0, 0};
    float m_Rotation = 0;
    glm::vec2 m_Scale = {1, 1};
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
