#include <gtest/gtest.h>

#include "Util/Position.hpp"
#include "config.hpp"

constexpr float FLOAT_TO_INT_ERROR = 1.0F;

// NOLINTBEGIN(readability-magic-numbers)

TEST(CastingTest, PTSD2SDL) {
    float a = 4.32;
    float b = 65.32;
    auto ptsdpos = Util::PTSDPosition(a, b);
    auto sdlpos = ptsdpos.ToSDLPosition();
    EXPECT_NEAR(sdlpos.x,
                a + static_cast<float>(PTSD_Config::WINDOW_WIDTH) / 2.0F,
                FLOAT_TO_INT_ERROR);
    EXPECT_NEAR(sdlpos.y,
                b + static_cast<float>(PTSD_Config::WINDOW_HEIGHT) / 2.0F,
                FLOAT_TO_INT_ERROR);
}

TEST(CastingTest, SDL2PTSD) {
    int a = 74;
    int b = 14;
    auto ptsdpos = Util::PTSDPosition::FromSDL(a, b);
    EXPECT_EQ(ptsdpos.x,
              static_cast<float>(a) -
                  static_cast<float>(PTSD_Config::WINDOW_WIDTH) / 2.0F);
    EXPECT_EQ(ptsdpos.y,
              static_cast<float>(b) -
                  static_cast<float>(PTSD_Config::WINDOW_HEIGHT) / 2.0F);
}

TEST(CastingTest, AddingVec2) {
    float a = 32;
    float b = 23;
    float c = 69;
    float d = 53;
    auto p1 = Util::PTSDPosition(a, b);
    auto v2 = glm::vec2(c, d);
    auto result = p1 - v2;
    EXPECT_EQ(result.x, a - c);
    EXPECT_EQ(result.y, b - d);
}

// NOLINTEND(readability-magic-numbers)
