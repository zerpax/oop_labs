cmake_minimum_required(VERSION 3.27)
enable_testing()
project(lab_1)

add_library(sad src/sad.cpp)

add_subdirectory(googletest)

add_executable(lab_1 main.cpp)
add_executable(test_1 test/test.cpp)


target_link_libraries(lab_1 PRIVATE  sad)
target_link_libraries(test_1 PRIVATE sad)
target_link_libraries(test_1 PRIVATE gtest gtest_main)



add_test(NAME BASIC COMMAND test)


