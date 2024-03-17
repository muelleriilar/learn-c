cmake_minimum_required(VERSION 3.10)
project(learn-c C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -O0")

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} m)
