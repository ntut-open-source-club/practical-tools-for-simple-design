#ifndef UTIL_TRANSFORM_UTILS_HPP
#define UTIL_TRANSFORM_UTILS_HPP

#include "Core/Drawable.hpp"

#include "Util/Transform.hpp"
#include "pch.hpp"

namespace Util {
Core::Matrices ConvertToUniformBufferData(const Util::Transform &transform,
                                          const glm::vec2 &size, float zIndex);
} // namespace Util

#endif // UTIL_TRANSFORM_UTILS_HPP
