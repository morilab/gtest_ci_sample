cmake_minimum_required(VERSION 3.10)
project(GTestCISample)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
enable_testing()

# Google Test の追加
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/external/googletest)
add_subdirectory(${GTEST_DIR} googletest_build)

# ソースコード
add_library(mylib src/mylib.cpp)
target_include_directories(mylib PUBLIC src)

# テストの追加
add_subdirectory(test)

# コードカバレッジの設定
if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Enabling code coverage flags")
        target_compile_options(mylib PUBLIC --coverage -O0 -g)
        target_link_libraries(mylib PUBLIC --coverage)
    else()
        message(WARNING "Code coverage is only supported for GCC and Clang")
    endif()
endif()

# カバレッジ計測用ターゲット追加
if(ENABLE_COVERAGE)
    find_program(LCOV lcov)
    find_program(GENHTML genhtml)

    if(LCOV AND GENHTML)
        add_custom_target(coverage
            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
            COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
            COMMAND ${LCOV} --directory ${CMAKE_BINARY_DIR} --capture --output-file coverage.info
            COMMAND ${LCOV} --extract coverage.info "${CMAKE_SOURCE_DIR}/src/*" --output-file coverage_filtered.info
            COMMAND ${LCOV} --list coverage_filtered.info > coverage_report.txt
            COMMAND ${GENHTML}     coverage_filtered.info --output-directory coverage_report
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating coverage report"
            VERBATIM
        )
    else()
        message(WARNING "lcov and genhtml not found, coverage target will not be available")
    endif()
endif()
