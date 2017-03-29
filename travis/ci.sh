#!/bin/sh

export OMP_NUM_THREADS=2


mpirun -np 1 ./mdacp ./run_cfg/input
