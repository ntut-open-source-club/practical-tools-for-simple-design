#include <gtest/gtest.h>

#include "Util/Position.hpp"
#include "config.hpp"

#define FLOAT_TO_INT_ERROR 1

// NOLINTBEGIN(readability-magic-numbers)

TEST(CastingTest, PTSD2SDL) {
    float a = 4.32, b = 65.32;
    auto p = Util::PTSDPosition(a, b);
    auto s = Util::SDLPosition(p); // explicit constructor (not lossless)
    EXPECT_NEAR(s.x, a + WINDOW_WIDTH / 2, FLOAT_TO_INT_ERROR);
    EXPECT_NEAR(s.y, b + WINDOW_HEIGHT / 2, FLOAT_TO_INT_ERROR);
}

TEST(CastingTest, SDL2PTSD) {
    auto s = Util::SDLPosition(0, 0);
    Util::PTSDPosition p = s; // converting constructor
    EXPECT_EQ(p.x, -(float)WINDOW_WIDTH / 2);
    EXPECT_EQ(p.y, -(float)WINDOW_HEIGHT / 2);
}

TEST(CastingTest, SDL2PTSD_Implicit) {
    auto s = Util::SDLPosition(0, 0);
    Util::PTSDPosition p = s;
    EXPECT_EQ(p.x, -(float)WINDOW_WIDTH / 2);
    EXPECT_EQ(p.y, -(float)WINDOW_HEIGHT / 2);
}

TEST(CastingTest, AddingVec2) {
    float a = 32, b = 23, c = 69, d = 53;
    auto p1 = Util::PTSDPosition(a, b);
    auto v2 = glm::vec2(c, d);
    auto result = p1 - v2;
    EXPECT_EQ(result.x, a - c);
    EXPECT_EQ(result.y, b - d);
}

// NOLINTEND(readability-magic-numbers)
