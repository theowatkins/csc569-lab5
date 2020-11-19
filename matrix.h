#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>

#define MSIZE 4

void print_matrix(int mat[MSIZE][MSIZE]);

void print_row(int res[MSIZE]);

double time_func(void (*foo) (int*, char ***), int *argc, char **argv[]);

#endif
