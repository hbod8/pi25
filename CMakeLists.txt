cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pi25)
pico_sdk_init()

add_compile_definitions(PI45_VERSION="0.1")
add_compile_definitions(PI45_LUA_VERSION="5.4.8")

##picocalc spi0
add_compile_definitions(PSRAM_MUTEX=1)
#add_compile_definitions(PSRAM_SPINLOCK=0)
add_compile_definitions(PSRAM_ASYNC=0)
add_compile_definitions(PSRAM_PIN_CS=20)
add_compile_definitions(PSRAM_PIN_SCK=21)
add_compile_definitions(PSRAM_PIN_MOSI=2)
add_compile_definitions(PSRAM_PIN_MISO=3)

add_subdirectory(src/drivers/i2ckbd)
add_subdirectory(src/drivers/lcdspi)
add_subdirectory(src/drivers/pwm_sound)
add_subdirectory(src/drivers/rp2040-psram)
add_subdirectory(src/assets)
add_subdirectory(src/lua)
add_subdirectory(src/lua-bindings)

add_executable(pi25
  src/pi25.c
)

pico_enable_stdio_usb(pi25 0)
pico_enable_stdio_uart(pi25 0)

target_link_libraries(pi25
  i2ckbd
  lcdspi
  pwm_sound
  rp2040-psram
  assets
  lua
  bindings
  pico_stdlib
  hardware_spi
)

pico_add_extra_outputs(pi25)
