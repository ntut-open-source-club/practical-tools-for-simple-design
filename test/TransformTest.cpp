#include <gtest/gtest.h>

#include "Util/Transform.hpp"

using Util::Transform;

TEST(TransformTest, DefaultConstructor) {
    Transform t1 = Transform();
    ASSERT_EQ(t1.Mat3(), glm::mat3(1.0F));
}
TEST(TransformTest, Constructor) {
    auto m1 = glm::mat3(4.0F); // NOLINT
    Transform t1 = Transform(m1);
    ASSERT_EQ(t1.Mat3(), m1);
}

TEST(TransformTest, Translation) {
    Transform t1 = Transform().Translate(glm::vec2(6, 9));
    auto origin = glm::vec3(0,0,1);
    auto p69 = glm::vec3(6,9,1);
    ASSERT_EQ(t1.Mat3() * origin, p69);
}

TEST(TransformTest, Rotate360) {
    Transform t1 = Transform().Rotate(glm::radians(0.0F));
    auto v = glm::vec3(1.0F,0.0F,1.0F);
    auto v2 = glm::vec3(1.0F,0.0F,1.0F);

    auto result = t1.Mat3() * v;
    EXPECT_FLOAT_EQ(result[0], v2[0]);
    EXPECT_FLOAT_EQ(result[1], v2[1]);
    EXPECT_FLOAT_EQ(result[2], v2[2]);
}

TEST(TransformTest, Rotate90) { // TODO: cant pass, maybe Floating-point error
    Transform t1 = Transform().Rotate(glm::radians(90.0F));
    auto v = glm::vec3(1.0F,0.0F,1.0F);
    auto v2 = glm::vec3(0.0F,1.0F,1.0F);

    auto result = t1.Mat3() * v;
    EXPECT_FLOAT_EQ(result[0], v2[0]);
    EXPECT_FLOAT_EQ(result[1], v2[1]);
    EXPECT_FLOAT_EQ(result[2], v2[2]);
}

TEST(TransformTest, Scaling) {
    Transform t1 = Transform().Scale(glm::vec2(4,2));
    auto v = glm::vec3(1.0F,1.0F,1.0F);
    auto v2 = glm::vec3(4.0F,2.0F,1.0F);
    ASSERT_EQ(t1.Mat3() * v, v2);
}

TEST(TransformTest, ScalingAndTranslation) {
    Transform t1 = Transform()
        .Translate(glm::vec2(-6,1))
        .Scale(glm::vec2(-1,9));
    auto v = glm::vec3(0.0F,0.0F,1.0F);
    auto v2 = glm::vec3(6.0F,9.0F,1.0F);
    ASSERT_EQ(t1.Mat3() * v, v2);
}