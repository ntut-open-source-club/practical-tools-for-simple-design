#include <gtest/gtest.h>

#include "Util/Position.hpp"
#include "config.hpp"

#define FLOAT_TO_INT_ERROR 1

// NOLINTBEGIN(readability-magic-numbers)

TEST(CastingTest, PTSD2SDL) {
    float a = 4.32, b = 65.32;
    auto ptsdpos = Util::PTSDPosition(a, b);
    auto sdlpos = ptsdpos.ToSDLPosition();
    EXPECT_NEAR(sdlpos.x, a + WINDOW_WIDTH / 2, FLOAT_TO_INT_ERROR);
    EXPECT_NEAR(sdlpos.y, b + WINDOW_HEIGHT / 2, FLOAT_TO_INT_ERROR);
}

TEST(CastingTest, SDL2PTSD) {
    int a = 74, b = 14;
    auto ptsdpos = Util::PTSDPosition::FromSDL(a, b);
    EXPECT_EQ(ptsdpos.x, (float)a - WINDOW_WIDTH / 2);
    EXPECT_EQ(ptsdpos.y, (float)b - WINDOW_HEIGHT / 2);
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
