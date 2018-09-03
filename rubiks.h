#ifndef RUBIKS_H_
# define RUBIKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define PRINT_SQUARE_DEBUG__ 0
#define EMPTY 0
#define BLOCKED 1
#define MY_ABS(x) ((x)<0 ? -(x) : (x))

void	*xMalloc(size_t size);
void	*super_xMalloc(size_t xSize, int x, size_t ySize, int y);
void	xFree(void *ptr);
void	superxFree(void **ptr, int size);
void	init_tab(int **table);
void	print_tab(int **table);
void    my_swap(int *a, int *b);
void    algo_line(int **table, int line);
void    algo_column(int **table, int column);
void    algo_square(int **table, int square);
void    algo_line_reverse(int **table, int line);
void    algo_column_reverse(int **table, int column);
void    algo_square_reverse(int **table, int square);
int     is_in_line(int **table, int line, int value);
int     is_in_col(int **table, int column, int value);
void	init_tab5(int **table);
void    verif_return(int *ret);
int     *look_for_space(int **table, int *lines, int *columns, int value);
int     *look_for_value(int **table, int *lines, int *columns, int value);
void	init_tab7(int **table);
void    rotate_lines(int **table, int line, int offset);
void    rotate_columns(int **table, int column, int offset);
void    init_empty(int *lines, int *columns);
void    init_for_value_f(int *lines);
void    init_for_space_f(int *lines);
void    build_first_line(int **table);
void    line_to_square(int **table, int line);
void    build_first_square(int **table);
void    init_for_value_s(int *lines);
void    init_for_space_s(int *lines);
void    build_last_line(int **table);
void    push_it_up(int **table);
void    build_second_square(int **table);
void    init_for_value_f(int *lines);
void    init_for_space_f(int *lines);
void    build_final_line(int **table);
void    build_last_squares(int **table);
int     my_rand(int min, int max);
void    shuffle_tab(int **table);

#endif