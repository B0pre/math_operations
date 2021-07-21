#tests

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests test_main.cpp calculator_test.cpp)
target_include_directories(runTests PUBLIC ../include)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread math_operations_lib)

add_custom_target(check ALL COMMAND runTests)
