#include <gtest/gtest.h>

#include "Util/Transform.hpp"

using Util::Transform;

// Tolerance for trigonometric function results because of PI approximation.
constexpr float M_PI_TOLERANCE = 1e-5F;

// NOLINTBEGIN(readability-magic-numbers)

TEST(TransformTest, DefaultConstructor) {
    Transform transform = Transform();
    EXPECT_EQ(transform.scale, glm::vec2(1));
    EXPECT_EQ(transform.rotation, 0);
    EXPECT_EQ(transform.translation, glm::vec2(0));
}

TEST(TransformTest, translation) {
    auto expected = glm::vec2(6, 9);
    Transform transform;
    transform.translation += expected;

    EXPECT_EQ(transform.translation, expected);
}

TEST(TransformTest, Rotate365) {
    auto expected = glm::radians(365.0F);
    Transform transform;
    transform.rotation += expected;

    auto result = transform.rotation;
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Rotate360) {
    auto expected = glm::radians(360.0F);
    Transform transform;
    transform.rotation += expected;

    auto result = transform.rotation;
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Rotate90) {
    auto expected = glm::radians(90.0F);
    Transform transform;
    transform.rotation += expected;

    auto result = transform.rotation;
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Scaling) {
    auto expected = glm::vec2(4, 2);
    Transform transform;
    transform.scale *= expected;

    auto result = transform.scale;
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
}

// NOLINTEND(readability-magic-numbers)
