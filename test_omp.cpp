#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <omp.h>

constexpr int size = 100;
int array[size] {0};

int main() {
  std::iota(array, array + size, 0);
  int sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  const int ref = std::accumulate(array, array + size, 0);
  if (sum != ref) {
    std::cerr << "Error occurs at " << __FILE__ << " " << __LINE__ << "\n";
    std::exit(1);
  }
}
