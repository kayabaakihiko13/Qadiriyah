cmake_minimum_required(VERSION 3.10)

project(math_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(testing_main testing_main.cpp test/math_test.cpp test/statistic_test.cpp)
target_link_libraries(testing_main gtest)
