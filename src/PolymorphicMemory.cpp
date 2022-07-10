//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "PolymorphicMemory.hpp"
#include <string.h>
#include <ostream>

namespace polymorphic {

//	template
//	class memory<CPU<complex<double>>;
//
std::ostream& operator<<(std::ostream& os, memory<CPU<double>>& mem) {
	os << "mem.size() = " << mem.size() << std::endl;
	for (size_t i = 0; i < mem.size(); ++i) {
		os << mem.data()[i] << " ";
	}
	return os;
}


	template
	class memory<CPU<double>>;
}

