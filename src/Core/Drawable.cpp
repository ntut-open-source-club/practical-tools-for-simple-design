#include "Core/Drawable.hpp"

#include "config.hpp"

namespace Core {
Drawable::Drawable(glm::mat3 transform)
    : m_Transform(transform) {

}
} // namespace Core
