#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>

#define MSIZE 1600

void print_matrix(int mat[MSIZE][MSIZE]);

void print_row(int res[MSIZE]);

double time_func(void (*foo) ());

#endif
