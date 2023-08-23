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
    ASSERT_EQ(transform.Mat3(), glm::mat3(1.0F));
}
TEST(TransformTest, Constructor) {
    auto init_matrix = glm::mat3(4.0F); // NOLINT
    auto transform = Transform(init_matrix);
    ASSERT_EQ(transform.Mat3(), init_matrix);
}

TEST(TransformTest, Translation) {
    Transform transform = Transform().Translate(glm::vec2(6, 9)); // NOLINT
    auto expected = glm::vec3(6.0F, 9.0F, 1.0F);                  // NOLINT
    ASSERT_EQ(transform.Mat3() * ZERO, expected);
}

TEST(TransformTest, Rotate360) {
    Transform transform = Transform().Rotate(glm::radians(360.0F)); // NOLINT
    auto expected = glm::vec3(1.0F, 0.0F, 1.0F);                    // NOLINT

    auto result = transform.Mat3() * UNIT_X;
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
    EXPECT_NEAR(result[2], expected[2], M_PI_TOLERANCE);
}

TEST(TransformTest, Rotate90) {
    Transform transform = Transform().Rotate(glm::radians(90.0F)); // NOLINT
    auto expected = glm::vec3(0.0F, 1.0F, 1.0F);                   // NOLINT

    auto result = transform.Mat3() * UNIT_X;
    EXPECT_NEAR(result[0], expected[0], M_PI_TOLERANCE);
    EXPECT_NEAR(result[1], expected[1], M_PI_TOLERANCE);
    EXPECT_NEAR(result[2], expected[2], M_PI_TOLERANCE);
}

TEST(TransformTest, Scaling) {
    Transform transform = Transform().Scale(glm::vec2(4, 2)); // NOLINT
    auto expected = glm::vec3(4.0F, 2.0F, 1.0F);              // NOLINT
    ASSERT_EQ(transform.Mat3() * ONE, expected);
}

TEST(TransformTest, ScalingAndTranslation) {
    Transform transform = Transform()                      // NOLINT
                              .Translate(glm::vec2(-6, 1)) // NOLINT
                              .Scale(glm::vec2(-1, 9));    // NOLINT
    auto expected = glm::vec3(6.0F, 9.0F, 1.0F);           // NOLINT
    ASSERT_EQ(transform.Mat3() * ZERO, expected);
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
    EXPECT_NEAR(result, expected, M_PI_TOLERANCE);
}

TEST(TransformTest, SetGetTranslate) {
    auto expected = glm::vec2(6, 9); // NOLINT
    Transform transform = Transform();
    transform.SetTranslation(expected);
    auto result = transform.GetTranslation();
    EXPECT_EQ(result, expected);
}