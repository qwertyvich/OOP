
cmake_minimum_required(VERSION 3.20)
project(Lab3_Project LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(main_program main.cpp src/Array.cpp src/Figure.cpp src/Rectangle.cpp src/Square.cpp src/Trapezoid.cpp)    # Основная программа
add_subdirectory(googletest)
add_executable(run_tests tests/Tests.cpp src/Array.cpp src/Figure.cpp src/Rectangle.cpp src/Square.cpp src/Trapezoid.cpp)  # Линкуем тесты с реализацией Octal
target_link_libraries(run_tests gtest gtest_main)
enable_testing()
add_test(NAME FigureTest COMMAND run_tests)
