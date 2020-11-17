#include <stdio.h>
#include "matrix.h"

#define MSIZE 4

int main(int argc, char *argv[] ) {
    int matrixA[MSIZE][MSIZE]; \
    int matrixB[MSIZE][MSIZE];
    int result[MSIZE][MSIZE];
    int i,j,k;

    for(i=0;i<MSIZE;i++) {
        for(j=0;j<MSIZE;j++) {
            result[i][j] = 0;
            for(k=0;k<MSIZE;k++){
                result[i][j] += matrixA[i][k]*matrixB[k][j];
            }
        }
    }

}
