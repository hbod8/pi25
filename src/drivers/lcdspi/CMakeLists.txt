cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

project(lcdspi
  VERSION 0.0.1
  DESCRIPTION "lcdspi for rp2040."
)

add_library(lcdspi STATIC
  lcdspi.h
  lcdspi.c
)

target_link_libraries(lcdspi
  i2ckbd
  pico_stdlib
  hardware_spi
  pico_multicore
  assets
)

target_include_directories(lcdspi INTERFACE ${CMAKE_CURRENT_LIST_DIR})
