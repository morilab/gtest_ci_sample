enable_testing()

add_executable(test_example test_example.cpp)
target_link_libraries(test_example mylib gtest gtest_main pthread)

add_test(NAME ExampleTest COMMAND test_example)

