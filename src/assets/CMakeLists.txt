cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)

project(drivers
        VERSION 0.0.1
        DESCRIPTION "assets")

add_library(assets INTERFACE)

target_sources(assets INTERFACE)

target_link_libraries(assets INTERFACE  pico_stdlib hardware_spi hardware_i2c)

target_include_directories(assets INTERFACE ${CMAKE_CURRENT_LIST_DIR})