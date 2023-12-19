cmake_minimum_required(VERSION 3.25)

include(cmake/CompileOptions.cmake)
#include(cmake/Werror.cmake)
#include(cmake/Sanitize.cmake)

project(string_lab)

set(HEADERS
  include/lab_string.hpp
)

set(SOURCES
  src/lab_string.cpp
)

add_library(${CMAKE_PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_subdirectory(external)
add_subdirectory(tests)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC array)