cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(
  math_operations
  VERSION 0.1
  DESCRIPTION "math operations"
  LANGUAGES CXX)

#set sources
add_subdirectory(src)

add_subdirectory(apps)

add_subdirectory(test)
