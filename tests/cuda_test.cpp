#include <gtest/gtest.h>
#include "cuMemory.h"

using namespace polymorphic;
double deps = 1e-7;


TEST(constructSize, MemoryGPU) {
	hostMemory<double> host(20);
	EXPECT_EQ(host.size(), 20);
	for (size_t i = 0; i < 20; ++i) {
		host.data()[i] = i;
	}

	cuMemory<double> dev(20);
	transferToDevice(dev, host);

	hostMemory<double> reHost(20);
	transferToHost(reHost, dev);
	for (size_t i = 0; i < 20; ++i) {
		EXPECT_NEAR(reHost.data()[i], (double) i, deps);
	}
}



