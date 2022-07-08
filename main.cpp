#include "PolymorphicMemory.h"
#include "PolymorphicMemory.cuh"
#include "malloc.cuh"


int main() {

	size_t n = 20;
	polymorphic::memory<double> mem(n);

	std::cout << "Memory: " << n << "\n";

	cuMem();

	polymorphic::memory<double, polymorphic::CUDA> cumem(n);

	return 0;
}

