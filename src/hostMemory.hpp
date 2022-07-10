//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "Memory.h"
#include <string.h>

namespace polymorphic {


	template <class T>
	T* CPU<T>::allocate(size_type size) {
		return (T*) malloc(size * sizeof(T));
	}

	template <class T>
	void CPU<T>::free() {
		::free(data_);
	}

	template <class T>
	void CPU<T>::memcopy(const CPU& src) {
		auto nCpy = (size() < src.size()) ? size() : src.size();
		memcpy(data(), src.data(), nCpy * sizeof(T));
	}


	template<class D>
	memory<D>::memory(size_t size) : dev_(size) {
	}

	template<class D>
	memory<D>::memory(const memory& B)
		: memory(B.size()) {
		dev_.memcopy(B.dev_);
	}

	template<class D>
	memory<D>::memory(memory&& B) noexcept {
		std::swap(dev_, B.dev_);
	}

	template<class D>
	memory<D>& memory<D>::operator=(const memory<D>& B) {
		/// Only allocate new memory if needed and catch self-assignment
		if (this == &B) {
			return *this;
		} else if (B.size() == this->size()) {
			dev_.memcopy(B.dev_);
		} else {
			D devB(B.size());
//			devB.memcopy(B.dev_);
			cout << "dev_:" << dev_.data() << endl;
			cout << "devB:" << devB.data() << endl;
			std::swap(dev_, devB);
			cout << "dev_:" << dev_.data() << endl;
			cout << "devB:" << devB.data() << endl;
			getchar();
			
//			memory<D> tmp(B);
//			std::swap(B, tmp);
			//*this = move(tmp);
		}
		return *this;
	}

	template<class D>
	memory<D>& memory<D>::operator=(memory<D>&& B) noexcept {
		std::swap(dev_, B.dev_);
		return *this;
	}

	template<class D>
	void memory<D>::resize(size_t newSize) {
		if (size() != newSize) {
			D devB(newSize);
			devB.memcopy(dev_);
			std::swap(dev_, devB);
		}
	}

}

