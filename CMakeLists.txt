cmake_minimum_required(VERSION 3.10)
project(Card_RPG CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB SRC_FILES src/*.cpp)

# Game executable
add_executable(Card_RPG ${SRC_FILES})
target_include_directories(Card_RPG PRIVATE include)

# -------------------------
# GoogleTest setup
# -------------------------
enable_testing()
find_package(GTest REQUIRED)

file(GLOB TEST_FILES tests/*.cpp)

add_executable(runTests ${TEST_FILES} ${SRC_FILES})
target_include_directories(runTests PRIVATE include)
target_link_libraries(runTests GTest::GTest GTest::Main pthread)

add_test(NAME AllTests COMMAND runTests)

