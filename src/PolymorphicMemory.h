//
// Created by Roman Ellerbrock on 6/30/22.
//

#ifndef POLYMORPHICMEMORY_H
#define POLYMORPHICMEMORY_H
#include "stdafx.h"

namespace polymorphic {

	template<typename T, class deviceA, class deviceB>
	void transfer(T *d_dest, const T* h_src, const size_t n, const size_t m);

	template<typename T, class deviceA, class deviceB>
	void transferFromDevice(T *d_dest, const T* h_src, const size_t n, const size_t m);

	template <class T = complex<double>>
	class CPU {
		using size_type = size_t;
	public:

		void memcopy(const CPU& src);

		CPU() = default;

		CPU(size_type size) : data_(allocate(size)), size_(size) {
		}

		~CPU() {
		}

		[[nodiscard]] const auto& size() const { return size_; }
		auto& size() { return size_; }

		[[nodiscard]] const T* data() const { return data_; }
		T* data() { return data_; }

	protected:
		T* allocate(size_type size);
		void free();

		T* data_{nullptr};
		size_type size_{0};
	};

	template<class Device = CPU<double>>
	class memory {
	public:
		explicit memory(size_t size);
		~memory() = default;

		memory(const memory& B);
		memory(memory&& B) noexcept;

		memory& operator=(const memory& B);
		memory& operator=(memory&& B) noexcept;

		void resize(size_t);

		[[nodiscard]] auto size() const { return dev_.size(); }

//		const auto *data() const { return dev_.data(); }
		auto* data() { return dev_.data(); }

//		auto size() const { return CPU::size(); }
//		const auto *data() const { return CPU::data(); }
	protected:
		Device dev_;

	};

	std::ostream& operator<<(std::ostream& os, memory<CPU<double>>& mem);

}


#endif //POLYMORPHICMEMORY_H
