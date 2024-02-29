#include <gtest/gtest.h>

TEST(SimpleTest, TestTrue) {
    ASSERT_TRUE(true);
}

TEST(SimpleTest, TestFalse) {
    ASSERT_FALSE(false);
}
