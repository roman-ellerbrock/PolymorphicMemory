//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "hostMemory.h"
#include "cuMemory.h"
#include <string.h>

namespace polymorphic {

	template <typename T>
	hostMemory<T>::hostMemory(const cuMemory<T>& dev) : hostMemory(dev.size()) {
		dev.transferToHost(*this);
	}

	template <typename T>
	hostMemory<T>& hostMemory<T>::operator=(const cuMemory<T>& dev) {

		if (this->size() == dev.size()) {
			dev.transferToHost(*this);
		} else {
			hostMemory<T> tmp(dev.size());
			dev.transferToHost(tmp);
			std::swap(tmp, *this);
		}
		return *this;
	}
	

	template <typename T>
	hostMemory<T> arange(size_t size) {
		hostMemory<T> host(size);
		for (size_t i = 0; i < size; ++i) {
			host.data()[i] = i;
		}
		return host;
	}

}

