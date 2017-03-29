#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);

  int rank = 0, size = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int loc_val = rank;
  int glb_sum = 0;
  MPI_Allreduce(&loc_val, &glb_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

  const int est_sum = (size - 1) * size / 2;

  if (glb_sum != est_sum) {
    std::cerr << "glb_sum est_sum\n";
    std::cerr << glb_sum << " " << est_sum << "\n";
    std::cerr << "Error occurs (glb_sum != est_sum) at " << __FILE__ << " " << __LINE__ << "\n";
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  MPI_Finalize();
}
