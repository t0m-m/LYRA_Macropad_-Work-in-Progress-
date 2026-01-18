#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "buttons.h"
#include "tusb.h"
#include "class/hid/hid.h"

//i2c pins
#define I2C_PORT i2c0
#define I2C_SDA 6
#define I2C_SCL 7

int main()
{   
    int raw_state[3][3];
    int row_table[3] = {ROW_0, ROW_1, ROW_2};
    int column_table[3] = {COL_0, COL_1, COL_2};

    stdio_init_all();
    tusb_init();
    board_init();

    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    while(1){
        tud_task();
        //tu beda nasze funkcje 

    }
    return 0;
}
