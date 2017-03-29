#!/bin/sh

export OMP_NUM_THREADS=4

# execute applications
./test_omp
mpirun -np 4 ./test_mpi
