#include <stdio.h>
#include "matrix.h"

void mp_mm(int *argc, char **argv[]){
    int matrixA[MSIZE][MSIZE];
    int matrixB[MSIZE][MSIZE];
    int result[MSIZE][MSIZE];
    int i,j,k;

    for(i=0;i<MSIZE;i++) {
        for(j=0;j<MSIZE;j++) {
            matrixA[i][j] = i+j;
            matrixB[i][j] = i+j+1;
        }
    }

    #pragma omp parallel for collapse(2) private(i, j, k) shared(matrixA, matrixB, result)
    for(i=0;i<MSIZE;i++) {
        for(j=0;j<MSIZE;j++) {
            result[i][j] = 0;
            for(k=0;k<MSIZE;k++){
                result[i][j] += matrixA[i][k]*matrixB[k][j];
            }
        }
    }

    // print_matrix(result);
}

int main(int argc, char *argv[] ) {
    printf("OpenMP took %.2f seconds to run.\n", time_func(&mp_mm));
    return 0;
}
