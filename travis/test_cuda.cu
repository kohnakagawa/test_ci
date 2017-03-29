#include <iostream>
#include <cstdlib>

__global__ void func(int* a) {
  const auto tid = threadIdx.x + blockIdx.x * blockDim.x;
  a[tid] = tid;
}

void check(const int* a,
           const int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != i) {
      std::cerr << "Error occurs (a[i] != i) at " << __FILE__ << " " << __LINE__ << "\n";
      std::exit(1);
    }
  }
}

int main() {
  const int tb_size = 128;
  const int gr_size = 1000;
  const auto size = tb_size * gr_size;

  int* a_h = new int[size];
  int* a_d = nullptr;
  cudaMalloc((void**)&a_d, size * sizeof(int));

  func<<<gr_size, tb_size>>>(a_d);
  cudaMemcpy(a_h, a_d,
             size * sizeof(int),
             cudaMemcpyDeviceToHost);
  check(a_h, size);
  cudaFree(a_d);
  delete [] a_h;
}
