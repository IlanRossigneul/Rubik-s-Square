#include "rubiks.h"

int     main() {
    
    int **tab;
    int *ret_value;
    int *ret_space;
    int lines[4];
    int columns[4];

    tab = super_xMalloc(sizeof(int), 4, sizeof(int *), 4);
    ret_value = xMalloc(sizeof(int));
    ret_space = xMalloc(sizeof(int));

    // Ex_01

    /*init_tab(tab);
    print_tab(tab);

    // Ex_02

    algo_line(tab, 0);
    algo_column(tab, 0);
    algo_square(tab, 0);

    // Ex_03

    algo_square_reverse(tab, 0);
    algo_column_reverse(tab, 0);
    algo_line_reverse(tab, 0);

    // Ex_04

    printf("%d - %d\n", is_in_line(tab, 0, 1), is_in_col(tab, 2, 3));
    printf("%d - %d\n", is_in_line(tab, 3, 1), is_in_col(tab, 2, 0));

    // Ex_05

    init_tab5(tab);
    print_tab(tab);
    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = EMPTY;
    lines[3] = BLOCKED;
    columns[0] = EMPTY;
    columns[1] = EMPTY;
    columns[2] = BLOCKED;
    columns[3] = BLOCKED;
    verif_return(look_for_space(tab, lines, columns, 1));
    verif_return(look_for_space(tab, lines, columns, 2));

    // Ex_06

    init_tab5(tab);
    print_tab(tab);
    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = EMPTY;
    lines[3] = BLOCKED;
    columns[0] = EMPTY;
    columns[1] = EMPTY;
    columns[2] = BLOCKED;
    columns[3] = BLOCKED;
    verif_return(look_for_value(tab, lines, columns, 2));
    verif_return(look_for_value(tab, lines, columns, 1));

    // Ex_07

    init_tab7(tab);
    print_tab(tab);
    lines[0] = BLOCKED;
    lines[1] = EMPTY;
    lines[2] = BLOCKED;
    lines[3] = BLOCKED;
    columns[0] = EMPTY;
    columns[1] = EMPTY;
    columns[2] = EMPTY;
    columns[3] = EMPTY;
    ret_value = look_for_value(tab, lines, columns, 0);
    lines[0] = EMPTY;
    lines[1] = BLOCKED;
    ret_space = look_for_space(tab, lines, columns, 0);
    rotate_lines(tab, ret_value[0], ret_value[1] - ret_space[1]);
    print_tab(tab);
    rotate_columns(tab, ret_space[1], ret_value[0] - ret_space[0]);
    print_tab(tab);

    // Ex_08

    build_first_square(tab);

    // Ex_09

    build_second_square(tab);

    // Ex_10

    build_last_squares(tab);*/

    // Bonus

    system("clear");
    printf("\n");
    init_tab(tab);
    print_tab(tab);
    sleep(2);
    system("clear");
    shuffle_tab(tab);
    printf("Shuffle\n");
    print_tab(tab);
    sleep(2);
    build_first_square(tab);
    build_second_square(tab);
    build_last_squares(tab);
    system("clear");
    printf("Done\n");
    print_tab(tab);

    xFree((void*)ret_value);
    xFree((void*)ret_space);
    superxFree((void**)tab, 4);
    return (0);
}
