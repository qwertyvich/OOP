#include <gtest/gtest.h>
#include "../includes/Octal.hpp"

TEST(OctalTest, InvalidNumber) {
    EXPECT_THROW(Octal("89"), std::logic_error); 
}

TEST(OctalTest, InvalidNumber2) {
    EXPECT_THROW(Octal("-12"), std::logic_error); 
}

TEST(OctalTest, SubtractionOutOfRange) {
    Octal a("13");  // 1*8 + 3 = 11
    Octal b("23");  // 2*8 + 3 = 19

    EXPECT_THROW(a - b, std::logic_error);  
}

TEST(OctalTest, Comparisons) {
    Octal a("23");  // 2*8 + 3 = 19
    Octal b("12");  // 1*8 + 2 = 10

    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a <= b);
}

TEST(OctalTest, Equality) {
    Octal a("77");
    Octal b("77");

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_FALSE(a < b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(a >= b);
}

TEST(OctalTest, InitializerListConstructor) {
    Octal a = { '1', '2', '3' };  // Представляет число 321

    ASSERT_EQ(a.getSize(), 3);
    EXPECT_EQ(a.getNumber()[0], '3');
    EXPECT_EQ(a.getNumber()[1], '2');
    EXPECT_EQ(a.getNumber()[2], '1');
}

TEST(OctalTest, FillConstructor) {
    Octal a(5, '7');  // Число "77777"

    ASSERT_EQ(a.getSize(), 5);
    for (size_t i = 0; i < a.getSize(); ++i) {
        EXPECT_EQ(a.getNumber()[i], '7');
    }
}

TEST(OctalTest, CopyConstructor) {
    Octal a("123");
    Octal b(a);

    ASSERT_EQ(b.getSize(), a.getSize());
    for (size_t i = 0; i < a.getSize(); ++i) {
        EXPECT_EQ(b.getNumber()[i], a.getNumber()[i]);
    }
}

TEST(OctalTest, CopyAssignment) {
    Octal a("123");
    Octal b = a;

    ASSERT_EQ(b.getSize(), a.getSize());
    for (size_t i = 0; i < a.getSize(); ++i) {
        EXPECT_EQ(b.getNumber()[i], a.getNumber()[i]);
    }
}

TEST(OctalTest, PrintMethod) {
    Octal a("123");  // Ожидаемый вывод: 123

    testing::internal::CaptureStdout();
    a.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "123\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();               
}
