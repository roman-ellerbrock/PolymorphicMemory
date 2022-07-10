//
// Created by Roman Ellerbrock on 6/30/22.
//

#ifndef POLYMORPHICMEMORY_CUH
#define POLYMORPHICMEMORY_CUH
#include "stdafx.h"
#include "hostMemory.h"

namespace polymorphic {


//	template <>
//	void transfer<cuMemory, Memory>(cuMemory& mem, const Memory& cumem);
	

	template <typename T>
	class cuMemory {
	public:
		cuMemory();
		~cuMemory();

		cuMemory(size_t size);

		void copy(const cuMemory& other);

		cuMemory(const cuMemory& other);

		cuMemory(cuMemory&& other) noexcept;

		cuMemory& operator=(const cuMemory<T>& other);

		cuMemory& operator=(cuMemory<T>&& other) noexcept;

		size_t size() const { return size_; }
		T* data() { return data_; }
		const T* data()const { return data_; }

	protected:
		T* data_{nullptr};
		size_t size_{0};
		// queue
	};

	template <typename T>
	void transferToDevice(cuMemory<T>& x, const hostMemory<T>& y);

	template <typename T>
	void transferToHost(hostMemory<T>& x, const cuMemory<T>& y);
}


#endif //POLYMORPHICMEMORY_CUH
