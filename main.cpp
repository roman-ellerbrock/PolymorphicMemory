#include "PolymorphicMemory.h"
//#include "PolymorphicMemory.cuh"
#include "malloc.cuh"
#include <iostream>

std::ostream& operator<<(std::ostream& os, polymorphic::memory<polymorphic::CPU<double>>& mem) {
	os << "mem.size() = " << mem.size() << std::endl;
	for (size_t i = 0; i < mem.size(); ++i) {
		os << mem.data()[i] << " ";
	}
	return os;
}

class CUDA;

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
//	cuMem();

//	polymorphic::memory<double, polymorphic::CUDA> A(n);
//	polymorphic::memory<double, polymorphic::CUDA> B(n);

	/// copy device to device
//	A = B;

	return 0;
}

