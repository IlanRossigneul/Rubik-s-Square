#include "rubiks.h"

/*
** Function for EMPTY only the 3rd line
*/

void    init_for_value_t(int *lines) {
    
    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = EMPTY;
    lines[3] = BLOCKED;
}

/*
** Function for EMPTY only the last line
*/

void    init_for_space_t(int *lines) {

    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = BLOCKED;
    lines[3] = EMPTY;
}

/*
** Function to align the last line with values equal to that of the table [3] [3]
*/

void    build_final_line(int **table) {

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
        init_for_value_t(lines);
        ret_value = look_for_value(table, lines, columns, value);
        init_for_space_t(lines);
        ret_space = look_for_space(table, lines, columns, value);
        while (ret_value[1] != ret_space[1]) {
            algo_line_reverse(table, 3);
            ret_space[1] == 3 ? ret_space[1] = 0 : ret_space[1]++;
        }
        if (ret_value[1] == 0) {
            algo_line_reverse(table, 3);
            algo_square_reverse(table, 2);
        } else if (ret_value[1] == 1) {
            algo_line(table, 3);
            algo_square(table, 2);
        } else if (ret_value[1] == 2) {
            algo_line_reverse(table, 3);
            algo_square_reverse(table, 3);
        } else if (ret_value[1] == 3) {
            algo_line(table, 3);
            algo_square(table, 3);
        }
    }
    xFree(ret_value);
    xFree(ret_space);
}

/*
** Function to build the last two squares downstairs
*/

void    build_last_squares(int **table) {

    build_final_line(table);
    line_to_square(table, 3);
}
