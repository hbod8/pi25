# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

project(rp2040-psram
  VERSION 1.0.0
  DESCRIPTION "A header-only library to allow access to SPI PSRAM via PIO on the RP2040 microcontroller."
)

add_library(rp2040-psram INTERFACE)

target_sources(rp2040-psram INTERFACE
  psram_spi.c
)
target_include_directories(rp2040-psram INTERFACE ${CMAKE_CURRENT_LIST_DIR})

if(PICO_SDK)
  pico_generate_pio_header(rp2040-psram ${CMAKE_CURRENT_LIST_DIR}/psram_spi.pio)
endif(PICO_SDK)

target_link_libraries(rp2040-psram INTERFACE
  pico_stdlib
  hardware_spi
  hardware_pio
  hardware_dma
)
