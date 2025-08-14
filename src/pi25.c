/**
 * PicoCalc Hello World
 * https://www.clockworkpi.com/
 */
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "i2ckbd.h"
#include "lcdspi.h"
#include "psram_spi.h"
#include "pwm_sound.h"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main() {
  // Basic init
  set_sys_clock_khz(133000, true);
  stdio_init_all();

  uart_init(uart0, 115200);

  uart_set_format(uart0, 8, 1, UART_PARITY_NONE);  // 8-N-1
  uart_set_fifo_enabled(uart0, false);

  init_i2c_kbd();
  lcd_init();

  // Screen setup
  lcd_clear();
  char buf[64];
  sprintf(buf, "Pi25 %s LUA %s\n", PI45_VERSION, PI45_LUA_VERSION);
  lcd_print_string(buf);

  while (1) {
    int c = lcd_getc(0);
    if(c != -1 && c > 0) {
      lcd_putc(0,c);
    }

    sleep_ms(20);
  }
}
