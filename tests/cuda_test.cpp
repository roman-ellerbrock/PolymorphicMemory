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

double residual(const memoryd& a, const memoryd& b) {
	double r = 0.;
	for (size_t i = 0; i < a.size(); ++i) {
		r += abs(pow(a.data()[i] - b.data()[i], 2));
	}
	return sqrt(r);
}

TEST_F(cuMemoryF, dgemm) {
	/// Create memory on host
	size_t n = 10;
	memoryd hostA = arange<double>(n * n);
	memoryd hostB = hostA;
	memoryd hostC(hostA.size());

	/// transfer to GPU
	cuMemoryd devA(hostA);
	cuMemoryd devB(hostA);
	cuMemoryd devC(hostA);

	/// perform dgemm
	int device = 0;
	int batch_size = 1000;
	using namespace blas;
	Queue queue(device, batch_size);

	gemm(Layout::ColMajor, Op::NoTrans, Op::NoTrans,
		n, n, n, 
		-1.0, devA.data(), n, 
		devB.data(), n, 
		0.0, devC.data(), n, 
		queue);

	memoryd hostC2 = devC;
	queue.sync();

	gemm(Layout::ColMajor, Op::NoTrans, Op::NoTrans,
		n, n, n, 
		-1.0, hostA.data(), n, 
		hostB.data(), n, 
		0.0, hostC.data(), n);

	EXPECT_NEAR(residual(hostC, hostC2), 0., deps);
}

TEST_F(cuMemoryF, cudaAllocator) {
	vector<double, cudaAllocator<double>> myvec(100);
}



