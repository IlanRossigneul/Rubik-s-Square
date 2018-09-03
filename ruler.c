#include "rubiks.h"

/*
** Function for malloc a table
*/

void    *xMalloc(size_t size) {

    void    *ptr;

    if ((ptr = malloc(size)) == NULL) {
        printf("Malloc failed with critical error\n");
        exit (-1);
    }

    return (ptr);
}

/*
** Function for malloc a 2D array
*/

void    *super_xMalloc(size_t xSize, int x, size_t ySize, int y) {

    void	**ptr;
    int	    i;

    i = 0;
    ptr = xMalloc(ySize * (y + 1));
    while (i < y) {
        ptr[i] = xMalloc(xSize * (x + 1));
        i++;
    }

    return (ptr);
}

/*
** Function for free a table
*/

void	xFree(void *ptr) {

    if (ptr == NULL) {
        return;
    }
    free(ptr);
    ptr = NULL;
}

/*
** Function for free a 2D array
*/

void	superxFree(void **ptr, int size) {

    int i;

    i = 0;
    while (i < size) {
        xFree(ptr[i]);
        i++;
    }
    xFree(ptr);
}

/*
** Function for random a range of min value included to max excluded
*/

int     my_rand(int min, int max) {

    int         res;
    static int  tmp = 0;

    res = 0;
    if (tmp == RAND_MAX) {
        tmp = 0;
    }
    srand(time(NULL) + tmp);
    res = rand()%((max - min) + min);
    tmp++;

    return (res);
}

/*
** Function to initialize the table for exercise 01
*/

void	init_tab(int **table) {

    table[0][0] = 0;
    table[0][1] = 0;
    table[0][2] = 1;
    table[0][3] = 1;
    table[1][0] = 0;
    table[1][1] = 0;
    table[1][2] = 1;
    table[1][3] = 1;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 3;
    table[2][3] = 3;
    table[3][0] = 2;
    table[3][1] = 2;
    table[3][2] = 3;
    table[3][3] = 3;
}

/*
** Function to initialize the array for exercise 05
*/

void	init_tab5(int **table) {
    table[0][0] = 2;
    table[0][1] = 1;
    table[0][2] = 3;
    table[0][3] = 0;
    table[1][0] = 0;
    table[1][1] = 0;
    table[1][2] = 1;
    table[1][3] = 1;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 3;
    table[2][3] = 0;
    table[3][0] = 2;
    table[3][1] = 3;
    table[3][2] = 1;
    table[3][3] = 3;
}

/*
** Function to initialize the table for exercise 07
*/

void	init_tab7(int **table)
{
    table[0][0] = 0;
    table[0][1] = 2;
    table[0][2] = 0;
    table[0][3] = 0;
    table[1][0] = 0;
    table[1][1] = 3;
    table[1][2] = 1;
    table[1][3] = 3;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 1;
    table[2][3] = 3;
    table[3][0] = 1;
    table[3][1] = 1;
    table[3][2] = 3;
    table[3][3] = 2;
}

/*
** Function to shuffle the 2D array
*/

void    shuffle_tab(int **table) {

    int i;
    int j;

    for (int x = 0; x < 1000; x++) {
        for (i = 0; i < 4; i++) {
            int r = my_rand(0, 4);
            for (j = 0; j < 4; j++) {
                /* shuffle by swapping cards pseudo-randomly a 1000 times */
                my_swap(&table[i][j], &table[r][j]);
                my_swap(&table[i][j], &table[i][r]);
            }
        }
    }
}

/*
** Function to draw the painting
*/

void	print_tab(int **table) {

    int cter;

    cter = 0;
    printf("−−−−−−−−−−−−−−−−−\n");
    while (cter < 4) {
        printf("| %d | %d | %d | %d |\n",
        table[cter][0],
        table[cter][1],
        table[cter][2],
        table[cter][3]);
        printf("−−−−−−−−−−−−−−−−−\n");
        cter++;
    }
    printf("\n");
}