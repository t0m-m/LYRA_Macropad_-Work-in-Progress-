#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "buttons.h"

#define DEBOUNCE_TICKS 5 // ile kolejnych spojnych odczytow uznajemy za stabilne

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

//funkcja do skanowania matrycy, tutaj sprawdzamy tylko surowy stan pinow, bez implementowania debouncingu
void matrix_scan(int row_table[3], int column_table[3], int raw_state[3][3]){

    for(int x = 0; x < 3; x++){

        //zerujemy jeden wiersz na raz
        gpio_put(row_table[x], 0);

        for(int y = 0; y < 3; y++){
            if(gpio_get(column_table[y]) == 0){
                raw_state[x][y] = 1;
            }
            else{
                raw_state[x][y] = 0;
            }
        }
        //dezaktywujemy ten wiersz, ustawiajac go w stan wysoki
        gpio_put(row_table[x], 1);
    }
};

//funkcja ktora ma za zdanie 1. przeprowadzic debouncing, 2. wyslac odpowiednie klawisze HID przez tinyUSB do komputera ktory je odczyta
void button_states(int raw_state[3][3]){

    //static, poniewaz funkcja bedzie pamietac tablice i nie bedzie tworzyc nowej za kazdym jej wywolaniem 
    static int debounced_state[3][3] = {0}; //stabilny stan klawisza, po debouncingu
    static int counter[3][3] = {0}; //licznik stabilnosci dla kazdego klawisza
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){

            if(raw_state[x][y] != debounced_state[x][y]){ //nastapila zmiana, wiec mamy potencjalnego "kandydata" do debounca
                counter[x][y]++;
                
                if(counter[x][y] >= DEBOUNCE_TICKS){ //nastapilo piec tickow, a wiec zmiana zostala podtrzymana wystarczajaco dlugo
                    debounced_state[x][y] = raw_state[x][y];
                    counter[x][y] = 0;

                    if (debounced_state[x][y] == 1) {
                        // KEY DOWN (stabilnie wcisniety)
                        // wysylamy raport HID
                    } else {
                        // KEY UP (stabilnie puszczony)
                        // ewentualny raport HID na puszczenie klawisza
                    }
                }

            }
            else{   //stabilny, nie nastapila zmiana, wiec resetujemy licznik
                counter[x][y] = 0;
            }
        }
    }
};
