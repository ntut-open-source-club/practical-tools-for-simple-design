#include "Util/TransformUtils.hpp"

#include "config.hpp"

namespace Util {

glm::mat4 TransformToMat4(const Transform &transform, const float zIndex) {
    constexpr glm::mat4 eye(1.F);

    // TODO: TRS comment
    return glm::translate(eye, {transform.translation, zIndex}) *
           glm::rotate(eye, transform.rotation, glm::vec3(0, 0, 1)) *
           glm::scale(eye, {transform.scale, 1});
}

Core::Matrices ConvertToUniformBufferData(const Util::Transform &transform,
                                          const float zIndex) {
    constexpr glm::mat4 eye(1.F);

    constexpr float nearClip = -100;
    constexpr float farClip = 100;

    auto projection =
        glm::ortho<float>(0.0F, 1.0F, 0.0F, 1.0F, nearClip, farClip);
    auto view =
        glm::scale(eye, {1.F / WINDOW_WIDTH, 1.F / WINDOW_HEIGHT, 1.F}) *
        glm::translate(eye, {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0});

    Core::Matrices data = {
        Util::TransformToMat4(transform, zIndex),
        projection * view,
    };

    return data;
}

} // namespace Util
