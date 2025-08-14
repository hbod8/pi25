cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)

project(bindings
  VERSION 0.0.1
  DESCRIPTION "lua bindings")

add_library(bindings INTERFACE)

target_sources(bindings INTERFACE bindings.c)

target_link_libraries(bindings INTERFACE)

target_include_directories(bindings INTERFACE ${CMAKE_CURRENT_LIST_DIR})
