//
// Created by Roman Ellerbrock on 6/30/22.
//

#ifndef POLYMORPHICMEMORY_CUH
#define POLYMORPHICMEMORY_CUH
#include "stdafx.h"
#include "hostMemory.h"
#include <blas.hh>

namespace polymorphic {

	template <typename T>
	struct cudaAllocator {
		using value_type = T;
		
		cudaAllocator() = default;

		template <class U>
		cudaAllocator(const cudaAllocator<U>&) {}
		
		T* allocate(std::size_t n);

		void deallocate(T* ptr, std::size_t n);
	};

	template <typename T, typename U>
	inline bool operator == (const cudaAllocator<T>&, const cudaAllocator<U>&) {
		return true;
	}

	template <typename T, typename U>
	inline bool operator != (const cudaAllocator<T>& a, const cudaAllocator<U>& b) {
		return !(a == b);
	}
	
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
		
		/// === host -- device communication ===
		void transferToDevice(const hostMemory<T>& y);

		void transferToHost(hostMemory<T>& x)const;

		cuMemory& operator=(const hostMemory<T>& host);

		cuMemory(const hostMemory<T>& host);

		size_t size() const { return size_; }
		T* data() { return data_; }
		const T* data()const { return data_; }

		auto& queue() { return queue_; }
		const auto& queue() const { return queue_; }

	protected:
		T* data_{nullptr};
		size_t size_{0};
		blas::Queue queue_;
	};

	using cuMemoryd = cuMemory<double>;
	using cuMemorycd = cuMemory<complex<double>>;

//	template <typename T>
//	friend hostMemory<T>& operator=(hostMemory<T>& host, const cuMemory<T>& dev);
}


#endif //POLYMORPHICMEMORY_CUH
