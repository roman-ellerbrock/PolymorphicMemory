#include <gtest/gtest.h>
#include "PolymorphicMemory.h"


using namespace polymorphic;
double eps = 1e-7;

TEST(constructSize, MemoryCPU) {
	memory<CPU<double>> mem(20);
	EXPECT_EQ(mem.size(), 20);
	for (size_t i = 0; i < 20; ++i) {
		mem.data()[i] = i;
	}
	for (size_t i = 0; i < 20; ++i) {
		EXPECT_NEAR(mem.data()[i], (double) i, eps);
	}
}

TEST(constructCopy, MemoryCPU) {
	memory<CPU<double>> mem(20);
	for (size_t i = 0; i < mem.size(); ++i) {
		mem.data()[i] = i;
	}

	memory<CPU<double>> A(mem);
	EXPECT_EQ(A.size(), 20);
	for (size_t i = 0; i < A.size(); ++i) {
		A.data()[i] = 2 * i;
		EXPECT_NEAR(mem.data()[i], (double) i, eps);
		EXPECT_NEAR(A.data()[i], (double) 2 * i, eps);
	}
}

TEST(constructAssign0, MemoryCPU) {
	memory<CPU<double>> mem(20);
	for (size_t i = 0; i < mem.size(); ++i) {
		mem.data()[i] = i;
	}

	memory<CPU<double>> A = mem;
	EXPECT_EQ(A.size(), 20);
	for (size_t i = 0; i < A.size(); ++i) {
		A.data()[i] = 2 * i;
		EXPECT_NEAR(mem.data()[i], (double) i, eps);
		EXPECT_NEAR(A.data()[i], (double) 2 * i, eps);
	}
}

TEST(constructAssign1, MemoryCPU) {
	memory<CPU<double>> mem(20);
	for (size_t i = 0; i < mem.size(); ++i) {
		mem.data()[i] = i;
	}

	memory<CPU<double>> A(20);
	A = mem;
	EXPECT_EQ(A.size(), 20);
	for (size_t i = 0; i < A.size(); ++i) {
		A.data()[i] = 2 * i;
		EXPECT_NEAR(mem.data()[i], (double) i, eps);
		EXPECT_NEAR(A.data()[i], (double) 2 * i, eps);
	}
}

TEST(CPUmove, MemoryCPU) {
	CPU<double> cpu(20);
	//CPU<double> cpu2(20);
	CPU<double> tmp = move(cpu);
	//cpu = move(cpu2);
	//cpu2 = move(tmp);
	
//	std::swap(cpu, cpu2);

}

/*TEST(constructAssign2, MemoryCPU) {
	memory<CPU<double>> mem(20);
	for (size_t i = 0; i < mem.size(); ++i) {
		mem.data()[i] = i;
	}

	memory<CPU<double>> A(10);
cout << "in.\n";
	A = mem;
cout << "out.\n";
	EXPECT_EQ(A.size(), 20);
cout << "yo.\n";
getchar();
	for (size_t i = 0; i < A.size(); ++i) {
		A.data()[i] = 2 * i;
		EXPECT_NEAR(mem.data()[i], (double) i, eps);
		EXPECT_NEAR(A.data()[i], (double) 2 * i, eps);
	}
}

*/

