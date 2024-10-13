#include <gtest/gtest.h>
#include "../include/palindrom.h"

TEST(PalindromeTest, Madam) {
    EXPECT_TRUE(palindrom("madam"));
}

TEST(PalindromeTest, Hello) {
    EXPECT_FALSE(palindrom("hello"));
}

TEST(PalindromeTest, Empty) {
    EXPECT_TRUE(palindrom(""));
}

TEST(PalindromeTest, A) {
    EXPECT_TRUE(palindrom("a"));
}

TEST(PalindromeTest, ABA) {
    EXPECT_TRUE(palindrom("a b a"));
}

TEST(PalindromeTest, String) {
    EXPECT_FALSE(palindrom("hello evey one"));
}

TEST(PalindromeTest, Nums) {
    EXPECT_TRUE(palindrom("888 888"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}