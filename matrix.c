#include <stdio.h>
#include <time.h>
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

// returns number of seconds given function took to run
double time_func(void (*foo) ()){
    float diff;
    struct timespec tstart, tend;

    clock_gettime(CLOCK_MONOTONIC, &tstart);
    foo();
    clock_gettime(CLOCK_MONOTONIC, &tend);

    diff = ((double) tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                      ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
    return diff;
}
