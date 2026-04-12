cmake_minimum_required(VERSION 3.14)

project(. VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(strumok_lib
        strumok_funcs.cpp
        strumok_tables.c
)


add_executable(implementation main.cpp)

target_link_libraries(implementation PRIVATE strumok_lib)


add_executable(run_tests tests/strumok_tests.cpp)

target_link_libraries(run_tests PRIVATE strumok_lib GTest::gtest_main)