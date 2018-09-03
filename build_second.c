#include "rubiks.h"

/*
** Function for EMPTY all lines except the last
*/

void    init_for_value_s(int *lines) {

    lines[0] = EMPTY;
    lines[1] = EMPTY;
    lines[2] = EMPTY;
    lines[3] = BLOCKED;
}

/*
** Function for EMPTY only the last line
*/

void    init_for_space_s(int *lines) {

    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = BLOCKED;
    lines[3] = EMPTY;
}

/*
** Function to align the last line with values equal to that of the table [3] [3]
*/

void    build_last_line(int **table) {

    int lines[4];
    int columns[4];
    int value;
    int *ret_value;
    int *ret_space;

    value = table[3][3];
    init_empty(lines, columns);
    ret_value = xMalloc(sizeof(int));
    ret_space = xMalloc(sizeof(int));
    while (table[3][0] != value || table[3][1] != value || table[3][2] != value || table[3][3] != value) {
        init_for_value_s(lines);
        ret_value = look_for_value(table, lines, columns, value);
        init_for_space_s(lines);
        ret_space = look_for_space(table, lines, columns, value);
        while (ret_value[1] < 2 && ret_value[0] == 2) {
            algo_line_reverse(table, 2);
            ret_value[1]++;
        }
        while (ret_value[1] != ret_space[1]) {
            algo_line_reverse(table, 3);
            ret_space[1] == 3 ? ret_space[1] = 0 : ret_space[1]++;
        }
        while (ret_value[0] != 3) {
            algo_column_reverse(table, ret_value[1]);
            ret_value[0]++;
        }
    }
    xFree((void*)ret_value);
    xFree((void*)ret_space);
}

/*
** Function to go up the square formed at the bottom right towards the square at the top right
*/

void    push_it_up(int **table) {

    rotate_columns(table, 2, 2);
    rotate_columns(table, 3, 2);
}

/*
** Function to build the second square at the top right
*/

void    build_second_square(int **table) {
    
    build_last_line(table);
    line_to_square(table, 3);
    push_it_up(table);
}