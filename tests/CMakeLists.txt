enable_testing()

set(TEST_SOURCES
    test_main.cpp
    # Add test files here
)

add_executable(Card_RPG_Tests ${TEST_SOURCES})
target_link_libraries(Card_RPG_Tests gtest gtest_main pthread)

add_test(NAME AllTests COMMAND Card_RPG_Tests)
