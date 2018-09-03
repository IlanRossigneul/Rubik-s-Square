#include "rubiks.h"

/*
** Function to initialize all rows and columns in EMPTY
*/

void    init_empty(int *lines, int *columns) {

    int i;

    i = 0;
    while (i < 4) {
        lines[i] = EMPTY;
        columns[i] = EMPTY;
        i++;
    }
}

/*
** Function for EMPTY all lines except the first
*/

void    init_for_value_f(int *lines) {

    lines[0] = BLOCKED;
    lines[1] = EMPTY;
    lines[2] = EMPTY;
    lines[3] = EMPTY;
}

/*
** Function for EMPTY only the first line
*/

void    init_for_space_f(int *lines) {

    lines[0] = EMPTY;
    lines[1] = BLOCKED;
    lines[2] = BLOCKED;
    lines[3] = BLOCKED;
}

/*
** Function to align the first line with values equal to that of the table [0] [0]
*/

void    build_first_line(int **table) {

    int lines[4];
    int columns[4];
    int value;
    int *ret_value;
    int *ret_space;

    value = table[0][0];
    init_empty(lines, columns);
    ret_value = xMalloc(sizeof(int));
    ret_space = xMalloc(sizeof(int));
    while (table[0][0] != value || table[0][1] != value || table[0][2] != value || table[0][3] != value) {
        init_for_value_f(lines);
        ret_value = look_for_value(table, lines, columns, value);
        init_for_space_f(lines);
        ret_space = look_for_space(table, lines, columns, value);
        while (ret_value[1] != ret_space[1]) {
            algo_line_reverse(table, ret_value[0]);
            ret_value[1] == 3 ? ret_value[1] = 0 : ret_value[1]++;
        }
        while (ret_value[0] != 0) {
            algo_column(table, ret_value[1]);
            ret_value[0]--;
        }
    }
    xFree((void*)ret_value);
    xFree((void*)ret_space);
}

/*
** Function to move from a row row to a tidy square
*/

void    line_to_square(int **table, int line) {

    algo_square_reverse(table, line);
    algo_square_reverse(table, line);
    algo_line(table, line);
    algo_line(table, line);
}

/*
** Function to build the first square at the top left
*/

void    build_first_square(int **table) {
    
    build_first_line(table);
    print_tab(table);
    line_to_square(table, 0);
}