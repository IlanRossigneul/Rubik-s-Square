#include "rubiks.h"

/*
** Function to display the 2D array coordinates given by the table ret
*/

void    verif_return(int *ret) {

    if (ret != NULL) {
        printf("line :\t\t%d\ncolumn :\t%d\n", ret[0], ret[1]);
    } else {
        printf("Nothing found in the given range.\n");
    }
}

/*
** Function to determine if space is available within a defined EMPTY range
*/

int     *look_for_space(int **table, int *lines, int *columns, int value) {

    int i;
    int j;
    int *ret;

    i = 0;
    ret = malloc(sizeof(int) * 2 + 1);
    while (i < 4) {
        j = 0;
            while (j < 4) {
                if (table[i][j] != value && lines[i] == EMPTY && columns[j] == EMPTY) {
                    ret[0] = i;
                    ret[1] = j;
                    return (ret);
                }  
                j++;
            }
        i++;
    }
    xFree((void*)ret);
    
    return NULL;
}