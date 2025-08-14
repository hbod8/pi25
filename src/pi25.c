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

void test_battery(){
  char buf[64];
  int bat_pcnt = read_battery();
  bat_pcnt = bat_pcnt>>8;
  int bat_charging = bitRead(bat_pcnt,7);
  bitClear(bat_pcnt,7);
  sprintf(buf,"battery percent is %d\n",bat_pcnt);
  printf("%s", buf);
  lcd_print_string(buf);
  if (bat_charging == 0) {
    sprintf(buf,"battery is not charging\n");
  } else {
    sprintf(buf,"battery is charging\n");
  }
  printf("%s", buf);
  lcd_print_string(buf);
}

int main() {
  set_sys_clock_khz(133000, true);
  stdio_init_all();

  uart_init(uart0, 115200);

  uart_set_format(uart0, 8, 1, UART_PARITY_NONE);  // 8-N-1
  uart_set_fifo_enabled(uart0, false);

  init_i2c_kbd();
  lcd_init();

  lcd_clear();
  char buf[64];
  sprintf(buf, "Pi25 %s LUA %s\n", PI45_VERSION, PI45_LUA_VERSION);
  lcd_print_string(buf);

  sleep_ms(2000);
  test_battery();
  while (1) {
    int c = lcd_getc(0);
    if(c != -1 && c > 0) {
      lcd_putc(0,c);
    }

    sleep_ms(20);
  }
}
