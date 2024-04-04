cmake_minimum_required(VERSION 3.10)
project(learn-c CXX)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -O0")

add_executable(${PROJECT_NAME} src/main.cc)

target_link_libraries(${PROJECT_NAME} m)
