#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "buttons.h"

//inicjalizacja przyciskow
void init_buttons(){

    //row inits
    gpio_init(ROW_0);
    gpio_init(ROW_1);
    gpio_init(ROW_2);

    //ustawiamy rowy jako outputy, poniewaz bedziemy skanowac matryce po linijkach, jedna na raz
    gpio_set_dir(ROW_0, GPIO_OUT); 
    gpio_set_dir(ROW_1, GPIO_OUT);
    gpio_set_dir(ROW_2, GPIO_OUT);

    //column inits
    gpio_init(COL_0);
    gpio_init(COL_1);
    gpio_init(COL_2);

    //ustawiamy columny jako inputy i bedziemy patrzec czy ktorys przycisk w danym wierszu nie jest wcisniety
    gpio_set_dir(COL_0, GPIO_IN); 
    gpio_set_dir(COL_1, GPIO_IN);
    gpio_set_dir(COL_2, GPIO_IN);

    //pullupy na columnach, przy wcisnieciu przycisku, przycisk zwiera coluimne z rowem przez co bedzie stan 0
    gpio_pull_up(COL_0);
    gpio_pull_up(COL_1);
    gpio_pull_up(COL_2);

    //encoder inits
    gpio_init(ROT_0);
    gpio_init(ROT_1);
    gpio_set_dir(ROT_0, GPIO_IN);
    gpio_set_dir(ROT_1, GPIO_IN);

};

//funkcja do skanowania matrycy
void matrix_scan(int row_table[3], int column_table[3], int buttons_pressed[3][3]){

    for(int x = 0; x < 3; x++){

        //zerujemy jeden wiersz na raz
        gpio_put(row_table[x], 0);

        for(int y = 0; y < 3; y++){
            if(gpio_get(column_table[y]) == 0){
                buttons_pressed[x][y] = 1;
            }
            else{
                buttons_pressed[x][y] = 0;
            }
        }
        gpio_put(row_table[x], 1);
    }
};

//funkcja do zczytywania przyciskow
void button_states(int buttons_pressed_prev[3][3], int buttons_pressed[3][3]){
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(buttons_pressed_prev[x][y] == 0 && buttons_pressed[x][y] == 1){ //nastapila zmiana SW0 z 0 na 1, czyli przycisk zostal wcisniety
                // tutaj chce wyslac taki przycisk jaki bedzie wcisniety
            }
            else if(buttons_pressed_prev[x][y] == 1 && buttons_pressed[x][y] == 0){ //nastapila zmiana SW0 z 1 na 0, czyli przycisk zostal wycisniety
                //mozliwa jakas akcja na wycisniecie
            }
            buttons_pressed_prev[x][y] = buttons_pressed[x][y]; // aktualizacja stanu poprzedniego
        }
    }
};
