#include "PolymorphicMemory.h"
#include "malloc.cuh"


int main() {

	size_t n = 20;
	polymorphic::memory<double> mem(n);

	std::cout << "Memory: " << n << "\n";

	cuMem();

	return 0;
}

