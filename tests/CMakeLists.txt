find_package(CppUTest REQUIRED)

add_executable(aoc24_tests AllTests.cpp)

target_link_libraries(aoc24_tests PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt)