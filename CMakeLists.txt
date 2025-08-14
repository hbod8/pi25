cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pi25)
pico_sdk_init()

add_subdirectory(src/drivers)
add_subdirectory(src/assets)

add_executable(pi25
  src/pi25.c
)

pico_enable_stdio_usb(pi25 0)
pico_enable_stdio_uart(pi25 0)

target_link_libraries(pi25
  drivers
  assets
  pico_stdlib
  hardware_spi
)

pico_add_extra_outputs(pi25)
