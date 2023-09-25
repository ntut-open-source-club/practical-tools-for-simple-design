#include "Util/Transform.hpp"

namespace Util {

// NOLINTBEGIN(readability-identifier-length,readability-magic-numbers)

Transform Transform::Rotate(float r) const {
    //FIXME: fix Transform
    throw "DONT USE THIS";
}

Transform Transform::Translate(const glm::vec2 &t) const {
    //FIXME: fix Transform
    throw "DONT USE THIS";
}

Transform Transform::Scale(const glm::vec2 &s) const {
    //FIXME: fix Transform
    throw "DONT USE THIS";
}

void Transform::SetRotation(float r) {
    m_Rotation = r;
}

void Transform::SetTranslation(const glm::vec2 &t) {
    m_Translation = t;
}

void Transform::SetScale(const glm::vec2 &s) {
    m_Scale = s;
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

// NOLINTEND(readability-identifier-length,readability-magic-numbers)

} // namespace Util
