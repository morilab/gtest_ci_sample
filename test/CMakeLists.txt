enable_testing()

add_executable(test_mylib test_mylib.cpp)
target_link_libraries(test_mylib mylib gtest gtest_main pthread)

add_test(NAME MylibTest COMMAND test_mylib)

