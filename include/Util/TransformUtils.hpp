#ifndef UTIL_TRANSFORM_UTILS_HPP
#define UTIL_TRANSFORM_UTILS_HPP

#include "Core/Drawable.hpp"

#include "Util/Transform.hpp"
#include "pch.hpp"

namespace Util {

/**
 * @brief Converts a Transform object into a 4x4 matrix.
 *
 * This function takes a Transform object and a float representing the z-index
 * as input. It returns a 4x4 matrix representing the transformation.
 *
 * @param transform The Transform object to be converted.
 * @param zIndex The z-index of the transformation.
 * @return A 4x4 matrix representing the transformation.
 */
glm::mat4 TransformToMat4(const Transform &transform, float zIndex);

/**
 * @brief Converts a Transform object into uniform buffer data.
 *
 * Converts transform data in Core::UniformBuffer format.
 * Call it and pass the returned value to Core::UniformBuffer->setData().
 *
 * @param transform The Transform object to be converted.
 * @param zIndex The z-index of the transformation.
 * @return A Matrices object representing the uniform buffer data.
 */
Core::Matrices ConvertToUniformBufferData(const Util::Transform &transform,
                                          float zIndex);

} // namespace Util

#endif // UTIL_TRANSFORM_UTILS_HPP
