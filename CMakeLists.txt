cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pi25)
pico_sdk_init()

add_compile_definitions(PI45_VERSION="0.1")
add_compile_definitions(PI45_LUA_VERSION="5.4.8")

add_subdirectory(src/drivers)
add_subdirectory(src/assets)
add_subdirectory(src/lua)

add_executable(pi25
  src/pi25.c
)

pico_enable_stdio_usb(pi25 0)
pico_enable_stdio_uart(pi25 0)

target_link_libraries(pi25
  drivers
  assets
  lua
  bindings
  pico_stdlib
  hardware_spi
)

pico_add_extra_outputs(pi25)
