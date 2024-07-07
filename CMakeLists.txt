cmake_minimum_required(VERSION 3.7)

project(scene2D)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

set(HEADERS
  ${PROJECT_SOURCE_DIR}/src/libbitmap.h
  ${PROJECT_SOURCE_DIR}/src/objects_2D.h
  ${PROJECT_SOURCE_DIR}/src/utils.h
)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/libbitmap.cpp
  ${PROJECT_SOURCE_DIR}/src/utils.cpp
)

add_library(libbitmap STATIC ${PROJECT_SOURCE_DIR}/src/libbitmap.cpp)
target_compile_features(libbitmap PRIVATE cxx_deleted_functions)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${CMAKE_SOURCE_DIR}/main.cpp
)

target_link_libraries(${PROJECT_NAME} libbitmap)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_deleted_functions)