#include "../assets/font.h"
#include <hardware/spi.h>

void write_chars(char* s) {
  spi_init(spi1, 1000 * 1000); // Initialize SPI at 1 MHz
  spi_write_blocking(spi1, font, sizeof(font)); // Write the font data to SPI
}