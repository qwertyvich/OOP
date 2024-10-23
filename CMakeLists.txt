cmake_minimum_required(VERSION 3.10)

# Название проекта
project(Lab2_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Добавляем исходные файлы проекта
add_executable(main_program main.cpp src/Octal.cpp)  # Основная программа

# Подключаем Google Test
add_subdirectory(googletest)

# Добавляем тесты
add_executable(run_tests tests/Tests.cpp src/Octal.cpp)  # Линкуем тесты с реализацией Octal

# Линкуем тесты с библиотекой Google Test
target_link_libraries(run_tests gtest gtest_main)

# Включаем тестирование
enable_testing()

# Регистрируем тесты
add_test(NAME OctalTest COMMAND run_tests)
