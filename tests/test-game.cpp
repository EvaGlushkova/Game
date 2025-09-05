#include <gtest/gtest.h>

TEST(FirstTest, Addition) {
EXPECT_EQ(5 + 3, 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}