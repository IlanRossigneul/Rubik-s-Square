#include "rubiks.h"

/*
** Function to exchange the values of 2 pointers
*/

void    my_swap(int *a, int *b) {

    int temp;
    
    temp = *b;
    *b = *a;
    *a = temp;
}

/*
** Function to shift a line of a 2D array to the left
*/

void    algo_line(int **table, int line) {

    system("clear");
    printf("Rotate Left line %d.\n", line);
    my_swap(&table[line][0], &table[line][1]);
    my_swap(&table[line][1], &table[line][2]);
    my_swap(&table[line][2], &table[line][3]);
    print_tab(table);
    sleep(2);
}

/*
** Function to shift a column of a 2D array upwards
*/

void    algo_column(int **table, int column) {

    system("clear");
    printf("Rotate Top column %d.\n", column);
    my_swap(&table[0][column], &table[1][column]);
    my_swap(&table[1][column], &table[2][column]);
    my_swap(&table[2][column], &table[3][column]);
    print_tab(table);
    sleep(2);
}

/*
** Function to rotate a square in a 2D array clockwise
*/

void    algo_square(int **table, int square) {

    system("clear");
    printf("Rotate Clockwise square %d.\n", square);
    switch (square) {
        case 1:
            my_swap(&table[0][2], &table[0][2 + 1]);
            my_swap(&table[0 + 1][2], &table[0 + 1][2 + 1]);
            my_swap(&table[0][2], &table[0 + 1][2 + 1]);
            break;
        case 2:
            my_swap(&table[2][0], &table[2][0 + 1]);
            my_swap(&table[2 + 1][0], &table[2 + 1][0 + 1]);
            my_swap(&table[2][0], &table[2 + 1][0 + 1]);
            break;
        case 3:
            my_swap(&table[2][2], &table[2][2 + 1]);
            my_swap(&table[2 + 1][2], &table[2 + 1][2 + 1]);
            my_swap(&table[2][2], &table[2 + 1][2 + 1]);
            break;
        default:
            my_swap(&table[square][square], &table[square][square + 1]);
            my_swap(&table[square + 1][square], &table[square + 1][square + 1]);
            my_swap(&table[square][square], &table[square + 1][square + 1]);
            break;
    }
    print_tab(table);
    sleep(2);
}