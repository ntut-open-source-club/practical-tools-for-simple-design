#ifndef UTIL_TRANSFORM_UTILS_HPP
#define UTIL_TRANSFORM_UTILS_HPP

#include "Util/Transform.hpp"
#include "pch.hpp"

namespace Util {

glm::mat4 TransformToMat4(const Transform &transform, const float zIndex);

}

#endif // UTIL_TRANSFORM_UTILS_HPP
