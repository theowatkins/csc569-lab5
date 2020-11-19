#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[] ) {
    printf("OpenMP took %.2f seconds to run.", time_function(mp_mm));
}

void mp_mm(){
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

    # pragma omp for
    for(i=0;i<MSIZE;i++) {
        for(j=0;j<MSIZE;j++) {
            result[i][j] = 0;
            for(k=0;k<MSIZE;k++){
                result[i][j] += matrixA[i][k]*matrixB[k][j];
            }
        }
    }
}
