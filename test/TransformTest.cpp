#include <gtest/gtest.h>

#include "Util/Transform.hpp"

using Util::Transform;

// Tolerance for trigonometric function results because of PI approximation.
constexpr float M_PI_TOLERANCE = 1e-5F;

// Useful 2D vectors represented in 3D homogeneous coordinates (HC)
constexpr glm::vec3 ZERO = {0, 0, 1};
constexpr glm::vec3 ONE = {1, 1, 1};
constexpr glm::vec3 UNIT_X = {1, 0, 1};

// NOLINTBEGIN(readability-magic-numbers)

TEST(TransformTest, DefaultConstructor) {
    Transform transform = Transform();
    EXPECT_EQ(transform.GetScale(), glm::vec2(1));
    EXPECT_EQ(transform.GetRotation(), 0);
    EXPECT_EQ(transform.GetTranslation(), glm::vec2(0));
}

TEST(TransformTest, Translation) {
    Transform transform = Transform().Translate(glm::vec2(6, 9));
    EXPECT_EQ(transform.GetTranslation(), glm::vec2(6, 9));
}

TEST(TransformTest, Rotate360) {
    auto expected = glm::radians(360.0F);
    Transform transform = Transform().Rotate(expected);
    auto result = transform.GetRotation();
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Rotate90) {
    auto expected = glm::radians(90.0F);
    Transform transform = Transform().Rotate(expected);
    auto result = transform.GetRotation();
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Scaling) {
    auto expected = glm::vec2(4, 2);
    Transform transform = Transform().Scale(expected);
    auto result = transform.GetScale();
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
}

TEST(TransformTest, SetGetScale) {
    auto expected = glm::vec2(20, 30);
    Transform transform = Transform();
    transform.SetScale(expected);
    transform.SetRotation(14);
    auto result = transform.GetScale();
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
}

TEST(TransformTest, SetGetRotation) {
    auto expected = glm::radians(269.69F);
    Transform transform = Transform();
    transform.SetRotation(expected);
    transform.SetScale(glm::vec2(6, 9));
    auto result = transform.GetRotation();
    // Note the 1000x tolerance
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE * 1e+3F);
}

TEST(TransformTest, SetGetTranslate) {
    auto expected = glm::vec2(6, 9);
    Transform transform = Transform();
    transform.SetTranslation(expected);
    auto result = transform.GetTranslation();
    EXPECT_EQ(result, expected);
}

// NOLINTEND(readability-magic-numbers)
