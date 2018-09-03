#include "rubiks.h"

/*
** Function to shift a line of a 2D array to the right
*/

void    algo_line_reverse(int **table, int line){

    system("clear");
    printf("Rotate Right line %d.\n", line);
    my_swap(&table[line][3], &table[line][2]);
    my_swap(&table[line][2], &table[line][1]);
    my_swap(&table[line][1], &table[line][0]);
    print_tab(table);
    sleep(2);
}

/*
** Function to shift a column of a 2D array down
*/

void    algo_column_reverse(int **table, int column) {
    
    system("clear");
    printf("Rotate Down column %d.\n", column);
    my_swap(&table[3][column], &table[2][column]);
    my_swap(&table[2][column], &table[1][column]);
    my_swap(&table[1][column], &table[0][column]);
    print_tab(table);
    sleep(2);
}

/*
** Function to turn a square inside a 2D array counterclockwise
*/

void    algo_square_reverse(int **table, int square) {

    system("clear");
    printf("Rotate Counter Clockwise square %d.\n", square);
    switch (square) {
        case 1:
            my_swap(&table[0][2], &table[0 + 1][2]);
            my_swap(&table[0][2 + 1], &table[0 + 1][2 + 1]);
            my_swap(&table[0][2], &table[0 + 1][2 + 1]);
            break;
        case 2:
            my_swap(&table[2][0], &table[2 + 1][0]);
            my_swap(&table[2][0 + 1], &table[2 + 1][0 + 1]);
            my_swap(&table[2][0], &table[2 + 1][0 + 1]);
            break;
        case 3:
            my_swap(&table[2][2], &table[2 + 1][2]);
            my_swap(&table[2][2 + 1], &table[2 + 1][2 + 1]);
            my_swap(&table[2][2], &table[2 + 1][2 + 1]);
            break;
        default:
            my_swap(&table[square][square], &table[square + 1][square]);
            my_swap(&table[square][square + 1], &table[square + 1][square + 1]);
            my_swap(&table[square][square], &table[square + 1][square + 1]);
            break;
    }
    print_tab(table);
    sleep(2);
}