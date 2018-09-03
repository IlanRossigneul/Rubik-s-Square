#include "rubiks.h"

/*
** Function to determine if a value is found within a defined EMPTY range
*/

int     *look_for_value(int **table, int *lines, int *columns, int value) {

    int i;
    int j;
    int *ret;

    i = 0;
    ret = malloc(sizeof(int) * 2 + 1);
    while (i < 4) {
        j = 0;
            while (j < 4) {
                if (table[i][j] == value && lines[i] == EMPTY && columns[j] == EMPTY) {
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