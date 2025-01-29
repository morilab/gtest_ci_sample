cmake_minimum_required(VERSION 3.10)
project(GTestCISample)

# Google Test の追加
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/external/googletest)
add_subdirectory(${GTEST_DIR} googletest_build)

# テスト対象のファイル
add_executable(test_example test_example.cpp)

# Google Test をリンク
target_link_libraries(test_example gtest gtest_main pthread)

