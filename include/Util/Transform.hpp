#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
struct Transform {
    glm::vec2 translation = {0, 0};
    float rotation = 0;
    glm::vec2 scale = {1, 1};
};
} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
