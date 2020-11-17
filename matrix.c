#include <stdio.h>
#include "matrix.h"

void print_matrix(int mat[MSIZE][MSIZE]) {
    int i,j;

    for(i=0;i<MSIZE;i++) {
        printf("\n");
        for(j=0;j<MSIZE;j++) {
            printf(" %d ",mat[i][j]);
        }
    }
    printf("\n");
}

void print_row(int res[MSIZE]) {
    int i;

    for(i=0;i<MSIZE;i++) {
        printf(" %d ", res[i]);
    }
    printf("\n");
}