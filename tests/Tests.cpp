#include "Rectangle.hpp"
#include "Square.hpp"
#include "Trapezoid.hpp"
#include "Array.hpp"
#include "Figure.hpp"
#include <gtest/gtest.h>

TEST(TestCenter, SquareCenter) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 14}, Dot<int>{14, 14}, Dot<int>{14, 0}};
    ASSERT_TRUE((s.Center() == Dot<int>{7, 7}));
}


TEST(TestCenter, RectangleСenter) {
    Rectangle<int> s = {Dot<int>{0, 0}, Dot<int>{0, 14}, Dot<int>{28, 14}, Dot<int>{28, 0}};
    ASSERT_TRUE((s.Center() == Dot<int>{14, 7}));
}

TEST(TestCenter, TrapezoidCenter) {
    Trapezoid<int> s = {Dot<int>{0, 0}, Dot<int>{0, 7}, Dot<int>{15, 7}, Dot<int>{5, 0}};
    ASSERT_TRUE((s.Center() == Dot<int>{5, 4}));
}


TEST(TestS, SquareAr) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 14}, Dot<int>{14, 14}, Dot<int>{14, 0}};
    ASSERT_EQ((double)s,  196.0);
}

TEST(TestS, RectangleAr) {
    Rectangle<int> s = {Dot<int>{0, 0}, Dot<int>{0, 14}, Dot<int>{28, 14}, Dot<int>{28, 0}};
    ASSERT_EQ((double)s,  392.0);
}

TEST(TestS, TrapezoidAr) {
    Trapezoid<int> t = {Dot<int>{0, 0}, Dot<int>{0, 6}, Dot<int>{4, 6}, Dot<int>{6, 0}};
    ASSERT_EQ((double)t, 36.973665961010283); 
}


TEST(TestArrayWork, FirstTest) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}}; 
    Rectangle<int> r = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    Trapezoid<int> t = {Dot<int>{0, 0}, Dot<int>{0, 6}, Dot<int>{4, 6}, Dot<int>{6, 0}};
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.push_back(std::make_shared<Square<int>>(s));
    arr.push_back(std::make_shared<Rectangle<int>>(r));
    arr.push_back(std::make_shared<Trapezoid<int>>(t));
    ASSERT_EQ(arr.get_total_area(), 48.973665961010283);
}

TEST(TestArrayWork, SecondTest) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}}; 
    Rectangle<int> r = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    Trapezoid<int> t = {Dot<int>{0, 0}, Dot<int>{0, 6}, Dot<int>{4, 6}, Dot<int>{6, 0}};

    Array<std::shared_ptr<Figure<int>>> arr1, arr2;
    arr1.push_back(std::make_shared<Square<int>>(s));
    arr1.push_back(std::make_shared<Rectangle<int>>(r));
    arr1.push_back(std::make_shared<Trapezoid<int>>(t));
    arr1.remove(1);
    arr2.push_back(std::make_shared<Square<int>>(s));
    arr2.push_back(std::make_shared<Trapezoid<int>>(t));
    
    ASSERT_EQ(arr2.get_size(), 2);  
    for (int i = 0; i < arr2.get_size(); ++i) {
        ASSERT_TRUE(*arr1[i] == *arr2[i]);  
    }
}

