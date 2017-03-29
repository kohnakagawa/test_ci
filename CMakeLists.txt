cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

# find_package(CUDA REQUIRED)

set(
  CUDA_NVCC_FLAGS
  ${CUDA_NVCC_FLAGS};
  "-std=c++11 -O3 -arch=sm_35 -lineinfo -Xptxas -v"
  )
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -fopenmp -cxx=g++-4.8")

add_executable(test_mpi test_mpi.cpp)
add_executable(test_omp test_omp.cpp)
# cuda_add_executable(test_cuda test_cuda.cu)

target_link_libraries(test_mpi mpi)


