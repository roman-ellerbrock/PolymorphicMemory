//
// Created by Roman Ellerbrock on 6/30/22.
//

#ifndef POLYMORPHICMEMORY_H
#define POLYMORPHICMEMORY_H
#include "stdafx.h"
#include <vector>

namespace polymorphic {
	template <typename T>
	class cuMemory;

	template <typename T>
	class hostMemory : public std::vector<T> {
	public:
		hostMemory(size_t size) : vector<T>(size) {}

		hostMemory(const cuMemory<T>& dev);
		hostMemory& operator=(const cuMemory<T>& dev);
	};

	template <typename T>
	hostMemory<T> arange(size_t size);

	std::ostream& operator<<(std::ostream& os, hostMemory<double>& mem);

	using memoryd = hostMemory<double>;
	using memorycd = hostMemory<complex<double>>;

}


#endif //POLYMORPHICMEMORY_H
