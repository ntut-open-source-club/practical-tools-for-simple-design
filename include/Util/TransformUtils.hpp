#ifndef UTIL_TRANSFORM_UTILS_HPP
#define UTIL_TRANSFORM_UTILS_HPP

#include "Core/Drawable.hpp"

#include "Util/Transform.hpp"
#include "pch.hpp"

namespace Util {

glm::mat4 TransformToMat4(const Transform &transform, float zIndex);

Core::Matrices ConvertToUniformBufferData(const Util::Transform &transform,
                                          float zIndex);

} // namespace Util

#endif // UTIL_TRANSFORM_UTILS_HPP
