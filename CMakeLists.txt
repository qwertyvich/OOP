cmake_minimum_required(VERSION 3.20)
project(lab7)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FILES
    src/Menu.cpp
    src/NPC.cpp
    src/NPCFabric.cpp
    src/ObserverConsolOutput.cpp
    src/ObserverFileOutput.cpp
    src/Visitor.cpp
    src/DeathHandler.cpp
    src/UI.cpp
    src/FightHandler.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(lab7 main.cpp ${COMPILE_FILES})
add_subdirectory(googletest)
add_executable(run_tests
 tests/Tests.cpp 
 src/Menu.cpp
 src/NPC.cpp
 src/NPCFabric.cpp
 src/ObserverConsolOutput.cpp
 src/ObserverFileOutput.cpp
 src/Visitor.cpp
 src/DeathHandler.cpp
 src/UI.cpp
 src/FightHandler.cpp
)
target_link_libraries(run_tests gtest gtest_main)
enable_testing()
add_test(Lab7Test run_tests)