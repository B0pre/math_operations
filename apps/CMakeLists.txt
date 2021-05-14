add_executable(math_operations main.cpp)
target_include_directories(math_operations PUBLIC ../include)
target_link_libraries(math_operations PRIVATE math_operations_lib)

