#include "cuMemory.h"
#include <cuda_runtime.h>
#include <curand.h>


namespace polymorphic {

	template <typename T>
	cuMemory<T>::~cuMemory() {
		cudaFree(data_);
	}

	template <typename T>
	cuMemory<T>::cuMemory(size_t size)
		: size_(size) {
		cudaMalloc(&data_, size * sizeof(T));
	}

	template <typename T>
	void cuMemory<T>::copy(const cuMemory& other) {
		cudaMemcpy(data(), other.data(), size() * sizeof(T), cudaMemcpyDeviceToDevice);
	}

	template <typename T>
	cuMemory<T>::cuMemory(const cuMemory& other) 
		: cuMemory(other.size()){
		copy(other);
	}

	template <typename T>
	cuMemory<T>::cuMemory(cuMemory&& other) noexcept {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
	}

	template <typename T>
	cuMemory<T>& cuMemory<T>::operator=(const cuMemory<T>& other) {
		if (this == &other) {
			return *this;
		} else if (size() == other.size()) {
			copy(other);
		} else {
			cuMemory tmp(other);
			std::swap(*this, tmp);
		}
		return *this;
	}

	template <typename T>
	cuMemory<T>& cuMemory<T>::operator=(cuMemory<T>&& other) noexcept {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}

	template <typename T>
	void cuMemory<T>::transferToDevice(const hostMemory<T>& host) {
		size_t bytes = host.size()*sizeof(T);
    		cudaMemcpy(data(), host.data(), bytes, cudaMemcpyHostToDevice);
	}

	template <typename T>
	void cuMemory<T>::transferToHost(hostMemory<T>& host) const {
		size_t bytes = host.size()*sizeof(T);
    		cudaMemcpy(host.data(), data(), bytes, cudaMemcpyDeviceToHost);
	}

	template <typename T>
	cuMemory<T>::cuMemory(const hostMemory<T>& host) : cuMemory(host.size()) {
		this->transferToDevice(host);
	}

	template <typename T>
	cuMemory<T>& cuMemory<T>::operator=(const hostMemory<T>& host) {
		if (size() == host.size()) {
			this->transferToDevice(host);
		} else {
			cuMemory tmp(host);
			std::swap(tmp, *this);
		}
		return *this;
	}

}

