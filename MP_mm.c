#include "mpi.h"
#include <stdio.h>
#include "matrix.h"

#define MSIZE 4

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

int main(int argc, char *argv[] ) {
    int numprocs, rank, chunk_size, i,j,k;
    int max, mymax,rem;
    int matrixA[MSIZE][MSIZE]; int matrixB[MSIZE][MSIZE]; 
    int global_result[MSIZE][MSIZE];
    MPI_Status status;

    /* Initialize MPI */
    MPI_Init( &argc,&argv);
    MPI_Comm_rank( MPI_COMM_WORLD, &rank);
    MPI_Comm_size( MPI_COMM_WORLD, &numprocs);
    chunk_size = MSIZE/numprocs;

    int result[chunk_size][MSIZE];
    int local_matrix[chunk_size][MSIZE];

    if (rank == 0) { /* Only on the root task... */
        /* Initialize Matrix and Vector */
        for(i=0;i<MSIZE;i++) {
            for(j=0;j<MSIZE;j++) {
                matrixA[i][j] = i+j;
                matrixB[i][j] = i+j+1;
            }
        }

        printf("Matrix A:\n");
        print_matrix(matrixA);
        printf("\nMatrix B:\n");
        print_matrix(matrixB);
    }

    /* Distribute matrixB */
    /* The matrix is just sent to everyone */
    MPI_Bcast(matrixB,MSIZE*MSIZE,MPI_INT,0,MPI_COMM_WORLD);

    /* Distribute Matrix */
    /* Assume the matrix is too big to bradcast. Send blocks of rows to each task,
    nrows/nprocs to each one */
    MPI_Scatter(matrixA,MSIZE*chunk_size,MPI_INT,local_matrix,MSIZE*chunk_size,MPI_INT,0,MPI_COMM_WORLD); 

    /*Each processor has a chunk of rows, now multiply and build a part of the solution vector
    */
    for(i=0;i<chunk_size;i++) {
        for(j=0;j<MSIZE;j++) {
            result[i][j] = 0;
            for(k=0;k<MSIZE;k++){
                result[i][j] += local_matrix[i][k]*matrixB[k][j];
            }
        }
    }

    if (rank == 0) {
        printf("\nProc0 local:");
        print_matrix(local_matrix);
        printf("\nProc0 matrixB:\n");
        print_matrix(matrixB); 
        printf("\nResult of proc0:\n");
        print_matrix(result);
        printf("\n\n");
    } else if (rank == 1) {
        printf("\nProc1 local:");
        print_matrix(local_matrix);
        printf("\nProc1 matrixB:\n");
        print_matrix(matrixB);
        printf("\nResult of proc1:\n");
        print_matrix(result);
        printf("\n\n");
    } else if (rank == 2) {
        printf("\nProc2 local:");
        print_matrix(local_matrix);
        printf("\nProc2 matrixB:\n");
        print_matrix(matrixB);
        printf("\nResult of proc2:\n");
        print_matrix(result);
        printf("\n\n");
    }

    /*Send result back to master */
    MPI_Gather(result,MSIZE*chunk_size,MPI_INT,global_result,MSIZE*chunk_size,MPI_INT,
    0,MPI_COMM_WORLD);

    /*Display result */
    if(rank==0) {
        printf("\nGlobal Result:");
        print_matrix(global_result);
    }
    
    MPI_Finalize();
    return 0;
} 
