set(HEADER_LIST ../include/*.h)

message(${HEADER_LIST})
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ../include)
file(GLOB CPPS "*.cpp")
add_definitions(-Wall -O2)
add_library(${PROJECT_NAME}_lib ${CPPS})

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header files"
	FILES ${HEADER_LIST})
