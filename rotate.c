#include "rubiks.h"

/*
** Function to move the line according to the offset value and if it is positive / negative
*/

void    rotate_lines(int **table, int line, int offset) {

    int i;

    i = 0;
    while (i < MY_ABS(offset)) {
        if (offset < 0) {
            algo_line_reverse(table, line);
        } else {
            algo_line(table, line);
        }
        i++;
    }
}

/*
** Function to move the column according to the offset value and if it is positive / negative
*/

void    rotate_columns(int **table, int column, int offset) {

    int j;

    j = 0;
    while (j < MY_ABS(offset)) {
        if (offset < 0) {
            algo_column_reverse(table, column);
        } else {
            algo_column(table, column);
        }
        j++;
    }
}