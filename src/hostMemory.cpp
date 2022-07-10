//
// Created by Roman Ellerbrock on 6/30/22.
//

#include "hostMemory.h"
#include <string.h>
#include <ostream>

namespace polymorphic {

//	template class hostMemory<double>;
//	template class hostMemory<complex<double>>;

	std::ostream& operator<<(std::ostream& os, hostMemory<double>& mem) {
		os << "mem.size() = " << mem.size() << std::endl;
		for (size_t i = 0; i < mem.size(); ++i) {
			os << mem.data()[i] << " ";
		}
		return os;
	}

}

