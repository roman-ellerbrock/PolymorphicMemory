#include "PolymorphicMemory.h"
//#include "PolymorphicMemory.cuh"
#include "malloc.cuh"
#include <iostream>

polymorphic::memory<polymorphic::CPU<double>> generator() {
	using namespace polymorphic;
	memory<CPU<double>> mem(10);
	mem.data()[0] = 1.;
	return mem;
}

int main() {

	size_t n = 20;
	using namespace polymorphic;
	memory<CPU<double>> mem(n);

	std::cout << "Memory: " << n << "\n";
	std::cout << mem << std::endl;

	memory<CPU<double>> A(n);
	std::cout << "A.size() = " << A.size() << std::endl;
	double* data = A.data();
	for (size_t i = 0; i < A.size(); ++i) {
		data[i] = i;
	}

	std::cout << "A:" << A << std::endl;

	memory<CPU<double>> B(n);
	B = A;
	std::cout << "A:" << A << std::endl;
	std::cout << "B = A:" << B << std::endl;

	memory<CPU<double>> C = A;
	std::cout << "C:" << C << std::endl;

	memory<CPU<double>> D(C);
	D = C;
	std::cout << "D:" << D << std::endl;

	return 0;
}

