#include <gtest/gtest.h>
#include "cuMemory.h"

using namespace polymorphic;
double deps = 1e-7;

class cuMemoryF : public ::testing::Test {
public:
	cuMemoryF() {
		host_ = arange<double>(20);
	}
	memoryd host_{20};
};

void checkArange(const hostMemory<double>& host, size_t size) {
	EXPECT_EQ(host.size(), size);
	for (size_t i = 0; i < size; ++i) {
		EXPECT_NEAR(host.data()[i], (double) i, deps);
	}

}

void cuCheckArange(const cuMemory<double>& dev, size_t size) {
	memoryd host(dev);
	EXPECT_EQ(host.size(), size);
	for (size_t i = 0; i < size; ++i) {
		EXPECT_NEAR(host.data()[i], (double) i, deps);
	}

}


TEST_F(cuMemoryF, hostArange) {
	checkArange(host_, 20);
}

TEST_F(cuMemoryF, constructSizeTransfer) {
	cuMemory<double> dev(20);
	dev.transferToDevice(host_);
	EXPECT_EQ(dev.size(), 20);

	hostMemory<double> reHost(20);
	dev.transferToHost(reHost);

	checkArange(reHost, 20);
}

TEST_F(cuMemoryF, constructCopy) {
	cuMemoryd dev(host_);
	memoryd rehost(dev);
	checkArange(rehost, 20);
}

TEST_F(cuMemoryF, assign) {
	cuMemoryd dev(host_.size());
	dev = host_;
	memoryd rehost(host_.size());
	rehost = dev;
	checkArange(rehost, 20);
}

TEST_F(cuMemoryF, assignResize) {
	cuMemoryd dev(10);
	dev = host_;
	memoryd rehost(10);
	rehost = dev;
	checkArange(rehost, 20);
}

/// Device - Device 

TEST_F(cuMemoryF, cuconstructCopy) {
	cuMemoryd dev(host_);
	cuMemoryd dev2(dev);
	cuCheckArange(dev2, 20);
}

TEST_F(cuMemoryF, cuAssign) {
	cuMemoryd dev(host_);
	cuMemoryd dev2(host_.size());
	dev2 = dev;
	cuCheckArange(dev2, 20);
}

TEST_F(cuMemoryF, cuAssignResize) {
	cuMemoryd dev(host_);
	cuMemoryd dev2(10);
	dev2 = dev;
	cuCheckArange(dev2, 20);
}



