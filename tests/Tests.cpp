#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include "Square.hpp"
#include "Array.hpp"
#include "Figure.hpp"
#include <gtest/gtest.h>


TEST(TestCenter, Test_Square) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    ASSERT_TRUE((s.Center() == Dot{1, 1})); 
}

TEST(TestCenter, Test_Rectangle) {
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    ASSERT_TRUE((r.Center() == Dot{2, 1})); 
}
TEST(TestArea, Test_Square) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    ASSERT_EQ((double)s, 4.); 
}

TEST(TestArea, Test_Rectangle) {
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    ASSERT_EQ((double)r, 8.); 
}

TEST(TestArray, Test_TotalArea) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}}; 
    Trapezoid t1 = {Dot{0, 0}, Dot{4, 0}, Dot{3, 2}, Dot{1, 2}};
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}}; 
    Array arr = {&s, &t1, &r};

    ASSERT_EQ(arr.get_total_area(), 18.);
}

TEST(TestArray, Test_Remove) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    Trapezoid t = {Dot{0, 0}, Dot{4, 0}, Dot{3, 2}, Dot{1, 2}};
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Array arr1 = {&s, &t, &r};
    Array arr2 = {&s, &r};

    arr1.remove(1);
    ASSERT_EQ(arr1.get_size(), arr2.get_size());
    for (size_t i = 0; i < arr1.get_size(); ++i) {
        ASSERT_EQ(arr1[i], arr2[i]);
    }
}

TEST(TestArray, Test_Centers) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    Trapezoid t = {Dot{0, 0}, Dot{4, 0}, Dot{3, 2}, Dot{1, 2}};
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Array arr = {&s, &t, &r};

    testing::internal::CaptureStdout();
    arr.Centers();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("(1, 1)") != std::string::npos); 
    EXPECT_TRUE(output.find("(2, 1)") != std::string::npos); 
    EXPECT_TRUE(output.find("(2, 1)") != std::string::npos); 
}

TEST(TestArray, Test_Areas) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    Trapezoid t = {Dot{0, 0}, Dot{4, 0}, Dot{3, 2}, Dot{1, 2}};
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Array arr = {&s, &t, &r};

    testing::internal::CaptureStdout();
    arr.Areas();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("4") != std::string::npos);
    EXPECT_TRUE(output.find("6") != std::string::npos); 
    EXPECT_TRUE(output.find("8") != std::string::npos);
}
