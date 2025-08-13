#include <gtest/gtest.h>

// Example test case — always passes
TEST(SanityCheck, TrueIsTrue) {
    EXPECT_TRUE(true);
}

// GoogleTest entry point
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
