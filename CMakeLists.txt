cmake_minimum_required(VERSION 3.7)

project(scene2D)
add_definitions(-DOWN_MAKE_UNIQUE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${PROJECT_SOURCE_DIR})

add_library(libbitmap libbitmap.cpp)
target_compile_features(libbitmap PRIVATE cxx_deleted_functions)

add_executable(scene main.cpp utils.cpp)
target_link_libraries(scene libbitmap)
target_compile_features(scene PRIVATE cxx_deleted_functions)