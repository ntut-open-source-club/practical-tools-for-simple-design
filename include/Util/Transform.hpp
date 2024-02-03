#ifndef UTIL_TRANSFORM_HPP
#define UTIL_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {

/**
 * @struct Transform
 * @brief A struct representing a transformation in 2D space.
 *
 * This struct encapsulates the properties of a transformation in 2D space.
 * @note The order of Util::Transform is translation, rotation, and scale.
 */
struct Transform {
    /**
     * @brief The translation of the transformation.
     *
     * This property represents the translation of the transformation in 2D
     * space. It is represented as a 2D vector.
     */
    glm::vec2 translation = {0, 0};

    /**
     * @brief The rotation of the transformation.
     *
     * This property represents the rotation of the transformation in 2D space.
     * It is represented as a float.
     * @note The unit of rotation is in radians not degrees.
     */
    float rotation = 0;

    /**
     * @brief The scale of the transformation.
     *
     * This property represents the scale of the transformation in 2D space.
     * It is represented as a 2D vector.
     */
    glm::vec2 scale = {1, 1};
};

} // namespace Util

#endif /* UTIL_TRANSFORM_HPP */
