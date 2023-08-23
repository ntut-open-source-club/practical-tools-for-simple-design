#include <gtest/gtest.h>

#include "Util/Transform.hpp"

using Util::Transform;

// Tolerance for trigonometric function results because of π approximation.
#define M_PI_TOLERANCE 1e-5F

// Useful 2D vectors represented in 3D homogeneous coordinates (HC)
#define ZERO glm::vec3(0, 0, 1)
#define ONE glm::vec3(1, 1, 1)
#define UNIT_X glm::vec3(1, 0, 1)

TEST(TransformTest, DefaultConstructor) {
    Transform transform = Transform(); // NOLINT
    EXPECT_EQ(transform.GetScale(), glm::vec2(1));
    EXPECT_EQ(transform.GetRotation(), 0);
    EXPECT_EQ(transform.GetTranslation(), glm::vec2(0));
}

TEST(TransformTest, Translation) {
    Transform transform = Transform().Translate(glm::vec2(6, 9)); // NOLINT
    EXPECT_EQ(transform.GetTranslation(), glm::vec2(6, 9));
}

TEST(TransformTest, Rotate360) {
    auto expected = glm::radians(360.0F); // NOLINT
    Transform transform = Transform().Rotate(expected);
    auto result = transform.GetRotation();
    // IDK the better way to fix v, is caused by π approximation 🤷‍♂️
    EXPECT_NEAR(result + 4 * acos(0.0), expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Rotate90) {
    auto expected = glm::radians(90.0F); // NOLINT
    Transform transform = Transform().Rotate(expected);
    auto result = transform.GetRotation();
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, Scaling) {
    auto expected = glm::vec2(4, 2);                   // NOLINT
    Transform transform = Transform().Scale(expected); // NOLINT
    auto result = transform.GetScale();
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
}

TEST(TransformTest, SetGetScale) {
    auto expected = glm::vec2(20, 30); // NOLINT
    Transform transform = Transform();
    transform.SetScale(expected);
    transform.SetRotation(14); // NOLINT
    auto result = transform.GetScale();
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
}

TEST(TransformTest, SetGetRotation) {
    auto expected = glm::radians(269.69F); // NOLINT
    Transform transform = Transform();
    transform.SetRotation(expected);
    transform.SetScale(glm::vec2(6, 9)); // NOLINT
    auto result = transform.GetRotation();
    // Note the 1000x tolerance
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE * 1e+3F);
}

TEST(TransformTest, SetGetTranslate) {
    auto expected = glm::vec2(6, 9); // NOLINT
    Transform transform = Transform();
    transform.SetTranslation(expected);
    auto result = transform.GetTranslation();
    EXPECT_EQ(result, expected);
}