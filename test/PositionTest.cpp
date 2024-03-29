#include <gtest/gtest.h>

#include "config.hpp"
#include "Util/Position.hpp"

#define FLOAT_TO_INT_ERROR 1

TEST(CastingTest, PTSD2SDL) {
    float a=4.32, b=65.32;
    auto p = PTSDPosition(a, b);
    auto s = p.toSDLPosition();
    EXPECT_NEAR(s.x, a + WINDOW_WIDTH/2, FLOAT_TO_INT_ERROR);
    EXPECT_NEAR(s.y, b + WINDOW_HEIGHT/2, FLOAT_TO_INT_ERROR);
}

TEST(CastingTest, SDL2PTSD) {
    auto s = SDLPosition(0, 0);
    PTSDPosition p = s.toPTSDPosition();
    EXPECT_EQ(p.x, -(float)WINDOW_WIDTH/2);
    EXPECT_EQ(p.y, -(float)WINDOW_HEIGHT/2);
}

TEST(CastingTest, SDL2PTSD_Implicit) {
    auto s = SDLPosition(0, 0);
    PTSDPosition p = s;
    EXPECT_EQ(p.x, -(float)WINDOW_WIDTH/2);
    EXPECT_EQ(p.y, -(float)WINDOW_HEIGHT/2);
}

TEST(CastingTest, AddingVec2) {
    float a=32,b=23,c=69,d=53;
    auto p1 = PTSDPosition(a, b);
    auto v2 = glm::vec2(c, d);
    auto result = p1 - v2;
    EXPECT_EQ(result.x, a-c);
    EXPECT_EQ(result.y, b-d);
}
