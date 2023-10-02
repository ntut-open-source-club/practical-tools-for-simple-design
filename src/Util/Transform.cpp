#include "Util/Transform.hpp"

namespace Util {

// NOLINTBEGIN(readability-identifier-length,readability-magic-numbers)

Transform Transform::Rotate(float r) const {
    auto newone = Transform(*this);
    newone.SetRotation(m_Rotation + r);
    return newone;
}

Transform Transform::Translate(const glm::vec2 &t) const {
    auto newone = Transform(*this);
    newone.SetTranslation(m_Translation + t);
    return newone;
}

Transform Transform::Scale(const glm::vec2 &s) const {
    auto newone = Transform(*this);
    newone.SetScale(m_Scale * s);
    return newone;
}

Transform &Transform::SetRotation(float r) {
    // FIXME: Really? I can't do float modulo `\_(:/)_/`
    while (r < 0) {
        r += glm::pi<float>() * 2;
    }
    while (r > glm::pi<float>() * 2) {
        r -= glm::pi<float>() * 2;
    }
    m_Rotation = r;
    return *this;
}

Transform &Transform::SetTranslation(const glm::vec2 &t) {
    m_Translation = t;
    return *this;
}

Transform &Transform::SetScale(const glm::vec2 &s) {
    m_Scale = s;
    return *this;
}

float Transform::GetRotation() const {
    return m_Rotation;
}

glm::vec2 Transform::GetTranslation() const {
    return m_Translation;
}

glm::vec2 Transform::GetScale() const {
    return m_Scale;
}

glm::mat4 Transform::GetMat4() const {
    constexpr glm::mat4 eye(1.F);

    // TODO: TRS comment
    return glm::translate(eye, {m_Translation, 0}) *
           glm::rotate(eye, m_Rotation, glm::vec3(0, 0, 1)) *
           glm::scale(eye, {m_Scale, 1});
}

// NOLINTEND(readability-identifier-length,readability-magic-numbers)

} // namespace Util
