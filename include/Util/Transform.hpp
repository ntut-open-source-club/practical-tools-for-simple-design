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

    Transform &SetTranslation(const glm::vec2 &translation);
    Transform &SetRotation(float radians);
    Transform &SetScale(const glm::vec2 &scale);

    glm::vec2 GetTranslation() const;
    float GetRotation() const;
    glm::vec2 GetScale() const;

public:
    // FIXME: Hide `Transform` implementation, TBD
    glm::mat4 GetMat4() const;

private:
    // TODO: Use public variables like Unity, TBD
    glm::vec2 m_Translation = {0, 0};
    float m_Rotation = 0;
    glm::vec2 m_Scale = {1, 1};
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
