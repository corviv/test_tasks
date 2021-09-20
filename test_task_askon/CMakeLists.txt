cmake_minimum_required(VERSION 3.20)
project(test_task_askon)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(arrays)

file(GLOB INPUT_DATA "arrays/*.txt")
file(COPY ${INPUT_DATA} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_FILES main.cpp include/Point.cpp include/SetPoints.cpp include/SetPoints.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
