cmake_minimum_required(VERSION 3.27)

enable_testing()

project(lab2)

add_subdirectory(googletest)


add_executable(lab2 seven.cpp)
add_executable(the_test test.cpp)

add_library(seven seven.cpp)

target_link_libraries(the_test PRIVATE seven)
target_link_libraries(the_test PRIVATE gtest gtest_main)



add_test(NAME test COMMAND test)
