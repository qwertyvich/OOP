cmake_minimum_required(VERSION 3.20)

project(lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILE_FILES main.cpp src/UI.cpp src/NPC.cpp src/NPCFabric.cpp src/ObserverConsolOutput.cpp src/ObserverFileOutput.cpp src/Visitor.cpp src/DeathAgregator.cpp src/Menu.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(lab6 main.cpp ${COMPILE_FILES})

add_subdirectory(googletest)
add_executable(run_tests
 tests/Tests.cpp 
 src/DeathAgregator.cpp
 src/Menu.cpp
 src/NPC.cpp
 src/NPCFabric.cpp
 src/Observer.cpp
 src/ObserverConsolOutput.cpp
 src/ObserverFileOutput.cpp
 src/UI.cpp
 src/Visitor.cpp
     ) 
target_link_libraries(run_tests gtest gtest_main)
enable_testing()
add_test(NAME Lab6Test COMMAND run_tests)