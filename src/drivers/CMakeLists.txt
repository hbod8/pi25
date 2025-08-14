cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 17)

project(drivers
        VERSION 0.0.1
        DESCRIPTION "drivers")

add_subdirectory(i2ckbd)
add_subdirectory(lcdspi)
add_subdirectory(pwm_sound)
add_subdirectory(rp2040-psram)

add_library(drivers INTERFACE)

##picocalc spi0
target_compile_definitions(drivers INTERFACE
    PSRAM_MUTEX=1
    #PSRAM_SPINLOCK=0
    PSRAM_ASYNC=0
    PSRAM_PIN_CS=20
    PSRAM_PIN_SCK=21
    PSRAM_PIN_MOSI=2
    PSRAM_PIN_MISO=3
)

target_sources(drivers INTERFACE
        term.c)

target_link_libraries(drivers INTERFACE
  assets
  hardware_flash
  hardware_irq
  hardware_adc
  hardware_pwm
  hardware_i2c
  hardware_spi
  hardware_dma
  hardware_exception
	hardware_pio
  pico_multicore
	i2ckbd
	lcdspi
  rp2040-psram
	pwm_sound)

target_include_directories(drivers INTERFACE ${CMAKE_CURRENT_LIST_DIR})