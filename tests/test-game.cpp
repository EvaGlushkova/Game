#include <gtest/gtest.h>

TEST(FirstTest, Addition) {
EXPECT_EQ(5 + 2, 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}