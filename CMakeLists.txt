cmake_minimum_required(VERSION 3.10)
project(GTestCISample)

# Google Test の追加
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/external/googletest)
add_subdirectory(${GTEST_DIR} googletest_build)

# ソースコード
add_library(mylib src/mylib.cpp)
target_include_directories(mylib PUBLIC src)

# テストの追加
add_subdirectory(test)

