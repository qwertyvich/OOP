cmake_minimum_required(VERSION 3.10)

# Название проекта
project(Lab1_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)

# Добавляем исходные файлы проекта
add_executable(main_program main.cpp src/palindrom.cpp)  # Добавление основной программы и функции палиндрома

# Подключаем Google Test
add_subdirectory(googletest)

# Добавляем тесты
add_executable(run_tests tests/Tests.cpp src/palindrom.cpp)  # Линкуем тесты с реализацией функции палиндрома

# Линкуем тесты с библиотекой Google Test
target_link_libraries(run_tests gtest gtest_main)

# Включаем тестирование
enable_testing()

# Добавляем тесты
add_test(NAME PalindromeTests COMMAND run_tests)
