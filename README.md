# csc569-lab5
# Alberto Rodriguez and Theo Watkins

mpicc -o mpi_mm matrix.c MPI_mm.c
mpicc -fopenmp -o mpi_mp_mm matrix.c MPI_MP_mm.c
gcc -fopenmp -o mp_mm matrix.c MP_mm.c
gcc -o seq_mm matrix.c seq_mm.c