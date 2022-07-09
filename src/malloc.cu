#include <cuda_runtime.h>

void cuMem() {
	
    int N = 2000;
    int bytes = N * sizeof(float);
    float *dev_A, *dev_B, *dev_C;

    cudaMalloc(&dev_A, bytes);

    cudaFree(dev_A);
}
