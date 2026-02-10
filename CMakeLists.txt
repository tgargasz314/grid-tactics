cmake_minimum_required(VERSION 3.20)
project(grid-tactics LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL)

add_executable(grid_tactics src/main.cpp)

target_link_libraries(grid_tactics PRIVATE SDL3::SDL3)

set_target_properties(grid_tactics PROPERTIES OUTPUT_NAME "grid-tactics")