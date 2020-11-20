# CSC 569 - lab5
Alberto Rodriguez and Theo Watkins

# Compilation
mpicc -o mpi_mm matrix.c MPI_mm.c
mpicc -fopenmp -o mpi_mp_mm matrix.c MPI_MP_mm.c
gcc -fopenmp -o mp_mm matrix.c MP_mm.c
gcc -o seq_mm matrix.c seq_mm.c

# Execution
mpiexec ./mpi_mm
mpiexec ./mpi_mp_mm
./mp_mm
./seq_mm

# Timing
We ran and timed each executable on the PSC Bridges super computer cluster with the size of the input matrices (MSIZE) set to 1600x1600.  
We ran the executables with 2, 4, and 8 nodes.  
A table that shows the timing for each run can be found here: https://docs.google.com/spreadsheets/d/1DhJ4aiJSJrX0zwEKK-mtjKTB4JQiptl3f9K3I4Ig65Q/edit?usp=sharing