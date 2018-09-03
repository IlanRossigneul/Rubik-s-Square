#include "rubiks.h"

/*
** Function to determine if a value is present in the line
*/

int     is_in_line(int **table, int line, int value) {

    int i;

    i = 0;
    while (i < 4) {
        if (table[line][i] == value)
            return (0);
        i++;
    }

    return (1);
}

/*
** Function to determine if a value is present in the column
*/

int     is_in_col(int **table, int column, int value) {

    int i;

    i = 0;
    while (i < 4) {
        if (table[i][column] == value)
            return (0);
        i++;
    }
    
    return (1);
}