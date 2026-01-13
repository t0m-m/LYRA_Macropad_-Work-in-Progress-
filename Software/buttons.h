#ifndef BUTTONS_H
#define BUTTONS_H

//row pins
#define ROW_0 3
#define ROW_1 28
#define ROW_2 29

//column pins
#define COL_0 2
#define COL_1 4
#define COL_2 0

//rotary encoder pins NIE BEDZIE DZIALAC WCISKANIE ENCODERA!
#define ROT_0 27
#define ROT_1 26

void init_buttons(void);
int matrix_scan(int row_table[3], int column_table[3], int buttons_pressed[3][3]);

#endif